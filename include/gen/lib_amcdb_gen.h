//
// include/gen/lib_amcdb_gen.h
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
//#pragma endinclude
// gen:ns_enums

// --- lib_amcdb_FieldIdEnum

enum lib_amcdb_FieldIdEnum {        // lib_amcdb.FieldId.value
     lib_amcdb_FieldId_value   = 0
};

enum { lib_amcdb_FieldIdEnum_N = 1 };

namespace lib_amcdb { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace lib_amcdb { // gen:ns_field
} // gen:ns_field
// gen:ns_fwddecl2
namespace lib_amcdb { struct FieldId; }
namespace lib_amcdb { // gen:ns_print_struct

// --- lib_amcdb.FieldId
#pragma pack(push,1)
struct FieldId { // lib_amcdb.FieldId: Field read helper
    i32   value;   //   -1
    inline operator lib_amcdb_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(lib_amcdb_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
lib_amcdb_FieldIdEnum value_GetEnum(const lib_amcdb::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(lib_amcdb::FieldId& parent, lib_amcdb_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const lib_amcdb::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const lib_amcdb::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(lib_amcdb::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(lib_amcdb::FieldId& parent, algo::strptr rhs, lib_amcdb_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(lib_amcdb::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of lib_amcdb::FieldId from an ascii string.
// The format of the string is the format of the lib_amcdb::FieldId's only field
bool                 FieldId_ReadStrptrMaybe(lib_amcdb::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 FieldId_Init(lib_amcdb::FieldId& parent);
// print string representation of lib_amcdb::FieldId to string LHS, no header -- cprint:lib_amcdb.FieldId.String
void                 FieldId_Print(lib_amcdb::FieldId & row, algo::cstring &str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace lib_amcdb { // gen:ns_func
} // gen:ns_func
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const lib_amcdb::FieldId &row);// cfmt:lib_amcdb.FieldId.String
}
