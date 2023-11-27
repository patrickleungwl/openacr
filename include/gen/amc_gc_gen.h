//
// include/gen/amc_gc_gen.h
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


#pragma once
#include "include/gen/command_gen.h"
#include "include/gen/algo_gen.h"
//#pragma endinclude
// gen:ns_enums

// --- amc_gc_FieldIdEnum

enum amc_gc_FieldIdEnum {        // amc_gc.FieldId.value
     amc_gc_FieldId_value   = 0
};

enum { amc_gc_FieldIdEnum_N = 1 };

namespace amc_gc { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace amc_gc { // gen:ns_field
extern const char *amc_gc_help;
} // gen:ns_field
// gen:ns_fwddecl2
namespace amc_gc { struct trace; }
namespace amc_gc { struct FDb; }
namespace amc_gc { struct FieldId; }
namespace amc_gc { extern struct amc_gc::FDb _db; }
namespace amc_gc { // gen:ns_print_struct

// --- amc_gc.trace
#pragma pack(push,1)
struct trace { // amc_gc.trace
    trace();
};
#pragma pack(pop)

// print string representation of amc_gc::trace to string LHS, no header -- cprint:amc_gc.trace.String
void                 trace_Print(amc_gc::trace & row, algo::cstring &str) __attribute__((nothrow));

// --- amc_gc.FDb
// create: amc_gc.FDb._db (Global)
struct FDb { // amc_gc.FDb
    command::amc_gc   cmdline;        //
    u32               n_cur;          //   1
    u32               n_del;          //   0
    u32               n_cppline;      //   0
    u32               n_newcppline;   //   0
    algo::cstring     buildlog;       //   "temp/amc_gc.build"
    u32               n_total;        //   0
    amc_gc::trace     trace;          //
};

// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     amc_gc.FDb.cmdline
//     algo_lib.FDb.cmdline
void                 ReadArgv() __attribute__((nothrow));
// Main loop.
void                 MainLoop();
// Main step
void                 Step();
// Main function
void                 Main();
void                 StaticCheck();
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool                 InsertStrptrMaybe(algo::strptr str);
// Load all finputs from given directory.
bool                 LoadTuplesMaybe(algo::strptr root, bool recursive) __attribute__((nothrow));
// Load all finputs from given file.
// Read tuples from file FNAME into this namespace's in-memory database.
// If RECURSIVE is TRUE, then also load these tuples into any parent namespaces
// It a file referred to by FNAME is missing, no error is reported (it's considered an empty set).
// Function returns TRUE if all records were parsed and inserted without error.
// If the function returns FALSE, use algo_lib::DetachBadTags() for error description
bool                 LoadTuplesFile(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load all finputs from given file descriptor.
bool                 LoadTuplesFd(algo::Fildes fd, algo::strptr fname, bool recursive) __attribute__((nothrow));
// Load specified ssimfile.
bool                 LoadSsimfileMaybe(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Calls Step function of dependencies
void                 Steps();
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 _db_XrefMaybe();

// Set all fields to initial values.
void                 FDb_Init();
void                 FDb_Uninit() __attribute__((nothrow));

// --- amc_gc.FieldId
#pragma pack(push,1)
struct FieldId { // amc_gc.FieldId: Field read helper
    i32   value;   //   -1
    inline operator amc_gc_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(amc_gc_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
amc_gc_FieldIdEnum   value_GetEnum(const amc_gc::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(amc_gc::FieldId& parent, amc_gc_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const amc_gc::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const amc_gc::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(amc_gc::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(amc_gc::FieldId& parent, algo::strptr rhs, amc_gc_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(amc_gc::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of amc_gc::FieldId from an ascii string.
// The format of the string is the format of the amc_gc::FieldId's only field
bool                 FieldId_ReadStrptrMaybe(amc_gc::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 FieldId_Init(amc_gc::FieldId& parent);
// print string representation of amc_gc::FieldId to string LHS, no header -- cprint:amc_gc.FieldId.String
void                 FieldId_Print(amc_gc::FieldId & row, algo::cstring &str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace amc_gc { // gen:ns_func
} // gen:ns_func
int                  main(int argc, char **argv);
#if defined(WIN32)
int WINAPI           WinMain(HINSTANCE,HINSTANCE,LPSTR,int);
#endif
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const amc_gc::trace &row);// cfmt:amc_gc.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const amc_gc::FieldId &row);// cfmt:amc_gc.FieldId.String
}
