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

#include <smmintrin.h>

#include "tlg_simd.h"
#include "tlg_types.h"

/* hkUlong, the reflection's type 0x1e: an unsigned integer as wide as a
 * pointer. */
typedef unsigned long hkUlong;

/* The result code of the calls that can fail: 0 for success. derived names. */
enum hkResult {
    HK_SUCCESS = 0, /* derived name */
    HK_FAILURE = 1  /* derived name */
};

/* Havok's assert in its release form (docs/DECISIONS.md D16): the build
 * compiles no checks, and the statement is a null statement. The id is 0
 * where the original id is not in the executable. */
#define HK_ASSERT(id, condition) ((void)0)

/* The break the library's kept checks stop on: an int3 (the debug trap,
 * tools/cc/src/llvm-3.3.src/lib/Target/X86/X86InstrSystem.td:37), after
 * which execution goes on; 92 of the library region's 214 int3s are reached
 * through a conditional branch (docs/DECISIONS.md D19). derived name. */
#define HK_BREAKPOINT(id) __builtin_debugtrap()

/* Havok's restrict qualifier for its output parameters (an aliasing
 * promise, part of the signature's meaning): an output that does not
 * overlap the inputs, so a value read before an output is written is
 * reused after it (hknpCircularSurfaceVelocity's slot 5, 0x15fa60, reads
 * its angular velocity once). */
#define HK_RESTRICT __restrict

/* The largest float Havok uses (its HK_REAL_MAX, 3.40282e+38f: the bits
 * 0x7f7fffee the constraint datas' slots 11 to 13 return and their breach
 * tests compare with). */
#define HK_REAL_MAX 3.40282e+38f

/* A copy of 16-byte quads (derived names): the source and destination
 * stepped together, the source first, until the count runs out
 * (hkIndexedTransformSet's matrix copies 0x23700 and 0x23770 pass four
 * quads a matrix, a count the copy tests again). */
namespace hkString /* derived name */
{
inline void memCpy16(void *dst, const void *src, int numQuads) /* derived name */
{
    Vec4 *d = static_cast<Vec4 *>(dst);
    const Vec4 *s = static_cast<const Vec4 *>(src);
    while (numQuads--) {
        *d = *s;
        s++;
        d++;
    }
}
} // namespace hkString

/* The scalar helpers (derived names): the larger and the smaller of two
 * values by one comparison each, and a value clamped to a range through
 * both (0x7c3e0: vmaxss against zero, then vminss against one). */
namespace hkMath /* derived name */
{
template <typename T> inline T max2(T a, T b) /* derived name */
{
    return a > b ? a : b;
}

template <typename T> inline T min2(T a, T b) /* derived name */
{
    return a < b ? a : b;
}

template <typename T> inline T clamp(T value, T low, T high) /* derived name */
{
    return min2(max2(value, low), high);
}

/* The integer forms work in a vector register (pminsd, pmaxsd: hknpLodShape's
 * slot 29 at 0x6896e, the constraint info's maximum at 0x82974). */
inline int min2(int a, int b)
{
    return _mm_cvtsi128_si32(_mm_min_epi32(_mm_cvtsi32_si128(a), _mm_cvtsi32_si128(b)));
}

inline int max2(int a, int b)
{
    return _mm_cvtsi128_si32(_mm_max_epi32(_mm_cvtsi32_si128(a), _mm_cvtsi32_si128(b)));
}

/* The magnitude of a float in a vector register: the bits doubled, which
 * shifts the sign out, then shifted back down with a zero in its place
 * (`vpaddd; vpsrld $1`, the aerodynamics' drag at 0x3bf3f; every such pair
 * in the library region doubles with vpaddd, none shifts with vpslld).
 * derived name. */
inline float fabs(float r)
{
    __m128i bits = _mm_castps_si128(_mm_set_ss(r));
    return _mm_cvtss_f32(_mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(bits, bits), 1)));
}
} // namespace hkMath

/* hkArray, the reflection's array type (its name in the type-name table at
 * 0x14b30e4): a data pointer, a size and a capacity whose top bits are
 * flags (0x80000000 when the array does not own its storage, as the
 * constructors store it; the capacity is masked with 0x3fffffff before a
 * grow). Field names derived. */
/* The flag a finish constructor takes, passed by value: the finish callback
 * forwards its int argument in it. derived name. */
struct hkFinishLoadedObjectFlag {
    s32 finishing; /* derived name */
};

template <typename T> struct hkArray {
    enum { DONT_DEALLOCATE_FLAG = int(0x80000000) }; /* derived name */

    /* An empty array that owns no storage (the constructors' stores). */
    hkArray() : data(0), size(0), capacityAndFlags(DONT_DEALLOCATE_FLAG) {}

    /* A loaded image's array is left as loaded. */
    hkArray(hkFinishLoadedObjectFlag) {}

    /* An array over storage it does not own (hkInplaceArray's). */
    hkArray(T *buffer, int initialSize, int capacity)
        : data(buffer), size(initialSize), capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG)
    {
    }

    /* Drop the elements, keeping the storage. derived name. */
    void clear()
    {
        size = 0;
    }

    /* Drop the elements and give the storage back to the containers'
     * allocator unless the array does not own it (defined in
     * tlg_lib_unknown.h, after AllocatorBase). derived name. */
    void clearAndDeallocate();

    T &operator[](int index)
    {
        return data[index];
    }

    const T &operator[](int index) const
    {
        return data[index];
    }

    T *data;              /* derived name */
    int size;             /* derived name */
    int capacityAndFlags; /* derived name */
};

/* hkInplaceArray (the reflection's TYPE_INPLACEARRAY, its name a string of
 * the executable): an array whose first N elements live in the object. */
template <typename T, int N> struct hkInplaceArray : public hkArray<T> {
    hkInplaceArray() : hkArray<T>(storage, 0, N) {}

    T storage[N];
};

/* hkBitField (type info registered at 0x9e2b, size 0x18): its member
 * storage at +0 (record 0x168d2f0), a hkBitFieldStorage of hkArray<unsigned
 * int> (the scoped type names at 0x14b332f onward) whose words are at +0
 * and numBits at +0x10 (records 0x168d350, 0x168d378). Havok writes it as a
 * template over the storage; the one instance used here is spelled out.
 * FUN_00047b30 resizes it, filling the new bits. */
struct hkBitFieldStorage {
    hkArray<u32> words;
    int numBits;
};

struct hkBitField {
    /* The cleanup callback of its type info (0x9cc0; fourteen other type
     * infos cite the same body). derived name. */
    static void FUN_00009cc0(void *object);

    /* Resizes the field to a number of bits, filling the bits it gains
     * with the value (0x47b30; the first int is not read). derived name. */
    void FUN_00047b30(int startBit, int numBits, int fillValue); /* derived name */

    /* Sets one bit (derived name). */
    void set(int index)
    {
        storage.words.data[index >> 5] |= 1 << (index & 31);
    }

    hkBitFieldStorage storage;
};

/* hkIntRealPair (type info "!hkIntRealPair" at 0x14b4435, hkClass 0x57b9560
 * built at 0x15133: size 8, members key (hkInt32) and value (hkReal) from
 * the records at 0x168e630), the element of hkSetIntFloatPair (hkClass
 * 0x57b95e0, built at 0x151dc: size 0x18), Havok's set over an array of
 * them with the count after it (derived names). */
struct hkIntRealPair {
    int key;
    float value;
};

struct hkSetIntFloatPair {
    /* The cleanup callback of its type info (0x15020; the other sets'
     * type infos registered by 0x150c0 cite the same body). derived
     * name. */
    static void FUN_00015020(void *object);

    hkArray<hkIntRealPair> elem; /* derived name */
    int numElems;                /* derived name */
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

    /* Compared in the storage type (0x27150's `cmp byte, sil`). */
    bool operator==(ENUM e) const
    {
        return m_storage == static_cast<STORAGE>(e);
    }

    STORAGE m_storage;
};

struct hkClassEnum;
struct hkClassMember;

/* A list of names (derived names): the name at +0, the next entry at +8.
 * The type registry's walk (0x17f8d5) asks hkClass::FUN_00004270 whether a
 * class's name is on one. */
struct NameList00004270 /* derived name */
{
    const char *name;             /* derived name */
    const NameList00004270 *next; /* derived name */
};

/* hkClass, the reflection's class record: name (char*, type 0x1d) at +0,
 * parent (pointer to hkClass, type 0x14) at +8, objectSize and
 * numImplementedInterfaces (int) at +0x10 and +0x14, declaredEnums and
 * declaredMembers (simple arrays: a pointer and an int count) at +0x18 and
 * +0x28, from its own member table at 0x16a6b60; its constructor
 * FUN_000041a0 stores the twelve fields from +0 to +0x4c. */
struct hkClass {
    /* Whether the class's name is on a list of names (0x4270; FUN_00017f40
     * compares them). derived name. */
    bool FUN_00004270(const NameList00004270 *list) const;

    /* The counts over the class and its parents: implemented interfaces
     * (0x42b0) and members (0x4350). derived names. */
    int FUN_000042b0() const; /* derived name */
    int FUN_00004350() const; /* derived name */
    /* The class's name, out of line (0x4200). derived name. */
    const char *FUN_00004200() const;
    /* The object's size, out of line (0x4580, one body with the other
     * classes' int getters at +0x10). derived name. */
    int FUN_00004580() const;

    const char *name;
    const hkClass *parent;
    int objectSize;
    int numImplementedInterfaces;
    const hkClassEnum *declaredEnums;
    int numDeclaredEnums; /* derived name */
    const hkClassMember *declaredMembers;
    int numDeclaredMembers; /* derived name */
};

/* hkClassEnum (the reflection's enum record; its type and its item's are
 * named "hkClassEnum" and "hkClassEnumItem"): the name at +0, the items at
 * +8 and their count at +0x10, each item a value and its name (16 bytes).
 * FUN_00014dc0 finds the name of a value, FUN_00014e00 the value of a
 * name; each fails (HK_FAILURE) when the enum has no such item. derived
 * names. */
struct hkClassEnum {
    struct Item {
        int value;
        const char *name;
    };

    hkResult FUN_00014dc0(int value, const char **nameOut) const;     /* derived name */
    hkResult FUN_00014e00(const char *itemName, int *valueOut) const; /* derived name */

    const char *name;
    const Item *items;
    int numItems;
};

/* derived name: tells whether two classes are the same, by address or by
 * name (strcmp); false when the other is null. */
bool FUN_00004210(const hkClass *self, const hkClass *other);

/* derived name: the same test again (0x185450), a bool from a bool (its
 * callers use the byte unwidened); the mesh code tests an object's class
 * against a known one with it. */
bool FUN_00185450(const hkClass *self, const hkClass *other);

/* hkMatrix3 (the reflection's type name): three columns of four floats. */
struct hkMatrix3 {
    Vec4 col0; /* derived name */
    Vec4 col1; /* derived name */
    Vec4 col2; /* derived name */

    /* derived name: whether the columns are of unit length and the third
     * the cross product of the first two, within epsilon (0xbde0; the
     * constraint datas' slot 7 asks it of their frames with 1e-5). */
    bool FUN_0000bde0(float epsilon = 1e-5f) const;

    /* derived name: this set to the inverse of m, from the cross products
     * of its columns over the determinant; zero and HK_FAILURE when the
     * determinant is within a tolerance of zero (0x1ae40). */
    hkResult FUN_0001ae40(const hkMatrix3 &m);

    /* derived name: this set to a * b (0x1a9f0: each column of b
     * transformed by a). */
    void FUN_0001a9f0(const hkMatrix3 &a, const hkMatrix3 &b);

    /* derived name: each column scaled, lane by lane, by a vector (0x1ac70;
     * called from 0x2913b, 0x293d2 and 0x2968e). */
    void FUN_0001ac70(const Vec4 &scale);

    /* derived name: m added column by column (0x1af70; called at 0x29ac8). */
    void FUN_0001af70(const hkMatrix3 &m);

    /* derived name: m subtracted column by column (0x1afa0; called at
     * 0xb1cc8 and 0x1578f8). */
    void FUN_0001afa0(const hkMatrix3 &m);

    /* derived name: m's columns, each scaled lane by lane by a vector the
     * caller holds in memory, added to this (0x1ad10; called at 0xb1ce3). */
    void FUN_0001ad10(const Vec4 &scale, const hkMatrix3 &m);

    /* derived name: whether the columns are of unit length within a
     * tolerance and orthogonal (0xbe80; the game calls it on its own
     * rotations). */
    bool FUN_0000be80() const;

    /* derived name: whether x, y and z of every column are ordered numbers
     * (0x1a940, called at 0xbf2a). */
    bool FUN_0001a940() const;

    /* derived name: the matrix transposed in place (0x1a980; the geometry
     * code calls it at 0xb1cbd, 0xb1e0c, 0xb1e86 and 0xb47d3). */
    void FUN_0001a980();
};

/* derived name: out = m times v, v's x, y and z broadcast and each scaling
 * its column (0x10ef0; called by FUN_0003bc10 at 0x3bed4 and by the four
 * shapes' functions from 0x524d0). */
void FUN_00010ef0(Vec4 &out, const hkMatrix3 &m, const Vec4 &v);

/* derived name: out = the transpose of m times v, each lane the dot product
 * of v's x, y and z with one column (0x10f20; FUN_0003bc10 calls it at
 * 0x3bd70). */
void FUN_00010f20(Vec4 &out, const hkMatrix3 &m, const Vec4 &v);

/* hkTransform (the reflection's TYPE_TRANSFORM, 64 bytes): a rotation and
 * a translation. */
struct hkTransform {
    /* derived name: a usable transform, its translation's x, y and z
     * numbers (not NaN) and its rotation orthonormal (0x10ce0; the game
     * checks a body's transform with it, 0xeae90b). */
    bool FUN_00010ce0() const;

    hkMatrix3 rotation; /* derived name */
    Vec4 translation;   /* derived name */
};

/* derived name: out = the point v under the transform, its rotation's
 * columns scaled by v's x, y and z and summed, the translation added
 * (0x10f50). */
void FUN_00010f50(Vec4 &out, const hkTransform &t, const Vec4 &v);

/* derived name: out = v brought into the transform's space, the
 * translation taken off and the rotation undone (0x10f90). */
void FUN_00010f90(Vec4 &out, const hkTransform &t, const Vec4 &v);

/* hkClassMember, a 40-byte member record (member names from its own
 * reflection strings at 0x14b2cc0: name, class, enum, type, subtype,
 * cArraySize, flags, offset). The records read here: 0x168c1f0 onward
 * (colorName: type 0x21, offset 0) and 0x168c920 (hkUuid's data: type 0x08,
 * cArraySize 4). */
struct hkClassMember {
    /* The member types, the reflection's own item names (0x14b6dd9 onward),
     * in their order. */
    enum Type {
        TYPE_VOID,
        TYPE_BOOL,
        TYPE_CHAR,
        TYPE_INT8,
        TYPE_UINT8,
        TYPE_INT16,
        TYPE_UINT16,
        TYPE_INT32,
        TYPE_UINT32,
        TYPE_INT64,
        TYPE_UINT64,
        TYPE_REAL,
        TYPE_VECTOR4,
        TYPE_QUATERNION,
        TYPE_MATRIX3,
        TYPE_ROTATION,
        TYPE_QSTRANSFORM,
        TYPE_MATRIX4,
        TYPE_TRANSFORM,
        TYPE_ZERO,
        TYPE_POINTER,
        TYPE_FUNCTIONPOINTER,
        TYPE_ARRAY,
        TYPE_INPLACEARRAY,
        TYPE_ENUM,
        TYPE_STRUCT,
        TYPE_SIMPLEARRAY,
        TYPE_HOMOGENEOUSARRAY,
        TYPE_VARIANT,
        TYPE_CSTRING,
        TYPE_ULONG,
        TYPE_FLAGS,
        TYPE_HALF,
        TYPE_STRINGPTR,
        TYPE_RELARRAY,
        TYPE_MAX,
    };

    /* A type's name, size and alignment (derived names): 24-byte rows of the
     * table at 0x16dc150 (defined in the TU that reads it, D17), one per type
     * from TYPE_VOID to TYPE_MAX, its name in the type-name pool from
     * 0x14b2fa6; the type byte is followed by seven bytes of padding, the
     * align field by four. */
    struct TypeProperties {
        u8 type;          /* derived name */
        const char *name; /* derived name */
        s16 size;         /* derived name */
        s16 align;        /* derived name */
    };

    static const TypeProperties &FUN_00007d40(Type type); /* derived name */

    /* The size of one element of an array member, by its subtype: a
     * struct's object size, -1 for an enum or flags element, else the
     * type's size (0x7f20). derived name. */
    int FUN_00007f20() const;

    /* The integer the member holds at an address, read by its type and
     * subtype (FUN_00091270). derived name. */
    s64 FUN_00007f90(const void *address) const;

    const char *name;
    const hkClass *structClass;   /* reflected as "class"; derived name */
    const hkClassEnum *enumClass; /* reflected as "enum"; derived name */
    u8 type;
    u8 subtype;
    s16 cArraySize;
    u16 flags;
    u16 offset;
};

/* derived name: reads an integer of a member type from an address, widened
 * to 64 bits (0x91270: a switch on the type, an enum's or flags' storage by
 * the subtype); 0 for a type that is not an integer. */
s64 FUN_00091270(hkClassMember::Type type, hkClassMember::Type subtype, const void *address);

/* An accessor of one member of an object (derived name): the member's
 * address at +0 (built by FUN_00184150 from the object and the record's
 * offset) and its record at +8. hkResourceHandle.cpp's link resolver
 * (0x17f770) reads the record through the shared +8 load FUN_00004250 and
 * stores the resolved object through FUN_001841d0. */
struct hkClassMemberAccessor /* derived name */
{
    hkClassMemberAccessor(void *object, const hkClassMember *member);
    void *&FUN_001841d0(int index) const; /* derived name */

    void *address;               /* derived name */
    const hkClassMember *member; /* derived name */
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
    /* The finish constructor of a loaded image: nothing to fix up but the
     * vtable. */
    hkBaseObject(hkFinishLoadedObjectFlag) {}

    hkBaseObject() {}

    /* Empty and inline: slots 0 and 1 of hkBaseObject's vtable are the empty
     * body FUN_00006660, and hkReferencedObject's deleting destructor
     * (FUN_000066e0) runs no base destructor. */
    virtual ~hkBaseObject() {}

    /* Slot 2 of hkBaseObject's vtable (0x168cb30), the last: the shared
     * empty body FUN_00000270, kept by every library-region vtable whose
     * slot 4 is FUN_000069a0. derived name. */
    virtual void FUN_00000270() {}
};

/* derived name: free a block of numBytes bytes on the thread's heap (the
 * memory router at %fs-relative 0x16d80b8, its heap at +0x58, slot 3). The
 * size comes as operator delete's, kept whole in a 64-bit register to the
 * call (0xbcf4) and narrowed to the int the allocator takes. */
void FUN_0000bcf0(void *block, unsigned long numBytes);

/* derived name: a block of numBytes bytes from the thread's heap (the same
 * router's heap, slot 2; the size an operator new's, narrowed to the int the
 * allocator takes). */
void *FUN_0000bcc0(unsigned long numBytes);

/* Its vtable 0x168cb60 (address point 0x168cb70): slot 0 the empty
 * FUN_00006660, slot 1 the deleting destructor FUN_000066e0, slot 2
 * hkBaseObject's, slot 3 the class getter's default FUN_000042d0 (no
 * class), slot 4 FUN_000069a0. The destructor is inline (a derived class's
 * base destructor calls nothing, 0x90450), so the vtable and the deleting
 * destructor are emitted with the key function, slot 4. */
class hkReferencedObject : public hkBaseObject
{
  public:
    hkReferencedObject(hkFinishLoadedObjectFlag flag) : hkBaseObject(flag) {}

    /* A new object: size unknown, one reference. */
    hkReferencedObject() : memSizeAndRefCount(0xffff0001) {}

    virtual ~hkReferencedObject() {}

    /* One more reference, counted only on an object with a known size (a
     * loaded object's size is zero and it is never freed): the low 16 bits
     * incremented by compare-and-swap, the size kept (0xacf10). derived
     * name. */
    void addReference() const
    {
        if ((memSizeAndRefCount & 0xffff0000) != 0) {
            /* volatile: other threads change the count between the reads,
             * so each attempt reads it again (0xacf20 reloads it). */
            volatile u32 *count = &memSizeAndRefCount;
            u32 oldValue, newValue;
            do {
                oldValue = *count;
                newValue = (oldValue & 0xffff0000) | u16(oldValue + 1);
            } while (__sync_val_compare_and_swap(count, oldValue, newValue) != oldValue);
        }
    }

    /* The class allocator: a new object comes from the thread's heap
     * (0x9c29), and placement stays available beside it; a deleted object
     * goes back to the heap at the class's size. */
    static void *operator new(unsigned long numBytes)
    {
        return FUN_0000bcc0(numBytes);
    }

    static void *operator new(unsigned long, void *where)
    {
        return where;
    }

    static void operator delete(void *object)
    {
        if (object) {
            FUN_0000bcf0(object, sizeof(hkReferencedObject));
        }
    }

    /* Slot 3: the object's reflected class. The default (the shared
     * FUN_000042d0) has none; a reflected class returns its hkClass (slot 3
     * of hknpCompoundShape's vtable, FUN_000418b0, returns 0x57c2e78).
     * derived name. */
    virtual const hkClass *getClassType() const
    {
        return 0;
    }

    /* Slot 4 of the reference-counted classes' vtables (FUN_000069a0, the
     * body behind it in most of them), the class's key function: the object
     * deletes itself through its deleting destructor; the reference release
     * at 0x44e86 calls slot 4 when the count reaches zero. derived name. */
    virtual void FUN_000069a0() const;

    /* mutable: a const object still takes references. */
    mutable u32 memSizeAndRefCount;
};

/* hkReferencedObjectLock, the singleton registered by that name (record
 * 0x57b7b58, instance 0x57b7b50, created by 0x6800: vtable address point
 * 0x168cb00, 0x30 bytes, a critical section at +0x20 with spin count 4000).
 * The int at +0xc (1 on creation) is the lock mode: FUN_00006950 sets it to 1
 * when worker threads start (0x70c6) and to 0 when they stop (0x7499); the
 * getter 0x6970 has no row. */
class hkReferencedObjectLock : public hkReferencedObject
{
  public:
    virtual ~hkReferencedObjectLock();

    int lockMode; /* derived name */
};

extern hkReferencedObjectLock *D_57b7b50; /* hkReferencedObjectLock's instance */

/* hkDummySingleton, the singleton registered by that name (record 0x57b80d0
 * filled by 0x9c50 on the list at 0x57b80b8, instance pointer 0x57b80c8):
 * 0x10 bytes, vtable 0x168d2b0 (no type info; slots 0 and 5 the empty
 * 0x8d60, slot 1 hkReferencedObject's deleting destructor). */
class hkDummySingleton : public hkReferencedObject
{
  public:
    hkDummySingleton() {}

    virtual ~hkDummySingleton();
};

/* Its create function, the record's (0x9c20). derived name. */
hkReferencedObject *FUN_00009c20(); /* derived name */

/* hkError, the singleton registered by that name (record 0x57af770 built by
 * 0x1010, instance pointer 0x57af768; hkError.cpp's FUN_00000ee0 reports
 * through it): slot 5 takes a message's kind, its id, the description, the
 * file and the line, and returns nonzero when the caller should stop
 * (0xfbc tests it before an int3). The free functions 0x14c50, 0x14c70 and
 * 0x14cb0 pass kinds 0, 1 and 3. */
class hkError : public hkReferencedObject
{
  public:
    enum Message /* derived name */
    {
        MESSAGE_REPORT,  /* derived name */
        MESSAGE_WARNING, /* derived name */
        MESSAGE_ASSERT,  /* derived name */
        MESSAGE_ERROR,   /* derived name */
    };

    virtual int message(Message kind, int id, const char *description, const char *file,
                        int line); /* vtable slot 5; derived name */

    static int FUN_00014c50(int id, const char *description, const char *file,
                            int line); /* derived name */
    static int FUN_00014c70(int id, const char *description, const char *file,
                            int line); /* derived name */
    static int FUN_00014cb0(int id, const char *description, const char *file,
                            int line); /* derived name */
};

extern hkError *D_57af768; /* hkError's instance */

/* A string pointer whose finish constructor (FUN_0000e5c0, empty) and
 * destructor (FUN_0000e5d0, frees the string when bit 0 of the pointer marks
 * it owned) are out of line. */
/* The string library's length (derived name; a wrapper over strlen). */
int FUN_00017fe0(const char *s); /* derived name */
/* The string library's comparison (derived name; a wrapper over strcmp,
 * 0x17f40). */
int FUN_00017f40(const char *a, const char *b); /* derived name */
/* Whether a string ends with a suffix (0x181c0; derived name): both
 * lengths taken with strlen, then the tail compared. */
hkBool FUN_000181c0(const char *string, const char *suffix); /* derived name */
/* Whether a directory entry's name passes a listing's pattern (0x1a770,
 * called at 0x1bf00 after each sceFiosDHReadSync): never an empty name, "."
 * or "..", every name without a pattern, else the names ending with what
 * follows the pattern's first character. derived name. */
bool FUN_0001a770(const char *name, const char *pattern); /* derived name */

struct hkStringPtr {
    /* The string's length, 0 for a null string (callers 0x8965, 0x7778a).
     * derived name. */
    int FUN_0000e770() const;

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

/* A growable character buffer (derived name): 128 characters in place
 * (0x90 bytes; the constructor 0x11690 points the array at +0x10).
 * FUN_000116c0 assigns a C string to it (length, grow through the
 * allocator, copy), FUN_00011900 formats into it. */
struct hkStringBuf /* derived name */
{
    hkStringBuf(const hkStringPtr &source);

    /* The characters' length, without the terminator the array holds. */
    int getLength() const
    {
        return string.size - 1;
    }

    /* Every letter A to Z made lower case, in place (0x11db0; the image
     * loader lowers a file's extension with it at 0x1885b5). derived
     * name. */
    void FUN_00011db0();

    hkInplaceArray<char, 128> string; /* derived name */
};

void FUN_000116c0(hkStringBuf *self, const char *string); /* derived name */

/* The default constructor: a null string (called on each new element by the
 * array growers at 0xc93b to 0xcb23, and by 0x3a575, 0x6c66c, 0x17f386). */
void FUN_0000e3d0(hkStringPtr *self); /* derived name */

/* The assignment: the other's string, copied when the other owns it
 * (0xe6c0). derived name. */
void FUN_0000e6c0(hkStringPtr *self, const hkStringPtr *other); /* derived name */

/* The string library's byte copy, a wrapper over memcpy (0x17e70). */
void FUN_00017e70(void *dst, const void *src, unsigned int n); /* derived name */

/* An XML reader (derived name; vtable 0x16a6aa0, address point 0x16a6ab0,
 * no type info), 0x28 bytes: hkSerializeDeprecated's slot 10 (0x19a4d0)
 * builds one on its stack (0x19a501, the constructor 0x19d8e0) and
 * destroys it (0x19da00, slot 0; slot 1 the deleting destructor 0x19d920).
 * Slot 5 (0x19da90) reads the next node of a stream into a pointer: a
 * reference-counted node whose kind at +0xc is 1 for an element and whose
 * name at +0x10 the caller compares with "hkpackfile". An array at +0x10
 * and a string at +0x20, both empty to begin with. */
class hkXmlParser : public hkReferencedObject /* derived name */
{
  public:
    hkXmlParser();
    virtual ~hkXmlParser();

    hkArray<void *> pendingNodes; /* derived name */
    hkStringPtr lastError;        /* derived name */
};

/* hkxEnvironment::Variable (type info "hkxEnvironmentVariable" 0x57c8100,
 * hkClass 0x57c80b0, both built by 0x8da60: size 0x10, no vtable; member
 * records at 0x16a2950): name and value, string
 * pointers at +0 and +8. Its finish callback is FUN_0008d9e0, its cleanup
 * callback FUN_0008da10 (hkMemoryResourceHandle::ExternalLink's type info,
 * 0x57c8620, cites the same two). */
struct hkxEnvironmentVariable {
    hkxEnvironmentVariable(hkFinishLoadedObjectFlag flag)
    {
        FUN_0000e5c0(&name, flag);
        FUN_0000e5c0(&value, flag);
    }

    hkStringPtr name;
    hkStringPtr value;
};

void FUN_0008d9e0(void *object, int finishing); /* derived name */
void FUN_0008da10(void *object);                /* derived name */

/* derived names: the string set from a C string of a given length (-1: up
 * to its terminator), copied into owned storage and the old one freed when
 * owned (FUN_0000e450); the constructor from a string (FUN_0000e540) starts
 * from a null string and sets it. */
void FUN_0000e450(hkStringPtr *self, const char *string, int length); /* derived name */
void FUN_0000e540(hkStringPtr *self, const char *string, int length); /* derived name */

/* Sets the string from (string, length): drops an owned copy, then stores a
 * new one (copied through the arena of the thread's block) or null; the
 * constructor at 0xe540 clears the pointer and tail-calls it. */
void FUN_0000e450(hkStringPtr *self, const char *string, int length); /* derived name */

/* Assigns a C string: unless it is the one held, drops an owned copy and
 * stores an owned copy of the new one (or null); returns the pointer. */
hkStringPtr *FUN_0000e620(hkStringPtr *self, const char *string); /* derived name */

/* What a load or save reports when it fails (derived names): an error id at
 * +0 (0: none yet) and a message at +8. The deprecated serializer's stubs set
 * id 7 and their message when nothing was reported before. */
struct SerializeErrorDetails /* derived name */
{
    int id;                     /* derived name */
    hkStringPtr defaultMessage; /* derived name */
};

/* hkSerializeDeprecated, the singleton registered by that name (record
 * 0x57c8a40 filled by 0x19a680; its create function 0x19a5f0 builds a static
 * instance at 0x57c8a08 with the vtable 0x16a6860, address point 0x16a6870,
 * and returns it with a reference added). This build links the stub, whose
 * slots fail with "Packfile versioning support is not linked..." (0x14cca20):
 * slot 6 (0x19a450) takes six arguments, the error details last, and returns
 * 1; slots 8 and 9 share 0x19a490, three arguments, the error details last,
 * returning null; slot 10 (0x19a4d0) reads an XML header. */
/* The stub's message (0x14cca20, "Packfile versioning support is not
 * linked...", 631 characters with its advice), referenced by its address: the
 * text is the executable's. */
extern const char D_14cca20[];

/* The XML save's message (0x14cc986, "XML packfile support is not
 * linked...", 118 characters), referenced by its address likewise. */
extern const char D_14cc986[];

class hkSerializeDeprecated : public hkReferencedObject
{
  public:
    /* Slot 6: the stub's XML save (five arguments before the error
     * record, the last on the stack; their types not recovered). */
    hkResult FUN_0019a450(const void *object, const void *klass, void *writer, const void *options,
                          void *listener,
                          SerializeErrorDetails *errorOut); /* vtable slot 6; derived name */
    void *FUN_0019a490(void *reader, const void *details,
                       SerializeErrorDetails *errorOut); /* vtable slots 8 and 9; derived name */
};

/* The polymorphic table of color pairs; its vtable is 0x168c1b0 (its finish
 * callback FUN_000002c0 stores 0x168c1c0), its destructor the first slot. */
class hkMonitorStreamColorTable : public hkReferencedObject
{
  public:
    hkMonitorStreamColorTable(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

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
 * 0x168d870 and leaves the uuid as loaded); the finish callback 0x3eb0
 * calls it by its address. */
class hkUuidObject : public hkReferencedObject
{
  public:
    hkUuidObject(hkFinishLoadedObjectFlag flag);

    hkUuid uuid;
};

void FUN_0000dc40(hkUuidObject *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* hkRefCountedProperties, 16 bytes: entries, an array (type 0x16) of
 * hkRefCountedProperties::Entry, at +0 (type info at 0x57b85d8, registered
 * by the initializer at 0xd390). Its finish constructor (FUN_0001c1e0,
 * empty) and destructor (FUN_0001c1f0, releases each entry) are out of
 * line. */
struct hkRefCountedProperties {
    /* 16 bytes: the referenced object at +0 (FUN_0001c1f0 drops a reference
     * on each) and the key at +8 that FUN_0001c2c0 searches by. */
    struct Entry {
        hkReferencedObject *object; /* derived name */
        u16 key;                    /* derived name */
        u8 unknownA[6];
    };

    /* Out of line at 0x1c1b0: the callers at 0x38551 and 0x44c93
     * allocate the 16 bytes from the thread's allocator and construct. */
    hkRefCountedProperties();

    /* The object under a key, the last entry first (0x1c550; the shapes ask
     * for key 0xf100 at 0x384be and 0x157118); null when none has it.
     * derived name. */
    hkReferencedObject *FUN_0001c550(u16 key) const;

    hkArray<Entry> entries;
};

void FUN_0001c1e0(hkRefCountedProperties *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0001c1f0(hkRefCountedProperties *self);                                /* derived name */

/* hkSimpleLocalFrame, polymorphic (vtable 0x168d8e0, address point
 * 0x168d8f0, stored by its finish callback 0x37f0; complete destructor
 * 0xde20, which releases the children and the group and frees the name):
 * members from its record table at 0x168c7d0, transform (type 0x12) at
 * +0x10, children (array of pointers) at +0x50, parentFrame (pointer) at
 * +0x60, group (pointer) at +0x68, name (hkStringPtr) at +0x70. Slots 5 to
 * 7 (FUN_0000df30, 0xdf60, FUN_0000df90) copy the transform out and in and
 * the translation row out, slot 9 (FUN_0000dcb0) returns the name (also
 * slot 20 of hkMemoryMeshBody, whose name sits at the same offset), slots
 * 10 and 11 read and set the parent frame, slot 12 (FUN_0000e160) returns
 * the child count and slot 13 (FUN_0000e170) a child by index. */
/* hkStringObject (hkClass 0x57b91b8, built at 0x10992: size 0x18, parent
 * hkReferencedObject's 0x57b8640, one member record at 0x168e120): string
 * (hkStringPtr) at +0x10. The finish callback 0x108e0 constructs it in
 * place; the complete destructor 0x10850 destroys the string. */
class hkStringObject : public hkReferencedObject
{
  public:
    hkStringObject(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag)
    {
        FUN_0000e5c0(&string, flag);
    }

    virtual ~hkStringObject();

    hkStringPtr string;
};

struct hkLocalFrame;

/* hkLocalFrameGroup (hkClass 0x57b76f0, built at 0x3914: size 0x18, parent
 * hkReferencedObject's 0x57b8640, one member record at 0x168c7a0): name
 * (hkStringPtr) at +0x10. The finish callback 0x37b0 constructs it in
 * place; the complete destructor 0x3710 destroys the name. */
class hkLocalFrameGroup : public hkReferencedObject
{
  public:
    hkLocalFrameGroup(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag)
    {
        FUN_0000e5c0(&name, flag);
    }

    virtual ~hkLocalFrameGroup();

    hkStringPtr name;
};

class hkSimpleLocalFrame : public hkReferencedObject
{
  public:
    hkSimpleLocalFrame(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag), children(flag)
    {
        FUN_0000e5c0(&name, flag);
    }

    void FUN_0000df30(Mat4 &out) const;          /* vtable slot 5; derived name */
    void FUN_0000df60(const Mat4 &newTransform); /* vtable slot 6; derived name */
    void FUN_0000df90(Vec4 &position) const;     /* vtable slot 7; derived name */
    const char *FUN_0000dcb0() const;            /* vtable slot 9; derived name */
    int FUN_0000e160() const;                    /* vtable slot 12; derived name */
    hkLocalFrame *FUN_0000e170(int index) const; /* vtable slot 13; derived name */

    Mat4 transform;
    hkArray<hkLocalFrame *> children;
    hkLocalFrame *parentFrame;
    hkLocalFrameGroup *group;
    hkStringPtr name;
};

/* hkcdPlanarEntity (hkClass 0x57ba190, built at 0x1d232: size 0x18,
 * parent hkReferencedObject's 0x57b8640, one member record at 0x168f3f0;
 * vtable 0x168f3b0): debugger (a pointer, not serialized: record flags
 * 0x400) at +0x10, which its finish constructor clears. The finish
 * callback 0x1d190 constructs it in place. */
class hkcdPlanarEntity : public hkReferencedObject
{
  public:
    hkcdPlanarEntity(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag), debugger(0) {}

    void *debugger;
};

/* hkcdShape (type info 0x57b9ed0, vtable 0x168f2f0): its finish
 * constructor FUN_0001cf40 is out of line, called by the finish callback
 * 0x1ca80 and by the reflection initializer at 0x1ccfe on a temporary; it
 * stores only the vtable. */
class hkcdShape : public hkReferencedObject
{
  public:
    hkcdShape(hkFinishLoadedObjectFlag flag);
};

/* hkcdPlanarGeometryPrimitivesCollection28 (type info 0x57b9e40, 0xd90
 * bytes; scoped name "hkcdPlanarGeometryPrimitivesCollection28_typename",
 * a template instance): its finish constructor is inline in its finish
 * callback FUN_0001c990 and stores only the vtable. */
class hkcdPlanarGeometryPrimitivesCollection28 : public hkReferencedObject
{
  public:
    hkcdPlanarGeometryPrimitivesCollection28(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag)
    {
    }
};

/* hkcdPlanarGeometryPolygonCollection (hkClass 0x57b9d70, built at 0x1c84f
 * with parent hkcdPlanarGeometryPrimitivesCollection28's 0x57b9df0;
 * vtable 0x16a3670): its finish constructor 0x95fb0 is out of
 * line, jumped to by the finish callback FUN_0001c7d0 and called by the
 * reflection initializer at 0x1c880. */
class hkcdPlanarGeometryPolygonCollection : public hkcdPlanarGeometryPrimitivesCollection28
{
  public:
    hkcdPlanarGeometryPolygonCollection(hkFinishLoadedObjectFlag flag);
};

/* hkcdPlanarSolid (hkClass 0x57ba410, built at 0x1d880: size 0x30, parent
 * hkcdPlanarEntity's 0x57ba190, member records at 0x168f6a0; vtable
 * 0x16a3640): nodes (a pointer to its NodeStorage) at +0x18, planes (a
 * pointer to hkcdPlanarGeometryPlanesCollection) at +0x20, rootNodeId
 * (hkUint32) at +0x28. Its finish constructor 0x95800 is out of line (the
 * finish callback 0x1d680 jumps to it, the reflection initializer at
 * 0x1d88c runs it on a temporary): the entity's clears the debugger before
 * the vtable is stored. Its nested NodeStorage (type info 0x57ba3b0, scoped
 * name "hkcdPlanarSolid::NodeStorage", 0x38 bytes) has a finish
 * constructor inline in its finish callback FUN_0001d620 that stores only
 * the vtable. */
class hkcdPlanarGeometryPlanesCollection;

class hkcdPlanarSolid : public hkcdPlanarEntity
{
  public:
    class NodeStorage;

    hkcdPlanarSolid(hkFinishLoadedObjectFlag flag);

    NodeStorage *nodes;
    hkcdPlanarGeometryPlanesCollection *planes;
    u32 rootNodeId;
};

/* hkcdPlanarCsgOperand (hkClass 0x57ba210, built at 0x1d335: size 0x28,
 * parent hkReferencedObject's, member records at 0x168f420; vtable
 * 0x16a3740): solid (a pointer to hkcdPlanarSolid) at +0x10,
 * danglingGeometry (a pointer to hkcdPlanarGeometry) at +0x18, regions (a
 * pointer, not serialized: record flags 0x400) at +0x20, which the finish
 * constructor clears. That constructor (0x9c0a0) is out of line: the finish
 * callback 0x1d290 jumps to it, the reflection initializer at 0x1d341 runs
 * it on a temporary. */
struct hkcdPlanarGeometry;

class hkcdPlanarCsgOperand : public hkReferencedObject
{
  public:
    hkcdPlanarCsgOperand(hkFinishLoadedObjectFlag flag);

    hkcdPlanarSolid *solid;
    hkcdPlanarGeometry *danglingGeometry;
    void *regions;
};

/* hkcdPlanarGeometry (hkClass 0x57ba110, built at 0x1d005: parent
 * hkcdPlanarEntity's 0x57ba190, member records at 0x168f330; vtable
 * 0x16a36f0): planes (a pointer to hkcdPlanarGeometryPlanesCollection) at
 * +0x18, polys (a pointer to hkcdPlanarGeometryPolygonCollection) at +0x20,
 * vertices (a pointer, not serialized: record flags 0x400) at +0x28. Its
 * finish constructor 0x9a860 is out of line (the finish callback
 * FUN_0001cf60 jumps to it, the reflection initializer at 0x1d010 runs it
 * on a temporary); a finished geometry runs FUN_0009a8a0 with 0. */
struct hkcdPlanarGeometry : public hkcdPlanarEntity {
    hkcdPlanarGeometry(hkFinishLoadedObjectFlag flag);
    virtual ~hkcdPlanarGeometry();

    /* 0x9a8a0, a large member (derived name). */
    void FUN_0009a8a0(int argument);

    hkcdPlanarGeometryPlanesCollection *planes;
    hkcdPlanarGeometryPolygonCollection *polys;
    void *vertices;
};

class hkcdPlanarSolid::NodeStorage : public hkReferencedObject
{
  public:
    NodeStorage(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* Reference-counted classes whose finish constructors are inline in their
 * finish callbacks and store only the vtable (vtable, callback): */
/* hknpDynamicCompoundShapeData: vtable 0x1692990, finish callback FUN_000343e0. */
class hknpDynamicCompoundShapeData : public hkReferencedObject
{
  public:
    hknpDynamicCompoundShapeData(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hknpStaticCompoundShapeData: vtable 0x1692950, finish callback FUN_00034440. */
class hknpStaticCompoundShapeData : public hkReferencedObject
{
  public:
    hknpStaticCompoundShapeData(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hknpCompressedMeshShapeInternals (its own members not yet read) and its
 * nested KeyMask (scoped name "hknpCompressedMeshShapeInternals::KeyMask",
 * vtable 0x1692ab0, finish callback FUN_00034e00; defined after
 * hknpShapeKeyMask, its parent). */
struct hknpCompressedMeshShapeInternals {
    class KeyMask;
};

/* hknpVehicleDefaultVelocityDamper: vtable 0x1695890, finish callback FUN_00035c60. */
class hknpVehicleDefaultVelocityDamper : public hkReferencedObject
{
  public:
    hknpVehicleDefaultVelocityDamper(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hknpCharacterRigidBodyCinfo: vtable 0x1692f70, finish callback FUN_000361c0. */
class hknpCharacterRigidBodyCinfo : public hkReferencedObject
{
  public:
    hknpCharacterRigidBodyCinfo(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hknpMaterialPalette: vtable 0x16937b0, finish callback FUN_000377c0. */
class hknpMaterialPalette : public hkReferencedObject
{
  public:
    hknpMaterialPalette(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hknpVehicleDriverInputAnalogStatus: vtable 0x16a4420, finish callback
 * FUN_000378e0; members (records from 0x16938c0) positionX and positionY
 * (floats) at +0xc and +0x10, handbrakeButtonPressed and
 * reverseButtonPressed (hkBool) at +0x14 and +0x15. */
class hknpVehicleDriverInputAnalogStatus : public hkReferencedObject
{
  public:
    hknpVehicleDriverInputAnalogStatus(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    float positionX;
    float positionY;
    hkBool handbrakeButtonPressed;
    hkBool reverseButtonPressed;
};

class hknpVehicleInstance;

/* hknpVehicleDefaultAnalogDriverInput: vtable 0x16a43c0, finish callback
 * FUN_000378b0; members (records from 0x1693820) slopeChangePointX,
 * initialSlope and deadZone (floats) at +0xc to +0x14, autoReverse (hkBool)
 * at +0x18. Slot 7 (FUN_00151de0) is the brake input. */
class hknpVehicleDefaultAnalogDriverInput : public hkReferencedObject
{
  public:
    hknpVehicleDefaultAnalogDriverInput(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    float FUN_00151de0(
        const hknpVehicleInstance *vehicle,
        const hknpVehicleDriverInputAnalogStatus *status) const; /* vtable slot 7; derived name */

    float slopeChangePointX;
    float initialSlope;
    float deadZone;
    hkBool autoReverse;
};

/* What a transmission's slot 5 (0x67f40) fills (derived names): two floats
 * from slots 6 and 7 at +4 and +0, the per-wheel torques at +8 (a pointer),
 * the answer of slot 8 at +0x11 and the gear (s8) slot 8 and slot 10 read at
 * +0x12; the vehicle instance keeps its own isReversing and currentGear
 * (+0x118, +0x119). */
struct hknpVehicleTransmissionOutput /* derived name */
{
    u8 unknown0[0x11];
    hkBool isReversing; /* derived name */
    s8 currentGear;     /* derived name */
    /* Set while the gear changes: slot 6 (0x67ffc) passes no torque then.
     * derived name. */
    hkBool isInGearChange;
};

/* hknpVehicleDefaultTransmission: vtable 0x1699b90, finish callback FUN_00037a90. */
class hknpVehicleDefaultTransmission : public hkReferencedObject
{
  public:
    hknpVehicleDefaultTransmission(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), gearsRatio(flag), wheelsTorqueRatio(flag)
    {
    }

    /* Slots 5 to 10 (0x67f40, 0x67ff0, 0x68030, 0x68130, 0x680b0,
     * 0x67ef0); slot 6 asks slot 10 for the ratio through the vtable. */
    virtual void unknownVirtual5();
    /* Slot 6: the torque passed on, none while the gear changes. derived
     * name. */
    virtual float FUN_00067ff0(const hknpVehicleInstance *vehicle,
                               const hknpVehicleTransmissionOutput &output) const;
    virtual void unknownVirtual7();
    virtual bool FUN_00068130(
        const hknpVehicleInstance *vehicle,
        const hknpVehicleTransmissionOutput &output) const; /* vtable slot 8; derived name */
    virtual void unknownVirtual9();
    virtual float FUN_00067ef0(
        const hknpVehicleInstance *vehicle,
        const hknpVehicleTransmissionOutput &output) const; /* vtable slot 10; derived name */

    /* Members from the records at 0x1693960. */
    float downshiftRPM;
    float upshiftRPM;
    float primaryTransmissionRatio;
    float clutchDelayTime;
    float reverseGearRatio;
    hkArray<float> gearsRatio;
    hkArray<float> wheelsTorqueRatio;
};

/* hknpVehicleDefaultAerodynamics: vtable 0x1695ac0, finish callback
 * FUN_0003a0d0. Members from its records (0x1695170 onward): airDensity,
 * frontalArea, dragCoefficient and liftCoefficient (floats) from +0xc,
 * extraGravityws (a vector) at +0x20. Slot 6 (0x3bf20) is the drag at a
 * speed, slot 7 (FUN_0003bf60) the lift. */
class hknpVehicleDefaultAerodynamics : public hkReferencedObject
{
  public:
    hknpVehicleDefaultAerodynamics(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    float FUN_0003bf20(float speed) const; /* vtable slot 6; derived name */
    float FUN_0003bf60(float speed) const; /* vtable slot 7; derived name */

    float airDensity;
    float frontalArea;
    float dragCoefficient;
    float liftCoefficient;
};

/* hknpGroupCollisionFilter: vtable 0x16952a0, finish callback FUN_0003a3b0. */
class hknpGroupCollisionFilter : public hkReferencedObject
{
  public:
    hknpGroupCollisionFilter(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516: vtable 0x1695240, finish callback FUN_0003a3d0. */
class hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516
    : public hkReferencedObject
{
  public:
    hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516(
        hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag)
    {
    }
};

/* hknpSurfaceVelocity (hkClass 0x57c19d8, 0x10 bytes, parent
 * hkReferencedObject): slot 5 gives the velocities of the surface at a
 * point, the linear one and the angular one through the last two
 * arguments (the surface velocity modifier asks for them at 0x16d200; the
 * two arguments between are not read by the circular one). derived names. */
class hknpSurfaceVelocity : public hkReferencedObject
{
  public:
    hknpSurfaceVelocity(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    virtual void calcVelocities(const hkVector4 &position, const void *argument2,
                                const void *argument3, hkVector4 *HK_RESTRICT linearVelocityOut,
                                hkVector4 *HK_RESTRICT angularVelocityOut) const = 0;
};

/* hknpCircularSurfaceVelocity: vtable 0x16a4f50, finish callback
 * FUN_0003af50; hkClass built at 0x3afe2 (0x30 bytes, parent
 * hknpSurfaceVelocity), records from 0x1695810: velocityIsLocalSpace
 * (hkBool) at +0xc, pivot and angularVelocity (vectors) at +0x10 and
 * +0x20. */
class hknpCircularSurfaceVelocity : public hknpSurfaceVelocity
{
  public:
    hknpCircularSurfaceVelocity(hkFinishLoadedObjectFlag flag) : hknpSurfaceVelocity(flag) {}

    /* Slot 5 (0x15fa60): the angular velocity everywhere, the linear one
     * that velocity's cross product with the point's offset from the
     * pivot. */
    void calcVelocities(const hkVector4 &position, const void *argument2, const void *argument3,
                        hkVector4 *HK_RESTRICT linearVelocityOut,
                        hkVector4 *HK_RESTRICT angularVelocityOut) const;

    hkBool velocityIsLocalSpace;
    hkVector4 pivot;
    hkVector4 angularVelocity;
};

/* hknpLinearSurfaceVelocity: vtable 0x16a4bb0, finish callback FUN_0003d520. */
class hknpLinearSurfaceVelocity : public hkReferencedObject
{
  public:
    hknpLinearSurfaceVelocity(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hknpVehicleDefaultSuspension: vtable 0x16a4040, finish callback FUN_0003e590. */
class hknpVehicleDefaultSuspension : public hkReferencedObject
{
  public:
    hknpVehicleDefaultSuspension(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hknpBodyReference: vtable 0x1696d20, finish callback FUN_0003f520. */
class hknpBodyReference : public hkReferencedObject
{
  public:
    hknpBodyReference(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hknpVehicleEngine, hknpVehicleBrake and hknpVehicleSteering: the
 * abstract vehicle components (hkClass 0x57bff60, 0x57c26f8 and 0x57c1988,
 * each 0x10 bytes with hkReferencedObject as its parent and no type info of
 * its own). */
class hknpVehicleEngine : public hkReferencedObject
{
  public:
    hknpVehicleEngine(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hknpVehicleBrake : public hkReferencedObject
{
  public:
    hknpVehicleBrake(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hknpVehicleSteering : public hkReferencedObject
{
  public:
    hknpVehicleSteering(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hknpVehicleDefaultEngine (hkClass 0x57c1310, 0x38 bytes, parent
 * hknpVehicleEngine): vtable 0x16a4d90, finish callback FUN_00046b70. */
class hknpVehicleDefaultEngine : public hknpVehicleEngine
{
  public:
    hknpVehicleDefaultEngine(hkFinishLoadedObjectFlag flag) : hknpVehicleEngine(flag) {}
};

/* hknpVehicleDefaultBrake (parent hknpVehicleBrake): vtable 0x16a5350,
 * finish callback FUN_0005b300. */
class hknpVehicleDefaultBrake : public hknpVehicleBrake
{
  public:
    hknpVehicleDefaultBrake(hkFinishLoadedObjectFlag flag) : hknpVehicleBrake(flag) {}
};

/* hknpRefMassDistribution (parent hkReferencedObject): vtable 0x169a820,
 * finish callback FUN_00069a80. */
class hknpRefMassDistribution : public hkReferencedObject
{
  public:
    hknpRefMassDistribution(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hknpVehicleDefaultSteering (parent hknpVehicleSteering): vtable 0x16a5750,
 * finish callback FUN_00077d60. */
class hknpVehicleDefaultSteering : public hknpVehicleSteering
{
  public:
    hknpVehicleDefaultSteering(hkFinishLoadedObjectFlag flag) : hknpVehicleSteering(flag) {}
};

/* Classes reflected with hkReferencedObject as their parent whose finish
 * constructors have nothing to fix up but the vtable (hkClass, vtable,
 * finish callback): hkpVehicleFrictionDescription (0x57c5cf8, 0x169a0d0,
 * FUN_00085110), hkxSpline (0x57c5f80, 0x16a0880, FUN_00085fa0),
 * hkxAnimatedVector (0x57c6580, 0x16a0d00, FUN_00086d70),
 * hkxTriangleSelectionChannel (0x57c6650, 0x16a0d40, FUN_00087000),
 * hkxVertexVectorDataChannel (0x57c66d0, 0x16a0df0, FUN_00087490) and
 * hkxSparselyAnimatedString (0x57c6750, 0x16a0e60, FUN_00087750),
 * hkxVertexFloatDataChannel (0x57c6850, 0x16a0fb0, FUN_00087b50),
 * hkxVertexIntDataChannel (0x16a1260, FUN_000880f0), hkxIndexBuffer
 * (0x57c6aa0, 0x16a12d0, FUN_00088330), hkxAnimatedQuaternion (0x16a1390,
 * FUN_000886d0), hkxSparselyAnimatedInt (0x57c6c68, 0x16a1400,
 * FUN_00088900), hkxEdgeSelectionChannel (0x16a14e0, FUN_00088cb0),
 * hkxAnimatedMatrix (0x57c6df0, 0x16a1550, FUN_00088e80), hkxEnum
 * (0x16a16f0, FUN_000898f0), hkxCamera (0x16a1a70, FUN_0008a270),
 * hkxAttributeHolder (0x16a1670, FUN_0008b390), hkxVertexSelectionChannel
 * (0x16a2500, FUN_0008bcd0) and hkxBlob (0x16a07f0, FUN_0008bdc0);
 * hkxSparselyAnimatedEnum (0x16a16b0, FUN_00089920) has
 * hkxSparselyAnimatedInt as its parent. */
class hkpVehicleFrictionDescription : public hkReferencedObject
{
  public:
    hkpVehicleFrictionDescription(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hknpVehicleData (type info 0x57c22f8 built by 0x69290: size 0x1b0,
 * vtable 0x169ace0, finish callback FUN_00069250; members from its record
 * table at 0x169a2a0): gravity at +0x10, numWheels (hkInt8) at +0x20,
 * chassisOrientation (a rotation) at +0x30, eleven floats from
 * torqueRollFactor at +0x60 to maxFrictionSolverMassRatio at +0x88,
 * wheelParams and numWheelsPerAxle (arrays) at +0x90 and +0xa0,
 * frictionDescription (an hkpVehicleFrictionDescription) at +0xb0; then
 * chassisFrictionInertiaInvDiag at +0x190 and alreadyInitialised at +0x1a0,
 * not typed here. */
struct hknpVehicleDataWheelComponentParams;

class hknpVehicleData : public hkReferencedObject
{
  public:
    hknpVehicleData(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), wheelParams(flag), numWheelsPerAxle(flag),
          frictionDescription(flag)
    {
    }

    virtual ~hknpVehicleData();

    Vec4 gravity;
    s8 numWheels;
    hkMatrix3 chassisOrientation;
    float torqueRollFactor;
    float torquePitchFactor;
    float torqueYawFactor;
    float extraTorqueFactor;
    float maxVelocityForPositionalFriction;
    float chassisUnitInertiaYaw;
    float chassisUnitInertiaRoll;
    float chassisUnitInertiaPitch;
    float frictionEqualizer;
    float normalClippingAngleCos;
    float maxFrictionSolverMassRatio;
    hkArray<hknpVehicleDataWheelComponentParams> wheelParams;
    hkArray<s8> numWheelsPerAxle;
    hkpVehicleFrictionDescription frictionDescription;
};

void FUN_00069250(void *object, int finishing); /* derived name */

class hkxSpline : public hkReferencedObject
{
  public:
    hkxSpline(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hkxAnimatedVector : public hkReferencedObject
{
  public:
    hkxAnimatedVector(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hkxTriangleSelectionChannel : public hkReferencedObject
{
  public:
    hkxTriangleSelectionChannel(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hkxVertexVectorDataChannel : public hkReferencedObject
{
  public:
    hkxVertexVectorDataChannel(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hkxSparselyAnimatedBool (type info 0x57c8280, size 0x30, hkClass parent
 * hkReferencedObject, built at 0x8e2fd): the finish callback FUN_0008e280
 * runs the inline finish constructor, nothing to fix up but the vtable. */
class hkxSparselyAnimatedBool : public hkReferencedObject
{
  public:
    hkxSparselyAnimatedBool(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hkxSparselyAnimatedString : public hkReferencedObject
{
  public:
    hkxSparselyAnimatedString(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hkxVertexFloatDataChannel : public hkReferencedObject
{
  public:
    hkxVertexFloatDataChannel(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hkxVertexIntDataChannel : public hkReferencedObject
{
  public:
    hkxVertexIntDataChannel(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hkxIndexBuffer : public hkReferencedObject
{
  public:
    hkxIndexBuffer(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hkxAnimatedQuaternion : public hkReferencedObject
{
  public:
    hkxAnimatedQuaternion(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hkxSparselyAnimatedInt : public hkReferencedObject
{
  public:
    hkxSparselyAnimatedInt(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hkxEdgeSelectionChannel : public hkReferencedObject
{
  public:
    hkxEdgeSelectionChannel(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hkxAnimatedMatrix : public hkReferencedObject
{
  public:
    hkxAnimatedMatrix(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hkxEnum : public hkReferencedObject
{
  public:
    hkxEnum(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hkxCamera : public hkReferencedObject
{
  public:
    hkxCamera(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hkxAttributeHolder (hkClass 0x57c76b0, built at 0x8b422: size 0x20,
 * parent hkReferencedObject's 0x57b8640, one member record at 0x16a1f70):
 * attributeGroups (an array of hkxAttributeGroup, class 0x57c6ce8) at
 * +0x10. */
struct hkxAttributeGroup;

class hkxAttributeHolder : public hkReferencedObject
{
  public:
    hkxAttributeHolder(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), attributeGroups(flag)
    {
    }

    /* Out of line (0x89380): the groups destroyed and freed. */
    virtual ~hkxAttributeHolder();

    hkArray<hkxAttributeGroup> attributeGroups;
};

/* hkxMaterial (hkClass 0x57c61d0, built at 0x86bf1: size 0xe0, parent
 * hkxAttributeHolder's; its member records are written at run time from
 * 0x57c6220, name (hkStringPtr) first, then stages, the four colours,
 * subMaterials, extraData and the rest): the finish callback 0x86350 finishes
 * only the name at +0x20. */
class hkxMaterial : public hkxAttributeHolder
{
  public:
    hkxMaterial(hkFinishLoadedObjectFlag flag) : hkxAttributeHolder(flag)
    {
        FUN_0000e5c0(&name, flag);
    }

    hkStringPtr name;
};

/* hkxMaterialEffect (hkClass 0x57c7140, built at 0x89e36: size 0x30,
 * parent hkReferencedObject's; member records written at run time from
 * 0x57c71c0: name, type, data): the finish callback 0x89c70 finishes the
 * name at +0x10. */
class hkxMaterialEffect : public hkReferencedObject
{
  public:
    hkxMaterialEffect(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag)
    {
        FUN_0000e5c0(&name, flag);
    }

    hkStringPtr name;
    u8 unknown18[0x18];
};

/* hkxNodeSelectionSet (hkClass 0x57c75b0, built at 0x8afe5: size 0x38,
 * parent hkxAttributeHolder's, member records at 0x16a1eb0): selectedNodes
 * (an array of pointers to hkxNode, class 0x57c77b0) at +0x20, name
 * (hkStringPtr) at +0x30. The finish callback 0x8af30 finishes the name. */
struct hkxNode;

class hkxNodeSelectionSet : public hkxAttributeHolder
{
  public:
    hkxNodeSelectionSet(hkFinishLoadedObjectFlag flag)
        : hkxAttributeHolder(flag), selectedNodes(flag)
    {
        FUN_0000e5c0(&name, flag);
    }

    hkArray<hkxNode *> selectedNodes;
    hkStringPtr name;
};

class hkxVertexSelectionChannel : public hkReferencedObject
{
  public:
    hkxVertexSelectionChannel(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hkxBlob (hkClass 0x57c7a80, built at 0x8be52: size 0x20, one member
 * record at 0x16a2570): data, an array of bytes, at +0x10. */
class hkxBlob : public hkReferencedObject
{
  public:
    hkxBlob(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag), data(flag) {}

    hkArray<u8> data;
};

class hkxSparselyAnimatedEnum : public hkxSparselyAnimatedInt
{
  public:
    hkxSparselyAnimatedEnum(hkFinishLoadedObjectFlag flag) : hkxSparselyAnimatedInt(flag) {}
};

/* hknpCharacterProxyCinfo: vtable 0x1696e90, finish callback FUN_00040510. */
class hknpCharacterProxyCinfo : public hkReferencedObject
{
  public:
    hknpCharacterProxyCinfo(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hknpTyremarksInfo: vtable 0x169a080, finish callback FUN_00042a20. */
class hknpTyremarksInfo : public hkReferencedObject
{
  public:
    hknpTyremarksInfo(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hknpTyremarksWheel: vtable 0x1697af0, finish callback FUN_00042a50. */
class hknpTyremarksWheel : public hkReferencedObject
{
  public:
    hknpTyremarksWheel(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hkcdSimdTree (type info 0x57bb3e0, vtable 0x1690d60): 0x18 bytes, its
 * nodes an hkArray at +8. Its finish constructor (0x21a20) is out of line:
 * the type info's finish callback FUN_0001f360 jumps to it, and
 * hknpExternMeshShapeData's finish constructor calls it on its member. */
class hkcdSimdTree
{
  public:
    hkcdSimdTree(hkFinishLoadedObjectFlag flag);
    virtual ~hkcdSimdTree();

    /* The nodes, an hkArray (size at +0x10, capacity and flags at +0x14);
     * the element type is not recovered. */
    u8 nodes[0x10]; /* derived name */
};

/* Polymorphic classes whose finish constructors are out of line, each
 * storing the class's vtable (and clearing a few members): */
class hkSkinnedRefMeshShape;     /* 0xaa660, vtable 0x16a38c0 */
class hkMemoryMeshShape;         /* 0x2a940, vtable 0x1692540 */
class hkMemoryMeshMaterial;      /* 0xaccf0, vtable 0x16a3920 */
class hkStorageSkinnedMeshShape; /* 0xae680, vtable 0x16a3b00 */
class hkMemoryMeshVertexBuffer;  /* 0x274e0, vtable 0x16921b0 */
class hknpDynamicCompoundShape;  /* 0x469a0, vtable 0x1697ef0 */
class hknpMaskedShape;           /* FUN_00037b90, vtable 0x1693a90 */

void FUN_0001cf40(hkcdShape *self, hkFinishLoadedObjectFlag flag);       /* derived name */
void FUN_00037b90(hknpMaskedShape *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* hkcdStaticAabbTree (hkClass 0x57bba10, built at 0x1fff2: size 0x18,
 * parent hkReferencedObject's; vtable 0x1690de0, address point 0x1690df0):
 * shouldDeleteTree (hkBool) at +0xc and treePtr at +0x10, from its record
 * table at 0x16903e0. Its finish constructor (0x22700) is out of line: the
 * finish callback FUN_0001ff50 jumps to it, the reflection initializer at
 * 0x1fffd calls it. A finished object owns its tree when it was allocated
 * (a memory size in the high half of +8), not loaded in place. */
class hkcdStaticAabbTree : public hkReferencedObject
{
  public:
    hkcdStaticAabbTree(hkFinishLoadedObjectFlag flag);
    virtual ~hkcdStaticAabbTree();

    hkBool shouldDeleteTree;
    void *treePtr;
};

/* hkcdDynamicAabbTree (hkClass 0x57bc890, built at 0x22592: size 0x18,
 * parent hkReferencedObject's; vtable 0x16a37b0, address point 0x16a37c0):
 * shouldDeleteTree (hkBool) at +0xc and treePtr at +0x10, from its record
 * table at 0x1690d90. Its finish constructor (0x9fc10) is out of line, as
 * the static tree's: the finish callback FUN_000224f0 jumps to it, the
 * reflection initializer at 0x2259d calls it. */
class hkcdDynamicAabbTree : public hkReferencedObject
{
  public:
    hkcdDynamicAabbTree(hkFinishLoadedObjectFlag flag);
    virtual ~hkcdDynamicAabbTree();

    hkBool shouldDeleteTree;
    void *treePtr;
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
    hkIndexedTransformSet(hkFinishLoadedObjectFlag flag);

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

/* hkVertexFormat (hkClass 0x57bcb30, size 0x104, records 0x1691160, built
 * at 0x22f48): elements (32 hkVertexFormat::Element) at +0, numElements
 * (hkInt32) at +0x100. Element (hkClass 0x57bcab0, 8 bytes, records built
 * at 0x22c81): dataType (hkEnum of ComponentType in hkUint8) at +0,
 * numValues (hkUint8) at +1, usage (hkEnum of ComponentUsage in hkUint8) at
 * +2, subUsage (hkUint8) at +3, flags (hkFlags in hkUint8) at +4, pad (3
 * hkUint8) at +5. FUN_000270a0, called on the member of each containing
 * object's constructor, empties it. */
struct hkVertexFormat {
    /* The element hints and the sharing kinds (hkClassEnum items from the
     * executable's strings at 0x14b76e4 to 0x14b7740, values from their
     * records at 0x1691350 to 0x16913b8). */
    enum HintFlags { FLAG_READ = 1, FLAG_WRITE = 2, FLAG_DYNAMIC = 4, FLAG_NOT_SHARED = 8 };

    enum SharingType { SHARING_ALL_SHARED, SHARING_ALL_NOT_SHARED, SHARING_MIXTURE };

    /* The element usages (hkClassEnum items from the strings at 0x14b7750
     * to 0x14b781a, values from their records at 0x1691280 to 0x1691340). */
    enum ComponentUsage {
        USAGE_NONE,
        USAGE_POSITION,
        USAGE_NORMAL,
        USAGE_COLOR,
        USAGE_TANGENT,
        USAGE_BINORMAL,
        USAGE_BLEND_MATRIX_INDEX,
        USAGE_BLEND_WEIGHTS,
        USAGE_BLEND_WEIGHTS_LAST_IMPLIED,
        USAGE_TEX_COORD,
        USAGE_POINT_SIZE,
        USAGE_USER,
        USAGE_LAST
    };

    /* derived name: whether none, all or some of the elements are marked
     * not shared (0x27240, called at 0x274a4). */
    SharingType FUN_00027240() const;

    /* derived name: the index of the element of a usage and sub-usage, or
     * -1 (0x27130, called at 0x25c1b and 0xae11b). */
    int FUN_00027130(ComponentUsage usage, int subUsage) const;

    struct Element {
        u8 dataType;
        u8 numValues;
        hkEnum<ComponentUsage, u8> usage;
        u8 subUsage;
        u8 flags;
        u8 pad[3];
    };

    Element elements[32];
    int numElements;
};

void FUN_000270a0(hkVertexFormat *self); /* derived name */

/* derived name: makes one format a copy of another, the element count first
 * and then that many elements. */
void FUN_000270b0(hkVertexFormat *self, const hkVertexFormat *other); /* derived name */

/* derived name: the order of a format's canonical form (the sort 0x26f20
 * that 0x27180 runs takes it by address): by usage, then by sub-usage. */
bool FUN_000271d0(const hkVertexFormat::Element &a, const hkVertexFormat::Element &b);

/* hkMeshVertexBuffer (hkClass 0x57bca60, built at 0x22c21, parent
 * hkReferencedObject, 0x10 bytes). Slots 11 to 14, kept by both
 * hkMultipleVertexBuffer (0x1692000) and hkMemoryMeshVertexBuffer
 * (0x16921b0), are its defaults: each hands a locked-vertices record, an
 * element index and an array of values to a function of
 * hkMeshVertexBufferUtil.cpp. The record (derived name LockedVertices) holds
 * 24-byte buffer descriptions from +0 and the vertex count at +0x304, as
 * FUN_000aaaf0 reads it. */
class hkMeshVertexBuffer : public hkReferencedObject
{
  public:
    hkMeshVertexBuffer(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    struct LockedVertices; /* derived name */

    hkResult FUN_000260a0(const LockedVertices &lockedVertices, int elementIndex,
                          float *values); /* vtable slot 11; derived name */
    hkResult FUN_000260b0(const LockedVertices &lockedVertices, int elementIndex,
                          const float *values); /* vtable slot 12; derived name */
    hkResult FUN_000260c0(const LockedVertices &lockedVertices, int elementIndex,
                          int *values); /* vtable slot 13; derived name */
    hkResult FUN_000260d0(const LockedVertices &lockedVertices, int elementIndex,
                          const int *values); /* vtable slot 14; derived name */
};

/* hkMultipleVertexBuffer, polymorphic (type info 0x57bcf70, size 0x158,
 * vtable 0x1692000 stored by its finish constructor FUN_00024fa0): slot 0,
 * the complete destructor FUN_00024b70, runs the out-of-line FUN_00024db0.
 * Members from its record table at 0x1691820: vertexFormat (struct) at +0xc,
 * lockedElements (array) at +0x110, lockedBuffer (pointer) at +0x120,
 * elementInfos and vertexBufferInfos (arrays) at +0x128 and +0x138,
 * numVertices (hkInt32) at +0x148, isLocked (hkBool) at +0x14c, updateCount
 * (hkUint32) at +0x150, writeLock, isSharable and constructionComplete
 * (hkBool) at +0x154, +0x155 and +0x156. */
extern const hkClass D_57bcf20; /* hkMultipleVertexBuffer's hkClass, built at 0x23adb */

/* Its hkClass's parent is hkMeshVertexBuffer's, 0x57bca60 (the constructor's
 * third argument at 0x23ae9); vertexFormat at +0xc sits in the tail padding
 * of hkReferencedObject. */
class hkMultipleVertexBuffer : public hkMeshVertexBuffer
{
  public:
    /* hkMultipleVertexBuffer::LockedElement (records from 0x16919e0, 7 bytes):
     * the hkUint8 members from +0 and the hkInt8 emulatedIndex at +6. */
    struct LockedElement {
        u8 vertexBufferIndex;
        u8 elementIndex;
        u8 lockedBufferIndex;
        u8 vertexFormatIndex;
        u8 lockFlags;
        u8 outputBufferIndex;
        s8 emulatedIndex;
    };

    /* derived name: orders locked elements by vertex buffer, then element;
     * the sort at 0x257f2 takes it. */
    static bool FUN_00024b60(const LockedElement &a, const LockedElement &b);

    hkMultipleVertexBuffer(hkFinishLoadedObjectFlag flag);
    virtual ~hkMultipleVertexBuffer();

    const hkClass *getClassType() const;                /* vtable slot 3, FUN_000238c0 */
    bool FUN_00024bd0() const;                          /* vtable slot 6; derived name */
    void FUN_00024be0(hkVertexFormat &formatOut) const; /* vtable slot 7; derived name */
    int FUN_00024bf0() const;                           /* vtable slot 8; derived name */

    hkVertexFormat vertexFormat;
    hkArray<LockedElement> lockedElements;
    u8 unknown120[0x28];
    int numVertices;
    hkBool isLocked;
    u32 updateCount;
    hkBool writeLock;
    hkBool isSharable;
    hkBool constructionComplete;
};

void FUN_00024fa0(hkMultipleVertexBuffer *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00024db0(hkMultipleVertexBuffer *self);                                /* derived name */

/* hkMemoryMeshBody, polymorphic, 0x80 bytes (type info 0x57bccf0, vtable
 * 0x1691610 stored by its finish constructor 0x23190): members from
 * its record table at 0x1691530, transform (type 0x11) at +0x10,
 * transformSet (pointer) at +0x50, shape (pointer to hkMeshShape) at +0x58,
 * vertexBuffers (array of pointers) at +0x60, name (hkStringPtr) at +0x70. */
/* hkMeshShape (hkClass 0x57bd7d0, the parent of hkSkinBinding): a
 * reference-counted object whose slot 8 returns its name (hkxBlobMeshShape,
 * hkSkinnedRefMeshShape, hkMemoryMeshMaterial and hkStorageSkinnedMeshShape
 * return their hkStringPtr there) and slot 9 sets it. Slot 7 takes an
 * hkMeshSection (a reflected class; hkMemoryMeshShape's override 0x2ad50
 * reads a pointer at +0x28 and an int at +0x38 of it). */
struct hkMeshSection;

class hkMeshShape : public hkReferencedObject
{
  public:
    hkMeshShape(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    virtual void unknownVirtual5();
    virtual void unknownVirtual6();
    virtual void unknownVirtual7(const hkMeshSection &section);
    virtual const char *getName() const;       /* vtable slot 8; derived name */
    virtual void setName(const char *newName); /* vtable slot 9; derived name */
};

/* The vertex buffer helpers of hkMeshVertexBufferUtil.cpp (the homes row of
 * FUN_000ab8d0; class name from the file name, derived). */
/* The record (derived names): 32 buffer descriptions of 24 bytes from +0
 * (the element's start, its stride, then the element itself at +0xc, its
 * data type and value count first, as 0xaab10 reads them), the buffer count
 * at +0x300 and the vertex count at +0x304. */
struct hkMeshVertexBuffer::LockedVertices /* derived name */
{
    struct Buffer /* derived name */
    {
        void *start;                     /* derived name */
        int stride;                      /* derived name */
        hkVertexFormat::Element element; /* derived name */
    };

    Buffer buffers[32]; /* derived name */
    int numBuffers;     /* derived name */
    int numVertices;    /* derived name */
};

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
    /* The finish constructor (0x274e0): a big-endian image is swapped to
     * the host's order once loaded. */
    hkMemoryMeshVertexBuffer(hkFinishLoadedObjectFlag flag);

    virtual ~hkMemoryMeshVertexBuffer();

    /* Swaps every element of every vertex to the other byte order (0x27520).
     * derived name. */
    void FUN_00027520();

    /* Not a vtable slot: called with no arguments by the type test at
     * 0xacf40, which checks an object's class (its slot 3) against it. */
    static const hkClass *FUN_0002ae00(); /* derived name */

    /* The description of one element's buffer in the vertex memory
     * (0x27ae0, called by hkMultipleVertexBuffer for its locked buffer):
     * where the element starts, the vertex stride, the element. derived
     * name. */
    void FUN_00027ae0(int elementIndex, hkMeshVertexBuffer::LockedVertices::Buffer &buffer);

    bool FUN_00027280() const; /* vtable slot 6; derived name */
    int FUN_00027290() const;  /* vtable slot 8; derived name */
    void FUN_00027b10();       /* vtable slot 15; derived name */

    u8 unknown8[4];
    hkVertexFormat format;
    int elementOffsets[32];
    hkArray<u8> memory;
    int vertexStride;
    hkBool locked;
    int numVertices;
    hkBool isBigEndian;
    hkBool isSharable;
};

class hkMeshVertexBufferUtil /* derived name */
{
  public:
    /* An element's values as floats, from one buffer description, for a
     * number of vertices (0xaab10). derived name. */
    static hkResult FUN_000aab10(const hkMeshVertexBuffer::LockedVertices::Buffer &buffer,
                                 float *values, int numVertices);
    static hkResult FUN_000aaaf0(const hkMeshVertexBuffer::LockedVertices &lockedVertices,
                                 int elementIndex, float *values); /* derived name */
    static hkResult FUN_000aae70(const hkMeshVertexBuffer::LockedVertices &lockedVertices,
                                 int elementIndex, const float *values); /* derived name */
    static hkResult FUN_000ab150(const hkMeshVertexBuffer::LockedVertices &lockedVertices,
                                 int elementIndex, int *values); /* derived name */
    static hkResult FUN_000ab4f0(const hkMeshVertexBuffer::LockedVertices &lockedVertices,
                                 int elementIndex, const int *values); /* derived name */
};

/* hkMeshBody, its parent (hkClass 0x57bd408, built at 0x246ae), a
 * hkReferencedObject with no members of its own. */
class hkMeshBody : public hkReferencedObject
{
  public:
    hkMeshBody(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* Slots 10 to 12 hand matrices to and from the transform set, slots 13 to
 * 15 return its matricesOrder, matricesNames and indexMappings; slot 20
 * (the shared FUN_0000dcb0) returns the name, slot 21 sets it. */
class hkMemoryMeshBody : public hkMeshBody
{
  public:
    hkMemoryMeshBody(hkFinishLoadedObjectFlag flag);
    virtual ~hkMemoryMeshBody();

    hkMeshShape *FUN_000230d0() const; /* vtable slot 5; derived name */
    int FUN_000230f0() const;          /* vtable slot 9; derived name */
    int FUN_00023160() const;          /* vtable slot 16; derived name */
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
    hkMeshVertexBuffer *FUN_000230e0(int index) const;  /* vtable slot 8; derived name */

    Mat4 transform;
    hkIndexedTransformSet *transformSet;
    hkMeshShape *shape;
    hkArray<hkMeshVertexBuffer *> vertexBuffers;
    hkStringPtr name;
};

/* Classes without a vtable whose finish constructor or destructor is out of
 * line (type info: vtable 0): */

/* hkcdPlanarGeometryPrimitives::Plane (type info 0x57ba4e0, size 0x40): its
 * finish constructor, only when finishing, runs FUN_00095ab0, which unpacks
 * the plane's packed integer coefficients at +0 and +0x10 (vector shifts)
 * into its float equation. */
struct hkcdPlanarGeometryPrimitivesPlane;

void FUN_00095ab0(hkcdPlanarGeometryPrimitivesPlane *self); /* derived name */

void FUN_00095aa0(hkcdPlanarGeometryPrimitivesPlane *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */

/* hkcdPlanarGeometryPlanesCollection (hkClass 0x57ba290, built at 0x1d458:
 * size 0x40, parent hkReferencedObject's 0x57b8640, member records at
 * 0x168f4a0; vtable 0x16a3770): offsetAndScale (hkVector4) at +0x10, planes
 * (array of hkcdPlanarGeometryPrimitives::Plane, hkClass 0x57ba490) at
 * +0x20, cache and criticalAccess (pointers, not serialized: record flags
 * 0x400) at +0x30 and +0x38. Its finish constructor 0x9c400 is out of line
 * (the finish callback FUN_0001d3b0 jumps to it, the reflection initializer
 * at 0x1d463 runs it on a temporary); a finished object gets its critical
 * section from FUN_0009c430. */
class hkcdPlanarGeometryPlanesCollection : public hkReferencedObject
{
  public:
    hkcdPlanarGeometryPlanesCollection(hkFinishLoadedObjectFlag flag);
    virtual ~hkcdPlanarGeometryPlanesCollection();

    /* Allocates the 0x10-byte critical section (0x1830 constructs it) and
     * keeps it at +0x38 (0x9c430). derived name. */
    void FUN_0009c430();

    Vec4 offsetAndScale;
    hkArray<hkcdPlanarGeometryPrimitivesPlane> planes;
    void *cache;
    void *criticalAccess;
};

/* hkcdStaticPvs (type info 0x57ba5e0, size 0x70): its destructor frees the
 * arrays at +0x58 and +0x48 through the thread's heap allocator. */
struct hkcdStaticPvs;

void FUN_0001d9e0(hkcdStaticPvs *self); /* derived name */

/* hkcdStaticMeshTreeBase (type info 0x57bc360, size 0x70): an empty finish
 * constructor (one shared body) and an out-of-line destructor. */
struct hkcdStaticMeshTreeBase;

void FUN_000a9140(hkcdStaticMeshTreeBase *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00020700(hkcdStaticMeshTreeBase *self);                                /* derived name */

/* The library's table of vector constants (derived name), extern, reached
 * through its GOT slot: row 33 (+0x210) holds the largest float less a few
 * units in each lane (0x7f7fffee), row 34 (+0x220) a large value
 * (0x5f7ffff0, about 1.8e19), row 38 row 33 negated. */
extern const Vec4 D_14b2060[];

/* hkQuaternion (the reflection's TYPE_QUATERNION, its name a string of the
 * executable): four floats in one vector. Field name derived. */
struct hkQuaternion {
    /* Whether the four lanes are ordered numbers and the length's square
     * is within epsilon of one (0x1a180; the game asks it at 0xeaeda1 and
     * 0xeaf9f0 and tests the int). Row 3 of the constant table is one in
     * each lane. derived name. */
    int FUN_0001a180(float epsilon) const;

    Vec4 vec; /* derived name */
};

/* hkAabb (hkClass 0x57b9c20): two hkVector4 bounds. Field names derived.
 * FUN_0014a1f0 empties it (min the largest value, max its negation, so any
 * point extends it); FUN_0014a220 makes it the whole space. */
struct hkAabb {
    void FUN_0014a1f0(); /* derived name */
    void FUN_0014a220(); /* derived name */

    Vec4 min; /* derived name */
    Vec4 max; /* derived name */
};

/* derived name: how far inner lies inside outer, the smallest of the six
 * margins in every lane (negative when it sticks out); 0x14a2b0, called at
 * 0x75526 and 0x173aca. */
Vec4 FUN_0014a2b0(const hkAabb &inner, const hkAabb &outer);

/* derived name: the bounds of an AABB under a transform (0x94060: the
 * centre transformed, the half extents through the rotation's absolute
 * values); the compound and LOD shapes' slot 7 calls it on their own. */
void FUN_00094060(const Mat4 &transform, const hkAabb &aabb, hkAabb &aabbOut); /* derived name */

/* hkcdStaticTree::DefaultTreeStorage32 (type info
 * "!hkcdStaticTree::DefaultTreeStorage32" at 0x14b56c0, hkClass 0x57ba910
 * built at 0x1e3ba: size 0x30): the nodes, 32 bytes each, at +0 and the
 * domain at +0x10 (derived names). */
struct hkcdStaticTree {
    struct DefaultTreeStorage32 {
        struct Node {
            u8 unknown0[0x20];
        };

        /* The cleanup callback of its type info (0x1e170; the other
         * storages with 32-byte nodes cite the same body). derived name. */
        static void FUN_0001e170(void *object);

        hkArray<Node> nodes; /* derived name */
        hkAabb domain;       /* derived name */
    };
};

/* hkcdDynamicTree's default storage over its raw-ulong codec (type info
 * "!hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecRawUlong_typename"
 * at 0x14b5e99, hkClass built by 0x1f750: size 0x18): the nodes, 64 bytes
 * each, at +0 (derived names). */
struct hkcdDynamicTree {
    struct CodecRawUlong {
        u8 unknown0[0x40];
    };

    template <typename CODEC> struct DefaultDynamicStorage {
        /* The cleanup callback of its type info (0x1f650 for the raw-ulong
         * codec; the other storages with 64-byte nodes cite the same body).
         * derived name. */
        static void FUN_0001f650(void *object);

        hkArray<CODEC> nodes; /* derived name */
        u8 unknown10[8];
    };
};

/* hknpCompressedMeshShapeTree (type info 0x57be2f0, size 0xa0) and the
 * hkcdStaticMeshTree instance it is built on (type info 0x57be570) register
 * one finish callback; the finish constructor is the shared empty body. Its
 * static tree's domain (hkAabb) is at +0x10, as in every hkcdStaticTree
 * record table (0x168fde0 to 0x16900e8). */
struct hknpCompressedMeshShapeTree;

void FUN_000a9140(hknpCompressedMeshShapeTree *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */

struct hknpCompressedMeshShapeTree {
    /* The finish constructor is out of line (0xa9140). */
    hknpCompressedMeshShapeTree(hkFinishLoadedObjectFlag flag)
    {
        FUN_000a9140(this, flag);
    }

    /* Clears the bits of the filter's keys the tree does not hold and
     * reports the change (0xa92c0); true when the filter changed anything.
     * derived name. */
    bool FUN_000a92c0(hkArray<u32> &filter) const;

    /* A key's bit in the filter set or cleared (0xa9410), and read
     * (0xa9550); the key is the part below the shape's own bits. derived
     * names. */
    void FUN_000a9410(hkArray<u32> &filter, u32 key, bool enabled) const;
    bool FUN_000a9550(const hkArray<u32> &filter, u32 key) const;

    u8 unknown0[0x10];
    hkAabb domain;
    u8 unknown30[0x70];
};

/* hkSkinnedMeshShape::BoneSection (type info 0x57bdc18, size 0x10): an
 * empty finish constructor (one shared body). */
struct hkSkinnedMeshShapeBoneSection;

void FUN_000add70(hkSkinnedMeshShapeBoneSection *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */

/* A signal (derived name): its slots in a list from the pointer at +0 (the
 * low two bits are flags), each slot's slot 1 destroying it; its
 * destructor FUN_00093530 is out of line. */
struct Signal00093530 /* derived name */
{
    /* No slots (the finish constructors of the libraries clear their
     * unserialized signals). */
    Signal00093530() : slots(0) {}

    void *slots; /* derived name */
};

void FUN_00093530(Signal00093530 *self); /* derived name: the destructor */
/* Every slot deleted (its slot 1) and the list emptied (0x93570; the
 * destructor runs it once the memory system is up, FUN_00009c10). derived
 * name. */
void FUN_00093570(Signal00093530 *self); /* derived name */

/* hknpShapeSignals, a reflected struct (hkClass at 0x57c2478); at most 16
 * bytes, the member after it in hknpMaskedShape sitting at +0x60: two
 * signals, each a pointer to its slot list (hknpScaledConvexShape's finish
 * constructor clears both; the shape watcher subscribes to the first, which
 * passes a byte of change flags, and the second, which passes the shape as
 * it is destroyed). Field names derived. */
struct hknpShapeSignals {
    Signal00093530 shapeMutated;   /* derived name */
    Signal00093530 shapeDestroyed; /* derived name */
};

/* hknpShapeSignals's type info (0x57c24c8, built with its hkClass by
 * 0x69980): no finish callback, the cleanup callback FUN_00069960, size
 * 0x10. */
void FUN_00069960(void *object); /* derived name */

/* A pool of worker threads (derived name): slot 9 gives the number of its
 * threads (the step input's thread count at 0x69924 is one more). */
class ThreadPool00069910 /* derived name */
{
  public:
    virtual ~ThreadPool00069910();
    virtual void unknownVirtual2();
    virtual void unknownVirtual3();
    virtual void unknownVirtual4();
    virtual void unknownVirtual5();
    virtual void unknownVirtual6();
    virtual void unknownVirtual7();
    virtual void unknownVirtual8();
    virtual int getNumThreads() const; /* slot 9; derived name */
};

/* What the game hands a physics step (derived name): the game fills one on
 * its stack at 0xe99d79 (a time step of 1/30 at +0, a pointer at +8) and
 * has FUN_00069910 count the threads from its thread pool: the calling
 * thread and the pool's, or the calling thread alone. */
struct StepInput00069910 /* derived name */
{
    void FUN_00069910(const ThreadPool00069910 *threadPool); /* derived name */

    u8 unknown0[0x10];
    int numCpuThreads; /* derived name */
    int numSpuThreads; /* derived name */
};

/* hknpShape, polymorphic, 0x28 bytes (type info 0x57bf210, hkClass with
 * hkReferencedObject as its parent, built at 0x38fcb; vtable 0x169ad20 stored
 * by its out-of-line finish constructor 0x6fa90, which the finish callback
 * FUN_00038d30, the reflection initializer at 0x38fe4 and the finish
 * constructors of the derived shapes call): its destructor, slot 0, is out of
 * line (0x6fb50: restores the vtable, releases the properties at +0x20). */
/* Its vtable's address point is 0x169ad30. Slots 8, 9 and 13 return 0 by
 * default (slot 8 the shared 0x42d0; slots 9 and 13, 0x6e5b0 and 0x6e830,
 * after reporting "Not implemented" from hknpShape.cpp). The other defaults
 * from slot 7 to 20 report the same; what they return (nothing, 0, or 0.0f
 * for slot 17) gives the return types, and the arguments are those the
 * overrides of hknpSphereShape (address point 0x1695c20) read: slot 7 a
 * transform's rows from %rsi, slot 11 a direction from %rsi, slot 12 bytes
 * from %rsi, a count in %edx and three vectors stored through %rcx, slot 14
 * a face index in %esi, a plane stored through %rdx and a byte through
 * %rcx, slot 15 the same index and plane and four vertices through %rcx
 * (returning 4). Slot 10 returns the shape's vertex array without reading
 * its arguments; the decorator's forward (a loaded `jmpq *%rax`, cookbook
 * 19) shows it has some. Argument names derived. */
class hknpShape;

/* hknpShapeInstance (hkClass 0x57bfe90, built at 0x3cb70: size 0x80, no
 * parent; member records at 0x1695f50): transform at +0, scale at +0x40,
 * shape at +0x50, shapeTag and destructionTag (hkUint16) at +0x58 and +0x5a,
 * 30 bytes of padding. The compound shapes keep arrays of them (the caller
 * at 0x42494 walks one). */
struct hknpShapeInstance {
    /* The transform with the scale applied to its rotation, column by
     * column (0x3ea90). derived name. */
    void FUN_0003ea90(hkTransform &transformOut) const;

    /* The translation's w holds an integer: six flag bits from bit 24 and
     * the instance's index in the rest, which the compound key masks' filter
     * is indexed by (0x33d4a's `and esi, 0xc0ffffff`). derived names. */
    enum { FLAGS_SHIFT = 24, FLAGS_MASK = 0x3f << FLAGS_SHIFT };

    int getIndex() const /* derived name */
    {
        return reinterpret_cast<const int *>(&transform.translation)[3] & ~FLAGS_MASK;
    }

    hkTransform transform;
    Vec4 scale;
    hknpShape *shape;
    u16 shapeTag;
    u16 destructionTag;
    u8 padding[30];
};

/* derived name: what slot 24 of hknpShape does by default (0x169e50, 0x51d
 * bytes): bounds the shape by slot 7 under the fourth argument's transform
 * and tests the first argument's point (+0x20) and distance (+0x30) against
 * the bounds before the query proper. */
void FUN_00169e50(const void *argument1, const void *argument2, const hknpShape *shape,
                  const void *argument3, const void *argument4, void *argument5); /* derived name */

class hknpShape : public hkReferencedObject
{
  public:
    /* The shape flags: the item names are the executable's strings (from
     * 0x14bdcf4, in this order), the values their bits in that order, which
     * the finish constructors' sets agree with (the capsule's 0x1c3, the
     * triangle's 0x9c3, the sphere's 0x2111). */
    enum FlagsEnum {
        IS_CONVEX_SHAPE = 1 << 0,
        IS_CONVEX_POLYTOPE_SHAPE = 1 << 1,
        IS_COMPOSITE_SHAPE = 1 << 2,
        IS_HEIGHT_FIELD_SHAPE = 1 << 3,
        USE_SINGLE_POINT_MANIFOLD = 1 << 4,
        IS_INTERIOR_TRIANGLE = 1 << 5,
        SUPPORTS_COLLISIONS_WITH_INTERIOR_TRIANGLES = 1 << 6,
        USE_NORMAL_TO_FIND_SUPPORT_PLANE = 1 << 7,
        USE_SMALL_FACE_INDICES = 1 << 8,
        NO_GET_SHAPE_KEYS_ON_SPU = 1 << 9,
        SHAPE_NOT_SUPPORTED_ON_SPU = 1 << 10,
        IS_TRIANGLE_OR_QUAD_SHAPE = 1 << 11,
        IS_QUAD_SHAPE = 1 << 12,
        IS_SPHERE_SHAPE = 1 << 13
    };

    hknpShape(hkFinishLoadedObjectFlag flag);
    virtual ~hknpShape();

    virtual void unknownVirtual5();
    virtual void unknownVirtual6();
    /* Slot 7: the shape's bounds under a transform. */
    virtual void unknownVirtual7(const Mat4 &transform, hkAabb &aabbOut) const;
    virtual int unknownVirtual8() const;
    virtual int unknownVirtual9() const;
    virtual const Vec4 *unknownVirtual10(Vec4 *buffer, int bufferSize) const;
    virtual void unknownVirtual11(const Vec4 &direction, Vec4 *vertexOut) const;
    virtual void unknownVirtual12(const u8 *ids, int numIds, Vec4 *verticesOut) const;
    virtual int unknownVirtual13() const;
    virtual void unknownVirtual14(int faceIndex, Vec4 *planeOut, u8 *valueOut) const;
    virtual int unknownVirtual15(int faceIndex, Vec4 *planeOut, Vec4 *verticesOut) const;
    /* Slot 16: the default (0x6ea10) reports "Not implemented" and
     * returns 0; hknpConvexShape's (0x45bb0) reads a vector through the
     * first argument and compares the fifth with -1; the decorator's
     * forward (FUN_0003b1a0) widens the fourth, a bool. */
    virtual int unknownVirtual16(const void *argument1, const void *argument2, void *argument3,
                                 bool argument4, int argument5) const;
    virtual float unknownVirtual17() const;
    /* Slots 18 to 29: the arguments as their implementations read them
     * (hknpShape's 0x6eb50 and 0x6ebf0, hknpConvexShape's from 0x45a80,
     * hknpStaticCompoundShape's from 0x418c0, hknpConvexPolytopeShape's
     * 0x152170); their types and names are not recovered. */
    virtual void unknownVirtual18(const void *argument1, void *argument2) const;
    virtual void unknownVirtual19(const void *argument1, const void *argument2, int argument3,
                                  float argument4, void *argument5, void *argument6) const;
    virtual int unknownVirtual20() const;
    virtual int unknownVirtual21(void *argument1, int argument2, int argument3,
                                 const void *argument4) const;
    virtual void unknownVirtual22(const void *argument1, const void *argument2,
                                  void *argument3) const;
    virtual void unknownVirtual23(const void *argument1, const void *argument2,
                                  const void *argument3, const void *argument4,
                                  void *argument5) const;
    /* Slot 24: five arguments, which the default (FUN_0006fa60) hands on
     * with the shape third to FUN_00169e50; its fourth holds at +0x20 the
     * transform slot 7 takes. */
    virtual void unknownVirtual24(const void *argument1, const void *argument2,
                                  const void *argument3, const void *argument4,
                                  void *argument5) const;
    virtual void unknownVirtual25(const void *argument1, const void *argument2,
                                  const void *argument3, const void *argument4,
                                  void *argument5) const;
    virtual void unknownVirtual26(const void *argument1, const void *argument2,
                                  const void *argument3, const void *argument4,
                                  void *argument5) const;
    virtual int unknownVirtual27(const void *argument1, const void *argument2, int argument3) const;
    virtual void unknownVirtual28(const void *argument1, void *argument2) const;
    virtual void unknownVirtual29(const void *argument1, void *argument2) const;
    /* Slot 30: the shared empty body 0x3b640, kept by every shape vtable
     * read so far. */
    virtual void unknownVirtual30();

    u8 unknownC[4];
    /* Shape flags; a composite shape's finish constructor sets 4 (0x71690,
     * inlined in hknpLodShape's 0x68160). derived name. */
    u16 flags;
    /* The bits of a key that select within this shape (the compressed
     * mesh's key mask shifts its keys by them, 0x34a80). */
    u8 numShapeKeyBits; /* name from the strings; offset derived */
    /* The rest from the member records the initializer 0x38d80 builds:
     * dispatchType (hkEnum of hkUint8) at +0x13, convexRadius (hkReal) at
     * +0x14, userData (hkUint64) at +0x18. */
    u8 dispatchType;
    float convexRadius;
    u64 userData;
    void *properties; /* a 16-byte object the destructor destroys and frees; derived name */
};

/* hknpDecoratorShape (type info 0x57bf020, vtable 0x16958d0 stored by its
 * finish constructor 0x3b0f0, which runs hknpShape's first): adds
 * nothing to destroy. It wraps a shape, its member coreShape (record at
 * 0x1694240: a pointer at +0x28), and slots 7 to 29 of its vtable (address
 * point 0x16958e0) forward to the same slot of that shape (0x3b120 to
 * 0x3b270; slot 22 is 0x37e80); hknpMaskedShape (0x1693a90) keeps them. */
class hknpDecoratorShape : public hknpShape
{
  public:
    hknpDecoratorShape(hkFinishLoadedObjectFlag flag); /* 0x3b0f0 */

    virtual ~hknpDecoratorShape();

    void FUN_0003b120(const Mat4 &transform,
                      hkAabb &aabbOut) const;                     /* vtable slot 7; derived name */
    int FUN_0003b280() const;                                     /* vtable slot 8; derived name */
    int FUN_0003b130() const;                                     /* vtable slot 9; derived name */
    const Vec4 *FUN_0003b140(Vec4 *buffer, int bufferSize) const; /* vtable slot 10; derived name */
    void FUN_0003b150(const Vec4 &direction,
                      Vec4 *vertexOut) const; /* vtable slot 11; derived name */
    void FUN_0003b160(const u8 *ids, int numIds,
                      Vec4 *verticesOut) const; /* vtable slot 12; derived name */
    int FUN_0003b170() const;                   /* vtable slot 13; derived name */
    void FUN_0003b180(int faceIndex, Vec4 *planeOut,
                      u8 *valueOut) const; /* vtable slot 14; derived name */
    int FUN_0003b190(int faceIndex, Vec4 *planeOut,
                     Vec4 *verticesOut) const; /* vtable slot 15; derived name */
    int FUN_0003b1a0(const void *argument1, const void *argument2, void *argument3, bool argument4,
                     int argument5) const; /* vtable slot 16; derived name */
    float FUN_0003b1c0() const;            /* vtable slot 17; derived name */
    void FUN_0003b1d0(const void *argument1,
                      void *argument2) const; /* vtable slot 18; derived name */
    void FUN_0003b1e0(const void *argument1, const void *argument2, int argument3, float argument4,
                      void *argument5, void *argument6) const; /* vtable slot 19; derived name */
    int FUN_0003b1f0() const;                                  /* vtable slot 20; derived name */
    int FUN_0003b200(void *argument1, int argument2, int argument3,
                     const void *argument4) const; /* vtable slot 21; derived name */
    void FUN_00037e80(const void *argument1, const void *argument2,
                      void *argument3) const; /* vtable slot 22; derived name */
    void FUN_0003b220(const void *argument1, const void *argument2, const void *argument3,
                      const void *argument4,
                      void *argument5) const; /* vtable slot 23; derived name */
    void FUN_0003b230(const void *argument1, const void *argument2, const void *argument3,
                      const void *argument4,
                      void *argument5) const; /* vtable slot 24; derived name */
    void FUN_0003b240(const void *argument1, const void *argument2, const void *argument3,
                      const void *argument4,
                      void *argument5) const; /* vtable slot 25; derived name */
    void FUN_0003b250(const void *argument1, const void *argument2, const void *argument3,
                      const void *argument4,
                      void *argument5) const; /* vtable slot 26; derived name */
    int FUN_0003b210(const void *argument1, const void *argument2,
                     int argument3) const; /* vtable slot 27; derived name */
    void FUN_0003b260(const void *argument1,
                      void *argument2) const; /* vtable slot 28; derived name */
    void FUN_0003b270(const void *argument1,
                      void *argument2) const; /* vtable slot 29; derived name */

    hknpShape *coreShape;
    int coreShapeSize; /* the record's second member (TYPE_INT32, +0x30) */
};

/* hknpShapeKeyMask, reflected (hkClass 0x57c1aa8, parent hkBaseObject): the
 * interface of a shape's key mask, slots 3 to 6 after hkBaseObject's. The
 * executable has no vtable of its own for it; the slots are named after
 * hknpMaskedShape::MaskWrapper's overriders and typed from their bodies
 * (slot 3 forwards a key and a bool, slots 4 and 5 return bool, slot 6 the
 * object's size: 16 for the wrapper, 32 for
 * hknpCompressedMeshShapeInternals::KeyMask's 0x2b020). */
class hknpShapeKeyMask : public hkBaseObject
{
  public:
    hknpShapeKeyMask(hkFinishLoadedObjectFlag flag) : hkBaseObject(flag) {}

    virtual void FUN_000381b0(u32 key, bool enabled) = 0; /* derived name */
    virtual bool FUN_000381d0() = 0;                      /* derived name */
    virtual bool FUN_000381f0(u32 key) const = 0;         /* derived name */
    virtual int FUN_00038210() const = 0;                 /* derived name */
};

/* hkHandle, a typed index: the scoped type name of the compound shapes'
 * instance array at 0x14bb530 spells hkFreeListArray<hknpShapeInstance,
 * hkHandle<short, 32767, hknpShapeInstanceIdDiscriminant>, 8,
 * hknpShapeInstance>, the second argument the instance id. Passed by value as a small struct, which the callee widens
 * itself (0x33d3c's `movsx rdx, si`). */
template <typename TYPE, TYPE INVALID_VALUE, typename DISCRIMINANT> struct hkHandle {
    TYPE value; /* derived name */
};

struct hknpShapeInstanceIdDiscriminant;
typedef hkHandle<short, 32767, hknpShapeInstanceIdDiscriminant> hknpShapeInstanceId;

/* hknpCompoundShapeKeyMask (hkClass 0x57c2ec8, built at 0x77f36: size 8,
 * parent hknpShapeKeyMask's 0x57c1aa8, no members): the interface adds slot
 * 7, whether an instance's keys pass the mask. */
class hknpCompoundShape;

class hknpCompoundShapeKeyMask : public hknpShapeKeyMask
{
  public:
    hknpCompoundShapeKeyMask(hkFinishLoadedObjectFlag flag) : hknpShapeKeyMask(flag) {}

    virtual int FUN_00033d30(hknpShapeInstanceId instanceId) const = 0; /* derived name */
};

/* hknpCompoundShapeInternalsKeyMask (hkClass 0x57bdf20, built at 0x34508:
 * size 0x30, parent hknpCompoundShapeKeyMask's 0x57c2ec8; member records at
 * 0x16929d0): shape (a pointer to hknpCompoundShape, not serialized) at +8,
 * instanceMasks (an array of pointers to hknpShapeKeyMask) at +0x10 and
 * filter (an array of hkUint32, a bit per instance) at +0x20. Vtable
 * 0x16927e0, finish callback FUN_000343b0. */
class hknpCompoundShapeInternalsKeyMask : public hknpCompoundShapeKeyMask
{
  public:
    hknpCompoundShapeInternalsKeyMask(hkFinishLoadedObjectFlag flag)
        : hknpCompoundShapeKeyMask(flag), instanceMasks(flag), filter(flag)
    {
    }

    virtual ~hknpCompoundShapeInternalsKeyMask(); /* vtable slots 0 and 1, 0x338d0 and 0x33990 */

    void FUN_000381b0(u32 key, bool enabled); /* vtable slot 3 (0x33a90); derived name */
    bool FUN_000381d0();                      /* vtable slot 4 (0x1bad0); derived name */
    bool FUN_000381f0(u32 key) const;         /* vtable slot 5 (0x33ca0); derived name */
    int FUN_00038210() const;                 /* vtable slot 6 (0x33d20); derived name */

    /* vtable slot 7 (0x33d30): the instance's bit in the filter. derived name. */
    int FUN_00033d30(hknpShapeInstanceId instanceId) const;

    const hknpCompoundShape *shape;
    hkArray<hknpShapeKeyMask *> instanceMasks;
    hkArray<u32> filter;
};

/* hknpStaticCompoundShapeKeyMask (hkClass 0x57bdea0, built at 0x34162: size
 * 0x30, parent hknpCompoundShapeInternalsKeyMask's 0x57bdf20, no members):
 * vtable 0x1692790, finish callback FUN_00034000. */
class hknpStaticCompoundShapeKeyMask : public hknpCompoundShapeInternalsKeyMask
{
  public:
    hknpStaticCompoundShapeKeyMask(hkFinishLoadedObjectFlag flag)
        : hknpCompoundShapeInternalsKeyMask(flag)
    {
    }

    bool FUN_000381d0(); /* vtable slot 4 (0x33b30); derived name */
};

/* hknpCompressedMeshShapeInternals::KeyMask (hkClass 0x57be220, size 0x20,
 * parent hknpShapeKeyMask's 0x57c1aa8; vtable 0x1692ab0, address point
 * 0x1692ac0): shape (a pointer to hknpCompressedMeshShape) at +8 and filter
 * (an array of hkUint32, a bit per key) at +0x10, from its record table at
 * 0x1692bc0. Slot 4 (0x34ac0) has the shape's mesh tree apply the filter;
 * slot 6 (0x2b020) returns the size, 32. */
class hknpCompressedMeshShape;

class hknpCompressedMeshShapeInternals::KeyMask : public hknpShapeKeyMask
{
  public:
    KeyMask(hkFinishLoadedObjectFlag flag) : hknpShapeKeyMask(flag), filter(flag) {}

    void FUN_000381b0(u32 key, bool enabled); /* vtable slot 3 (0x34a80); derived name */
    bool FUN_000381d0();                      /* vtable slot 4 (0x34ac0); derived name */
    bool FUN_000381f0(u32 key) const;         /* vtable slot 5 (0x34ae0); derived name */
    int FUN_00038210() const;                 /* vtable slot 6 (0x2b020); derived name */

    hknpCompressedMeshShape *shape;
    hkArray<u32> filter;
};

/* hknpMaskedShape, polymorphic, 0x70 bytes (type info 0x57bea28, vtable
 * 0x1693a80, address point 0x1693a90), reflected with hknpDecoratorShape as
 * its parent (hkClass 0x57be9d8): members from its record table at
 * 0x16936b0, mask (pointer) at +0x38, maskWrapper (struct) at +0x40,
 * mutationSignals (struct hknpShapeSignals) at +0x50, maskSize (int) at
 * +0x60. Its vtable adds slots 31 and 32: slot 31 (0x37d80) releases the
 * mask, has the core shape's slot 20 make a new one and tail-calls slot 32;
 * slot 32 (0x37dd0) runs the mask's slot 4, fires the mutation signals and
 * returns the mask's answer. */
class hknpMaskedShape : public hknpDecoratorShape
{
  public:
    /* hknpMaskedShape::MaskWrapper (type info 0x57be9a8, vtable 0x1693ba0,
     * reflected with hknpShapeKeyMask as its parent, hkClass 0x57be958): the
     * mask the shape hands out, 16 bytes, forwarding to its masked shape at
     * +8 (slots 3 and 5 to the shape's mask, slot 4 to the shape's slot 32).
     * Its finish constructor FUN_00038230 is out of line, called by the
     * finish callback 0x36780 and by the reflection initializer at 0x36863;
     * it stores only the vtable. */
    class MaskWrapper : public hknpShapeKeyMask
    {
      public:
        MaskWrapper(hkFinishLoadedObjectFlag flag);

        void FUN_000381b0(u32 key, bool enabled); /* vtable slot 3; derived name */
        bool FUN_000381d0();                      /* vtable slot 4; derived name */
        bool FUN_000381f0(u32 key) const;         /* vtable slot 5; derived name */
        /* slot 6 is the shared body FUN_00038210 (returns 16). */
        int FUN_00038210() const; /* vtable slot 6; derived name */

        hknpMaskedShape *maskedShape; /* derived name */
    };

    virtual ~hknpMaskedShape();

    virtual void FUN_00037d80(); /* vtable slot 31; derived name */
    virtual bool FUN_00037dd0(); /* vtable slot 32; derived name */

    hknpShapeSignals *FUN_00038120(); /* vtable slot 8; derived name */

    hknpShapeKeyMask *mask;
    MaskWrapper maskWrapper;
    hknpShapeSignals mutationSignals;
    s32 maskSize;
};

void FUN_00038230(hknpMaskedShape::MaskWrapper *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */

/* hknpFirstPersonGun, hknpBallGun and hknpMountedBallGun, each finish
 * constructor running its parent's first (0x156620, 0x157e00,
 * FUN_00166900; type infos below). hknpBallGun's destructor is out of line
 * (0x157ef0: stores its vtable, address point 0x16a48e0, and releases what
 * it holds); hknpMountedBallGun adds nothing to destroy, its slot 0
 * (vtable address point 0x16a5290) jumps to it. */
/* hknpFirstPersonGun's vtable (address point 0x16a47f0): slots 2 to 4 the
 * reference-counted object's (0x270, 0x42d0, 0x69a0); slots 5 to 7 and 10
 * the shared empty body 0xadd50; slot 8 (FUN_00156870) runs slot 10, which
 * hknpBallGun overrides (0x1584e0: empties what it holds in the world in
 * its first argument) and hknpProjectileGun too (0x159750); slot 9 (0xacf90)
 * returns the name (hkStringPtr) at +0x10. */
/* hknpWorld (the name of its source file, hknpWorld.cpp, which the homed
 * FUN_0004d0a0 asserts in; the class name is derived from it): its
 * constructor FUN_00048b20 builds the 0x570-byte object at +0x1b8
 * (constructor FUN_00066230; a derived name below, from what it holds), and
 * sets the collision filter of the world's description (+0xa8 of it) there
 * through FUN_000667b0, which keeps a reference to the new filter at +0x568
 * and releases the old one. FUN_0004bcc0 forwards to it. */
/* hknpCollisionFilter (hkClass 0x57c0cb0, built at 0x4049f: size 0x10,
 * parent hkReferencedObject's; its one member record and enum are built at
 * run time). Slots 5 to 9 of the filters' vtables are its interface, named
 * by hknpPairCollisionFilter's bodies (derived names): slot 5 (0x1679a0)
 * filters an array of 8-byte pairs of body ids and returns how many are
 * left; slots 6 to 9 answer whether a collision is enabled, from a query
 * type and, by slot: a flag (6), two inputs whose filter info sits at +4 of
 * the first and +0x44 of the second (7, as hknpGroupCollisionFilter's
 * 0x3a290 reads them), two body ids (8), a flag and two inputs with their
 * filter info at +4 (9, 0x3a2f0). */
struct hknpCollisionFilterContext;     /* derived name */
struct hknpCollisionFilterBodyIdPair;  /* derived name */
struct hknpCollisionFilterQueryInput;  /* derived name */
struct hknpCollisionFilterTargetInput; /* derived name */
struct hknpCollisionFilterShapeInput;  /* derived name */

class hknpCollisionFilter : public hkReferencedObject
{
  public:
    hknpCollisionFilter(u8 filterType) : type(filterType) {}

    hknpCollisionFilter(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    virtual int FUN_001679a0(const hknpCollisionFilterContext &context,
                             hknpCollisionFilterBodyIdPair *pairs,
                             int numPairs) const = 0;              /* derived name */
    virtual bool FUN_00167ad0(int queryType, bool flag) const = 0; /* derived name */
    virtual bool
    FUN_00167be0(int queryType, const hknpCollisionFilterQueryInput &query,
                 const hknpCollisionFilterTargetInput &target) const = 0;         /* derived name */
    virtual bool FUN_00167af0(int queryType, u32 bodyIdA, u32 bodyIdB) const = 0; /* derived name */
    virtual bool FUN_00167c00(int queryType, bool targetIsB, const hknpCollisionFilterShapeInput &a,
                              const hknpCollisionFilterShapeInput &b) const = 0; /* derived name */

    /* The one member, a byte at +0xc (its record is built at run time):
     * hknpDisableCollisionFilter's constructor stores 0 there before its
     * vtable (0x41077). derived name. */
    u8 type;
};

/* hknpDisableCollisionFilter (hkClass parent hknpCollisionFilter's
 * 0x57c0cb0, built at 0x3e3cf; vtable 0x16978a0, finish callback
 * FUN_0003e340): filter type 0. One instance is a global of its own file
 * (0x57c1080, built by that file's initializer 0x41070, read by nothing in
 * the executable). Its slots are not recovered. */
class hknpDisableCollisionFilter : public hknpCollisionFilter
{
  public:
    hknpDisableCollisionFilter() : hknpCollisionFilter(0) {}

    hknpDisableCollisionFilter(hkFinishLoadedObjectFlag flag) : hknpCollisionFilter(flag) {}

    int FUN_001679a0(const hknpCollisionFilterContext &context,
                     hknpCollisionFilterBodyIdPair *pairs, int numPairs) const;
    bool FUN_00167ad0(int queryType, bool flag) const;
    bool FUN_00167be0(int queryType, const hknpCollisionFilterQueryInput &query,
                      const hknpCollisionFilterTargetInput &target) const;
    bool FUN_00167af0(int queryType, u32 bodyIdA, u32 bodyIdB) const;
    bool FUN_00167c00(int queryType, bool targetIsB, const hknpCollisionFilterShapeInput &a,
                      const hknpCollisionFilterShapeInput &b) const;
};

/* A collision cache that keeps properties beside its contact data
 * (derived names): FUN_0017a0a0 reserves a property under a key (a bit of
 * the byte at +0x17 marks each key in use) of a size and an alignment, and
 * returns it, or null when the key is taken or the cache is full. */
struct hknpManifoldCollisionCache; /* derived name */
void *FUN_0017a0a0(hknpManifoldCollisionCache *cache, u8 propertyKey, u8 size,
                   int alignment); /* derived name */

/* What slot 3 of the modifier interface receives last: the new manifold's
 * collision cache first (derived names). */
struct ManifoldCreatedInput /* derived name */
{
    hknpManifoldCollisionCache *collisionCache; /* derived name */
};

/* The modifier of vtable 0x16a4dd0 (address point 0x16a4de0; derived name),
 * one of the twenty FUN_00048b20 builds for the world (0x49d35): slot 2
 * (0x12a8b0) returns its mask 9; slot 3 (0x15d7c0), called when a manifold
 * is created, gives the cache a zeroed vector under property key 1, which
 * slot 7 (0x15d7f0) reads back. */
class Modifier16a4de0 /* derived name */
{
  public:
    void FUN_0015d7c0(const void *threadContext, const void *sharedData, const void *bodyA,
                      const void *bodyB,
                      ManifoldCreatedInput *input); /* vtable slot 3; derived name */
};

/* The world's constructor (0x4a1bb to 0x4a258) fills two tables of the
 * manager by type: the collision detectors of the default modifier set
 * (its members at +0x78 to +0xd8) by collision cache type 1 to 7, and two
 * objects of the world (+0x380, +0x388) at 0 and 1 of the other. */
struct hknpCollisionDetector; /* derived name */

class hknpModifierManager /* derived name */
{
  public:
    enum Type4e0 /* derived name */
    {
        NUM_TYPES_4E0 = 8 /* derived name */
    };

    enum CollisionCacheType /* derived name */
    {
        NUM_COLLISION_CACHE_TYPES = 9 /* derived name */
    };

    void FUN_00066770(Type4e0 type, void *object);                               /* derived name */
    void FUN_00066790(CollisionCacheType type, hknpCollisionDetector *detector); /* derived name */
    void FUN_000667b0(hknpCollisionFilter *filter);                              /* derived name */

    u8 unknown0[0x4e0];
    void *objects4e0[NUM_TYPES_4E0];                                      /* derived name */
    hknpCollisionDetector *collisionDetectors[NUM_COLLISION_CACHE_TYPES]; /* derived name */
};

/* The reference-counted object at +0x6c8 (set by the constructor at
 * 0x49619) hands out the signals of world events (derived names):
 * FUN_0006bdf0 the signal of an event type for one body (hknpCharacterProxy
 * subscribes to type 1 of its own body at 0x1766d8 and 0x176bc8),
 * FUN_0006bf60 the signal of an event type for all (type 2 at 0x1596f5),
 * each created on first use. FUN_0004fbd0 and FUN_0004fbe0 forward to
 * them. */
struct hknpEventSignal; /* derived name */

class hknpEventDispatcher /* derived name */
{
  public:
    hknpEventSignal *FUN_0006bdf0(int eventType, int bodyId); /* derived name */
    hknpEventSignal *FUN_0006bf60(int eventType);             /* derived name */
};

/* The polymorphic object at +0x1d0 of the world (derived name), one of two
 * classes picked by the byte at +0x50 of the world's description: when it
 * is 1, a 0x1a0-byte one (constructor FUN_00150240, vtable address point
 * 0x16a4390), otherwise a 0x20-byte one (vtable address point 0x169acb0);
 * both start with a null pointer at +0x10, which FUN_00051610 returns. */
class hknpWorldObject1d0 /* derived name */
{
  public:
    /* Inline and empty: the smaller class's deleting destructor (0x6c810)
     * calls no base destructor. */
    virtual ~hknpWorldObject1d0() {}

    u8 unknown8[8];
    void *pointer10; /* derived name */
};

/* The 0x20-byte one (derived name; vtable 0x169aca0): its destructor is the
 * shared empty 0x3b640, its deleting destructor 0x6c810, which a second
 * 0x20-byte class's vtable (0x16a66c0, stored by FUN_0018d640) cites by
 * address. */
class hknpWorldObject1d0Small : public hknpWorldObject1d0 /* derived name */
{
  public:
    virtual ~hknpWorldObject1d0Small();

    /* The class allocator's delete (defined in tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    u8 unknown18[8];
};

/* hknpBody (reflected, record table at 0x1695350): 0x90 bytes as the
 * world's body array is indexed; motionId at +0x68. */
/* hknpBody (hkClass 0x57bfa50, 0x90 bytes, record table 0x1695350):
 * transform at +0, flags at +0x40, motionId at +0x68. The w lanes of the
 * transform's rotation columns hold the center of mass in the body's space
 * (FUN_0003a670 stores it there; the caller at 0x5f45b passes a world point
 * rotated into the body). */
struct hknpBody {
    void FUN_0003a670(const Vec4 &centerOfMassLocal); /* derived name */

    hkTransform transform;
    int flags;
    u8 unknown44[0x24];
    int motionId;
    u32 broadPhaseId; /* -1 while the body is not in the broad phase */
    u8 unknown70[0x20];
};

/* What the world holds at +0x10 (derived name after hknpBodyManager.cpp, the
 * file 0x1607c0 cites; the callers at 0x6c953 and 0x18d0c0 pass the
 * world's +0x10): the bodies' array from +0x10, the ids of the active
 * bodies from +0xa0. FUN_001612a0 fetches every active body ahead of the
 * solver. */
struct hknpBodyManager /* derived name */
{
    void FUN_001612a0() const; /* derived name */

    u8 unknown0[0x10];
    hkArray<hknpBody> bodies; /* derived name */
    u8 unknown20[0x80];
    hkArray<u32> activeBodyIds; /* derived name */
};

/* hknpMotion (reflected, record table at 0x16945d0): 0x80 bytes as the
 * world's motion array is indexed; cellIndex (one byte) at +0x3e. */
struct hknpMotion {
    u8 unknown0[0x3e];
    u8 cellIndex;
    u8 unknown3f;
    /* The vector FUN_0005df00 hands out for a body: its linear velocity,
     * by the next getter (0x5df30), which rotates the vector at +0x50 by
     * the quaternion at +0x10, the angular one. derived name. */
    Vec4 linearVelocity;
    u8 unknown50[0x30];
};

/* The world's motion manager at +0x110 (derived names: nothing names it):
 * the motions from +8, the highest motion index in use at +0x24, an array
 * of 16-byte arrays of 4-byte elements at +0x28 (the initializer 0x46dc0
 * resizes it and frees each element's storage). A motion is in use while
 * its byte at +0x3f is set. 0x38 bytes: the world's next member is at
 * +0x148. */
struct hknpMotionManager /* derived name */
{
    /* Out of line (0x46d80, called at 0x48b88 for the world's +0x110): the
     * arrays empty, +0x1c an invalid index, +0x20 and the peak index 0
     * (initialized in member order: the zeros from +0x20 to +0x33 are one
     * memset, cookbook 82). */
    hknpMotionManager();

    /* Walks the motions in use from index 1; 0x7fffffff once past the end
     * (the loop at 0x373c7 stops on it). */
    struct MotionIterator {
        /* Out of line (0x46d40, called at 0x373c2): starts before the first
         * and steps to it. */
        MotionIterator(const hknpMotionManager &motionManager);

        void next()
        {
            for (++index; index <= manager->peakMotionIndex; ++index) {
                if (manager->motions[index].unknown3f != 0) {
                    return;
                }
            }
            index = 0x7fffffff;
        }

        const hknpMotionManager *manager;
        u32 index;
    };

    u8 unknown0[8];
    hkArray<hknpMotion> motions;
    u32 unknown18;
    u32 unknown1c;
    u32 unknown20;
    u32 peakMotionIndex;
    hkArray<hkArray<u32>> unknown28;
};

/* The object at +0x4f8 of the world (derived names): the world at +0, the
 * object at +8 whose 16-byte records it indexes by a body's int at +0x68;
 * FUN_00062b20 takes a body id and a bool, reads the body's flags at +0x40
 * (bit 2 first) and sets or clears a byte at +0xb of the body's record. */
struct hknpWorld;

/* hknpConstraint (hkClass 0x57c2b78, built at 0x706c5: size 0x40; its
 * member records are built at run time): the two bodies' ids at +4 and
 * +0xc, which the constraint filter reads. Field names derived. */
struct hknpConstraint {
    u8 unknown0[4];
    u32 bodyIdA; /* derived name */
    u8 unknown8[4];
    u32 bodyIdB; /* derived name */
    u8 unknown10[0x30];
};

/* The reference-counted object at +0x6c0 of the world (derived names: no
 * type info names it), 0x10 bytes, built by the world's constructor at
 * 0x49a67 and released by 0x4b5bd. Its constructor 0x1585d0 clears the
 * byte at +0xc before it stores the vtable 0x16a4940 (slots 5 and 6 the
 * shared empty bodies 0x3b640 and 0xadd50): clang runs the base
 * initializers, then the vtable pointers, then the members
 * (tools/cc/src/llvm-3.3.src/tools/clang/lib/CodeGen/CGClass.cpp:1139,
 * EmitCtorPrologue), so the byte is a base class's, whose own vptr store
 * the derived one overwrites. */
class hknpWorldObject6c0Base : public hkReferencedObject /* derived name */
{
  public:
    hknpWorldObject6c0Base() : flagC(false) {}

    bool flagC; /* derived name */
};

class hknpWorldObject6c0 : public hknpWorldObject6c0Base /* derived name */
{
  public:
    hknpWorldObject6c0();
};

/* The pool at +0x6f0 of the world (derived names: nothing names it), 0x1f60
 * bytes from the thread's heap, built at 0x50325: eight contexts of 0x3c0
 * bytes from +0x10 (each constructed by 0x167cd0, which sets its index to
 * -1), handed out and taken back through a lock-free list. The head at
 * +0x1e10 holds the first free index in its low four bits and a tag above
 * them, which every take advances (0x16ff90); next[] holds each free
 * context's successor, 0xf ending the list (the world's setup at 0x5038c
 * links 0 to 7). */
struct hknpWorldContextPool /* derived name */
{
    struct Context {
        int index;
        u8 unknown4[0x3bc];
    };

    /* A context back on the list, at its own index (0x16ffe0). */
    void FUN_0016ffe0(const Context *context);

    u8 unknown0[0x10];
    Context contexts[8];
    u32 freeHead;
    int next[8];
};

/* The reference-counted object at +0x380 of the world (derived names: no
 * type info names its vtable 0x16926d0, address point 0x16926e0), 0x10
 * bytes, built by the world's constructor at 0x49c39. Its slot 15
 * (FUN_0002d770) sets the two floats at 0x16dc5e0 and 0x16dc5e4 (1 and -0.05
 * in the image), the second negated; slot 14 (0x31320) reads both. */
extern float D_16dc5e0; /* derived name */
extern float D_16dc5e4; /* derived name */

/* The 0x120-byte records it hands out (derived names): slot 8 (0x310f0)
 * allocates count of them in one block from the allocator at 0x57b8480 and
 * stores their addresses in an array, slot 9 (0x31170) frees them, slot 10
 * (0x311b0) sets each one's first pointer from a second array. */
struct hknpWorldObject380Record /* derived name */
{
    void *pointer0; /* derived name */
    u8 unknown8[0x118];
};

class hknpWorldObject380 : public hkReferencedObject /* derived name */
{
  public:
    /* Slot 9 (0x31170): the records' block back to the allocator at
     * 0x57b8480, the record pointers cleared. derived name. */
    void FUN_00031170(hknpWorldObject380Record **records, int count);
    void FUN_000311b0(hknpWorldObject380Record **records, void *const *pointers,
                      int count);                  /* vtable slot 10; derived name */
    void FUN_0002d770(float value0, float value1); /* vtable slot 15; derived name */
};

/* A list node the object at +0x388 walks (derived names): a link whose
 * next pointer (+0x10) is typed as the link, and a key byte at +0x18 the
 * node adds; consecutive nodes with the same key form a run. The walk
 * casts each link to the node (FUN_0006c2d0 keeps the pointer it tested
 * for null as its result: the cast stands between the test and the
 * return). */
struct hknpWorldObject388Link /* derived name */
{
    u8 unknown0[0x10];
    hknpWorldObject388Link *next; /* derived name */
};

struct hknpWorldObject388Node : public hknpWorldObject388Link /* derived name */
{
    u8 key; /* derived name */
};

/* The reference-counted object at +0x388 of the world (derived names: no
 * type info names its vtable 0x16a3d40, address point 0x16a3d50), 0x10
 * bytes, built by the world's constructor at 0x49c0a. Slot 6 (0xfc820)
 * processes a run of nodes and returns the node after it; slot 5
 * (FUN_0006c2d0) only skips the run. */
struct hknpWorldStepContextf6a90; /* derived name */

class hknpWorldObject388 : public hkReferencedObject /* derived name */
{
  public:
    hknpWorldObject388Node *
    FUN_0006c2d0(hknpWorldObject388Node *first); /* vtable slot 5; derived name */

    /* The constraint solve (0xc4cd0, in the second compiler generation's
     * stretch) over a step's world, its solver settings and its
     * constraints (0xf6a90, called by the step at 0x6d96e). derived name. */
    void FUN_000f6a90(const hknpWorldStepContextf6a90 *context, void *argument1, void *argument2,
                      void *argument3);
};

struct hknpWorldObject4f8 /* derived name */
{
    void FUN_00062b20(int bodyId, bool flag); /* derived name */
    /* Takes a body that is in the broad phase (0x639b0, through
     * hknpWorld::FUN_0004e0c0): reads its flags, bit 3 first. derived name. */
    void FUN_000639b0(int bodyId); /* derived name */
    /* Runs 0x63a40 on each id of an array (0x64070; the island activation
     * under the timer "TtActivateIslands" at 0x15ba28 and the step at
     * 0x6ca67 call it). derived names. */
    void FUN_00063a40(int id);
    void FUN_00064070(const hkArray<int> &ids);

    hknpWorld *world; /* derived name */
};

/* A slot of a member-function signal (vtable 0x1698ee0, ruled hkSlot, D14):
 * 0x18 bytes, its deleting destructor 0x47cc0 frees 0x18. The constructor,
 * inlined at 0x49442 and 0x156010, links the slot at the head of its
 * signal's list: next takes the signal's head without its two flag bits,
 * the head becomes this slot with the flags kept, object is the instance the
 * slot calls (the subscriber's this: %r12 at 0x4946e, %rbx at 0x15603b).
 * The derived vtables 0x1698eb0 and 0x1698f10 keep this destructor in slot
 * 0 (their implicit destructors are aliases of it), test a 16-byte
 * member-function pointer against the one they hold at +0x18 (slot 2,
 * 0x47d60) and call it on object (slot 3, 0x47c80 and 0x47d90). The signal
 * deletes its slots still linked (0x93530 walks next and calls slot 1 of
 * each), and nothing clears object after the constructor. */
class hkSlot /* derived name */
{
  public:
    virtual ~hkSlot();

    hkSlot *next; /* derived name */
    void *object; /* derived name */
};

/* hknpMaterialId, the material library's 16-bit handle (the template
 * argument of hknpMaterialFreeListArray in the scoped type names, 0x14bf3cf):
 * passed by value as a two-byte struct, so a callee widens it itself or
 * masks it. Field name derived. */
struct hknpMaterialId {
    u16 value; /* derived name */
};

struct hknpMaterial; /* the free-list array's element; fields not typed yet */
struct hknpMaterialFreeListArrayOperations;

/* hkFreeListArray, the free-list array of the scoped type names
 * (hkFreeListArray<hknpMaterial, hknpMaterialId, 8,
 * hknpMaterialFreeListArrayOperations>, 0x14bf3cf onward): elements (an
 * hkArray) at +0 and firstFree (int) at +0x10, records 0x1696a10 and
 * 0x1696a38. */
template <typename T, typename Id, int N, typename Ops> struct hkFreeListArray {
    /* A loaded image's array is left as loaded. */
    hkFreeListArray(hkFinishLoadedObjectFlag flag) : elements(flag) {}

    hkArray<T> elements;
    int firstFree;
};

/* hknpMaterialLibrary (vtable 0x1699540, type info registered at 0x6156d):
 * materialAddedSignal, materialModifiedSignal and materialRemovedSignal at
 * +0x10, +0x18 and +0x20 (not serialized, record flags 0x400) and entries,
 * the materials' free-list array, at +0x28 (records from 0x1699580). */
struct hknpMaterialLibrary : public hkReferencedObject {
    /* Inline: the type info's finish callback 0x61480 holds it. The
     * signals start empty, the entries are left as loaded. */
    hknpMaterialLibrary(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag), entries(flag) {}

    virtual ~hknpMaterialLibrary();

    Signal00093530 materialAddedSignal;
    Signal00093530 materialModifiedSignal;
    Signal00093530 materialRemovedSignal;
    hkFreeListArray<hknpMaterial, hknpMaterialId, 8, hknpMaterialFreeListArrayOperations> entries;
};

struct hknpWorld;

/* A slot calling a member function of the world with a material id (derived
 * name; vtable 0x1698f10, address point 0x1698f20): the world's constructor
 * builds two in place, for 0x4bc60 on the material library's
 * materialAddedSignal (+0x10, 0x490e9) and for 0x4bc40 on its
 * materialModifiedSignal (+0x18, 0x4914a), the member-function pointer at
 * +0x18. Slot 2 (0x47d60) compares a member-function pointer with it, slot 3
 * (FUN_00047d90, the body several slot vtables share) calls it on the
 * object. */
class hknpWorldMaterialSlot : public hkSlot /* derived name */
{
  public:
    typedef void (hknpWorld::*Method)(hknpMaterialId id); /* derived name */

    /* Slot 2 (0x47d60, the body the slot vtables share): whether a
     * member-function pointer of size bytes is the one held. */
    int FUN_00047d60(const void *otherMethod, int size) const; /* vtable slot 2; derived name */
    void FUN_00047d90(hknpMaterialId id);                      /* vtable slot 3; derived name */

    Method method; /* derived name */
};

/* The same slot for a member function taking a byte (derived name; vtable
 * 0x1698eb0, address point 0x1698ec0, 0x28 bytes): the world's constructor
 * builds one for 0x4bc90 on its quality library's qualityModifiedSignal
 * (0x4944d). Slot 3 (FUN_00047c80, the body vtable 0x16a47b0 shares, built
 * at 0x15601b) calls it on the object. */
class hknpWorldQualitySlot : public hkSlot /* derived name */
{
  public:
    typedef void (hknpWorld::*Method)(u8 id); /* derived name */

    void FUN_00047c80(u8 id); /* vtable slot 3; derived name */

    Method method; /* derived name */
};

/* The world's solver settings (derived name; at +0x390 of the world). */
struct hknpSolverInfo /* derived name */
{
    u8 unknown0[0x160];
};

void FUN_000c4cd0(hknpWorld *world, hknpSolverInfo *solverInfo, hknpConstraint *constraints,
                  int numConstraints, void *argument1, void *argument2,
                  void *argument3); /* derived name */

/* What the world hands its modifiers (derived names: the callers at
 * 0x6455d, 0x6d4b2, 0x14efc9 and 0x176310 fill one on their stack with
 * FUN_00167c90 and pass it to the modifier manager's calls, 0x657b0 among
 * them). +0x10 is not set there. */
struct ModifierSharedData /* derived name */
{
    /* From the world: its object at +0x280 when the flag at +0x278 is set,
     * the pointer at +0x1d8, the solver settings and the vector at +0x250
     * (0x167c90). */
    void FUN_00167c90(const hknpWorld *world);

    const void *object0;
    void *pointer8;
    u8 unknown10[8];
    const hknpSolverInfo *solverInfo;
    Vec4 vector20;
};

struct hknpWorldStepContextf6a90 /* derived name */
{
    u8 unknown0[8];
    hknpWorld *world; /* derived name */
};

struct hknpWorld {
    /* Hands a body id and a bool to the object at +0x4f8 when the flag at
     * +0x4f0 is set (the command dispatcher at 0x16ef96 calls it). derived
     * name. */
    void FUN_0005b560(int bodyId, bool flag);                 /* derived name */
    void FUN_0004bcc0(hknpCollisionFilter *filter);           /* derived name */
    void *FUN_00051610() const;                               /* derived name */
    hknpEventSignal *FUN_0004fbd0(int eventType, int bodyId); /* derived name */
    hknpEventSignal *FUN_0004fbe0(int eventType);             /* derived name */
    void FUN_0004bcb0(const Vec4 &newGravity);                /* derived name */
    void FUN_0004bc90(u8 id);                                 /* derived name */
    void FUN_0004bc40(hknpMaterialId id);                     /* derived name */
    void FUN_0004bc60(hknpMaterialId id);                     /* derived name */
    /* Hands a body to the object at +0x4f8 when it is in the broad phase
     * (22 callers, 0x5b711 to 0x178399). derived name. */
    void FUN_0004e0c0(int bodyId); /* derived name */
    /* A body's motion's linear velocity, by reference (0x5df00). derived
     * name. */
    const Vec4 &FUN_0005df00(int bodyId) const; /* derived name */

    u8 unknown0[0x20];
    /* The body and motion arrays: FUN_0004c170 (in this file's range) stores
     * a body's motionId and indexes both. */
    hknpBody *bodies; /* derived name */
    u8 unknown28[0xf0];
    hknpMotion *motions; /* derived name */
    u8 unknown120[0x30];
    /* The constraint array, indexed by constraint id (the constraint
     * filter's signal handlers 0x159dd0 and 0x159df0). */
    hknpConstraint *constraints; /* derived name */
    u8 unknown158[0x3c];
    /* The highest constraint id in use (0xf6a90 passes one more as the
     * count). derived name. */
    int peakConstraintId;
    u8 unknown198[0x20];
    hknpModifierManager *modifierManager; /* derived name */
    u8 unknown1c0[0x10];
    hknpWorldObject1d0 *object1d0; /* derived name */
    /* Read by FUN_00167c90 with +0x250, +0x278 and +0x280. derived names. */
    void *pointer1d8;
    u8 unknown1e0[0x70];
    Vec4 vector250;
    u8 unknown260[0x18];
    bool enabled278;
    u8 unknown279[7];
    u8 unknown280[0x108];
    hknpWorldObject388 *object388; /* derived name */
    /* The solver's settings the constraint solve (0xc4cd0) reads, floats
     * from +0 to +0x120. derived name. */
    hknpSolverInfo solverInfo;
    /* A flag and the object it enables (FUN_0005b560 forwards to the object
     * only when the flag is set). */
    bool enabled4f0;               /* derived name */
    hknpWorldObject4f8 *object4f8; /* derived name */
    u8 unknown500[0x130];
    /* The constructor copies it from hknpWorldCinfo's gravity (record at
     * 0x1698370, +0x60) at 0x48d84, and 0x4ae7e copies it back. */
    Vec4 gravity; /* derived name */
    u8 unknown640[8];
    /* The material library: the constructor subscribes 0x4bc60 to its
     * materialAddedSignal and 0x4bc40 to its materialModifiedSignal. */
    hknpMaterialLibrary *materialLibrary; /* derived name */
    u8 unknown650[0x10];
    /* A bit per material id: FUN_0004bc40, the handler of the library's
     * materialModifiedSignal, sets the id's bit; FUN_0004bc60, the handler
     * of its materialAddedSignal, keeps the field as long as the
     * library's material array. */
    hkBitField bits660; /* derived name */
    /* A bit per 8-bit id (the constructor empties it at 0x48cb5, the
     * destructor frees its words at 0x4b8c0): FUN_0004bc90, the handler the
     * world subscribes to the signal at +0x10 of its object at +0x658
     * (0x4b0d2), sets the id's bit. */
    hkBitField bits678; /* derived name */
    u8 unknown690[0x30];
    hknpWorldObject6c0 *object6c0;        /* derived name */
    hknpEventDispatcher *eventDispatcher; /* derived name */
};

/* Its hkClass (built at 0x3cfea) has hkReferencedObject's, 0x57b8640, as
 * its parent. */
class hknpFirstPersonGun : public hkReferencedObject
{
  public:
    /* The finish constructor, out of line (0x156620; its type info's
     * finish callback 0x3ccf0 jumps to it). */
    hknpFirstPersonGun(hkFinishLoadedObjectFlag flag);
    virtual ~hknpFirstPersonGun();

    virtual void unknownVirtual5();
    virtual void fireGun(hknpWorld *world,
                         const hkTransform &viewTransform); /* vtable slot 6; derived name */
    /* Slot 7: the gun's step (the empty 0xadd50 here); its last two
     * arguments are bools, widened again when forwarded. derived name. */
    virtual void stepGun(float timeStep, hknpWorld *world, const void *characterBody,
                         const hkTransform &viewTransform, bool fire, bool fireRmb);
    virtual void FUN_00156870(hknpWorld *world); /* vtable slot 8; derived name */
    virtual const char *FUN_000acf90() const;    /* vtable slot 9; derived name */
    virtual void reset(hknpWorld *world);        /* vtable slot 10; derived name */

    /* The weapon types (the reflection's item names from 0x14bacb3 onward);
     * each gun's finish constructor sets its own (0, 1 for the ball gun at
     * 0x157e2d, 4 for the mounted one at 0x166925). Enum name derived. */
    enum Type {
        WEAPON_TYPE_INVALID,
        WEAPON_TYPE_BALLGUN,
        WEAPON_TYPE_GRENADEGUN,
        WEAPON_TYPE_GRAVITYGUN,
        WEAPON_TYPE_MOUNTEDBALLGUN,
        WEAPON_TYPE_TWEAKERGUN,
        WEAPON_TYPE_MISSILEGUN,
        WEAPON_TYPE_RAYCASTGUN,
        WEAPON_TYPE_SPHEREGUN,
        WEAPON_TYPE_STICKYGUN,
        WEAPON_TYPE_NUM_TYPES
    };

    /* From +0xc, in the reference-counted object's tail: the type, then the
     * name (hkStringPtr) at +0x10 that slot 9 returns; the rest untyped.
     * hknpProjectileGun's first member sits at +0x34, in this class's
     * tail. */
    hkEnum<Type, u8> type; /* derived name */
    u8 unknown0d[0x27];
};

/* hknpProjectileGun (type info 0x57bf7e0, vtable 0x16a4b30, address point
 * 0x16a4b40; finish constructor 0x1595c0): maxProjectiles at +0x34,
 * reloadTime and reload (floats) at +0x38 and +0x3c, projectiles (an array
 * of pointers) at +0x40 and npWorld at +0x50, the last three not
 * serialized (records from 0x1695020). Slot 6 fires when reloaded and
 * starts the reload; slot 7 (0x1598c0) counts the reload down by the time
 * step and runs slot 12. */
class hknpProjectileGun : public hknpFirstPersonGun
{
  public:
    /* The finish constructor, out of line (0x1595c0; the finish callback
     * 0x39e30 jumps to it, the reflection initializer calls it at 0x39fc6):
     * the projectiles, not serialized, start as an empty array. */
    hknpProjectileGun(hkFinishLoadedObjectFlag flag);
    virtual void fireGun(hknpWorld *world,
                         const hkTransform &viewTransform); /* vtable slot 6; derived name */
    virtual void onGunFired(
        hknpWorld *world,
        const hkTransform &viewTransform); /* vtable slot 11, the empty 0x158a30; derived name */
    /* Slot 7 (0x1598c0): the reload counts down, then slot 12 runs. */
    virtual void stepGun(float timeStep, hknpWorld *world, const void *characterBody,
                         const hkTransform &viewTransform, bool fire, bool fireRmb);
    /* Slot 12 (0x1598f0): steps the projectiles. derived name. */
    virtual void updateProjectiles(float timeStep, hknpWorld *world, const void *characterBody,
                                   const hkTransform &viewTransform, bool fire, bool fireRmb);

    int maxProjectiles;
    float reloadTime;
    float reload;
    hkArray<void *> projectiles;
    hknpWorld *npWorld;
};

class hknpBallGun : public hknpFirstPersonGun
{
  public:
    /* The finish constructor, out of line (0x157e00). */
    hknpBallGun(hkFinishLoadedObjectFlag flag);

    virtual ~hknpBallGun();
};

class hknpMountedBallGun : public hknpBallGun
{
  public:
    /* The finish constructor, out of line (0x166900). */
    hknpMountedBallGun(hkFinishLoadedObjectFlag flag);

    virtual ~hknpMountedBallGun();
};

struct hknpMotionProperties; /* 0x57bf510, no vtable; the shared empty body FUN_000396a0 */

/* hknpMotionPropertiesId, the motion properties library's handle (the
 * template argument of its free-list array in the scoped type names,
 * 0x14bf45a); fields not typed yet. */
struct hknpMotionPropertiesId;
struct hknpMotionPropertiesFreeListArrayOperations;

/* hknpMotionPropertiesLibrary (type info 0x57bf0a0, vtable 0x1693770):
 * entryAddedSignal, entryModifiedSignal and entryRemovedSignal at +0x10,
 * +0x18 and +0x20 (not serialized, record flags 0x400, records from
 * 0x1694290) and entries, the motion properties' free-list array, at
 * +0x28. Its finish constructor 0x36de0 is out of line, jumped to by the
 * type info's finish callback 0x38c10 and called by the reflection
 * initializer at 0x38cc0; the signals start empty. */
struct hknpMotionPropertiesLibrary : public hkReferencedObject {
    hknpMotionPropertiesLibrary(hkFinishLoadedObjectFlag flag);
    virtual ~hknpMotionPropertiesLibrary();

    Signal00093530 entryAddedSignal;
    Signal00093530 entryModifiedSignal;
    Signal00093530 entryRemovedSignal;
    hkFreeListArray<hknpMotionProperties, hknpMotionPropertiesId, 8,
                    hknpMotionPropertiesFreeListArrayOperations>
        entries;
};

/* hknp classes registered by the reflection TU at 0x38b10 onward, each with
 * an out-of-line finish constructor (type info, the vtable it stores): */
class hknpCapsuleShape; /* 0x57bf490; 0x730d0 runs hknpConvexPolytopeShape's, vtable 0x169b260 */
class hknpConvexPolytopeShape; /* 0x57bf760; FUN_001520b0, vtable 0x16a4460 */

/* hknpShapeMassProperties (hkClass 0x57bf240, 0x30 bytes, parent
 * hkReferencedObject; type info 0x57bf290, vtable 0x1693ef0): its finish
 * constructor 0x6fa80 is out of line, jumped to by the finish callback
 * FUN_00038d60 and called by the reflection initializer at 0x39094; it
 * stores only the vtable. */
class hknpShapeMassProperties : public hkReferencedObject
{
  public:
    hknpShapeMassProperties(hkFinishLoadedObjectFlag flag);
};

/* hknpPhysicsSceneData (hkClass 0x57bf310, 0x28 bytes, parent
 * hkReferencedObject, two members in its record table at 0x1694550; type
 * info 0x57bf360, vtable 0x1697ea0): its finish constructor 0x46790 is out of
 * line, jumped to by the finish callback FUN_00039190 and called by the
 * reflection initializer at 0x39288; it stores only the vtable. */
class hknpPhysicsSceneData : public hkReferencedObject
{
  public:
    hknpPhysicsSceneData(hkFinishLoadedObjectFlag flag);
};

void FUN_000396a0(hknpMotionProperties *self, hkFinishLoadedObjectFlag flag); /* derived name */
/* More hknp classes with an out-of-line finish constructor (type info, the
 * vtable it stores): */
class hknpProjectileGun;  /* 0x57bf7e0; 0x1595c0 runs hknpFirstPersonGun's, vtable 0x16a4b30 */
class hknpFirstPersonGun; /* 0x57c0000; 0x156620, vtable 0x16a47e0 */
class hknpConstraintCollisionFilter; /* 0x57c0368; FUN_00159b40, vtable 0x16a4c20 */
struct
    hknpLodShape; /* 0x57c05b8; FUN_00068160 runs hknpShape's, stores 0x1697c80, then its own 0x1699c00 */
class hknpTriangleShape; /* 0x57c0838; 0x78230 runs hknpConvexPolytopeShape's, vtable 0x169b670 */

/* hknpDummyShape (type info 0x57bfd60; hkClass 0x57bfd10 built at 0x3bba5:
 * size 0x60, parent hknpShape's 0x57bf1c0, member records at 0x1695a70):
 * aabb (struct hkAabb) at +0x30, signals (struct hknpShapeSignals, flags
 * 0x400, not serialized) at +0x50. Its finish constructor 0x3e170 is out of
 * line, jumped to by the finish callback FUN_0003bb00 and called by the
 * reflection initializer at 0x3bbb0; the signals start empty. */
class hknpDummyShape : public hknpShape
{
  public:
    hknpDummyShape(hkFinishLoadedObjectFlag flag);
    virtual ~hknpDummyShape();

    /* Slot 7 (0x3e2f0): the AABB under the transform, grown by the convex
     * radius. */
    void unknownVirtual7(const Mat4 &transform, hkAabb &aabbOut) const;

    hkAabb aabb;
    hknpShapeSignals signals;
};

/* hknpPhysicsSystemData (type info 0x57c0198; hkClass 0x57c0148, built at
 * 0x3d115: size 0x78, parent hkReferencedObject's, member records at
 * 0x1696330; vtable 0x16a5130): arrays of materials (hknpMaterial),
 * motionProperties, motionCinfos, bodyCinfos and constraintCinfos from
 * +0x10, referencedObjects (pointers to hkReferencedObject) at +0x60, name
 * (hkStringPtr) at +0x70. Its finish constructor 0x165a80 is out of line:
 * the finish callback 0x3d070 jumps to it, the reflection initializer at
 * 0x3d123 runs it on a temporary. */
struct hknpMaterial;
struct hknpMotionCinfo;
struct hknpBodyCinfo;
struct hknpConstraintCinfo;

class hknpPhysicsSystemData : public hkReferencedObject
{
  public:
    hknpPhysicsSystemData(hkFinishLoadedObjectFlag flag);

    hkArray<hknpMaterial> materials;
    hkArray<hknpMotionProperties> motionProperties;
    hkArray<hknpMotionCinfo> motionCinfos;
    hkArray<hknpBodyCinfo> bodyCinfos;
    hkArray<hknpConstraintCinfo> constraintCinfos;
    hkArray<hkReferencedObject *> referencedObjects;
    hkStringPtr name;
};

class hknpMountedBallGun; /* 0x57c0ab8; FUN_00166900 runs FUN_00157e00, vtable 0x16a5280 */

/* hknpScaledConvexShapeBase (type info 0x57c0c78; hkClass 0x57c0bf8, built
 * at 0x3f7a3: size 0x60, parent hknpDecoratorShape; vtable 0x16a5390). */
class hknpScaledConvexShapeBase : public hknpDecoratorShape
{
  public:
    /* The finish constructor (0x16a810): the decorator's, then the
     * vtable. */
    hknpScaledConvexShapeBase(hkFinishLoadedObjectFlag flag);

    /* The record's members (0x1696dc0): two vectors. */
    Vec4 scale;
    Vec4 translation;
};

/* hknpScaledConvexShape, polymorphic, 0x70 bytes (type info 0x57c0c48,
 * vtable 0x16a54a0, address point 0x16a54b0; hkClass 0x57c0ba8 built at
 * 0x3f6ed, parent hknpScaledConvexShapeBase's), one member of its own:
 * mutationSignals (struct hknpShapeSignals, flags 0x400, record 0x1696d90)
 * at +0x60, which its destructor (0x16cf30) walks as a signal's slot list
 * and slot 8 returns, as hknpMaskedShape's slot 8 returns its own. Its
 * finish constructor FUN_0016ce90 runs the base's (0x16a810) inline: the
 * two are in one file. */
class hknpScaledConvexShape : public hknpScaledConvexShapeBase
{
  public:
    hknpScaledConvexShape(hkFinishLoadedObjectFlag flag);
    virtual ~hknpScaledConvexShape();

    hknpShapeSignals *FUN_0016ced0(); /* vtable slot 8; derived name */

    hknpShapeSignals mutationSignals;
};

/* hknpPairCollisionFilter (type info 0x57c1160; hkClass 0x57c1110, built
 * at 0x42895: size 0x28, parent hknpCollisionFilter; vtable 0x16a52f0):
 * disabledPairs (a hash map of pairs, not serialized: record flags 0x400)
 * at +0x10, childFilter (a pointer to hknpCollisionFilter) at +0x20. Each
 * of slots 5 to 9 asks the child filter first, when there is one, and slot
 * 8 then looks the pair up in the map; hknpConstraintCollisionFilter (its
 * hkClass parent) keeps all five. */
struct hknpPairCollisionFilterMapPairFilterKeyOverrideType {
    /* An empty map: no storage, no elements, the hash modulus -1. */
    hknpPairCollisionFilterMapPairFilterKeyOverrideType() : elem(0), numElems(0), hashMod(-1) {}

    void *elem;
    int numElems;
    int hashMod;
};

class hknpPairCollisionFilter : public hknpCollisionFilter
{
  public:
    /* The finish constructor (0x1673f0): the map is not serialized and
     * starts empty; the child filter is left as loaded. */
    hknpPairCollisionFilter(hkFinishLoadedObjectFlag flag);

    int FUN_001679a0(const hknpCollisionFilterContext &context,
                     hknpCollisionFilterBodyIdPair *pairs, int numPairs) const; /* derived name */
    bool FUN_00167ad0(int queryType, bool flag) const;                          /* derived name */
    bool FUN_00167be0(int queryType, const hknpCollisionFilterQueryInput &query,
                      const hknpCollisionFilterTargetInput &target) const; /* derived name */
    bool FUN_00167af0(int queryType, u32 bodyIdA, u32 bodyIdB) const;      /* derived name */
    bool FUN_00167c00(int queryType, bool targetIsB, const hknpCollisionFilterShapeInput &a,
                      const hknpCollisionFilterShapeInput &b) const; /* derived name */

    /* Disables the collisions between two bodies of a world (the pair is
     * ordered by id first, 0x167420). derived name. */
    void FUN_00167420(hknpWorld *world, u32 bodyIdA, u32 bodyIdB); /* derived name */
    /* The reverse for a pair (0x167660, ordered the same way): the int is
     * handed to the world's FUN_0005c120 with the pair. derived name. */
    int FUN_00167660(hknpWorld *world, u32 bodyIdA, u32 bodyIdB, int mode); /* derived name */

    hknpPairCollisionFilterMapPairFilterKeyOverrideType disabledPairs;
    hknpCollisionFilter *childFilter;
};

/* hknpConstraintCollisionFilter (type info 0x57c0368; hkClass 0x57c0318,
 * built at 0x3d4a5: size 0x30, parent hknpPairCollisionFilter; vtable
 * 0x16a4c20): subscribedWorld (a pointer, not serialized: flags 0x400) at
 * +0x28. FUN_00159ca0 moves its subscription to a world: the handlers
 * 0x159dd0 and 0x159df0 join the world's signals at +0x5d8 and +0x5e0,
 * which pass the world and a constraint id; the first disables the
 * collisions between the constraint's two bodies (FUN_00167420), the
 * second hands the pair to FUN_00167660 with 1. */
class hknpConstraintCollisionFilter : public hknpPairCollisionFilter
{
  public:
    /* The finish constructor (0x159b40): the pair filter's, then the
     * vtable; the subscribed world is left as loaded. */
    hknpConstraintCollisionFilter(hkFinishLoadedObjectFlag flag);

    void FUN_00159dd0(hknpWorld *world, u32 constraintId); /* derived name */
    void FUN_00159df0(hknpWorld *world, u32 constraintId); /* derived name */

    hknpWorld *subscribedWorld;
};

/* hkRelArray, the reflection's type 0x22 (the type-name table at 0x14b30e4):
 * an array stored after its owner, a 16-bit size and a 16-bit offset. */
template <typename T> class hkRelArray
{
  public:
    int getSize() const
    {
        return size;
    }

    /* The elements, `offset` bytes from the array itself. */
    const T *begin() const
    {
        return reinterpret_cast<const T *>(reinterpret_cast<const char *>(this) + offset);
    }

    u16 size;   /* derived name */
    u16 offset; /* derived name */
};

/* hknpConvexShape, 0x30 bytes (type info 0x57c1958, hkClass 0x57c1908 with
 * hknpShape as parent, vtable 0x1697d90 stored by its finish constructor
 * FUN_00042e90): one reflected member, vertices (hkRelArray of hkVector4,
 * subtype 12) at +0x28 (record 0x1699720). */
/* What slot 22 of a shape's vtable fills (derived names): hknpConvexShape's
 * (0x45aa0, kept by the sphere, capsule, triangle and polytope shapes)
 * stores the shape at +0x170, clears bit 3 of the flags at +0x150 and sets
 * the int at +0x154 to 1; hknpShape's default (0x6f7d0) reports that it is
 * not implemented, the decorator's (0x37e80) forwards to its child. */
struct hknpShapeSlot22Output /* derived name */
{
    u8 unknown0[0x150];
    u8 flags;  /* derived name */
    int value; /* derived name */
    u8 unknown158[0x18];
    const hknpShape *shape; /* derived name */
};

/* What slot 29 of the convex shapes reads (derived names): an int at +0
 * and two vectors at +0x20 and +0x40, which FUN_00169330 applies to the
 * shape's vertices as v * scale + offset. */
struct hknpShapeSlot29Input /* derived name */
{
    int mode; /* derived name */
    u8 unknown4[0x1c];
    Vec4 scale; /* derived name */
    u8 unknown30[0x10];
    Vec4 offset; /* derived name */
};

class hknpConvexShape;

/* Fills the output from the shape's vertices (its slot 13 gives their
 * count), at most maxCount of them (0x169330). derived names. */
void FUN_00169330(const hknpConvexShape *shape, int mode, const Vec4 &scale, const Vec4 &offset,
                  void *output, int maxCount);

class hknpConvexShape : public hknpShape
{
  public:
    /* The finish constructor, out of line (0x42e90). */
    hknpConvexShape(hkFinishLoadedObjectFlag flag);

    int FUN_000430e0() const;         /* vtable slot 6; derived name */
    int FUN_00045ac0() const;         /* vtable slot 9; derived name */
    const Vec4 *FUN_00045ad0() const; /* vtable slot 10; derived name */
    int FUN_00045a80(u32 *argument1, int argument2, int argument3,
                     const u32 *argument4) const; /* vtable slot 21; derived name */
    void FUN_00045aa0(const void *argument1, const void *argument2,
                      hknpShapeSlot22Output *output) const; /* vtable slot 22; derived name */
    /* Slot 29, kept by the convex, triangle, convex polytope and scaled
     * convex shapes' vtables. */
    void FUN_000430f0(const hknpShapeSlot29Input &input,
                      void *output) const; /* vtable slot 29; derived name */

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
    /* The finish constructor, out of line (0x1520b0; the capsule's 0x730d0
     * and the triangle's 0x78230 run it): hknpConvexShape's, the vtable, and
     * flags 3 when finishing. */
    hknpConvexPolytopeShape(hkFinishLoadedObjectFlag flag);

    /* hknpConvexPolytopeShape::Face (records from 0x1694e60): firstIndex
     * (hkUint16) at +0, numIndices and minHalfAngle (hkUint8) at +2 and
     * +3. */
    struct Face {
        u16 firstIndex;
        u8 numIndices;
        u8 minHalfAngle;
    };
    class Connectivity;

    int FUN_00072f70() const; /* vtable slot 13; derived name */
    /* Slot 14 (0x72f80, kept by the capsule and triangle shapes): a face's
     * plane and its minimum half angle. derived name. */
    void FUN_00072f80(int faceIndex, Vec4 &planeOut, u8 &minAngleOut) const;

    /* The bytes a polytope shape of a class of sizeOfBaseClass bytes
     * needs with its vertices, faces, planes and indices after it, each
     * block rounded up to 16 (0x1542f0). derived names. */
    static int FUN_001542f0(int numVertices, int numFaces, int numIndices,
                            int sizeOfBaseClass); /* derived name */

    hkRelArray<Vec4> planes;
    hkRelArray<Face> faces;
    hkRelArray<u8> indices;
    Connectivity *connectivity;
};

/* hknpCapsuleShape (type info 0x57bf490; hkClass 0x57bf440, built at
 * 0x39545: size 0x60, parent hknpConvexPolytopeShape, member records at
 * 0x1694850; vtable 0x169b260): the segment's ends a and b at +0x40 and
 * +0x50. Slot 6 (0x73170) is its size with the polytope it carries, eight
 * vertices, six faces and 24 indices. */
class hknpCapsuleShape : public hknpConvexPolytopeShape
{
  public:
    /* The finish constructor, out of line (0x730d0, jumped to by the finish
     * callback FUN_000394a0). */
    hknpCapsuleShape(hkFinishLoadedObjectFlag flag);

    int FUN_00073170() const; /* vtable slot 6; derived name */

    Vec4 a;
    Vec4 b;
};

/* hknpSphereShape (type info 0x57c2798, vtable 0x1695c10) over
 * hknpConvexShape, and hknpTriangleShape (type info 0x57c0838, vtable
 * 0x169b670) over hknpConvexPolytopeShape: finish constructors out of line
 * (0x3c540, 0x78230), jumped to by the finish callbacks FUN_0006b6b0 and
 * FUN_0003e730. */
class hknpSphereShape : public hknpConvexShape
{
  public:
    hknpSphereShape(hkFinishLoadedObjectFlag flag);
};

class hknpTriangleShape : public hknpConvexPolytopeShape
{
  public:
    hknpTriangleShape(hkFinishLoadedObjectFlag flag);
};

/* hknpConvexPolytopeShape::Connectivity (scoped name of the type info;
 * vtable 0x1694e20, finish callback FUN_00039ae0): the shape's
 * connectivity pointer at +0x38 refers to one. */
class hknpConvexPolytopeShape::Connectivity : public hkReferencedObject
{
  public:
    Connectivity(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hknpBreakableConstraintData, polymorphic, 0x28 bytes (type info
 * 0x57c23f8, vtable 0x1695b10): its one reflected member, threshold (float),
 * sits at +0x20 (record table 0x169a740); its constructor FUN_0003c210 sets
 * it to 10. FUN_0003c270 and FUN_0003c280 read and write it (the class is
 * defined after hkpWrappedConstraintData, its parent, as is
 * hknpMalleableConstraintData). Both are built by the game code at 0xea7a00
 * and 0xea8280. */

/* hknpWorldCinfo (type info 0x57c13e0, hkClass 0x57c1390, no vtable; 0xf0
 * bytes, as hknpRefWorldCinfo's size gives it): an empty finish
 * constructor (the shared body FUN_0003b640) and an out-of-line destructor
 * FUN_0003b650, which releases the references from +0xb0 down. */
struct hknpWorldCinfo {
    u8 unknown0[0xa8];
    /* Two of the references the destructor releases (it goes on below
     * +0xa8). */
    hkReferencedObject *referenceA8; /* derived name */
    hkReferencedObject *referenceB0; /* derived name */
    u8 unknownB8[0x38];
};

void FUN_0003b640(hknpWorldCinfo *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0003b650(hknpWorldCinfo *self);                                /* derived name */

/* hknpRefWorldCinfo (hkClass 0x57bf2c0, built at 0x39330: size 0x100,
 * parent hkReferencedObject's 0x57b8640, one member record at 0x16945a0;
 * vtable 0x1694510): info (a struct of class hknpWorldCinfo) at +0x10. The
 * finish callback 0x391c0 constructs it in place; the complete destructor
 * 0x39100 destroys the info. */
class hknpRefWorldCinfo : public hkReferencedObject
{
  public:
    hknpRefWorldCinfo(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag)
    {
        FUN_0003b640(&info, flag);
    }

    virtual ~hknpRefWorldCinfo();

    hknpWorldCinfo info;
};

/* hknpWorldSnapshot (type info 0x57c0638; hkClass 0x57c05e8, built at
 * 0x3e0c5: size 0x140, parent hkReferencedObject's, member records at
 * 0x16966e0; vtable 0x16a4d50): worldCinfo (hknpWorldCinfo) at +0x10, then
 * arrays of bodies (hknpBody), bodyNames (hkStringPtr), motions
 * (hknpMotion) and constraints (hknpConstraintCinfo) from +0x100. Its
 * finish constructor 0x15bf30 is out of line: the finish callback 0x3e020
 * jumps to it, the reflection initializer at 0x3e0d4 runs it on a
 * temporary. */
struct hknpBody;
struct hknpConstraintCinfo;

class hknpWorldSnapshot : public hkReferencedObject
{
  public:
    hknpWorldSnapshot(hkFinishLoadedObjectFlag flag);

    hknpWorldCinfo worldCinfo;
    hkArray<hknpBody> bodies;
    hkArray<hkStringPtr> bodyNames;
    hkArray<hknpMotion> motions;
    hkArray<hknpConstraintCinfo> constraints;
};

class hknpMalleableConstraintData; /* 0x57c18d8; FUN_00067960 runs 0x7d520, vtable 0x1699a90 */

void FUN_00067960(hknpMalleableConstraintData *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */

/* hknpBodyQuality (hkClass 0x57bee30, built at 0x3894a), 16 bytes: the
 * member strings supportedFlags, requestedFlags and
 * contactCachingRelativeMovementThreshold (0x14bd85e onward); the library
 * cinfo's setup (0x71330) sets the int at +0 to ten times the quality's
 * index and edits the flags at +4. */
struct hknpBodyQuality {
    /* 0x16a380, run by 0x71330 on each of the library's qualities with the
     * cinfo's unit scale, which it does not read: all cleared, every flag
     * supported, the threshold 0.1. derived name. */
    void FUN_0016a380(float unitScale);

    int priority; /* derived name */
    u32 supportedFlags;
    u32 requestedFlags;
    float contactCachingRelativeMovementThreshold;
};

/* hknpBodyQualityLibrary (type info 0x57c1a78; hkClass 0x57c1a28, built at
 * 0x61e85: size 0x220, parent hkReferencedObject's 0x57b8640, member
 * records at 0x16997a0; vtable 0x169b150): qualityModifiedSignal (not
 * serialized: record flags 0x400) at +0x10, qualities (hknpBodyQuality) from
 * +0x20. Finish constructor FUN_00071190, complete destructor 0x70f50. */
struct hknpBodyQualityLibrary : public hkReferencedObject {
    virtual ~hknpBodyQualityLibrary();

    Signal00093530 qualityModifiedSignal;
    u8 unknown18[8];
    hknpBodyQuality qualities[32];
};

void FUN_00071190(hknpBodyQualityLibrary *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* What the world's constructor sets its body quality library up with (the
 * library, 0x220 bytes, built by 0x70ff0 at 0x49362, takes it at 0x49410
 * through 0x71330): built on the stack by its constructor, then each member
 * copied from the hknpWorldCinfo member of the same name (records 0x1698668,
 * 0x16984d8, 0x1698500, 0x1698398). Member names from those records. */
struct hknpBodyQualityLibraryCinfo /* derived name */
{
    hknpBodyQualityLibraryCinfo();

    float unitScale;
    hkBool enableWeldingForDefaultObjects;
    hkBool enableWeldingForCriticalObjects;
    hkBool enableContactCaching;
};

/* hknpMaterial (type info 0x57c1f40, no vtable, cleanup 0x300) and
 * hknpMaterialDescriptor (type info 0x57c1fc0, no vtable, cleanup 0x66e80):
 * each finish constructor (FUN_0006c6f0, FUN_0006c800) runs hkStringPtr's on
 * the name at +0. */
struct hknpMaterial {
    /* Inline where hknpRefMaterial's finish constructor and destructor run
     * them (0x6c7e0, 0x6c5d0 finish and destroy the name directly). */
    hknpMaterial(hkFinishLoadedObjectFlag flag)
    {
        FUN_0000e5c0(&name, flag);
    }

    ~hknpMaterial()
    {
        FUN_0000e5d0(&name);
    }

    /* Out of line (0x6c700; the material library's copies at 0x776d0,
     * 0x77976 and 0x77a8f): the name copied as a string, the rest as bytes. */
    hknpMaterial(const hknpMaterial &other);

    hkStringPtr name; /* derived name */
    u8 unknown8[0x48];
};

struct hknpMaterialDescriptor {
    hkStringPtr name; /* derived name */
};

void FUN_0006c6f0(hknpMaterial *self, hkFinishLoadedObjectFlag flag);           /* derived name */
void FUN_0006c800(hknpMaterialDescriptor *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* hknpRefMaterial (type info 0x57c2040; hkClass 0x57c1ff0, built at
 * 0x67838: size 0x60, parent hkReferencedObject's 0x57b8640, one member
 * record at 0x1699940; vtable 0x169ac60): material (a struct of class
 * hknpMaterial, 0x50 bytes) at +0x10. Its finish constructor 0x6c7e0 is out
 * of line (the finish callback 0x66ef0 jumps to it, the reflection
 * initializer at 0x67847 runs it on a temporary); complete destructor
 * 0x6c5d0. */
class hknpRefMaterial : public hkReferencedObject
{
  public:
    hknpRefMaterial(hkFinishLoadedObjectFlag flag);
    virtual ~hknpRefMaterial();

    hknpMaterial material;
};
class hknpBallGun; /* 0x57c20c0; FUN_00157e00 runs hknpFirstPersonGun's, vtable 0x16a48d0 */
class hknpBreakableConstraintData; /* 0x57c23f8; FUN_0003c240 runs 0x7d520, vtable 0x1695b10 */
struct
    hknpCompressedMeshShape; /* 0x57c26c8; FUN_00158610 runs hknpShape's, then vtable 0x16a4990 */

/* hknpBreakableConstraintData's finish constructor (0x3c240, the class's
 * constructor below), called by name from its finish callback while the
 * class has pure slots this header does not override. derived name. */
void FUN_0003c240(hknpBreakableConstraintData *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */

/* hknpDestructionShapeProperties (type info 0x57c2648; hkClass 0x57c25f8,
 * built at 0x6b465: size 0x70, parent hkReferencedObject's, member records
 * at 0x169a9a0; vtable 0x16a5940): worldFromShape (a transform) at +0x10,
 * sceneNodeUuid (hkUuid) at +0x50, isHierarchicalCompound and
 * hasDestructionShapes (hkBool) at +0x60 and +0x61. Its finish constructor
 * 0x175a50 is out of line: the finish callback 0x6b3c0 jumps to it, the
 * reflection initializer at 0x6b473 runs it on a temporary. */
class hknpDestructionShapeProperties : public hkReferencedObject
{
  public:
    hknpDestructionShapeProperties(hkFinishLoadedObjectFlag flag);

    hkTransform worldFromShape;
    hkUuid sceneNodeUuid;
    hkBool isHierarchicalCompound;
    hkBool hasDestructionShapes;
};

void FUN_00158610(hknpCompressedMeshShape *self, hkFinishLoadedObjectFlag flag); /* derived name */
/* Slot 17 of hknpSphereShape's vtable (address point 0x1695c20) returns pi,
 * hknpCapsuleShape's (0x169b270) pi / 2. */
float FUN_0003c660(const hknpSphereShape *self); /* derived name */

/* hknpCompressedMeshShapeData (hkClass 0x57be1a0; record table 0x1692b40):
 * meshTree (hknpCompressedMeshShapeTree) at +0x10, simdTree at +0xb0,
 * connectivity at +0xc8. */
struct hknpCompressedMeshShapeData : public hkReferencedObject {
    /* Inline where its type info's finish callback (0x34da0) runs it: the
     * mesh tree's finish (0xa9140), then the SIMD tree's. */
    hknpCompressedMeshShapeData(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), meshTree(flag), simdTree(flag)
    {
    }

    hknpCompressedMeshShapeTree meshTree;
    hkcdSimdTree simdTree;
};

/* hknpCompressedMeshShape (its records at 0x169aa40: data, a pointer to
 * hknpCompressedMeshShapeData, at +0x58; quadIsFlat and triangleIsInterior
 * at +0x60 and +0x78; numTriangles at +0x90): FUN_0010bf40 returns the mesh
 * tree's domain, which slot 7 of its vtable (0x158840, address point
 * 0x16a49a0) transforms into the AABB it reports (0x94060). */
class hknpCompressedMeshShape : public hknpShape
{
  public:
    virtual ~hknpCompressedMeshShape();

    const hkAabb *FUN_0010bf40() const; /* derived name */
    void FUN_00158840(const Mat4 &transform,
                      hkAabb &aabbOut) const; /* vtable slot 7; derived name */

    u8 unknown28[0x30];
    hknpCompressedMeshShapeData *data;
};

float FUN_00073940(const hknpCapsuleShape *self); /* derived name */

/* hknpExternMeshShape (type info 0x57c28e8, size 0x70): its finish
 * constructor runs hknpShape's, stores 0x1697c80, sets bit 2 of the byte at
 * +0x10 when finishing, then stores its own vtable 0x16a5170. */
class hknpExternMeshShape;

/* hknpBroadPhaseConfig (hkClass 0x57c0248, size 0x10, no members of its own)
 * and hknpDefaultBroadPhaseConfig (hkClass 0x57c0298, size 0x30, parent
 * hknpBroadPhaseConfig; type info 0x57c02e8, vtable 0x16a45f0, address point
 * 0x16a4600), registered by the initializer at 0x3d1f0. The one member,
 * layers (record table 0x16964a0), is a C array of four
 * hknpBroadPhaseConfig::Layer (hkClass 0x57c01c8, size 8, records at
 * 0x1696450: collideWithLayerMask, hkUint32, at +0; isVolatile, hkBool, at
 * +4) at +0xc, in the tail padding of the base; the constructor at 0x154da0
 * fills the four layers. hknpBroadPhaseConfig's hkClass parent is
 * hkReferencedObject (built at 0x3d297). hknpDefaultBroadPhaseConfig's finish
 * constructor 0x154d90 is out of line, jumped to by the finish callback
 * FUN_0003d1d0 and called by the reflection initializer at 0x3d387. */
class hknpBroadPhaseConfig : public hkReferencedObject
{
  public:
    struct Layer {
        u32 collideWithLayerMask;
        bool isVolatile;
    };

    hknpBroadPhaseConfig(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    virtual ~hknpBroadPhaseConfig();
};

class hknpDefaultBroadPhaseConfig : public hknpBroadPhaseConfig
{
  public:
    hknpDefaultBroadPhaseConfig(hkFinishLoadedObjectFlag flag);

    Layer *FUN_00154e00(hkUlong layerIndex); /* vtable slot 6; derived name */

    Layer layers[4];
};

/* Constraint data atoms (hkp, the constraint solver's reflection TUs from
 * 0x7ac40): each Atoms struct's finish constructor sets the int at +0x94
 * (-1, or a packed pair when finishing), and its finish callback runs it.
 * hkpLinearClearanceConstraintData::Atoms: type info 0x57c36b8, size 0x120,
 * 0x83880. hkpPrismaticConstraintData::Atoms: type info 0x57c4058,
 * size 0x100, 0x7e520. */
/* What slot 20 of the constraint data vtables fills (pure in
 * hkpConstraintData): the size of the runtime the solver keeps for the
 * constraint and its number of solver results, two ints stored as one 8-byte
 * constant by the overrides. The callers (0x679b0, 0x17565d) pass a bool
 * before it and read the second int. Names derived. */
struct ConstraintRuntimeInfo /* derived name */
{
    int sizeOfExternalRuntime; /* derived name */
    int numSolverResults;      /* derived name */
};

/* One solver result of a constraint (derived names): 8 bytes, the impulse
 * the solver applied first. Slot 19 of the fixed, ball-and-socket and
 * deformable fixed data (0x7c000) reads the first three results' impulses. */
struct hkpSolverResults /* derived name */
{
    /* Nothing applied yet (0x79114 clears four). derived name. */
    void init()
    {
        impulseApplied = 0.0f;
        internalSolverData = 0.0f;
    }

    float impulseApplied;     /* derived name */
    float internalSolverData; /* derived name */
};

/* hkpConstraintData, the constraint data base (hkClass 0x57c45a8, built at
 * 0x7f444, 0x18 bytes, parent hkReferencedObject; finish constructor
 * 0x82850 stores its vtable 0x169fac0, address point 0x169fad0, whose
 * slots 5 to 7 and 20 are pure). Slots 8 to 10 default to the empty body
 * 0x3b640; slots 11 to 13, kept by twenty-odd constraint data vtables,
 * return the largest float Havok uses (0x7f7fffee) for the linear, angular
 * and breach impulse limits; slot 15 (0x82bc0) returns 255; slot 24
 * defaults to the empty body too. */
/* The string library's memory fill (derived name; a wrapper over memset). */
void FUN_00018160(void *dst, int value, unsigned int n); /* derived name */

class hkpConstraintData : public hkReferencedObject
{
  public:
    hkpConstraintData(hkFinishLoadedObjectFlag flag);

    /* What slot 6 fills (derived names): hkpFixedConstraintData's override
     * (0x7bf20) hands its 0xc0 bytes of atoms and this argument to
     * FUN_00082890, which stores the atoms and their size at +0x10 and
     * +0x18, zeroes the four counts from +0 and adds the jacobian header's
     * 32 bytes to the schemas' size at +4, then each atom's schema size,
     * solver results (+8) and temporaries (+0xc); some atoms add to +0x1c.
     * hkpPointToPathConstraintData's override (0x7a020) adds its own. */
    struct ConstraintInfo {
        void clear()
        {
            maxSizeOfSchema = 0;
            sizeOfSchemas = 0;
            numSolverResults = 0;
            numSolverElemTemps = 0;
        }

        void addHeader()
        {
            sizeOfSchemas += 32;
        }

        void add(int schemaSize, int solverResults, int solverElemTemps)
        {
            sizeOfSchemas += schemaSize;
            numSolverResults += solverResults;
            numSolverElemTemps += solverElemTemps;
        }

        int maxSizeOfSchema;    /* derived name */
        int sizeOfSchemas;      /* derived name */
        int numSolverResults;   /* derived name */
        int numSolverElemTemps; /* derived name */
        const void *atoms;      /* derived name */
        int sizeOfAllAtoms;     /* derived name */
        int unknown1c;
    };

    /* derived name: what the slot 6 overrides call with their atoms, the
     * atoms' size and the argument (0x82890). */
    static void FUN_00082890(const void *atoms, int sizeOfAtoms, ConstraintInfo &infoOut);

    virtual int unknownVirtual5() const = 0;
    virtual void unknownVirtual6(ConstraintInfo &infoOut) const = 0;
    /* Slot 7 (pure): whether the data is usable; an hkBool, which the
     * wrapped data's forwarder (FUN_00067c60) passes on with a jmp (a bool
     * would keep the call, cookbook 25). */
    virtual hkBool unknownVirtual7() const = 0;
    virtual void unknownVirtual8();
    virtual void unknownVirtual9();
    virtual void unknownVirtual10();
    virtual float FUN_00082b90() const; /* vtable slot 11; derived name */
    virtual float FUN_00082ba0() const; /* vtable slot 12; derived name */
    virtual float FUN_00082bb0() const; /* vtable slot 13; derived name */
    virtual void unknownVirtual14();
    virtual int unknownVirtual15() const;
    virtual void unknownVirtual16();
    virtual void unknownVirtual17();
    virtual void unknownVirtual18();

    /* Slot 19's default, kept by most constraint data vtables (the copy at
     * 0x7b5a0 sits in the file of the class whose slot 5 is 0x7b560, type
     * code 22): zeroes the vector its fifth argument points to. The three
     * arguments before it are integers or pointers, not recovered. */
    virtual void FUN_0007b5a0(const void *argument1, const void *argument2, const void *argument3,
                              Vec4 &out) const; /* vtable slot 19; derived name */

    /* Slot 20 (pure): the runtime size and solver result count. The flag is
     * an hkBool, not a bool: the wrapped data's forwarder (FUN_00067b30)
     * passes it on without widening it (cookbook 17). */
    virtual void unknownVirtual20(hkBool wantRuntime, ConstraintRuntimeInfo &infoOut) const = 0;
    /* Slot 21: by default (the shared FUN_00013e90) the solver results are
     * the runtime itself. */
    virtual void *unknownVirtual21(void *runtime) const;
    /* Slot 22's default, kept by every constraint data vtable read so far:
     * a new instance's runtime, when it has one, starts zeroed. */
    virtual void FUN_00082860(void *runtime,
                              int sizeOfRuntime) const; /* vtable slot 22; derived name */
    virtual void unknownVirtual23();

    /* Slot 24, the empty body 0x3b640 by default: the call a bridge atom
     * makes into the data it wraps (FUN_0007d020). derived name. */
    virtual void buildJacobianCallback(const void *input, void *output);

    u8 unknownC[0xc];
};

/* hkpSetLocalTransformsConstraintAtom (reflected): transformA and
 * transformB (hkTransform) at +0x10 and +0x50 (member records 0x169e560 and
 * 0x169e588), after the atom's type and padding. */
struct hkpSetLocalTransformsConstraintAtom {
    u16 type; /* derived name */
    u8 padding[0xe];
    hkTransform transformA;
    hkTransform transformB;
};

/* hkpSetLocalRotationsConstraintAtom (hkClass 0x57c51f0, size 0x70, record
 * table 0x169e510): rotationA and rotationB (TYPE_ROTATION, three columns)
 * at +0x10 and +0x40, after the atom's type and padding. */
struct hkpSetLocalRotationsConstraintAtom {
    u16 type; /* derived name */
    u8 padding[0xe];
    hkMatrix3 rotationA;
    hkMatrix3 rotationB;
};

/* Two constraint atoms with their reflected members: hkpSetupStabilizationAtom
 * (record table 0x169e600: enabled at +2, padding at +3, maxLinImpulse at
 * +4, maxAngImpulse at +8, maxAngle at +0xc) and hkpBallSocketConstraintAtom
 * (records built by the initializer at 0x80a40: solvingMethod at +2,
 * bodiesToNotify at +3, velocityStabilizationFactor at +4,
 * enableLinearImpulseLimit at +5, breachImpulse at +8,
 * inertiaStabilizationFactor at +0xc). The u16 at +0 is the atom's type,
 * which the constructors store. */
/* hkpSetLocalTranslationsConstraintAtom (reflected): translationA and
 * translationB (hkVector4) at +0x10 and +0x20 (member records 0x169e5b0 and
 * 0x169e5d8), after the atom's type and padding. */
struct hkpSetLocalTranslationsConstraintAtom {
    u16 type; /* derived name */
    u8 padding[0xe];
    Vec4 translationA;
    Vec4 translationB;
};

/* hkpConstraintAtom (hkClass 0x57c4650, size 2): the atoms' base. Of its
 * three enums (records from 0x169ed60) the third is SolvingMethod, items
 * METHOD_STABILIZED 0 and METHOD_OLD 1 (0x169ed48, 0x169ed58). */
struct hkpConstraintAtom {
    enum SolvingMethod { METHOD_STABILIZED = 0, METHOD_OLD = 1 };
};

struct hkpSetupStabilizationAtom {
    u16 type; /* derived name */
    hkBool enabled;
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

/* hkpLinFrictionConstraintAtom (0x10 bytes, records built at 0x815b4):
 * isEnabled and frictionAxis (hkUint8) at +2 and +3, maxFrictionForce at
 * +4, padding (8 bytes, not serialized) at +8. */
struct hkpLinFrictionConstraintAtom {
    u16 type; /* derived name */
    u8 isEnabled;
    u8 frictionAxis;
    float maxFrictionForce;
    u8 padding[8];
};

class hkpConstraintMotor;

struct hkpLinMotorConstraintAtom {
    hkpLinMotorConstraintAtom(hkFinishLoadedObjectFlag)
    {
        initializedOffset = -1;
        previousTargetPositionOffset = -1;
    }

    u16 type;         /* derived name */
    hkBool isEnabled; /* TYPE_BOOL in the record */
    u8 motorAxis;
    s16 initializedOffset;
    s16 previousTargetPositionOffset;
    hkpConstraintMotor *motor;
    float targetPosition;
    u8 padding[12]; /* not serialized: the atom is 0x20 bytes */
};

class hkpPrismaticConstraintData : public hkpConstraintData
{
  public:
    /* Members from the record table 0x169cb60: transforms at +0, motor
     * (hkpLinMotorConstraintAtom) at +0x90, friction, ang, lin0, lin1 and
     * linLimit from +0xb0. Its finish constructor (0x7e520) is out of line:
     * when finishing, the motor's offsets into the runtime are set. */
    struct Atoms {
        Atoms(hkFinishLoadedObjectFlag flag);

        hkpSetLocalTransformsConstraintAtom transforms;
        hkpLinMotorConstraintAtom motor;
        hkpLinFrictionConstraintAtom friction;
        u8 unknownC0[0x40]; /* ang, lin0, lin1, linLimit */
    };

    /* What the solver keeps for the constraint (derived names): its first
     * four solver results are the motor's and the friction's. */
    struct Runtime {
        hkpSolverResults solverResults[4];
    };

    /* The finish constructor (0x7ce10; hkClass 0x57c4088 built at 0x7cf8e,
     * 0x120 bytes, parent hkpConstraintData's 0x57c45a8): the atoms finish
     * themselves. vtable 0x169d1f0, address point 0x169d200. */
    hkpPrismaticConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpPrismaticConstraintData();

    void FUN_0007e870(
        hkpConstraintData::ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    /* The motor on or off, the friction the other way, and the runtime's
     * motor and friction results cleared when there is one (0x7e910,
     * called by the game at 0xeb1966). derived name. */
    void FUN_0007e910(void *runtime, hkBool isEnabled);
    void FUN_0007e890(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

    Atoms atoms;
};

/* Polymorphic constraint data classes with no member read yet (vtable
 * address points; the class names from the type-info registrations of their
 * finish constructors). hkpPointToPathConstraintData: 0x169bc50 (finish
 * constructor FUN_0007f120). hkpCogWheelConstraintData: 0x169c2c0
 * (FUN_0007c9d0). hkpRagdollLimitsData: 0x169c950 (FUN_000788f0); its slot
 * 20 (0x7c8b0) is also hkpHingeLimitsData's (0x169fef0, FUN_00082250). */
class hkpPointToPathConstraintData; /* defined after hkEnum */

void FUN_0007f120(void *object, int finishing); /* derived name */

/* hkpCogWheelConstraintData (hkClass 0x57c3e88, built at 0x7cb3b, 0xc0 bytes, parent hkpConstraintData; vtable 0x169c2b0): atoms at +0x20 (record table 0x169ca30: transforms at +0, cogWheels at +0x90). */
class hkpCogWheelConstraintData : public hkpConstraintData
{
  public:
    /* 0xa0 bytes at +0x20 (what slot 6 hands on). */
    struct Atoms {
        hkpSetLocalTransformsConstraintAtom transforms;
        u8 cogWheels[0x10];
    };

    /* The finish constructor (0x7c9d0): the atoms are left as loaded. */
    hkpCogWheelConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpCogWheelConstraintData();

    void FUN_0007b570(
        hkpConstraintData::ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    void FUN_0007b590(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

    Atoms atoms;
};

/* Constraint data classes known by their slot 6 alone (vtable address points
 * from their type-info registrations; the atoms at +0x20 and their size are
 * what slot 6 hands to FUN_00082890). */
/* hkpStiffSpringConstraintAtom (hkClass 0x57c53f0, size 0x20, record
 * table 0x169e6d0): length, maxLength, springConstant and springDamping
 * (floats) from +0x10, after the atom's type and padding. */
struct hkpStiffSpringConstraintAtom {
    u16 type; /* derived name */
    u8 padding[0xe];
    float length;
    float maxLength;
    float springConstant;
    float springDamping;
};

/* hkpStiffSpringConstraintData::Atoms (hkClass 0x57c3568, size 0x60, record
 * table 0x169beb0): pivots at +0, setupStabilization at +0x30, spring at
 * +0x40. Slot 7 (0x7d710) tells whether the spring's length is positive and
 * within its maximum. */
/* hkpStiffSpringConstraintData (hkClass 0x57c35e8, built at 0x7abbb, 0x80
 * bytes, parent hkpConstraintData; vtable 0x169cfe0). */
class hkpStiffSpringConstraintData : public hkpConstraintData /* vtable address point 0x169cff0 */
{
  public:
    struct Atoms {
        hkpSetLocalTranslationsConstraintAtom pivots;
        hkpSetupStabilizationAtom setupStabilization;
        hkpStiffSpringConstraintAtom spring;
    };

    /* The finish constructor (0x7aa50): the atoms are left as loaded. */
    hkpStiffSpringConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpStiffSpringConstraintData();

    void FUN_0007d6e0(
        hkpConstraintData::ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    hkBool FUN_0007d710() const;                           /* vtable slot 7; derived name */

    Atoms atoms;
};

/* hkpPulleyConstraintAtom (hkClass 0x57c5070, size 0x40, record table
 * 0x169e380): fixedPivotAinWorld and fixedPivotBinWorld (hkVector4) at
 * +0x10 and +0x20, ropeLength and leverageOnBodyB (floats) at +0x30, after
 * the atom's type and padding. */
struct hkpPulleyConstraintAtom {
    u16 type; /* derived name */
    u8 padding[0xe];
    Vec4 fixedPivotAinWorld;
    Vec4 fixedPivotBinWorld;
    float ropeLength;
    float leverageOnBodyB;
};

/* hkpPulleyConstraintData::Atoms (hkClass 0x57c3768, size 0x70, record
 * table 0x169c1b0): translations (an hkpSetLocalTranslationsConstraintAtom)
 * at +0, pulley at +0x30. Slot 7 (0x825a0) tells whether the rope's length
 * and the leverage are positive. */
/* hkpPulleyConstraintData (hkClass 0x57c37e8, built at 0x7b02b, 0x90 bytes, parent hkpConstraintData; vtable 0x169f5f0). */
class hkpPulleyConstraintData : public hkpConstraintData /* vtable address point 0x169f600 */
{
  public:
    struct Atoms {
        hkpSetLocalTranslationsConstraintAtom translations;
        hkpPulleyConstraintAtom pulley;
    };

    /* The finish constructor (0x7aec0): the atoms are left as loaded. */
    hkpPulleyConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpPulleyConstraintData();

    void FUN_00082570(
        hkpConstraintData::ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    hkBool FUN_000825a0() const;                           /* vtable slot 7; derived name */

    Atoms atoms;
};

/* Slots 6 (0x83000) and 20 (0x83020) are also hkpWheelConstraintData's
 * (0x16a5e20). */
/* hkpDeformableFixedConstraintData (hkClass 0x57c34e8, parent
 * hkpConstraintData, 0x170 bytes; vtable 0x169fdf0, address point
 * 0x169fe00): its one member atoms at +0x20 (record 0x169be80) is an
 * hkpDeformableFixedConstraintData::Atoms, 0x150 bytes (record table
 * 0x169be00: transforms at +0, lin, an hkpDeformableLinConstraintAtom, at
 * +0x90, ang, an hkpDeformableAngConstraintAtom, at +0xf0). */
class hkpDeformableFixedConstraintData : public hkpConstraintData
{
  public:
    struct Atoms {
        hkpSetLocalTransformsConstraintAtom transforms;
        u8 lin[0x60];
        u8 ang[0x60];
    };

    /* The finish constructor (0x7a830): the atoms are left as loaded. */
    hkpDeformableFixedConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpDeformableFixedConstraintData();

    void FUN_00083000(
        hkpConstraintData::ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    void FUN_00083020(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

    Atoms atoms;
};

/* hkpHingeLimitsData (hkClass 0x57c5928, built at 0x823be, 0xc0 bytes,
 * parent hkpConstraintData; vtable 0x169fee0, address point 0x169fef0):
 * atoms at +0x20, an hkpHingeLimitsData::Atoms of 0xa0 bytes (record table
 * 0x169f4a0: rotations at +0, angLimit at +0x70, 2dAng at +0x90). Its slot
 * 20 is hkpRagdollLimitsData's (0x7c8b0). */
class hkpHingeLimitsData : public hkpConstraintData
{
  public:
    struct Atoms {
        hkpSetLocalRotationsConstraintAtom rotations;
        u8 angLimit[0x20];
        u8 unknown90[0x10]; /* 2dAng */
    };

    /* The finish constructor (0x82250): the atoms are left as loaded. */
    hkpHingeLimitsData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpHingeLimitsData();

    /* Slot 7 (0x83150): both rotations orthonormal. */
    hkBool unknownVirtual7() const;

    Atoms atoms;
};

/* hkpWheelConstraintData (hkClass 0x57c43d8, built at 0x7ec1e, 0x190 bytes,
 * parent hkpConstraintData; vtable 0x16a5e10, address point 0x16a5e20;
 * member records 0x169d400): atoms at +0x20, an
 * hkpWheelConstraintData::Atoms of 0x150 bytes (record table 0x169d2e0:
 * suspensionBase at +0, lin0Limit at +0x90, lin0Soft at +0xa0, lin1 at
 * +0xb0, lin2 at +0xc0, steeringBase at +0xd0, 2dAng at +0x140), then
 * initialAxleInB and initialSteeringAxisInB (hkVector4) at +0x170 and
 * +0x180. Its slots 6 and 20 are hkpDeformableFixedConstraintData's code
 * (0x83000, 0x83020), whose atoms have the same size. */
class hkpWheelConstraintData : public hkpConstraintData
{
  public:
    struct Atoms {
        hkpSetLocalTransformsConstraintAtom suspensionBase;
        u8 lin0Limit[0x10];
        u8 lin0Soft[0x10];
        u8 lin1[0x10];
        u8 lin2[0x10];
        hkpSetLocalRotationsConstraintAtom steeringBase;
        u8 unknown140[0x10]; /* 2dAng */
    };

    /* The finish constructor (0x7eab0): the atoms are left as loaded. */
    hkpWheelConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpWheelConstraintData();

    Atoms atoms;
    Vec4 initialAxleInB;
    Vec4 initialSteeringAxisInB;
};

/* hkpRotationalConstraintData (hkClass 0x57c3a68, built at 0x7b75b, 0xa0 bytes, parent hkpConstraintData; vtable 0x16a0110): atoms at +0x20 (record table 0x169c3a0: rotations at +0, ang at +0x70). */
class hkpRotationalConstraintData : public hkpConstraintData /* vtable address point 0x16a0120 */
{
  public:
    struct Atoms {
        hkpSetLocalRotationsConstraintAtom rotations;
        u8 ang[0x10];
    };

    /* The finish constructor (0x7b5f0): the atoms are left as loaded. */
    hkpRotationalConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpRotationalConstraintData();

    /* Slot 7 (0x83520): both rotations orthonormal. */
    hkBool unknownVirtual7() const;

    void FUN_000834e0(
        hkpConstraintData::ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    void FUN_00083500(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

    Atoms atoms;
};

/* hkpConeLimitConstraintAtom (records built by the initializer at 0x80da0:
 * isEnabled, twistAxisInA, refAxisInB, angleMeasurementMode and
 * memOffsetToAngleOffset, bytes from +2; then minAngle, maxAngle and
 * angularLimitsTauFactor), 0x20 bytes in the atoms that hold it. A nonzero
 * memOffsetToAngleOffset is where the constraint's runtime keeps the cone's
 * angle offset (its stabilization). */
struct hkpConeLimitConstraintAtom {
    u16 type; /* derived name */
    u8 isEnabled;
    u8 twistAxisInA;
    u8 refAxisInB;
    u8 angleMeasurementMode; /* hkEnum of hkUint8 */
    u8 memOffsetToAngleOffset;
    u8 unknown7[0x19];
};

/* hkpRagdollLimitsData: atoms at +0x20 (records 0x169b8f8, 0x169b920 and
 * 0x169b948: twistLimit at +0x70, coneLimit at +0x90, planesLimit at +0xb0). Its finish constructor
 * (0x788d0) re-enables the cone's stabilization through FUN_0007c860 when the
 * loaded offset is nonzero. */
class hkpRagdollLimitsData
{
  public:
    struct Atoms {
        u8 unknown0[0x90]; /* up to and with twistLimit (+0x70) */
        hkpConeLimitConstraintAtom coneLimit;
        u8 unknownB0[0x20]; /* planesLimit */
    };

    virtual ~hkpRagdollLimitsData();

    void FUN_0007c890(
        hkpConstraintData::ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    void FUN_0007c860(hkBool enable);                      /* derived name */

    void FUN_0007c8b0(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

    u8 unknown8[0x18];
    Atoms atoms;
};

/* hkpPointToPlaneConstraintData (type info registered at 0x7bab4; hkClass
 * 0x57c3be8, built at 0x7ba6b: size 0xc0, parent hkpConstraintData; vtable
 * 0x169c530, address point 0x169c540): atoms at +0x20 (transforms at +0,
 * lin at +0x90, record table 0x169c4b0). Its slot 20 (0x7bb90), kept by
 * hkpStiffSpringConstraintData and hkpPulleyConstraintData, wants 8 bytes
 * of runtime and one solver result, or none. */
class hkpPointToPlaneConstraintData : public hkpConstraintData
{
  public:
    struct Atoms {
        hkpSetLocalTransformsConstraintAtom transforms;
        u8 lin[0x10];
    };

    /* The finish constructor (0x7b900): the atoms are left as loaded. */
    hkpPointToPlaneConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpPointToPlaneConstraintData();

    /* Slot 7 (0x7bbb0): both frames' rotations orthonormal. */
    hkBool unknownVirtual7() const;

    void FUN_0007bb90(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

    Atoms atoms;
};

/* hkpLinearClearanceConstraintData: address point 0x16a0300 (finish
 * constructor FUN_0007ac70). hkpRackAndPinionConstraintData: 0x16a0210
 * (FUN_0007d080). */
class hkpLinearClearanceConstraintData : public hkpConstraintData
{
  public:
    /* Members from the record table 0x169bf60: transforms at +0, motor
     * (hkpLinMotorConstraintAtom) at +0x90, three frictions, ang and three
     * linear limits from +0xb0. Its finish constructor (0x83880) is out of
     * line: when finishing, the motor's offsets into the runtime are set. */
    struct Atoms {
        Atoms(hkFinishLoadedObjectFlag flag);

        hkpSetLocalTransformsConstraintAtom transforms;
        hkpLinMotorConstraintAtom motor;
        u8 unknownB0[0x70]; /* three frictions, ang and three linear limits */
    };

    /* The finish constructor (0x7ac70; hkClass built at 0x7ad45, parent
     * hkpConstraintData's 0x57c45a8): the atoms finish themselves. */
    hkpLinearClearanceConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpLinearClearanceConstraintData();

    void FUN_000839f0(
        hkpConstraintData::ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    void FUN_00083a10(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

    Atoms atoms;
};

/* hkpRackAndPinionConstraintData (hkClass 0x57c4188, built at 0x7d1ee, 0xc0
 * bytes, parent hkpConstraintData; vtable 0x16a0200): atoms at +0x20 (record
 * table 0x169cd00: transforms at +0, rackAndPinion at +0x90). */
class hkpRackAndPinionConstraintData : public hkpConstraintData
{
  public:
    struct Atoms {
        hkpSetLocalTransformsConstraintAtom transforms;
        u8 rackAndPinion[0x10];
    };

    /* The finish constructor (0x7d080): the atoms are left as loaded. */
    hkpRackAndPinionConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpRackAndPinionConstraintData();

    void FUN_000836c0(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

    Atoms atoms;
};

/* A constraint data class with no name found (no type-info registration
 * holds its vtable; slot 3 is the shared 0x42d0). ConstraintData169ffe0:
 * address point 0x169ffe0, slot 5 returns 26, 0xc0 bytes, built by the
 * constructor 0x831a0 when 0x79b63 copies 0xa0 bytes of atoms into one.
 * (The class of address point 0x16a5d30, constructor 0x17b170, is
 * hkp6DofConstraintData, its type info's vtable.) */
class ConstraintData169ffe0 : public hkpConstraintData /* derived name */
{
  public:
    /* The constructor's stores: local transforms (type 2) at +0, both
     * identity, and an atom of type 0x11 at +0x90. */
    struct Atoms {
        hkpSetLocalTransformsConstraintAtom transforms;
        u8 unknown90[0x10];
    };

    virtual ~ConstraintData169ffe0();

    /* Slot 7 (0x832d0): both frames' rotations orthonormal. */
    hkBool unknownVirtual7() const;

    void FUN_000832b0(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

    Atoms atoms;
};

/* hkpLimitedHingeConstraintData::Atoms: type info 0x57c57f8, size 0x110,
 * FUN_00078df0 (also the u16 at +0xb4). hkpRagdollConstraintData::Atoms:
 * type info 0x57c5b48, size 0x180, 0x7dae0 (the int at +0xa4). */
class hkpLimitedHingeConstraintData;

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

/* hkpConstraintMotor (hkClass 0x57c3af0, parent hkReferencedObject) and
 * hkpLimitedForceConstraintMotor (hkClass 0x57c59a8, parent
 * hkpConstraintMotor): the abstract bases of the constraint motors. */
class hkpConstraintMotor : public hkReferencedObject
{
  public:
    /* The motor types (item names from the executable's strings at
     * 0x14c40cb to 0x14c4107; values derived from their order). */
    enum MotorType {
        TYPE_INVALID,
        TYPE_POSITION,
        TYPE_VELOCITY,
        TYPE_SPRING_DAMPER,
        TYPE_CALLBACK
    };

    hkpConstraintMotor() {}

    hkpConstraintMotor(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    hkEnum<MotorType, s8> type; /* derived name */
};

class hkpLimitedForceConstraintMotor : public hkpConstraintMotor
{
  public:
    hkpLimitedForceConstraintMotor() {}

    hkpLimitedForceConstraintMotor(hkFinishLoadedObjectFlag flag) : hkpConstraintMotor(flag) {}

    float minForce; /* name from the executable's strings; offset derived */
    float maxForce; /* name from the executable's strings; offset derived */
};

/* hkpPositionConstraintMotor (hkClass 0x57c30e8), hkpVelocityConstraintMotor
 * (hkClass 0x57c32e8) and hkpCallbackConstraintMotor (hkClass 0x57c3cc0),
 * each with hkpLimitedForceConstraintMotor as its parent: vtables 0x169f5b0,
 * 0x169c790 and 0x16a5ff0, finish callbacks FUN_000787d0, FUN_00079330 and
 * FUN_0007c410. */
class hkpPositionConstraintMotor : public hkpLimitedForceConstraintMotor
{
  public:
    hkpPositionConstraintMotor(hkFinishLoadedObjectFlag flag) : hkpLimitedForceConstraintMotor(flag)
    {
    }
};

class hkpVelocityConstraintMotor : public hkpLimitedForceConstraintMotor
{
  public:
    hkpVelocityConstraintMotor(hkFinishLoadedObjectFlag flag) : hkpLimitedForceConstraintMotor(flag)
    {
    }
};

class hkpCallbackConstraintMotor : public hkpLimitedForceConstraintMotor
{
  public:
    /* The callback's kind (the enum CallbackType, items
     * CALLBACK_MOTOR_TYPE_HAVOK_DEMO_SPRING_DAMPER and
     * CALLBACK_MOTOR_TYPE_USER_0 to 3 from the strings at 0x14c423b on). */
    enum CallbackType {
        CALLBACK_MOTOR_TYPE_HAVOK_DEMO_SPRING_DAMPER,
        CALLBACK_MOTOR_TYPE_USER_0,
        CALLBACK_MOTOR_TYPE_USER_1,
        CALLBACK_MOTOR_TYPE_USER_2,
        CALLBACK_MOTOR_TYPE_USER_3
    };

    /* The function that fills the motor's solver data (signature not
     * recovered). derived name. */
    typedef void (*CalcMotorDataCallbackFunc)();

    /* 0x17d0c0 (the game builds one at 0xeb1204): a limited-force motor of
     * the callback type with a force range of a million each way. */
    hkpCallbackConstraintMotor(CallbackType callbackType, CalcMotorDataCallbackFunc callbackFunc);

    hkpCallbackConstraintMotor(hkFinishLoadedObjectFlag flag) : hkpLimitedForceConstraintMotor(flag)
    {
    }

    CalcMotorDataCallbackFunc callbackFunc; /* name from the strings; offset derived */
    hkEnum<CallbackType, u32> callbackType; /* name from the strings; offset derived */
};

/* hkpSpringDamperConstraintMotor (hkClass 0x57c5bf8, parent
 * hkpLimitedForceConstraintMotor): vtable 0x16a5ce0, finish callback
 * FUN_00083360. */
class hkpSpringDamperConstraintMotor : public hkpLimitedForceConstraintMotor
{
  public:
    /* 0x17afe0 (the game builds one at 0xeb1270): a limited-force motor of
     * the spring-damper type with a force range of a million each way and
     * no spring. */
    hkpSpringDamperConstraintMotor();

    hkpSpringDamperConstraintMotor(hkFinishLoadedObjectFlag flag)
        : hkpLimitedForceConstraintMotor(flag)
    {
    }

    float springConstant; /* name from the strings; offset derived */
    float springDamping;  /* name from the strings; offset derived */
};

/* hkpAngFrictionConstraintAtom (0x10 bytes, record table 0x169da20):
 * isEnabled, firstFrictionAxis and numFrictionAxes (hkUint8) at +2 to +4,
 * maxFrictionTorque at +8, padding (4 bytes, not serialized) at +0xc. */
struct hkpAngFrictionConstraintAtom {
    u16 type; /* derived name */
    u8 isEnabled;
    u8 firstFrictionAxis;
    u8 numFrictionAxes;
    float maxFrictionTorque;
    u8 padding[4];
};

/* hkpAngMotorConstraintAtom (type info 0x57c4920, size 0x20, record table
 * 0x169ee30): isEnabled at +2, motorAxis at +3, initializedOffset and
 * previousTargetAngleOffset (hkInt16) at +4 and +6, motor at +8,
 * targetAngle at +0x10, correspondingAngLimitSolverResultOffset (hkInt16)
 * at +0x14, padding at +0x16. Its finish constructor resets the three
 * offsets. */
struct hkpAngMotorConstraintAtom {
    hkpAngMotorConstraintAtom(hkFinishLoadedObjectFlag)
    {
        initializedOffset = -1;
        previousTargetAngleOffset = -1;
        correspondingAngLimitSolverResultOffset = -1;
    }

    u16 type;         /* derived name */
    hkBool isEnabled; /* TYPE_BOOL in the record */
    u8 motorAxis;
    s16 initializedOffset;
    s16 previousTargetAngleOffset;
    hkpConstraintMotor *motor;
    float targetAngle;
    s16 correspondingAngLimitSolverResultOffset;
    u8 padding[10];
};

/* hkpRagdollMotorConstraintAtom (record table 0x169f090): isEnabled at +2,
 * initializedOffset at +4, previousTargetAnglesOffset at +6, target_bRca at
 * +0x10, motors (three pointers to hkpConstraintMotor, hkClass 0x57c3af0)
 * at +0x40. */
struct hkpRagdollMotorConstraintAtom {
    /* The finish callback's body is hkpLinMotorConstraintAtom's (0x803f0):
     * the two runtime offsets reset. */
    hkpRagdollMotorConstraintAtom(hkFinishLoadedObjectFlag)
    {
        initializedOffset = -1;
        previousTargetAnglesOffset = -1;
    }

    u16 type; /* derived name */
    bool isEnabled;
    u8 unknown3;
    s16 initializedOffset;
    s16 previousTargetAnglesOffset;
    u8 unknown8[8];
    hkMatrix3 target_bRca;
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
        /* Out of line (0x7dae0): when finishing, the motors' offsets into
         * the runtime are set. */
        Atoms(hkFinishLoadedObjectFlag flag);

        hkpSetLocalTransformsConstraintAtom transforms;
        hkpSetupStabilizationAtom setupStabilization;
        hkpRagdollMotorConstraintAtom ragdollMotors;
        u8 unknown100[0x30]; /* angFriction, twistLimit */
        hkpConeLimitConstraintAtom coneLimit;
        u8 unknown150[0x20]; /* planesLimit */
        hkpBallSocketConstraintAtom ballSocket;
    };

    virtual ~hkpRagdollConstraintData();

    void FUN_0007dce0(
        hkpConstraintData::ConstraintInfo &infoOut) const;      /* vtable slot 6; derived name */
    void FUN_0007dc90(float newBreachImpulse);                  /* vtable slot 10; derived name */
    float FUN_0007dca0() const;                                 /* vtable slot 13; derived name */
    void FUN_0007dcb0(int bodyIndex);                           /* vtable slot 14; derived name */
    u8 FUN_0007dcd0() const;                                    /* vtable slot 15; derived name */
    void FUN_0007e2b0(hkpConstraintAtom::SolvingMethod method); /* vtable slot 16; derived name */
    hkResult FUN_0007e2f0(float factor);                        /* vtable slot 17; derived name */
    hkResult FUN_0007e2e0(float &factorOut) const;              /* vtable slot 18; derived name */
    void FUN_0007e310(const void *argument1, const void *argument2, const hkpSolverResults *results,
                      Vec4 &out) const; /* vtable slot 19; derived name */
    void FUN_0007dd00(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

    void FUN_0007dad0(hkBool enable); /* derived name */

    hkpConstraintMotor *FUN_0007dfc0() const; /* derived name */
    hkpConstraintMotor *FUN_0007e0a0() const; /* derived name */
    hkpConstraintMotor *FUN_0007e160() const; /* derived name */

    /* derived name: target_bRca = target * transformA's rotation. */
    void FUN_0007df80(const hkMatrix3 &target);

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
/* hkClass 0x57c3f88 (built at 0x7cd5b), parent hkpConstraintData. */
class hkpBallAndSocketConstraintData : public hkpConstraintData
{
  public:
    struct Atoms {
        hkpSetLocalTranslationsConstraintAtom pivots;
        hkpSetupStabilizationAtom setupStabilization;
        hkpBallSocketConstraintAtom ballSocket;
    };

    /* The finish constructor (0x7cbf0): the atoms are left as loaded. */
    hkpBallAndSocketConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpBallAndSocketConstraintData();

    /* derived name: sets the pivots in each body's space (called by the game
     * after the constructor FUN_0007c1d0, 0xea746a). */
    void FUN_0007c2a0(const Vec4 &pivotA, const Vec4 &pivotB);

    void FUN_0007c330(
        hkpConstraintData::ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    hkBool FUN_0007c380() const;                           /* vtable slot 7; derived name */

    void FUN_0007c2e0(float newMaxImpulse);                     /* vtable slot 8; derived name */
    void FUN_0007c2c0(float newBreachImpulse);                  /* vtable slot 10; derived name */
    float FUN_0007c300() const;                                 /* vtable slot 11; derived name */
    float FUN_0007c2d0() const;                                 /* vtable slot 13; derived name */
    void FUN_0007c310(int bodyIndex);                           /* vtable slot 14; derived name */
    u8 FUN_0007c320() const;                                    /* vtable slot 15; derived name */
    void FUN_0007c3b0(hkpConstraintAtom::SolvingMethod method); /* vtable slot 16; derived name */
    hkResult FUN_0007c3e0(float factor);                        /* vtable slot 17; derived name */
    hkResult FUN_0007c3d0(float &factorOut) const;              /* vtable slot 18; derived name */
    void FUN_0007c350(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

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
class hkpLimitedHingeConstraintData : public hkpConstraintData
{
  public:
    struct Atoms {
        /* Out of line (0x78df0): when finishing, the motor's offsets into
         * the runtime are set. */
        Atoms(hkFinishLoadedObjectFlag flag);

        hkpSetLocalTransformsConstraintAtom transforms;
        hkpSetupStabilizationAtom setupStabilization;
        hkpAngMotorConstraintAtom angMotor;
        hkpAngFrictionConstraintAtom angFriction;
        u8 unknownD0[0x30]; /* angLimit, 2dAng */
        hkpBallSocketConstraintAtom ballSocket;
    };

    /* What the solver keeps for the constraint (derived names): its first
     * four solver results are the motor's and the friction's. */
    struct Runtime {
        hkpSolverResults solverResults[4];
    };

    /* The finish constructor (0x82000): the atoms finish themselves. */
    hkpLimitedHingeConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpLimitedHingeConstraintData();

    void FUN_000791f0(
        hkpConstraintData::ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    /* The motor on or off, the friction the other way, and the runtime's
     * motor and friction results cleared when there is one (0x79100,
     * called by the game at 0xeb19d9). derived name. */
    void FUN_00079100(void *runtime, hkBool isEnabled);
    void FUN_000790b0(float newBreachImpulse);                  /* vtable slot 10; derived name */
    float FUN_000790c0() const;                                 /* vtable slot 13; derived name */
    void FUN_000790d0(int bodyIndex);                           /* vtable slot 14; derived name */
    u8 FUN_000790f0() const;                                    /* vtable slot 15; derived name */
    void FUN_000792a0(hkpConstraintAtom::SolvingMethod method); /* vtable slot 16; derived name */
    hkResult FUN_000792e0(float factor);                        /* vtable slot 17; derived name */
    hkResult FUN_000792d0(float &factorOut) const;              /* vtable slot 18; derived name */
    void FUN_00079300(const void *argument1, const void *argument2, const hkpSolverResults *results,
                      Vec4 &out) const; /* vtable slot 19; derived name */
    void FUN_00079210(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

    Atoms atoms;
};

/* hkpBridgeConstraintAtom (records 0x169b7b0, 0x169b7d8): buildJacobianFunc at +8,
 * the function the solver calls with constraintData at +0x10. Its
 * initializer FUN_0007d030 stores the data and FUN_0007d020, which hands the
 * call on to the data's slot 24; the finish constructor runs it when the
 * object is being finished (hkpBridgeAtoms' callback FUN_00078610, the
 * finish constructor at 0x7f140 with the atoms at +0x20), and so does the
 * code at 0x79e62. */
void FUN_0007d020(hkpConstraintData *data, const void *input, void *output); /* derived name */

struct hkpBridgeConstraintAtom;
void FUN_0007d030(hkpBridgeConstraintAtom *self, hkpConstraintData *data); /* derived name */

struct hkpBridgeConstraintAtom {
    hkpBridgeConstraintAtom(hkFinishLoadedObjectFlag flag)
    {
        if (flag.finishing) {
            FUN_0007d030(this, constraintData);
        }
    }

    u16 type; /* derived name */
    u8 unknown2[6];
    void (*buildJacobianFunc)(hkpConstraintData *data, const void *input, void *output);
    hkpConstraintData *constraintData;
};

/* hkpBridgeAtoms (type info 0x57c3038, 0x20 bytes, record 0x169b780): its
 * bridgeAtom at +0, 0x18 bytes; the 0x20 is the 16-byte alignment of the
 * constraint atoms (hkpPointToPathConstraintData's path follows them at
 * +0x40). */
struct alignas(16) hkpBridgeAtoms {
    hkpBridgeAtoms(hkFinishLoadedObjectFlag flag) : bridgeAtom(flag) {}

    hkpBridgeConstraintAtom bridgeAtom;
};

/* hkpWrappedConstraintData (hkClass 0x57c4308, built at 0x7e39e, 0x20 bytes,
 * parent hkpConstraintData; finish constructor 0x7d520 stores its
 * vtable 0x169cee0, address point 0x169cef0, slot 5 pure): one reflected
 * member, constraintData (a pointer to hkpConstraintData) at +0x18 (record
 * 0x169d1c0). Slot 7 (FUN_00067c60, emitted in hknpMalleableConstraintData's
 * file and kept by it and hknpBreakableConstraintData) forwards to the
 * wrapped data's slot 7; slot 6 (FUN_0007d5b0, kept by
 * hknpBreakableConstraintData, address point 0x1695b20) forwards to its
 * slot 6. */
class hkpWrappedConstraintData : public hkpConstraintData
{
  public:
    /* The finish constructor, out of line (0x7d520): hkpConstraintData's,
     * then the vtable; the wrapped pointer is left as loaded. */
    hkpWrappedConstraintData(hkFinishLoadedObjectFlag flag);

    /* The constructor, out of line (0x7d550): a new object over the data it
     * wraps, whose reference it takes. */
    hkpWrappedConstraintData(hkpConstraintData *constraintData);

    void FUN_0007d5b0(ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    hkBool FUN_00067c60() const;                      /* vtable slot 7; derived name */
    void FUN_0007d600(const void *argument1, const void *argument2, const void *argument3,
                      Vec4 &out) const; /* vtable slot 19; derived name */
    void FUN_00067b30(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */
    void *FUN_0007d5d0(void *runtime) const;                 /* vtable slot 21; derived name */

    hkpConstraintData *constraintData;
};

/* hknpBridgeConstraintAtom (hkClass 0x57c1808, built at 0x61667, 0x18
 * bytes, parent hkpConstraintAtom's 0x57c4650). */
struct hknpBridgeConstraintAtom {
    u16 type; /* derived name */
    u8 unknown2[0x16];
};

/* hknpMalleableConstraintData, polymorphic, 0x40 bytes (type info 0x57c18d8,
 * vtable 0x1699a90; its finish constructor FUN_00067960 runs
 * hkpWrappedConstraintData's 0x7d520): members atom (an
 * hknpBridgeConstraintAtom) at +0x20, wantsRuntime at +0x38 and strength
 * (float) at +0x3c (record table 0x16996a0); FUN_00067c40 writes the
 * strength. Slot 6 (FUN_00067b00) takes the wrapped data's info and puts its
 * own atom in place of the atoms. */
class hknpMalleableConstraintData : public hkpWrappedConstraintData
{
  public:
    virtual ~hknpMalleableConstraintData();

    void FUN_00067b00(ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    void FUN_00067c40(float newStrength);             /* derived name */

    hknpBridgeConstraintAtom atom;
    hkBool wantsRuntime;
    u8 unknown39[3];
    float strength;
};

/* hknpBreakableConstraintData (type info 0x57c23f8, vtable 0x1695b10,
 * address point 0x1695b20): a wrapped constraint data with a threshold;
 * its slot 5 is 0x37b70, slots 6, 7 and 19 to 21 the wrapped data's. */
class hknpBreakableConstraintData : public hkpWrappedConstraintData
{
  public:
    hknpBreakableConstraintData(hkFinishLoadedObjectFlag flag); /* 0x3c240 */
    /* 0x3c210: over the wrapped data, the threshold 10 to start. */
    hknpBreakableConstraintData(hkpConstraintData *constraintData);

    virtual ~hknpBreakableConstraintData();

    float FUN_0003c270() const;            /* derived name */
    void FUN_0003c280(float newThreshold); /* derived name */

    float threshold;
};

/* hkpFixedConstraintData, polymorphic, 0xe0 bytes (type info 0x57c3438,
 * hkClass 0x57c33e8, parent hkpConstraintData; vtable 0x169c620, address
 * point 0x169c630): its member atoms at
 * +0x20 is an hkpFixedConstraintData::Atoms, 0xc0 bytes (record table
 * 0x169bd30: transforms at +0, setupStabilization at +0x90, ballSocket at
 * +0xa0, ang at +0xb0). Slot 8 (0x7bea0) sets the stabilization's linear
 * impulse limit and the ball socket's enableLinearImpulseLimit, slot 9 its
 * angular limit; slots 11 and 12 read the two limits back. */
class hkpFixedConstraintData : public hkpConstraintData
{
  public:
    struct Atoms {
        hkpSetLocalTransformsConstraintAtom transforms;
        hkpSetupStabilizationAtom setupStabilization;
        hkpBallSocketConstraintAtom ballSocket;
        u8 ang[0x10];
    };

    /* The finish constructor (0x7a610): the atoms are left as loaded. */
    hkpFixedConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpFixedConstraintData();

    void FUN_0007bf20(
        hkpConstraintData::ConstraintInfo &infoOut) const;      /* vtable slot 6; derived name */
    hkBool FUN_0007bf70() const;                                /* vtable slot 7; derived name */
    void FUN_0007bea0(float newMaxImpulse);                     /* vtable slot 8; derived name */
    void FUN_0007bec0(float newMaxAngImpulse);                  /* vtable slot 9; derived name */
    float FUN_0007bed0() const;                                 /* vtable slot 11; derived name */
    float FUN_0007bee0() const;                                 /* vtable slot 12; derived name */
    void FUN_0007bef0(int bodyIndex);                           /* vtable slot 14; derived name */
    u8 FUN_0007bf10() const;                                    /* vtable slot 15; derived name */
    void FUN_0007bfa0(hkpConstraintAtom::SolvingMethod method); /* vtable slot 16; derived name */
    hkResult FUN_0007bfe0(float factor);                        /* vtable slot 17; derived name */
    hkResult FUN_0007bfd0(float &factorOut) const;              /* vtable slot 18; derived name */
    void FUN_0007c000(const void *argument1, const void *argument2, const hkpSolverResults *results,
                      Vec4 &out) const; /* vtable slot 19; derived name */
    void FUN_0007bf40(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

    Atoms atoms;
};

/* hkpHingeConstraintData, polymorphic, 0xe0 bytes (type info 0x57c42d8,
 * vtable 0x169d4f0, address point 0x169d500): its member atoms at +0x20 is an
 * hkpHingeConstraintData::Atoms, 0xc0 bytes (record table 0x169cdd0:
 * transforms at +0, setupStabilization at +0x90, 2dAng at +0xa0, ballSocket
 * at +0xb0). Slots 10 and 13 of its vtable write and read the ball-socket
 * atom's breach impulse. */
/* hkClass 0x57c4288 (built at 0x7d40e), parent hkpConstraintData. */
class hkpHingeConstraintData : public hkpConstraintData
{
  public:
    struct Atoms {
        hkpSetLocalTransformsConstraintAtom transforms;
        hkpSetupStabilizationAtom setupStabilization;
        u8 unknownA0[0x10]; /* 2dAng */
        hkpBallSocketConstraintAtom ballSocket;
    };

    /* The finish constructor (0x7d2a0): the atoms are left as loaded. */
    hkpHingeConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpHingeConstraintData();

    void FUN_0007efa0(float newBreachImpulse);                  /* vtable slot 10; derived name */
    float FUN_0007efb0() const;                                 /* vtable slot 13; derived name */
    void FUN_0007efc0(int bodyIndex);                           /* vtable slot 14; derived name */
    u8 FUN_0007efe0() const;                                    /* vtable slot 15; derived name */
    void FUN_0007f090(hkpConstraintAtom::SolvingMethod method); /* vtable slot 16; derived name */
    hkResult FUN_0007f0d0(float factor);                        /* vtable slot 17; derived name */
    hkResult FUN_0007f0c0(float &factorOut) const;              /* vtable slot 18; derived name */
    void FUN_0007f0f0(const void *argument1, const void *argument2, const hkpSolverResults *results,
                      Vec4 &out) const; /* vtable slot 19; derived name */
    void FUN_0007eff0(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

    Atoms atoms;
};

/* hkpWheelFrictionConstraintAtom (hkClass 0x57c5570, records from
 * 0x169f160): isEnabled, forwardAxis and sideAxis (bytes) at +2 to +4,
 * radius at +8, axle (a pointer to hkpWheelFrictionConstraintAtom::Axle,
 * hkClass 0x57c54f0) at +0x10, maxFrictionForce and torque at +0x20 and
 * +0x24, frictionImpulse and slipImpulse (two floats each) at +0x28 and
 * +0x30, padding (8 bytes, not serialized) at +0x38. */
struct hkpWheelFrictionConstraintAtom {
    struct Axle;

    /* The finish constructor, inline in the type info's finish callback
     * FUN_00080660 (size 0x40): a loaded atom starts with no impulses. */
    hkpWheelFrictionConstraintAtom(hkFinishLoadedObjectFlag flag)
    {
        if (flag.finishing) {
            slipImpulse[0] = 0.0f;
            slipImpulse[1] = 0.0f;
            frictionImpulse[0] = 0.0f;
            frictionImpulse[1] = 0.0f;
        }
    }

    u8 unknown0[0x10];
    Axle *axle;
    u8 unknown18[0x10];
    float frictionImpulse[2]; /* record 0x169f278 */
    float slipImpulse[2];     /* record 0x169f2a0 */
    u8 padding[8];
};

/* hkpWheelFrictionConstraintData (vtable address point 0x16a5f10, stored at
 * 0x7b122 and 0x7b33f; slot 5 FUN_0017cf20 returns its type code 20): its
 * atoms at +0x20 are an hkpWheelFrictionConstraintData::Atoms (records
 * 0x169c230: transforms at +0, friction at +0x90). Slot 6 (0x7c890) hands
 * the atoms on with their size, 0xd0; slot 7 (FUN_0017cf10) tells whether
 * the friction atom has an axle. */
class hkpWheelFrictionConstraintData : public hkpConstraintData
{
  public:
    /* Its finish constructor is inline in the type info's finish callback
     * FUN_0007b0d0 (registered at 0x7b2c7, size 0xd0): the friction atom's
     * impulses are reset. */
    struct Atoms {
        Atoms(hkFinishLoadedObjectFlag flag) : friction(flag) {}

        hkpSetLocalTransformsConstraintAtom transforms;
        hkpWheelFrictionConstraintAtom friction;
    };

    /* Inline: the type info's finish callback FUN_0007b110 holds it, as
     * the reflection initializer (0x7b33a) does: hkpConstraintData's, the
     * vtable, then the atoms'. */
    hkpWheelFrictionConstraintData(hkFinishLoadedObjectFlag flag)
        : hkpConstraintData(flag), atoms(flag)
    {
    }

    virtual ~hkpWheelFrictionConstraintData();

    int unknownVirtual5() const; /* slot 5 (FUN_0017cf20) */
    void unknownVirtual6(hkpConstraintData::ConstraintInfo &infoOut) const; /* slot 6 (0x7c890) */
    hkBool unknownVirtual7() const;                                         /* slot 7 (0x17cf10) */
    void unknownVirtual20(hkBool wantRuntime,
                          ConstraintRuntimeInfo &infoOut) const; /* slot 20 (0x17cf30) */

    Atoms atoms;
};

void FUN_0007b110(void *object, int finishing); /* derived name */

/* hkp6DofConstraintData, polymorphic (type info 0x57c5ac8, size 0x2b0): its
 * finish constructor FUN_0017b5f0 runs 0x82850 (the constraint data
 * base's), stores the vtable 0x16a5d20 and resets the packed u16 pairs of
 * its atoms. hkp6DofConstraintData::Blueprints (type info 0x57c5a48, size
 * 0x200): its finish constructor FUN_0017b0d0 resets the same pairs from
 * +0xb4. Members from the record tables 0x169f910 and 0x169f730: blueprints
 * at +0x20 (ballSocket at +0x1f0 of it), isDirty (hkBool) at +0x220. Slots
 * 10 and 13 of its vtable (address point 0x16a5d30) write and read the
 * ball-socket atom's breach impulse. */
class hkp6DofConstraintData
{
  public:
    /* MotorIndex, the class's first enum (records from 0x169fa70): its
     * items MOTOR_TWIST, MOTOR_SWING0, MOTOR_SWING1 and MOTOR_ALL. */
    enum MotorIndex { MOTOR_TWIST = 0, MOTOR_SWING0 = 1, MOTOR_SWING1 = 2, MOTOR_ALL = 3 };

    struct Blueprints {
        u8 unknown0[0xb0]; /* linearIsFixed to setupStabilization */
        hkpRagdollMotorConstraintAtom ragdollMotors;
        u8 unknown110[0xe0]; /* angFriction to linearMotor2 */
        hkpBallSocketConstraintAtom ballSocket;
    };

    virtual ~hkp6DofConstraintData();

    /* An angular motor by index; MOTOR_ALL gives the twist motor (0x17bb20;
     * the constraint's builder at 0x79bd5 asks for each). derived name. */
    hkpConstraintMotor *FUN_0017bb20(MotorIndex index) const;

    void FUN_0017b910(float newBreachImpulse);     /* vtable slot 10; derived name */
    float FUN_0017b920() const;                    /* vtable slot 13; derived name */
    void FUN_0017b930(int bodyIndex);              /* vtable slot 14; derived name */
    u8 FUN_0017b950() const;                       /* vtable slot 15; derived name */
    hkResult FUN_0017bb70(float &factorOut) const; /* vtable slot 18; derived name */
    void FUN_0017b990(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */
    /* Slot 6 (0x17b960): the compiled atoms' schemas and solver data, then
     * 256 bytes of schemas and four temporaries more. derived name. */
    void FUN_0017b960(hkpConstraintData::ConstraintInfo &infoOut) const;

    u8 unknown8[0x18];
    Blueprints blueprints;
    hkBool isDirty;
    int numRuntimeElements;
    int atomToCompiledAtomOffset[11];
    int resultToRuntime[19];
    /* Not serialized (record flags 0x400); the element type is not in the
     * record. */
    hkArray<u8> compiledAtoms;
};

void FUN_0017b5f0(hkp6DofConstraintData *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0017b0d0(hkp6DofConstraintData::Blueprints *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */

/* hkx scene classes (the reflection TUs from 0x87e20), each with an
 * out-of-line finish constructor or destructor:
 * hkxVertexBuffer::VertexData (type info 0x57c6970, size 0x68, no vtable):
 * its destructor FUN_00087cf0 frees its arrays from +0x40 down.
 * hkxVertexBuffer, polymorphic (type info 0x57c69f0, size 0x88): its finish
 * constructor 0x8a1a0 stores the vtable 0x16a1a30 and runs
 * hkxVertexDescription's (0x8c0a0, an empty body shared with twelve
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
 * hkMemoryResourceHandle (type info 0x57c86a0, size 0x30): 0x17f110
 * stores the vtable 0x16a6270 and runs hkStringPtr's on +0x18.
 * hkxMesh (type info 0x57c6f90, size 0x30): FUN_0008bea0 stores the vtable
 * 0x16a25a0.
 * hkAlignSceneToNodeOptions (type info 0x57c7288, size 0x20): 0x17d520
 * stores the vtable 0x16a6030 and runs hkStringPtr's on +0x18.
 * hkxMaterialShaderSet (type info 0x57c7680, size 0x20): FUN_0008b370
 * stores the vtable 0x16a1f30.
 * hkxSkinBinding, polymorphic (type info 0x57c7500, size 0x80, vtable
 * 0x16a1cc0 stored by its finish constructor FUN_0008a9b0): slot 0, the
 * complete destructor FUN_0008a830, runs the out-of-line FUN_0008a890,
 * which restores the vtable and frees the arrays from +0x30 down. */
/* hkxVertexDescription (hkClass 0x57c7f40, built at 0x8d20a: size 0x10,
 * one member record at 0x16a27a0): decls (an array of its ElementDecl, class
 * 0x57c7ec0) at +0. Its finish constructor is out of line, the empty body at
 * 0x8c0a0 that twelve vtable slots share. */
struct hkxVertexDescriptionElementDecl;

struct hkxVertexDescription {
    hkxVertexDescription(hkFinishLoadedObjectFlag flag);

    hkArray<hkxVertexDescriptionElementDecl> decls;
};

/* hkxVertexBuffer (hkClass 0x57c69a0, built at 0x87f8b: size 0x88, parent
 * hkReferencedObject's, member records at 0x16a1210): data (its VertexData,
 * class 0x57c6920) at +0x10, desc (hkxVertexDescription) at +0x78. Its
 * finish constructor 0x8a1a0 is out of line (the finish callback 0x87e40
 * jumps to it; hkxVertexAnimation's runs it on its vertData). */
class hkxVertexBuffer : public hkReferencedObject
{
  public:
    /* hkxVertexBufferVertexData (hkClass 0x57c6920, built at 0x87ee2, size
     * 0x68, member records at 0x16a1050). */
    struct VertexData {
        VertexData(hkFinishLoadedObjectFlag flag)
            : vectorData(flag), floatData(flag), uint32Data(flag), uint16Data(flag), uint8Data(flag)
        {
        }

        hkArray<u32> vectorData;
        hkArray<u32> floatData;
        hkArray<u32> uint32Data;
        hkArray<u16> uint16Data;
        hkArray<u8> uint8Data;
        u32 numVerts;
        u32 vectorStride;
        u32 floatStride;
        u32 uint32Stride;
        u32 uint16Stride;
        u32 uint8Stride;
    };

    hkxVertexBuffer(hkFinishLoadedObjectFlag flag);

    VertexData data;
    hkxVertexDescription desc;
};

/* hkxVertexAnimation (hkClass 0x57c7dc0, built at 0x8cd70: size 0xb8,
 * parent hkReferencedObject's, member records at 0x16a2700): time (float)
 * at +0xc, vertData (hkxVertexBuffer) at +0x10, vertexIndexMap (an array of
 * hkInt32) at +0x98, componentMap (an array of class 0x57c7d40) at +0xa8.
 * The finish callback 0x8cb10 constructs it in place. */
struct hkxVertexAnimationUsageMap;

class hkxVertexAnimation : public hkReferencedObject
{
  public:
    hkxVertexAnimation(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), vertData(flag), vertexIndexMap(flag), componentMap(flag)
    {
    }

    float time;
    hkxVertexBuffer vertData;
    hkArray<s32> vertexIndexMap;
    hkArray<hkxVertexAnimationUsageMap> componentMap;
};

/* hkxMesh (hkClass parent hkReferencedObject, built at 0x8924a): its
 * finish constructor 0x8bea0 is out of line, jumped to by the finish
 * callback FUN_00089140 and called by the reflection initializer at
 * 0x892bd. */
class hkxMesh : public hkReferencedObject
{
  public:
    class UserChannelInfo;

    hkxMesh(hkFinishLoadedObjectFlag flag);
};

/* hkxMesh::UserChannelInfo (hkClass 0x57c6ec0, "hkxMeshUserChannelInfo",
 * built at 0x891e4: size 0x30, parent hkxAttributeHolder's; vtable
 * 0x16a1590, member records at 0x16a15d0): name and className
 * (hkStringPtr) at +0x20 and +0x28. Its destructor (0x89020) destroys both
 * and runs hkxAttributeHolder's. */
class hkxMesh::UserChannelInfo : public hkxAttributeHolder
{
  public:
    /* Inline where its type info's finish callback (0x890e0) runs it. */
    UserChannelInfo(hkFinishLoadedObjectFlag flag) : hkxAttributeHolder(flag)
    {
        FUN_0000e5c0(&name, flag);
        FUN_0000e5c0(&className, flag);
    }

    virtual ~UserChannelInfo();

    hkStringPtr name;
    hkStringPtr className;
};

/* hkxTextureInplace (hkClass 0x57c7530, built at 0x8ac85: size 0x30, parent
 * hkReferencedObject's; vtable 0x16a1d90, member records at 0x16a1dd0):
 * fileType (four chars) at +0xc, data (an array of bytes) at +0x10, name
 * and originalFilename (hkStringPtr) at +0x20 and +0x28. Its finish
 * constructor is inline where the type info's finish callback (0x8abb0)
 * runs it. */
class hkxTextureInplace : public hkReferencedObject
{
  public:
    hkxTextureInplace(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag), data(flag)
    {
        FUN_0000e5c0(&name, flag);
        FUN_0000e5c0(&originalFilename, flag);
    }

    char fileType[4];
    hkArray<u8> data;
    hkStringPtr name;
    hkStringPtr originalFilename;
};

/* hkxScene (hkClass 0x57c7830, built at 0x8b7c8: size 0xf0, parent
 * hkReferencedObject's; vtable 0x16a2910, fifteen member records at
 * 0x16a2180): modeller and asset (hkStringPtr) at +0x10 and +0x18, then
 * sceneLength, numFrames, rootNode, the arrays of selection sets, cameras,
 * lights, meshes, materials, textures, skin bindings and splines from
 * +0x30, appliedTransform (hkMatrix3) at +0xc0. Its finish constructor is
 * inline where the type info's finish callback (0x8b6f0) runs it; only the
 * two strings have anything to finish. */
class hkxScene : public hkReferencedObject
{
  public:
    hkxScene(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag)
    {
        FUN_0000e5c0(&modeller, flag);
        FUN_0000e5c0(&asset, flag);
    }

    hkStringPtr modeller;
    hkStringPtr asset;
    u8 unknown20[0xd0];
};

/* hkAlignSceneToNodeOptions: members from its record table at 0x16a18c0:
 * invert and the transform flags (hkBool) from +0xc, keyframe (hkInt32) at
 * +0x14, nodeName (hkStringPtr) at +0x18. FUN_0017d550, beside the finish
 * constructor, sets the node name; hkMemoryResourceHandle's identical name
 * setter (0x17f2f0, slot 7 of its vtable 0x16a6280) was folded onto it. */
class hkAlignSceneToNodeOptions : public hkReferencedObject
{
  public:
    hkAlignSceneToNodeOptions(hkFinishLoadedObjectFlag flag);
    virtual ~hkAlignSceneToNodeOptions();

    void FUN_0017d550(const char *newName); /* derived name */

    hkBool invert;
    hkBool transformPositionX;
    hkBool transformPositionY;
    hkBool transformPositionZ;
    hkBool transformRotation;
    hkBool transformScale;
    hkBool transformSkew;
    int keyframe;
    hkStringPtr nodeName;
};

/* hkxMaterialShaderSet (hkClass parent hkReferencedObject): its finish
 * constructor 0x8b370 is out of line, jumped to by the finish callback
 * FUN_0008b070 and called by the reflection initializer at 0x8b11d. */
class hkxMaterialShaderSet : public hkReferencedObject
{
  public:
    hkxMaterialShaderSet(hkFinishLoadedObjectFlag flag);
};

/* hkxLight (hkClass parent hkReferencedObject, built at 0x8c560): its
 * finish callback FUN_0008c380 runs the inline finish constructor, which
 * has nothing to fix up but the vtable. */
class hkxLight : public hkReferencedObject
{
  public:
    hkxLight(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hkxSkinBinding (hkClass parent hkReferencedObject): its finish
 * constructor, run by the finish callback FUN_0008a9b0, has nothing to fix
 * up but the vtable. */
class hkxSkinBinding : public hkReferencedObject
{
  public:
    hkxSkinBinding(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hkxMeshSection (hkClass parent hkReferencedObject, built at 0x8e07d):
 * its finish callback FUN_0008e000 runs the inline finish constructor,
 * which has nothing to fix up but the vtable. */
class hkxMeshSection : public hkReferencedObject
{
  public:
    hkxMeshSection(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hkxAttribute's members from its record table at 0x16a23e0: name
 * (hkStringPtr) at +0, value at +8. */
struct hkxAttribute {
    hkStringPtr name;
};

/* hkxEnvironment (hkClass 0x57c8130, parent hkReferencedObject, built at
 * 0x8db07): its finish constructor 0x17d6f0 is out of line, jumped to by the
 * finish callback FUN_0008da40 and called by the reflection initializer at
 * 0x8db93. */
class hkxEnvironment : public hkReferencedObject
{
  public:
    hkxEnvironment(hkFinishLoadedObjectFlag flag);
};

class hkRootLevelContainer
{
  public:
    struct NamedVariant;
};

/* hkRootLevelContainer::NamedVariant (hkClass 0x57c83b0, built at 0x8e71d:
 * size 0x18, member records at 0x16a2f60): name and className
 * (hkStringPtr) at +0 and +8, variant (a pointer to hkReferencedObject) at
 * +0x10. Its finish constructor is out of line (0x17dde0, reached from the
 * finish callback 0x8e530): the two strings finish, the variant is left as
 * loaded. */
struct hkRootLevelContainer::NamedVariant {
    NamedVariant(hkFinishLoadedObjectFlag flag);

    hkStringPtr name;
    hkStringPtr className;
    hkReferencedObject *variant;
};
struct hkMemoryResourceContainer;

/* A reference-counted pointer to an hkReferencedObject whose class is looked
 * up from the object's vtable (derived name: the reflection types it as a
 * pointer to hkReferencedObject). FUN_00090250 stores a new object, adding a
 * reference to it and removing one from the old; FUN_000902f0 returns the
 * object's hkClass through the registry singleton at 0x57c8910 (slot 7), or
 * null. */
struct hkRefVariant /* derived name */ {
    hkReferencedObject *object; /* derived name */
};

void FUN_00090250(hkRefVariant *self, hkReferencedObject *object); /* derived name */
const hkClass *FUN_000902f0(const hkRefVariant *self);             /* derived name */

/* hkResourceBase (hkClass 0x57c86d0, built at 0x8eb5c: size 0x10, parent
 * hkReferencedObject's, one enum and no members) and hkResourceHandle
 * (hkClass 0x57c8650, built at 0x8ec1c: size 0x10, parent hkResourceBase,
 * no members): the abstract parents, with nothing of their own to finish. */
class hkResourceBase : public hkReferencedObject
{
  public:
    hkResourceBase(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

class hkResourceHandle : public hkResourceBase
{
  public:
    hkResourceHandle(hkFinishLoadedObjectFlag flag) : hkResourceBase(flag) {}
};

/* hkMemoryResourceHandle::ExternalLink (hkClass 0x57c85d0, built at
 * 0x8e9fc: size 0x10, member records at 0x16a3130): memberName and
 * externalId (hkStringPtr) at +0 and +8. */
struct hkMemoryResourceHandleExternalLink;

/* hkMemoryResourceHandle (vtable address point 0x16a6280; slot 0 the complete
 * destructor 0x17f180): members from its record table at 0x16a30b0: variant
 * (a pointer to hkReferencedObject) at +0x10, name (hkStringPtr) at +0x18,
 * references (array) at +0x20. Slot 6 (0x17f2d0) returns the name or "null",
 * slot 7 sets it (folded onto FUN_0017d550), slot 8 (0x7f80) returns the
 * object, slot 9 its class and slot 10 sets it. */
class hkMemoryResourceHandle : public hkResourceHandle
{
  public:
    hkMemoryResourceHandle(hkFinishLoadedObjectFlag flag);

    const char *FUN_0017f2d0() const;              /* vtable slot 6; derived name */
    const hkClass *FUN_0017f310() const;           /* vtable slot 9; derived name */
    void FUN_0017f320(hkReferencedObject *object); /* vtable slot 10; derived name */

    hkRefVariant variant;
    hkStringPtr name;
    hkArray<hkMemoryResourceHandleExternalLink> references;
};

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

void FUN_0008c990(hkxVertexAnimation *self);                                  /* derived name */
void FUN_0008dc50(hkxMeshSection *self);                                      /* derived name */
void FUN_0017d790(hkxAttribute *self, hkFinishLoadedObjectFlag flag);         /* derived name */
void FUN_0017de10(hkRootLevelContainer *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_0017fb60(hkMemoryResourceContainer *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */

void FUN_00087cf0(hkxVertexBuffer::VertexData *self); /* derived name */
void FUN_0008a890(hkxSkinBinding *self);              /* derived name */
/* hkSkinBinding (vtable 0x16a3860): slot 0, the complete destructor
 * FUN_000aa370, runs the out-of-line FUN_000aa3d0, which restores the
 * vtable. hkStorageSkinnedMeshShape (vtable 0x16a3b00): slot 0, the
 * complete destructor FUN_000ad910, runs the out-of-line FUN_000adba0. */
class hkSkinBinding;
void FUN_000aa3d0(hkSkinBinding *self);             /* derived name */
void FUN_000adba0(hkStorageSkinnedMeshShape *self); /* derived name */

/* hkpPointToPathConstraintData's members, from the records its reflection
 * initializer builds (0x7f1b2 to 0x7f30c, the names in order at 0x14c4707
 * onward): atoms (hkpBridgeAtoms) at +0x20, path (a pointer to
 * hkpParametricCurve) at +0x40, maxFrictionForce (hkReal) at +0x48,
 * angularConstrainedDOF (hkEnum of OrientationConstraintType in hkInt8) at
 * +0x4c, transform_OS_KS (two hkTransform) at +0x50. The enum's item names
 * are the reflection's (0x14c4794 onward). */
class hkpParametricCurve;

class hkpPointToPathConstraintData : public hkpConstraintData
{
  public:
    /* Inline: the type info's finish callback FUN_0007f120 holds it, as
     * the reflection initializer (0x7f377) does: hkpConstraintData's, the
     * vtable, then the bridge atom's finish. */
    hkpPointToPathConstraintData(hkFinishLoadedObjectFlag flag)
        : hkpConstraintData(flag), atoms(flag)
    {
    }

    enum OrientationConstraintType {
        CONSTRAIN_ORIENTATION_INVALID,
        CONSTRAIN_ORIENTATION_NONE,
        CONSTRAIN_ORIENTATION_ALLOW_SPIN,
        CONSTRAIN_ORIENTATION_TO_PATH,
        CONSTRAIN_ORIENTATION_MAX_ID
    };

    virtual ~hkpPointToPathConstraintData();

    int unknownVirtual5() const;                                            /* slot 5 (0x3e420) */
    void unknownVirtual6(hkpConstraintData::ConstraintInfo &infoOut) const; /* slot 6 (0x7a020) */
    hkBool unknownVirtual7() const;                                         /* slot 7 (0x7a590) */
    void unknownVirtual20(hkBool wantRuntime,
                          ConstraintRuntimeInfo &infoOut) const; /* slot 20 (0x7a050) */

    hkpBridgeAtoms atoms;
    hkpParametricCurve *path;
    float maxFrictionForce;
    hkEnum<OrientationConstraintType, s8> angularConstrainedDOF;
};

/* hkMemoryMeshMaterial, 0x80 bytes (type info 0x57bd4a8, vtable 0x16a3920 stored
 * by its finish constructor 0xaccf0): members from its record table
 * at 0x1691e80, materialName (hkStringPtr) at +0x10, textures (array of
 * pointers to hkMeshTexture, hkClass 0x57bc990) at +0x18, diffuseColor,
 * ambientColor, specularColor and emissiveColor (hkVector4) from +0x30,
 * userData (hkUlong) at +0x70, tesselationFactor (hkReal) at +0x78,
 * displacementAmount (hkReal) at +0x7c. */
extern const hkClass D_57bd458; /* hkMemoryMeshMaterial's hkClass, built at 0x24752 */

class hkMeshTexture;

/* hkMeshMaterial (hkClass 0x57bd680, built at 0x26654, parent
 * hkReferencedObject's 0x57b8640), the parent of hkMemoryMeshMaterial's
 * hkClass (at 0x24760). */
class hkMeshMaterial : public hkReferencedObject
{
  public:
    hkMeshMaterial(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    /* The material interface's slots up to 14, typed from
     * hkMemoryMeshMaterial's overriders (vtable 0x16a3910); the later slots
     * are not declared yet. derived names. */
    virtual hkResult unknownVirtual5(const hkVertexFormat &format, hkVertexFormat &formatOut);
    virtual hkMeshVertexBuffer *unknownVirtual6(hkMeshVertexBuffer *buffer);
    virtual hkBool unknownVirtual7(hkMeshVertexBuffer *buffer);
    virtual void unknownVirtual8();
    virtual void unknownVirtual9(const char *newName);
    virtual const char *unknownVirtual10() const;
    virtual int unknownVirtual11() const;
    virtual hkMeshTexture *unknownVirtual12(int index) const;
    /* Slot 13 adds a texture, slot 14 puts one at an index. */
    virtual void unknownVirtual13(hkMeshTexture *texture);
    virtual void unknownVirtual14(int index, hkMeshTexture *texture);
};

class hkMemoryMeshMaterial : public hkMeshMaterial
{
  public:
    /* Out of line (0xaccf0): the finish callback 0x246d0 jumps to it, the
     * reflection initializer at 0x24784 runs it on a temporary. */
    hkMemoryMeshMaterial(hkFinishLoadedObjectFlag flag);
    virtual ~hkMemoryMeshMaterial();

    const hkClass *getClassType() const; /* vtable slot 3, FUN_000246c0 */
    hkResult FUN_000acf00(const hkVertexFormat &format,
                          hkVertexFormat &formatOut);             /* vtable slot 5; derived name */
    hkMeshVertexBuffer *FUN_000acf10(hkMeshVertexBuffer *buffer); /* vtable slot 6; derived name */
    hkBool FUN_000acf40(hkMeshVertexBuffer *buffer);              /* vtable slot 7; derived name */
    void FUN_000acf80(const char *newName);                       /* vtable slot 9; derived name */
    const char *FUN_000acf90() const;                             /* vtable slot 10; derived name */
    hkMeshTexture *FUN_000acfb0(int index) const;                 /* vtable slot 12; derived name */
    /* The index a new texture goes at (0xacfc0): after the textures whose
     * slot 15 value is not above its own, the later ones moved up and a
     * null slot left for it. derived name. */
    int FUN_000acfc0(hkMeshTexture *texture);
    void FUN_000ad1c0(hkMeshTexture *texture); /* vtable slot 13; derived name */
    void FUN_000ad2a0(Vec4 &diffuse, Vec4 &ambient, Vec4 &specular,
                      Vec4 &emissive) const; /* vtable slot 15; derived name */
    void FUN_000ad2d0(const Vec4 &diffuse, const Vec4 &ambient, const Vec4 &specular,
                      const Vec4 &emissive); /* vtable slot 16; derived name */
    hkUlong FUN_000acae0() const;            /* vtable slot 17; derived name */
    void FUN_000acaf0(hkUlong newUserData);  /* vtable slot 18; derived name */
    float FUN_000acb00() const;              /* vtable slot 19; derived name */
    void FUN_000acb10(float factor);         /* vtable slot 20; derived name */
    float FUN_000acb20() const;              /* vtable slot 21; derived name */
    void FUN_000acb30(float amount);         /* vtable slot 22; derived name */

    hkStringPtr materialName;
    hkArray<hkMeshTexture *> textures;
    Vec4 diffuseColor;
    Vec4 ambientColor;
    Vec4 specularColor;
    Vec4 emissiveColor;
    hkUlong userData;
    float tesselationFactor;
    float displacementAmount;
};

/* hkMeshTexture (hkClass 0x57bc990, built at 0x229f0, parent
 * hkReferencedObject's 0x57b8640), the texture interface, with its three
 * reflected enums (item tables at 0x1690ea0, 0x1690f00, 0x1690f30). */
class hkMeshTexture : public hkReferencedObject
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

    hkMeshTexture(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

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
    hkMemoryMeshTexture(hkFinishLoadedObjectFlag flag) : hkMeshTexture(flag), data(flag)
    {
        FUN_0000e5c0(&filename, flag);
    }

    virtual ~hkMemoryMeshTexture();

    const hkClass *getClassType() const; /* vtable slot 3, FUN_000247f0 */
    void FUN_000ad620(u8 *&dataOut, int &sizeOut,
                      Format &formatOut);             /* vtable slot 5; derived name */
    Format FUN_000ad6e0() const;                      /* vtable slot 8; derived name */
    bool FUN_000ad710() const;                        /* vtable slot 11; derived name */
    void FUN_000ad720(bool newHasMipMaps);            /* vtable slot 12; derived name */
    FilterMode FUN_000ad730() const;                  /* vtable slot 13; derived name */
    void FUN_000ad740(FilterMode newFilterMode);      /* vtable slot 14; derived name */
    TextureUsageType FUN_000ad750() const;            /* vtable slot 15; derived name */
    void FUN_000ad760(TextureUsageType newUsageHint); /* vtable slot 16; derived name */
    int FUN_000ad770() const;                         /* vtable slot 17; derived name */
    void FUN_000ad780(int newTextureCoordChannel);    /* vtable slot 18; derived name */

    hkStringPtr filename;
    hkArray<u8> data;
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

/* The stream writer interface (derived name; hkPs4StreamWriter,
 * hkBufferedStreamWriter and hkArrayStreamWriter fill it): slot 5 tells
 * whether the stream is usable (hkBool), slot 6 writes (buffer, byte count),
 * slot 7 flushes. Slots 2 to 4 are not recovered. */
class hkStreamWriter : public hkReferencedObject /* derived name */
{
  public:
    virtual hkBool isOk() const;                     /* vtable slot 5; derived name */
    virtual int write(const void *buffer, int size); /* vtable slot 6; derived name */
    virtual void flush();                            /* vtable slot 7; derived name */
    /* Slot 8: the buffered writer asks the stream it buffers (FUN_00009280)
     * and answers true without one. */
    virtual hkBool unknownVirtual8() const;
    /* Slot 9: a seek from the start (0), the position (1) or the end (2)
     * (the counting writer's 0x19f6d0; the buffered writer's is 0x92a0).
     * derived name. */
    virtual hkResult seek(int offset, int whence);
    /* Slot 10: the position in the stream, negative when it has none (the
     * buffered writer's 0x9380 asks the stream it buffers). derived name. */
    virtual int tell() const;
};

/* A stream writer that only counts (derived name; vtable 0x16a6af0, address
 * point 0x16a6b00, no type info; constructor FUN_0019f670, built on the stack
 * at 0x19ad01 and 0x19c76d): the write position at +0xc and the end of what
 * was written at +0x10. Slot 6 (0x19f6a0) advances the position by the byte
 * count and keeps the end at least there, returning the count; slot 9
 * (0x19f6d0) seeks from the start, the position or the end; slot 10 (the
 * shared 0x34840) tells the position; 5 and 8 answer true, 7 is empty. */
class OffsetOnlyStreamWriter : public hkStreamWriter /* derived name */
{
  public:
    OffsetOnlyStreamWriter();
    virtual ~OffsetOnlyStreamWriter();

    int write(const void *buffer, int size); /* vtable slot 6 */
    hkResult seek(int offset, int whence);   /* vtable slot 9 */

    int offset; /* derived name */
    int end;    /* derived name */
};

/* An output archive over a stream writer (derived name): a reference-counted
 * object (vtable address point 0x168d400, five slots, constructor 0xa280,
 * complete destructor 0xa3b0 releasing the writer at +0x10) with a
 * byte-swap flag at +0x18 (set and read by 0xabd0 and 0xabe0); 0xac00
 * returns the writer, FUN_0000abf0 tells whether it is usable. A caller
 * (0x1a3854) builds one on the stack, writes, then returns that test. */
class hkOArchive : public hkReferencedObject /* derived name */
{
  public:
    hkBool FUN_0000abf0() const; /* derived name */

    hkStreamWriter *writer; /* derived name */
    hkBool byteSwap;        /* derived name */
};

/* Its writer (hkStreamWriter) at +0x10: FUN_000089e0 flushes it,
 * FUN_000089f0 writes to it. The caller at 0x14ec7 passes an hkOArchive
 * built by 0xa280 (writer also at +0x10), and hkSkinBinding's slot 6 is
 * this body too: identical bodies folded onto this one. */
class hkOstream : public hkReferencedObject
{
  public:
    /* Slot 0 of its vtable (0x168d100, stored by its constructor 0x80c0):
     * stores the vtable and releases the writer (0x8310). */
    virtual ~hkOstream();

    const hkClass *getClassType() const;            /* vtable slot 3, FUN_00008a20 */
    void FUN_000089e0();                            /* derived name */
    int FUN_000089f0(const void *buffer, int size); /* derived name */

    /* derived name: the operator<< of a C string (0x8440): writes its
     * strlen bytes, or "(null)" for a null pointer, and returns the
     * stream. */
    hkOstream &FUN_00008440(const char *string);

    /* derived name: the operator<< of a string buffer (0x89a0, called six
     * times by 0xadd80): its characters without the terminator, or
     * "(null)" for a buffer with none, and the stream returned. */
    hkOstream &FUN_000089a0(const hkStringBuf &string);

    /* derived name: the operator<< of an unsigned int (0x8550): formatted
     * with "%u" into a buffer on the stack, written, and the stream
     * returned. */
    hkOstream &FUN_00008550(unsigned int value);

    /* derived name: formatted output (0x86f0, variadic). */
    void FUN_000086f0(const char *format, ...);

    /* derived names: the operator<< of a vector, its four lanes as "%g"
     * (0x86b0, called at 0x3db61, 0x3db7c and 0x3db97), and of a vector whose
     * last lane is set apart, as "%f" (0x8810, called at 0x16f35b and
     * 0x16f59b). Each returns the stream. */
    hkOstream &FUN_000086b0(const Vec4 &v);
    hkOstream &FUN_00008810(const Vec4 &v);

    hkStreamWriter *writer; /* derived name */
};

/* A stream over a caller's buffer (derived name; vtable 0x168c3a0, no type
 * info; its slot 3 is hkOstream's class getter): the constructor 0xda0
 * runs hkOstream's (0x80c0) and builds its writer in place in the last 0x30
 * bytes of the buffer (FUN_00008f50), so the destructor drops the writer
 * before hkOstream's destructor would release it. "Not implemented" reports
 * (0x6f7d0 and its siblings) build one on the stack over 0x200 bytes. */
class BufferOstream : public hkOstream /* derived name */
{
  public:
    virtual ~BufferOstream();
};

/* The world's events print their names: the dispatcher at 0x6c110 switches
 * on an event's 16-bit type at +4 (26 types) and calls the type's printer
 * with the world and the stream it was given. Derived names, from the
 * printed names: */
struct hknpConstraintForceEvent /* derived name */
{
    void FUN_0003ddb0(hknpWorld *world, hkOstream &out) const; /* derived name */
};

struct hknpConstraintForceExceededEvent /* derived name */
{
    void FUN_0003ddc0(hknpWorld *world, hkOstream &out) const; /* derived name */
};

/* Two body events print the body's id, at +0xc. */
struct hknpBodyExitedBroadPhaseEvent /* derived name */
{
    void FUN_00155490(hknpWorld *world, hkOstream &out) const; /* derived name */

    u8 unknown0[0xc];
    u32 bodyId; /* derived name */
};

struct hknpBodyBreachedExpandedAabbEvent /* derived name */
{
    void FUN_001554c0(hknpWorld *world, hkOstream &out) const; /* derived name */

    u8 unknown0[0xc];
    u32 bodyId; /* derived name */
};

/* The printer of the four reserved types (the dispatcher's last four
 * cases). */
struct hknpReservedEvent /* derived name */
{
    void FUN_00040be0(hknpWorld *world, hkOstream &out) const; /* derived name */
};

/* hkBufferedStreamWriter: its hkClass at 0x57b7fe8 is built by the
 * reflection initializer at 0x93d0 (name "hkBufferedStreamWriter"); slot 3
 * of its vtable (address point 0x168d220, FUN_00008ea0) returns it. */
extern const hkClass D_57b7fe8; /* hkBufferedStreamWriter's hkClass */

/* Its slots 5 to 7 (0x9260, 0x90f0, 0x91f0) are the stream writer's; its
 * hkClass has no parent (0x9429), the stream writer not being reflected. The
 * stream it buffers is at +0x10. */
class hkBufferedStreamWriter : public hkStreamWriter
{
  public:
    const hkClass *getClassType() const; /* vtable slot 3, FUN_00008ea0 */
    hkBool FUN_00009260() const;         /* vtable slot 5; derived name */
    hkBool FUN_00009280() const;         /* vtable slot 8; derived name */
    int FUN_00009380() const;            /* vtable slot 10; derived name */

    hkStreamWriter *stream; /* derived name */
    /* The buffer, the bytes in it and its capacity, as the constructor
     * 0x8f50 stores them and the write slot 0x90f0 reads them. */
    char *buffer;       /* derived name */
    int bufferSize;     /* derived name */
    int bufferCapacity; /* derived name */
};

/* hkSkinnedRefMeshShape: its hkClass at 0x57bcd20 is built by the
 * reflection initializer at 0x23402; slot 3 of its vtable (0x16a38c0,
 * FUN_00023370) returns it; its parent is hkMeshShape's, 0x57bd7d0 (at
 * 0x23410). */
extern const hkClass D_57bcd20; /* hkSkinnedRefMeshShape's hkClass */

class hkSkinnedRefMeshShape : public hkMeshShape
{
  public:
    /* Out of line (0xaa660): the finish callback 0x23380 jumps to it, the
     * reflection initializer at 0x23431 runs it on a temporary. */
    hkSkinnedRefMeshShape(hkFinishLoadedObjectFlag flag);
    virtual ~hkSkinnedRefMeshShape();

    const hkClass *getClassType() const;    /* vtable slot 3, FUN_00023370 */
    const char *FUN_000aa880() const;       /* vtable slot 8; derived name */
    void FUN_000aa890(const char *newName); /* vtable slot 9; derived name */

    /* From its record table at 0x16916c0: skinnedMeshShape (pointer) at
     * +0x10, bones and localFromRootTransforms (arrays) at +0x18 and +0x28,
     * name (hkStringPtr) at +0x38. */
    u8 unknownC[0x2c];
    hkStringPtr name;
};

/* hkMemoryMeshShape: its hkClass at 0x57bd0a0 is built by the reflection
 * initializer at 0x241e3; slot 3 of its vtable (0x1692540, FUN_00023de0)
 * returns it; its parent is hkMeshShape's, 0x57bd7d0 (at 0x241f1). */
extern const hkClass D_57bd0a0; /* hkMemoryMeshShape's hkClass */

class hkMemoryMeshShape : public hkMeshShape
{
  public:
    hkMemoryMeshShape(hkFinishLoadedObjectFlag flag);
    virtual ~hkMemoryMeshShape();

    const hkClass *getClassType() const;    /* vtable slot 3, FUN_00023de0 */
    const char *FUN_0002a910() const;       /* vtable slot 8; derived name */
    void FUN_0002a920(const char *newName); /* vtable slot 9; derived name */

    /* From its record table at 0x1691bf0: sections (array) at +0x10,
     * indices16 and indices32 (arrays) at +0x20 and +0x30, name
     * (hkStringPtr, finished by its finish constructor 0x2a940) at +0x40. */
    u8 unknownC[0x34];
    hkStringPtr name;
};

/* hkSkinBinding: its hkClass at 0x57bd288 is built by the reflection
 * initializer at 0x24362; slot 3 of its vtable (0x16a3860, FUN_000242d0)
 * returns it. */
extern const hkClass D_57bd288; /* hkSkinBinding's hkClass */

/* Its members from the record table at 0x1691c90 (0x38 bytes): skin (a
 * pointer to hkMeshShape) at +0x10, worldFromBoneTransforms (array of
 * hkTransform) at +0x18, boneNames (array of hkStringPtr) at +0x28. Slots 5
 * to 9 forward to the skin (slot 5 folded onto 0xabf0, slot 6 onto 0x89f0;
 * 0xaa520, FUN_000aa530 the name, 0xaa540). Its finish constructor 0xaa4f0
 * is out of line, jumped to by the finish callback FUN_000242e0 and called
 * by the reflection initializer at 0x24390. */
class hkSkinBinding : public hkMeshShape
{
  public:
    hkSkinBinding(hkFinishLoadedObjectFlag flag);
    virtual ~hkSkinBinding();

    const hkClass *getClassType() const;             /* vtable slot 3, FUN_000242d0 */
    void FUN_000aa520(const hkMeshSection &section); /* vtable slot 7; derived name */
    const char *FUN_000aa530() const;                /* vtable slot 8; derived name */
    void FUN_000aa540(const char *newName);          /* vtable slot 9; derived name */

    hkMeshShape *skin;
};

/* hkSkinnedMeshShape::Part (records 0x1692280, 0x30 bytes): startVertex,
 * numVertices, startIndex and numIndices (hkInt32) from +0, boneSetId and
 * meshSectionIndex (hkUint16) at +0x10 and +0x12, boundingSphere
 * (hkVector4) at +0x20. hkStorageSkinnedMeshShape keeps its parts in an
 * array at +0x40 (count at +0x48); its slot 16 (0xae860) sorts them with the
 * quick sort FUN_000ad970 and the order FUN_000ad900. */
/* hkSkinnedMeshShape::BoneSet (records 0x1692230): boneBufferOffset and
 * numBones (hkUint16) at +0 and +2. hkSkinnedMeshShape's hkClass 0x57bdcc8
 * (built at 0x27de4) has hkReferencedObject's 0x57b8640 as parent. */
class hkSkinnedMeshShape : public hkReferencedObject
{
  public:
    hkSkinnedMeshShape(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    /* A bone set's id: a 16-bit handle passed by value (derived name). The
     * callee widens it itself (`movzwl %si` before the index in 0xae770):
     * a two-byte struct travels as an i16 with no zero-extension promise,
     * unlike a plain hkUint16 parameter. */
    struct BoneSetId {
        /* Its own assignment: a part's copy (0xae83f, the quick sort's at
         * 0xad9da) copies the id by itself, outside the memcpy of the four
         * counts before it, which a plain field would have joined. */
        void operator=(const BoneSetId &other)
        {
            value = other.value;
        }

        u16 value; /* derived name */
    };

    /* A part's mesh section, a handle as the bone set's is: copied by its
     * own assignment too (0xae848), where a plain field would have joined
     * the vector's copy after it. derived name. */
    struct MeshSectionIndex {
        void operator=(const MeshSectionIndex &other)
        {
            value = other.value;
        }

        u16 value; /* derived name */
    };

    struct BoneSet {
        u16 boneBufferOffset;
        u16 numBones;
    };

    struct Part {
        int startVertex;
        int numVertices;
        int startIndex;
        int numIndices;
        BoneSetId boneSetId;
        MeshSectionIndex meshSectionIndex;
        hkVector4 boundingSphere;
    };
};

bool FUN_000ad900(const hkSkinnedMeshShape::Part &a,
                  const hkSkinnedMeshShape::Part &b); /* derived name */

/* The quick sort of parts between two indices, inclusive, by an order
 * (0xad970; derived name). */
void FUN_000ad970(hkSkinnedMeshShape::Part *parts, int low, int high,
                  bool (*less)(const hkSkinnedMeshShape::Part &a,
                               const hkSkinnedMeshShape::Part &b)); /* derived name */

/* hkStorageSkinnedMeshShape: its hkClass at 0x57bdd18 is built by the
 * reflection initializer at 0x27e79; slot 3 of its vtable (0x16a3b00,
 * FUN_00027bd0) returns it; its parent is hkSkinnedMeshShape's, 0x57bdcc8
 * (at 0x27ec9). */
extern const hkClass D_57bdd18; /* hkStorageSkinnedMeshShape's hkClass */

class hkStorageSkinnedMeshShape : public hkSkinnedMeshShape
{
  public:
    /* Out of line (0xae680): the finish callback 0x27be0 jumps to it, the
     * reflection initializer at 0x27ee6 runs it on a temporary. */
    hkStorageSkinnedMeshShape(hkFinishLoadedObjectFlag flag);
    virtual ~hkStorageSkinnedMeshShape();

    const hkClass *getClassType() const; /* vtable slot 3, FUN_00027bd0 */
    void
    FUN_000ae770(hkSkinnedMeshShape::BoneSetId boneSetId,
                 hkSkinnedMeshShape::BoneSet &boneSetOut) const; /* vtable slot 7; derived name */
    const char *FUN_000aea20() const;                            /* vtable slot 12; derived name */
    void FUN_000aea30(const char *newName);                      /* vtable slot 13; derived name */
    void FUN_000ae860();                                         /* vtable slot 16; derived name */
    /* Slot 10 (0xae820): a copy of a part. derived name. */
    void FUN_000ae820(int partIndex, hkSkinnedMeshShape::Part &partOut) const;

    /* From its record table at 0x1692420: bonesBuffer, boneSets,
     * boneSections and parts (arrays) from +0x10, name (hkStringPtr) at
     * +0x50. */
    u8 unknownC[4];
    u8 bonesBuffer[0x10];
    hkArray<hkSkinnedMeshShape::BoneSet> boneSets;
    u8 boneSections[0x10];
    hkArray<hkSkinnedMeshShape::Part> parts;
    hkStringPtr name;
};

/* hkGeometry, polymorphic (vtable 0x1692500; hkClass parent
 * hkReferencedObject, built at 0x1a5b5): members from its record table at
 * 0x168ea40, vertices (array of hkVector4) at +0x10 and triangles (array of
 * hkGeometry::Triangle, 16 bytes each) at +0x20. Its finish constructor
 * 0x93c60 is out of line, jumped to by the finish callback FUN_0001a4e0 and
 * called by the reflection initializer at 0x1a633; FUN_00093c70 empties both
 * arrays (called at 0x42340, 0x104028 and 0x10415b). */
class hkGeometry : public hkReferencedObject
{
  public:
    struct Triangle;

    hkGeometry(hkFinishLoadedObjectFlag flag);
    virtual ~hkGeometry();

    void FUN_00093c70(); /* derived name */

    hkArray<Vec4> vertices;
    hkArray<Triangle> triangles;
};

/* hkGeometry::Triangle: the vertex indices a, b and c and the material, four
 * hkInt32 (member records 0x168e950 to 0x168e9c8). */
struct hkGeometry::Triangle {
    s32 a;
    s32 b;
    s32 c;
    s32 material;
};

/* hknpDefaultExternMeshShapeGeometry (type info 0x57bfce0, vtable address
 * point 0x16959f0, reflected member geometry at +0x10): its destructors
 * (slots 0 and 1, 0x3b870 and 0x3b8e0) release the counted reference to the
 * hkGeometry at +0x10; slot 5 (FUN_0003b980) returns its triangle count,
 * slot 6 copies a triangle's three vertices, slot 7 returns a triangle's
 * 16-bit material at +0xc. */
class hknpDefaultExternMeshShapeGeometry : public hkReferencedObject
{
  public:
    /* The finish constructor, inline in the finish callback FUN_0003ba10:
     * only the vtable is set. */
    hknpDefaultExternMeshShapeGeometry(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    virtual ~hknpDefaultExternMeshShapeGeometry();

    int FUN_0003b980() const;                  /* vtable slot 5; derived name */
    u16 FUN_0003b9e0(int triangleIndex) const; /* vtable slot 7; derived name */

    hkGeometry *geometry;
};

/* hknpCompositeShape: its hkClass at 0x57c2cf8 (parent 0x57bf1c0) is built by
 * the reflection initializer at 0x71732, whose type info names the vtable
 * 0x1697c80 (address point 0x1697c90), the intermediate base whose vtable the
 * finish constructors of hknpLodShape, hknpCompressedHeightFieldShape and
 * hknpCompressedMeshShape store before their own. Slot 3 (FUN_00042e80)
 * returns it, and six derived vtables (0x1699c10, 0x16a3e40, 0x16a49a0,
 * 0x16a5180, 0x16a5990, 0x16ca050) keep it. */
extern const hkClass D_57c2cf8; /* hknpCompositeShape's hkClass */

class hknpCompositeShape : public hknpShape
{
  public:
    /* Inline: the type info's finish callback FUN_00071690 runs it, and
     * hknpLodShape's finish constructor (0x68160) inlines it before storing
     * its own vtable. */
    hknpCompositeShape(hkFinishLoadedObjectFlag flag) : hknpShape(flag)
    {
        if (flag.finishing) {
            flags |= 4;
        }
    }

    virtual ~hknpCompositeShape();

    const hkClass *getClassType() const; /* vtable slot 3, FUN_00042e80 */
};

/* What hknpExternMeshShapeData's buildContext points to (derived name; the
 * member is not serialized, flags 0x400): signals at +0x48, which slot 8 of
 * hknpExternMeshShape hands out. */
struct hknpExternMeshShapeBuildContext /* derived name */
{
    u8 unknown0[0x48];
    hknpShapeSignals mutationSignals; /* derived name */
};

/* hknpExternMeshShapeData (hkClass 0x57be420 built at 0x35585, parent
 * hkReferencedObject, 0x60 bytes): aabbTree (struct) at +0x10, simdTree
 * (struct) at +0x40 and buildContext (pointer) at +0x58, member records from
 * 0x1692c80. */
class hknpExternMeshShapeData : public hkReferencedObject
{
  public:
    /* The finish constructor, inline: the type info's finish callback
     * (FUN_000354c0) and the reflection initializer (0x3558a) each hold a
     * copy. The build context is not serialized and starts null. */
    hknpExternMeshShapeData(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), simdTree(flag)
    {
        buildContext = 0;
    }

    u8 aabbTree[0x30];
    hkcdSimdTree simdTree;
    hknpExternMeshShapeBuildContext *buildContext;
};

/* hknpExternMeshShape (hkClass 0x57c2898, parent hknpCompositeShape, 0x70
 * bytes): geometry (pointer) at +0x60 and boundingVolumeData (pointer to
 * hknpExternMeshShapeData) at +0x68 (records 0x169abc0, 0x169abe8). */
/* hknpHeightFieldShape (hkClass 0x57bf540, built at 0x3993e: size 0xf0,
 * parent hknpCompositeShape's 0x57c2cf8): no type info and no vtable of its
 * own in the executable; its inline finish constructor's vptr store dies
 * under the derived one (the same block, DSE). */
class hknpHeightFieldShape : public hknpCompositeShape
{
  public:
    hknpHeightFieldShape(hkFinishLoadedObjectFlag flag) : hknpCompositeShape(flag) {}
};

/* hknpCompressedHeightFieldShape (type info 0x57c2378; hkClass 0x57c2328,
 * built at 0x6958a: size 0x120, parent hknpHeightFieldShape's 0x57bf540;
 * vtable 0x16a5980). */
class hknpCompressedHeightFieldShape : public hknpHeightFieldShape
{
  public:
    /* The finish constructor, out of line (0x175de0): the finish callback
     * FUN_000694e0 jumps to it, the reflection initializer calls it at
     * 0x69593. */
    hknpCompressedHeightFieldShape(hkFinishLoadedObjectFlag flag);
};

class hknpExternMeshShape : public hknpCompositeShape
{
  public:
    /* The finish constructor, out of line (0x1660e0): the finish callback
     * FUN_0006c440 jumps to it, the reflection initializer calls it at
     * 0x6c506. */
    hknpExternMeshShape(hkFinishLoadedObjectFlag flag);

    hknpShapeSignals *FUN_000eafb0(); /* vtable slot 8; derived name */

    u8 unknown28[0x38]; /* hknpCompositeShape's members, not recovered */
    void *geometry;
    hknpExternMeshShapeData *boundingVolumeData;
};

/* What hknpCompoundShape's constructor from a description (0x412a0, the
 * static compound shape's at 0x38466 runs it) is built from: 0x28 bytes,
 * not reflected, one built on the game's stack at 0xea5b13 and filled at
 * +0 and +8 before 0x38440 builds the shape. The constructor reads the ints
 * at +8 and +0xc (the larger one sizes the shape's array) and the buffer
 * at +0x20; the static compound shape's, the pointer at +0x18. Its
 * constructor is out of line (0x41260). derived names. */
struct hknpCompoundShapeCinfo /* derived name */
{
    hknpCompoundShapeCinfo();

    const void *unknown0;
    int unknown8;
    int unknownC;
    bool unknown10;
    const void *unknown18;
    void *unknown20;
};

/* hknpCompoundShape: its hkClass at 0x57c2e78 is built by the reflection
 * initializer at 0x77eae and is the parent of hknpDynamicCompoundShape's and
 * hknpStaticCompoundShape's; slot 3 of its vtable (address point 0x1697910,
 * FUN_000418b0) returns it. */
extern const hkClass D_57c2e78; /* hknpCompoundShape's hkClass */

/* Its parent is hknpCompositeShape (the hkClass constructor's third
 * argument at 0x77ebc is 0x57c2cf8). Slots 0 to 30 of the vtable at
 * 0x1697910 keep hknpShape's bodies except slots 0, 1 and 3 and its own
 * 7 (FUN_00041870), 8 (FUN_00041890), 21 (FUN_000418c0), 22
 * (FUN_00041a80), 27 (FUN_000426b0), 28 (FUN_00041e40) and 29
 * (FUN_00042300). Slots 31 and 32 are pure (__cxa_pure_virtual); slot 31
 * of hknpStaticCompoundShape (FUN_000d0450) recomputes the shape's AABB
 * from its tree, hence its name. */
class hknpCompoundShape : public hknpCompositeShape
{
  public:
    /* The finish constructor, out of line (0x41590): hknpShape's, its
     * vtable, bit 2 of the flags at +0x10 when finishing, then the
     * compound's own vtable and the signal pointers at +0xa8 and +0xb0
     * cleared. */
    hknpCompoundShape(hkFinishLoadedObjectFlag flag);

    virtual ~hknpCompoundShape();

    const hkClass *getClassType() const; /* vtable slot 3, FUN_000418b0 */
    void unknownVirtual7(const Mat4 &transform, hkAabb &aabbOut) const; /* FUN_00041870 */
    virtual void updateAabb() = 0;                                      /* slot 31; derived name */
    virtual void unknownVirtual32() = 0;

    hknpShapeSignals *FUN_00041890(); /* vtable slot 8; derived name */

    u8 unknown28[0x38];
    hkFreeListArray<hknpShapeInstance, hknpShapeInstanceId, 8, hknpShapeInstance> instances;
    /* The AABB slot 7 transforms (updateAabb recomputes it). */
    hkAabb aabb;
    /* Members from the record table 0x169b520 (hkClass 0x57c2e78, size
     * 0xc0): instances at +0x60, aabb at +0x80, isMutable (hkBool) at
     * +0xa0, mutationSignals (not serialized, flags 0x400) at +0xa8. */
    hkBool isMutable;
    hknpShapeSignals mutationSignals;
};

/* hknpStaticCompoundShape, polymorphic, 0xc0 bytes (type info 0x57c2818,
 * parent hknpCompoundShape): its finish callback FUN_0006c310 runs the
 * finish constructor 0x385d0, which stores the vtable 0x1693f40, whose
 * slot 0 is the destructor at 0x386c0. Its hkClass's parent is
 * hknpCompoundShape's, 0x57c2e78 (at 0x6c3a3). */
extern const hkClass D_57c27c8; /* hknpStaticCompoundShape's hkClass, built at 0x6c395 */

class hknpStaticCompoundShape : public hknpCompoundShape
{
  public:
    hknpStaticCompoundShape(hkFinishLoadedObjectFlag flag); /* 0x385d0 */

    virtual ~hknpStaticCompoundShape();

    void updateAabb();       /* vtable slot 31, FUN_000d0450 */
    void unknownVirtual32(); /* vtable slot 32 */

    /* vtable slot 3, FUN_00038740, also of hknpStaticCompoundShapeInternals
     * (0x1692840), which does not override it */
    const hkClass *getClassType() const;
};

/* hknpStaticCompoundShapeInternals, 0xc0 bytes (type info 0x57bde70, vtable
 * 0x1692840), reflected with hknpStaticCompoundShape as its parent and no
 * members of its own. */
class hknpStaticCompoundShapeInternals : public hknpStaticCompoundShape
{
  public:
    hknpStaticCompoundShapeInternals(hkFinishLoadedObjectFlag flag) : hknpStaticCompoundShape(flag)
    {
    }

    virtual ~hknpStaticCompoundShapeInternals();
};

/* The finish callback of hknpStaticCompoundShapeInternals' type info
 * (0x57bde70, set at 0x340cc). derived name. */
void FUN_00033fb0(void *object, int finishing); /* derived name */

/* hknpDynamicCompoundShape: its hkClass at 0x57be640 is built by the
 * reflection initializer at 0x35935; slot 3 of its vtable (0x1697ef0,
 * FUN_000358a0) returns it; its parent is hknpCompoundShape's, 0x57c2e78
 * (at 0x35943). */
extern const hkClass D_57be640; /* hknpDynamicCompoundShape's hkClass */

class hknpDynamicCompoundShape : public hknpCompoundShape
{
  public:
    hknpDynamicCompoundShape(hkFinishLoadedObjectFlag flag); /* 0x469a0 */

    virtual ~hknpDynamicCompoundShape();

    void updateAabb();       /* vtable slot 31, 0xefff0 */
    void unknownVirtual32(); /* vtable slot 32, 0xf04a0 */

    const hkClass *getClassType() const; /* vtable slot 3, FUN_000358a0 */
};

/* hknpLodShape (type info 0x57c05b8, parent hknpCompositeShape: its finish
 * constructor FUN_00068160 stores hknpCompositeShape's vtable before its own
 * 0x1699c00): slot 7 (FUN_00068350) transforms the AABB at +0x110. */
struct hknpLodShape : public hknpCompositeShape {
    /* The finish constructor, out of line (0x68160): the finish callback
     * FUN_0003de50 jumps to it, the reflection initializer calls it at
     * 0x3dfa6. */
    hknpLodShape(hkFinishLoadedObjectFlag flag);

    /* What slot 29's first argument holds at +0x10 (derived names). */
    struct Slot29Argument {
        u8 unknown0[0x10];
        int levelOfDetail; /* derived name */
    };

    void unknownVirtual7(const Mat4 &transform, hkAabb &aabbOut) const; /* FUN_00068350 */
    void FUN_00068960(const Slot29Argument *argument1,
                      void *argument2) const; /* vtable slot 29; derived name */

    /* Members from the records at 0x16965c0. */
    u8 unknown28[0x2c];
    int numLevelsOfDetail;
    u8 infos[0x40];
    const hknpShape *shapes[8];
    u8 unknownD8[0x38]; /* shapesMemorySizes, indexCurrentShapeOnSpu, currentShapePpuAddress */
    hkAabb aabb;        /* maximumAabb */
};

/* hkxBlobMeshShape: its hkClass at 0x57c5e78 is built by the reflection initializer at
 * 0x85de2; slot 3 of its vtable (address point 0x16a07a0, FUN_00085d30) returns it; its parent is hkMeshShape's,
 * 0x57bd7d0 (at 0x85df0). */
extern const hkClass D_57c5e78; /* hkxBlobMeshShape's hkClass */

class hkxBlobMeshShape : public hkMeshShape
{
  public:
    /* The finish constructor (0x85d40, the type info's finish function
     * itself): the vtable, the blob's, then the name finished. */
    hkxBlobMeshShape(hkFinishLoadedObjectFlag flag);

    virtual ~hkxBlobMeshShape();

    const hkClass *getClassType() const;    /* vtable slot 3, FUN_00085d30 */
    const char *FUN_00085c20() const;       /* vtable slot 8; derived name */
    void FUN_00085c30(const char *newName); /* vtable slot 9; derived name */

    /* From its record table at 0x16a0830 (0x38 bytes): blob (struct
     * hkxBlob, hkClass 0x57c7a80) at +0x10, name (hkStringPtr) at +0x30. */
    hkxBlob blob;
    hkStringPtr name;
};

/* hkxTextureFile: its hkClass at 0x57c67d0 is built by the reflection initializer at
 * 0x879b2 (size 0x28, member records at 0x16a0f30: filename, name and
 * originalFilename, hkStringPtr, from +0x10); slot 3 of its vtable (address
 * point 0x16a0f00, FUN_000878e0) returns it; its parent is
 * hkReferencedObject's, 0x57b8640 (at 0x879c0). */
extern const hkClass D_57c67d0; /* hkxTextureFile's hkClass */

class hkxTextureFile : public hkReferencedObject
{
  public:
    /* Slot 0 (0x87830): the three strings destroyed, the last first. */
    virtual ~hkxTextureFile();

    const hkClass *getClassType() const; /* vtable slot 3, FUN_000878e0 */

    hkStringPtr filename;
    hkStringPtr name;
    hkStringPtr originalFilename;
};

/* hkxAnimatedFloat: its hkClass at 0x57c7930 is built by the reflection initializer at
 * 0x8bac2; slot 3 of its vtable (address point 0x16a24d0, FUN_0008ba30) returns it. */
extern const hkClass D_57c7930; /* hkxAnimatedFloat's hkClass */

class hkxAnimatedFloat : public hkReferencedObject
{
  public:
    /* Its finish constructor, run by the finish callback FUN_0008ba40, has
     * nothing to fix up but the vtable (0x16a24c0); hkReferencedObject is
     * the hkClass's parent. */
    hkxAnimatedFloat(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    virtual ~hkxAnimatedFloat();

    const hkClass *getClassType() const; /* vtable slot 3, FUN_0008ba30 */
};

/* hkArrayStreamWriter: its hkClass at 0x57c8750 is built by the reflection initializer at
 * 0x901fb; slot 3 of its vtable (address point 0x16a3300, FUN_0008ff00) returns it. Its hkClass has no parent (null third
 * argument at 0x90209): hkStreamWriter is not reflected. Its vtable keeps
 * the stream writer's slots: 5 true (0x40b0), 6 the write (0x90000), 7 an
 * empty flush (0x270), 8 true (0x40b0). */
extern const hkClass D_57c8750; /* hkArrayStreamWriter's hkClass */

class hkArrayStreamWriter : public hkStreamWriter
{
  public:
    virtual ~hkArrayStreamWriter();

    const hkClass *getClassType() const; /* vtable slot 3, FUN_0008ff00 */
};

/* hknpVehicleInstance: hkClass 0x57c1490 (size 0x120, parent hknpUnaryAction's
 * 0x57bfbc0), built by the reflection initializer at 0x47a5d with its member
 * records at 0x1698a70; its finish callback 0x47990 stores the vtable
 * (address point 0x16a50a0, complete destructor FUN_001625d0). Members read so
 * far: world at +0x20, wheelCollide (a pointer to hknpVehicleWheelCollide)
 * at +0x68, wheelsInfo (array of hknpVehicleInstance::WheelInfo)
 * at +0x80, torque and rpm (hkReal) at +0xf8 and +0xfc, mainSteeringAngle
 * at +0x100. */
/* hknpVehicleWheelCollide (hkClass 0x57c1510, built at 0x5b2a1, 0x18 bytes,
 * parent hkReferencedObject, member records at 0x16992b0; vtable 0x169af50,
 * no type info, slots 5 to 9 pure): alreadyUsed (hkBool) at +0xc, type (the
 * enum WheelCollideType in a hkUint8, record 0x16993b0) at +0xd and
 * wheelCollisionFilterInfo (hkUint32) at +0x10, the last two not serialized
 * (record flags 0x400). hknpVehicleRayCastWheelCollide and
 * hknpVehicleLinearCastWheelCollide derive from it; their finish callbacks
 * (0x75f60 and 0x70750) hold its finish constructor and theirs, which set
 * the type when finishing. */
class hknpVehicleWheelCollide : public hkReferencedObject
{
  public:
    enum WheelCollideType {
        INVALID_WHEEL_COLLIDE = 0,
        RAY_CAST_WHEEL_COLLIDE = 1,
        LINEAR_CAST_WHEEL_COLLIDE = 2,
        USER_WHEEL_COLLIDE1 = 3,
        USER_WHEEL_COLLIDE2 = 4,
        USER_WHEEL_COLLIDE3 = 5,
        USER_WHEEL_COLLIDE4 = 6,
        USER_WHEEL_COLLIDE5 = 7
    };

    /* The type is not serialized: a finished object has none until the
     * derived class's finish constructor names its own. */
    hknpVehicleWheelCollide(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag)
    {
        if (flag.finishing) {
            type = INVALID_WHEEL_COLLIDE;
        }
    }

    virtual void unknownVirtual5();
    virtual void unknownVirtual6();
    virtual void unknownVirtual7();
    /* Slot 8: empty in both wheel collides (0x175a80, 0xadd50); the vehicle's
     * slot 8 hands it the pointer at +0x10 of its own argument. */
    virtual void unknownVirtual8(void *argument);
    virtual void unknownVirtual9();

    hkBool alreadyUsed;
    hkEnum<WheelCollideType, u8> type;
    u32 wheelCollisionFilterInfo;
};

/* hknpVehicleRayCastWheelCollide (type info at 0x7604a, vtable 0x16a4aa0)
 * and hknpVehicleLinearCastWheelCollide (0x38 bytes, type info at 0x708de,
 * vtable 0x16a5bd0): their members are not typed yet. */
class hknpVehicleRayCastWheelCollide : public hknpVehicleWheelCollide
{
  public:
    hknpVehicleRayCastWheelCollide(hkFinishLoadedObjectFlag flag) : hknpVehicleWheelCollide(flag)
    {
        if (flag.finishing) {
            type = RAY_CAST_WHEEL_COLLIDE;
        }
    }

    virtual ~hknpVehicleRayCastWheelCollide();
};

class hknpVehicleLinearCastWheelCollide : public hknpVehicleWheelCollide
{
  public:
    hknpVehicleLinearCastWheelCollide(hkFinishLoadedObjectFlag flag) : hknpVehicleWheelCollide(flag)
    {
        if (flag.finishing) {
            type = LINEAR_CAST_WHEEL_COLLIDE;
        }
    }

    virtual ~hknpVehicleLinearCastWheelCollide();
};

/* A body's id (derived name): a 32-bit handle passed by value, 0x7fffffff
 * when it names no body. */
struct hknpBodyId {
    u32 value; /* derived name */
};

/* The argument of hknpVehicleInstance's slot 8 (derived name): a pointer at
 * +0x10, which the vehicle hands to its wheel collide's slot 8. */
struct hknpVehicleInstanceSlot8Argument /* derived name */
{
    u8 unknown0[0x10];
    void *unknown10;
};

/* hknpAction (hkClass 0x57bfad0, built at 0x3adf5: size 0x18, parent
 * hkReferencedObject's 0x57b8640, one member record at 0x16956e0): userData
 * (hkUlong) at +0x10. */
class hknpAction : public hkReferencedObject
{
  public:
    hknpAction(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    hkUlong userData;
};

/* hknpUnaryAction (hkClass 0x57bfbc0, built at 0x3af2a: size 0x20, parent
 * hknpAction's), one member, bodyId at +0x18 (record 0x1695790): the
 * vehicle's slot 5 (FUN_00162540) hands out its address and a count of 1,
 * slot 6 (FUN_00162550) forgets it when that body is removed. */
class hknpUnaryAction : public hknpAction
{
  public:
    hknpUnaryAction(hkFinishLoadedObjectFlag flag) : hknpAction(flag) {}

    hknpBodyId bodyId;
};

/* Its own members from +0x20 (records from 0x1698a70): world (a pointer, not
 * serialized: record flags 0x400), which the finish constructor clears (the
 * finish callback 0x47990), then data, driverInput, steering, engine,
 * transmission, brake, suspension, aerodynamics, wheelCollide, tyreMarks
 * and velocityDamper (pointers) from +0x28 to +0x78. */
class hknpVehicleInstance : public hknpUnaryAction
{
  public:
    hknpVehicleInstance(hkFinishLoadedObjectFlag flag) : hknpUnaryAction(flag), world(0) {}

    virtual ~hknpVehicleInstance();

    void FUN_00162540(hknpBodyId *&bodiesOut, int &numBodiesOut); /* vtable slot 5; derived name */
    void FUN_00162550(hknpBodyId removedId);                      /* vtable slot 6; derived name */
    void FUN_00165990(
        const hknpVehicleInstanceSlot8Argument *argument); /* vtable slot 8; derived name */
    void FUN_001659b0();                                   /* vtable slot 9; derived name */
    float FUN_00165880() const;                            /* vtable slot 13; derived name */

    void *world;
    u8 unknown28[0x40];
    hknpVehicleWheelCollide *wheelCollide;
    u8 unknown70[0x84];
    hkBool tryingToReverse; /* record 0x1698d18 */
    u8 unknownF5[3];
    float torque; /* record at 0x1698a70's nineteenth */
    float rpm;
    u8 unknown100
        [0x18]; /* mainSteeringAngle, mainSteeringAngleAssumingNoReduction, wheelsSteeringAngle */
    hkBool isReversing; /* record 0x1698e08 */
};

/* hknpCharacterProxy (derived name: its timers "findSupportingContacts",
 * "getGround" and "checkSupport", beside hknpCharacterProxyCinfo's type
 * info), a reference-counted object (vtable address point 0x16a5b80, built
 * by the constructor 0x176420, complete destructor 0x176b70). The
 * constructor subscribes FUN_00176b10 to a signal (the member slot of
 * vtable 0x16a5b50 holding the object, the function and a zero adjustment),
 * and the function forwards the signal's two arguments to slot 5
 * (0x176cc0); slot 6 (0x1781b0) opens "checkSupport", slot 7 (0x177660)
 * "findSupportingContacts". */
struct hknpCharacterProxySignalSource; /* derived name: the signal's first argument */
struct hknpCharacterProxySignalData;   /* derived name: the second, a pointer at +0x28 */

/* The reference-counted object at +0x20 of the proxy (derived name): set
 * with a reference by 0x177130, released by the destructor 0x176b70, and
 * told through its slot 7 of each of the world's post-solve signals. */
class hknpCharacterProxy;

class hknpCharacterProxyListener : public hkReferencedObject /* derived name */
{
  public:
    virtual void unknownVirtual5();
    virtual void unknownVirtual6();
    virtual void unknownVirtual7(hknpCharacterProxy *proxy);
};

struct hknpCharacterProxyContact /* derived name */
{
    u8 unknown0[0x30];
};

class hknpCharacterProxy : public hkReferencedObject /* derived name */
{
  public:
    virtual void FUN_00176cc0(hknpCharacterProxySignalSource *source,
                              hknpCharacterProxySignalData *data); /* vtable slot 5; derived name */

    void FUN_00176b10(hknpCharacterProxySignalSource *source,
                      hknpCharacterProxySignalData *data); /* derived name */

    /* The handler of the world's post-solve signal (the list at +0x608 of
     * the world, fired with the world at 0x512d8, "TtPostSolveSignal"),
     * which the constructor subscribes at 0x176858. derived name. */
    void FUN_00177640(hknpWorld *world);

    /* The handler of the world's signal at +0x5f0, which the constructor
     * subscribes at 0x17677b: drops the contacts when the proxy's body has
     * flag 8 set. derived name. */
    void FUN_001782f0(hknpWorld *world);

    /* The proxy's body (the constructor stores the id the world's body
     * creation 0x4e270 returns, 0x176675). */
    int bodyId; /* derived name */
    u8 unknown10[8];
    hknpWorld *world;                     /* copied from the cinfo's +0x18; derived name */
    hknpCharacterProxyListener *listener; /* derived name */
    u8 unknown28[0x40];
    /* 48-byte records the signal handler 0x176cc0 appends (growing through
     * 0xb40 with the size 0x30). */
    hkArray<hknpCharacterProxyContact> contacts; /* derived name */
};

/* The physics world's query collector (derived name): a polymorphic class
 * whose +0x10 (16 bytes) each collector copies from the one it forwards to
 * after adding a hit (the early-out value of the query). Two collectors
 * built on the stack by the world's queries (0x524d5 to 0x52a24) wrap
 * another: vtables 0x1698fd0 (the wrapped collector at +0x20) and 0x1699020
 * (at +0x30, a direction at +0x20). Their slot 4 (0x48420, 0x48570) adds a
 * hit to the wrapped collector with its normal negated and its position
 * moved along the normal (by the hit's distance) or along the direction (by
 * its fraction), so they report the hits of the shape pair flipped
 * (derived names below from that); slot 3 (FUN_00048410, FUN_00048560) and
 * slot 6 (0x48510, 0x48660) forward to the wrapped collector's. */
class hknpCollisionQueryCollector /* derived name */
{
  public:
    /* Inline and empty: the collectors' deleting destructors call no base
     * destructor. */
    virtual ~hknpCollisionQueryCollector() {}

    /* The class allocator's delete, inline (defined in tlg_lib_unknown.h
     * beside the router it frees through): the collectors' deleting
     * destructors (0x483d0, 0x48520, 0x70970) give the object back to the
     * calling thread's heap at its size. */
    static void operator delete(void *object, unsigned long numBytes);

    virtual void unknownVirtual2();
    /* Slot 3 empties the collector (the all-hits collector's 0x70a10: no
     * hints, the early-out value back to the largest, no hits). derived
     * name. */
    virtual void reset();
    virtual void unknownVirtual4();
    virtual void unknownVirtual5();
    virtual bool unknownVirtual6() const;

    int hints; /* derived name */
    u8 unknownC[4];
    Vec4 earlyOut; /* derived name */
};

/* A query result as the collectors keep them (derived name): 0x60 bytes. */
struct hknpCollisionResult /* derived name */
{
    u8 unknown0[0x60];
};

/* A collector that keeps every hit (derived name; vtable 0x169b100,
 * address point 0x169b110, no type info): the hits in an array at +0x20.
 * Slot 3 (FUN_00070a10) empties it; its destructors 0x70900 and 0x70970
 * empty it and free the array. */
class hknpAllHitsCollector : public hknpCollisionQueryCollector /* derived name */
{
  public:
    void reset(); /* vtable slot 3, FUN_00070a10 */

    hkArray<hknpCollisionResult> hits; /* derived name */
};

class hknpFlippedGetClosestPointsQueryCollector
    : public hknpCollisionQueryCollector /* derived name */
{
  public:
    /* Empty (the shared 0x3b640); the deleting destructor is 0x483d0. */
    virtual ~hknpFlippedGetClosestPointsQueryCollector();

    void FUN_00048410();       /* vtable slot 3; derived name */
    bool FUN_00048510() const; /* vtable slot 6; derived name */

    hknpCollisionQueryCollector *childCollector; /* derived name */
};

/* A collector that wraps another at +0x48 (derived name), built on the
 * stack at 0xd7324 and 0xd746c (vtable 0x16a3c50) and at 0xf0590 (vtable
 * 0x16a3d00, the same bodies): its slot 4 (0xcf8d0) scales a hit's position
 * by +0x20 and its normal by +0x30, transforms them by the transform at
 * +0x40 (the normal renormalised) and adds the hit to the wrapped
 * collector; slot 3 (FUN_000cf8c0) and slot 6 (0xcfa10) forward to the
 * wrapped collector's. */
class hknpScaledQueryCollector : public hknpCollisionQueryCollector /* derived name */
{
  public:
    /* Empty; the deleting destructor is 0xcf880 (in both vtables). */
    virtual ~hknpScaledQueryCollector();

    void FUN_000cf8c0();       /* vtable slot 3; derived name */
    bool FUN_000cfa10() const; /* vtable slot 6; derived name */

    Vec4 positionScale;                          /* derived name */
    Vec4 normalScale;                            /* derived name */
    const Mat4 *transform;                       /* derived name */
    hknpCollisionQueryCollector *childCollector; /* derived name */
};

/* The same with an offset (derived name), built at 0x16b00e: vtable 0x16a55c0,
 * the wrapped collector at +0x58. Its slot 4 (0x16d090) scales a hit's
 * position by +0x30 and offsets it by +0x20, scales the normal by +0x40,
 * transforms both by the transform at +0x50 and adds the hit to the
 * wrapped collector; slot 3 (FUN_0016d080) and slot 6 (0x16d1d0) forward
 * to the wrapped collector's. */
class hknpScaledOffsetQueryCollector : public hknpCollisionQueryCollector /* derived name */
{
  public:
    /* Empty; the deleting destructor is 0x16d040. */
    virtual ~hknpScaledOffsetQueryCollector();

    void FUN_0016d080();       /* vtable slot 3; derived name */
    bool FUN_0016d1d0() const; /* vtable slot 6; derived name */

    Vec4 positionOffset;                         /* derived name */
    Vec4 positionScale;                          /* derived name */
    Vec4 normalScale;                            /* derived name */
    const Mat4 *transform;                       /* derived name */
    hknpCollisionQueryCollector *childCollector; /* derived name */
};

class hknpFlippedShapeCastQueryCollector : public hknpCollisionQueryCollector /* derived name */
{
  public:
    /* Empty (the shared 0x3b640); the deleting destructor is 0x48520. */
    virtual ~hknpFlippedShapeCastQueryCollector();

    void FUN_00048560();       /* vtable slot 3; derived name */
    bool FUN_00048660() const; /* vtable slot 6; derived name */

    Vec4 castDirection;                          /* derived name */
    hknpCollisionQueryCollector *childCollector; /* derived name */
};

/* A processor of a query's items (derived name; vtable 0x16a3d90, address
 * point 0x16a3da0), 0xf0 bytes, built on the stack by FUN_0010dbc0
 * (0x10dc18): slot 2 (0x10b090) takes a pointer to the items and their
 * count. Its destructor is the shared empty 0xadd50 and its deleting
 * destructor 0x10b050, which the processor of vtable 0x16a3dc0 (built by
 * FUN_0010bf50, slot 2 0x10b810) cites by address. */
class QueryProcessor0010b090 /* derived name */
{
  public:
    virtual ~QueryProcessor0010b090();

    /* The class allocator's delete (defined in tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    u8 unknown8[8];
    Vec4 unknown10[14];
};

/* A collector that keeps the closest hit (derived name), 0x90 bytes, vtable
 * address point 0x169a700, built at 0x1569c8, 0x158c45, 0x158cb5 and
 * 0x179268: slot 3 (0x69640) resets it, slot 4 (0x696e0) keeps a hit whose
 * distance (+0x20 of the 0x60-byte hit) is below the kept one's (+0x40),
 * the hit kept at +0x20 and the flag at +0x80 telling one was kept;
 * slot 6 (FUN_000696d0) reads the flag. */
class hknpClosestHitCollector : public hknpCollisionQueryCollector /* derived name */
{
  public:
    /* Empty; the deleting destructor is 0x69600. */
    virtual ~hknpClosestHitCollector();

    bool FUN_000696d0() const; /* vtable slot 6; derived name */

    u8 hit[0x60];  /* derived name */
    hkBool hasHit; /* derived name */
};

/* hkpParametricCurve (hkClass 0x57c3c68, 0x10 bytes, parent
 * hkReferencedObject, no members of its own). */
class hkpParametricCurve : public hkReferencedObject
{
  public:
    hkpParametricCurve(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* hkpLinearParametricCurve (hkClass 0x57c3268, 0x50 bytes, parent
 * hkpParametricCurve; finish callback FUN_00078b00;
 * type info 0x57c32b8; finish constructor 0x78b00 stores its vtable
 * 0x169d890, address point 0x169d8a0): members from its record table at
 * 0x169ba00: smoothingFactor (float) at +0xc, closedLoop (hkBool) at
 * +0x10, dirNotParallelToTangentAlongWholePath (hkVector4) at +0x20,
 * points (array of hkVector4) at +0x30, distance (array of float) at +0x40.
 * Slot 9 (FUN_0007fad0) returns the curve's last parameter, the point count
 * less one. */
class hkpLinearParametricCurve : public hkpParametricCurve
{
  public:
    hkpLinearParametricCurve(hkFinishLoadedObjectFlag flag)
        : hkpParametricCurve(flag), points(flag), distance(flag)
    {
    }

    float FUN_0007fad0() const; /* vtable slot 9; derived name */

    float smoothingFactor;
    hkBool closedLoop;
    u8 unknown11[0xf];
    Vec4 dirNotParallelToTangentAlongWholePath;
    hkArray<Vec4> points;
    hkArray<float> distance;
};

/* A block stream's writer (derived name), 0x28 bytes: the stream it writes
 * (null until bound; 0x938a0 binds it and loads the stream's first block as
 * the current one), the current block, the byte offset in it, the number of
 * elements written to it, and the allocator the blocks come from. Its
 * finalize 0x93a10 writes the current block's header (or frees an empty
 * one) and clears the current block; every stack writer in the region is
 * finalized before it goes out of scope (0x3fa03, 0x64777, 0x6d20b), and
 * the command writers held at +0x390 of their owner are finalized through
 * their member at +0x10 (0x170078, 0x170507). */
struct hkBlockStream; /* derived name */

struct hkBlockStreamWriter /* derived name */
{
    /* An unbound writer. */
    hkBlockStreamWriter() : blockStream(0) {}

    /* Binds the writer to a stream at its first block (0x938a0). derived
     * name. */
    void FUN_000938a0(void *blockAllocator, hkBlockStream *stream);

    /* Binds the writer to a stream to append to its last block (0x938c0):
     * the block's used bytes and elements become the writer's, and its
     * elements leave the stream's count until the writer closes the block
     * again. derived name. */
    void FUN_000938c0(void *blockAllocator, hkBlockStream *stream);

    hkBlockStream *blockStream; /* derived name */
    void *currentBlock;         /* derived name */
    int currentByteOffset;      /* derived name */
    int currentNumElements;     /* derived name */
    void *allocator;            /* derived name */
};

/* A command stream writer (vtable 0x16a3370, ruled hkBlockStreamCommandWriter,
 * D14), 0x38 bytes: constructor 0x904c0 (called at 0x167f1b on a 0x38-byte
 * block, stores 0xffff0001 at +8 and clears the writer's stream), deleting
 * destructor 0x90460 (frees the size kept in the high half of +8). Slot 5
 * (0x904f0) appends a record whose padded byte size is the u16 at its start
 * to the writer (0x939c0 opens a new 0xfe0-byte block); 0x938a0 binds the
 * writer at 0x167f35. */
class hkBlockStreamCommandWriter : public hkReferencedObject /* derived name */
{
  public:
    hkBlockStreamCommandWriter();
    virtual ~hkBlockStreamCommandWriter();

    hkBlockStreamWriter writer; /* derived name */
};

/* The allocator of the block streams' blocks (derived names): reference
 * counted (the world takes a reference to its cinfo's
 * persistentStreamAllocator, +0x30, and keeps it at +0x1c0, 0x48dce), slot 5
 * hands out a batch of blocks and slot 6 takes a batch back (the cache
 * below). */
class BlockStreamAllocator : public hkReferencedObject /* derived name */
{
  public:
    virtual void blockAllocBatch(void **blocksOut, int numBlocks) = 0; /* slot 5; derived name */
    virtual void blockFreeBatch(void **blocks, int numBlocks) = 0;     /* slot 6; derived name */
};

/* A thread's cache of free blocks (derived names): the allocator it
 * returns them to at +0, up to eight blocks from +8, their count at +0x48.
 * FUN_0008eec0 takes one, refilling six when empty; FUN_0008ef10 takes a
 * block back, handing six to the allocator when the cache fills;
 * FUN_0008ef60 hands every cached block back (the world's step does, at
 * 0x49cb9, after each stream it builds with a cache on its stack). */
class AllocatorBase; /* tlg_lib_unknown.h */

struct BlockCache /* derived name */
{
    void FUN_0008ef10(void *block); /* derived name */
    void FUN_0008ef60();            /* derived name */

    BlockStreamAllocator *allocator; /* derived name */
    void *blocks[8];                 /* derived name */
    int numBlocks;                   /* derived name */
};

/* A block stream (derived names): the count of every element written at +8
 * (a writer's block is added to it when the block is closed, 0x939f0), a
 * flag at +0x18 that some of its blocks were freed while it was read, and
 * the blocks from +0x20 (0x947f0 appends one). A reader done with a block
 * (0x93ba3, 0x93be6) has FUN_00094df0 free it. */
/* A block of a block stream (derived names): the 32-bit word at +0 holds
 * its element count in the low half and its used bytes in the high half
 * (the writer's finalize 0x93a10 writes both at once, the append 0x938c0
 * reads each half, consumers subtract from it atomically), its index in the
 * stream at +4, the data from +0x20. */
struct hkBlockStreamBlock /* derived name */
{
    /* The block's first eight bytes, which a consumer done with the block
     * reads at once (0x93bd3 and 0x93b8a load them in one 64-bit read). */
    struct Header {
        u32 numElementsAndBytesUsed; /* derived name */
        int blockIndexInStream;      /* derived name */
    };

    Header getHeader() const
    {
        return header;
    }

    Header header; /* derived name */
    u8 unknown8[0x18];
    u8 data[0xfe0]; /* derived name */
};

struct hkBlockStream /* derived name */
{
    void FUN_00094df0(BlockCache *cache, void *block, int index); /* derived name */

    u8 unknown0[8];
    int numTotalElements; /* derived name */
    u8 unknownC[0xc];
    hkBool partiallyFreed; /* derived name */
    u8 unknown19[7];
    hkArray<hkBlockStreamBlock *> blocks; /* derived name */
};

/* What a consumer keeps of the block it reads (derived names): the stream,
 * the cache freed blocks go to, the block and the number of its elements
 * consumed. FUN_00093bc0 gives the block back to the stream's cache when
 * every element was consumed, and otherwise takes the consumed ones off its
 * count (atomically: other consumers may share the block). */
struct hkBlockStreamConsumedBlock /* derived name */
{
    void FUN_00093bc0(); /* derived name */

    hkBlockStream *stream; /* derived name */
    u8 unknown8[8];
    BlockCache *cache;         /* derived name */
    hkBlockStreamBlock *block; /* derived name */
    int numElementsConsumed;   /* derived name */
};

/* A stretch of a block stream (derived names): the block it starts in, the
 * byte offset of its first element in that block's data and how many of its
 * elements are in that block, and its element count. The reader starts at
 * one with FUN_000937f0 (seventeen callers). */
struct hkBlockStreamRange /* derived name */
{
    const hkBlockStreamBlock *startBlock; /* derived name */
    u16 startByteOffset;                  /* derived name */
    u16 startBlockNumElements;            /* derived name */
    int numElements;                      /* derived name */
};

/* A block stream's reader (derived names), 0x18 bytes: the current block,
 * the next element's address in it (null when the block is empty), the
 * elements left in the other blocks and in this one. */
struct hkBlockStreamReader /* derived name */
{
    /* At the stream's first block, every later element still to read
     * (0x937c0). derived name. */
    void FUN_000937c0(const hkBlockStream *stream);
    /* At the start of a range (0x937f0). derived name. */
    void FUN_000937f0(const hkBlockStreamRange *range);

    const hkBlockStreamBlock *currentBlock; /* derived name */
    const u8 *currentByteLocation;          /* derived name */
    int numElementsToReadInOtherBlocks;     /* derived name */
    int numElementsToReadInThisBlock;       /* derived name */
};

/* A reader that frees what it has read (derived names): the stream at
 * +0x18, the elements of the current block still to free at +0x20, the
 * cache freed blocks go to at +0x28. Starting at a stream (0x93a70, called
 * twice at 0x6cf21 and 0x6cf3e) marks the stream partly freed, then reads
 * from its start (the reader's FUN_000937c0, inline in its file). */
struct hkBlockStreamConsumer : public hkBlockStreamReader /* derived name */
{
    void FUN_00093a70(BlockCache *cache, hkBlockStream *stream); /* derived name */

    hkBlockStream *stream;            /* derived name */
    int numElementsToFreeInThisBlock; /* derived name */
    BlockCache *cache;                /* derived name */
};

/* A command of a command stream (derived names): its padded byte size at +0
 * (hkBlockStreamCommandWriter's slot 5 copies that many bytes), its primary
 * type at +3, the index of the dispatcher that executes it. */
struct hkCommand /* derived name */
{
    u16 sizePaddedTo16; /* derived name */
    u8 unknown2;
    u8 primaryType;    /* derived name */
    u16 secondaryType; /* the kind within the primary type (0x8ec53); derived name */
};

/* A reference-counted executor of one primary type of command (derived
 * name): slot 5 executes a command. */
class hkSecondaryCommandDispatcher : public hkReferencedObject /* derived name */
{
  public:
    virtual void exec(const hkCommand &command) = 0; /* vtable slot 5; derived name */
};

/* The executors by primary type (derived name), eight references (the
 * constructor 0x90570 clears them; the simulation builds one on the stack
 * at 0x17008b and runs each command of a stream through it, 0x170396). */
class hkPrimaryCommandDispatcher /* derived name */
{
  public:
    void FUN_00090830(const hkCommand &command); /* derived name */

    hkSecondaryCommandDispatcher *dispatchers[8]; /* derived name */
};

/* hkDebugDisplay, the singleton registered by that name (record filled by
 * 0x183cd0, its instance pointer at 0x57c88c0, created by 0x183c40).
 * FUN_001839d0 draws a line: start, end, colour, an id and a tag. derived
 * names but the class's. */
class hkDebugDisplay : public hkReferencedObject
{
  public:
    void FUN_001839d0(const hkVector4 &start, const hkVector4 &end, int color, int id,
                      int tag); /* derived name */
};

extern hkDebugDisplay *D_57c88c0;

/* The tag the debug commands draw under (derived name): an int nothing in
 * the library writes, read at 0x8ec5b. */
extern int D_57c8720;

/* hkDebugLineCommand (the name its printer writes, "hkDebugLineCommand
 * Start=", 0x14c3cc5): a command of secondary type 0, its colour at +8, the
 * line's ends at +0x10 and +0x20. */
struct hkDebugLineCommand : public hkCommand {
    u8 unknown6[2];
    int color; /* derived name */
    u8 unknownC[4];
    hkVector4 start; /* derived name */
    hkVector4 end;   /* derived name */
};

/* The executor of the debug commands (derived name; vtable 0x16a31d0,
 * address point 0x16a31e0, no type info): slot 5 (0x8ec50) draws a line
 * command through hkDebugDisplay, slot 6 (0x8ec90) prints it. */
class hkDebugCommandProcessor : public hkSecondaryCommandDispatcher /* derived name */
{
  public:
    virtual void exec(const hkCommand &command);
};

/* A map from strings to pointer-sized values (derived name): 24-byte
 * entries (hash, key, value; a hash of -1 marks a free slot) at +0, the
 * count at +8 and the hash mask at +0xc. FUN_00091600 returns the first
 * used slot as an opaque pointer-sized iterator, FUN_00013890 tests that
 * its slot index is within the hash mask, FUN_00091650 steps to the next;
 * FUN_00091900 looks a key up (the hash h * 31 + c over the characters,
 * compared with strcmp) and returns its value or the default. */
struct StringMap /* derived name */
{
    struct IteratorTag;
    typedef IteratorTag *Iterator;

    struct Entry {
        hkUlong hash;    /* derived name */
        const char *key; /* derived name */
        hkUlong value;   /* derived name */
    };

    Entry *entries;
    int numEntries;
    int hashMod;

    void FUN_00091ac0();                         /* derived name */
    Iterator FUN_00091600() const;               /* derived name */
    Iterator FUN_00091650(Iterator it) const;    /* derived name */
    bool FUN_00013890(Iterator it) const;        /* derived name */
    const char *FUN_00091630(Iterator it) const; /* derived name */
    hkUlong FUN_00091640(Iterator it) const;     /* derived name */
    /* Sets the value of a key, adding the entry when it is new (0x91690). */
    void FUN_00091690(const char *key, hkUlong value);                 /* derived name */
    hkUlong FUN_00091900(const char *key, hkUlong defaultValue) const; /* derived name */
};

/* The map's destructor, out of line (0x915e0): the entries go back to the
 * allocator at 0x57b8480 at (hashMod + 1) * 24 bytes. derived name. */
void FUN_000915e0(StringMap *self); /* derived name */

/* A map from pointers to pointer-sized values (derived name): 16-byte
 * entries (key, value; a key of -1 marks a free slot) at +0, the count at +8
 * and the hash mask at +0xc. FUN_00013b30 looks a key up (the hash
 * (key >> 4) * 0x9e3779b1) and returns its value or the default. */
/* The allocator the containers use (derived name): an object, not a
 * pointer, reached by address from 1,621 sites. */
extern AllocatorBase D_57b8480;

/* hkContainerHeapAllocator, the allocator argument of the bit field's
 * hkArray in the scoped type names (0x14b7368): its allocator is
 * D_57b8480 (the bit field's resize 0x47b30 passes it), handed out by
 * reference, so the calls through it are virtual (0x915e0's `jmpq *%rcx`). */
struct hkContainerHeapAllocator {
    static AllocatorBase &get() /* derived name */
    {
        return D_57b8480;
    }
};

struct PointerMap /* derived name */
{
    void *entries;
    int numEntries;
    int hashMod;

    hkUlong FUN_00013b30(hkUlong key, hkUlong defaultValue) const; /* derived name */
    /* Sets the value of a key, growing the entries from the allocator given
     * when the map is more than half full (0x138a0); nonzero when the key
     * was new. */
    int FUN_000138a0(AllocatorBase &allocator, hkUlong key, hkUlong value); /* derived name */
    /* Rebuilds the entries at a new capacity (at least 8) from the
     * allocator given, reinserting every used one (0x13940). */
    void FUN_00013940(AllocatorBase &allocator, int newCapacity); /* derived name */
    /* Makes room for a number of entries without a rebuild: the capacity
     * doubled from 8 until it is twice the number (0x13e30). */
    void FUN_00013e30(AllocatorBase &allocator, int numElements); /* derived name */
    /* Every entry marked empty and the entries given back to the allocator
     * given unless the map does not own them (0x13db0). derived name. */
    void FUN_00013db0(AllocatorBase &allocator); /* derived name */
};

/* The map's own destructor, out of line and empty: the linker folded it
 * onto the shared empty body 0xe5c0 (the vtable class registry's destructor
 * tail-jumps to it, 0x184393). */
void FUN_0000e5c0(PointerMap *self); /* derived name */

/* The reference-counted base (derived name; vtable address point 0x16a6970,
 * constructor FUN_0019be50, destructor body FUN_0019c150; slot 9 pure) of the
 * class whose constructor is FUN_00181b10 (vtable address point 0x16a6480):
 * an array at +0x10 and pointer maps at +0x20, +0x30 and +0x40, a string
 * map from +0x50. Slot 8 (FUN_0019cd00) adds a pair to the map at +0x40. */
struct Object0019c150 /* derived name */
{
    void FUN_0019cd00(const void *key, const void *value); /* vtable slot 8; derived name */

    u8 unknown0[0x40];
    PointerMap map40; /* derived name */
};

/* A named test of a loaded object's class (derived names), registered by its
 * constructor (0x17e940) on the list at 0x57c8868: an id at +0, the name
 * at +8, the test at +0x10, the next record at +0x18. The static
 * initializer at 0x17de70 builds the record 0x57c8848 (id 20,
 * "hasRootLevelContainer", the test 0x17de40, which compares the class's
 * name with "hkRootLevelContainer"); 0x17db39 walks the list and keeps the
 * id of every test that passes. */
struct ClassTest /* derived name */
{
    typedef bool (*Function)(const void *object, const hkClass *klass); /* derived name */

    ClassTest(u16 id, const char *name, Function test);

    u16 id;           /* derived name */
    const char *name; /* derived name */
    Function test;    /* derived name */
    ClassTest *next;  /* derived name */
};

extern ClassTest *D_57c8868; /* the head of the tests' list; derived name */

/* The test "hasRootLevelContainer" registers (derived name). */
bool FUN_0017de40(const void *object, const hkClass *klass); /* derived name */

/* The type registries, each a singleton registered by name on the list at
 * 0x57b80b8 (a record of name, create function, instance address and
 * next): hkTypeInfoRegistry (record 0x57c8940, instance 0x57c8938, created
 * by 0x184e80), hkDefaultClassNameRegistry (record 0x57c8968, instance
 * 0x57c8960, created by 0x184f40), hkVtableClassRegistry (record 0x57c8918,
 * instance 0x57c8910, created by 0x1845b0) and hkBuiltinTypeRegistry
 * (record 0x57c88a0, instance 0x57c8898, created by 0x17ef90). */
/* A type info, the record each reflected class's static initializer fills
 * (docs/DECISIONS.md D12): the type name, the scoped name, the finish and
 * cleanup callbacks a loaded object is run through, the vtable address point
 * and the object size. derived names. */
struct hkTypeInfo {
    typedef void (*FinishLoadedObjectFunction)(void *object, int finishing); /* derived name */
    typedef void (*CleanupLoadedObjectFunction)(void *object);               /* derived name */

    void FUN_00092f90(void *object, int finishing) const; /* derived name */
    void FUN_00092fc0(void *object) const;                /* derived name */

    const char *typeName;                        /* derived name */
    const char *scopedName;                      /* derived name */
    FinishLoadedObjectFunction finishFunction;   /* derived name */
    CleanupLoadedObjectFunction cleanupFunction; /* derived name */
    const void *vtable;                          /* derived name */
    hkUlong size;                                /* derived name */
};

/* hkTypeInfoRegistry, 0x30 bytes, vtable address point 0x16a60c0: the type
 * infos by type name at +0x10 and two ints at +0x28 (1 and 1 on creation;
 * the first is the flag slot 6 passes to the type info's finish). Slot 5
 * (0x17d8b0) registers a type info under its name, slot 6 (0x17d8d0)
 * finishes a loaded object of a named type, slot 8 (0x17d7a0) merges
 * another registry's map, slot 9 (FUN_0017d960) looks a type info up. */
class hkTypeInfoRegistry : public hkReferencedObject
{
  public:
    virtual ~hkTypeInfoRegistry();

    void FUN_0017d8b0(const hkTypeInfo *info); /* vtable slot 5; derived name */
    /* Slot 7: cleans up a loaded object of a named type and returns the
     * type info, or null when no type of that name is registered. */
    const hkTypeInfo *FUN_0017d920(void *object, const char *typeName) const; /* derived name */
    const hkTypeInfo *FUN_0017d960(const char *typeName) const; /* vtable slot 9; derived name */

    StringMap map; /* derived name */
};

/* hkDefaultClassNameRegistry (vtable address point 0x16a6180) over the
 * dynamic class name registry (derived name, vtable address point 0x16a6200,
 * which the constructor 0x184f40 stores first): a name at +0x10 (the string
 * 0x14b3b02) and the classes by name at +0x18. Slot 6 of both vtables
 * (FUN_0017ec90) looks a class up. */
class hkDynamicClassNameRegistry : public hkReferencedObject /* derived name */
{
  public:
    virtual ~hkDynamicClassNameRegistry();

    virtual void unknownVirtual5(); /* the folded 0x7f80: the name at +0x10 */
    virtual const hkClass *
    FUN_0017ec90(const char *className) const; /* vtable slot 6; derived name */
    virtual void unknownVirtual7();            /* 0x17eca0 */
    virtual void unknownVirtual8();            /* FUN_0017ed60: sets the name */
    /* Slot 9 (0x17ed70): registers a class under a name, the class's own
     * when none is given. derived name. */
    virtual void FUN_0017ed70(const hkClass *klass, const char *className);
    /* Slot 10 (0x17edb0): registers each class of a null-terminated list
     * under its own name, through slot 9. derived name. */
    virtual void FUN_0017edb0(const hkClass *const *classes);

    const char *name; /* derived name */
    StringMap map;    /* derived name */
};

class hkDefaultClassNameRegistry : public hkDynamicClassNameRegistry
{
  public:
    virtual ~hkDefaultClassNameRegistry();
};

/* A class name registry over a static list of classes (derived name;
 * vtable 0x16a63b0, address point 0x16a63c0, no type info), 0x28 bytes: a
 * name at +0x10, the null-terminated list at +0x18, its class version at
 * +0x20 and a flag at +0x24 that slots 6 (0x181940) and 7 (0x181860) test
 * for zero before they finish the list's classes through 0x19aff0, setting
 * it after. The static instance 0x57c8870 is built at 0x17f09e over the
 * list 0x16c9060, version -1, name "hk_2014.2.0-r1", before its singleton
 * record "hkBuiltinTypeRegistry" is linked. */
class hkStaticClassNameRegistry : public hkReferencedObject /* derived name */
{
  public:
    hkStaticClassNameRegistry(const hkClass *const *classes, int classVersion, const char *name);

    const char *name;              /* derived name */
    const hkClass *const *classes; /* derived name */
    int classVersion;              /* derived name */
    int ready;                     /* derived name */
};

/* hkVtableClassRegistry, 0x20 bytes, vtable address point 0x16a6580: the
 * classes by vtable at +0x10 (an empty map on creation: no entries, count 0,
 * hash mask -1). Slot 6 (FUN_00184410) looks a vtable's class up. */
class hkVtableClassRegistry : public hkReferencedObject
{
  public:
    /* Slot 0 (0x184360): the map's entries given back to the container
     * allocator, then the map's destructor. */
    virtual ~hkVtableClassRegistry();

    virtual void FUN_00184520(const void *vtable,
                              const hkClass *klass);               /* vtable slot 5; derived name */
    virtual const hkClass *FUN_00184410(const void *vtable) const; /* vtable slot 6; derived name */
    /* Slot 7: the singleton's callers reach it through the vtable
     * (0x902f0's `jmpq *%rax` after the slot load at +0x38). */
    virtual const hkClass *FUN_00184420(const void *object) const; /* vtable slot 7; derived name */

    PointerMap map; /* derived name */
};

extern hkTypeInfoRegistry *D_57c8938;         /* hkTypeInfoRegistry's instance */
extern hkDefaultClassNameRegistry *D_57c8960; /* hkDefaultClassNameRegistry's instance */
extern hkVtableClassRegistry *D_57c8910;      /* hkVtableClassRegistry's instance */

/* hkBuiltinTypeRegistry's instance (vtable address point 0x16a6120, 0x10
 * bytes, created by 0x17ef90 once the three registries above exist): slots
 * 5 to 7 (FUN_0017e970 to FUN_0017e990) return the three registries, slot 8
 * (0x17ef10) adds a type, slot 9 (0x17e9a0) rebuilds the registries. */
class hkBuiltinTypeRegistry : public hkReferencedObject
{
  public:
    virtual ~hkBuiltinTypeRegistry();

    hkTypeInfoRegistry *FUN_0017e970();         /* vtable slot 5; derived name */
    hkDefaultClassNameRegistry *FUN_0017e980(); /* vtable slot 6; derived name */
    hkVtableClassRegistry *FUN_0017e990();      /* vtable slot 7; derived name */
};

/* A shape's watcher (derived names): the owner at +0 (whose bool at +0x20
 * says some watched shape changed), the shape at +8, whose vtable slot 8
 * returns its two signals (at +0 one passing a byte of change flags, at +8
 * one passing the shape as it is destroyed); the change flags gathered at
 * +0x20. FUN_00155b00 is the handler of the first signal, subscribed at
 * 0x156026 through a member function pointer and unsubscribed at 0x155b3f,
 * 0x155c52 and 0x155d53; 0x155b10 handles the second. */
struct ShapeWatcher;

struct ShapeWatcherOwner /* derived name */
{
    /* 0x155bc0 (the world builds one at 0x48ce1): no watchers, nothing
     * changed. */
    ShapeWatcherOwner();

    /* Two lists of watchers, each unsubscribed and freed by 0x155bf0. */
    hkArray<ShapeWatcher *> watchers;      /* derived name */
    hkArray<ShapeWatcher *> otherWatchers; /* derived name */
    bool anyShapeChanged;                  /* derived name */
};

struct ShapeWatcher /* derived name */
{
    void FUN_00155b00(u8 changeFlags); /* derived name */

    ShapeWatcherOwner *owner; /* derived name */
    const hknpShape *shape;   /* derived name */
    u8 unknown10[0x10];
    u8 changeFlags; /* derived name */
};

/* The nodes the XML reader at 0x19da90 returns (derived names: no string
 * names the reader or its nodes): reference-counted objects with the node
 * type at +0xc. The reader allocates an end element (vtable 0x16a6a20, type
 * 2, 0x18 bytes, its name at +0x10, built at 0x19e1eb from the text after
 * "</") and character data (vtable 0x16a6a60, type 3, 0x18 bytes, its text
 * at +0x10, built at 0x19e08c and 0x19e28b); a start element (vtable
 * 0x16a69e0, its name at +0x10 and an array of name and value pairs at
 * +0x18) is the third kind. */
class XmlNode : public hkReferencedObject /* derived name */
{
  public:
    int type; /* derived name */
};

class XmlEndElement : public XmlNode /* derived name */
{
  public:
    virtual ~XmlEndElement();

    hkStringPtr name; /* derived name */
};

class XmlCharacters : public XmlNode /* derived name */
{
  public:
    virtual ~XmlCharacters();

    hkStringPtr text; /* derived name */
};

#endif
