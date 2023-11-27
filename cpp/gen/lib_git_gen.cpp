//
// cpp/gen/lib_git_gen.cpp
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
#include "include/gen/lib_git_gen.h"
#include "include/gen/lib_git_gen.inl.h"
#include "include/gen/lib_json_gen.h"
#include "include/gen/lib_json_gen.inl.h"
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_lib_gen.inl.h"
//#pragma endinclude
namespace lib_git { // gen:ns_print_proto
    // Load statically available data into tables, register tables and database.
    static void          InitReflection();
    // find trace by row id (used to implement reflection)
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    static i32           trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    static void          SizeCheck();
} // gen:ns_print_proto

// --- lib_git.trace..Print
// print string representation of lib_git::trace to string LHS, no header -- cprint:lib_git.trace.String
void lib_git::trace_Print(lib_git::trace & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "lib_git.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- lib_git.FDb._db.InitReflection
// Load statically available data into tables, register tables and database.
static void lib_git::InitReflection() {
    algo_lib::imdb_InsertMaybe(algo::Imdb("lib_git", NULL, NULL, NULL, NULL, algo::Comment()));

    algo::Imtable t_trace;
    t_trace.imtable         = "lib_git.trace";
    t_trace.ssimfile        = "";
    t_trace.size            = sizeof(lib_git::trace);
    t_trace.comment.value   = "";
    t_trace.c_RowidFind     = trace_RowidFind;
    t_trace.NItems          = trace_N;
    t_trace.Print           = (algo::ImrowPrintFcn)lib_git::trace_Print;
    algo_lib::imtable_InsertMaybe(t_trace);


    // -- load signatures of existing dispatches --
}

// --- lib_git.FDb._db.StaticCheck
void lib_git::StaticCheck() {
    algo_assert(_offset_of(lib_git::FieldId, value) + sizeof(((lib_git::FieldId*)0)->value) == sizeof(lib_git::FieldId));
}

// --- lib_git.FDb._db.InsertStrptrMaybe
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool lib_git::InsertStrptrMaybe(algo::strptr str) {
    bool retval = true;
    (void)str;//only to avoid -Wunused-parameter
    return retval;
}

// --- lib_git.FDb._db.LoadTuplesMaybe
// Load all finputs from given directory.
bool lib_git::LoadTuplesMaybe(algo::strptr root, bool recursive) {
    bool retval = true;
    if (FileQ(root)) {
        retval = lib_git::LoadTuplesFile(root, recursive);
    } else if (root == "-") {
        retval = lib_git::LoadTuplesFd(algo::Fildes(0),"(stdin)",recursive);
    } else if (DirectoryQ(root)) {
        retval = retval && lib_git::LoadTuplesFile(algo::SsimFname(root,"dmmeta.dispsigcheck"),recursive);
    } else {
        algo_lib::SaveBadTag("path", root);
        algo_lib::SaveBadTag("comment", "Wrong working directory?");
        retval = false;
    }
    return retval;
}

// --- lib_git.FDb._db.LoadTuplesFile
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
bool lib_git::LoadTuplesFile(algo::strptr fname, bool recursive) {
    bool retval = true;
    algo_lib::FFildes fildes;
    fildes.fd = OpenRead(fname,algo::FileFlags());
    if (ValidQ(fildes.fd)) {
        retval = LoadTuplesFd(fildes.fd, fname, recursive);
    }
    return retval;
}

// --- lib_git.FDb._db.LoadTuplesFd
// Load all finputs from given file descriptor.
bool lib_git::LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) {
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

// --- lib_git.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool lib_git::LoadSsimfileMaybe(algo::strptr fname, bool recursive) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = lib_git::LoadTuplesFile(fname, recursive);
    }
    return retval;
}

// --- lib_git.FDb._db.Steps
// Calls Step function of dependencies
void lib_git::Steps() {
    algo_lib::Step(); // dependent namespace specified via (dev.targdep)
}

// --- lib_git.FDb._db.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool lib_git::_db_XrefMaybe() {
    bool retval = true;
    return retval;
}

// --- lib_git.FDb.trace.RowidFind
// find trace by row id (used to implement reflection)
static algo::ImrowPtr lib_git::trace_RowidFind(int t) {
    return algo::ImrowPtr(t==0 ? u64(&_db.trace) : u64(0));
}

// --- lib_git.FDb.trace.N
// Function return 1
inline static i32 lib_git::trace_N() {
    return 1;
}

// --- lib_git.FDb..Init
// Set all fields to initial values.
void lib_git::FDb_Init() {

    lib_git::InitReflection();
}

// --- lib_git.FDb..Uninit
void lib_git::FDb_Uninit() {
    lib_git::FDb &row = _db; (void)row;
}

// --- lib_git.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* lib_git::value_ToCstr(const lib_git::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case lib_git_FieldId_value         : ret = "value";  break;
    }
    return ret;
}

// --- lib_git.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void lib_git::value_Print(const lib_git::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- lib_git.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool lib_git::value_SetStrptrMaybe(lib_git::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,lib_git_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- lib_git.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void lib_git::value_SetStrptr(lib_git::FieldId& parent, algo::strptr rhs, lib_git_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- lib_git.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool lib_git::value_ReadStrptrMaybe(lib_git::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- lib_git.FieldId..ReadStrptrMaybe
// Read fields of lib_git::FieldId from an ascii string.
// The format of the string is the format of the lib_git::FieldId's only field
bool lib_git::FieldId_ReadStrptrMaybe(lib_git::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- lib_git.FieldId..Print
// print string representation of lib_git::FieldId to string LHS, no header -- cprint:lib_git.FieldId.String
void lib_git::FieldId_Print(lib_git::FieldId & row, algo::cstring &str) {
    lib_git::value_Print(row, str);
}

// --- lib_git...SizeCheck
inline static void lib_git::SizeCheck() {
}
