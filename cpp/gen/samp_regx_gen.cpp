//
// cpp/gen/samp_regx_gen.cpp
// Generated by AMC
//
// Copyright (C) 2008-2013 AlgoEngineering LLC
// Copyright (C) 2013-2019 NYSE | Intercontinental Exchange
// Copyright (C) 2020-2023 Astra
// Copyright (C) 2023 AlgoRND
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//


#include "include/algo.h"  // hard-coded include
#include "include/gen/samp_regx_gen.h"
#include "include/gen/samp_regx_gen.inl.h"
#include "include/gen/command_gen.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/lib_json_gen.h"
#include "include/gen/lib_json_gen.inl.h"
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_lib_gen.inl.h"
//#pragma endinclude

// Instantiate all libraries linked into this executable,
// in dependency order
lib_json::FDb    lib_json::_db;     // dependency found via dev.targdep
algo_lib::FDb    algo_lib::_db;     // dependency found via dev.targdep
samp_regx::FDb   samp_regx::_db;    // dependency found via dev.targdep

namespace samp_regx {
const char *samp_regx_help =
"Usage: samp_regx [-expr:]<string> [[-string:]<string>] [options]\n"
"    OPTION      TYPE    DFLT    COMMENT\n"
"    -in         string  \"data\"  Input directory or filename, - for stdin\n"
"    [expr]      string          Expression\n"
"    -style      int     acr     Regx style (acr|shell|classic|literal)\n"
"                                    acr  ACR-style regx\n"
"                                    shell  Shell-style regx\n"
"                                    classic  Classic regx\n"
"                                    literal  Literal string\n"
"    -match                      Match a string\n"
"    [string]    string  \"\"      String to match\n"
"    -show                       Show regx innards\n"
"    -verbose    int             Verbosity level (0..255); alias -v; cumulative\n"
"    -debug      int             Debug level (0..255); alias -d; cumulative\n"
"    -help                       Print help and exit; alias -h\n"
"    -version                    Print version and exit\n"
"    -signature                  Show signatures and exit; alias -sig\n"
;


} // namespace samp_regx
namespace samp_regx { // gen:ns_print_proto
    // Load statically available data into tables, register tables and database.
    static void          InitReflection();
    // find trace by row id (used to implement reflection)
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    static i32           trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    static void          SizeCheck();
} // gen:ns_print_proto

// --- samp_regx.trace..Print
// print string representation of samp_regx::trace to string LHS, no header -- cprint:samp_regx.trace.String
void samp_regx::trace_Print(samp_regx::trace & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "samp_regx.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- samp_regx.FDb._db.ReadArgv
// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     samp_regx.FDb.cmdline
//     algo_lib.FDb.cmdline
void samp_regx::ReadArgv() {
    command::samp_regx &cmd = samp_regx::_db.cmdline;
    algo_lib::Cmdline &base = algo_lib::_db.cmdline;
    int needarg=-1;// unknown
    int argidx=1;// skip process name
    int anonidx=0;
    algo::strptr nextanon = command::samp_regx_GetAnon(cmd, anonidx);
    tempstr err;
    algo::strptr attrname;
    bool isanon=false; // true if attrname is anonfld (positional)
    algo_lib::FieldId baseattrid;
    command::FieldId attrid;
    bool endopt=false;
    int whichns=0;// which namespace does the current attribute belong to
    bool expr_present = false;
    for (; argidx < algo_lib::_db.argc; argidx++) {
        algo::strptr arg = algo_lib::_db.argv[argidx];
        algo::strptr attrval;
        algo::strptr dfltval;
        bool haveval=false;
        bool dash=elems_N(arg)>1 && arg.elems[0]=='-'; // a single dash is not an option
        // this attribute is a value
        if (endopt || needarg>0 || !dash) {
            attrval=arg;
            haveval=true;
        } else {
            // this attribute is a field name (with - or --)
            // or a -- by itself
            bool dashdash = elems_N(arg) >= 2 && arg.elems[1]=='-';
            int skip = int(dash) + dashdash;
            attrname=ch_RestFrom(arg,skip);
            if (skip==2 && elems_N(arg)==2) {
                endopt=true;
                continue;// nothing else to do here
            }
            // parse "-a:B" arg into attrname,attrvalue
            algo::i32_Range colon = TFind(attrname,':');
            if (colon.beg < colon.end) {
                attrval=ch_RestFrom(attrname,colon.end);
                attrname=ch_FirstN(attrname,colon.beg);
                haveval=true;
            }
            // look up which command (this one or the base) contains the field
            whichns=0;
            needarg=-1;
            // look up parameter information in base namespace (needarg will be -1 if lookup fails)
            if (algo_lib::FieldId_ReadStrptrMaybe(baseattrid,attrname)) {
                needarg = algo_lib::Cmdline_NArgs(baseattrid,dfltval,&isanon);
            }
            if (needarg<0) {
                whichns=1;
                // look up parameter information in this namespace (needarg will be -1 if lookup fails)
                if (command::FieldId_ReadStrptrMaybe(attrid,attrname)) {
                    needarg = command::samp_regx_NArgs(attrid,dfltval,&isanon);
                }
            }
            if (attrval == "" && dfltval != "") {
                attrval=dfltval;
                haveval=true;
            }
            if (needarg<0) {
                err<<"samp_regx: unknown option "<<Keyval("value",arg)<<eol;
            } else {
                if (isanon) {
                    if (attrname == nextanon) { // treat named anon (positional) argument as unnamed
                        attrname = ""; // treat it as unnamed
                    } else if (nextanon != "") { // disallow out-of-order anon (positional) args
                        err<<"samp_regx: error at "<<algo::strptr_ToSsim(arg)<<": must be preceded by [-"<<nextanon<<"]"<<eol;
                    }
                }
            }
        }
        // look up anon field name based on index
        // anon fields are only allowed in the leaf ns, never base
        if (ch_N(attrname) == 0) {
            attrname = nextanon;
            nextanon = command::samp_regx_GetAnon(cmd, ++anonidx);
            command::FieldId_ReadStrptrMaybe(attrid,attrname);
            whichns=1;
        }
        if (ch_N(attrname) == 0) {
            err << "samp_regx: too many arguments. error at "<<algo::strptr_ToSsim(arg)<<eol;
        }
        // read value into currently selected arg
        if (haveval) {
            bool ret=false;
            // it's already known which namespace is consuming the args,
            // so directly go there
            if (whichns == 0) {
                ret=algo_lib::Cmdline_ReadFieldMaybe(base, attrname, attrval);
            }
            if (whichns==1) {
                ret=command::samp_regx_ReadFieldMaybe(cmd, attrname, attrval);
                switch(attrid.value) {
                    case command_FieldId_expr: expr_present=true; break;
                    default:break;
                }
            }
            if (!ret) {
                err<<"samp_regx: error in "
                <<Keyval("option",attrname)
                <<Keyval("value",attrval)<<eol;
            }
            needarg--;
            if (needarg <= 0) {
                attrname="";// forget which argument was being filled
            }
        }
    }
    bool dohelp = false;
    bool doexit=false;
    if (algo_lib::_db.cmdline.help) {
        dohelp = true;
        doexit = true;
        algo_lib::_db.exit_code = 1; // help exits with non-zero status code
    } else if (algo_lib::_db.cmdline.version) {
        // -ver output goes to stdout
        prlog(algo::gitinfo_Get());
        doexit = true;
    } else if (algo_lib::_db.cmdline.signature) {
        ind_beg(algo_lib::_db_dispsigcheck_curs,dispsigcheck,algo_lib::_db) {
            // dispsig goes to stdout
            dmmeta::Dispsigcheck out;
            dispsigcheck_CopyOut(dispsigcheck,out);
            prlog(out);
        }ind_end
        doexit = true;
    }
    if (!dohelp) {
        if (!expr_present) {
            err << "samp_regx: Missing value for required argument -expr (see -help)" << eol;
            doexit = true;
        }
    }
    if (err != "") {
        algo_lib::_db.exit_code=1;
        prerr(err);
        doexit=true;
    }
    if (dohelp) {
        prlog(samp_regx_help);
    }
    if (doexit) {
        _exit(algo_lib::_db.exit_code);
    }
    algo_lib::ResetErrtext();
    vrfy(samp_regx::LoadTuplesMaybe(cmd.in,true)
    ,tempstr()<<"where:load_input  "<<algo_lib::DetachBadTags());
}

// --- samp_regx.FDb._db.MainLoop
// Main loop.
void samp_regx::MainLoop() {
    algo::SchedTime time(algo::get_cycles());
    algo_lib::_db.clock          = time;
    do {
        algo_lib::_db.next_loop.value = algo_lib::_db.limit;
        samp_regx::Steps();
    } while (algo_lib::_db.next_loop < algo_lib::_db.limit);
}

// --- samp_regx.FDb._db.Step
// Main step
void samp_regx::Step() {
}

// --- samp_regx.FDb._db.InitReflection
// Load statically available data into tables, register tables and database.
static void samp_regx::InitReflection() {
    algo_lib::imdb_InsertMaybe(algo::Imdb("samp_regx", NULL, NULL, samp_regx::MainLoop, NULL, algo::Comment()));

    algo::Imtable t_trace;
    t_trace.imtable         = "samp_regx.trace";
    t_trace.ssimfile        = "";
    t_trace.size            = sizeof(samp_regx::trace);
    t_trace.comment.value   = "";
    t_trace.c_RowidFind     = trace_RowidFind;
    t_trace.NItems          = trace_N;
    t_trace.Print           = (algo::ImrowPrintFcn)samp_regx::trace_Print;
    algo_lib::imtable_InsertMaybe(t_trace);


    // -- load signatures of existing dispatches --
}

// --- samp_regx.FDb._db.StaticCheck
void samp_regx::StaticCheck() {
    algo_assert(_offset_of(samp_regx::FieldId, value) + sizeof(((samp_regx::FieldId*)0)->value) == sizeof(samp_regx::FieldId));
}

// --- samp_regx.FDb._db.InsertStrptrMaybe
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool samp_regx::InsertStrptrMaybe(algo::strptr str) {
    bool retval = true;
    (void)str;//only to avoid -Wunused-parameter
    return retval;
}

// --- samp_regx.FDb._db.LoadTuplesMaybe
// Load all finputs from given directory.
bool samp_regx::LoadTuplesMaybe(algo::strptr root, bool recursive) {
    bool retval = true;
    if (FileQ(root)) {
        retval = samp_regx::LoadTuplesFile(root, recursive);
    } else if (root == "-") {
        retval = samp_regx::LoadTuplesFd(algo::Fildes(0),"(stdin)",recursive);
    } else if (DirectoryQ(root)) {
        retval = retval && samp_regx::LoadTuplesFile(algo::SsimFname(root,"dmmeta.dispsigcheck"),recursive);
    } else {
        algo_lib::SaveBadTag("path", root);
        algo_lib::SaveBadTag("comment", "Wrong working directory?");
        retval = false;
    }
    return retval;
}

// --- samp_regx.FDb._db.LoadTuplesFile
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
bool samp_regx::LoadTuplesFile(algo::strptr fname, bool recursive) {
    bool retval = true;
    algo_lib::FFildes fildes;
    fildes.fd = OpenRead(fname,algo::FileFlags());
    if (ValidQ(fildes.fd)) {
        retval = LoadTuplesFd(fildes.fd, fname, recursive);
    }
    return retval;
}

// --- samp_regx.FDb._db.LoadTuplesFd
// Load all finputs from given file descriptor.
bool samp_regx::LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) {
    bool retval = true;
    ind_beg(algo::FileLine_curs,line,fd) {
        if (recursive) {
            retval = retval && algo_lib::InsertStrptrMaybe(line);
        }
        if (!retval) {
            algo_lib::_db.errtext << eol
            << fname << ":"
            << (ind_curs(line).i+1)
            << ": " << line << eol;
            break;
        }
    }ind_end;
    return retval;
}

// --- samp_regx.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool samp_regx::LoadSsimfileMaybe(algo::strptr fname, bool recursive) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = samp_regx::LoadTuplesFile(fname, recursive);
    }
    return retval;
}

// --- samp_regx.FDb._db.Steps
// Calls Step function of dependencies
void samp_regx::Steps() {
    algo_lib::Step(); // dependent namespace specified via (dev.targdep)
}

// --- samp_regx.FDb._db.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool samp_regx::_db_XrefMaybe() {
    bool retval = true;
    return retval;
}

// --- samp_regx.FDb.trace.RowidFind
// find trace by row id (used to implement reflection)
static algo::ImrowPtr samp_regx::trace_RowidFind(int t) {
    return algo::ImrowPtr(t==0 ? u64(&_db.trace) : u64(0));
}

// --- samp_regx.FDb.trace.N
// Function return 1
inline static i32 samp_regx::trace_N() {
    return 1;
}

// --- samp_regx.FDb..Init
// Set all fields to initial values.
void samp_regx::FDb_Init() {

    samp_regx::InitReflection();
}

// --- samp_regx.FDb..Uninit
void samp_regx::FDb_Uninit() {
    samp_regx::FDb &row = _db; (void)row;
}

// --- samp_regx.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* samp_regx::value_ToCstr(const samp_regx::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case samp_regx_FieldId_value       : ret = "value";  break;
    }
    return ret;
}

// --- samp_regx.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void samp_regx::value_Print(const samp_regx::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- samp_regx.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool samp_regx::value_SetStrptrMaybe(samp_regx::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,samp_regx_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- samp_regx.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void samp_regx::value_SetStrptr(samp_regx::FieldId& parent, algo::strptr rhs, samp_regx_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- samp_regx.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool samp_regx::value_ReadStrptrMaybe(samp_regx::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- samp_regx.FieldId..ReadStrptrMaybe
// Read fields of samp_regx::FieldId from an ascii string.
// The format of the string is the format of the samp_regx::FieldId's only field
bool samp_regx::FieldId_ReadStrptrMaybe(samp_regx::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- samp_regx.FieldId..Print
// print string representation of samp_regx::FieldId to string LHS, no header -- cprint:samp_regx.FieldId.String
void samp_regx::FieldId_Print(samp_regx::FieldId & row, algo::cstring &str) {
    samp_regx::value_Print(row, str);
}

// --- samp_regx...SizeCheck
inline static void samp_regx::SizeCheck() {
}

// --- samp_regx...main
int main(int argc, char **argv) {
    try {
        lib_json::FDb_Init();
        algo_lib::FDb_Init();
        samp_regx::FDb_Init();
        algo_lib::_db.argc = argc;
        algo_lib::_db.argv = argv;
        algo_lib::IohookInit();
        samp_regx::ReadArgv(); // dmmeta.main:samp_regx
        samp_regx::Main(); // user-defined main
    } catch(algo_lib::ErrorX &x) {
        prerr("samp_regx.error  " << x); // there may be additional hints in DetachBadTags
        algo_lib::_db.exit_code = 1;
    }
    if (algo_lib::_db.last_signal) {
        algo_lib::_db.exit_code = 1;
    }
    try {
        samp_regx::FDb_Uninit();
        algo_lib::FDb_Uninit();
        lib_json::FDb_Uninit();
    } catch(algo_lib::ErrorX &) {
        // don't print anything, might crash
        algo_lib::_db.exit_code = 1;
    }
    // only the lower 1 byte makes it to the outside world
    (void)i32_UpdateMin(algo_lib::_db.exit_code,255);
    return algo_lib::_db.exit_code;
}

// --- samp_regx...WinMain
#if defined(WIN32)
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
    return main(__argc,__argv);
}
#endif
