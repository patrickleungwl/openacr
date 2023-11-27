//
// include/gen/ssimfilt_gen.h
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

// --- ssimfilt_FieldIdEnum

enum ssimfilt_FieldIdEnum {        // ssimfilt.FieldId.value
     ssimfilt_FieldId_value   = 0
};

enum { ssimfilt_FieldIdEnum_N = 1 };

namespace ssimfilt { // gen:ns_pkeytypedef
} // gen:ns_pkeytypedef
namespace ssimfilt { // gen:ns_field
extern const char *ssimfilt_help;
} // gen:ns_field
// gen:ns_fwddecl2
namespace ssimfilt { struct _db_tuple_curs; }
namespace ssimfilt { struct _db_matchfield_curs; }
namespace ssimfilt { struct _db_selfield_curs; }
namespace ssimfilt { struct trace; }
namespace ssimfilt { struct FDb; }
namespace ssimfilt { struct FieldId; }
namespace ssimfilt { struct KVRegx; }
namespace ssimfilt { extern struct ssimfilt::FDb _db; }
namespace ssimfilt { // gen:ns_print_struct

// --- ssimfilt.trace
#pragma pack(push,1)
struct trace { // ssimfilt.trace
    trace();
};
#pragma pack(pop)

// print string representation of ssimfilt::trace to string LHS, no header -- cprint:ssimfilt.trace.String
void                 trace_Print(ssimfilt::trace & row, algo::cstring &str) __attribute__((nothrow));

// --- ssimfilt.FDb
// create: ssimfilt.FDb._db (Global)
struct FDb { // ssimfilt.FDb
    command::ssimfilt   cmdline;               //
    algo::Tuple*        tuple_lary[32];        // level array
    i32                 tuple_n;               // number of elements in array
    ssimfilt::KVRegx*   matchfield_lary[32];   // level array
    i32                 matchfield_n;          // number of elements in array
    ssimfilt::KVRegx*   selfield_lary[32];     // level array
    i32                 selfield_n;            // number of elements in array
    bool                csv_locked;            //   false  CSV header locked
    ssimfilt::trace     trace;                 //
};

// Read argc,argv directly into the fields of the command line(s)
// The following fields are updated:
//     ssimfilt.FDb.cmdline
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
algo::Tuple&         tuple_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
algo::Tuple*         tuple_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                tuple_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 tuple_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
algo::Tuple*         tuple_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
algo::Tuple*         tuple_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  tuple_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
void                 tuple_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 tuple_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
algo::Tuple&         tuple_qFind(u64 t) __attribute__((nothrow, pure));

// Allocate memory for new default row.
// If out of memory, process is killed.
ssimfilt::KVRegx&    matchfield_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
ssimfilt::KVRegx*    matchfield_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                matchfield_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 matchfield_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
ssimfilt::KVRegx*    matchfield_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
ssimfilt::KVRegx*    matchfield_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  matchfield_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
void                 matchfield_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 matchfield_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
ssimfilt::KVRegx&    matchfield_qFind(u64 t) __attribute__((nothrow, pure));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool                 matchfield_XrefMaybe(ssimfilt::KVRegx &row);

// Allocate memory for new default row.
// If out of memory, process is killed.
ssimfilt::KVRegx&    selfield_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
ssimfilt::KVRegx*    selfield_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                selfield_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 selfield_EmptyQ() __attribute__((nothrow, pure));
// Look up row by row id. Return NULL if out of range
ssimfilt::KVRegx*    selfield_Find(u64 t) __attribute__((__warn_unused_result__, nothrow, pure));
// Return pointer to last element of array, or NULL if array is empty
ssimfilt::KVRegx*    selfield_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  selfield_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
void                 selfield_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 selfield_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
ssimfilt::KVRegx&    selfield_qFind(u64 t) __attribute__((nothrow, pure));

// cursor points to valid item
void                 _db_tuple_curs_Reset(_db_tuple_curs &curs, ssimfilt::FDb &parent);
// cursor points to valid item
bool                 _db_tuple_curs_ValidQ(_db_tuple_curs &curs);
// proceed to next item
void                 _db_tuple_curs_Next(_db_tuple_curs &curs);
// item access
algo::Tuple&         _db_tuple_curs_Access(_db_tuple_curs &curs);
// cursor points to valid item
void                 _db_matchfield_curs_Reset(_db_matchfield_curs &curs, ssimfilt::FDb &parent);
// cursor points to valid item
bool                 _db_matchfield_curs_ValidQ(_db_matchfield_curs &curs);
// proceed to next item
void                 _db_matchfield_curs_Next(_db_matchfield_curs &curs);
// item access
ssimfilt::KVRegx&    _db_matchfield_curs_Access(_db_matchfield_curs &curs);
// cursor points to valid item
void                 _db_selfield_curs_Reset(_db_selfield_curs &curs, ssimfilt::FDb &parent);
// cursor points to valid item
bool                 _db_selfield_curs_ValidQ(_db_selfield_curs &curs);
// proceed to next item
void                 _db_selfield_curs_Next(_db_selfield_curs &curs);
// item access
ssimfilt::KVRegx&    _db_selfield_curs_Access(_db_selfield_curs &curs);
// Set all fields to initial values.
void                 FDb_Init();
void                 FDb_Uninit() __attribute__((nothrow));

// --- ssimfilt.FieldId
#pragma pack(push,1)
struct FieldId { // ssimfilt.FieldId: Field read helper
    i32   value;   //   -1
    inline operator ssimfilt_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(ssimfilt_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
ssimfilt_FieldIdEnum value_GetEnum(const ssimfilt::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(ssimfilt::FieldId& parent, ssimfilt_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const ssimfilt::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const ssimfilt::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(ssimfilt::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(ssimfilt::FieldId& parent, algo::strptr rhs, ssimfilt_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(ssimfilt::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of ssimfilt::FieldId from an ascii string.
// The format of the string is the format of the ssimfilt::FieldId's only field
bool                 FieldId_ReadStrptrMaybe(ssimfilt::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 FieldId_Init(ssimfilt::FieldId& parent);
// print string representation of ssimfilt::FieldId to string LHS, no header -- cprint:ssimfilt.FieldId.String
void                 FieldId_Print(ssimfilt::FieldId & row, algo::cstring &str) __attribute__((nothrow));

// --- ssimfilt.KVRegx
// create: ssimfilt.FDb.matchfield (Lary)
// create: ssimfilt.FDb.selfield (Lary)
struct KVRegx { // ssimfilt.KVRegx: Filters that must match input key/value pairs
    algo_lib::Regx   key;     // Sql Regx
    algo_lib::Regx   value;   // Sql Regx
private:
    friend ssimfilt::KVRegx&    matchfield_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend ssimfilt::KVRegx*    matchfield_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 matchfield_RemoveAll() __attribute__((nothrow));
    friend void                 matchfield_RemoveLast() __attribute__((nothrow));
    friend ssimfilt::KVRegx&    selfield_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend ssimfilt::KVRegx*    selfield_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 selfield_RemoveAll() __attribute__((nothrow));
    friend void                 selfield_RemoveLast() __attribute__((nothrow));
    KVRegx();
    // reftype Regx of ssimfilt.KVRegx.key prohibits copy
    // reftype Regx of ssimfilt.KVRegx.value prohibits copy
    KVRegx(const KVRegx&){ /*disallow copy constructor */}
    void operator =(const KVRegx&){ /*disallow direct assignment */}
};

// Print back to string
void                 key_Print(ssimfilt::KVRegx& matchfield, algo::cstring &out) __attribute__((nothrow));

// Print back to string
void                 value_Print(ssimfilt::KVRegx& matchfield, algo::cstring &out) __attribute__((nothrow));

} // gen:ns_print_struct
namespace ssimfilt { // gen:ns_curstext

struct _db_tuple_curs {// cursor
    typedef algo::Tuple ChildType;
    ssimfilt::FDb *parent;
    i64 index;
    _db_tuple_curs(){ parent=NULL; index=0; }
};


struct _db_matchfield_curs {// cursor
    typedef ssimfilt::KVRegx ChildType;
    ssimfilt::FDb *parent;
    i64 index;
    _db_matchfield_curs(){ parent=NULL; index=0; }
};


struct _db_selfield_curs {// cursor
    typedef ssimfilt::KVRegx ChildType;
    ssimfilt::FDb *parent;
    i64 index;
    _db_selfield_curs(){ parent=NULL; index=0; }
};

} // gen:ns_curstext
namespace ssimfilt { // gen:ns_func
} // gen:ns_func
int                  main(int argc, char **argv);
#if defined(WIN32)
int WINAPI           WinMain(HINSTANCE,HINSTANCE,LPSTR,int);
#endif
// gen:ns_operators
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const ssimfilt::trace &row);// cfmt:ssimfilt.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const ssimfilt::FieldId &row);// cfmt:ssimfilt.FieldId.String
}
