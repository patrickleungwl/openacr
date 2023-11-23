//
// include/gen/gcache_gen.inl.h
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
#include "include/gen/report_gen.inl.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/algo_gen.inl.h"
//#pragma endinclude
inline gcache::cleanreport::cleanreport(i32                            in_n_cachefile
        ,i32                            in_n_cachefile_del
        ,i32                            in_n_cachefile_recent
        ,i32                            in_n_logline
        ,i32                            in_n_logline_del
        ,i64                            in_new_cachesize_mb)
    : n_cachefile(in_n_cachefile)
    , n_cachefile_del(in_n_cachefile_del)
    , n_cachefile_recent(in_n_cachefile_recent)
    , n_logline(in_n_logline)
    , n_logline_del(in_n_logline_del)
    , new_cachesize_mb(in_new_cachesize_mb)
{
}
inline gcache::cleanreport::cleanreport() {
    gcache::cleanreport_Init(*this);
}


// --- gcache.cleanreport..Init
// Set all fields to initial values.
inline void gcache::cleanreport_Init(gcache::cleanreport& parent) {
    parent.n_cachefile = i32(0);
    parent.n_cachefile_del = i32(0);
    parent.n_cachefile_recent = i32(0);
    parent.n_logline = i32(0);
    parent.n_logline_del = i32(0);
    parent.new_cachesize_mb = i64(0);
}
inline gcache::trace::trace() {
}

inline gcache::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline gcache::FieldId::FieldId(gcache_FieldIdEnum arg) { this->value = i32(arg); }
inline gcache::FieldId::FieldId() {
    gcache::FieldId_Init(*this);
}


// --- gcache.FieldId.value.GetEnum
// Get value of field as enum type
inline gcache_FieldIdEnum gcache::value_GetEnum(const gcache::FieldId& parent) {
    return gcache_FieldIdEnum(parent.value);
}

// --- gcache.FieldId.value.SetEnum
// Set value of field from enum type.
inline void gcache::value_SetEnum(gcache::FieldId& parent, gcache_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- gcache.FieldId.value.Cast
inline gcache::FieldId::operator gcache_FieldIdEnum () const {
    return gcache_FieldIdEnum((*this).value);
}

// --- gcache.FieldId..Init
// Set all fields to initial values.
inline void gcache::FieldId_Init(gcache::FieldId& parent) {
    parent.value = i32(-1);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const gcache::cleanreport &row) {// cfmt:gcache.cleanreport.String
    gcache::cleanreport_Print(const_cast<gcache::cleanreport&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const gcache::trace &row) {// cfmt:gcache.trace.String
    gcache::trace_Print(const_cast<gcache::trace&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const gcache::FieldId &row) {// cfmt:gcache.FieldId.String
    gcache::FieldId_Print(const_cast<gcache::FieldId&>(row), str);
    return str;
}
