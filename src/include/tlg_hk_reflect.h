/* Havok types (Havok 2014.2, config/flags.base.txt) as their reflection sees
 * them. Each reflection TU registers a type info per class: a name, a scoped
 * name, a finish callback, a cleanup callback, the vtable and the size
 * (the monitor stream types by the static initializer at 0x3f0 into
 * 0x57af350, 0x57af3d0, ...; hkUuid and hkUuidObject by the one at 0x3ed0
 * into 0x57b7a50, 0x57b7ad0). Class and member names are the reflection's own
 * strings (0x14b2400 and 0x14b2b1f onward); a member's type is its
 * hkClassMember type byte, 0x21 being the entry "hkStringPtr" of the
 * type-name table at 0x14b30e4. */
#ifndef TLG_HK_REFLECT_H
#define TLG_HK_REFLECT_H

#include "tlg_types.h"

/* hkClass, the reflection's class record: name (char*, type 0x1d) at +0
 * and parent (pointer to hkClass, type 0x14) at +8, from its own member
 * table at 0x16a6b60; its constructor FUN_000041a0 stores the twelve
 * fields from +0 to +0x4c. */
struct hkClass {
    const char *name;
    const hkClass *parent;
};

/* hkClassMember, a 40-byte member record (member names from its own
 * reflection strings at 0x14b2cc0: name, class, enum, type, subtype,
 * cArraySize, flags, offset). The records read here: 0x168c1f0 onward
 * (colorName: type 0x21, offset 0) and 0x168c920 (hkUuid's data: type 0x08,
 * cArraySize 4). */
struct hkClassEnum;

struct hkClassMember {
    const char *name;
    const hkClass *structClass;   /* reflected as "class"; derived name */
    const hkClassEnum *enumClass; /* reflected as "enum"; derived name */
    u8 type;
    u8 subtype;
    s16 cArraySize;
    u16 flags;
    u16 offset;
};

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

/* Sets the string from (string, length): drops an owned copy, then stores a
 * new one (copied through the arena of the thread's block) or null; the
 * constructor at 0xe540 clears the pointer and tail-calls it. */
void FUN_0000e450(hkStringPtr *self, const char *string, int length); /* derived name */

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

/* hkUuid, 16 bytes: data, four 32-bit unsigned ints (type 0x08, array of
 * 4). Its finish constructor is out of line and empty (FUN_0000dbc0). */
struct hkUuid {
    u32 data[4];
};

void FUN_0000dbc0(hkUuid *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* hkUuidObject, 32 bytes and polymorphic: uuid (an hkUuid) at +0xc. Its
 * finish constructor is out of line (FUN_0000dc40: stores the vtable
 * 0x168d870). */
struct hkUuidObject;

void FUN_0000dc40(hkUuidObject *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* hkRefCountedProperties, 16 bytes: entries, an array (type 0x16) of
 * hkRefCountedProperties::Entry, at +0 (type info at 0x57b85d8, registered
 * by the initializer at 0xd390). Its finish constructor (FUN_0001c1e0,
 * empty) and destructor (FUN_0001c1f0, releases each entry) are out of
 * line. */
struct hkRefCountedProperties;

void FUN_0001c1e0(hkRefCountedProperties *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0001c1f0(hkRefCountedProperties *self);                                /* derived name */

/* hkSimpleLocalFrame, polymorphic (vtable 0x168d8f0, stored by its finish
 * callback 0x37f0): members from its record table at 0x168c7d0, transform
 * (type 0x12) at +0x10, children (array of pointers) at +0x50, parentFrame
 * (pointer) at +0x60, group (pointer) at +0x68, name (hkStringPtr) at +0x70.
 * FUN_0000df30 copies the transform out, FUN_0000e160 reads the child count
 * at +0x58. */
struct hkLocalFrame;
struct hkLocalFrameGroup;

class hkSimpleLocalFrame
{
  public:
    virtual ~hkSimpleLocalFrame();

    u8 unknown8[0x58];
    hkLocalFrame *parentFrame;
    hkLocalFrameGroup *group;
    hkStringPtr name;
};

/* Polymorphic classes whose finish constructors are out of line, each
 * storing the class's vtable (and clearing a few members): */
struct hkGeometry;                          /* FUN_00093c60, vtable 0x1692500 */
struct hkcdPlanarGeometryPolygonCollection; /* FUN_00095fb0, vtable 0x16a3680 */
struct hkcdShape;                           /* FUN_0001cf40, vtable 0x168f300 */
struct hkcdPlanarGeometry;                  /* FUN_0009a860, vtable 0x16a3700 */
struct hkcdPlanarCsgOperand;                /* FUN_0009c0a0, vtable 0x16a3740 */
struct hkcdPlanarGeometryPlanesCollection;  /* FUN_0009c400, vtable 0x16a3780 */
struct hkcdPlanarSolid;                     /* FUN_00095800, vtable 0x16a3640 */

void FUN_00093c60(hkGeometry *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00095fb0(hkcdPlanarGeometryPolygonCollection *self,
                  hkFinishLoadedObjectFlag flag);                             /* derived name */
void FUN_0001cf40(hkcdShape *self, hkFinishLoadedObjectFlag flag);            /* derived name */
void FUN_0009a860(hkcdPlanarGeometry *self, hkFinishLoadedObjectFlag flag);   /* derived name */
void FUN_0009c0a0(hkcdPlanarCsgOperand *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0009c400(hkcdPlanarGeometryPlanesCollection *self,
                  hkFinishLoadedObjectFlag flag);                        /* derived name */
void FUN_00095800(hkcdPlanarSolid *self, hkFinishLoadedObjectFlag flag); /* derived name */

#endif
