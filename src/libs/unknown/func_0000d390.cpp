/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkRefCountedProperties' type info
 * (0x57b85e8): construct the object in place from a loaded image through
 * its out-of-line finish constructor. */
static void finishLoadedObjecthkRefCountedProperties(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_0001c1e0(static_cast<hkRefCountedProperties *>(object), flag);
}

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x8d60. */
static void finishLoadedObjecthkRefCountedPropertiesEntry(void *object,
                                                          int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkRefCountedProperties::Entry(flag);
}

/* derived names: the cleanup callback of hkRefCountedProperties::Entry's
 * type info: destroy the entry in place, which releases its object's
 * reference. */
static void cleanupLoadedObjecthkRefCountedPropertiesEntry(void *object) /* derived name */
{
    static_cast<hkRefCountedProperties::Entry *>(object)->~Entry();
}

/* derived names: the cleanup callback of hkRefCountedProperties' type info
 * (0x57b85f0): destroy the object in place through its out-of-line
 * destructor. */
static void cleanupLoadedObjecthkRefCountedProperties(void *object) /* derived name */
{
    static_cast<hkRefCountedProperties *>(object)->~hkRefCountedProperties();
}

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
                           finishLoadedObjecthkRefCountedPropertiesEntry,
                           cleanupLoadedObjecthkRefCountedPropertiesEntry, 0,
                           sizeof(hkRefCountedProperties::Entry));
const hkClass D_57b8588("hkRefCountedProperties", 0, sizeof(hkRefCountedProperties), 0, 0,
                        D_168d810, 1, D_168d7c0, 1, 0, 0, 0, 1);
extern const hkTypeInfo D_57b85d8;
const hkTypeInfo D_57b85d8("hkRefCountedProperties", "!hkRefCountedProperties",
                           finishLoadedObjecthkRefCountedProperties,
                           cleanupLoadedObjecthkRefCountedProperties, 0,
                           sizeof(hkRefCountedProperties));
