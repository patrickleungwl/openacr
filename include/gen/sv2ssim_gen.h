//
// include/gen/sv2ssim_gen.h
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
#include "include/gen/amcdb_gen.h"
#include "include/gen/algo_gen.h"
#include "include/gen/command_gen.h"
#include "include/gen/dmmeta_gen.h"
//#pragma endinclude
// gen:ns_enums

// --- sv2ssim_FieldIdEnum

enum sv2ssim_FieldIdEnum {                  // sv2ssim.FieldId.value
     sv2ssim_FieldId_name             = 0
    ,sv2ssim_FieldId_ctype            = 1
    ,sv2ssim_FieldId_maxwid           = 2
    ,sv2ssim_FieldId_minval           = 3
    ,sv2ssim_FieldId_maxval           = 4
    ,sv2ssim_FieldId_minwid_fix1      = 5
    ,sv2ssim_FieldId_maxwid_fix1      = 6
    ,sv2ssim_FieldId_minwid_fix2      = 7
    ,sv2ssim_FieldId_maxwid_fix2      = 8
    ,sv2ssim_FieldId_couldbe_int      = 9
    ,sv2ssim_FieldId_couldbe_bool     = 10
    ,sv2ssim_FieldId_couldbe_fixwid   = 11
    ,sv2ssim_FieldId_couldbe_double   = 12
    ,sv2ssim_FieldId_rowid            = 13
    ,sv2ssim_FieldId_value            = 14
};

enum { sv2ssim_FieldIdEnum_N = 15 };


// --- sv2ssim_TableIdEnum

enum sv2ssim_TableIdEnum {                 // sv2ssim.TableId.value
     sv2ssim_TableId_amcdb_Bltin     = 0   // amcdb.Bltin -> sv2ssim.FBltin
    ,sv2ssim_TableId_amcdb_bltin     = 0   // amcdb.bltin -> sv2ssim.FBltin
    ,sv2ssim_TableId_dmmeta_Svtype   = 1   // dmmeta.Svtype -> sv2ssim.FSvtype
    ,sv2ssim_TableId_dmmeta_svtype   = 1   // dmmeta.svtype -> sv2ssim.FSvtype
};

enum { sv2ssim_TableIdEnum_N = 4 };

namespace sv2ssim { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace sv2ssim { // gen:ns_field
extern const char *sv2ssim_help;
} // gen:ns_field
// gen:ns_fwddecl2
namespace sv2ssim { struct _db_field_curs; }
namespace sv2ssim { struct _db_linetok_curs; }
namespace sv2ssim { struct _db_svtype_curs; }
namespace sv2ssim { struct _db_zd_selfield_curs; }
namespace sv2ssim { struct _db_bltin_curs; }
namespace sv2ssim { struct FBltin; }
namespace sv2ssim { struct trace; }
namespace sv2ssim { struct FDb; }
namespace sv2ssim { struct FField; }
namespace sv2ssim { struct FSvtype; }
namespace sv2ssim { struct FieldId; }
namespace sv2ssim { struct TableId; }
namespace sv2ssim { extern struct sv2ssim::FDb _db; }
namespace sv2ssim { // gen:ns_print_struct

// --- sv2ssim.FBltin
// create: sv2ssim.FDb.bltin (Lary)
// global access: ind_bltin (Thash)
struct FBltin { // sv2ssim.FBltin
    algo::Smallstr50   ctype;            //
    bool               likeu64;          //   false
    bool               bigendok;         //   false
    bool               issigned;         //   false
    algo::Comment      comment;          //
    sv2ssim::FBltin*   ind_bltin_next;   // hash next
private:
    friend sv2ssim::FBltin&     bltin_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend sv2ssim::FBltin*     bltin_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 bltin_RemoveAll() __attribute__((nothrow));
    friend void                 bltin_RemoveLast() __attribute__((nothrow));
    FBltin();
    ~FBltin();
    FBltin(const FBltin&){ /*disallow copy constructor */}
    void operator =(const FBltin&){ /*disallow direct assignment */}
};

// Copy fields out of row
void                 bltin_CopyOut(sv2ssim::FBltin &row, amcdb::Bltin &out) __attribute__((nothrow));
// Copy fields in to row
void                 bltin_CopyIn(sv2ssim::FBltin &row, amcdb::Bltin &in) __attribute__((nothrow));

// Set all fields to initial values.
void                 FBltin_Init(sv2ssim::FBltin& bltin);
void                 FBltin_Uninit(sv2ssim::FBltin& bltin) __attribute__((nothrow));

// --- sv2ssim.trace
#pragma pack(push,1)
struct trace { // sv2ssim.trace
    trace();
};
#pragma pack(pop)

// print string representation of sv2ssim::trace to string LHS, no header -- cprint:sv2ssim.trace.String
void                 trace_Print(sv2ssim::trace & row, algo::cstring &str) __attribute__((nothrow));

// --- sv2ssim.FDb
// create: sv2ssim.FDb._db (Global)
struct FDb { // sv2ssim.FDb
    command::sv2ssim    cmdline;                   //
    sv2ssim::FField*    field_lary[32];            // level array
    i32                 field_n;                   // number of elements in array
    algo::cstring*      linetok_elems;             // pointer to elements
    u32                 linetok_n;                 // number of elements in array
    u32                 linetok_max;               // max. capacity of array before realloc
    i32                 n_wideline;                //   true  Number of lines wider than header
    sv2ssim::FSvtype*   svtype_lary[32];           // level array
    i32                 svtype_n;                  // number of elements in array
    sv2ssim::FField**   ind_field_buckets_elems;   // pointer to bucket array
    i32                 ind_field_buckets_n;       // number of elements in bucket array
    i32                 ind_field_n;               // number of elements in the hash table
    sv2ssim::FField*    zd_selfield_head;          // zero-terminated doubly linked list
    i32                 zd_selfield_n;             // zero-terminated doubly linked list
    sv2ssim::FField*    zd_selfield_tail;          // pointer to last element
    sv2ssim::FBltin*    bltin_lary[32];            // level array
    i32                 bltin_n;                   // number of elements in array
    sv2ssim::FBltin**   ind_bltin_buckets_elems;   // pointer to bucket array
    i32                 ind_bltin_buckets_n;       // number of elements in bucket array
    i32                 ind_bltin_n;               // number of elements in the hash table
    sv2ssim::trace      trace;                     //
};

// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     sv2ssim.FDb.cmdline
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

// Allocate memory for new default row.
// If out of memory, process is killed.
sv2ssim::FField&     field_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
sv2ssim::FField*     field_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                field_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 field_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
sv2ssim::FField*     field_Find(i32 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
sv2ssim::FField*     field_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  field_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
void                 field_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 field_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
sv2ssim::FField&     field_qFind(i32 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 field_XrefMaybe(sv2ssim::FField &row);

// Reserve space. Insert element at the end
// The new element is initialized to a default value
algo::cstring&       linetok_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Reserve space for new element, reallocating the array if necessary
// Insert new element at specified index. Index must be in range or a fatal error occurs.
algo::cstring&       linetok_AllocAt(int at) __attribute__((__warn_unused_result__, nothrow));
// Reserve space. Insert N elements at the end of the array, return pointer to array
algo::aryptr<algo::cstring> linetok_AllocN(int n_elems) __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 linetok_EmptyQ() __attribute__((nothrow));
// Look up row by row id. Return NULL if out of range
algo::cstring*       linetok_Find(u64 t) __attribute__((__warn_unused_result__, nothrow));
// Return array pointer by value
algo::aryptr<algo::cstring> linetok_Getary() __attribute__((nothrow));
// Return pointer to last element of array, or NULL if array is empty
algo::cstring*       linetok_Last() __attribute__((nothrow, pure));
// Return max. number of items in the array
i32                  linetok_Max() __attribute__((nothrow));
// Return number of items in the array
i32                  linetok_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove item by index. If index outside of range, do nothing.
void                 linetok_Remove(u32 i) __attribute__((nothrow));
void                 linetok_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 linetok_RemoveLast() __attribute__((nothrow));
// Make sure N *more* elements will fit in array. Process dies if out of memory
void                 linetok_Reserve(int n) __attribute__((nothrow));
// Make sure N elements fit in array. Process dies if out of memory
void                 linetok_AbsReserve(int n) __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
algo::cstring&       linetok_qFind(u64 t) __attribute__((nothrow));
// Return reference to last element of array. No bounds checking
algo::cstring&       linetok_qLast() __attribute__((nothrow));
// Return row id of specified element
u64                  linetok_rowid_Get(algo::cstring &elem) __attribute__((nothrow));
// Reserve space. Insert N elements at the end of the array, return pointer to array
algo::aryptr<algo::cstring> linetok_AllocNVal(int n_elems, const algo::cstring& val) __attribute__((nothrow));

// Allocate memory for new default row.
// If out of memory, process is killed.
sv2ssim::FSvtype&    svtype_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
sv2ssim::FSvtype*    svtype_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
sv2ssim::FSvtype*    svtype_InsertMaybe(const dmmeta::Svtype &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                svtype_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 svtype_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
sv2ssim::FSvtype*    svtype_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
sv2ssim::FSvtype*    svtype_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  svtype_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
void                 svtype_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 svtype_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
sv2ssim::FSvtype&    svtype_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 svtype_XrefMaybe(sv2ssim::FSvtype &row);

// Return true if hash is empty
bool                 ind_field_EmptyQ() __attribute__((nothrow));
// Find row by key. Return NULL if not found.
sv2ssim::FField*     ind_field_Find(const algo::strptr& key) __attribute__((__warn_unused_result__, nothrow));
// Look up row by key and return reference. Throw exception if not found
sv2ssim::FField&     ind_field_FindX(const algo::strptr& key);
// Find row by key. If not found, create and x-reference a new row with with this key.
sv2ssim::FField&     ind_field_GetOrCreate(const algo::strptr& key) __attribute__((nothrow));
// Return number of items in the hash
i32                  ind_field_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
bool                 ind_field_InsertMaybe(sv2ssim::FField& row) __attribute__((nothrow));
// Remove reference to element from hash index. If element is not in hash, do nothing
void                 ind_field_Remove(sv2ssim::FField& row) __attribute__((nothrow));
// Reserve enough room in the hash for N more elements. Return success code.
void                 ind_field_Reserve(int n) __attribute__((nothrow));

// Return true if index is empty
bool                 zd_selfield_EmptyQ() __attribute__((__warn_unused_result__, nothrow, pure));
// If index empty, return NULL. Otherwise return pointer to first element in index
sv2ssim::FField*     zd_selfield_First() __attribute__((__warn_unused_result__, nothrow, pure));
// Return true if row is in the linked list, false otherwise
bool                 zd_selfield_InLlistQ(sv2ssim::FField& row) __attribute__((__warn_unused_result__, nothrow));
// Insert row into linked list. If row is already in linked list, do nothing.
void                 zd_selfield_Insert(sv2ssim::FField& row) __attribute__((nothrow));
// If index empty, return NULL. Otherwise return pointer to last element in index
sv2ssim::FField*     zd_selfield_Last() __attribute__((__warn_unused_result__, nothrow, pure));
// Return number of items in the linked list
i32                  zd_selfield_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to next element in the list
sv2ssim::FField*     zd_selfield_Next(sv2ssim::FField &row) __attribute__((__warn_unused_result__, nothrow));
// Return pointer to previous element in the list
sv2ssim::FField*     zd_selfield_Prev(sv2ssim::FField &row) __attribute__((__warn_unused_result__, nothrow));
// Remove element from index. If element is not in index, do nothing.
void                 zd_selfield_Remove(sv2ssim::FField& row) __attribute__((nothrow));
// Empty the index. (The rows are not deleted)
void                 zd_selfield_RemoveAll() __attribute__((nothrow));
// If linked list is empty, return NULL. Otherwise unlink and return pointer to first element.
sv2ssim::FField*     zd_selfield_RemoveFirst() __attribute__((nothrow));
// Return reference to last element in the index. No bounds checking.
sv2ssim::FField&     zd_selfield_qLast() __attribute__((__warn_unused_result__, nothrow));

// Allocate memory for new default row.
// If out of memory, process is killed.
sv2ssim::FBltin&     bltin_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
sv2ssim::FBltin*     bltin_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
sv2ssim::FBltin*     bltin_InsertMaybe(const amcdb::Bltin &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                bltin_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 bltin_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
sv2ssim::FBltin*     bltin_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
sv2ssim::FBltin*     bltin_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  bltin_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
void                 bltin_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 bltin_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
sv2ssim::FBltin&     bltin_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 bltin_XrefMaybe(sv2ssim::FBltin &row);

// Return true if hash is empty
bool                 ind_bltin_EmptyQ() __attribute__((nothrow));
// Find row by key. Return NULL if not found.
sv2ssim::FBltin*     ind_bltin_Find(const algo::strptr& key) __attribute__((__warn_unused_result__, nothrow));
// Look up row by key and return reference. Throw exception if not found
sv2ssim::FBltin&     ind_bltin_FindX(const algo::strptr& key);
// Find row by key. If not found, create and x-reference a new row with with this key.
sv2ssim::FBltin&     ind_bltin_GetOrCreate(const algo::strptr& key) __attribute__((nothrow));
// Return number of items in the hash
i32                  ind_bltin_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
bool                 ind_bltin_InsertMaybe(sv2ssim::FBltin& row) __attribute__((nothrow));
// Remove reference to element from hash index. If element is not in hash, do nothing
void                 ind_bltin_Remove(sv2ssim::FBltin& row) __attribute__((nothrow));
// Reserve enough room in the hash for N more elements. Return success code.
void                 ind_bltin_Reserve(int n) __attribute__((nothrow));

// cursor points to valid item
void                 _db_field_curs_Reset(_db_field_curs &curs, sv2ssim::FDb &parent);
// cursor points to valid item
bool                 _db_field_curs_ValidQ(_db_field_curs &curs);
// proceed to next item
void                 _db_field_curs_Next(_db_field_curs &curs);
// item access
sv2ssim::FField&     _db_field_curs_Access(_db_field_curs &curs);
// proceed to next item
void                 _db_linetok_curs_Next(_db_linetok_curs &curs);
void                 _db_linetok_curs_Reset(_db_linetok_curs &curs, sv2ssim::FDb &parent);
// cursor points to valid item
bool                 _db_linetok_curs_ValidQ(_db_linetok_curs &curs);
// item access
algo::cstring&       _db_linetok_curs_Access(_db_linetok_curs &curs);
// cursor points to valid item
void                 _db_svtype_curs_Reset(_db_svtype_curs &curs, sv2ssim::FDb &parent);
// cursor points to valid item
bool                 _db_svtype_curs_ValidQ(_db_svtype_curs &curs);
// proceed to next item
void                 _db_svtype_curs_Next(_db_svtype_curs &curs);
// item access
sv2ssim::FSvtype&    _db_svtype_curs_Access(_db_svtype_curs &curs);
// cursor points to valid item
void                 _db_zd_selfield_curs_Reset(_db_zd_selfield_curs &curs, sv2ssim::FDb &parent);
// cursor points to valid item
bool                 _db_zd_selfield_curs_ValidQ(_db_zd_selfield_curs &curs);
// proceed to next item
void                 _db_zd_selfield_curs_Next(_db_zd_selfield_curs &curs);
// item access
sv2ssim::FField&     _db_zd_selfield_curs_Access(_db_zd_selfield_curs &curs);
// cursor points to valid item
void                 _db_bltin_curs_Reset(_db_bltin_curs &curs, sv2ssim::FDb &parent);
// cursor points to valid item
bool                 _db_bltin_curs_ValidQ(_db_bltin_curs &curs);
// proceed to next item
void                 _db_bltin_curs_Next(_db_bltin_curs &curs);
// item access
sv2ssim::FBltin&     _db_bltin_curs_Access(_db_bltin_curs &curs);
// Set all fields to initial values.
void                 FDb_Init();
void                 FDb_Uninit() __attribute__((nothrow));

// --- sv2ssim.FField
// create: sv2ssim.FDb.field (Lary)
// global access: ind_field (Thash)
// global access: zd_selfield (Llist)
struct FField { // sv2ssim.FField
    sv2ssim::FField*   ind_field_next;     // hash next
    sv2ssim::FField*   zd_selfield_next;   // zslist link; -1 means not-in-list
    sv2ssim::FField*   zd_selfield_prev;   // previous element
    algo::cstring      name;               // Field name
    algo::Smallstr50   ctype;              // Determined type
    i32                maxwid;             //   0  Max field width in chars
    double             minval;             //   1e300  Min numeric value
    double             maxval;             //   -1e300  Max numeric value
    i32                minwid_fix1;        //   100000  Min digits before .
    i32                maxwid_fix1;        //   0  Max digits before .
    i32                minwid_fix2;        //   100000  Min digits after .
    i32                maxwid_fix2;        //   0  Max digits after .
    bool               couldbe_int;        //   true
    bool               couldbe_bool;       //   true
    bool               couldbe_fixwid;     //   true  Fixed width char
    bool               couldbe_double;     //   true
    i32                rowid;              //   0
private:
    friend sv2ssim::FField&     field_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend sv2ssim::FField*     field_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 field_RemoveAll() __attribute__((nothrow));
    friend void                 field_RemoveLast() __attribute__((nothrow));
    FField();
    ~FField();
    FField(const FField&){ /*disallow copy constructor */}
    void operator =(const FField&){ /*disallow direct assignment */}
};

// Set all fields to initial values.
void                 FField_Init(sv2ssim::FField& field);
bool                 FField_ReadFieldMaybe(sv2ssim::FField &parent, algo::strptr field, algo::strptr strval) __attribute__((nothrow));
// Read fields of sv2ssim::FField from an ascii string.
// The format of the string is an ssim Tuple
bool                 FField_ReadStrptrMaybe(sv2ssim::FField &parent, algo::strptr in_str);
void                 FField_Uninit(sv2ssim::FField& field) __attribute__((nothrow));
// print string representation of sv2ssim::FField to string LHS, no header -- cprint:sv2ssim.FField.String
void                 FField_Print(sv2ssim::FField & row, algo::cstring &str) __attribute__((nothrow));

// --- sv2ssim.FSvtype
// create: sv2ssim.FDb.svtype (Lary)
struct FSvtype { // sv2ssim.FSvtype
    algo::Smallstr50   ctype;       // Type to choose
    i32                maxwid;      //   0  Maximum width in chars of input field
    i32                fixedwid1;   //   0  Max chars before decimal point
    i32                fixedwid2;   //   0  Max chars after decimal point
    algo::Comment      comment;     //
private:
    friend sv2ssim::FSvtype&    svtype_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend sv2ssim::FSvtype*    svtype_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 svtype_RemoveAll() __attribute__((nothrow));
    friend void                 svtype_RemoveLast() __attribute__((nothrow));
    FSvtype();
};

// Copy fields out of row
void                 svtype_CopyOut(sv2ssim::FSvtype &row, dmmeta::Svtype &out) __attribute__((nothrow));
// Copy fields in to row
void                 svtype_CopyIn(sv2ssim::FSvtype &row, dmmeta::Svtype &in) __attribute__((nothrow));

// Set all fields to initial values.
void                 FSvtype_Init(sv2ssim::FSvtype& svtype);

// --- sv2ssim.FieldId
#pragma pack(push,1)
struct FieldId { // sv2ssim.FieldId: Field read helper
    i32   value;   //   -1
    inline operator sv2ssim_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(sv2ssim_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
sv2ssim_FieldIdEnum  value_GetEnum(const sv2ssim::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(sv2ssim::FieldId& parent, sv2ssim_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const sv2ssim::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const sv2ssim::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(sv2ssim::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(sv2ssim::FieldId& parent, algo::strptr rhs, sv2ssim_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(sv2ssim::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of sv2ssim::FieldId from an ascii string.
// The format of the string is the format of the sv2ssim::FieldId's only field
bool                 FieldId_ReadStrptrMaybe(sv2ssim::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 FieldId_Init(sv2ssim::FieldId& parent);
// print string representation of sv2ssim::FieldId to string LHS, no header -- cprint:sv2ssim.FieldId.String
void                 FieldId_Print(sv2ssim::FieldId & row, algo::cstring &str) __attribute__((nothrow));

// --- sv2ssim.TableId
struct TableId { // sv2ssim.TableId: Index of table in this namespace
    i32   value;   //   -1  index of table
    inline operator sv2ssim_TableIdEnum() const;
    explicit TableId(i32                            in_value);
    TableId(sv2ssim_TableIdEnum arg);
    TableId();
};

// Get value of field as enum type
sv2ssim_TableIdEnum  value_GetEnum(const sv2ssim::TableId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(sv2ssim::TableId& parent, sv2ssim_TableIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const sv2ssim::TableId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const sv2ssim::TableId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(sv2ssim::TableId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(sv2ssim::TableId& parent, algo::strptr rhs, sv2ssim_TableIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(sv2ssim::TableId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of sv2ssim::TableId from an ascii string.
// The format of the string is the format of the sv2ssim::TableId's only field
bool                 TableId_ReadStrptrMaybe(sv2ssim::TableId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 TableId_Init(sv2ssim::TableId& parent);
// print string representation of sv2ssim::TableId to string LHS, no header -- cprint:sv2ssim.TableId.String
void                 TableId_Print(sv2ssim::TableId & row, algo::cstring &str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace sv2ssim { // gen:ns_curstext

struct _db_field_curs {// cursor
    typedef sv2ssim::FField ChildType;
    sv2ssim::FDb *parent;
    i64 index;
    _db_field_curs(){ parent=NULL; index=0; }
};


struct _db_linetok_curs {// cursor
    typedef algo::cstring ChildType;
    algo::cstring* elems;
    int n_elems;
    int index;
    _db_linetok_curs() { elems=NULL; n_elems=0; index=0; }
};


struct _db_svtype_curs {// cursor
    typedef sv2ssim::FSvtype ChildType;
    sv2ssim::FDb *parent;
    i64 index;
    _db_svtype_curs(){ parent=NULL; index=0; }
};


struct _db_zd_selfield_curs {// fcurs:sv2ssim.FDb.zd_selfield/curs
    typedef sv2ssim::FField ChildType;
    sv2ssim::FField* row;
    _db_zd_selfield_curs() {
        row = NULL;
    }
};


struct _db_bltin_curs {// cursor
    typedef sv2ssim::FBltin ChildType;
    sv2ssim::FDb *parent;
    i64 index;
    _db_bltin_curs(){ parent=NULL; index=0; }
};

} // gen:ns_curstext
namespace sv2ssim { // gen:ns_func
} // gen:ns_func
int                  main(int argc, char **argv);
#if defined(WIN32)
int WINAPI           WinMain(HINSTANCE,HINSTANCE,LPSTR,int);
#endif
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const sv2ssim::trace &row);// cfmt:sv2ssim.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const sv2ssim::FField &row);// cfmt:sv2ssim.FField.String
inline algo::cstring &operator <<(algo::cstring &str, const sv2ssim::FieldId &row);// cfmt:sv2ssim.FieldId.String
inline algo::cstring &operator <<(algo::cstring &str, const sv2ssim::TableId &row);// cfmt:sv2ssim.TableId.String
}
