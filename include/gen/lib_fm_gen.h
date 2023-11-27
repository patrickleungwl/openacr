//
// include/gen/lib_fm_gen.h
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
#include "include/gen/fmdb_gen.h"
#include "include/gen/algo_gen.h"
#include "include/gen/fm_gen.h"
//#pragma endinclude
// gen:ns_enums

// --- lib_fm_FieldIdEnum

enum lib_fm_FieldIdEnum {        // lib_fm.FieldId.value
     lib_fm_FieldId_value   = 0
};

enum { lib_fm_FieldIdEnum_N = 1 };


// --- lib_fm_TableIdEnum

enum lib_fm_TableIdEnum {                    // lib_fm.TableId.value
     lib_fm_TableId_fmdb_AlmCode       = 0   // fmdb.AlmCode -> lib_fm.FAlmCode
    ,lib_fm_TableId_fmdb_alm_code      = 0   // fmdb.alm_code -> lib_fm.FAlmCode
    ,lib_fm_TableId_fmdb_AlmObjtype    = 1   // fmdb.AlmObjtype -> lib_fm.FAlmObjtype
    ,lib_fm_TableId_fmdb_alm_objtype   = 1   // fmdb.alm_objtype -> lib_fm.FAlmObjtype
};

enum { lib_fm_TableIdEnum_N = 4 };

namespace lib_fm { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace lib_fm { // gen:ns_field
} // gen:ns_field
// gen:ns_fwddecl2
namespace lib_fm { struct _db_alarm_curs; }
namespace lib_fm { struct _db_alm_code_curs; }
namespace lib_fm { struct _db_alm_objtype_curs; }
namespace lib_fm { struct FAlarm; }
namespace lib_fm { struct FAlmCode; }
namespace lib_fm { struct FAlmObjtype; }
namespace lib_fm { struct trace; }
namespace lib_fm { struct FDb; }
namespace lib_fm { struct FieldId; }
namespace lib_fm { struct TableId; }
namespace lib_fm { extern struct lib_fm::FDb _db; }
namespace lib_fm { // hook_fcn_typedef
    typedef void (*_db_h_alarm_hook)(void* userctx, lib_fm::FAlarm& arg); // hook:lib_fm.FDb.h_alarm
} // hook_decl
namespace lib_fm { // gen:ns_gsymbol
    extern const char* fmdb_alm_code_TEST_EXER; // "TEST-EXER"
} // gen:ns_gsymbol
namespace lib_fm { // gen:ns_gsymbol
    extern const char* fmdb_alm_objtype_SYS; // "SYS"
} // gen:ns_gsymbol
namespace lib_fm { // gen:ns_gsymbol
    extern const char* fmdb_alm_source_UnitTest; // "UnitTest"
} // gen:ns_gsymbol
namespace lib_fm { // gen:ns_print_struct

// --- lib_fm.FAlarm
// create: lib_fm.FDb.alarm (Lary)
// global access: ind_alarm (Thash)
// global access: h_alarm (Hook)
struct FAlarm { // lib_fm.FAlarm
    algo::Smallstr200   alarm;             // Alarm identity: code@object
    fm::Flag            flag;              // Flag: raised or cleared
    fm::Severity        severity;          // Perceived severity
    i32                 n_occurred;        //   0  How many times the alarm occurred since first_time
    algo::UnTime        first_time;        // Time of first occurrence
    algo::UnTime        last_time;         // Time of last occurrence
    algo::UnTime        clear_time;        // Time when the alarm has beed cleared (only for cleared alarms
    algo::UnTime        update_time;       // Time of last update
    fm::Summary         objtype_summary;   // Object type explained
    fm::Summary         summary;           // Alarm summary from inventory
    fm::Description     description;       // Alarm message from object
    fm::Source          source;            // Subsystem where alarm has been detected
    lib_fm::FAlarm*     ind_alarm_next;    // hash next
private:
    friend lib_fm::FAlarm&      alarm_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend lib_fm::FAlarm*      alarm_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 alarm_RemoveAll() __attribute__((nothrow));
    friend void                 alarm_RemoveLast() __attribute__((nothrow));
    FAlarm();
    ~FAlarm();
    FAlarm(const FAlarm&){ /*disallow copy constructor */}
    void operator =(const FAlarm&){ /*disallow direct assignment */}
};

// Copy fields out of row
void                 alarm_CopyOut(lib_fm::FAlarm &row, fmdb::Alarm &out) __attribute__((nothrow));
// Copy fields in to row
void                 alarm_CopyIn(lib_fm::FAlarm &row, fmdb::Alarm &in) __attribute__((nothrow));

fm::Code             code_Get(lib_fm::FAlarm& alarm) __attribute__((__warn_unused_result__, nothrow));

algo::Smallstr200    object_Get(lib_fm::FAlarm& alarm) __attribute__((__warn_unused_result__, nothrow));

fm::Objtype          objtype_Get(lib_fm::FAlarm& alarm) __attribute__((__warn_unused_result__, nothrow));

fm::Objinst          objinst_Get(lib_fm::FAlarm& alarm) __attribute__((__warn_unused_result__, nothrow));

algo::Smallstr50     objprefix_Get(lib_fm::FAlarm& alarm) __attribute__((__warn_unused_result__, nothrow));

// Set all fields to initial values.
void                 FAlarm_Init(lib_fm::FAlarm& alarm);
void                 FAlarm_Uninit(lib_fm::FAlarm& alarm) __attribute__((nothrow));

// --- lib_fm.FAlmCode
// create: lib_fm.FDb.alm_code (Lary)
// global access: ind_alm_code (Thash)
struct FAlmCode { // lib_fm.FAlmCode
    fm::Code            alm_code;            // Alarm code
    fm::Severity        severity;            // Assigned severity
    fm::Source          source;              //
    fm::Summary         summary;             // Alarm summary (slogan)
    lib_fm::FAlmCode*   ind_alm_code_next;   // hash next
private:
    friend lib_fm::FAlmCode&    alm_code_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend lib_fm::FAlmCode*    alm_code_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 alm_code_RemoveAll() __attribute__((nothrow));
    friend void                 alm_code_RemoveLast() __attribute__((nothrow));
    FAlmCode();
    ~FAlmCode();
    FAlmCode(const FAlmCode&){ /*disallow copy constructor */}
    void operator =(const FAlmCode&){ /*disallow direct assignment */}
};

// Copy fields out of row
void                 alm_code_CopyOut(lib_fm::FAlmCode &row, fmdb::AlmCode &out) __attribute__((nothrow));
// Copy fields in to row
void                 alm_code_CopyIn(lib_fm::FAlmCode &row, fmdb::AlmCode &in) __attribute__((nothrow));

// Set all fields to initial values.
void                 FAlmCode_Init(lib_fm::FAlmCode& alm_code);
void                 FAlmCode_Uninit(lib_fm::FAlmCode& alm_code) __attribute__((nothrow));

// --- lib_fm.FAlmObjtype
// create: lib_fm.FDb.alm_objtype (Lary)
// global access: ind_alm_objtype (Thash)
struct FAlmObjtype { // lib_fm.FAlmObjtype
    fm::Objtype            alm_objtype;            // Object type
    fm::Summary            summary;                // Object type summary
    lib_fm::FAlmObjtype*   ind_alm_objtype_next;   // hash next
private:
    friend lib_fm::FAlmObjtype& alm_objtype_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend lib_fm::FAlmObjtype* alm_objtype_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 alm_objtype_RemoveAll() __attribute__((nothrow));
    friend void                 alm_objtype_RemoveLast() __attribute__((nothrow));
    FAlmObjtype();
    ~FAlmObjtype();
    FAlmObjtype(const FAlmObjtype&){ /*disallow copy constructor */}
    void operator =(const FAlmObjtype&){ /*disallow direct assignment */}
};

// Copy fields out of row
void                 alm_objtype_CopyOut(lib_fm::FAlmObjtype &row, fmdb::AlmObjtype &out) __attribute__((nothrow));
// Copy fields in to row
void                 alm_objtype_CopyIn(lib_fm::FAlmObjtype &row, fmdb::AlmObjtype &in) __attribute__((nothrow));

// Set all fields to initial values.
void                 FAlmObjtype_Init(lib_fm::FAlmObjtype& alm_objtype);
void                 FAlmObjtype_Uninit(lib_fm::FAlmObjtype& alm_objtype) __attribute__((nothrow));

// --- lib_fm.trace
#pragma pack(push,1)
struct trace { // lib_fm.trace
    trace();
};
#pragma pack(pop)

// print string representation of lib_fm::trace to string LHS, no header -- cprint:lib_fm.trace.String
void                 trace_Print(lib_fm::trace & row, algo::cstring &str) __attribute__((nothrow));

// --- lib_fm.FDb
// create: lib_fm.FDb._db (Global)
struct FDb { // lib_fm.FDb
    lib_fm::FAlarm*            alarm_lary[32];                  // level array
    i32                        alarm_n;                         // number of elements in array
    lib_fm::FAlarm**           ind_alarm_buckets_elems;         // pointer to bucket array
    i32                        ind_alarm_buckets_n;             // number of elements in bucket array
    i32                        ind_alarm_n;                     // number of elements in the hash table
    lib_fm::FAlmCode*          alm_code_lary[32];               // level array
    i32                        alm_code_n;                      // number of elements in array
    lib_fm::FAlmCode**         ind_alm_code_buckets_elems;      // pointer to bucket array
    i32                        ind_alm_code_buckets_n;          // number of elements in bucket array
    i32                        ind_alm_code_n;                  // number of elements in the hash table
    algo::cstring              object_prefix;                   //
    lib_fm::FAlmObjtype*       alm_objtype_lary[32];            // level array
    i32                        alm_objtype_n;                   // number of elements in array
    lib_fm::FAlmObjtype**      ind_alm_objtype_buckets_elems;   // pointer to bucket array
    i32                        ind_alm_objtype_buckets_n;       // number of elements in bucket array
    i32                        ind_alm_objtype_n;               // number of elements in the hash table
    lib_fm::_db_h_alarm_hook   h_alarm;                         //   NULL  Pointer to a function
    u64                        h_alarm_ctx;                     //   0  Callback context
    lib_fm::trace              trace;                           //
};

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
// Save ssim data to given directory.
u32                  SaveTuples(algo::strptr root) __attribute__((nothrow));
// Load specified ssimfile.
bool                 LoadSsimfileMaybe(algo::strptr fname, bool recursive) __attribute__((nothrow));
// Calls Step function of dependencies
void                 Steps();
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 _db_XrefMaybe();

// Allocate memory for new default row.
// If out of memory, process is killed.
lib_fm::FAlarm&      alarm_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
lib_fm::FAlarm*      alarm_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
lib_fm::FAlarm*      alarm_InsertMaybe(const fmdb::Alarm &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                alarm_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 alarm_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
lib_fm::FAlarm*      alarm_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
lib_fm::FAlarm*      alarm_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  alarm_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
void                 alarm_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 alarm_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
lib_fm::FAlarm&      alarm_qFind(u64 t) __attribute__((nothrow, pure));
// Save table to ssimfile
bool                 alarm_SaveSsimfile(algo::strptr fname) __attribute__((nothrow));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 alarm_XrefMaybe(lib_fm::FAlarm &row);

// Return true if hash is empty
bool                 ind_alarm_EmptyQ() __attribute__((nothrow));
// Find row by key. Return NULL if not found.
lib_fm::FAlarm*      ind_alarm_Find(const algo::strptr& key) __attribute__((__warn_unused_result__, nothrow));
// Look up row by key and return reference. Throw exception if not found
lib_fm::FAlarm&      ind_alarm_FindX(const algo::strptr& key);
// Find row by key. If not found, create and x-reference a new row with with this key.
lib_fm::FAlarm&      ind_alarm_GetOrCreate(const algo::strptr& key) __attribute__((nothrow));
// Return number of items in the hash
i32                  ind_alarm_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
bool                 ind_alarm_InsertMaybe(lib_fm::FAlarm& row) __attribute__((nothrow));
// Remove reference to element from hash index. If element is not in hash, do nothing
void                 ind_alarm_Remove(lib_fm::FAlarm& row) __attribute__((nothrow));
// Reserve enough room in the hash for N more elements. Return success code.
void                 ind_alarm_Reserve(int n) __attribute__((nothrow));

// Allocate memory for new default row.
// If out of memory, process is killed.
lib_fm::FAlmCode&    alm_code_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
lib_fm::FAlmCode*    alm_code_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
lib_fm::FAlmCode*    alm_code_InsertMaybe(const fmdb::AlmCode &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                alm_code_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 alm_code_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
lib_fm::FAlmCode*    alm_code_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
lib_fm::FAlmCode*    alm_code_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  alm_code_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
void                 alm_code_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 alm_code_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
lib_fm::FAlmCode&    alm_code_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 alm_code_XrefMaybe(lib_fm::FAlmCode &row);

// Return true if hash is empty
bool                 ind_alm_code_EmptyQ() __attribute__((nothrow));
// Find row by key. Return NULL if not found.
lib_fm::FAlmCode*    ind_alm_code_Find(const algo::strptr& key) __attribute__((__warn_unused_result__, nothrow));
// Look up row by key and return reference. Throw exception if not found
lib_fm::FAlmCode&    ind_alm_code_FindX(const algo::strptr& key);
// Find row by key. If not found, create and x-reference a new row with with this key.
lib_fm::FAlmCode&    ind_alm_code_GetOrCreate(const algo::strptr& key) __attribute__((nothrow));
// Return number of items in the hash
i32                  ind_alm_code_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
bool                 ind_alm_code_InsertMaybe(lib_fm::FAlmCode& row) __attribute__((nothrow));
// Remove reference to element from hash index. If element is not in hash, do nothing
void                 ind_alm_code_Remove(lib_fm::FAlmCode& row) __attribute__((nothrow));
// Reserve enough room in the hash for N more elements. Return success code.
void                 ind_alm_code_Reserve(int n) __attribute__((nothrow));

// Allocate memory for new default row.
// If out of memory, process is killed.
lib_fm::FAlmObjtype& alm_objtype_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
lib_fm::FAlmObjtype* alm_objtype_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
lib_fm::FAlmObjtype* alm_objtype_InsertMaybe(const fmdb::AlmObjtype &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                alm_objtype_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 alm_objtype_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
lib_fm::FAlmObjtype* alm_objtype_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
lib_fm::FAlmObjtype* alm_objtype_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  alm_objtype_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
void                 alm_objtype_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 alm_objtype_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
lib_fm::FAlmObjtype& alm_objtype_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 alm_objtype_XrefMaybe(lib_fm::FAlmObjtype &row);

// Return true if hash is empty
bool                 ind_alm_objtype_EmptyQ() __attribute__((nothrow));
// Find row by key. Return NULL if not found.
lib_fm::FAlmObjtype* ind_alm_objtype_Find(const algo::strptr& key) __attribute__((__warn_unused_result__, nothrow));
// Look up row by key and return reference. Throw exception if not found
lib_fm::FAlmObjtype& ind_alm_objtype_FindX(const algo::strptr& key);
// Find row by key. If not found, create and x-reference a new row with with this key.
lib_fm::FAlmObjtype& ind_alm_objtype_GetOrCreate(const algo::strptr& key) __attribute__((nothrow));
// Return number of items in the hash
i32                  ind_alm_objtype_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
bool                 ind_alm_objtype_InsertMaybe(lib_fm::FAlmObjtype& row) __attribute__((nothrow));
// Remove reference to element from hash index. If element is not in hash, do nothing
void                 ind_alm_objtype_Remove(lib_fm::FAlmObjtype& row) __attribute__((nothrow));
// Reserve enough room in the hash for N more elements. Return success code.
void                 ind_alm_objtype_Reserve(int n) __attribute__((nothrow));

// Invoke function by pointer
void                 h_alarm_Call(lib_fm::FAlarm& arg) __attribute__((nothrow));
// Assign 0-argument hook with no context pointer
void                 h_alarm_Set0(void (*fcn)() ) __attribute__((nothrow));
// Assign 1-argument hook with context pointer
template<class T> void h_alarm_Set1(T& ctx, void (*fcn)(T&) ) __attribute__((nothrow));
// Assign 2-argument hook with context pointer
template<class T> void h_alarm_Set2(T& ctx, void (*fcn)(T&, lib_fm::FAlarm& arg) ) __attribute__((nothrow));

// cursor points to valid item
void                 _db_alarm_curs_Reset(_db_alarm_curs &curs, lib_fm::FDb &parent);
// cursor points to valid item
bool                 _db_alarm_curs_ValidQ(_db_alarm_curs &curs);
// proceed to next item
void                 _db_alarm_curs_Next(_db_alarm_curs &curs);
// item access
lib_fm::FAlarm&      _db_alarm_curs_Access(_db_alarm_curs &curs);
// cursor points to valid item
void                 _db_alm_code_curs_Reset(_db_alm_code_curs &curs, lib_fm::FDb &parent);
// cursor points to valid item
bool                 _db_alm_code_curs_ValidQ(_db_alm_code_curs &curs);
// proceed to next item
void                 _db_alm_code_curs_Next(_db_alm_code_curs &curs);
// item access
lib_fm::FAlmCode&    _db_alm_code_curs_Access(_db_alm_code_curs &curs);
// cursor points to valid item
void                 _db_alm_objtype_curs_Reset(_db_alm_objtype_curs &curs, lib_fm::FDb &parent);
// cursor points to valid item
bool                 _db_alm_objtype_curs_ValidQ(_db_alm_objtype_curs &curs);
// proceed to next item
void                 _db_alm_objtype_curs_Next(_db_alm_objtype_curs &curs);
// item access
lib_fm::FAlmObjtype& _db_alm_objtype_curs_Access(_db_alm_objtype_curs &curs);
// Set all fields to initial values.
void                 FDb_Init();
void                 FDb_Uninit() __attribute__((nothrow));

// --- lib_fm.FieldId
#pragma pack(push,1)
struct FieldId { // lib_fm.FieldId: Field read helper
    i32   value;   //   -1
    inline operator lib_fm_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(lib_fm_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
lib_fm_FieldIdEnum   value_GetEnum(const lib_fm::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(lib_fm::FieldId& parent, lib_fm_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const lib_fm::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const lib_fm::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(lib_fm::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(lib_fm::FieldId& parent, algo::strptr rhs, lib_fm_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(lib_fm::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of lib_fm::FieldId from an ascii string.
// The format of the string is the format of the lib_fm::FieldId's only field
bool                 FieldId_ReadStrptrMaybe(lib_fm::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 FieldId_Init(lib_fm::FieldId& parent);
// print string representation of lib_fm::FieldId to string LHS, no header -- cprint:lib_fm.FieldId.String
void                 FieldId_Print(lib_fm::FieldId & row, algo::cstring &str) __attribute__((nothrow));

// --- lib_fm.TableId
struct TableId { // lib_fm.TableId: Index of table in this namespace
    i32   value;   //   -1  index of table
    inline operator lib_fm_TableIdEnum() const;
    explicit TableId(i32                            in_value);
    TableId(lib_fm_TableIdEnum arg);
    TableId();
};

// Get value of field as enum type
lib_fm_TableIdEnum   value_GetEnum(const lib_fm::TableId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(lib_fm::TableId& parent, lib_fm_TableIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const lib_fm::TableId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const lib_fm::TableId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(lib_fm::TableId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(lib_fm::TableId& parent, algo::strptr rhs, lib_fm_TableIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(lib_fm::TableId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of lib_fm::TableId from an ascii string.
// The format of the string is the format of the lib_fm::TableId's only field
bool                 TableId_ReadStrptrMaybe(lib_fm::TableId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 TableId_Init(lib_fm::TableId& parent);
// print string representation of lib_fm::TableId to string LHS, no header -- cprint:lib_fm.TableId.String
void                 TableId_Print(lib_fm::TableId & row, algo::cstring &str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace lib_fm { // gen:ns_curstext

struct _db_alarm_curs {// cursor
    typedef lib_fm::FAlarm ChildType;
    lib_fm::FDb *parent;
    i64 index;
    _db_alarm_curs(){ parent=NULL; index=0; }
};


struct _db_alm_code_curs {// cursor
    typedef lib_fm::FAlmCode ChildType;
    lib_fm::FDb *parent;
    i64 index;
    _db_alm_code_curs(){ parent=NULL; index=0; }
};


struct _db_alm_objtype_curs {// cursor
    typedef lib_fm::FAlmObjtype ChildType;
    lib_fm::FDb *parent;
    i64 index;
    _db_alm_objtype_curs(){ parent=NULL; index=0; }
};

} // gen:ns_curstext
namespace lib_fm { // gen:ns_func
} // gen:ns_func
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const lib_fm::trace &row);// cfmt:lib_fm.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const lib_fm::FieldId &row);// cfmt:lib_fm.FieldId.String
inline algo::cstring &operator <<(algo::cstring &str, const lib_fm::TableId &row);// cfmt:lib_fm.TableId.String
}
