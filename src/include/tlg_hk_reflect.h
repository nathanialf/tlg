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

#include "tlg_simd.h"
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
struct hkcdSimdTree;                        /* FUN_00021a20, vtable 0x1690d70 */
struct hkcdStaticAabbTree;                  /* FUN_00022700, vtable 0x1690df0 */
struct hkcdDynamicAabbTree;                 /* FUN_0009fc10, vtable 0x16a37c0 */
struct hkSkinnedRefMeshShape;               /* FUN_000aa660, vtable 0x16a38c0 */
struct hkMemoryMeshShape;                   /* FUN_0002a940, vtable 0x1692540 */
struct hkSkinBinding;                       /* FUN_000aa4f0, vtable 0x16a3860 */
class hkMemoryMeshMaterial;                 /* FUN_000accf0, vtable 0x16a3920 */
struct hkStorageSkinnedMeshShape;           /* FUN_000ae680, vtable 0x16a3b00 */
struct hkMemoryMeshVertexBuffer;            /* FUN_000274e0, vtable 0x16921b0 */
struct hknpDynamicCompoundShape;            /* FUN_000469a0, vtable 0x1697ef0 */
struct hknpMaskedShapeMaskWrapper;          /* FUN_00038230, vtable 0x1693bb0 */
class hknpMaskedShape;                      /* FUN_00037b90, vtable 0x1693a90 */

void FUN_00093c60(hkGeometry *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00095fb0(hkcdPlanarGeometryPolygonCollection *self,
                  hkFinishLoadedObjectFlag flag);                             /* derived name */
void FUN_0001cf40(hkcdShape *self, hkFinishLoadedObjectFlag flag);            /* derived name */
void FUN_0009a860(hkcdPlanarGeometry *self, hkFinishLoadedObjectFlag flag);   /* derived name */
void FUN_0009c0a0(hkcdPlanarCsgOperand *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0009c400(hkcdPlanarGeometryPlanesCollection *self,
                  hkFinishLoadedObjectFlag flag);                              /* derived name */
void FUN_00095800(hkcdPlanarSolid *self, hkFinishLoadedObjectFlag flag);       /* derived name */
void FUN_00021a20(hkcdSimdTree *self, hkFinishLoadedObjectFlag flag);          /* derived name */
void FUN_00022700(hkcdStaticAabbTree *self, hkFinishLoadedObjectFlag flag);    /* derived name */
void FUN_0009fc10(hkcdDynamicAabbTree *self, hkFinishLoadedObjectFlag flag);   /* derived name */
void FUN_000aa660(hkSkinnedRefMeshShape *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0002a940(hkMemoryMeshShape *self, hkFinishLoadedObjectFlag flag);     /* derived name */
void FUN_000aa4f0(hkSkinBinding *self, hkFinishLoadedObjectFlag flag);         /* derived name */
void FUN_000accf0(hkMemoryMeshMaterial *self, hkFinishLoadedObjectFlag flag);  /* derived name */
void FUN_000ae680(hkStorageSkinnedMeshShape *self,
                  hkFinishLoadedObjectFlag flag);                                 /* derived name */
void FUN_000274e0(hkMemoryMeshVertexBuffer *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_000469a0(hknpDynamicCompoundShape *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00038230(hknpMaskedShapeMaskWrapper *self,
                  hkFinishLoadedObjectFlag flag);                        /* derived name */
void FUN_00037b90(hknpMaskedShape *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* hknpCompressedMeshShapeData, polymorphic (type info 0x57be1f0, vtable
 * 0x1692b10): slot 0, the complete destructor FUN_00034b20, runs the
 * out-of-line FUN_00034b80, which restores the vtable. */
struct hknpCompressedMeshShapeData;

void FUN_00034b80(hknpCompressedMeshShapeData *self); /* derived name */

/* hkIndexedTransformSet, polymorphic (type info 0x57bd358, vtable 0x1691770
 * stored by its finish constructor FUN_000236e0): slot 0, the complete
 * destructor FUN_00023490, runs the out-of-line FUN_000234f0, which restores
 * the vtable and frees the arrays at +0x50 (16-byte elements), +0x40
 * (hkStringPtr) and below. */
struct hkIndexedTransformSet;

void FUN_000236e0(hkIndexedTransformSet *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_000234f0(hkIndexedTransformSet *self);                                /* derived name */

/* hkMultipleVertexBuffer, polymorphic (type info 0x57bcf70, size 0x158,
 * vtable 0x1692000 stored by its finish constructor FUN_00024fa0): slot 0,
 * the complete destructor FUN_00024b70, runs the out-of-line FUN_00024db0. */
struct hkMultipleVertexBuffer;

void FUN_00024fa0(hkMultipleVertexBuffer *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00024db0(hkMultipleVertexBuffer *self);                                /* derived name */

/* hkMemoryMeshBody, polymorphic, 0x80 bytes (type info 0x57bccf0, vtable
 * 0x1691610 stored by its finish constructor FUN_00023190): members from
 * its record table at 0x1691530, transform (type 0x11) at +0x10,
 * transformSet (pointer) at +0x50, shape (pointer to hkMeshShape) at +0x58,
 * vertexBuffers (array of pointers) at +0x60, name (hkStringPtr) at +0x70. */
struct hkMeshShape;

class hkMemoryMeshBody
{
  public:
    virtual ~hkMemoryMeshBody();

    hkMeshShape *FUN_000230d0() const; /* vtable slot 5; derived name */

    u8 unknown8[0x48];
    hkIndexedTransformSet *transformSet;
    hkMeshShape *shape;
};

void FUN_00023190(hkMemoryMeshBody *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* Classes without a vtable whose finish constructor or destructor is out of
 * line (type info: vtable 0): */

/* hkcdPlanarGeometryPrimitives::Plane (type info 0x57ba4e0, size 0x40): its
 * finish constructor runs only when finishing. */
struct hkcdPlanarGeometryPrimitivesPlane;

void FUN_00095aa0(hkcdPlanarGeometryPrimitivesPlane *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */

/* hkcdStaticPvs (type info 0x57ba5e0, size 0x70): its destructor frees the
 * arrays at +0x58 and +0x48 through the thread's heap allocator. */
struct hkcdStaticPvs;

void FUN_0001d9e0(hkcdStaticPvs *self); /* derived name */

/* hkcdStaticMeshTreeBase (type info 0x57bc360, size 0x70): an empty finish
 * constructor (one shared body) and an out-of-line destructor. */
struct hkcdStaticMeshTreeBase;

void FUN_000a9140(hkcdStaticMeshTreeBase *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00020700(hkcdStaticMeshTreeBase *self);                                /* derived name */

/* hknpCompressedMeshShapeTree (type info 0x57be2f0, size 0xa0) and the
 * hkcdStaticMeshTree instance it is built on (type info 0x57be570) register
 * one finish callback; the finish constructor is the shared empty body. */
struct hknpCompressedMeshShapeTree;

void FUN_000a9140(hknpCompressedMeshShapeTree *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */

/* hkSkinnedMeshShape::BoneSection (type info 0x57bdc18, size 0x10): an
 * empty finish constructor (one shared body). */
struct hkSkinnedMeshShapeBoneSection;

void FUN_000add70(hkSkinnedMeshShapeBoneSection *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */

/* hknpStaticCompoundShape, polymorphic, 0xc0 bytes (type info 0x57c2818,
 * parent hknpCompoundShape): its finish callback FUN_0006c310 runs the
 * finish constructor FUN_000385d0, which stores the vtable 0x1693f40, whose
 * slot 0 is the destructor at 0x386c0. */
class hknpStaticCompoundShape
{
  public:
    virtual ~hknpStaticCompoundShape();
};

/* hknpStaticCompoundShapeInternals, 0xc0 bytes (type info 0x57bde70, vtable
 * 0x1692840), reflected with hknpStaticCompoundShape as its parent and no
 * members of its own. */
class hknpStaticCompoundShapeInternals : public hknpStaticCompoundShape
{
  public:
    virtual ~hknpStaticCompoundShapeInternals();
};

/* hknpShapeSignals, a reflected struct (hkClass at 0x57c2478); at most 16
 * bytes, the member after it in hknpMaskedShape sitting at +0x60. */
struct hknpShapeSignals {
    u8 unknown0[0x10];
};

/* hknpMaskedShape, polymorphic, 0x70 bytes (type info 0x57bea28, vtable
 * 0x1693a90): members from its record table at 0x16936b0, mask (pointer)
 * at +0x38, maskWrapper (struct) at +0x40, mutationSignals (struct
 * hknpShapeSignals) at +0x50, maskSize (int) at +0x60. */
class hknpMaskedShape
{
  public:
    virtual ~hknpMaskedShape();

    hknpShapeSignals *FUN_00038120(); /* vtable slot 8; derived name */

    u8 unknown8[0x48];
    hknpShapeSignals mutationSignals;
    s32 maskSize;
};

/* hknpScaledConvexShape, polymorphic, 0x70 bytes (type info 0x57c0c48,
 * vtable 0x16a54a0, address point 0x16a54b0), reflected with
 * hknpScaledConvexShapeBase (0x60 bytes) as its parent and no members of its
 * own. Its finish constructor FUN_0016ce90 clears the two pointers of the 16
 * bytes at +0x60, which its destructor (0x16cf30) walks as a signal's slot
 * list; slot 8 returns their address as hknpMaskedShape's slot 8 returns its
 * mutation signals. */
class hknpScaledConvexShape
{
  public:
    virtual ~hknpScaledConvexShape();

    hknpShapeSignals *FUN_0016ced0(); /* vtable slot 8; derived name */

    u8 unknown8[0x58];
    hknpShapeSignals mutationSignals; /* derived name */
};

/* hknpShape, polymorphic (type info 0x57bf210, vtable 0x169ad20 stored by
 * its finish constructor FUN_0006fa90): its destructor, slot 0, is out of
 * line (0x6fb50: restores the vtable, releases the properties at +0x20). */
class hknpShape
{
  public:
    virtual ~hknpShape();
};

/* hknpDecoratorShape (type info 0x57bf020, vtable 0x16958d0 stored by its
 * finish constructor FUN_0003b0f0, which runs hknpShape's first): adds
 * nothing to destroy. */
class hknpDecoratorShape : public hknpShape
{
  public:
    virtual ~hknpDecoratorShape();
};

/* hknpFirstPersonGun, hknpBallGun and hknpMountedBallGun, each finish
 * constructor running its parent's first (FUN_00156620, FUN_00157e00,
 * FUN_00166900; type infos below). hknpBallGun's destructor is out of line
 * (0x157ef0: stores its vtable, address point 0x16a48e0, and releases what
 * it holds); hknpMountedBallGun adds nothing to destroy, its slot 0
 * (vtable address point 0x16a5290) jumps to it. */
class hknpFirstPersonGun
{
  public:
    virtual ~hknpFirstPersonGun();
};

class hknpBallGun : public hknpFirstPersonGun
{
  public:
    virtual ~hknpBallGun();
};

class hknpMountedBallGun : public hknpBallGun
{
  public:
    virtual ~hknpMountedBallGun();
};

/* hknp classes registered by the reflection TU at 0x38b10 onward, each with
 * an out-of-line finish constructor (type info, the vtable it stores): */
struct hknpMotionPropertiesLibrary; /* 0x57bf0a0; FUN_00036de0, vtable 0x1693770 */
struct hknpShapeMassProperties;     /* 0x57bf290; FUN_0006fa80, vtable 0x1693ef0 */
struct hknpPhysicsSceneData;        /* 0x57bf360; FUN_00046790, vtable 0x1697ea0 */
struct
    hknpCapsuleShape; /* 0x57bf490; FUN_000730d0 runs hknpConvexPolytopeShape's, vtable 0x169b260 */
struct hknpMotionProperties;   /* 0x57bf510, no vtable; the shared empty body FUN_000396a0 */
class hknpConvexPolytopeShape; /* 0x57bf760; FUN_001520b0, vtable 0x16a4460 */

void FUN_0003b0f0(hknpDecoratorShape *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00036de0(hknpMotionPropertiesLibrary *self,
                  hkFinishLoadedObjectFlag flag);                                /* derived name */
void FUN_0006fa90(hknpShape *self, hkFinishLoadedObjectFlag flag);               /* derived name */
void FUN_0006fa80(hknpShapeMassProperties *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00046790(hknpPhysicsSceneData *self, hkFinishLoadedObjectFlag flag);    /* derived name */
void FUN_000730d0(hknpCapsuleShape *self, hkFinishLoadedObjectFlag flag);        /* derived name */
void FUN_000396a0(hknpMotionProperties *self, hkFinishLoadedObjectFlag flag);    /* derived name */
void FUN_001520b0(hknpConvexPolytopeShape *self, hkFinishLoadedObjectFlag flag); /* derived name */
/* More hknp classes with an out-of-line finish constructor (type info, the
 * vtable it stores): */
struct hknpProjectileGun; /* 0x57bf7e0; FUN_001595c0 runs hknpFirstPersonGun's, vtable 0x16a4b30 */
struct hknpDummyShape;    /* 0x57bfd60; FUN_0003e170 runs hknpShape's, vtable 0x16967b0 */
class hknpFirstPersonGun; /* 0x57c0000; FUN_00156620, vtable 0x16a47e0 */
struct hknpPhysicsSystemData;         /* 0x57c0198; FUN_00165a80, vtable 0x16a5130 */
struct hknpDefaultBroadPhaseConfig;   /* 0x57c02e8; FUN_00154d90, vtable 0x16a45f0 */
struct hknpConstraintCollisionFilter; /* 0x57c0368; FUN_00159b40, vtable 0x16a4c20 */
struct
    hknpLodShape; /* 0x57c05b8; FUN_00068160 runs hknpShape's, stores 0x1697c80, then its own 0x1699c00 */
struct hknpWorldSnapshot; /* 0x57c0638; FUN_0015bf30, vtable 0x16a4d50 */
struct
    hknpTriangleShape; /* 0x57c0838; FUN_00078230 runs hknpConvexPolytopeShape's, vtable 0x169b670 */

void FUN_001595c0(hknpProjectileGun *self, hkFinishLoadedObjectFlag flag);     /* derived name */
void FUN_0003e170(hknpDummyShape *self, hkFinishLoadedObjectFlag flag);        /* derived name */
void FUN_00156620(hknpFirstPersonGun *self, hkFinishLoadedObjectFlag flag);    /* derived name */
void FUN_00165a80(hknpPhysicsSystemData *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00154d90(hknpDefaultBroadPhaseConfig *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00159b40(hknpConstraintCollisionFilter *self,
                  hkFinishLoadedObjectFlag flag);                          /* derived name */
void FUN_00068160(hknpLodShape *self, hkFinishLoadedObjectFlag flag);      /* derived name */
void FUN_0015bf30(hknpWorldSnapshot *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00078230(hknpTriangleShape *self, hkFinishLoadedObjectFlag flag); /* derived name */
class hknpMountedBallGun; /* 0x57c0ab8; FUN_00166900 runs FUN_00157e00, vtable 0x16a5280 */
class
    hknpScaledConvexShape; /* 0x57c0c48; FUN_0016ce90 runs hknpDecoratorShape's, vtable 0x16a54a0 */
struct
    hknpScaledConvexShapeBase; /* 0x57c0c78; FUN_0016a810 runs hknpDecoratorShape's, vtable 0x16a5390 */
struct hknpPairCollisionFilter; /* 0x57c1160; FUN_001673f0, vtable 0x16a52f0 */

void FUN_00166900(hknpMountedBallGun *self, hkFinishLoadedObjectFlag flag);    /* derived name */
void FUN_0016ce90(hknpScaledConvexShape *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0016a810(hknpScaledConvexShapeBase *self,
                  hkFinishLoadedObjectFlag flag);                                /* derived name */
void FUN_001673f0(hknpPairCollisionFilter *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* hkRelArray, the reflection's type 0x22 (the type-name table at 0x14b30e4):
 * an array stored after its owner, a 16-bit size and a 16-bit offset. */
template <typename T> class hkRelArray
{
  public:
    int getSize() const
    {
        return size;
    }

    u16 size;   /* derived name */
    u16 offset; /* derived name */
};

/* hknpConvexShape, 0x30 bytes (type info 0x57c1958, hkClass 0x57c1908 with
 * hknpShape as parent, vtable 0x1697d90 stored by its finish constructor
 * FUN_00042e90): one reflected member, vertices (hkRelArray of hkVector4,
 * subtype 12) at +0x28 (record 0x1699720). */
class hknpConvexShape : public hknpShape
{
  public:
    int FUN_00045ac0() const; /* vtable slot 9; derived name */

    u8 unknown8[0x20];
    hkRelArray<Vec4> vertices;
};

/* hknpConvexPolytopeShape (type info 0x57bf760, hkClass 0x57bf710 with
 * hknpConvexShape as parent, size 0x40): members from its record table at
 * 0x1694f80, planes (hkRelArray of hkVector4) at +0x2c, in hknpConvexShape's
 * tail padding, faces (hkRelArray of Face, class 0x57bf590) at +0x30,
 * indices (hkRelArray) at +0x34, connectivity (pointer) at +0x38. */
class hknpConvexPolytopeShape : public hknpConvexShape
{
  public:
    struct Face;

    int FUN_00072f70() const; /* vtable slot 13; derived name */

    hkRelArray<Vec4> planes;
    hkRelArray<Face> faces;
};
/* hknpWorldCinfo (type info 0x57c13e0, no vtable): an empty finish
 * constructor (the shared body FUN_0003b640) and an out-of-line destructor
 * FUN_0003b650, which releases the references from +0xb0 down. */
struct hknpWorldCinfo;

void FUN_0003b640(hknpWorldCinfo *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0003b650(hknpWorldCinfo *self);                                /* derived name */

struct
    hknpMalleableConstraintData; /* 0x57c18d8; FUN_00067960 runs FUN_0007d520, vtable 0x1699a90 */
struct hknpBodyQualityLibrary;   /* 0x57c1a78; FUN_00071190, vtable 0x169b150 */

void FUN_00067960(hknpMalleableConstraintData *self,
                  hkFinishLoadedObjectFlag flag);                               /* derived name */
void FUN_00042e90(hknpConvexShape *self, hkFinishLoadedObjectFlag flag);        /* derived name */
void FUN_00071190(hknpBodyQualityLibrary *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* hknpMaterial (type info 0x57c1f40, no vtable, cleanup 0x300) and
 * hknpMaterialDescriptor (type info 0x57c1fc0, no vtable, cleanup 0x66e80):
 * each finish constructor (FUN_0006c6f0, FUN_0006c800) runs hkStringPtr's on
 * the name at +0. */
struct hknpMaterial {
    hkStringPtr name; /* derived name */
};

struct hknpMaterialDescriptor {
    hkStringPtr name; /* derived name */
};

void FUN_0006c6f0(hknpMaterial *self, hkFinishLoadedObjectFlag flag);           /* derived name */
void FUN_0006c800(hknpMaterialDescriptor *self, hkFinishLoadedObjectFlag flag); /* derived name */
/* hknpRefMaterial (type info 0x57c2040): its finish constructor
 * FUN_0006c7e0 stores the vtable 0x169ac60 and runs hkStringPtr's on +0x10. */
struct hknpRefMaterial;
class hknpBallGun; /* 0x57c20c0; FUN_00157e00 runs hknpFirstPersonGun's, vtable 0x16a48d0 */
struct
    hknpCompressedHeightFieldShape; /* 0x57c2378; FUN_00175de0 runs hknpShape's, then vtable 0x16a5980 */
struct
    hknpBreakableConstraintData; /* 0x57c23f8; FUN_0003c240 runs FUN_0007d520, vtable 0x1695b10 */
struct hknpDestructionShapeProperties; /* 0x57c2648; FUN_00175a50, vtable 0x16a5940 */
struct
    hknpCompressedMeshShape; /* 0x57c26c8; FUN_00158610 runs hknpShape's, then vtable 0x16a4990 */
struct hknpSphereShape;      /* 0x57c2798; FUN_0003c540 runs hknpConvexShape's, vtable 0x1695c10 */

void FUN_0006c7e0(hknpRefMaterial *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00157e00(hknpBallGun *self, hkFinishLoadedObjectFlag flag);     /* derived name */
void FUN_00175de0(hknpCompressedHeightFieldShape *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0003c240(hknpBreakableConstraintData *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00175a50(hknpDestructionShapeProperties *self,
                  hkFinishLoadedObjectFlag flag);                                /* derived name */
void FUN_00158610(hknpCompressedMeshShape *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0003c540(hknpSphereShape *self, hkFinishLoadedObjectFlag flag);         /* derived name */
/* hknpStaticCompoundShape's finish constructor (see the class above). */
void FUN_000385d0(hknpStaticCompoundShape *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* hknpExternMeshShape (type info 0x57c28e8, size 0x70): its finish
 * constructor FUN_001660e0 runs hknpShape's, stores 0x1697c80, sets bit 2
 * of the byte at +0x10 when finishing, then stores its own vtable 0x16a5170. */
struct hknpExternMeshShape;

void FUN_001660e0(hknpExternMeshShape *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* Constraint data atoms (hkp, the constraint solver's reflection TUs from
 * 0x7ac40): each Atoms struct's finish constructor sets the int at +0x94
 * (-1, or a packed pair when finishing), and its finish callback runs it.
 * hkpLinearClearanceConstraintData::Atoms: type info 0x57c36b8, size 0x120,
 * FUN_00083880. hkpPrismaticConstraintData::Atoms: type info 0x57c4058,
 * size 0x100, FUN_0007e520. */
class hkpLinearClearanceConstraintData
{
  public:
    struct Atoms;
};

class hkpPrismaticConstraintData
{
  public:
    struct Atoms;
};

/* hkpLimitedHingeConstraintData::Atoms: type info 0x57c57f8, size 0x110,
 * FUN_00078df0 (also the u16 at +0xb4). hkpRagdollConstraintData::Atoms:
 * type info 0x57c5b48, size 0x180, FUN_0007dae0 (the int at +0xa4). */
class hkpLimitedHingeConstraintData
{
  public:
    struct Atoms;
};

class hkpRagdollConstraintData
{
  public:
    struct Atoms;
};

/* hkp6DofConstraintData, polymorphic (type info 0x57c5ac8, size 0x2b0): its
 * finish constructor FUN_0017b5f0 runs FUN_00082850 (the constraint data
 * base's), stores the vtable 0x16a5d20 and resets the packed u16 pairs of
 * its atoms. hkp6DofConstraintData::Blueprints (type info 0x57c5a48, size
 * 0x200): its finish constructor FUN_0017b0d0 resets the same pairs from
 * +0xb4. */
class hkp6DofConstraintData
{
  public:
    struct Blueprints;
};

void FUN_00083880(hkpLinearClearanceConstraintData::Atoms *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0007e520(hkpPrismaticConstraintData::Atoms *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00078df0(hkpLimitedHingeConstraintData::Atoms *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0007dae0(hkpRagdollConstraintData::Atoms *self,
                  hkFinishLoadedObjectFlag flag);                              /* derived name */
void FUN_0017b5f0(hkp6DofConstraintData *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0017b0d0(hkp6DofConstraintData::Blueprints *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */

/* hkx scene classes (the reflection TUs from 0x87e20), each with an
 * out-of-line finish constructor or destructor:
 * hkxVertexBuffer::VertexData (type info 0x57c6970, size 0x68, no vtable):
 * its destructor FUN_00087cf0 frees its arrays from +0x40 down.
 * hkxVertexBuffer, polymorphic (type info 0x57c69f0, size 0x88): its finish
 * constructor FUN_0008a1a0 stores the vtable 0x16a1a30 and runs
 * hkxVertexDescription's (FUN_0008c0a0, an empty body shared with twelve
 * vtable slots) on the member at +0x78.
 * hkxVertexDescription (type info 0x57c7f90, size 0x10, no vtable).
 * hkxVertexAnimation, polymorphic (type info 0x57c7e10, size 0xb8, vtable
 * 0x16a26d0 stored by its finish constructor 0x8cb10, which runs
 * hkxVertexBuffer's on the member at +0x10): slot 0, the complete
 * destructor FUN_0008c930, runs the out-of-line FUN_0008c990.
 * hkxMeshSection, polymorphic (type info 0x57c8200, size 0x70, vtable
 * 0x16a29e0 stored by its finish constructor 0x8e000): slot 0, the complete
 * destructor FUN_0008dbf0, runs the out-of-line FUN_0008dc50.
 * hkxAttribute (type info 0x57c7900, size 0x10, no vtable, cleanup 0x66e80):
 * its finish constructor FUN_0017d790 runs hkStringPtr's on +0.
 * hkxEnvironment (type info 0x57c8180, size 0x20): FUN_0017d6f0 stores the
 * vtable 0x16a6070.
 * hkRootLevelContainer::NamedVariant (type info 0x57c8400, size 0x18, no
 * vtable): FUN_0017dde0 runs hkStringPtr's on +0 and +8.
 * hkRootLevelContainer (type info 0x57c8480, size 0x10, no vtable): the
 * empty body FUN_0017de10 (shared with fourteen vtable slots).
 * hkMemoryResourceContainer (type info 0x57c85a0, size 0x40): FUN_0017fb60
 * stores the vtable 0x16a6300 and finishes the members from +0x10.
 * hkMemoryResourceHandle (type info 0x57c86a0, size 0x30): FUN_0017f110
 * stores the vtable 0x16a6270 and runs hkStringPtr's on +0x18.
 * hkxMesh (type info 0x57c6f90, size 0x30): FUN_0008bea0 stores the vtable
 * 0x16a25a0.
 * hkAlignSceneToNodeOptions (type info 0x57c7288, size 0x20): FUN_0017d520
 * stores the vtable 0x16a6030 and runs hkStringPtr's on +0x18.
 * hkxMaterialShaderSet (type info 0x57c7680, size 0x20): FUN_0008b370
 * stores the vtable 0x16a1f30.
 * hkxSkinBinding, polymorphic (type info 0x57c7500, size 0x80, vtable
 * 0x16a1cc0 stored by its finish constructor FUN_0008a9b0): slot 0, the
 * complete destructor FUN_0008a830, runs the out-of-line FUN_0008a890,
 * which restores the vtable and frees the arrays from +0x30 down. */
class hkxVertexBuffer
{
  public:
    struct VertexData;
};

struct hkxMesh;
struct hkAlignSceneToNodeOptions;
struct hkxMaterialShaderSet;
struct hkxSkinBinding;
struct hkxVertexDescription;
struct hkxVertexAnimation;
struct hkxMeshSection;

/* hkxAttribute's members from its record table at 0x16a23e0: name
 * (hkStringPtr) at +0, value at +8. */
struct hkxAttribute {
    hkStringPtr name;
};
struct hkxEnvironment;

class hkRootLevelContainer
{
  public:
    struct NamedVariant;
};
struct hkMemoryResourceContainer;
struct hkMemoryResourceHandle;

void FUN_0008c0a0(hkxVertexDescription *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0008c990(hkxVertexAnimation *self);                                  /* derived name */
void FUN_0008dc50(hkxMeshSection *self);                                      /* derived name */
void FUN_0017d790(hkxAttribute *self, hkFinishLoadedObjectFlag flag);         /* derived name */
void FUN_0017d6f0(hkxEnvironment *self, hkFinishLoadedObjectFlag flag);       /* derived name */
void FUN_0017dde0(hkRootLevelContainer::NamedVariant *self,
                  hkFinishLoadedObjectFlag flag);                             /* derived name */
void FUN_0017de10(hkRootLevelContainer *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0017fb60(hkMemoryResourceContainer *self,
                  hkFinishLoadedObjectFlag flag);                               /* derived name */
void FUN_0017f110(hkMemoryResourceHandle *self, hkFinishLoadedObjectFlag flag); /* derived name */

void FUN_00087cf0(hkxVertexBuffer::VertexData *self);                    /* derived name */
void FUN_0008a1a0(hkxVertexBuffer *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0008bea0(hkxMesh *self, hkFinishLoadedObjectFlag flag);         /* derived name */
void FUN_0017d520(hkAlignSceneToNodeOptions *self,
                  hkFinishLoadedObjectFlag flag);                             /* derived name */
void FUN_0008b370(hkxMaterialShaderSet *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0008a890(hkxSkinBinding *self);                                      /* derived name */
/* hkSkinBinding (vtable 0x16a3860): slot 0, the complete destructor
 * FUN_000aa370, runs the out-of-line FUN_000aa3d0, which restores the
 * vtable. hkStorageSkinnedMeshShape (vtable 0x16a3b00): slot 0, the
 * complete destructor FUN_000ad910, runs the out-of-line FUN_000adba0. */
void FUN_000aa3d0(hkSkinBinding *self);             /* derived name */
void FUN_000adba0(hkStorageSkinnedMeshShape *self); /* derived name */

/* hkEnum, the reflection's type 0x18: an enum kept in a smaller integer
 * (the record's subtype, 3 for hkInt8), converted on read and write. */
template <typename ENUM, typename STORAGE> class hkEnum
{
  public:
    operator ENUM() const
    {
        return static_cast<ENUM>(m_storage);
    }

    hkEnum &operator=(ENUM e)
    {
        m_storage = static_cast<STORAGE>(e);
        return *this;
    }

    STORAGE m_storage;
};

/* hkUlong, the reflection's type 0x1e: an unsigned integer as wide as a
 * pointer. */
typedef unsigned long hkUlong;

/* hkMemoryMeshMaterial, 0x80 bytes (type info 0x57bd4a8, vtable 0x16a3920 stored
 * by its finish constructor FUN_000accf0): members from its record table
 * at 0x1691e80, materialName (hkStringPtr) at +0x10, textures (array of
 * pointers to hkMeshTexture, hkClass 0x57bc990) at +0x18, diffuseColor,
 * ambientColor, specularColor and emissiveColor (hkVector4) from +0x30,
 * userData (hkUlong) at +0x70, tesselationFactor (hkReal) at +0x78. */
class hkMemoryMeshMaterial
{
  public:
    virtual ~hkMemoryMeshMaterial();

    hkUlong FUN_000acae0() const;           /* vtable slot 17; derived name */
    void FUN_000acaf0(hkUlong newUserData); /* vtable slot 18; derived name */

    u8 unknown8[8];
    hkStringPtr materialName;
    u8 textures[0x10];
    Vec4 diffuseColor;
    Vec4 ambientColor;
    Vec4 specularColor;
    Vec4 emissiveColor;
    hkUlong userData;
    float tesselationFactor;
};

/* hkMeshTexture (hkClass 0x57bc990), the texture interface, with its three
 * reflected enums (item tables at 0x1690ea0, 0x1690f00, 0x1690f30). */
class hkMeshTexture
{
  public:
    enum Format { Unknown, PNG, TGA, BMP, DDS, RAW };

    enum FilterMode { POINT, LINEAR, ANISOTROPIC };

    enum TextureUsageType {
        UNKNOWN,
        DIFFUSE,
        REFLECTION,
        BUMP,
        NORMAL,
        DISPLACEMENT,
        SPECULAR,
        SPECULARANDGLOSS,
        OPACITY,
        EMISSIVE,
        REFRACTION,
        GLOSS,
        DOMINANTS,
        NOTEXPORTED
    };

    virtual ~hkMeshTexture();
};

/* hkMemoryMeshTexture, 0x30 bytes (type info 0x57bd648, parent
 * hkMeshTexture, vtable 0x16a39f0 stored by its finish constructor
 * 0x24800): members from the records its static initializer builds
 * (0x24850 onward), filename (hkStringPtr) at +0x10, data (array of hkUint8)
 * at +0x18, format (hkEnum of Format in hkInt8) at +0x28, hasMipMaps (hkBool)
 * at +0x29, filterMode at +0x2a and usageHint at +0x2b (hkEnum in hkInt8),
 * textureCoordChannel (hkInt32) at +0x2c. Slots 8 to 18 of its vtable read
 * and write them. */
class hkMemoryMeshTexture : public hkMeshTexture
{
  public:
    virtual ~hkMemoryMeshTexture();

    Format FUN_000ad6e0() const;                      /* vtable slot 8; derived name */
    void FUN_000ad720(bool newHasMipMaps);            /* vtable slot 12; derived name */
    FilterMode FUN_000ad730() const;                  /* vtable slot 13; derived name */
    void FUN_000ad740(FilterMode newFilterMode);      /* vtable slot 14; derived name */
    TextureUsageType FUN_000ad750() const;            /* vtable slot 15; derived name */
    void FUN_000ad760(TextureUsageType newUsageHint); /* vtable slot 16; derived name */
    int FUN_000ad770() const;                         /* vtable slot 17; derived name */
    void FUN_000ad780(int newTextureCoordChannel);    /* vtable slot 18; derived name */

    u8 unknown8[8];
    hkStringPtr filename;
    u8 data[0x10];
    hkEnum<Format, s8> format;
    bool hasMipMaps;
    hkEnum<FilterMode, s8> filterMode;
    hkEnum<TextureUsageType, s8> usageHint;
    s32 textureCoordChannel;
};
#endif
