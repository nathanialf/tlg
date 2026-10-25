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

/* hkUlong, the reflection's type 0x1e: an unsigned integer as wide as a
 * pointer. */
typedef unsigned long hkUlong;

/* hkArray, the reflection's array type (its name in the type-name table at
 * 0x14b30e4): a data pointer, a size and a capacity whose top bits are
 * flags (0x80000000 when the array does not own its storage, as the
 * constructors store it; the capacity is masked with 0x3fffffff before a
 * grow). Field names derived. */
template <typename T> struct hkArray {
    T *data;              /* derived name */
    int size;             /* derived name */
    int capacityAndFlags; /* derived name */
};

/* hkBool, the reflection's boolean (its name in the type-name table at
 * 0x14b2fab): a char, read as a test against zero (`cmpb $0; setne`) and
 * written from a bool. A function returning one returns the byte built from
 * a bool (the widened compare: `shrl $31; xorb $1` for x >= 0 in
 * hkPs4StreamWriter's slot 5). Field name derived. */
class hkBool
{
  public:
    hkBool() {}

    hkBool(bool b)
    {
        value = static_cast<char>(b);
    }

    operator bool() const
    {
        return value != 0;
    }

    hkBool &operator=(bool b)
    {
        value = static_cast<char>(b);
        return *this;
    }

    char value; /* derived name */
};

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

/* hkBaseObject and hkReferencedObject (names from the reflection; the
 * hkClass of hkReferencedObject, 0x57b8640, is built at 0xe222, its one
 * member record at 0x168d980): the polymorphic root and the reference-counted object, whose
 * memSizeAndRefCount (hkUint32) at +8 holds the allocation size in the top
 * 16 bits (0xffff when unknown, the deleting destructors then free the
 * class's own size) and the reference count in the low 16 (constructors
 * store 0xffff0001). */
class hkBaseObject
{
  public:
    virtual ~hkBaseObject();
};

class hkReferencedObject : public hkBaseObject
{
  public:
    u32 memSizeAndRefCount;
};

/* A string pointer whose finish constructor (FUN_0000e5c0, empty) and
 * destructor (FUN_0000e5d0, frees the string when bit 0 of the pointer marks
 * it owned) are out of line. */
struct hkStringPtr {
    /* The string without the ownership bit. derived name. */
    const char *cString() const
    {
        return reinterpret_cast<const char *>(reinterpret_cast<hkUlong>(stringAndFlag) &
                                              ~static_cast<hkUlong>(1));
    }

    const char *stringAndFlag; /* derived name */
};

void FUN_0000e5c0(hkStringPtr *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0000e5d0(hkStringPtr *self);                                /* derived name */

/* The default constructor: a null string (called on each new element by the
 * array growers at 0xc93b to 0xcb23, and by 0x3a575, 0x6c66c, 0x17f386). */
void FUN_0000e3d0(hkStringPtr *self); /* derived name */

/* Sets the string from (string, length): drops an owned copy, then stores a
 * new one (copied through the arena of the thread's block) or null; the
 * constructor at 0xe540 clears the pointer and tail-calls it. */
void FUN_0000e450(hkStringPtr *self, const char *string, int length); /* derived name */

/* Assigns a C string: unless it is the one held, drops an owned copy and
 * stores an owned copy of the new one (or null); returns the pointer. */
hkStringPtr *FUN_0000e620(hkStringPtr *self, const char *string); /* derived name */

/* A polymorphic class (vtable address point 0x168d8f0, complete destructor
 * 0xde20) with its name (hkStringPtr, freed by the destructor) at +0x70 and
 * two reference-counted objects at +0x50 and +0x68 the destructor releases.
 * Slot 9 (FUN_0000dcb0) returns the name; the body is also slot 20 of
 * hkMemoryMeshBody, whose name sits at the same offset. */
class Class168d8f0 /* derived name */
{
  public:
    virtual ~Class168d8f0();

    const char *FUN_0000dcb0() const; /* vtable slot 9; derived name */

    u8 unknown8[0x68];
    hkStringPtr name; /* derived name */
};

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
class hkGeometry;                           /* FUN_00093c60, vtable 0x1692500 */
struct hkcdPlanarGeometryPolygonCollection; /* FUN_00095fb0, vtable 0x16a3680 */
struct hkcdShape;                           /* FUN_0001cf40, vtable 0x168f300 */
struct hkcdPlanarGeometry;                  /* FUN_0009a860, vtable 0x16a3700 */
struct hkcdPlanarCsgOperand;                /* FUN_0009c0a0, vtable 0x16a3740 */
struct hkcdPlanarGeometryPlanesCollection;  /* FUN_0009c400, vtable 0x16a3780 */
struct hkcdPlanarSolid;                     /* FUN_00095800, vtable 0x16a3640 */
struct hkcdSimdTree;                        /* FUN_00021a20, vtable 0x1690d70 */
struct hkcdStaticAabbTree;                  /* FUN_00022700, vtable 0x1690df0 */
struct hkcdDynamicAabbTree;                 /* FUN_0009fc10, vtable 0x16a37c0 */
class hkSkinnedRefMeshShape;                /* FUN_000aa660, vtable 0x16a38c0 */
class hkMemoryMeshShape;                    /* FUN_0002a940, vtable 0x1692540 */
class hkSkinBinding;                        /* FUN_000aa4f0, vtable 0x16a3860 */
class hkMemoryMeshMaterial;                 /* FUN_000accf0, vtable 0x16a3920 */
class hkStorageSkinnedMeshShape;            /* FUN_000ae680, vtable 0x16a3b00 */
class hkMemoryMeshVertexBuffer;             /* FUN_000274e0, vtable 0x16921b0 */
class hknpDynamicCompoundShape;             /* FUN_000469a0, vtable 0x1697ef0 */
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

/* hkMemoryMeshVertexBuffer, polymorphic (vtable address point 0x16921b0):
 * members from its record table at 0x1692590: format (struct) at +0xc,
 * elementOffsets (hkInt32[32]) at +0x110, memory (array of hkUint8) at
 * +0x190, vertexStride (hkInt32) at +0x1a0, locked (hkBool) at +0x1a4,
 * numVertices (hkInt32) at +0x1a8, isBigEndian and isSharable (hkBool) at
 * +0x1ac and +0x1ad. */
extern const hkClass D_57bdd98; /* hkMemoryMeshVertexBuffer's hkClass, built at 0x2ae92 */

class hkMemoryMeshVertexBuffer
{
  public:
    virtual ~hkMemoryMeshVertexBuffer();

    /* Not a vtable slot: called with no arguments by the type test at
     * 0xacf40, which checks an object's class (its slot 3) against it. */
    static const hkClass *FUN_0002ae00(); /* derived name */

    int FUN_00027290() const; /* vtable slot 8; derived name */
    void FUN_00027b10();      /* vtable slot 15; derived name */

    u8 unknown8[0x19c];
    hkBool locked;
    u8 unknown1a5[3];
    int numVertices;
};

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
struct hkMeshBoneIndexMapping; /* derived name: the class 0x57bd388 */

/* Its members from the record table at 0x1691d10 (size 0x68, hkClass
 * 0x57bd308, its parent hkReferencedObject's 0x57b8640): matrices and
 * inverseMatrices (arrays of hkMatrix4) at +0x10 and +0x20, matricesOrder
 * (array of hkInt16) at +0x30, matricesNames (array of hkStringPtr) at
 * +0x40, indexMappings (array of the class 0x57bd388) at +0x50,
 * allMatricesAreAffine (hkBool) at +0x60. FUN_00023700 copies matrices in
 * from a start index, FUN_00023770 copies them out and FUN_000237b0 copies
 * the inverses out. */
struct hkIndexedTransformSet : public hkReferencedObject {
    hkArray<Mat4> matrices;
    hkArray<Mat4> inverseMatrices;
    hkArray<s16> matricesOrder;
    hkArray<hkStringPtr> matricesNames;
    hkArray<hkMeshBoneIndexMapping> indexMappings;
    hkBool allMatricesAreAffine;
};

void FUN_00023700(hkIndexedTransformSet *self, int startIndex, const Mat4 *matrices,
                  int numMatrices); /* derived name */
void FUN_00023770(const hkIndexedTransformSet *self, int startIndex, Mat4 *matrices,
                  int numMatrices); /* derived name */
void FUN_000237b0(const hkIndexedTransformSet *self, int startIndex, Mat4 *matrices,
                  int numMatrices); /* derived name */

void FUN_000236e0(hkIndexedTransformSet *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_000234f0(hkIndexedTransformSet *self);                                /* derived name */

/* hkMultipleVertexBuffer, polymorphic (type info 0x57bcf70, size 0x158,
 * vtable 0x1692000 stored by its finish constructor FUN_00024fa0): slot 0,
 * the complete destructor FUN_00024b70, runs the out-of-line FUN_00024db0.
 * Members from its record table at 0x1691820: vertexFormat (struct) at +0xc,
 * lockedElements (array) at +0x110, lockedBuffer (pointer) at +0x120,
 * elementInfos and vertexBufferInfos (arrays) at +0x128 and +0x138,
 * numVertices (hkInt32) at +0x148, isLocked (hkBool) at +0x14c, updateCount
 * (hkUint32) at +0x150. */
extern const hkClass D_57bcf20; /* hkMultipleVertexBuffer's hkClass, built at 0x23adb */

class hkMultipleVertexBuffer
{
  public:
    virtual ~hkMultipleVertexBuffer();

    const hkClass *FUN_000238c0() const; /* vtable slot 3; derived name */
    int FUN_00024bf0() const;            /* vtable slot 8; derived name */

    u8 unknown8[0x140];
    int numVertices;
};

void FUN_00024fa0(hkMultipleVertexBuffer *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00024db0(hkMultipleVertexBuffer *self);                                /* derived name */

/* hkMemoryMeshBody, polymorphic, 0x80 bytes (type info 0x57bccf0, vtable
 * 0x1691610 stored by its finish constructor FUN_00023190): members from
 * its record table at 0x1691530, transform (type 0x11) at +0x10,
 * transformSet (pointer) at +0x50, shape (pointer to hkMeshShape) at +0x58,
 * vertexBuffers (array of pointers) at +0x60, name (hkStringPtr) at +0x70. */
struct hkMeshShape;

/* hkMeshBody, its parent (hkClass 0x57bd408, built at 0x246ae), a
 * hkReferencedObject with no members of its own. */
class hkMeshBody : public hkReferencedObject
{
};

/* Slots 10 to 12 hand matrices to and from the transform set, slots 13 to
 * 15 return its matricesOrder, matricesNames and indexMappings; slot 20
 * (the shared FUN_0000dcb0) returns the name, slot 21 sets it. */
class hkMemoryMeshBody : public hkMeshBody
{
  public:
    virtual ~hkMemoryMeshBody();

    hkMeshShape *FUN_000230d0() const; /* vtable slot 5; derived name */
    void FUN_00023100(int startIndex, const Mat4 *matrices,
                      int numMatrices); /* vtable slot 10; derived name */
    void FUN_00023110(int startIndex, Mat4 *matrices,
                      int numMatrices) const; /* vtable slot 11; derived name */
    void FUN_00023120(int startIndex, Mat4 *matrices,
                      int numMatrices) const;           /* vtable slot 12; derived name */
    const s16 *FUN_00023130() const;                    /* vtable slot 13; derived name */
    const hkStringPtr *FUN_00023140() const;            /* vtable slot 14; derived name */
    const hkMeshBoneIndexMapping *FUN_00023150() const; /* vtable slot 15; derived name */
    void FUN_00023170(const char *newName);             /* vtable slot 21; derived name */

    Mat4 transform;
    hkIndexedTransformSet *transformSet;
    hkMeshShape *shape;
    hkArray<void *> vertexBuffers; /* pointers to the class 0x57bca60 */
    hkStringPtr name;
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
extern const hkClass D_57c27c8; /* hknpStaticCompoundShape's hkClass, built at 0x6c395 */

class hknpStaticCompoundShape
{
  public:
    virtual ~hknpStaticCompoundShape();

    /* vtable slot 3, also of hknpStaticCompoundShapeInternals (0x1692840),
     * which does not override it; derived name */
    const hkClass *FUN_00038740() const;
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
class hknpDefaultBroadPhaseConfig;    /* 0x57c02e8; FUN_00154d90, vtable 0x16a45f0 */
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

/* hknpBreakableConstraintData, polymorphic, 0x28 bytes (type info
 * 0x57c23f8, vtable 0x1695b10): its one reflected member, threshold (float),
 * sits at +0x20 (record table 0x169a740); its constructor FUN_0003c210 sets
 * it to 10. FUN_0003c270 and FUN_0003c280 read and write it.
 * hknpMalleableConstraintData, polymorphic, 0x40 bytes (type info 0x57c18d8,
 * vtable 0x1699a90): members atom at +0x20, wantsRuntime at +0x38 and
 * strength (float) at +0x3c (record table 0x16996a0); FUN_00067c40 writes
 * the strength. Both are built by the game code at 0xea7a00 and 0xea8280. */
class hknpBreakableConstraintData
{
  public:
    virtual ~hknpBreakableConstraintData();

    float FUN_0003c270() const;            /* derived name */
    void FUN_0003c280(float newThreshold); /* derived name */

    u8 unknown8[0x18];
    float threshold;
};

class hknpMalleableConstraintData
{
  public:
    virtual ~hknpMalleableConstraintData();

    void FUN_00067c40(float newStrength); /* derived name */

    u8 unknown8[0x34];
    float strength;
};

/* hknpWorldCinfo (type info 0x57c13e0, no vtable): an empty finish
 * constructor (the shared body FUN_0003b640) and an out-of-line destructor
 * FUN_0003b650, which releases the references from +0xb0 down. */
struct hknpWorldCinfo;

void FUN_0003b640(hknpWorldCinfo *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0003b650(hknpWorldCinfo *self);                                /* derived name */

class hknpMalleableConstraintData; /* 0x57c18d8; FUN_00067960 runs FUN_0007d520, vtable 0x1699a90 */
struct hknpBodyQualityLibrary;     /* 0x57c1a78; FUN_00071190, vtable 0x169b150 */

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
class hknpBreakableConstraintData; /* 0x57c23f8; FUN_0003c240 runs FUN_0007d520, vtable 0x1695b10 */
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
/* Slot 17 of hknpSphereShape's vtable (address point 0x1695c20) returns pi,
 * hknpCapsuleShape's (0x169b270) pi / 2. */
float FUN_0003c660(const hknpSphereShape *self);  /* derived name */
float FUN_00073940(const hknpCapsuleShape *self); /* derived name */
/* hknpStaticCompoundShape's finish constructor (see the class above). */
void FUN_000385d0(hknpStaticCompoundShape *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* hknpExternMeshShape (type info 0x57c28e8, size 0x70): its finish
 * constructor FUN_001660e0 runs hknpShape's, stores 0x1697c80, sets bit 2
 * of the byte at +0x10 when finishing, then stores its own vtable 0x16a5170. */
struct hknpExternMeshShape;

void FUN_001660e0(hknpExternMeshShape *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* hknpBroadPhaseConfig (hkClass 0x57c0248, size 0x10, no members of its own)
 * and hknpDefaultBroadPhaseConfig (hkClass 0x57c0298, size 0x30, parent
 * hknpBroadPhaseConfig; type info 0x57c02e8, vtable 0x16a45f0, address point
 * 0x16a4600), registered by the initializer at 0x3d1f0. The one member,
 * layers (record table 0x16964a0), is a C array of four
 * hknpBroadPhaseConfig::Layer (hkClass 0x57c01c8, size 8, records at
 * 0x1696450: collideWithLayerMask, hkUint32, at +0; isVolatile, hkBool, at
 * +4) at +0xc, in the tail padding of the base; the constructor at 0x154da0
 * fills the four layers. */
class hknpBroadPhaseConfig
{
  public:
    struct Layer {
        u32 collideWithLayerMask;
        bool isVolatile;
    };

    virtual ~hknpBroadPhaseConfig();

    u8 unknown8[4];
};

class hknpDefaultBroadPhaseConfig : public hknpBroadPhaseConfig
{
  public:
    Layer *FUN_00154e00(hkUlong layerIndex); /* vtable slot 6; derived name */

    Layer layers[4];
};

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
class hkpLimitedHingeConstraintData;

/* Two constraint atoms with their reflected members: hkpSetupStabilizationAtom
 * (record table 0x169e600: enabled at +2, padding at +3, maxLinImpulse at
 * +4, maxAngImpulse at +8, maxAngle at +0xc) and hkpBallSocketConstraintAtom
 * (records built by the initializer at 0x80a40: solvingMethod at +2,
 * bodiesToNotify at +3, velocityStabilizationFactor at +4,
 * enableLinearImpulseLimit at +5, breachImpulse at +8,
 * inertiaStabilizationFactor at +0xc). The u16 at +0 is the atom's type,
 * which the constructors store. */
struct hkpSetupStabilizationAtom {
    u16 type; /* derived name */
    bool enabled;
    u8 padding;
    float maxLinImpulse;
    float maxAngImpulse;
    float maxAngle;
};

struct hkpBallSocketConstraintAtom {
    u16 type; /* derived name */
    u8 solvingMethod;
    u8 bodiesToNotify;
    u8 velocityStabilizationFactor;
    bool enableLinearImpulseLimit;
    u8 unknown6[2];
    float breachImpulse;
    float inertiaStabilizationFactor;
};

/* Placement new, as the engine declares it for the finish callbacks: no
 * exception specification, so the storage is not tested for null. */
inline void *operator new(unsigned long, void *where)
{
    return where;
}

/* hknpConstraintCinfo (type info 0x57beab0, size 0x20; its member records
 * are built at run time by the initializer at 0x36a40): constraintData
 * (pointer) at +0, bodyA and bodyB (hkUint32) at +8 and +0xc, flags at
 * +0x10, name (hkStringPtr) at +0x18. Its finish constructor finishes the
 * name. */
struct hknpConstraintData;

struct hknpConstraintCinfo {
    hknpConstraintCinfo(hkFinishLoadedObjectFlag flag)
    {
        FUN_0000e5c0(&name, flag);
    }

    hknpConstraintData *constraintData;
    u32 bodyA;
    u32 bodyB;
    u32 flags;
    hkStringPtr name;
};

/* hknpBodyCinfo (type info 0x57bedf8, size 0xa0, record table 0x1693bf0):
 * shape (pointer) at +0, flags (hkInt32) at +8, collisionFilterInfo
 * (hkUint32) at +0xc, materialId (hkUint16) at +0x10, qualityId (hkUint8) at
 * +0x12, userData (hkUint64) at +0x18, name (hkStringPtr) at +0x20, then
 * motionType, position, orientation, velocities, mass and the rest up to
 * localFrame at +0x90. Its finish constructor finishes the name. */
struct hknpBodyCinfo {
    hknpBodyCinfo(hkFinishLoadedObjectFlag flag)
    {
        FUN_0000e5c0(&name, flag);
    }

    const hknpShape *shape;
    s32 flags;
    u32 collisionFilterInfo;
    u16 materialId;
    u8 qualityId;
    u8 unknown13[5];
    u64 userData;
    hkStringPtr name;
    u8 unknown28[0x78];
};

/* hkpLinMotorConstraintAtom (type info 0x57c4f40, record table 0x169ef70):
 * isEnabled at +2, motorAxis at +3, initializedOffset and
 * previousTargetPositionOffset (hkInt16) at +4 and +6, motor (pointer to
 * hkpConstraintMotor) at +8, targetPosition at +0x10. Its finish
 * constructor resets both offsets. */
struct hkpConstraintMotor;

struct hkpLinMotorConstraintAtom {
    hkpLinMotorConstraintAtom(hkFinishLoadedObjectFlag)
    {
        initializedOffset = -1;
        previousTargetPositionOffset = -1;
    }

    u16 type; /* derived name */
    bool isEnabled;
    u8 motorAxis;
    s16 initializedOffset;
    s16 previousTargetPositionOffset;
    hkpConstraintMotor *motor;
    float targetPosition;
    u8 padding[4];
};

/* hkpRagdollMotorConstraintAtom (record table 0x169f090): isEnabled at +2,
 * initializedOffset at +4, previousTargetAnglesOffset at +6, target_bRca at
 * +0x10, motors (three pointers to hkpConstraintMotor, hkClass 0x57c3af0)
 * at +0x40. */
struct hkpRagdollMotorConstraintAtom {
    u16 type; /* derived name */
    bool isEnabled;
    u8 unknown3;
    s16 initializedOffset;
    s16 previousTargetAnglesOffset;
    u8 unknown8[8];
    u8 target_bRca[0x30];
    hkpConstraintMotor *motors[3];
    u8 unknown58[8];
};

/* hkpRagdollConstraintData, polymorphic (type info 0x57c5bc8, vtable
 * 0x169d0d0, address point 0x169d0e0; constructor FUN_0007d810, finish
 * callback 0x82c70): its member atoms at +0x20 is an
 * hkpRagdollConstraintData::Atoms, 0x180 bytes (record table from 0x169fbb0:
 * transforms at +0, setupStabilization at +0x90, ragdollMotors at +0xa0,
 * angFriction at +0x100, twistLimit at +0x110, coneLimit at +0x130,
 * planesLimit at +0x150, ballSocket at +0x170). Slots 10 and 13 of its vtable
 * write and read the ball-socket atom's breach impulse.
 * FUN_0007dfc0, FUN_0007e160 and FUN_0007e0a0 return the three motors (the
 * copy at 0x79740 takes a reference to each through them), FUN_0007dfe0
 * returns one by index; the setters beside them (0x7dff0, 0x7e0b0, 0x7e170)
 * swap the counted references. */
class hkpRagdollConstraintData
{
  public:
    struct Atoms {
        u8 transforms[0x90];
        hkpSetupStabilizationAtom setupStabilization;
        hkpRagdollMotorConstraintAtom ragdollMotors;
        u8 unknown100[0x70]; /* angFriction, twistLimit, coneLimit, planesLimit */
        hkpBallSocketConstraintAtom ballSocket;
    };

    virtual ~hkpRagdollConstraintData();

    void FUN_0007dc90(float newBreachImpulse); /* vtable slot 10; derived name */
    float FUN_0007dca0() const;                /* vtable slot 13; derived name */

    hkpConstraintMotor *FUN_0007dfc0() const; /* derived name */
    hkpConstraintMotor *FUN_0007e0a0() const; /* derived name */
    hkpConstraintMotor *FUN_0007e160() const; /* derived name */

    u8 unknown8[0x18];
    Atoms atoms;
};

/* hkpBallAndSocketConstraintData, polymorphic, 0x70 bytes (type info
 * 0x57c3fd8, vtable 0x169c7d0, address point 0x169c7e0; constructor
 * FUN_0007c1d0, finish constructor FUN_0007cbf0): its member atoms (at
 * +0x20) is an hkpBallAndSocketConstraintData::Atoms, 0x50 bytes, with
 * pivots at +0, setupStabilization at +0x30 and ballSocket at +0x40
 * (record table 0x169cab0). Slots 10, 11 and 13 of its vtable read and
 * write the breach impulse and the stabilization's linear impulse limit;
 * slot 14 (0x7c310) stores 1 << index into bodiesToNotify and slot 15 reads
 * the index back. */
class hkpBallAndSocketConstraintData
{
  public:
    struct Atoms {
        u8 pivots[0x30];
        hkpSetupStabilizationAtom setupStabilization;
        hkpBallSocketConstraintAtom ballSocket;
    };

    virtual ~hkpBallAndSocketConstraintData();

    void FUN_0007c2c0(float newBreachImpulse); /* vtable slot 10; derived name */
    float FUN_0007c300() const;                /* vtable slot 11; derived name */
    float FUN_0007c2d0() const;                /* vtable slot 13; derived name */
    u8 FUN_0007c320() const;                   /* vtable slot 15; derived name */

    u8 unknown8[0x18];
    Atoms atoms;
};

/* hkpLimitedHingeConstraintData, polymorphic, 0x130 bytes (type info
 * 0x57c5878, vtable 0x169bad0, address point 0x169bae0; finish constructor
 * FUN_00082000): its member atoms at +0x20 is an
 * hkpLimitedHingeConstraintData::Atoms, 0x110 bytes (record table 0x169f2f0:
 * transforms at +0, setupStabilization at +0x90, angMotor at +0xa0,
 * angFriction at +0xc0, angLimit at +0xd0, 2dAng at +0xf0, ballSocket at
 * +0x100). Slots 10 and 13 of its vtable write and read the ball-socket
 * atom's breach impulse, as hkpBallAndSocketConstraintData's do. */
class hkpLimitedHingeConstraintData
{
  public:
    struct Atoms {
        u8 transforms[0x90];
        hkpSetupStabilizationAtom setupStabilization;
        u8 unknownA0[0x60]; /* angMotor, angFriction, angLimit, 2dAng */
        hkpBallSocketConstraintAtom ballSocket;
    };

    virtual ~hkpLimitedHingeConstraintData();

    void FUN_000790b0(float newBreachImpulse); /* vtable slot 10; derived name */
    float FUN_000790c0() const;                /* vtable slot 13; derived name */

    u8 unknown8[0x18];
    Atoms atoms;
};

/* hkpConstraintData, the constraint data base (hkClass 0x57c45a8, built at
 * 0x7f444, 0x18 bytes, parent hkReferencedObject; finish constructor
 * FUN_00082850 stores its vtable 0x169fac0, address point 0x169fad0, whose
 * slots 5 to 7 and 20 are pure). Slots 8 to 10 default to the empty body
 * 0x3b640; slots 11 to 13, kept by twenty-odd constraint data vtables,
 * return the largest float Havok uses (0x7f7fffee) for the linear, angular
 * and breach impulse limits; slot 15 (0x82bc0) returns 255. */
class hkpConstraintData : public hkReferencedObject
{
  public:
    float FUN_00082b90() const; /* vtable slot 11; derived name */
    float FUN_00082ba0() const; /* vtable slot 12; derived name */
    float FUN_00082bb0() const; /* vtable slot 13; derived name */
};

/* hkpFixedConstraintData, polymorphic, 0xe0 bytes (type info 0x57c3438,
 * vtable 0x169c620, address point 0x169c630): its member atoms at
 * +0x20 is an hkpFixedConstraintData::Atoms, 0xc0 bytes (record table
 * 0x169bd30: transforms at +0, setupStabilization at +0x90, ballSocket at
 * +0xa0, ang at +0xb0). Slot 8 (0x7bea0) sets the stabilization's linear
 * impulse limit and the ball socket's enableLinearImpulseLimit, slot 9 its
 * angular limit; slots 11 and 12 read the two limits back. */
class hkpFixedConstraintData
{
  public:
    struct Atoms {
        u8 transforms[0x90];
        hkpSetupStabilizationAtom setupStabilization;
        hkpBallSocketConstraintAtom ballSocket;
        u8 ang[0x10];
    };

    virtual ~hkpFixedConstraintData();

    void FUN_0007bec0(float newMaxAngImpulse); /* vtable slot 9; derived name */
    float FUN_0007bed0() const;                /* vtable slot 11; derived name */
    float FUN_0007bee0() const;                /* vtable slot 12; derived name */

    u8 unknown8[0x18];
    Atoms atoms;
};

/* hkpHingeConstraintData, polymorphic, 0xe0 bytes (type info 0x57c42d8,
 * vtable 0x169d4f0, address point 0x169d500): its member atoms at +0x20 is an
 * hkpHingeConstraintData::Atoms, 0xc0 bytes (record table 0x169cdd0:
 * transforms at +0, setupStabilization at +0x90, 2dAng at +0xa0, ballSocket
 * at +0xb0). Slots 10 and 13 of its vtable write and read the ball-socket
 * atom's breach impulse. */
class hkpHingeConstraintData
{
  public:
    struct Atoms {
        u8 transforms[0x90];
        hkpSetupStabilizationAtom setupStabilization;
        u8 unknownA0[0x10]; /* 2dAng */
        hkpBallSocketConstraintAtom ballSocket;
    };

    virtual ~hkpHingeConstraintData();

    void FUN_0007efa0(float newBreachImpulse); /* vtable slot 10; derived name */
    float FUN_0007efb0() const;                /* vtable slot 13; derived name */

    u8 unknown8[0x18];
    Atoms atoms;
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

/* hkxVertexDescription::ElementDecl (type info 0x57c7f10, size 0x18, no
 * vtable; its records, built at run time by the initializer from 0x8cf60,
 * name byteStride and channelID, the hkStringPtr at +0x10). Its finish
 * constructor finishes the channel name, its destructor destroys it. */
struct hkxVertexDescriptionElementDecl {
    hkxVertexDescriptionElementDecl(hkFinishLoadedObjectFlag flag)
    {
        FUN_0000e5c0(&channelID, flag);
    }

    ~hkxVertexDescriptionElementDecl()
    {
        FUN_0000e5d0(&channelID);
    }

    u8 unknown0[0x10];
    hkStringPtr channelID;
};

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

/* hkMemoryMeshMaterial, 0x80 bytes (type info 0x57bd4a8, vtable 0x16a3920 stored
 * by its finish constructor FUN_000accf0): members from its record table
 * at 0x1691e80, materialName (hkStringPtr) at +0x10, textures (array of
 * pointers to hkMeshTexture, hkClass 0x57bc990) at +0x18, diffuseColor,
 * ambientColor, specularColor and emissiveColor (hkVector4) from +0x30,
 * userData (hkUlong) at +0x70, tesselationFactor (hkReal) at +0x78,
 * displacementAmount (hkReal) at +0x7c. */
extern const hkClass D_57bd458; /* hkMemoryMeshMaterial's hkClass, built at 0x24752 */

class hkMemoryMeshMaterial
{
  public:
    virtual ~hkMemoryMeshMaterial();

    const hkClass *FUN_000246c0() const;    /* vtable slot 3; derived name */
    void FUN_000acf80(const char *newName); /* vtable slot 9; derived name */
    const char *FUN_000acf90() const;       /* vtable slot 10; derived name */
    hkUlong FUN_000acae0() const;           /* vtable slot 17; derived name */
    void FUN_000acaf0(hkUlong newUserData); /* vtable slot 18; derived name */
    float FUN_000acb00() const;             /* vtable slot 19; derived name */
    void FUN_000acb10(float factor);        /* vtable slot 20; derived name */
    float FUN_000acb20() const;             /* vtable slot 21; derived name */
    void FUN_000acb30(float amount);        /* vtable slot 22; derived name */

    u8 unknown8[8];
    hkStringPtr materialName;
    u8 textures[0x10];
    Vec4 diffuseColor;
    Vec4 ambientColor;
    Vec4 specularColor;
    Vec4 emissiveColor;
    hkUlong userData;
    float tesselationFactor;
    float displacementAmount;
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
extern const hkClass D_57bd5f8; /* hkMemoryMeshTexture's hkClass, built at 0x248d2 */

class hkMemoryMeshTexture : public hkMeshTexture
{
  public:
    virtual ~hkMemoryMeshTexture();

    const hkClass *FUN_000247f0() const;              /* vtable slot 3; derived name */
    Format FUN_000ad6e0() const;                      /* vtable slot 8; derived name */
    bool FUN_000ad710() const;                        /* vtable slot 11; derived name */
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
    hkBool hasMipMaps;
    hkEnum<FilterMode, s8> filterMode;
    hkEnum<TextureUsageType, s8> usageHint;
    s32 textureCoordChannel;
};

/* hkOstream: its hkClass at 0x57b7e18 is built by the reflection
 * initializer at 0x8a7b (name "hkOstream"); slot 3 of the vtables at
 * 0x168c3b0 and 0x168d110 (FUN_00008a20) returns it. */
extern const hkClass D_57b7e18; /* hkOstream's hkClass */

class hkOstream
{
  public:
    const hkClass *FUN_00008a20() const; /* vtable slot 3; derived name */
};

/* hkBufferedStreamWriter: its hkClass at 0x57b7fe8 is built by the
 * reflection initializer at 0x93d0 (name "hkBufferedStreamWriter"); slot 3
 * of its vtable (address point 0x168d220, FUN_00008ea0) returns it. */
extern const hkClass D_57b7fe8; /* hkBufferedStreamWriter's hkClass */

class hkBufferedStreamWriter
{
  public:
    const hkClass *FUN_00008ea0() const; /* vtable slot 3; derived name */
};

/* hkSkinnedRefMeshShape: its hkClass at 0x57bcd20 is built by the
 * reflection initializer at 0x23402; slot 3 of its vtable (0x16a38c0,
 * FUN_00023370) returns it. */
extern const hkClass D_57bcd20; /* hkSkinnedRefMeshShape's hkClass */

class hkSkinnedRefMeshShape
{
  public:
    virtual ~hkSkinnedRefMeshShape();

    const hkClass *FUN_00023370() const;    /* vtable slot 3; derived name */
    const char *FUN_000aa880() const;       /* vtable slot 8; derived name */
    void FUN_000aa890(const char *newName); /* vtable slot 9; derived name */

    /* From its record table at 0x16916c0: skinnedMeshShape (pointer) at
     * +0x10, bones and localFromRootTransforms (arrays) at +0x18 and +0x28,
     * name (hkStringPtr) at +0x38. */
    u8 unknown8[0x30];
    hkStringPtr name;
};

/* hkMemoryMeshShape: its hkClass at 0x57bd0a0 is built by the reflection
 * initializer at 0x241e3; slot 3 of its vtable (0x1692540, FUN_00023de0)
 * returns it. */
extern const hkClass D_57bd0a0; /* hkMemoryMeshShape's hkClass */

class hkMemoryMeshShape
{
  public:
    virtual ~hkMemoryMeshShape();

    const hkClass *FUN_00023de0() const;    /* vtable slot 3; derived name */
    const char *FUN_0002a910() const;       /* vtable slot 8; derived name */
    void FUN_0002a920(const char *newName); /* vtable slot 9; derived name */

    /* From its record table at 0x1691bf0: sections (array) at +0x10,
     * indices16 and indices32 (arrays) at +0x20 and +0x30, name
     * (hkStringPtr, finished by FUN_0002a940) at +0x40. */
    u8 unknown8[0x38];
    hkStringPtr name;
};

/* hkSkinBinding: its hkClass at 0x57bd288 is built by the reflection
 * initializer at 0x24362; slot 3 of its vtable (0x16a3860, FUN_000242d0)
 * returns it. */
extern const hkClass D_57bd288; /* hkSkinBinding's hkClass */

class hkSkinBinding
{
  public:
    virtual ~hkSkinBinding();

    const hkClass *FUN_000242d0() const; /* vtable slot 3; derived name */
};

/* hkStorageSkinnedMeshShape: its hkClass at 0x57bdd18 is built by the
 * reflection initializer at 0x27e79; slot 3 of its vtable (0x16a3b00,
 * FUN_00027bd0) returns it. */
extern const hkClass D_57bdd18; /* hkStorageSkinnedMeshShape's hkClass */

class hkStorageSkinnedMeshShape
{
  public:
    virtual ~hkStorageSkinnedMeshShape();

    const hkClass *FUN_00027bd0() const;    /* vtable slot 3; derived name */
    const char *FUN_000aea20() const;       /* vtable slot 12; derived name */
    void FUN_000aea30(const char *newName); /* vtable slot 13; derived name */

    /* From its record table at 0x1692420: bonesBuffer, boneSets,
     * boneSections and parts (arrays) from +0x10, name (hkStringPtr) at
     * +0x50. */
    u8 unknown8[0x48];
    hkStringPtr name;
};

/* hknpDynamicCompoundShape: its hkClass at 0x57be640 is built by the
 * reflection initializer at 0x35935; slot 3 of its vtable (0x1697ef0,
 * FUN_000358a0) returns it. */
extern const hkClass D_57be640; /* hknpDynamicCompoundShape's hkClass */

class hknpDynamicCompoundShape
{
  public:
    virtual ~hknpDynamicCompoundShape();

    const hkClass *FUN_000358a0() const; /* vtable slot 3; derived name */
};

/* hkGeometry, polymorphic (vtable 0x1692500): members from its record table
 * at 0x168ea40, vertices (array of hkVector4) at +0x10 and triangles (array
 * of hkGeometry::Triangle, 16 bytes each) at +0x20. */
class hkGeometry
{
  public:
    struct Triangle;

    virtual ~hkGeometry();

    u8 unknown8[8];
    hkArray<Vec4> vertices;
    hkArray<Triangle> triangles;
};

/* hknpDefaultExternMeshShapeGeometry (type info 0x57bfce0, vtable address
 * point 0x16959f0, reflected member geometry at +0x10): its destructors
 * (slots 0 and 1, 0x3b870 and 0x3b8e0) release the counted reference to the
 * hkGeometry at +0x10; slot 5 (FUN_0003b980) returns its triangle count,
 * slot 6 copies a triangle's three vertices, slot 7 returns a triangle's
 * 16-bit material at +0xc. */
class hknpDefaultExternMeshShapeGeometry
{
  public:
    virtual ~hknpDefaultExternMeshShapeGeometry();

    int FUN_0003b980() const; /* vtable slot 5; derived name */

    u8 unknown8[8];
    hkGeometry *geometry;
};

/* hknpCompoundShape: its hkClass at 0x57c2e78 is built by the reflection
 * initializer at 0x77eae and is the parent of hknpDynamicCompoundShape's and
 * hknpStaticCompoundShape's; slot 3 of its vtable (address point 0x1697910,
 * FUN_000418b0) returns it. */
extern const hkClass D_57c2e78; /* hknpCompoundShape's hkClass */

/* Slots 0 to 30 of the vtable at 0x1697910 hold the bodies named below
 * (slots 2 to 30 by the function each holds; their signatures are not
 * recovered except slot 3's). Slots 31 and 32 are pure (__cxa_pure_virtual);
 * slot 31 of hknpStaticCompoundShape (FUN_000d0450) recomputes the shape's
 * AABB from its tree, hence its name. */
class hknpCompoundShape
{
  public:
    virtual ~hknpCompoundShape();

    virtual void FUN_00000270();                 /* slot 2 */
    virtual const hkClass *FUN_000418b0() const; /* slot 3; derived name */
    virtual void FUN_000069a0();                 /* slot 4 */
    virtual void FUN_0006e3d0();                 /* slot 5 */
    virtual void FUN_0006e510();                 /* slot 6 */
    virtual void FUN_00041870();                 /* slot 7 */
    virtual void FUN_00041890();                 /* slot 8 */
    virtual void FUN_0006e5b0();                 /* slot 9 */
    virtual void FUN_0006e650();                 /* slot 10 */
    virtual void FUN_0006e6f0();                 /* slot 11 */
    virtual void FUN_0006e790();                 /* slot 12 */
    virtual void FUN_0006e830();                 /* slot 13 */
    virtual void FUN_0006e970();                 /* slot 14 */
    virtual void FUN_0006e8d0();                 /* slot 15 */
    virtual void FUN_0006ea10();                 /* slot 16 */
    virtual void FUN_0006eab0();                 /* slot 17 */
    virtual void FUN_0006eb50();                 /* slot 18 */
    virtual void FUN_0006ebf0();                 /* slot 19 */
    virtual void FUN_0006fbd0();                 /* slot 20 */
    virtual void FUN_000418c0();                 /* slot 21 */
    virtual void FUN_00041a80();                 /* slot 22 */
    virtual void FUN_0006f9c0();                 /* slot 23 */
    virtual void FUN_0006fa60();                 /* slot 24 */
    virtual void FUN_0006f880();                 /* slot 25 */
    virtual void FUN_0006f920();                 /* slot 26 */
    virtual void FUN_000426b0();                 /* slot 27 */
    virtual void FUN_00041e40();                 /* slot 28 */
    virtual void FUN_00042300();                 /* slot 29 */
    virtual void FUN_0003b640();                 /* slot 30 */
    virtual void updateAabb() = 0;               /* slot 31; derived name */
};

/* hknpCompositeShape: its hkClass at 0x57c2cf8 (parent 0x57bf1c0) is built by
 * the reflection initializer at 0x71732, whose type info names the vtable
 * 0x1697c80 (address point 0x1697c90), the intermediate base whose vtable the
 * finish constructors of hknpLodShape, hknpCompressedHeightFieldShape and
 * hknpCompressedMeshShape store before their own. Slot 3 (FUN_00042e80)
 * returns it, and six derived vtables (0x1699c10, 0x16a3e40, 0x16a49a0,
 * 0x16a5180, 0x16a5990, 0x16ca050) keep it. */
extern const hkClass D_57c2cf8; /* hknpCompositeShape's hkClass */

class hknpCompositeShape
{
  public:
    virtual ~hknpCompositeShape();

    const hkClass *FUN_00042e80() const; /* vtable slot 3; derived name */
};

/* hkxBlobMeshShape: its hkClass at 0x57c5e78 is built by the reflection initializer at
 * 0x85de2; slot 3 of its vtable (address point 0x16a07a0, FUN_00085d30) returns it. */
extern const hkClass D_57c5e78; /* hkxBlobMeshShape's hkClass */

class hkxBlobMeshShape
{
  public:
    virtual ~hkxBlobMeshShape();

    const hkClass *FUN_00085d30() const;    /* vtable slot 3; derived name */
    const char *FUN_00085c20() const;       /* vtable slot 8; derived name */
    void FUN_00085c30(const char *newName); /* vtable slot 9; derived name */

    /* From its record table at 0x16a0830 (0x38 bytes): blob (struct
     * hkxBlob, hkClass 0x57c7a80) at +0x10, name (hkStringPtr) at +0x30. */
    u8 unknown8[0x28];
    hkStringPtr name;
};

/* hkxTextureFile: its hkClass at 0x57c67d0 is built by the reflection initializer at
 * 0x879b2; slot 3 of its vtable (address point 0x16a0f00, FUN_000878e0) returns it. */
extern const hkClass D_57c67d0; /* hkxTextureFile's hkClass */

class hkxTextureFile
{
  public:
    virtual ~hkxTextureFile();

    const hkClass *FUN_000878e0() const; /* vtable slot 3; derived name */
};

/* hkxAnimatedFloat: its hkClass at 0x57c7930 is built by the reflection initializer at
 * 0x8bac2; slot 3 of its vtable (address point 0x16a24d0, FUN_0008ba30) returns it. */
extern const hkClass D_57c7930; /* hkxAnimatedFloat's hkClass */

class hkxAnimatedFloat
{
  public:
    virtual ~hkxAnimatedFloat();

    const hkClass *FUN_0008ba30() const; /* vtable slot 3; derived name */
};

/* hkArrayStreamWriter: its hkClass at 0x57c8750 is built by the reflection initializer at
 * 0x901fb; slot 3 of its vtable (address point 0x16a3300, FUN_0008ff00) returns it. */
extern const hkClass D_57c8750; /* hkArrayStreamWriter's hkClass */

class hkArrayStreamWriter
{
  public:
    virtual ~hkArrayStreamWriter();

    const hkClass *FUN_0008ff00() const; /* vtable slot 3; derived name */
};

#endif
