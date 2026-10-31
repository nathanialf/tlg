/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The entry's finish callback: nothing to finish (the linker folded it
 * into the empty body 0x8d60, AllocatorBase's destructor; D15's round 57
 * addendum). */
void FUN_00008d60(void *object, int finishing) {}

/* hkRefCountedProperties's finish and cleanup callbacks (func_0000d370.cpp,
 * func_0000d380.cpp). derived names. */
void FUN_0000d370(void *object, int finishing);
void FUN_0000d380(void *object);

extern const hkClassMember D_168d740[]; /* derived name: the entry's records */
extern const hkClassMember D_168d7c0[]; /* derived name: hkRefCountedProperties's record */
extern const hkClassEnum D_168d810[];   /* derived name: its one enum */

/* This file's static initializer (0xd390): hkRefCountedProperties::Entry's
 * reflection (no parent, its three members) and type info, then
 * hkRefCountedProperties's (its one enum and one member, version 1), neither
 * with a vtable. The type infos' names are the base's strings. */
const hkClass D_57b8508("hkRefCountedPropertiesEntry", 0, sizeof(hkRefCountedProperties::Entry), 0,
                        0, 0, 0, D_168d740, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57b8558;
const hkTypeInfo D_57b8558("hkRefCountedPropertiesEntry", "!hkRefCountedProperties::Entry",
                           FUN_00008d60, hkRefCountedProperties::Entry::FUN_0000d300, 0,
                           sizeof(hkRefCountedProperties::Entry));
const hkClass D_57b8588("hkRefCountedProperties", 0, sizeof(hkRefCountedProperties), 0, 0,
                        D_168d810, 1, D_168d7c0, 1, 0, 0, 0, 1);
extern const hkTypeInfo D_57b85d8;
const hkTypeInfo D_57b85d8("hkRefCountedProperties", "!hkRefCountedProperties", FUN_0000d370,
                           FUN_0000d380, 0, sizeof(hkRefCountedProperties));
