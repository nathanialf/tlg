/* Havok's monitor stream types (Havok 2014.2, config/flags.base.txt) as their
 * reflection sees them. The library TU at 0x2a0..0xa50 registers a type info
 * for each: a name, a scoped name, a finish callback, a cleanup callback, the
 * vtable and the size (stored by the static initializer at 0x3f0 into
 * 0x57af350, 0x57af3d0, ...). Class and member names are the reflection's own
 * strings (0x14b2400 onward); a member's type is its hkClassMember type byte,
 * 0x21 being the entry "hkStringPtr" of the type-name table at 0x14b30e4. */
#ifndef TLG_HK_MONITOR_H
#define TLG_HK_MONITOR_H

#include "tlg_types.h"

/* The flag a finish constructor takes, passed by value: the finish callback
 * forwards its int argument in it. derived name. */
struct hkFinishLoadedObjectFlag {
    s32 finishing; /* derived name */
};

/* A string pointer whose finish constructor (FUN_0000e5c0, empty) and
 * destructor (FUN_0000e5d0, frees the string when bit 0 of the pointer marks
 * it owned) are out of line. */
struct hkStringPtr {
    const char *stringAndFlag; /* derived name */
};

void FUN_0000e5c0(hkStringPtr *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0000e5d0(hkStringPtr *self);                                /* derived name */

/* The polymorphic table of color pairs; its vtable is 0x168c1b0 (its finish
 * callback FUN_000002c0 stores 0x168c1c0), its destructor the first slot. */
class hkMonitorStreamColorTable
{
  public:
    virtual ~hkMonitorStreamColorTable();
};

/* hkMonitorStreamColorTable::ColorPair, 16 bytes: colorName (hkStringPtr) at
 * +0, then color. */
struct hkMonitorStreamColorTableColorPair {
    hkStringPtr colorName;
};

/* hkMonitorStreamStringMap::StringMap: id (type 0x0a, 64-bit unsigned) at
 * +0 and string (hkStringPtr) at +8. Its finish constructor is out of line
 * (FUN_0000d520). */
struct hkMonitorStreamStringMapStringMap {
    u64 id;
    hkStringPtr string;
};

void FUN_0000d520(hkMonitorStreamStringMapStringMap *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */

/* hkMonitorStreamStringMap: map, an array (type 0x16) of StringMap, at +0.
 * Its finish constructor is out of line and empty (FUN_0000d500). */
struct hkMonitorStreamStringMap;

void FUN_0000d500(hkMonitorStreamStringMap *self, hkFinishLoadedObjectFlag flag); /* derived name */

#endif
