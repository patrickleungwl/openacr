//
// cpp/gen/lib_mysql_gen.cpp
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
#include "include/gen/lib_mysql_gen.h"
#include "include/gen/lib_mysql_gen.inl.h"
//#pragma endinclude
namespace lib_mysql { // gen:ns_print_proto
    // Load statically available data into tables, register tables and database.
    static void          InitReflection();
    // find trace by row id (used to implement reflection)
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    static i32           trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    static void          SizeCheck();
} // gen:ns_print_proto

// --- lib_mysql.trace..Print
// print string representation of lib_mysql::trace to string LHS, no header -- cprint:lib_mysql.trace.String
void lib_mysql::trace_Print(lib_mysql::trace & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "lib_mysql.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- lib_mysql.FDb.res.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool lib_mysql::res_XrefMaybe(lib_mysql::Res &row) {
    bool retval = true;
    (void)row;
    return retval;
}

// --- lib_mysql.FDb._db.InitReflection
// Load statically available data into tables, register tables and database.
static void lib_mysql::InitReflection() {
    algo_lib::imdb_InsertMaybe(algo::Imdb("lib_mysql", NULL, NULL, NULL, NULL, algo::Comment()));

    algo::Imtable t_trace;
    t_trace.imtable         = "lib_mysql.trace";
    t_trace.ssimfile        = "";
    t_trace.size            = sizeof(lib_mysql::trace);
    t_trace.comment.value   = "";
    t_trace.c_RowidFind     = trace_RowidFind;
    t_trace.NItems          = trace_N;
    t_trace.Print           = (algo::ImrowPrintFcn)lib_mysql::trace_Print;
    algo_lib::imtable_InsertMaybe(t_trace);


    // -- load signatures of existing dispatches --
}

// --- lib_mysql.FDb._db.StaticCheck
void lib_mysql::StaticCheck() {
    algo_assert(_offset_of(lib_mysql::FieldId, value) + sizeof(((lib_mysql::FieldId*)0)->value) == sizeof(lib_mysql::FieldId));
}

// --- lib_mysql.FDb._db.InsertStrptrMaybe
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool lib_mysql::InsertStrptrMaybe(algo::strptr str) {
    bool retval = true;
    (void)str;//only to avoid -Wunused-parameter
    return retval;
}

// --- lib_mysql.FDb._db.LoadTuplesMaybe
// Load all finputs from given directory.
bool lib_mysql::LoadTuplesMaybe(algo::strptr root, bool recursive) {
    bool retval = true;
    if (FileQ(root)) {
        retval = lib_mysql::LoadTuplesFile(root, recursive);
    } else if (root == "-") {
        retval = lib_mysql::LoadTuplesFd(algo::Fildes(0),"(stdin)",recursive);
    } else if (DirectoryQ(root)) {
    } else {
        algo_lib::SaveBadTag("path", root);
        algo_lib::SaveBadTag("comment", "Wrong working directory?");
        retval = false;
    }
    return retval;
}

// --- lib_mysql.FDb._db.LoadTuplesFile
// Load all finputs from given file.
bool lib_mysql::LoadTuplesFile(algo::strptr fname, bool recursive) {
    bool retval = true;
    algo_lib::FFildes fildes;
    fildes.fd = OpenRead(fname,algo_FileFlags__throw);
    retval = LoadTuplesFd(fildes.fd, fname, recursive);
    return retval;
}

// --- lib_mysql.FDb._db.LoadTuplesFd
// Load all finputs from given file descriptor.
bool lib_mysql::LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) {
    bool retval = true;
    ind_beg(algo::FileLine_curs,line,fd) {
        if (recursive) {
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

// --- lib_mysql.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool lib_mysql::LoadSsimfileMaybe(algo::strptr fname, bool recursive) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = lib_mysql::LoadTuplesFile(fname, recursive);
    }
    return retval;
}

// --- lib_mysql.FDb._db.Steps
// Calls Step function of dependencies
void lib_mysql::Steps() {
}

// --- lib_mysql.FDb._db.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool lib_mysql::_db_XrefMaybe() {
    bool retval = true;
    return retval;
}

// --- lib_mysql.FDb.trace.RowidFind
// find trace by row id (used to implement reflection)
static algo::ImrowPtr lib_mysql::trace_RowidFind(int t) {
    return algo::ImrowPtr(t==0 ? u64(&_db.trace) : u64(0));
}

// --- lib_mysql.FDb.trace.N
// Function return 1
inline static i32 lib_mysql::trace_N() {
    return 1;
}

// --- lib_mysql.FDb..Init
// Set all fields to initial values.
void lib_mysql::FDb_Init() {
    _db.mysql = NULL;

    lib_mysql::InitReflection();
}

// --- lib_mysql.FDb..Uninit
void lib_mysql::FDb_Uninit() {
    lib_mysql::FDb &row = _db; (void)row;
    mysql_Cleanup(); // dmmeta.fcleanup:lib_mysql.FDb.mysql
}

// --- lib_mysql.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* lib_mysql::value_ToCstr(const lib_mysql::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case lib_mysql_FieldId_value       : ret = "value";  break;
    }
    return ret;
}

// --- lib_mysql.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void lib_mysql::value_Print(const lib_mysql::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- lib_mysql.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool lib_mysql::value_SetStrptrMaybe(lib_mysql::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,lib_mysql_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- lib_mysql.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void lib_mysql::value_SetStrptr(lib_mysql::FieldId& parent, algo::strptr rhs, lib_mysql_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- lib_mysql.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool lib_mysql::value_ReadStrptrMaybe(lib_mysql::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- lib_mysql.FieldId..ReadStrptrMaybe
// Read fields of lib_mysql::FieldId from an ascii string.
// The format of the string is the format of the lib_mysql::FieldId's only field
bool lib_mysql::FieldId_ReadStrptrMaybe(lib_mysql::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- lib_mysql.FieldId..Print
// print string representation of lib_mysql::FieldId to string LHS, no header -- cprint:lib_mysql.FieldId.String
void lib_mysql::FieldId_Print(lib_mysql::FieldId & row, algo::cstring &str) {
    lib_mysql::value_Print(row, str);
}

// --- lib_mysql.Res..Uninit
void lib_mysql::Res_Uninit(lib_mysql::Res& res) {
    lib_mysql::Res &row = res; (void)row;
    res_Cleanup(res); // dmmeta.fcleanup:lib_mysql.Res.res
}

// --- lib_mysql...SizeCheck
inline static void lib_mysql::SizeCheck() {
}
