//
// cpp/gen/ams_cat_gen.cpp
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
#include "include/gen/ams_cat_gen.h"
#include "include/gen/ams_cat_gen.inl.h"
#include "include/gen/command_gen.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/lib_json_gen.h"
#include "include/gen/lib_json_gen.inl.h"
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_lib_gen.inl.h"
#include "include/gen/lib_prot_gen.h"
#include "include/gen/lib_prot_gen.inl.h"
#include "include/gen/lib_ams_gen.h"
#include "include/gen/lib_ams_gen.inl.h"
//#pragma endinclude

// Instantiate all libraries linked into this executable,
// in dependency order
lib_json::FDb   lib_json::_db;    // dependency found via dev.targdep
algo_lib::FDb   algo_lib::_db;    // dependency found via dev.targdep
lib_ams::FDb    lib_ams::_db;     // dependency found via dev.targdep
ams_cat::FDb    ams_cat::_db;     // dependency found via dev.targdep

namespace ams_cat {
const char *ams_cat_help =
"ams_cat: Algo Messaging System sample tool\n"
"Usage: ams_cat [options]\n"
"    OPTION      TYPE    DFLT    COMMENT\n"
"    -in         string  \"data\"  Input directory or filename, - for stdin\n"
"    -verbose    int             Verbosity level (0..255); alias -v; cumulative\n"
"    -debug      int             Debug level (0..255); alias -d; cumulative\n"
"    -help                       Print help and exit; alias -h\n"
"    -version                    Print version and exit\n"
"    -signature                  Show signatures and exit; alias -sig\n"
;


} // namespace ams_cat
namespace ams_cat { // gen:ns_print_proto
    // Load statically available data into tables, register tables and database.
    static void          InitReflection();
    // find trace by row id (used to implement reflection)
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    static i32           trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    static void          SizeCheck();
} // gen:ns_print_proto

// --- ams_cat.trace..Print
// print string representation of ams_cat::trace to string LHS, no header -- cprint:ams_cat.trace.String
void ams_cat::trace_Print(ams_cat::trace & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "ams_cat.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- ams_cat.FDb._db.ReadArgv
// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     ams_cat.FDb.cmdline
//     algo_lib.FDb.cmdline
void ams_cat::ReadArgv() {
    command::ams_cat &cmd = ams_cat::_db.cmdline;
    algo_lib::Cmdline &base = algo_lib::_db.cmdline;
    int needarg=-1;// unknown
    int argidx=1;// skip process name
    tempstr err;
    algo::strptr attrname;
    bool isanon=false; // true if attrname is anonfld (positional)
    algo_lib::FieldId baseattrid;
    command::FieldId attrid;
    bool endopt=false;
    int whichns=0;// which namespace does the current attribute belong to
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
                    needarg = command::ams_cat_NArgs(attrid,dfltval,&isanon);
                }
            }
            if (attrval == "" && dfltval != "") {
                attrval=dfltval;
                haveval=true;
            }
            if (needarg<0) {
                err<<"ams_cat: unknown option "<<Keyval("value",arg)<<eol;
            } else {
            }
        }
        if (ch_N(attrname) == 0) {
            err << "ams_cat: too many arguments. error at "<<algo::strptr_ToSsim(arg)<<eol;
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
                ret=command::ams_cat_ReadFieldMaybe(cmd, attrname, attrval);
                switch(attrid.value) {
                    default:break;
                }
            }
            if (!ret) {
                err<<"ams_cat: error in "
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
    }
    if (err != "") {
        algo_lib::_db.exit_code=1;
        prerr(err);
        doexit=true;
    }
    if (dohelp) {
        prlog(ams_cat_help);
    }
    if (doexit) {
        _exit(algo_lib::_db.exit_code);
    }
    algo_lib::ResetErrtext();
    vrfy(ams_cat::LoadTuplesMaybe(cmd.in,true)
    ,tempstr()<<"where:load_input  "<<algo_lib::DetachBadTags());
}

// --- ams_cat.FDb._db.MainLoop
// Main loop.
void ams_cat::MainLoop() {
    algo::SchedTime time(algo::get_cycles());
    algo_lib::_db.clock          = time;
    do {
        algo_lib::_db.next_loop.value = algo_lib::_db.limit;
        ams_cat::Steps();
    } while (algo_lib::_db.next_loop < algo_lib::_db.limit);
}

// --- ams_cat.FDb._db.Step
// Main step
void ams_cat::Step() {
}

// --- ams_cat.FDb._db.InitReflection
// Load statically available data into tables, register tables and database.
static void ams_cat::InitReflection() {
    algo_lib::imdb_InsertMaybe(algo::Imdb("ams_cat", NULL, NULL, ams_cat::MainLoop, NULL, algo::Comment()));

    algo::Imtable t_trace;
    t_trace.imtable         = "ams_cat.trace";
    t_trace.ssimfile        = "";
    t_trace.size            = sizeof(ams_cat::trace);
    t_trace.comment.value   = "";
    t_trace.c_RowidFind     = trace_RowidFind;
    t_trace.NItems          = trace_N;
    t_trace.Print           = (algo::ImrowPrintFcn)ams_cat::trace_Print;
    algo_lib::imtable_InsertMaybe(t_trace);


    // -- load signatures of existing dispatches --
}

// --- ams_cat.FDb._db.StaticCheck
void ams_cat::StaticCheck() {
    algo_assert(_offset_of(ams_cat::FieldId, value) + sizeof(((ams_cat::FieldId*)0)->value) == sizeof(ams_cat::FieldId));
}

// --- ams_cat.FDb._db.InsertStrptrMaybe
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool ams_cat::InsertStrptrMaybe(algo::strptr str) {
    bool retval = true;
    (void)str;//only to avoid -Wunused-parameter
    return retval;
}

// --- ams_cat.FDb._db.LoadTuplesMaybe
// Load all finputs from given directory.
bool ams_cat::LoadTuplesMaybe(algo::strptr root, bool recursive) {
    bool retval = true;
    if (FileQ(root)) {
        retval = ams_cat::LoadTuplesFile(root, recursive);
    } else if (root == "-") {
        retval = ams_cat::LoadTuplesFd(algo::Fildes(0),"(stdin)",recursive);
    } else if (DirectoryQ(root)) {
        retval = retval && ams_cat::LoadTuplesFile(algo::SsimFname(root,"dmmeta.dispsigcheck"),recursive);
    } else {
        algo_lib::SaveBadTag("path", root);
        algo_lib::SaveBadTag("comment", "Wrong working directory?");
        retval = false;
    }
    return retval;
}

// --- ams_cat.FDb._db.LoadTuplesFile
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
bool ams_cat::LoadTuplesFile(algo::strptr fname, bool recursive) {
    bool retval = true;
    algo_lib::FFildes fildes;
    fildes.fd = OpenRead(fname,algo::FileFlags());
    if (ValidQ(fildes.fd)) {
        retval = LoadTuplesFd(fildes.fd, fname, recursive);
    }
    return retval;
}

// --- ams_cat.FDb._db.LoadTuplesFd
// Load all finputs from given file descriptor.
bool ams_cat::LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) {
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

// --- ams_cat.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool ams_cat::LoadSsimfileMaybe(algo::strptr fname, bool recursive) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = ams_cat::LoadTuplesFile(fname, recursive);
    }
    return retval;
}

// --- ams_cat.FDb._db.Steps
// Calls Step function of dependencies
void ams_cat::Steps() {
    lib_ams::Step(); // dependent namespace specified via (dev.targdep)
    algo_lib::Step(); // dependent namespace specified via (dev.targdep)
}

// --- ams_cat.FDb._db.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool ams_cat::_db_XrefMaybe() {
    bool retval = true;
    return retval;
}

// --- ams_cat.FDb.trace.RowidFind
// find trace by row id (used to implement reflection)
static algo::ImrowPtr ams_cat::trace_RowidFind(int t) {
    return algo::ImrowPtr(t==0 ? u64(&_db.trace) : u64(0));
}

// --- ams_cat.FDb.trace.N
// Function return 1
inline static i32 ams_cat::trace_N() {
    return 1;
}

// --- ams_cat.FDb..Init
// Set all fields to initial values.
void ams_cat::FDb_Init() {

    ams_cat::InitReflection();
}

// --- ams_cat.FDb..Uninit
void ams_cat::FDb_Uninit() {
    ams_cat::FDb &row = _db; (void)row;
}

// --- ams_cat.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* ams_cat::value_ToCstr(const ams_cat::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case ams_cat_FieldId_value         : ret = "value";  break;
    }
    return ret;
}

// --- ams_cat.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void ams_cat::value_Print(const ams_cat::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- ams_cat.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool ams_cat::value_SetStrptrMaybe(ams_cat::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,ams_cat_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- ams_cat.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void ams_cat::value_SetStrptr(ams_cat::FieldId& parent, algo::strptr rhs, ams_cat_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- ams_cat.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool ams_cat::value_ReadStrptrMaybe(ams_cat::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- ams_cat.FieldId..ReadStrptrMaybe
// Read fields of ams_cat::FieldId from an ascii string.
// The format of the string is the format of the ams_cat::FieldId's only field
bool ams_cat::FieldId_ReadStrptrMaybe(ams_cat::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- ams_cat.FieldId..Print
// print string representation of ams_cat::FieldId to string LHS, no header -- cprint:ams_cat.FieldId.String
void ams_cat::FieldId_Print(ams_cat::FieldId & row, algo::cstring &str) {
    ams_cat::value_Print(row, str);
}

// --- ams_cat...SizeCheck
inline static void ams_cat::SizeCheck() {
}

// --- ams_cat...main
int main(int argc, char **argv) {
    try {
        lib_json::FDb_Init();
        algo_lib::FDb_Init();
        lib_ams::FDb_Init();
        ams_cat::FDb_Init();
        algo_lib::_db.argc = argc;
        algo_lib::_db.argv = argv;
        algo_lib::IohookInit();
        ams_cat::ReadArgv(); // dmmeta.main:ams_cat
        ams_cat::Main(); // user-defined main
    } catch(algo_lib::ErrorX &x) {
        prerr("ams_cat.error  " << x); // there may be additional hints in DetachBadTags
        algo_lib::_db.exit_code = 1;
    }
    if (algo_lib::_db.last_signal) {
        algo_lib::_db.exit_code = 1;
    }
    try {
        ams_cat::FDb_Uninit();
        lib_ams::FDb_Uninit();
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

// --- ams_cat...WinMain
#if defined(WIN32)
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
    return main(__argc,__argv);
}
#endif
