//
// cpp/gen/helloworld_gen.cpp
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
#include "include/gen/helloworld_gen.h"
#include "include/gen/helloworld_gen.inl.h"
#include "include/gen/command_gen.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/lib_json_gen.h"
#include "include/gen/lib_json_gen.inl.h"
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_lib_gen.inl.h"
#include "include/gen/lib_prot_gen.h"
#include "include/gen/lib_prot_gen.inl.h"
//#pragma endinclude

// Instantiate all libraries linked into this executable,
// in dependency order
lib_json::FDb     lib_json::_db;      // dependency found via dev.targdep
algo_lib::FDb     algo_lib::_db;      // dependency found via dev.targdep
helloworld::FDb   helloworld::_db;    // dependency found via dev.targdep

namespace helloworld {
const char *helloworld_help =
"Usage: helloworld [options]\n"
"    OPTION      TYPE    DFLT    COMMENT\n"
"    -in         string  \"data\"  Input directory or filename, - for stdin\n"
"    -verbose    int             Verbosity level (0..255); alias -v; cumulative\n"
"    -debug      int             Debug level (0..255); alias -d; cumulative\n"
"    -help                       Print help and exit; alias -h\n"
"    -version                    Print version and exit\n"
"    -signature                  Show signatures and exit; alias -sig\n"
;


} // namespace helloworld
namespace helloworld { // gen:ns_print_proto
    // Load statically available data into tables, register tables and database.
    static void          InitReflection();
    // find trace by row id (used to implement reflection)
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    static i32           trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    static void          SizeCheck();
} // gen:ns_print_proto

// --- helloworld.trace..Print
// print string representation of helloworld::trace to string LHS, no header -- cprint:helloworld.trace.String
void helloworld::trace_Print(helloworld::trace & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "helloworld.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- helloworld.FDb._db.ReadArgv
// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     helloworld.FDb.cmdline
//     algo_lib.FDb.cmdline
void helloworld::ReadArgv() {
    command::helloworld &cmd = helloworld::_db.cmdline;
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
                    needarg = command::helloworld_NArgs(attrid,dfltval,&isanon);
                }
            }
            if (attrval == "" && dfltval != "") {
                attrval=dfltval;
                haveval=true;
            }
            if (needarg<0) {
                err<<"helloworld: unknown option "<<Keyval("value",arg)<<eol;
            } else {
            }
        }
        if (ch_N(attrname) == 0) {
            err << "helloworld: too many arguments. error at "<<algo::strptr_ToSsim(arg)<<eol;
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
                ret=command::helloworld_ReadFieldMaybe(cmd, attrname, attrval);
                switch(attrid.value) {
                    default:break;
                }
            }
            if (!ret) {
                err<<"helloworld: error in "
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
        prlog(helloworld_help);
    }
    if (doexit) {
        _exit(algo_lib::_db.exit_code);
    }
    algo_lib::ResetErrtext();
    vrfy(helloworld::LoadTuplesMaybe(cmd.in,true)
    ,tempstr()<<"where:load_input  "<<algo_lib::DetachBadTags());
}

// --- helloworld.FDb._db.MainLoop
// Main loop.
void helloworld::MainLoop() {
    algo::SchedTime time(algo::get_cycles());
    algo_lib::_db.clock          = time;
    do {
        algo_lib::_db.next_loop.value = algo_lib::_db.limit;
        helloworld::Steps();
    } while (algo_lib::_db.next_loop < algo_lib::_db.limit);
}

// --- helloworld.FDb._db.Step
// Main step
void helloworld::Step() {
}

// --- helloworld.FDb._db.InitReflection
// Load statically available data into tables, register tables and database.
static void helloworld::InitReflection() {
    algo_lib::imdb_InsertMaybe(algo::Imdb("helloworld", NULL, NULL, helloworld::MainLoop, NULL, algo::Comment()));

    algo::Imtable t_trace;
    t_trace.imtable         = "helloworld.trace";
    t_trace.ssimfile        = "";
    t_trace.size            = sizeof(helloworld::trace);
    t_trace.comment.value   = "";
    t_trace.c_RowidFind     = trace_RowidFind;
    t_trace.NItems          = trace_N;
    t_trace.Print           = (algo::ImrowPrintFcn)helloworld::trace_Print;
    algo_lib::imtable_InsertMaybe(t_trace);


    // -- load signatures of existing dispatches --
}

// --- helloworld.FDb._db.StaticCheck
void helloworld::StaticCheck() {
    algo_assert(_offset_of(helloworld::FieldId, value) + sizeof(((helloworld::FieldId*)0)->value) == sizeof(helloworld::FieldId));
}

// --- helloworld.FDb._db.InsertStrptrMaybe
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool helloworld::InsertStrptrMaybe(algo::strptr str) {
    bool retval = true;
    (void)str;//only to avoid -Wunused-parameter
    return retval;
}

// --- helloworld.FDb._db.LoadTuplesMaybe
// Load all finputs from given directory.
bool helloworld::LoadTuplesMaybe(algo::strptr root, bool recursive) {
    bool retval = true;
    if (FileQ(root)) {
        retval = helloworld::LoadTuplesFile(root, recursive);
    } else if (root == "-") {
        retval = helloworld::LoadTuplesFd(algo::Fildes(0),"(stdin)",recursive);
    } else if (DirectoryQ(root)) {
        retval = retval && helloworld::LoadTuplesFile(algo::SsimFname(root,"dmmeta.dispsigcheck"),recursive);
    } else {
        algo_lib::SaveBadTag("path", root);
        algo_lib::SaveBadTag("comment", "Wrong working directory?");
        retval = false;
    }
    return retval;
}

// --- helloworld.FDb._db.LoadTuplesFile
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
bool helloworld::LoadTuplesFile(algo::strptr fname, bool recursive) {
    bool retval = true;
    algo_lib::FFildes fildes;
    // missing files are not an error
    fildes.fd = OpenRead(fname,algo::FileFlags());
    if (ValidQ(fildes.fd)) {
        retval = LoadTuplesFd(fildes.fd, fname, recursive);
    }
    return retval;
}

// --- helloworld.FDb._db.LoadTuplesFd
// Load all finputs from given file descriptor.
bool helloworld::LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) {
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

// --- helloworld.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool helloworld::LoadSsimfileMaybe(algo::strptr fname, bool recursive) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = helloworld::LoadTuplesFile(fname, recursive);
    }
    return retval;
}

// --- helloworld.FDb._db.Steps
// Calls Step function of dependencies
void helloworld::Steps() {
    algo_lib::Step(); // dependent namespace specified via (dev.targdep)
}

// --- helloworld.FDb._db.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool helloworld::_db_XrefMaybe() {
    bool retval = true;
    return retval;
}

// --- helloworld.FDb.trace.RowidFind
// find trace by row id (used to implement reflection)
static algo::ImrowPtr helloworld::trace_RowidFind(int t) {
    return algo::ImrowPtr(t==0 ? u64(&_db.trace) : u64(0));
}

// --- helloworld.FDb.trace.N
// Function return 1
inline static i32 helloworld::trace_N() {
    return 1;
}

// --- helloworld.FDb..Init
// Set all fields to initial values.
void helloworld::FDb_Init() {

    helloworld::InitReflection();
}

// --- helloworld.FDb..Uninit
void helloworld::FDb_Uninit() {
    helloworld::FDb &row = _db; (void)row;
}

// --- helloworld.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* helloworld::value_ToCstr(const helloworld::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case helloworld_FieldId_value      : ret = "value";  break;
    }
    return ret;
}

// --- helloworld.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void helloworld::value_Print(const helloworld::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- helloworld.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool helloworld::value_SetStrptrMaybe(helloworld::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,helloworld_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- helloworld.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void helloworld::value_SetStrptr(helloworld::FieldId& parent, algo::strptr rhs, helloworld_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- helloworld.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool helloworld::value_ReadStrptrMaybe(helloworld::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- helloworld.FieldId..ReadStrptrMaybe
// Read fields of helloworld::FieldId from an ascii string.
// The format of the string is the format of the helloworld::FieldId's only field
bool helloworld::FieldId_ReadStrptrMaybe(helloworld::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- helloworld.FieldId..Print
// print string representation of helloworld::FieldId to string LHS, no header -- cprint:helloworld.FieldId.String
void helloworld::FieldId_Print(helloworld::FieldId & row, algo::cstring &str) {
    helloworld::value_Print(row, str);
}

// --- helloworld...SizeCheck
inline static void helloworld::SizeCheck() {
}

// --- helloworld...main
int main(int argc, char **argv) {
    try {
        lib_json::FDb_Init();
        algo_lib::FDb_Init();
        helloworld::FDb_Init();
        algo_lib::_db.argc = argc;
        algo_lib::_db.argv = argv;
        algo_lib::IohookInit();
        helloworld::ReadArgv(); // dmmeta.main:helloworld
        helloworld::Main(); // user-defined main
    } catch(algo_lib::ErrorX &x) {
        prerr("helloworld.error  " << x); // there may be additional hints in DetachBadTags
        algo_lib::_db.exit_code = 1;
    }
    if (algo_lib::_db.last_signal) {
        algo_lib::_db.exit_code = 1;
    }
    try {
        helloworld::FDb_Uninit();
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

// --- helloworld...WinMain
#if defined(WIN32)
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
    return main(__argc,__argv);
}
#endif
