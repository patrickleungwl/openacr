//
// include/gen/src_lim_gen.h
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
#include "include/gen/dev_gen.h"
#include "include/gen/algo_gen.h"
#include "include/gen/algo_lib_gen.h"
#include "include/gen/command_gen.h"
//#pragma endinclude
// gen:ns_enums

// --- src_lim_FieldIdEnum

enum src_lim_FieldIdEnum {        // src_lim.FieldId.value
     src_lim_FieldId_value   = 0
};

enum { src_lim_FieldIdEnum_N = 1 };


// --- src_lim_TableIdEnum

enum src_lim_TableIdEnum {               // src_lim.TableId.value
     src_lim_TableId_dev_Badline   = 0   // dev.Badline -> src_lim.FBadline
    ,src_lim_TableId_dev_badline   = 0   // dev.badline -> src_lim.FBadline
    ,src_lim_TableId_dev_Gitfile   = 1   // dev.Gitfile -> src_lim.FGitfile
    ,src_lim_TableId_dev_gitfile   = 1   // dev.gitfile -> src_lim.FGitfile
    ,src_lim_TableId_dev_Include   = 2   // dev.Include -> src_lim.FInclude
    ,src_lim_TableId_dev_include   = 2   // dev.include -> src_lim.FInclude
    ,src_lim_TableId_dev_Linelim   = 3   // dev.Linelim -> src_lim.FLinelim
    ,src_lim_TableId_dev_linelim   = 3   // dev.linelim -> src_lim.FLinelim
    ,src_lim_TableId_dev_Targsrc   = 4   // dev.Targsrc -> src_lim.FTargsrc
    ,src_lim_TableId_dev_targsrc   = 4   // dev.targsrc -> src_lim.FTargsrc
};

enum { src_lim_TableIdEnum_N = 10 };

namespace src_lim { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace src_lim { // gen:ns_field
extern const char *src_lim_help;
} // gen:ns_field
// gen:ns_fwddecl2
namespace src_lim { struct FGitfile; }
namespace src_lim { struct _db_include_curs; }
namespace src_lim { struct _db_linelim_curs; }
namespace src_lim { struct _db_targsrc_curs; }
namespace src_lim { struct _db_gitfile_curs; }
namespace src_lim { struct _db_badline_curs; }
namespace src_lim { struct gitfile_zd_include_curs; }
namespace src_lim { struct FBadline; }
namespace src_lim { struct trace; }
namespace src_lim { struct FDb; }
namespace src_lim { struct FInclude; }
namespace src_lim { struct FLinelim; }
namespace src_lim { struct FTargsrc; }
namespace src_lim { struct FieldId; }
namespace src_lim { struct TableId; }
namespace src_lim { extern struct src_lim::FDb _db; }
namespace src_lim { // gen:ns_print_struct

// --- src_lim.FBadline
// create: src_lim.FDb.badline (Lary)
struct FBadline { // src_lim.FBadline
    algo::Smallstr50    badline;         //
    algo::Smallstr200   expr;            //
    algo::Smallstr50    targsrc_regx;    //
    algo::Comment       comment;         //
    algo_lib::Regx      regx;            //
    algo_lib::Regx      _targsrc_regx;   //
    bool                select;          //   false
private:
    friend src_lim::FBadline&   badline_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend src_lim::FBadline*   badline_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 badline_RemoveAll() __attribute__((nothrow));
    friend void                 badline_RemoveLast() __attribute__((nothrow));
    FBadline();
    // value field src_lim.FBadline.regx is not copiable
    // value field src_lim.FBadline._targsrc_regx is not copiable
    FBadline(const FBadline&){ /*disallow copy constructor */}
    void operator =(const FBadline&){ /*disallow direct assignment */}
};

// Copy fields out of row
void                 badline_CopyOut(src_lim::FBadline &row, dev::Badline &out) __attribute__((nothrow));
// Copy fields in to row
void                 badline_CopyIn(src_lim::FBadline &row, dev::Badline &in) __attribute__((nothrow));

// Set all fields to initial values.
void                 FBadline_Init(src_lim::FBadline& badline);

// --- src_lim.trace
#pragma pack(push,1)
struct trace { // src_lim.trace
    trace();
};
#pragma pack(pop)

// print string representation of src_lim::trace to string LHS, no header -- cprint:src_lim.trace.String
void                 trace_Print(src_lim::trace & row, algo::cstring &str) __attribute__((nothrow));

// --- src_lim.FDb
// create: src_lim.FDb._db (Global)
struct FDb { // src_lim.FDb
    src_lim::FInclude*    include_lary[32];            // level array
    i32                   include_n;                   // number of elements in array
    src_lim::FLinelim*    linelim_lary[32];            // level array
    i32                   linelim_n;                   // number of elements in array
    command::src_lim      cmdline;                     //
    src_lim::FTargsrc*    targsrc_lary[32];            // level array
    i32                   targsrc_n;                   // number of elements in array
    src_lim::FGitfile*    gitfile_lary[32];            // level array
    i32                   gitfile_n;                   // number of elements in array
    src_lim::FGitfile**   ind_gitfile_buckets_elems;   // pointer to bucket array
    i32                   ind_gitfile_buckets_n;       // number of elements in bucket array
    i32                   ind_gitfile_n;               // number of elements in the hash table
    algo::cstring         outtext;                     //
    src_lim::FBadline*    badline_lary[32];            // level array
    i32                   badline_n;                   // number of elements in array
    src_lim::trace        trace;                       //
};

// Allocate memory for new default row.
// If out of memory, process is killed.
src_lim::FInclude&   include_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
src_lim::FInclude*   include_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
src_lim::FInclude*   include_InsertMaybe(const dev::Include &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                include_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 include_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
src_lim::FInclude*   include_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
src_lim::FInclude*   include_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  include_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Delete last element of array. Do nothing if array is empty.
void                 include_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
src_lim::FInclude&   include_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 include_XrefMaybe(src_lim::FInclude &row);

// Allocate memory for new default row.
// If out of memory, process is killed.
src_lim::FLinelim&   linelim_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
src_lim::FLinelim*   linelim_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
src_lim::FLinelim*   linelim_InsertMaybe(const dev::Linelim &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                linelim_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 linelim_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
src_lim::FLinelim*   linelim_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
src_lim::FLinelim*   linelim_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  linelim_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Delete last element of array. Do nothing if array is empty.
void                 linelim_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
src_lim::FLinelim&   linelim_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 linelim_XrefMaybe(src_lim::FLinelim &row);

// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     src_lim.FDb.cmdline
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
src_lim::FTargsrc&   targsrc_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
src_lim::FTargsrc*   targsrc_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
src_lim::FTargsrc*   targsrc_InsertMaybe(const dev::Targsrc &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                targsrc_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 targsrc_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
src_lim::FTargsrc*   targsrc_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
src_lim::FTargsrc*   targsrc_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  targsrc_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Delete last element of array. Do nothing if array is empty.
void                 targsrc_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
src_lim::FTargsrc&   targsrc_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 targsrc_XrefMaybe(src_lim::FTargsrc &row);

// Allocate memory for new default row.
// If out of memory, process is killed.
src_lim::FGitfile&   gitfile_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
src_lim::FGitfile*   gitfile_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
src_lim::FGitfile*   gitfile_InsertMaybe(const dev::Gitfile &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                gitfile_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 gitfile_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
src_lim::FGitfile*   gitfile_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
src_lim::FGitfile*   gitfile_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  gitfile_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Delete last element of array. Do nothing if array is empty.
void                 gitfile_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
src_lim::FGitfile&   gitfile_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 gitfile_XrefMaybe(src_lim::FGitfile &row);

// Return true if hash is empty
bool                 ind_gitfile_EmptyQ() __attribute__((nothrow));
// Find row by key. Return NULL if not found.
src_lim::FGitfile*   ind_gitfile_Find(const algo::strptr& key) __attribute__((__warn_unused_result__, nothrow));
// Look up row by key and return reference. Throw exception if not found
src_lim::FGitfile&   ind_gitfile_FindX(const algo::strptr& key);
// Find row by key. If not found, create and x-reference a new row with with this key.
src_lim::FGitfile&   ind_gitfile_GetOrCreate(const algo::strptr& key) __attribute__((nothrow));
// Return number of items in the hash
i32                  ind_gitfile_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
bool                 ind_gitfile_InsertMaybe(src_lim::FGitfile& row) __attribute__((nothrow));
// Remove reference to element from hash index. If element is not in hash, do nothing
void                 ind_gitfile_Remove(src_lim::FGitfile& row) __attribute__((nothrow));
// Reserve enough room in the hash for N more elements. Return success code.
void                 ind_gitfile_Reserve(int n) __attribute__((nothrow));

// Allocate memory for new default row.
// If out of memory, process is killed.
src_lim::FBadline&   badline_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
src_lim::FBadline*   badline_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
src_lim::FBadline*   badline_InsertMaybe(const dev::Badline &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                badline_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 badline_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
src_lim::FBadline*   badline_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
src_lim::FBadline*   badline_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  badline_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
void                 badline_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 badline_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
src_lim::FBadline&   badline_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 badline_XrefMaybe(src_lim::FBadline &row);

// cursor points to valid item
void                 _db_include_curs_Reset(_db_include_curs &curs, src_lim::FDb &parent);
// cursor points to valid item
bool                 _db_include_curs_ValidQ(_db_include_curs &curs);
// proceed to next item
void                 _db_include_curs_Next(_db_include_curs &curs);
// item access
src_lim::FInclude&   _db_include_curs_Access(_db_include_curs &curs);
// cursor points to valid item
void                 _db_linelim_curs_Reset(_db_linelim_curs &curs, src_lim::FDb &parent);
// cursor points to valid item
bool                 _db_linelim_curs_ValidQ(_db_linelim_curs &curs);
// proceed to next item
void                 _db_linelim_curs_Next(_db_linelim_curs &curs);
// item access
src_lim::FLinelim&   _db_linelim_curs_Access(_db_linelim_curs &curs);
// cursor points to valid item
void                 _db_targsrc_curs_Reset(_db_targsrc_curs &curs, src_lim::FDb &parent);
// cursor points to valid item
bool                 _db_targsrc_curs_ValidQ(_db_targsrc_curs &curs);
// proceed to next item
void                 _db_targsrc_curs_Next(_db_targsrc_curs &curs);
// item access
src_lim::FTargsrc&   _db_targsrc_curs_Access(_db_targsrc_curs &curs);
// cursor points to valid item
void                 _db_gitfile_curs_Reset(_db_gitfile_curs &curs, src_lim::FDb &parent);
// cursor points to valid item
bool                 _db_gitfile_curs_ValidQ(_db_gitfile_curs &curs);
// proceed to next item
void                 _db_gitfile_curs_Next(_db_gitfile_curs &curs);
// item access
src_lim::FGitfile&   _db_gitfile_curs_Access(_db_gitfile_curs &curs);
// cursor points to valid item
void                 _db_badline_curs_Reset(_db_badline_curs &curs, src_lim::FDb &parent);
// cursor points to valid item
bool                 _db_badline_curs_ValidQ(_db_badline_curs &curs);
// proceed to next item
void                 _db_badline_curs_Next(_db_badline_curs &curs);
// item access
src_lim::FBadline&   _db_badline_curs_Access(_db_badline_curs &curs);
// Set all fields to initial values.
void                 FDb_Init();
void                 FDb_Uninit() __attribute__((nothrow));

// --- src_lim.FGitfile
// create: src_lim.FDb.gitfile (Lary)
// global access: ind_gitfile (Thash)
// access: src_lim.FTargsrc.p_gitfile (Upptr)
struct FGitfile { // src_lim.FGitfile
    src_lim::FGitfile*   ind_gitfile_next;   // hash next
    algo::Smallstr200    gitfile;            //
    src_lim::FInclude*   zd_include_head;    // zero-terminated doubly linked list
    i32                  zd_include_n;       // zero-terminated doubly linked list
    src_lim::FInclude*   zd_include_tail;    // pointer to last element
    src_lim::FLinelim*   c_linelim;          // optional pointer
    src_lim::FTargsrc*   c_targsrc;          // optional pointer
private:
    friend src_lim::FGitfile&   gitfile_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend src_lim::FGitfile*   gitfile_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 gitfile_RemoveLast() __attribute__((nothrow));
    FGitfile();
    ~FGitfile();
    FGitfile(const FGitfile&){ /*disallow copy constructor */}
    void operator =(const FGitfile&){ /*disallow direct assignment */}
};

// Copy fields out of row
void                 gitfile_CopyOut(src_lim::FGitfile &row, dev::Gitfile &out) __attribute__((nothrow));
// Copy fields in to row
void                 gitfile_CopyIn(src_lim::FGitfile &row, dev::Gitfile &in) __attribute__((nothrow));

algo::Smallstr50     ext_Get(src_lim::FGitfile& gitfile) __attribute__((__warn_unused_result__, nothrow));

// Return true if index is empty
bool                 zd_include_EmptyQ(src_lim::FGitfile& gitfile) __attribute__((__warn_unused_result__, nothrow, pure));
// If index empty, return NULL. Otherwise return pointer to first element in index
src_lim::FInclude*   zd_include_First(src_lim::FGitfile& gitfile) __attribute__((__warn_unused_result__, nothrow, pure));
// Return true if row is in the linked list, false otherwise
bool                 zd_include_InLlistQ(src_lim::FInclude& row) __attribute__((__warn_unused_result__, nothrow));
// Insert row into linked list. If row is already in linked list, do nothing.
void                 zd_include_Insert(src_lim::FGitfile& gitfile, src_lim::FInclude& row) __attribute__((nothrow));
// If index empty, return NULL. Otherwise return pointer to last element in index
src_lim::FInclude*   zd_include_Last(src_lim::FGitfile& gitfile) __attribute__((__warn_unused_result__, nothrow, pure));
// Return number of items in the linked list
i32                  zd_include_N(const src_lim::FGitfile& gitfile) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to next element in the list
src_lim::FInclude*   zd_include_Next(src_lim::FInclude &row) __attribute__((__warn_unused_result__, nothrow));
// Return pointer to previous element in the list
src_lim::FInclude*   zd_include_Prev(src_lim::FInclude &row) __attribute__((__warn_unused_result__, nothrow));
// Remove element from index. If element is not in index, do nothing.
void                 zd_include_Remove(src_lim::FGitfile& gitfile, src_lim::FInclude& row) __attribute__((nothrow));
// Empty the index. (The rows are not deleted)
void                 zd_include_RemoveAll(src_lim::FGitfile& gitfile) __attribute__((nothrow));
// If linked list is empty, return NULL. Otherwise unlink and return pointer to first element.
src_lim::FInclude*   zd_include_RemoveFirst(src_lim::FGitfile& gitfile) __attribute__((nothrow));
// Return reference to last element in the index. No bounds checking.
src_lim::FInclude&   zd_include_qLast(src_lim::FGitfile& gitfile) __attribute__((__warn_unused_result__, nothrow));

// Insert row into pointer index. Return final membership status.
bool                 c_linelim_InsertMaybe(src_lim::FGitfile& gitfile, src_lim::FLinelim& row) __attribute__((nothrow));
// Remove element from index. If element is not in index, do nothing.
void                 c_linelim_Remove(src_lim::FGitfile& gitfile, src_lim::FLinelim& row) __attribute__((nothrow));

// Insert row into pointer index. Return final membership status.
bool                 c_targsrc_InsertMaybe(src_lim::FGitfile& gitfile, src_lim::FTargsrc& row) __attribute__((nothrow));
// Remove element from index. If element is not in index, do nothing.
void                 c_targsrc_Remove(src_lim::FGitfile& gitfile, src_lim::FTargsrc& row) __attribute__((nothrow));

// Set all fields to initial values.
void                 FGitfile_Init(src_lim::FGitfile& gitfile);
// cursor points to valid item
void                 gitfile_zd_include_curs_Reset(gitfile_zd_include_curs &curs, src_lim::FGitfile &parent);
// cursor points to valid item
bool                 gitfile_zd_include_curs_ValidQ(gitfile_zd_include_curs &curs);
// proceed to next item
void                 gitfile_zd_include_curs_Next(gitfile_zd_include_curs &curs);
// item access
src_lim::FInclude&   gitfile_zd_include_curs_Access(gitfile_zd_include_curs &curs);
void                 FGitfile_Uninit(src_lim::FGitfile& gitfile) __attribute__((nothrow));

// --- src_lim.FInclude
// create: src_lim.FDb.include (Lary)
// access: src_lim.FGitfile.zd_include (Llist)
struct FInclude { // src_lim.FInclude
    src_lim::FInclude*   zd_include_next;   // zslist link; -1 means not-in-list
    src_lim::FInclude*   zd_include_prev;   // previous element
    algo::Smallstr200    include;           //
    bool                 sys;               //   false
    algo::Comment        comment;           //
private:
    friend src_lim::FInclude&   include_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend src_lim::FInclude*   include_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 include_RemoveLast() __attribute__((nothrow));
    FInclude();
    ~FInclude();
    FInclude(const FInclude&){ /*disallow copy constructor */}
    void operator =(const FInclude&){ /*disallow direct assignment */}
};

// Copy fields out of row
void                 include_CopyOut(src_lim::FInclude &row, dev::Include &out) __attribute__((nothrow));
// Copy fields in to row
void                 include_CopyIn(src_lim::FInclude &row, dev::Include &in) __attribute__((nothrow));

algo::Smallstr200    srcfile_Get(src_lim::FInclude& include) __attribute__((__warn_unused_result__, nothrow));

algo::Smallstr200    filename_Get(src_lim::FInclude& include) __attribute__((__warn_unused_result__, nothrow));

// Set all fields to initial values.
void                 FInclude_Init(src_lim::FInclude& include);
void                 FInclude_Uninit(src_lim::FInclude& include) __attribute__((nothrow));

// --- src_lim.FLinelim
// create: src_lim.FDb.linelim (Lary)
// access: src_lim.FGitfile.c_linelim (Ptr)
struct FLinelim { // src_lim.FLinelim
    algo::Smallstr200   gitfile;        //
    u32                 nlongline;      //   0
    u32                 longestline;    //   0
    u32                 nbadws;         //   0
    u32                 maxws;          //   0
    u32                 nlongfunc;      //   0
    u32                 longestfunc;    //   0
    u32                 nmysteryfunc;   //   0
    algo::Smallstr50    badness;        //
private:
    friend src_lim::FLinelim&   linelim_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend src_lim::FLinelim*   linelim_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 linelim_RemoveLast() __attribute__((nothrow));
    FLinelim();
    ~FLinelim();
    FLinelim(const FLinelim&){ /*disallow copy constructor */}
    void operator =(const FLinelim&){ /*disallow direct assignment */}
};

// Copy fields out of row
void                 linelim_CopyOut(src_lim::FLinelim &row, dev::Linelim &out) __attribute__((nothrow));
// Copy fields in to row
void                 linelim_CopyIn(src_lim::FLinelim &row, dev::Linelim &in) __attribute__((nothrow));

// Set all fields to initial values.
void                 FLinelim_Init(src_lim::FLinelim& linelim);
void                 FLinelim_Uninit(src_lim::FLinelim& linelim) __attribute__((nothrow));

// --- src_lim.FTargsrc
// create: src_lim.FDb.targsrc (Lary)
// access: src_lim.FGitfile.c_targsrc (Ptr)
struct FTargsrc { // src_lim.FTargsrc
    algo::Smallstr100    targsrc;     //
    algo::Comment        comment;     //
    src_lim::FGitfile*   p_gitfile;   // reference to parent row
    bool                 select;      //   false
private:
    friend src_lim::FTargsrc&   targsrc_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend src_lim::FTargsrc*   targsrc_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 targsrc_RemoveLast() __attribute__((nothrow));
    FTargsrc();
    ~FTargsrc();
    FTargsrc(const FTargsrc&){ /*disallow copy constructor */}
    void operator =(const FTargsrc&){ /*disallow direct assignment */}
};

// Copy fields out of row
void                 targsrc_CopyOut(src_lim::FTargsrc &row, dev::Targsrc &out) __attribute__((nothrow));
// Copy fields in to row
void                 targsrc_CopyIn(src_lim::FTargsrc &row, dev::Targsrc &in) __attribute__((nothrow));

algo::Smallstr16     target_Get(src_lim::FTargsrc& targsrc) __attribute__((__warn_unused_result__, nothrow));

algo::Smallstr200    src_Get(src_lim::FTargsrc& targsrc) __attribute__((__warn_unused_result__, nothrow));

algo::Smallstr10     ext_Get(src_lim::FTargsrc& targsrc) __attribute__((__warn_unused_result__, nothrow));

// Set all fields to initial values.
void                 FTargsrc_Init(src_lim::FTargsrc& targsrc);
void                 FTargsrc_Uninit(src_lim::FTargsrc& targsrc) __attribute__((nothrow));

// --- src_lim.FieldId
#pragma pack(push,1)
struct FieldId { // src_lim.FieldId: Field read helper
    i32   value;   //   -1
    inline operator src_lim_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(src_lim_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
src_lim_FieldIdEnum  value_GetEnum(const src_lim::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(src_lim::FieldId& parent, src_lim_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const src_lim::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const src_lim::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(src_lim::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(src_lim::FieldId& parent, algo::strptr rhs, src_lim_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(src_lim::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of src_lim::FieldId from an ascii string.
// The format of the string is the format of the src_lim::FieldId's only field
bool                 FieldId_ReadStrptrMaybe(src_lim::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 FieldId_Init(src_lim::FieldId& parent);
// print string representation of src_lim::FieldId to string LHS, no header -- cprint:src_lim.FieldId.String
void                 FieldId_Print(src_lim::FieldId & row, algo::cstring &str) __attribute__((nothrow));

// --- src_lim.TableId
struct TableId { // src_lim.TableId: Index of table in this namespace
    i32   value;   //   -1  index of table
    inline operator src_lim_TableIdEnum() const;
    explicit TableId(i32                            in_value);
    TableId(src_lim_TableIdEnum arg);
    TableId();
};

// Get value of field as enum type
src_lim_TableIdEnum  value_GetEnum(const src_lim::TableId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(src_lim::TableId& parent, src_lim_TableIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const src_lim::TableId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const src_lim::TableId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(src_lim::TableId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(src_lim::TableId& parent, algo::strptr rhs, src_lim_TableIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(src_lim::TableId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of src_lim::TableId from an ascii string.
// The format of the string is the format of the src_lim::TableId's only field
bool                 TableId_ReadStrptrMaybe(src_lim::TableId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 TableId_Init(src_lim::TableId& parent);
// print string representation of src_lim::TableId to string LHS, no header -- cprint:src_lim.TableId.String
void                 TableId_Print(src_lim::TableId & row, algo::cstring &str) __attribute__((nothrow));
} // gen:ns_print_struct
namespace src_lim { // gen:ns_curstext

struct _db_include_curs {// cursor
    typedef src_lim::FInclude ChildType;
    src_lim::FDb *parent;
    i64 index;
    _db_include_curs(){ parent=NULL; index=0; }
};


struct _db_linelim_curs {// cursor
    typedef src_lim::FLinelim ChildType;
    src_lim::FDb *parent;
    i64 index;
    _db_linelim_curs(){ parent=NULL; index=0; }
};


struct _db_targsrc_curs {// cursor
    typedef src_lim::FTargsrc ChildType;
    src_lim::FDb *parent;
    i64 index;
    _db_targsrc_curs(){ parent=NULL; index=0; }
};


struct _db_gitfile_curs {// cursor
    typedef src_lim::FGitfile ChildType;
    src_lim::FDb *parent;
    i64 index;
    _db_gitfile_curs(){ parent=NULL; index=0; }
};


struct _db_badline_curs {// cursor
    typedef src_lim::FBadline ChildType;
    src_lim::FDb *parent;
    i64 index;
    _db_badline_curs(){ parent=NULL; index=0; }
};


struct gitfile_zd_include_curs {// fcurs:src_lim.FGitfile.zd_include/curs
    typedef src_lim::FInclude ChildType;
    src_lim::FInclude* row;
    gitfile_zd_include_curs() {
        row = NULL;
    }
};

} // gen:ns_curstext
namespace src_lim { // gen:ns_func
} // gen:ns_func
int                  main(int argc, char **argv);
#if defined(WIN32)
int WINAPI           WinMain(HINSTANCE,HINSTANCE,LPSTR,int);
#endif
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const src_lim::trace &row);// cfmt:src_lim.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const src_lim::FieldId &row);// cfmt:src_lim.FieldId.String
inline algo::cstring &operator <<(algo::cstring &str, const src_lim::TableId &row);// cfmt:src_lim.TableId.String
}
