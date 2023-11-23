//
// cpp/gen/ssimfilt_gen.cpp
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
#include "include/gen/ssimfilt_gen.h"
#include "include/gen/ssimfilt_gen.inl.h"
#include "include/gen/command_gen.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/algo_gen.h"
#include "include/gen/algo_gen.inl.h"
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_lib_gen.inl.h"
#include "include/gen/lib_json_gen.h"
#include "include/gen/lib_json_gen.inl.h"
//#pragma endinclude

// Instantiate all libraries linked into this executable,
// in dependency order
lib_json::FDb   lib_json::_db;    // dependency found via dev.targdep
algo_lib::FDb   algo_lib::_db;    // dependency found via dev.targdep
ssimfilt::FDb   ssimfilt::_db;    // dependency found via dev.targdep

namespace ssimfilt {
const char *ssimfilt_help =
"ssimfilt: Tuple utility\n"
"Usage: ssimfilt [[-typetag:]<regx>] [[-match:]<string>] [options]\n"
"    OPTION      TYPE    DFLT    COMMENT\n"
"    -in         string  \"data\"  Input directory or filename, - for stdin\n"
"    [typetag]   regx    \"%\"     (filter) Match typetag. ^=first encountered typetag\n"
"    [match]...  string          (filter) Select input tuple if value of key matches value (regx:regx)\n"
"    -field...   string          (project) Select fields for output (regx)\n"
"    -format     int     ssim    Output format for selected tuples (ssim|csv|field|cmd|table)\n"
"                                    ssim  Print selected/filtered tuples\n"
"                                    csv  First tuple determines header. CSV quoting is used. Newlines are removed\n"
"                                    field  Print selected fields, one per line\n"
"                                    cmd  Emit command for each tuple (implied if -cmd is set)\n"
"                                    table  ASCII table for each group of tuples\n"
"    -t                          Alias for -format:table\n"
"    -cmd        string  \"\"      Command to output\n"
"    -verbose    int             Verbosity level (0..255); alias -v; cumulative\n"
"    -debug      int             Debug level (0..255); alias -d; cumulative\n"
"    -help                       Print help and exit; alias -h\n"
"    -version                    Print version and exit\n"
"    -signature                  Show signatures and exit; alias -sig\n"
;


} // namespace ssimfilt
namespace ssimfilt { // gen:ns_print_proto
    // Load statically available data into tables, register tables and database.
    static void          InitReflection();
    // find trace by row id (used to implement reflection)
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    static i32           trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    static void          SizeCheck();
} // gen:ns_print_proto

// --- ssimfilt.trace..Print
// print string representation of ssimfilt::trace to string LHS, no header -- cprint:ssimfilt.trace.String
void ssimfilt::trace_Print(ssimfilt::trace & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "ssimfilt.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- ssimfilt.FDb._db.ReadArgv
// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     ssimfilt.FDb.cmdline
//     algo_lib.FDb.cmdline
void ssimfilt::ReadArgv() {
    command::ssimfilt &cmd = ssimfilt::_db.cmdline;
    algo_lib::Cmdline &base = algo_lib::_db.cmdline;
    int needarg=-1;// unknown
    int argidx=1;// skip process name
    int anonidx=0;
    algo::strptr nextanon = command::ssimfilt_GetAnon(cmd, anonidx);
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
                    needarg = command::ssimfilt_NArgs(attrid,dfltval,&isanon);
                }
            }
            if (attrval == "" && dfltval != "") {
                attrval=dfltval;
                haveval=true;
            }
            if (needarg<0) {
                err<<"ssimfilt: unknown option "<<Keyval("value",arg)<<eol;
            } else {
                if (isanon) {
                    if (attrname == nextanon) { // treat named anon (positional) argument as unnamed
                        attrname = ""; // treat it as unnamed
                    } else if (nextanon != "") { // disallow out-of-order anon (positional) args
                        err<<"ssimfilt: error at "<<algo::strptr_ToSsim(arg)<<": must be preceded by [-"<<nextanon<<"]"<<eol;
                    }
                }
            }
        }
        // look up anon field name based on index
        // anon fields are only allowed in the leaf ns, never base
        if (ch_N(attrname) == 0) {
            attrname = nextanon;
            nextanon = command::ssimfilt_GetAnon(cmd, ++anonidx);
            command::FieldId_ReadStrptrMaybe(attrid,attrname);
            whichns=1;
        }
        if (ch_N(attrname) == 0) {
            err << "ssimfilt: too many arguments. error at "<<algo::strptr_ToSsim(arg)<<eol;
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
                ret=command::ssimfilt_ReadFieldMaybe(cmd, attrname, attrval);
                switch(attrid.value) {
                    default:break;
                }
            }
            if (!ret) {
                err<<"ssimfilt: error in "
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
        prlog(ssimfilt_help);
    }
    if (doexit) {
        _exit(algo_lib::_db.exit_code);
    }
    algo_lib::ResetErrtext();
    vrfy(ssimfilt::LoadTuplesMaybe(cmd.in,true)
    ,tempstr()<<"where:load_input  "<<algo_lib::DetachBadTags());
}

// --- ssimfilt.FDb._db.MainLoop
// Main loop.
void ssimfilt::MainLoop() {
    algo::SchedTime time(algo::get_cycles());
    algo_lib::_db.clock          = time;
    do {
        algo_lib::_db.next_loop.value = algo_lib::_db.limit;
        ssimfilt::Steps();
    } while (algo_lib::_db.next_loop < algo_lib::_db.limit);
}

// --- ssimfilt.FDb._db.Step
// Main step
void ssimfilt::Step() {
}

// --- ssimfilt.FDb._db.InitReflection
// Load statically available data into tables, register tables and database.
static void ssimfilt::InitReflection() {
    algo_lib::imdb_InsertMaybe(algo::Imdb("ssimfilt", NULL, NULL, ssimfilt::MainLoop, NULL, algo::Comment()));

    algo::Imtable t_trace;
    t_trace.imtable         = "ssimfilt.trace";
    t_trace.ssimfile        = "";
    t_trace.size            = sizeof(ssimfilt::trace);
    t_trace.comment.value   = "";
    t_trace.c_RowidFind     = trace_RowidFind;
    t_trace.NItems          = trace_N;
    t_trace.Print           = (algo::ImrowPrintFcn)ssimfilt::trace_Print;
    algo_lib::imtable_InsertMaybe(t_trace);


    // -- load signatures of existing dispatches --
}

// --- ssimfilt.FDb._db.StaticCheck
void ssimfilt::StaticCheck() {
    algo_assert(_offset_of(ssimfilt::FieldId, value) + sizeof(((ssimfilt::FieldId*)0)->value) == sizeof(ssimfilt::FieldId));
}

// --- ssimfilt.FDb._db.InsertStrptrMaybe
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool ssimfilt::InsertStrptrMaybe(algo::strptr str) {
    bool retval = true;
    (void)str;//only to avoid -Wunused-parameter
    return retval;
}

// --- ssimfilt.FDb._db.LoadTuplesMaybe
// Load all finputs from given directory.
bool ssimfilt::LoadTuplesMaybe(algo::strptr root, bool recursive) {
    bool retval = true;
    if (FileQ(root)) {
        retval = ssimfilt::LoadTuplesFile(root, recursive);
    } else if (root == "-") {
        retval = ssimfilt::LoadTuplesFd(algo::Fildes(0),"(stdin)",recursive);
    } else if (DirectoryQ(root)) {
        retval = retval && ssimfilt::LoadTuplesFile(algo::SsimFname(root,"dmmeta.dispsigcheck"),recursive);
    } else {
        algo_lib::SaveBadTag("path", root);
        algo_lib::SaveBadTag("comment", "Wrong working directory?");
        retval = false;
    }
    return retval;
}

// --- ssimfilt.FDb._db.LoadTuplesFile
// Load all finputs from given file.
bool ssimfilt::LoadTuplesFile(algo::strptr fname, bool recursive) {
    bool retval = true;
    algo_lib::FFildes fildes;
    fildes.fd = OpenRead(fname,algo_FileFlags__throw);
    retval = LoadTuplesFd(fildes.fd, fname, recursive);
    return retval;
}

// --- ssimfilt.FDb._db.LoadTuplesFd
// Load all finputs from given file descriptor.
bool ssimfilt::LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) {
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

// --- ssimfilt.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool ssimfilt::LoadSsimfileMaybe(algo::strptr fname, bool recursive) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = ssimfilt::LoadTuplesFile(fname, recursive);
    }
    return retval;
}

// --- ssimfilt.FDb._db.Steps
// Calls Step function of dependencies
void ssimfilt::Steps() {
    algo_lib::Step(); // dependent namespace specified via (dev.targdep)
}

// --- ssimfilt.FDb._db.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool ssimfilt::_db_XrefMaybe() {
    bool retval = true;
    return retval;
}

// --- ssimfilt.FDb.tuple.Alloc
// Allocate memory for new default row.
// If out of memory, process is killed.
algo::Tuple& ssimfilt::tuple_Alloc() {
    algo::Tuple* row = tuple_AllocMaybe();
    if (UNLIKELY(row == NULL)) {
        FatalErrorExit("ssimfilt.out_of_mem  field:ssimfilt.FDb.tuple  comment:'Alloc failed'");
    }
    return *row;
}

// --- ssimfilt.FDb.tuple.AllocMaybe
// Allocate memory for new element. If out of memory, return NULL.
algo::Tuple* ssimfilt::tuple_AllocMaybe() {
    algo::Tuple *row = (algo::Tuple*)tuple_AllocMem();
    if (row) {
        new (row) algo::Tuple; // call constructor
    }
    return row;
}

// --- ssimfilt.FDb.tuple.AllocMem
// Allocate space for one element. If no memory available, return NULL.
void* ssimfilt::tuple_AllocMem() {
    u64 new_nelems     = _db.tuple_n+1;
    // compute level and index on level
    u64 bsr   = algo::u64_BitScanReverse(new_nelems);
    u64 base  = u64(1)<<bsr;
    u64 index = new_nelems-base;
    void *ret = NULL;
    // if level doesn't exist yet, create it
    algo::Tuple*  lev   = NULL;
    if (bsr < 32) {
        lev = _db.tuple_lary[bsr];
        if (!lev) {
            lev=(algo::Tuple*)algo_lib::malloc_AllocMem(sizeof(algo::Tuple) * (u64(1)<<bsr));
            _db.tuple_lary[bsr] = lev;
        }
    }
    // allocate element from this level
    if (lev) {
        _db.tuple_n = i32(new_nelems);
        ret = lev + index;
    }
    return ret;
}

// --- ssimfilt.FDb.tuple.RemoveAll
// Remove all elements from Lary
void ssimfilt::tuple_RemoveAll() {
    for (u64 n = _db.tuple_n; n>0; ) {
        n--;
        tuple_qFind(u64(n)).~Tuple(); // destroy last element
        _db.tuple_n = i32(n);
    }
}

// --- ssimfilt.FDb.tuple.RemoveLast
// Delete last element of array. Do nothing if array is empty.
void ssimfilt::tuple_RemoveLast() {
    u64 n = _db.tuple_n;
    if (n > 0) {
        n -= 1;
        tuple_qFind(u64(n)).~Tuple();
        _db.tuple_n = i32(n);
    }
}

// --- ssimfilt.FDb.matchfield.Alloc
// Allocate memory for new default row.
// If out of memory, process is killed.
ssimfilt::KVRegx& ssimfilt::matchfield_Alloc() {
    ssimfilt::KVRegx* row = matchfield_AllocMaybe();
    if (UNLIKELY(row == NULL)) {
        FatalErrorExit("ssimfilt.out_of_mem  field:ssimfilt.FDb.matchfield  comment:'Alloc failed'");
    }
    return *row;
}

// --- ssimfilt.FDb.matchfield.AllocMaybe
// Allocate memory for new element. If out of memory, return NULL.
ssimfilt::KVRegx* ssimfilt::matchfield_AllocMaybe() {
    ssimfilt::KVRegx *row = (ssimfilt::KVRegx*)matchfield_AllocMem();
    if (row) {
        new (row) ssimfilt::KVRegx; // call constructor
    }
    return row;
}

// --- ssimfilt.FDb.matchfield.AllocMem
// Allocate space for one element. If no memory available, return NULL.
void* ssimfilt::matchfield_AllocMem() {
    u64 new_nelems     = _db.matchfield_n+1;
    // compute level and index on level
    u64 bsr   = algo::u64_BitScanReverse(new_nelems);
    u64 base  = u64(1)<<bsr;
    u64 index = new_nelems-base;
    void *ret = NULL;
    // if level doesn't exist yet, create it
    ssimfilt::KVRegx*  lev   = NULL;
    if (bsr < 32) {
        lev = _db.matchfield_lary[bsr];
        if (!lev) {
            lev=(ssimfilt::KVRegx*)algo_lib::malloc_AllocMem(sizeof(ssimfilt::KVRegx) * (u64(1)<<bsr));
            _db.matchfield_lary[bsr] = lev;
        }
    }
    // allocate element from this level
    if (lev) {
        _db.matchfield_n = i32(new_nelems);
        ret = lev + index;
    }
    return ret;
}

// --- ssimfilt.FDb.matchfield.RemoveAll
// Remove all elements from Lary
void ssimfilt::matchfield_RemoveAll() {
    for (u64 n = _db.matchfield_n; n>0; ) {
        n--;
        matchfield_qFind(u64(n)).~KVRegx(); // destroy last element
        _db.matchfield_n = i32(n);
    }
}

// --- ssimfilt.FDb.matchfield.RemoveLast
// Delete last element of array. Do nothing if array is empty.
void ssimfilt::matchfield_RemoveLast() {
    u64 n = _db.matchfield_n;
    if (n > 0) {
        n -= 1;
        matchfield_qFind(u64(n)).~KVRegx();
        _db.matchfield_n = i32(n);
    }
}

// --- ssimfilt.FDb.matchfield.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool ssimfilt::matchfield_XrefMaybe(ssimfilt::KVRegx &row) {
    bool retval = true;
    (void)row;
    return retval;
}

// --- ssimfilt.FDb.selfield.Alloc
// Allocate memory for new default row.
// If out of memory, process is killed.
ssimfilt::KVRegx& ssimfilt::selfield_Alloc() {
    ssimfilt::KVRegx* row = selfield_AllocMaybe();
    if (UNLIKELY(row == NULL)) {
        FatalErrorExit("ssimfilt.out_of_mem  field:ssimfilt.FDb.selfield  comment:'Alloc failed'");
    }
    return *row;
}

// --- ssimfilt.FDb.selfield.AllocMaybe
// Allocate memory for new element. If out of memory, return NULL.
ssimfilt::KVRegx* ssimfilt::selfield_AllocMaybe() {
    ssimfilt::KVRegx *row = (ssimfilt::KVRegx*)selfield_AllocMem();
    if (row) {
        new (row) ssimfilt::KVRegx; // call constructor
    }
    return row;
}

// --- ssimfilt.FDb.selfield.AllocMem
// Allocate space for one element. If no memory available, return NULL.
void* ssimfilt::selfield_AllocMem() {
    u64 new_nelems     = _db.selfield_n+1;
    // compute level and index on level
    u64 bsr   = algo::u64_BitScanReverse(new_nelems);
    u64 base  = u64(1)<<bsr;
    u64 index = new_nelems-base;
    void *ret = NULL;
    // if level doesn't exist yet, create it
    ssimfilt::KVRegx*  lev   = NULL;
    if (bsr < 32) {
        lev = _db.selfield_lary[bsr];
        if (!lev) {
            lev=(ssimfilt::KVRegx*)algo_lib::malloc_AllocMem(sizeof(ssimfilt::KVRegx) * (u64(1)<<bsr));
            _db.selfield_lary[bsr] = lev;
        }
    }
    // allocate element from this level
    if (lev) {
        _db.selfield_n = i32(new_nelems);
        ret = lev + index;
    }
    return ret;
}

// --- ssimfilt.FDb.selfield.RemoveAll
// Remove all elements from Lary
void ssimfilt::selfield_RemoveAll() {
    for (u64 n = _db.selfield_n; n>0; ) {
        n--;
        selfield_qFind(u64(n)).~KVRegx(); // destroy last element
        _db.selfield_n = i32(n);
    }
}

// --- ssimfilt.FDb.selfield.RemoveLast
// Delete last element of array. Do nothing if array is empty.
void ssimfilt::selfield_RemoveLast() {
    u64 n = _db.selfield_n;
    if (n > 0) {
        n -= 1;
        selfield_qFind(u64(n)).~KVRegx();
        _db.selfield_n = i32(n);
    }
}

// --- ssimfilt.FDb.trace.RowidFind
// find trace by row id (used to implement reflection)
static algo::ImrowPtr ssimfilt::trace_RowidFind(int t) {
    return algo::ImrowPtr(t==0 ? u64(&_db.trace) : u64(0));
}

// --- ssimfilt.FDb.trace.N
// Function return 1
inline static i32 ssimfilt::trace_N() {
    return 1;
}

// --- ssimfilt.FDb..Init
// Set all fields to initial values.
void ssimfilt::FDb_Init() {
    // initialize LAry tuple (ssimfilt.FDb.tuple)
    _db.tuple_n = 0;
    memset(_db.tuple_lary, 0, sizeof(_db.tuple_lary)); // zero out all level pointers
    algo::Tuple* tuple_first = (algo::Tuple*)algo_lib::malloc_AllocMem(sizeof(algo::Tuple) * (u64(1)<<4));
    if (!tuple_first) {
        FatalErrorExit("out of memory");
    }
    for (int i = 0; i < 4; i++) {
        _db.tuple_lary[i]  = tuple_first;
        tuple_first    += 1ULL<<i;
    }
    // initialize LAry matchfield (ssimfilt.FDb.matchfield)
    _db.matchfield_n = 0;
    memset(_db.matchfield_lary, 0, sizeof(_db.matchfield_lary)); // zero out all level pointers
    ssimfilt::KVRegx* matchfield_first = (ssimfilt::KVRegx*)algo_lib::malloc_AllocMem(sizeof(ssimfilt::KVRegx) * (u64(1)<<4));
    if (!matchfield_first) {
        FatalErrorExit("out of memory");
    }
    for (int i = 0; i < 4; i++) {
        _db.matchfield_lary[i]  = matchfield_first;
        matchfield_first    += 1ULL<<i;
    }
    // initialize LAry selfield (ssimfilt.FDb.selfield)
    _db.selfield_n = 0;
    memset(_db.selfield_lary, 0, sizeof(_db.selfield_lary)); // zero out all level pointers
    ssimfilt::KVRegx* selfield_first = (ssimfilt::KVRegx*)algo_lib::malloc_AllocMem(sizeof(ssimfilt::KVRegx) * (u64(1)<<4));
    if (!selfield_first) {
        FatalErrorExit("out of memory");
    }
    for (int i = 0; i < 4; i++) {
        _db.selfield_lary[i]  = selfield_first;
        selfield_first    += 1ULL<<i;
    }
    _db.csv_locked = bool(false);

    ssimfilt::InitReflection();
}

// --- ssimfilt.FDb..Uninit
void ssimfilt::FDb_Uninit() {
    ssimfilt::FDb &row = _db; (void)row;

    // ssimfilt.FDb.selfield.Uninit (Lary)  //Select fields for output
    // skip destruction in global scope

    // ssimfilt.FDb.matchfield.Uninit (Lary)  //Input tuple filter. Comes from cmdline.match array
    // skip destruction in global scope

    // ssimfilt.FDb.tuple.Uninit (Lary)  //Accumulated tuples
    // skip destruction in global scope
}

// --- ssimfilt.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* ssimfilt::value_ToCstr(const ssimfilt::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case ssimfilt_FieldId_value        : ret = "value";  break;
    }
    return ret;
}

// --- ssimfilt.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void ssimfilt::value_Print(const ssimfilt::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- ssimfilt.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool ssimfilt::value_SetStrptrMaybe(ssimfilt::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,ssimfilt_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- ssimfilt.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void ssimfilt::value_SetStrptr(ssimfilt::FieldId& parent, algo::strptr rhs, ssimfilt_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- ssimfilt.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool ssimfilt::value_ReadStrptrMaybe(ssimfilt::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- ssimfilt.FieldId..ReadStrptrMaybe
// Read fields of ssimfilt::FieldId from an ascii string.
// The format of the string is the format of the ssimfilt::FieldId's only field
bool ssimfilt::FieldId_ReadStrptrMaybe(ssimfilt::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- ssimfilt.FieldId..Print
// print string representation of ssimfilt::FieldId to string LHS, no header -- cprint:ssimfilt.FieldId.String
void ssimfilt::FieldId_Print(ssimfilt::FieldId & row, algo::cstring &str) {
    ssimfilt::value_Print(row, str);
}

// --- ssimfilt.KVRegx.key.Print
// Print back to string
void ssimfilt::key_Print(ssimfilt::KVRegx& matchfield, algo::cstring &out) {
    Regx_Print(matchfield.key, out);
}

// --- ssimfilt.KVRegx.value.Print
// Print back to string
void ssimfilt::value_Print(ssimfilt::KVRegx& matchfield, algo::cstring &out) {
    Regx_Print(matchfield.value, out);
}

// --- ssimfilt...SizeCheck
inline static void ssimfilt::SizeCheck() {
}

// --- ssimfilt...main
int main(int argc, char **argv) {
    try {
        lib_json::FDb_Init();
        algo_lib::FDb_Init();
        ssimfilt::FDb_Init();
        algo_lib::_db.argc = argc;
        algo_lib::_db.argv = argv;
        algo_lib::IohookInit();
        ssimfilt::ReadArgv(); // dmmeta.main:ssimfilt
        ssimfilt::Main(); // user-defined main
    } catch(algo_lib::ErrorX &x) {
        prerr("ssimfilt.error  " << x); // there may be additional hints in DetachBadTags
        algo_lib::_db.exit_code = 1;
    }
    if (algo_lib::_db.last_signal) {
        algo_lib::_db.exit_code = 1;
    }
    try {
        ssimfilt::FDb_Uninit();
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

// --- ssimfilt...WinMain
#if defined(WIN32)
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
    return main(__argc,__argv);
}
#endif
