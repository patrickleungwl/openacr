//
// include/gen/dev_gen.inl.h
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
inline dev::Arch::Arch(const algo::strptr&            in_arch
        ,const algo::Comment&           in_comment)
    : arch(in_arch)
    , comment(in_comment)
{
}
inline dev::Arch::Arch() {
}

inline dev::Badline::Badline() {
}

inline dev::Builddir::Builddir() {
}

inline dev::Cfg::Cfg(const algo::strptr&            in_cfg
        ,const algo::strptr&            in_suffix
        ,const algo::Comment&           in_comment)
    : cfg(in_cfg)
    , suffix(in_suffix)
    , comment(in_comment)
{
}
inline dev::Cfg::Cfg() {
}

inline dev::Compiler::Compiler(const algo::strptr&            in_compiler
        ,const algo::strptr&            in_ranlib
        ,const algo::strptr&            in_ar
        ,const algo::strptr&            in_link
        ,const algo::strptr&            in_libext
        ,const algo::strptr&            in_exeext
        ,const algo::strptr&            in_pchext
        ,const algo::strptr&            in_objext
        ,const algo::strptr&            in_rc
        ,const algo::Comment&           in_comment)
    : compiler(in_compiler)
    , ranlib(in_ranlib)
    , ar(in_ar)
    , link(in_link)
    , libext(in_libext)
    , exeext(in_exeext)
    , pchext(in_pchext)
    , objext(in_objext)
    , rc(in_rc)
    , comment(in_comment)
{
}
inline dev::Compiler::Compiler() {
}

inline dev::Covfile::Covfile() {
    dev::Covfile_Init(*this);
}


// --- dev.Covfile..Init
// Set all fields to initial values.
inline void dev::Covfile_Init(dev::Covfile& parent) {
    parent.total = u32(0);
    parent.nonexe = u32(0);
    parent.exe = u32(0);
    parent.hit = u32(0);
}
inline dev::Covline::Covline() {
    dev::Covline_Init(*this);
}


// --- dev.Covline.flag.GetEnum
// Get value of field as enum type
inline dev_Covline_flag_Enum dev::flag_GetEnum(const dev::Covline& parent) {
    return dev_Covline_flag_Enum(parent.flag);
}

// --- dev.Covline.flag.SetEnum
// Set value of field from enum type.
inline void dev::flag_SetEnum(dev::Covline& parent, dev_Covline_flag_Enum rhs) {
    parent.flag = char(rhs);
}

// --- dev.Covline..Init
// Set all fields to initial values.
inline void dev::Covline_Init(dev::Covline& parent) {
    parent.flag = char('N');
    parent.hit = u32(0);
}
inline dev::Covtarget::Covtarget() {
    dev::Covtarget_Init(*this);
}


// --- dev.Covtarget..Init
// Set all fields to initial values.
inline void dev::Covtarget_Init(dev::Covtarget& parent) {
    parent.total = u32(0);
    parent.nonexe = u32(0);
    parent.exe = u32(0);
    parent.hit = u32(0);
}
inline dev::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline dev::FieldId::FieldId(dev_FieldIdEnum arg) { this->value = i32(arg); }
inline dev::FieldId::FieldId() {
    dev::FieldId_Init(*this);
}


// --- dev.FieldId.value.GetEnum
// Get value of field as enum type
inline dev_FieldIdEnum dev::value_GetEnum(const dev::FieldId& parent) {
    return dev_FieldIdEnum(parent.value);
}

// --- dev.FieldId.value.SetEnum
// Set value of field from enum type.
inline void dev::value_SetEnum(dev::FieldId& parent, dev_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- dev.FieldId.value.Cast
inline dev::FieldId::operator dev_FieldIdEnum () const {
    return dev_FieldIdEnum((*this).value);
}

// --- dev.FieldId..Init
// Set all fields to initial values.
inline void dev::FieldId_Init(dev::FieldId& parent) {
    parent.value = i32(-1);
}
inline dev::Gitfile::Gitfile(const algo::strptr&            in_gitfile)
    : gitfile(in_gitfile)
{
}
inline dev::Gitfile::Gitfile() {
}

inline dev::Gitinfo::Gitinfo(const algo::strptr&            in_gitinfo
        ,const algo::strptr&            in_author
        ,const algo::strptr&            in_cfg
        ,const algo::strptr&            in_compver
        ,const algo::strptr&            in_package
        ,const algo::Comment&           in_comment)
    : gitinfo(in_gitinfo)
    , author(in_author)
    , cfg(in_cfg)
    , compver(in_compver)
    , package(in_package)
    , comment(in_comment)
{
}
inline dev::Gitinfo::Gitinfo() {
}

inline dev::Hilite::Hilite() {
}

inline dev::Htmlentity::Htmlentity() {
    dev::Htmlentity_Init(*this);
}


// --- dev.Htmlentity..Init
// Set all fields to initial values.
inline void dev::Htmlentity_Init(dev::Htmlentity& parent) {
    parent.code = i32(0);
}
inline dev::Include::Include() {
    dev::Include_Init(*this);
}


// --- dev.Include..Init
// Set all fields to initial values.
inline void dev::Include_Init(dev::Include& parent) {
    parent.sys = bool(false);
}
inline dev::Issue::Issue() {
}

inline dev::License::License() {
}

inline dev::Linelim::Linelim() {
    dev::Linelim_Init(*this);
}


// --- dev.Linelim..Init
// Set all fields to initial values.
inline void dev::Linelim_Init(dev::Linelim& parent) {
    parent.nlongline = u32(0);
    parent.longestline = u32(0);
    parent.nbadws = u32(0);
    parent.maxws = u32(0);
    parent.nlongfunc = u32(0);
    parent.longestfunc = u32(0);
    parent.nmysteryfunc = u32(0);
}
inline dev::Mr::Mr() {
}

inline dev::Msgfile::Msgfile() {
    dev::Msgfile_Init(*this);
}


// --- dev.Msgfile..Init
// Set all fields to initial values.
inline void dev::Msgfile_Init(dev::Msgfile& parent) {
    parent.strict = bool(false);
}
inline dev::Noindent::Noindent() {
}

inline dev::OptType::OptType(const algo::strptr&            in_opt_type
        ,const algo::strptr&            in_sep
        ,const algo::Comment&           in_comment)
    : opt_type(in_opt_type)
    , sep(in_sep)
    , comment(in_comment)
{
}
inline dev::OptType::OptType() {
}

inline dev::Project::Project() {
}

inline dev::Readme::Readme(const algo::strptr&            in_gitfile
        ,bool                           in_inl
        ,bool                           in_sandbox
        ,const algo::strptr&            in_filter
        ,const algo::Comment&           in_comment)
    : gitfile(in_gitfile)
    , inl(in_inl)
    , sandbox(in_sandbox)
    , filter(in_filter)
    , comment(in_comment)
{
}
inline dev::Readme::Readme() {
    dev::Readme_Init(*this);
}


// --- dev.Readme..Init
// Set all fields to initial values.
inline void dev::Readme_Init(dev::Readme& parent) {
    parent.inl = bool(false);
    parent.sandbox = bool(false);
}
inline dev::Sandbox::Sandbox() {
}

inline dev::Sbpath::Sbpath() {
}

inline dev::Scriptfile::Scriptfile() {
}

inline dev::Srcfile::Srcfile() {
}

inline dev::Ssimfs::Ssimfs() {
    dev::Ssimfs_Init(*this);
}


// --- dev.Ssimfs..Init
// Set all fields to initial values.
inline void dev::Ssimfs_Init(dev::Ssimfs& parent) {
    parent.rmfile = bool(false);
    parent.needfile = bool(false);
}
inline dev::Syscmd::Syscmd(i64                            in_syscmd
        ,const algo::strptr&            in_command
        ,i32                            in_pid
        ,i32                            in_status
        ,i32                            in_nprereq
        ,bool                           in_fail_prereq
        ,bool                           in_completed
        ,i32                            in_maxtime)
    : syscmd(in_syscmd)
    , command(in_command)
    , pid(in_pid)
    , status(in_status)
    , nprereq(in_nprereq)
    , fail_prereq(in_fail_prereq)
    , completed(in_completed)
    , maxtime(in_maxtime)
{
}
inline dev::Syscmd::Syscmd() {
    dev::Syscmd_Init(*this);
}


// --- dev.Syscmd..Init
// Set all fields to initial values.
inline void dev::Syscmd_Init(dev::Syscmd& parent) {
    parent.syscmd = i64(0);
    parent.pid = i32(0);
    parent.status = i32(0);
    parent.nprereq = i32(0);
    parent.fail_prereq = bool(false);
    parent.completed = bool(false);
    parent.maxtime = i32(0);
}
inline dev::Syscmddep::Syscmddep(i64                            in_child
        ,i64                            in_parent)
    : child(in_child)
    , parent(in_parent)
{
}
inline dev::Syscmddep::Syscmddep() {
    dev::Syscmddep_Init(*this);
}


// --- dev.Syscmddep..Init
// Set all fields to initial values.
inline void dev::Syscmddep_Init(dev::Syscmddep& parent) {
    parent.child = i64(0);
    parent.parent = i64(0);
}
inline dev::Syslib::Syslib() {
}

inline dev::Targdep::Targdep(const algo::strptr&            in_targdep
        ,const algo::Comment&           in_comment)
    : targdep(in_targdep)
    , comment(in_comment)
{
}
inline dev::Targdep::Targdep() {
}

inline dev::Target::Target(const algo::strptr&            in_target
        ,const algo::strptr&            in_compat)
    : target(in_target)
    , compat(in_compat)
{
}
inline dev::Target::Target() {
    dev::Target_Init(*this);
}


// --- dev.Target..Init
// Set all fields to initial values.
inline void dev::Target_Init(dev::Target& parent) {
    parent.compat = algo::strptr("Linux-%.%-%");
}
inline dev::Targsrc::Targsrc(const algo::strptr&            in_targsrc
        ,const algo::Comment&           in_comment)
    : targsrc(in_targsrc)
    , comment(in_comment)
{
}
inline dev::Targsrc::Targsrc() {
}

inline dev::Targsyslib::Targsyslib() {
}

inline dev::Tgtcov::Tgtcov() {
}

inline dev::Timefmt::Timefmt() {
    dev::Timefmt_Init(*this);
}


// --- dev.Timefmt..Init
// Set all fields to initial values.
inline void dev::Timefmt_Init(dev::Timefmt& parent) {
    parent.dirname = bool(false);
}
inline dev::ToolOpt::ToolOpt(const algo::strptr&            in_tool_opt
        ,const algo::Comment&           in_comment)
    : tool_opt(in_tool_opt)
    , comment(in_comment)
{
}
inline dev::ToolOpt::ToolOpt() {
}

inline dev::Uname::Uname(const algo::strptr&            in_uname
        ,const algo::Comment&           in_comment)
    : uname(in_uname)
    , comment(in_comment)
{
}
inline dev::Uname::Uname() {
}

inline dev::Unstablefld::Unstablefld() {
}


inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Badline &row) {// cfmt:dev.Badline.String
    dev::Badline_Print(const_cast<dev::Badline&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Covfile &row) {// cfmt:dev.Covfile.String
    dev::Covfile_Print(const_cast<dev::Covfile&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Covline &row) {// cfmt:dev.Covline.String
    dev::Covline_Print(const_cast<dev::Covline&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Covtarget &row) {// cfmt:dev.Covtarget.String
    dev::Covtarget_Print(const_cast<dev::Covtarget&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::FieldId &row) {// cfmt:dev.FieldId.String
    dev::FieldId_Print(const_cast<dev::FieldId&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Gitfile &row) {// cfmt:dev.Gitfile.String
    dev::Gitfile_Print(const_cast<dev::Gitfile&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Hilite &row) {// cfmt:dev.Hilite.String
    dev::Hilite_Print(const_cast<dev::Hilite&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Htmlentity &row) {// cfmt:dev.Htmlentity.String
    dev::Htmlentity_Print(const_cast<dev::Htmlentity&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Include &row) {// cfmt:dev.Include.String
    dev::Include_Print(const_cast<dev::Include&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Issue &row) {// cfmt:dev.Issue.String
    dev::Issue_Print(const_cast<dev::Issue&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::License &row) {// cfmt:dev.License.String
    dev::License_Print(const_cast<dev::License&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Linelim &row) {// cfmt:dev.Linelim.String
    dev::Linelim_Print(const_cast<dev::Linelim&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Mr &row) {// cfmt:dev.Mr.String
    dev::Mr_Print(const_cast<dev::Mr&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Msgfile &row) {// cfmt:dev.Msgfile.String
    dev::Msgfile_Print(const_cast<dev::Msgfile&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Noindent &row) {// cfmt:dev.Noindent.String
    dev::Noindent_Print(const_cast<dev::Noindent&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Readme &row) {// cfmt:dev.Readme.String
    dev::Readme_Print(const_cast<dev::Readme&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Sandbox &row) {// cfmt:dev.Sandbox.String
    dev::Sandbox_Print(const_cast<dev::Sandbox&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Sbpath &row) {// cfmt:dev.Sbpath.String
    dev::Sbpath_Print(const_cast<dev::Sbpath&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Scriptfile &row) {// cfmt:dev.Scriptfile.String
    dev::Scriptfile_Print(const_cast<dev::Scriptfile&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Srcfile &row) {// cfmt:dev.Srcfile.String
    dev::Srcfile_Print(const_cast<dev::Srcfile&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Ssimfs &row) {// cfmt:dev.Ssimfs.String
    dev::Ssimfs_Print(const_cast<dev::Ssimfs&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Syscmd &row) {// cfmt:dev.Syscmd.String
    dev::Syscmd_Print(const_cast<dev::Syscmd&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Syscmddep &row) {// cfmt:dev.Syscmddep.String
    dev::Syscmddep_Print(const_cast<dev::Syscmddep&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Syslib &row) {// cfmt:dev.Syslib.String
    dev::Syslib_Print(const_cast<dev::Syslib&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Targdep &row) {// cfmt:dev.Targdep.String
    dev::Targdep_Print(const_cast<dev::Targdep&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Target &row) {// cfmt:dev.Target.String
    dev::Target_Print(const_cast<dev::Target&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Targsrc &row) {// cfmt:dev.Targsrc.String
    dev::Targsrc_Print(const_cast<dev::Targsrc&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Targsyslib &row) {// cfmt:dev.Targsyslib.String
    dev::Targsyslib_Print(const_cast<dev::Targsyslib&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Tgtcov &row) {// cfmt:dev.Tgtcov.String
    dev::Tgtcov_Print(const_cast<dev::Tgtcov&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Timefmt &row) {// cfmt:dev.Timefmt.String
    dev::Timefmt_Print(const_cast<dev::Timefmt&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::ToolOpt &row) {// cfmt:dev.ToolOpt.String
    dev::ToolOpt_Print(const_cast<dev::ToolOpt&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Uname &row) {// cfmt:dev.Uname.String
    dev::Uname_Print(const_cast<dev::Uname&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const dev::Unstablefld &row) {// cfmt:dev.Unstablefld.String
    dev::Unstablefld_Print(const_cast<dev::Unstablefld&>(row), str);
    return str;
}
