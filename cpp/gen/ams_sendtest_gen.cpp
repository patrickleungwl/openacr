//
// cpp/gen/ams_sendtest_gen.cpp
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#include "include/algo.h"  // hard-coded include
#include "include/gen/ams_sendtest_gen.h"
#include "include/gen/ams_sendtest_gen.inl.h"
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_lib_gen.inl.h"
#include "include/gen/algo_gen.h"
#include "include/gen/algo_gen.inl.h"
#include "include/gen/command_gen.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/ams_gen.h"
#include "include/gen/ams_gen.inl.h"
#include "include/gen/lib_ams_gen.h"
#include "include/gen/lib_ams_gen.inl.h"
#include "include/gen/lib_json_gen.h"
#include "include/gen/lib_json_gen.inl.h"
#include "include/gen/lib_prot_gen.h"
#include "include/gen/lib_prot_gen.inl.h"
//#pragma endinclude

// Instantiate all libraries linked into this executable,
// in dependency order
lib_json::FDb       lib_json::_db;        // dependency found via dev.targdep
algo_lib::FDb       algo_lib::_db;        // dependency found via dev.targdep
lib_ams::FDb        lib_ams::_db;         // dependency found via dev.targdep
ams_sendtest::FDb   ams_sendtest::_db;    // dependency found via dev.targdep

namespace ams_sendtest {
const char *ams_sendtest_help =
"Usage: ams_sendtest [options]\n"
"    -in            string  Input directory or filename, - for stdin. default: \"data\"\n"
"    -id            int     Process index (0=parent). default: 0\n"
"    -file_prefix   string  Use file_prefix\n"
"    -nchild        int     Number of stream readers. default: 1\n"
"    -blocking              Use blocking send mode. default: false\n"
"    -nmsg          int     Number of messages to send/receive. default: 1000\n"
"    -trace         string  Regx expression specifying what to trace\n"
"    -timeout       int     Time limit for the send. default: 30\n"
"    -recvdelay_ns  int     Pause nanoseconds between messages. default: 0\n"
"    -senddelay_ns  int     Pause nanoseconds between messages. default: 0\n"
"    -msgsize_min   int     Minimum message length. default: 64\n"
"    -msgsize_max   int     Maximum message length. default: 1024\n"
"    -bufsize       int     Shared memory buffer size. default: 32768\n"
"    -recvdelay     int     Pause nanoseconds between messages. default: 0\n"
"    -verbose               Enable verbose mode\n"
"    -debug                 Enable debug mode\n"
"    -version               Show version information\n"
"    -sig                   Print SHA1 signatures for dispatches\n"
"    -help                  Print this screen and exit\n"
;


const char *ams_sendtest_syntax =
"-in:string=\"data\"\n"
" -id:int=0\n"
" -file_prefix:string=\n"
" -nchild:int=1\n"
" -blocking:flag\n"
" -nmsg:int=1000\n"
" -trace:string=\n"
" -timeout:int=30\n"
" -recvdelay_ns:int=0\n"
" -senddelay_ns:int=0\n"
" -msgsize_min:int=64\n"
" -msgsize_max:int=1024\n"
" -bufsize:int=32768\n"
" -recvdelay:int=0\n"
;
} // namespace ams_sendtest
namespace ams_sendtest { // gen:ns_print_proto
    // Load statically available data into tables, register tables and database.
    static void          InitReflection();
    // find trace by row id (used to implement reflection)
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    static i32           trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    static void          SizeCheck();
} // gen:ns_print_proto

// --- ams_sendtest.AmsSendTest..Print
// print string representation of ams_sendtest::AmsSendTest to string LHS, no header -- cprint:ams_sendtest.AmsSendTest.String
void ams_sendtest::AmsSendTest_Print(ams_sendtest::AmsSendTest & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "ams_sendtest.AmsSendTest";

    u64_Print(row.n_msg_send, temp);
    PrintAttrSpaceReset(str,"n_msg_send", temp);

    u64_Print(row.n_msg_recv, temp);
    PrintAttrSpaceReset(str,"n_msg_recv", temp);

    u64_Print(row.n_write_wait, temp);
    PrintAttrSpaceReset(str,"n_write_wait", temp);

    u64_Print(row.n_msg_limit, temp);
    PrintAttrSpaceReset(str,"n_msg_limit", temp);

    u64_Print(row.sum_recv_latency, temp);
    PrintAttrSpaceReset(str,"sum_recv_latency", temp);
}

// --- ams_sendtest.FChild.child.Start
// Start subprocess
// If subprocess already running, do nothing. Otherwise, start it
int ams_sendtest::child_Start(ams_sendtest::FChild& child) {
    int retval = 0;
    if (child.child_pid == 0) {
        verblog(child_ToCmdline(child)); // maybe print command
#ifdef WIN32
        algo_lib::ResolveExecFname(child.child_path);
        tempstr cmdline(child_ToCmdline(child));
        child.child_pid = dospawn(Zeroterm(child.child_path),Zeroterm(cmdline),child.child_timeout,child.child_fstdin,child.child_fstdout,child.child_fstderr);
#else
        child.child_pid = fork();
        if (child.child_pid == 0) { // child
            algo_lib::DieWithParent();
            if (child.child_timeout > 0) {
                alarm(child.child_timeout);
            }
            if (retval==0) retval=algo_lib::ApplyRedirect(child.child_fstdin , 0);
            if (retval==0) retval=algo_lib::ApplyRedirect(child.child_fstdout, 1);
            if (retval==0) retval=algo_lib::ApplyRedirect(child.child_fstderr, 2);
            if (retval==0) retval= child_Execv(child);
            if (retval != 0) { // if start fails, print error
                int err=errno;
                prerr("ams_sendtest.child_execv"
                <<Keyval("errno",err)
                <<Keyval("errstr",strerror(err))
                <<Keyval("comment","Execv failed"));
            }
            _exit(127); // if failed to start, exit anyway
        } else if (child.child_pid == -1) {
            retval = errno; // failed to fork
        }
#endif
    }
    child.child_status = child.child_pid > 0 ? 0 : -1; // if didn't start, set error status
    return retval;
}

// --- ams_sendtest.FChild.child.StartRead
// Start subprocess & Read output
algo::Fildes ams_sendtest::child_StartRead(ams_sendtest::FChild& child, algo_lib::FFildes &read) {
    int pipefd[2];
    int rc=pipe(pipefd);
    (void)rc;
    read.fd.value = pipefd[0];
    child.child_fstdout  << ">&" << pipefd[1];
    child_Start(child);
    (void)close(pipefd[1]);
    return read.fd;
}

// --- ams_sendtest.FChild.child.Kill
// Kill subprocess and wait
void ams_sendtest::child_Kill(ams_sendtest::FChild& child) {
    if (child.child_pid != 0) {
        kill(child.child_pid,9);
        child_Wait(child);
    }
}

// --- ams_sendtest.FChild.child.Wait
// Wait for subprocess to return
void ams_sendtest::child_Wait(ams_sendtest::FChild& child) {
    if (child.child_pid > 0) {
        int wait_flags = 0;
        int wait_status = 0;
        int rc = -1;
        do {
            // really wait for subprocess to exit
            rc = waitpid(child.child_pid,&wait_status,wait_flags);
        } while (rc==-1 && errno==EINTR);
        if (rc == child.child_pid) {
            child.child_status = wait_status;
            child.child_pid = 0;
        }
    }
}

// --- ams_sendtest.FChild.child.Exec
// Start + Wait
// Execute subprocess and return exit code
int ams_sendtest::child_Exec(ams_sendtest::FChild& child) {
    child_Start(child);
    child_Wait(child);
    return child.child_status;
}

// --- ams_sendtest.FChild.child.ExecX
// Start + Wait, throw exception on error
// Execute subprocess; throw human-readable exception on error
void ams_sendtest::child_ExecX(ams_sendtest::FChild& child) {
    int rc = child_Exec(child);
    vrfy(rc==0, tempstr() << "algo_lib.exec" << Keyval("cmd",child_ToCmdline(child))
    << Keyval("comment",algo::DescribeWaitStatus(child.child_status)));
}

// --- ams_sendtest.FChild.child.Execv
// Call execv()
// Call execv with specified parameters -- cprint:ams_sendtest.Argv
int ams_sendtest::child_Execv(ams_sendtest::FChild& child) {
    char **argv = (char**)alloca((28+2+algo_lib::_db.cmdline.verbose)*sizeof(char*)); // start of first arg (future pointer)
    algo::tempstr temp;
    int n_argv=0;
    argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
    temp << child.child_path;
    ch_Alloc(temp) = 0;// NUL term for pathname

    if (child.child_cmd.in != "data") {
        argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
        temp << "-in:";
        cstring_Print(child.child_cmd.in, temp);
        ch_Alloc(temp) = 0;// NUL term for this arg
    }

    if (child.child_cmd.id != 0) {
        argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
        temp << "-id:";
        i32_Print(child.child_cmd.id, temp);
        ch_Alloc(temp) = 0;// NUL term for this arg
    }

    if (child.child_cmd.file_prefix != "") {
        argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
        temp << "-file_prefix:";
        cstring_Print(child.child_cmd.file_prefix, temp);
        ch_Alloc(temp) = 0;// NUL term for this arg
    }

    if (child.child_cmd.nchild != 1) {
        argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
        temp << "-nchild:";
        i32_Print(child.child_cmd.nchild, temp);
        ch_Alloc(temp) = 0;// NUL term for this arg
    }

    if (child.child_cmd.blocking != false) {
        argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
        temp << "-blocking:";
        bool_Print(child.child_cmd.blocking, temp);
        ch_Alloc(temp) = 0;// NUL term for this arg
    }

    if (child.child_cmd.nmsg != 1000) {
        argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
        temp << "-nmsg:";
        i32_Print(child.child_cmd.nmsg, temp);
        ch_Alloc(temp) = 0;// NUL term for this arg
    }

    if (child.child_cmd.trace.expr != "") {
        argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
        temp << "-trace:";
        command::trace_Print(child.child_cmd, temp);
        ch_Alloc(temp) = 0;// NUL term for this arg
    }

    if (child.child_cmd.timeout != 30) {
        argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
        temp << "-timeout:";
        i32_Print(child.child_cmd.timeout, temp);
        ch_Alloc(temp) = 0;// NUL term for this arg
    }

    if (child.child_cmd.recvdelay_ns != 0) {
        argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
        temp << "-recvdelay_ns:";
        i64_Print(child.child_cmd.recvdelay_ns, temp);
        ch_Alloc(temp) = 0;// NUL term for this arg
    }

    if (child.child_cmd.senddelay_ns != 0) {
        argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
        temp << "-senddelay_ns:";
        i64_Print(child.child_cmd.senddelay_ns, temp);
        ch_Alloc(temp) = 0;// NUL term for this arg
    }

    if (child.child_cmd.msgsize_min != 64) {
        argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
        temp << "-msgsize_min:";
        i32_Print(child.child_cmd.msgsize_min, temp);
        ch_Alloc(temp) = 0;// NUL term for this arg
    }

    if (child.child_cmd.msgsize_max != 1024) {
        argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
        temp << "-msgsize_max:";
        i32_Print(child.child_cmd.msgsize_max, temp);
        ch_Alloc(temp) = 0;// NUL term for this arg
    }

    if (child.child_cmd.bufsize != 32768) {
        argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
        temp << "-bufsize:";
        i32_Print(child.child_cmd.bufsize, temp);
        ch_Alloc(temp) = 0;// NUL term for this arg
    }

    if (child.child_cmd.recvdelay != 0) {
        argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
        temp << "-recvdelay:";
        i64_Print(child.child_cmd.recvdelay, temp);
        ch_Alloc(temp) = 0;// NUL term for this arg
    }
    for (int i=0; i+1 < algo_lib::_db.cmdline.verbose; i++) {
        argv[n_argv++] = (char*)(int_ptr)ch_N(temp);// future pointer
        temp << "-verbose";
        ch_Alloc(temp) = 0;
    }
    argv[n_argv] = NULL; // last pointer
    while (n_argv>0) { // shift pointers
        argv[--n_argv] += (u64)temp.ch_elems;
    }
    // if child.child_path is relative, search for it in PATH
    algo_lib::ResolveExecFname(child.child_path);
    return execv(Zeroterm(child.child_path),argv);
}

// --- ams_sendtest.FChild.child.ToCmdline
algo::tempstr ams_sendtest::child_ToCmdline(ams_sendtest::FChild& child) {
    algo::tempstr retval;
    retval << child.child_path << " ";
    command::ams_sendtest_PrintArgv(child.child_cmd,retval);
    if (ch_N(child.child_fstdin)) {
        retval << " " << child.child_fstdin;
    }
    if (ch_N(child.child_fstdout)) {
        retval << " " << child.child_fstdout;
    }
    if (ch_N(child.child_fstderr)) {
        retval << " 2" << child.child_fstderr;
    }
    return retval;
}

// --- ams_sendtest.FChild..Init
// Set all fields to initial values.
void ams_sendtest::FChild_Init(ams_sendtest::FChild& child) {
    child.child_path = algo::strptr("bin/ams_sendtest");
    child.child_pid = pid_t(0);
    child.child_timeout = i32(0);
    child.child_status = i32(0);
}

// --- ams_sendtest.FChild..Uninit
void ams_sendtest::FChild_Uninit(ams_sendtest::FChild& child) {
    ams_sendtest::FChild &row = child; (void)row;

    // ams_sendtest.FChild.child.Uninit (Exec)  //
    child_Kill(child); // kill child, ensure forward progress
}

// --- ams_sendtest.trace..Print
// print string representation of ams_sendtest::trace to string LHS, no header -- cprint:ams_sendtest.trace.String
void ams_sendtest::trace_Print(ams_sendtest::trace & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "ams_sendtest.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- ams_sendtest.FDb._db.MainArgs
// Main function
void ams_sendtest::MainArgs(int argc, char **argv) {
    Argtuple argtuple;
    Argtuple_ReadArgv(argtuple, argc,argv,ams_sendtest_syntax, ams_sendtest_help);
    vrfy(ams_sendtest_ReadTupleMaybe(ams_sendtest::_db.cmdline, argtuple.tuple),"where:read_cmdline");
    vrfy(ams_sendtest::LoadTuplesMaybe(ams_sendtest::_db.cmdline.in)
    ,tempstr()<<"where:load_input  "<<algo_lib::DetachBadTags());
    ams_sendtest::Main(); // call through to user-defined main
}

// --- ams_sendtest.FDb._db.MainLoop
// Main loop.
void ams_sendtest::MainLoop() {
    algo::SchedTime time(algo::get_cycles());
    algo_lib::_db.clock          = time;
    do {
        algo_lib::_db.next_loop.value = algo_lib::_db.limit;
        ams_sendtest::Steps();
    } while (algo_lib::_db.next_loop < algo_lib::_db.limit);
}

// --- ams_sendtest.FDb._db.Step
// Main step
void ams_sendtest::Step() {
}

// --- ams_sendtest.FDb._db.InitReflection
// Load statically available data into tables, register tables and database.
static void ams_sendtest::InitReflection() {
    algo_lib::imdb_InsertMaybe(algo::Imdb("ams_sendtest", NULL, NULL, ams_sendtest::MainLoop, NULL, algo::Comment()));

    algo::Imtable t_trace;
    t_trace.imtable         = "ams_sendtest.trace";
    t_trace.ssimfile        = "";
    t_trace.size            = sizeof(ams_sendtest::trace);
    t_trace.comment.value   = "";
    t_trace.c_RowidFind     = trace_RowidFind;
    t_trace.NItems          = trace_N;
    t_trace.Print           = (algo::ImrowPrintFcn)ams_sendtest::trace_Print;
    algo_lib::imtable_InsertMaybe(t_trace);


    // -- load signatures of existing dispatches --
}

// --- ams_sendtest.FDb._db.StaticCheck
void ams_sendtest::StaticCheck() {
    algo_assert(_offset_of(ams_sendtest::FieldId, value) + sizeof(((ams_sendtest::FieldId*)0)->value) == sizeof(ams_sendtest::FieldId));
}

// --- ams_sendtest.FDb._db.InsertStrptrMaybe
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool ams_sendtest::InsertStrptrMaybe(algo::strptr str) {
    bool retval = true;
    (void)str;//only to avoid -Wunused-parameter
    return retval;
}

// --- ams_sendtest.FDb._db.LoadTuplesMaybe
// Load all finputs from given directory.
bool ams_sendtest::LoadTuplesMaybe(algo::strptr root) {
    bool retval = true;
    (void)root;//only to avoid -Wunused-parameter
    return retval;
}

// --- ams_sendtest.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool ams_sendtest::LoadSsimfileMaybe(algo::strptr fname) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = algo_lib::LoadTuplesFile(fname, ams_sendtest::InsertStrptrMaybe, true);
    }
    return retval;
}

// --- ams_sendtest.FDb._db.Steps
// Calls Step function of dependencies
void ams_sendtest::Steps() {
    lib_ams::Step(); // dependent namespace specified via (dev.targdep)
    algo_lib::Step(); // dependent namespace specified via (dev.targdep)
}

// --- ams_sendtest.FDb._db.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool ams_sendtest::_db_XrefMaybe() {
    bool retval = true;
    return retval;
}

// --- ams_sendtest.FDb.child.Alloc
// Allocate memory for new default row.
// If out of memory, process is killed.
ams_sendtest::FChild& ams_sendtest::child_Alloc() {
    ams_sendtest::FChild* row = child_AllocMaybe();
    if (UNLIKELY(row == NULL)) {
        FatalErrorExit("ams_sendtest.out_of_mem  field:ams_sendtest.FDb.child  comment:'Alloc failed'");
    }
    return *row;
}

// --- ams_sendtest.FDb.child.AllocMaybe
// Allocate memory for new element. If out of memory, return NULL.
ams_sendtest::FChild* ams_sendtest::child_AllocMaybe() {
    ams_sendtest::FChild *row = (ams_sendtest::FChild*)child_AllocMem();
    if (row) {
        new (row) ams_sendtest::FChild; // call constructor
    }
    return row;
}

// --- ams_sendtest.FDb.child.AllocMem
// Allocate space for one element. If no memory available, return NULL.
void* ams_sendtest::child_AllocMem() {
    u64 new_nelems     = _db.child_n+1;
    // compute level and index on level
    u64 bsr   = algo::u64_BitScanReverse(new_nelems);
    u64 base  = u64(1)<<bsr;
    u64 index = new_nelems-base;
    void *ret = NULL;
    // if level doesn't exist yet, create it
    ams_sendtest::FChild*  lev   = NULL;
    if (bsr < 32) {
        lev = _db.child_lary[bsr];
        if (!lev) {
            lev=(ams_sendtest::FChild*)algo_lib::malloc_AllocMem(sizeof(ams_sendtest::FChild) * (u64(1)<<bsr));
            _db.child_lary[bsr] = lev;
        }
    }
    // allocate element from this level
    if (lev) {
        _db.child_n = i32(new_nelems);
        ret = lev + index;
    }
    return ret;
}

// --- ams_sendtest.FDb.child.RemoveAll
// Remove all elements from Lary
void ams_sendtest::child_RemoveAll() {
    for (u64 n = _db.child_n; n>0; ) {
        n--;
        child_qFind(u64(n)).~FChild(); // destroy last element
        _db.child_n = i32(n);
    }
}

// --- ams_sendtest.FDb.child.RemoveLast
// Delete last element of array. Do nothing if array is empty.
void ams_sendtest::child_RemoveLast() {
    u64 n = _db.child_n;
    if (n > 0) {
        n -= 1;
        child_qFind(u64(n)).~FChild();
        _db.child_n = i32(n);
    }
}

// --- ams_sendtest.FDb.child.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool ams_sendtest::child_XrefMaybe(ams_sendtest::FChild &row) {
    bool retval = true;
    (void)row;
    return retval;
}

// --- ams_sendtest.FDb.trace.RowidFind
// find trace by row id (used to implement reflection)
static algo::ImrowPtr ams_sendtest::trace_RowidFind(int t) {
    return algo::ImrowPtr(t==0 ? u64(&_db.trace) : u64(0));
}

// --- ams_sendtest.FDb.trace.N
// Function return 1
inline static i32 ams_sendtest::trace_N() {
    return 1;
}

// --- ams_sendtest.FDb..Init
// Set all fields to initial values.
void ams_sendtest::FDb_Init() {
    _db.c_out = NULL;
    // initialize LAry child (ams_sendtest.FDb.child)
    _db.child_n = 0;
    memset(_db.child_lary, 0, sizeof(_db.child_lary)); // zero out all level pointers
    ams_sendtest::FChild* child_first = (ams_sendtest::FChild*)algo_lib::malloc_AllocMem(sizeof(ams_sendtest::FChild) * (u64(1)<<4));
    if (!child_first) {
        FatalErrorExit("out of memory");
    }
    for (int i = 0; i < 4; i++) {
        _db.child_lary[i]  = child_first;
        child_first    += 1ULL<<i;
    }

    ams_sendtest::InitReflection();
}

// --- ams_sendtest.FDb..Uninit
void ams_sendtest::FDb_Uninit() {
    ams_sendtest::FDb &row = _db; (void)row;

    // ams_sendtest.FDb.child.Uninit (Lary)  //
    // skip destruction in global scope
}

// --- ams_sendtest.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* ams_sendtest::value_ToCstr(const ams_sendtest::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case ams_sendtest_FieldId_value    : ret = "value";  break;
    }
    return ret;
}

// --- ams_sendtest.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void ams_sendtest::value_Print(const ams_sendtest::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- ams_sendtest.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool ams_sendtest::value_SetStrptrMaybe(ams_sendtest::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,ams_sendtest_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- ams_sendtest.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void ams_sendtest::value_SetStrptr(ams_sendtest::FieldId& parent, algo::strptr rhs, ams_sendtest_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- ams_sendtest.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool ams_sendtest::value_ReadStrptrMaybe(ams_sendtest::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- ams_sendtest.FieldId..ReadStrptrMaybe
// Read fields of ams_sendtest::FieldId from an ascii string.
// The format of the string is the format of the ams_sendtest::FieldId's only field
bool ams_sendtest::FieldId_ReadStrptrMaybe(ams_sendtest::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && ams_sendtest::value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- ams_sendtest.FieldId..Print
// print string representation of ams_sendtest::FieldId to string LHS, no header -- cprint:ams_sendtest.FieldId.String
void ams_sendtest::FieldId_Print(ams_sendtest::FieldId & row, algo::cstring &str) {
    ams_sendtest::value_Print(row, str);
}

// --- ams_sendtest...SizeCheck
inline static void ams_sendtest::SizeCheck() {
}

// --- ams_sendtest...main
int main(int argc, char **argv) {
    try {
        lib_json::FDb_Init();
        algo_lib::FDb_Init();
        lib_ams::FDb_Init();
        ams_sendtest::FDb_Init();
        algo_lib::_db.argc = argc;
        algo_lib::_db.argv = argv;
        algo_lib::IohookInit();
        ams_sendtest::MainArgs(algo_lib::_db.argc,algo_lib::_db.argv); // dmmeta.main:ams_sendtest
    } catch(algo_lib::ErrorX &x) {
        prerr("ams_sendtest.error  " << x); // there may be additional hints in DetachBadTags
        algo_lib::_db.exit_code = 1;
    }
    if (algo_lib::_db.last_signal) {
        algo_lib::_db.exit_code = 1;
    }
    try {
        ams_sendtest::FDb_Uninit();
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

// --- ams_sendtest...WinMain
#if defined(WIN32)
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
    return main(__argc,__argv);
}
#endif
