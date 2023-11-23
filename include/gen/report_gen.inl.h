//
// include/gen/report_gen.inl.h
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
#include "include/gen/algo_gen.inl.h"
//#pragma endinclude
inline report::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline report::FieldId::FieldId(report_FieldIdEnum arg) { this->value = i32(arg); }
inline report::FieldId::FieldId() {
    report::FieldId_Init(*this);
}


// --- report.FieldId.value.GetEnum
// Get value of field as enum type
inline report_FieldIdEnum report::value_GetEnum(const report::FieldId& parent) {
    return report_FieldIdEnum(parent.value);
}

// --- report.FieldId.value.SetEnum
// Set value of field from enum type.
inline void report::value_SetEnum(report::FieldId& parent, report_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- report.FieldId.value.Cast
inline report::FieldId::operator report_FieldIdEnum () const {
    return report_FieldIdEnum((*this).value);
}

// --- report.FieldId..Init
// Set all fields to initial values.
inline void report::FieldId_Init(report::FieldId& parent) {
    parent.value = i32(-1);
}
inline report::Protocol::Protocol() {
}

inline report::abt::abt(u16                            in_n_target
        ,algo::UnDiff                   in_time
        ,const algo::strptr&            in_hitrate
        ,u32                            in_n_warn
        ,u32                            in_n_err
        ,u16                            in_n_install)
    : n_target(in_n_target)
    , time(in_time)
    , hitrate(in_hitrate)
    , n_warn(in_n_warn)
    , n_err(in_n_err)
    , n_install(in_n_install)
{
}
inline report::abt::abt() {
    report::abt_Init(*this);
}


// --- report.abt..Init
// Set all fields to initial values.
inline void report::abt_Init(report::abt& parent) {
    parent.n_target = u16(0);
    parent.n_warn = u32(0);
    parent.n_err = u32(0);
    parent.n_install = u16(0);
}
inline report::acr::acr() {
    report::acr_Init(*this);
}


// --- report.acr..Init
// Set all fields to initial values.
inline void report::acr_Init(report::acr& parent) {
    parent.n_select = u32(0);
    parent.n_insert = u32(0);
    parent.n_delete = u32(0);
    parent.n_ignore = u32(0);
    parent.n_update = u32(0);
    parent.n_file_mod = u32(0);
}
inline report::acr_check::acr_check(u32                            in_records
        ,u32                            in_errors)
    : records(in_records)
    , errors(in_errors)
{
}
inline report::acr_check::acr_check() {
    report::acr_check_Init(*this);
}


// --- report.acr_check..Init
// Set all fields to initial values.
inline void report::acr_check_Init(report::acr_check& parent) {
    parent.records = u32(0);
    parent.errors = u32(0);
}
inline report::amc::amc() {
    report::amc_Init(*this);
}


// --- report.amc..Init
// Set all fields to initial values.
inline void report::amc_Init(report::amc& parent) {
    parent.n_cppfile = u32(0);
    parent.n_cppline = u32(0);
    parent.n_ctype = u32(0);
    parent.n_func = u32(0);
    parent.n_xref = u32(0);
    parent.n_filemod = u32(0);
}
inline report::atf_comp::atf_comp() {
    report::atf_comp_Init(*this);
}


// --- report.atf_comp..Init
// Set all fields to initial values.
inline void report::atf_comp_Init(report::atf_comp& parent) {
    parent.ntest = i32(0);
    parent.nselect = i32(0);
    parent.npass = i32(0);
    parent.nskip = i32(0);
    parent.nrun = i32(0);
    parent.nwrite = i32(0);
    parent.nerr = i32(0);
    parent.ninsert = i32(0);
    parent.success = bool(false);
}
inline report::atf_unit::atf_unit() {
    report::atf_unit_Init(*this);
}


// --- report.atf_unit..Init
// Set all fields to initial values.
inline void report::atf_unit_Init(report::atf_unit& parent) {
    parent.n_test_total = u32(0);
    parent.success = bool(false);
    parent.n_test_run = u64(0);
    parent.n_err = u64(0);
}
inline report::gcache::gcache(algo::UnTime                   in_starttime
        ,double                         in_elapsed_sec
        ,i32                            in_preproc_size
        ,bool                           in_hit
        ,const algo::strptr&            in_cached_file
        ,bool                           in_copy_file_range)
    : starttime(in_starttime)
    , elapsed_sec(in_elapsed_sec)
    , preproc_size(in_preproc_size)
    , hit(in_hit)
    , cached_file(in_cached_file)
    , copy_file_range(in_copy_file_range)
{
}
inline report::gcache::gcache() {
    report::gcache_Init(*this);
}


// --- report.gcache..Init
// Set all fields to initial values.
inline void report::gcache_Init(report::gcache& parent) {
    parent.elapsed_sec = double(0.0);
    parent.preproc_size = i32(0);
    parent.hit = bool(false);
    parent.copy_file_range = bool(false);
}
inline report::src_func::src_func() {
    report::src_func_Init(*this);
}


// --- report.src_func..Init
// Set all fields to initial values.
inline void report::src_func_Init(report::src_func& parent) {
    parent.n_func = u32(0);
    parent.n_line = u32(0);
    parent.n_static = u32(0);
    parent.n_inline = u32(0);
    parent.n_mysteryfunc = u32(0);
    parent.n_filemod = u32(0);
    parent.n_baddecl = u32(0);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::FieldId &row) {// cfmt:report.FieldId.String
    report::FieldId_Print(const_cast<report::FieldId&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::abt &row) {// cfmt:report.abt.String
    report::abt_Print(const_cast<report::abt&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::acr &row) {// cfmt:report.acr.String
    report::acr_Print(const_cast<report::acr&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::acr_check &row) {// cfmt:report.acr_check.String
    report::acr_check_Print(const_cast<report::acr_check&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::amc &row) {// cfmt:report.amc.String
    report::amc_Print(const_cast<report::amc&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::atf_comp &row) {// cfmt:report.atf_comp.String
    report::atf_comp_Print(const_cast<report::atf_comp&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::atf_unit &row) {// cfmt:report.atf_unit.String
    report::atf_unit_Print(const_cast<report::atf_unit&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::gcache &row) {// cfmt:report.gcache.String
    report::gcache_Print(const_cast<report::gcache&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const report::src_func &row) {// cfmt:report.src_func.String
    report::src_func_Print(const_cast<report::src_func&>(row), str);
    return str;
}
