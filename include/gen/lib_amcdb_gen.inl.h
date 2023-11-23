//
// include/gen/lib_amcdb_gen.inl.h
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
inline lib_amcdb::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline lib_amcdb::FieldId::FieldId(lib_amcdb_FieldIdEnum arg) { this->value = i32(arg); }
inline lib_amcdb::FieldId::FieldId() {
    lib_amcdb::FieldId_Init(*this);
}


// --- lib_amcdb.FieldId.value.GetEnum
// Get value of field as enum type
inline lib_amcdb_FieldIdEnum lib_amcdb::value_GetEnum(const lib_amcdb::FieldId& parent) {
    return lib_amcdb_FieldIdEnum(parent.value);
}

// --- lib_amcdb.FieldId.value.SetEnum
// Set value of field from enum type.
inline void lib_amcdb::value_SetEnum(lib_amcdb::FieldId& parent, lib_amcdb_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- lib_amcdb.FieldId.value.Cast
inline lib_amcdb::FieldId::operator lib_amcdb_FieldIdEnum () const {
    return lib_amcdb_FieldIdEnum((*this).value);
}

// --- lib_amcdb.FieldId..Init
// Set all fields to initial values.
inline void lib_amcdb::FieldId_Init(lib_amcdb::FieldId& parent) {
    parent.value = i32(-1);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const lib_amcdb::FieldId &row) {// cfmt:lib_amcdb.FieldId.String
    lib_amcdb::FieldId_Print(const_cast<lib_amcdb::FieldId&>(row), str);
    return str;
}