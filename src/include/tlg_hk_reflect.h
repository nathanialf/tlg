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

#include "tlg_libc.h"
#include "tlg_sce_kernel.h"
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

/* A pointer moved by a byte offset through its integer value, as Havok's
 * hkAddByteOffsetConst is (the block reader's advance tests the result for
 * null again, 0x65fa8). */
template <typename T> inline const T *hkAddByteOffsetConst(const T *base, long offset)
{
    return reinterpret_cast<const T *>(reinterpret_cast<hkUlong>(base) + offset);
}

/* The same for a pointer to write through, as Havok's hkAddByteOffset is. */
template <typename T> inline T *hkAddByteOffset(T *base, long offset)
{
    return reinterpret_cast<T *>(reinterpret_cast<hkUlong>(base) + offset);
}

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

/* Havok's large value short of the maximum (its HK_REAL_HIGH,
 * 1.8446726e+19f: the bits 0x5f7ffff0, row 34 of the vector constant
 * table; the motion construction info's limits start at it, 0x1590c9). */
#define HK_REAL_HIGH 1.8446726e+19f

/* Pi as Havok spells it (its HK_REAL_PI; the sphere's slot 17 returns it,
 * 0x3c660). */
#define HK_REAL_PI 3.14159265358979f

/* Havok's smallest float step at one (its HK_REAL_EPSILON, the float
 * epsilon 1.192092896e-07f: the rack and pinion's slot 7 compares with it,
 * 0x83688). */
#define HK_REAL_EPSILON 1.192092896e-07f

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

/* A copy of 4-byte words, counted up (a command copied into its block
 * stream, 0x90540: `dec; jne`, where the quad copy's `while (n--)` gives
 * `neg; inc; jne`). derived name. */
inline void memCpy4(void *dst, const void *src, int numWords) /* derived name */
{
    u32 *d = static_cast<u32 *>(dst);
    const u32 *s = static_cast<const u32 *>(src);
    for (int i = 0; i < numWords; i++) {
        *d = *s;
        s++;
        d++;
    }
}

/* Fills of 4-byte words and 16-byte quads (derived names): the count
 * stepped down to zero, one element stored a step (0x17a360 fills an
 * object either way). */
inline void memSet4(void *dst, const int value, int numWords) /* derived name */
{
    u32 *dst32 = static_cast<u32 *>(dst);
    for (int i = numWords - 1; i >= 0; i--) {
        *dst32 = value;
        dst32++;
    }
}

inline void memSet16(void *dst, const void *value, int numQuads) /* derived name */
{
    const Vec4 *valueQuad = static_cast<const Vec4 *>(value);
    Vec4 *dstQuad = static_cast<Vec4 *>(dst);
    for (int i = numQuads - 1; i >= 0; i--) {
        *dstQuad = *valueQuad;
        dstQuad++;
    }
}

/* numBytes bytes cleared, a zero quad at a time (0x18250). derived name. */
void FUN_00018250(void *dst, int numBytes); /* derived name */

/* 0x17f60 (the name table's lookup FUN_00014e00 calls it): the strings
 * compared without case, -1, 0 or 1. derived name. */
int FUN_00017f60(const char *s1, const char *s2); /* derived name */
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

/* The unsigned forms likewise (pminud, pmaxud: the broad phase's largest
 * bucket index, 0x13e20d). */
inline u32 min2(u32 a, u32 b)
{
    return u32(
        _mm_cvtsi128_si32(_mm_min_epu32(_mm_cvtsi32_si128(int(a)), _mm_cvtsi32_si128(int(b)))));
}

inline u32 max2(u32 a, u32 b)
{
    return u32(
        _mm_cvtsi128_si32(_mm_max_epu32(_mm_cvtsi32_si128(int(a)), _mm_cvtsi32_si128(int(b)))));
}

/* The float forms too, on the scalars set into vectors (vmaxss, vminss):
 * the zero of a max is a vector zero, which no scalar zero of the function
 * is shared with (the transmission's 0x68030 sets it again after its call,
 * where the sum's zero before its loop stays in place). */
inline float min2(float a, float b)
{
    return _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(a), _mm_set_ss(b)));
}

inline float max2(float a, float b)
{
    return _mm_cvtss_f32(_mm_max_ss(_mm_set_ss(a), _mm_set_ss(b)));
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

/* hkHalf (the reflection's TYPE_HALF, its name in the type-name table at
 * 0x14b30dd): a float's top 16 bits. Set from a vector's first lane by
 * truncation, `vpsrad $16; vpackssdw; vmovd` (0x15db42). Field name
 * derived. */
struct hkHalf {
    /* The float whose upper half the value is (0x69461: `movzx; shl 16`).
     * derived name. */
    float getReal() const
    {
        union {
            u32 bits;
            float real;
        } value32;

        value32.bits = u32(u16(value)) << 16;
        return value32.real;
    }

    /* The upper half of the float's bits (0x30e6b: `vmovd; shr 16`).
     * derived name. */
    void setReal(float r)
    {
        union {
            float real;
            u32 bits;
        } value32;

        value32.real = r;
        value = s16(value32.bits >> 16);
    }

    void setReal(__m128 r)
    {
        __m128i bits = _mm_srai_epi32(_mm_castps_si128(r), 16);
        bits = _mm_packs_epi32(bits, bits);
        value = static_cast<s16>(_mm_cvtsi128_si32(bits));
    }

    s16 value;
};

/* The array utilities' element traits (derived names): a type that
 * declares itself plain old data is copied into an array by assignment,
 * any other class by copy construction. A body's record goes in member by
 * member through its id's own assignment (0x63930, 0x63e63), where a
 * skinned mesh part, whose handles have their own assignment too, goes
 * over whole (0xae9a0). */
namespace hkTrait /* derived name */
{
struct TypeIsPod {};

struct TypeIsClass {};

template <typename T> struct IsPodType {
    template <typename U> static char test(typename U::hkIsPodType *);
    template <typename U> static int test(...);

    enum { result = sizeof(test<T>(0)) == sizeof(char) };
};

template <bool POD> struct PodSelect {
    typedef TypeIsClass type;
};

template <> struct PodSelect<true> {
    typedef TypeIsPod type;
};
} // namespace hkTrait

#define HK_DECLARE_POD_TYPE() typedef hkTrait::TypeIsPod hkIsPodType /* derived name */

namespace hkArrayUtil /* derived name */
{
template <typename T> inline void constructWithCopy(T *t, const T &copy, hkTrait::TypeIsPod)
{
    *t = copy;
}

template <typename T> inline void constructWithCopy(T *t, const T &copy, hkTrait::TypeIsClass)
{
    new (t) T(copy);
}

template <typename T> inline void constructWithCopy(T *t, const T &copy)
{
    constructWithCopy(t, copy, typename hkTrait::PodSelect<hkTrait::IsPodType<T>::result>::type());
}

/* An element default-constructed in place: nothing for plain old data, the
 * constructor for a class (an expanded array's new element, 0x17f386). */
template <typename T> inline void construct(T *, hkTrait::TypeIsPod) {}

template <typename T> inline void construct(T *t, hkTrait::TypeIsClass)
{
    new (t) T;
}

template <typename T> inline void construct(T *t)
{
    construct(t, typename hkTrait::PodSelect<hkTrait::IsPodType<T>::result>::type());
}

/* n elements default-constructed in place, as an array that grows by its
 * size constructs the ones it gains (the body manager's entries, 0x160fb0,
 * where the constructor's two stores are one). derived name. */
template <typename T> inline void construct(T *t, int n)
{
    for (int i = 0; i < n; i++) {
        construct(t + i);
    }
}

/* n elements copied by assignment. Its own function: inlined, the loop's
 * source step comes out before the destination's (the curve's points
 * copied out, 0x7fde0), where the loop written in place steps the
 * destination first. derived name. */
template <typename T> inline void copy(T *dst, const T *src, int n)
{
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}
} // namespace hkArrayUtil

/* A body's id (derived name): a 32-bit handle passed by value, 0x7fffffff
 * when it names no body. Its assignment is its own, as the other handles'
 * are (cookbook 85): a record holding one is copied member by member
 * (0x63930), and a pair of them field by field (0x63739). */
struct hknpBodyId {
    hknpBodyId() {}

    explicit hknpBodyId(u32 v) : value(v) {}

    void operator=(const hknpBodyId &other)
    {
        value = other.value;
    }

    u32 value; /* derived name */
};

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

/* A boolean as an int, nonzero for true, as Havok's tests return it
 * (the group filter's 0x3a290 tests the value once, after both paths). */
typedef int hkBool32;

class AllocatorBase; /* tlg_lib_unknown.h */

template <typename T> struct hkArray {
    enum {
        CAPACITY_MASK = 0x3fffffff,            /* derived name */
        DONT_DEALLOCATE_FLAG = int(0x80000000) /* derived name */
    };

    /* An empty array that owns no storage (the constructors' stores). */
    hkArray() : data(0), size(0), capacityAndFlags(DONT_DEALLOCATE_FLAG) {}

    /* A loaded image's array is left as loaded. */
    hkArray(hkFinishLoadedObjectFlag) {}

    /* An array over storage it does not own (hkInplaceArray's). */
    hkArray(T *buffer, int initialSize, int capacity)
        : data(buffer), size(initialSize), capacityAndFlags(capacity | DONT_DEALLOCATE_FLAG)
    {
    }

    /* The storage given back (the vertex storage's destructor 0x9a760).
     * Declared inline: clang 3.3 gives the inliner's hint (threshold 325
     * for 225) only to a function written with the keyword
     * (CodeGenFunction.cpp:497-504), and hknpCompoundShape's destructor
     * (0x41650) holds this one, clearAndDeallocate inside it, within the
     * free-list array's destructor, which fits only with the hint. */
    inline ~hkArray()
    {
        clearAndDeallocate();
    }

    /* The capacity without its flags (the cleanup callbacks of 0x1e200,
     * 0x1e270 and 0x1f5f0 mask it before scaling by an element size that
     * is not a power of two). derived name. */
    int getCapacity() const
    {
        return capacityAndFlags & CAPACITY_MASK;
    }

    /* Drop the elements, keeping the storage: each destroyed from the last
     * (hkMemoryResourceHandle's external links, 0x17f270; nothing for an
     * element with no destructor). */
    void clear()
    {
        destructElements(data, size);
        size = 0;
    }

    /* Elements destroyed in place from the last (Havok's array utilities'
     * destruct, the storage handed in: the loop at 0x17f2a0 reads it once).
     * derived name. */
    static void destructElements(T *elements, int numElements)
    {
        for (int i = numElements - 1; i >= 0; i--) {
            elements[i].~T();
        }
    }

    int getSize() const
    {
        return size;
    }

    /* Room for n more elements at the end, the capacity not checked; the
     * first of them returned. */
    T *expandByUnchecked(int n)
    {
        const int oldSize = size;
        size = oldSize + n;
        return data + oldSize;
    }

    void setSizeUnchecked(int n)
    {
        size = n;
    }

    /* The array set over storage it does not own (the memory texture's
     * slot 6, 0xad6c4). derived name. */
    void setDataUserFree(T *newData, int newSize, int capacity)
    {
        data = newData;
        size = newSize;
        capacityAndFlags = capacity | DONT_DEALLOCATE_FLAG;
    }

    /* An element appended, the capacity not checked: copied to the end,
     * then counted (0x161490 reads the storage before the size). */
    void pushBackUnchecked(const T &element)
    {
        *(data + size) = element;
        size++;
    }

    /* Drop the elements and give the storage back to the containers'
     * allocator unless the array does not own it (defined in
     * tlg_lib_unknown.h, after AllocatorBase). The keyword is on this
     * declaration: a class template's member takes it from the declaration
     * in the class, not from the definition outside (0x41650 inlines it).
     * derived name. */
    inline void clearAndDeallocate();

    /* An element appended, the storage grown through FUN_00000b40 when it
     * is full (defined in tlg_lib_unknown.h, after AllocatorBase). */
    void pushBack(const T &element);

    /* The same, the storage grown from the allocator given (defined in
     * tlg_lib_unknown.h; a local frame's descendants, 0xdd83). */
    void pushBack(AllocatorBase &allocator, const T &element);

    /* The element at an index destroyed and the last one moved into its
     * place as raw words, without its copy constructor (hkMemoryResource
     * Handle's link removal 0x17f3e0: two 8-byte moves). derived name. */
    void removeAt(int index)
    {
        data[index].~T();
        size--;
        if (size != index) {
            u64 *dst = reinterpret_cast<u64 *>(data + index);
            const u64 *src = reinterpret_cast<const u64 *>(data + size);
            for (int i = 0; i < int(sizeof(T) / sizeof(u64)); i++) {
                dst[i] = src[i];
            }
        }
    }

    /* Elements copied onto the end, the storage grown first as setSize
     * grows it (defined in tlg_lib_unknown.h; the skinned mesh's bone list,
     * 0xae780). */
    void append(const T *elements, int numElements);

    /* Room for one more element at the end, grown as pushBack grows: the
     * new element returned (defined in tlg_lib_unknown.h; the solver's
     * arrays at 0x92600). */
    T &expandOne();

    /* The same, the storage grown from the allocator given (defined in
     * tlg_lib_unknown.h; the thread pool's timer streams, 0x77b0). */
    T &expandOne(AllocatorBase &allocator);

    /* Room for n elements at least, from the allocator given (defined in
     * tlg_lib_unknown.h). */
    void reserve(AllocatorBase &allocator, int n);

    /* n elements, the storage grown from the containers' allocator when it
     * is too small and the elements it gains default-constructed, nothing
     * for plain old data or a trivial constructor (defined in
     * tlg_lib_unknown.h). */
    void setSize(int n);

    /* n elements, the storage grown from the allocator given (defined in
     * tlg_lib_unknown.h; the string buffer's, 0x115f0). */
    void setSize(AllocatorBase &allocator, int n);

    /* The same, the elements it gains set to a value (an array stream
     * writer's seek pads with zero, 0x9018e). derived name. */
    void setSize(AllocatorBase &allocator, int n, const T &fill);

    /* Elements copied in at an index, those after it moved up first
     * through the overlapping move (defined in tlg_lib_unknown.h; the XML
     * reader's text and tags, 0x19dc0e). */
    void insertAt(int index, const T *elements, int numElements);

    /* The last element dropped. */
    void popBack()
    {
        size--;
        destructElements(data + size, 1);
    }

    /* The two arrays' storage, sizes and flags exchanged (the XML
     * reader's attributes handed to their node, 0x19e55e). */
    void swap(hkArray &other)
    {
        T *const otherData = other.data;
        other.data = data;
        data = otherData;
        const int otherSize = other.size;
        other.size = size;
        size = otherSize;
        const int otherCapacity = other.capacityAndFlags;
        other.capacityAndFlags = capacityAndFlags;
        capacityAndFlags = otherCapacity;
    }

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

/* An array whose first N elements live in the object on a 16-byte
 * boundary: an int of padding after the array, then the storage (the
 * collide task's array at +0x40 starts its storage at +0x60, the world
 * contexts' at +0x2a0 at +0x2c0). derived
 * name. */
template <typename T, int N> struct hkInplaceArrayAligned16 : public hkArray<T> /* derived name */ {
    hkInplaceArrayAligned16() : hkArray<T>(storage, 0, N) {}

    int padding;
    T storage[N] __attribute__((aligned(16)));
};

/* hkFloat16Transform (hkClass 0x57af6e8, built at 0xd4d: size 0x18, no
 * parent, one member record at 0x168c370): elements, twelve 16-bit floats
 * (the record's struct type, the class at 0x57b9da0). */
/* hkFloat16 (hkClass 0x57b9ba0, built at 0x1c15d: size 2, its one record
 * at 0x168eb40). */
struct hkFloat16 {
    u16 value;
};

struct hkFloat16Transform {
    hkFloat16 elements[12];
};

/* hkSphere (hkClass 0x57af790, built at 0x10ed: size 0x10, no parent, one
 * member record at 0x168c3e0): pos, a vector. */
struct hkSphere {
    Vec4 pos;
};

/* hkTraceStreamTitle (hkClass 0x57b8038, built at 0x94dd: size 0x20, no
 * parent, flags 1, one member record at 0x168d280): value, 32 characters. */
struct hkTraceStreamTitle {
    char value[32];
};

/* hkFourTransposedPointsf (hkClass 0x57b8488, built at 0xc21d: size 0x30,
 * no parent, one member record at 0x168d650): vertices, three vectors. */
struct hkFourTransposedPointsf {
    Vec4 vertices[3];
};

/* hkAabbHalf (hkClass 0x57b9238, built at 0x113fd: size 0x10, no parent,
 * version 1, one member record at 0x168e150): data, eight 16-bit words. */
struct hkAabbHalf {
    u16 data[8];
};

/* hkBitField (type info registered at 0x9e2b, size 0x18): its member
 * storage at +0 (record 0x168d2f0), a hkBitFieldStorage of hkArray<unsigned
 * int> (the scoped type names at 0x14b332f onward) whose words are at +0
 * and numBits at +0x10 (records 0x168d350, 0x168d378). Havok writes it as a
 * template over the storage; the one instance used here is spelled out.
 * FUN_00047b30 resizes it, filling the new bits. */
struct hkBitFieldStorage {
    hkBitFieldStorage() {}

    /* A loaded image's storage is left as loaded. */
    hkBitFieldStorage(hkFinishLoadedObjectFlag flag) : words(flag) {}

    hkArray<u32> words;
    int numBits;
};

struct hkBitField {
    hkBitField() {}

    /* A loaded image's field is left as loaded. */
    hkBitField(hkFinishLoadedObjectFlag flag) : storage(flag) {}

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

    /* Clears one bit (derived name). */
    void clear(int index)
    {
        storage.words.data[index >> 5] &= ~(1 << (index & 31));
    }

    /* Every bit set in another field of the same size set here too (inline
     * in 0x66080): four words at a time through the vector unit, then the
     * words left one by one through two walking pointers. derived name. */
    void orWith(const hkBitField &other)
    {
        const int numQuadWords = storage.words.size & ~3;
        int i = 0;
        if (numQuadWords > 0) {
            const u32 *const otherWords = other.storage.words.data;
            u32 *const words = storage.words.data;
            for (; i < numQuadWords; i += 4) {
                const __m128 bits = _mm_load_ps(reinterpret_cast<const float *>(words + i));
                const __m128 otherBits =
                    _mm_load_ps(reinterpret_cast<const float *>(otherWords + i));
                _mm_store_ps(reinterpret_cast<float *>(words + i), _mm_or_ps(bits, otherBits));
            }
        }
        if (i < storage.words.size) {
            u32 *words = storage.words.data + i;
            const u32 *otherWords = other.storage.words.data + i;
            for (; i < storage.words.size; i++) {
                *words++ |= *otherWords++;
            }
        }
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
struct hkClass;
class hkStreamWriter;

/* hkVariant (the reflection's TYPE_VARIANT): an object and its class.
 * derived field names. */
struct hkVariant {
    void *object;         /* derived name */
    const hkClass *klass; /* derived name */
};

/* hkCustomAttributes: an array of named variants (24 bytes each) and its
 * count. derived field names. */
struct hkCustomAttributes {
    struct Attribute {
        const char *name; /* derived name */
        hkVariant value;  /* derived name */
    };

    /* The value of the attribute of a name, null when none has it (inline
     * in hkClass's 0x4a40; defined after the string library). derived
     * name. */
    const hkVariant *getAttribute(const char *attributeName) const;

    const Attribute *attributes; /* derived name */
    int numAttributes;           /* derived name */
};

struct hkClass {
    /* Out of line (0x41a0, called by every reflection initializer): the
     * fields in order; the implemented interfaces' list is not kept, only
     * their count. */
    hkClass(const char *className, const hkClass *parentClass, int objectSizeInBytes,
            const hkClass **implementedInterfaces, int numImplementedInterfaces,
            const hkClassEnum *declaredEnums, int numDeclaredEnums,
            const hkClassMember *declaredMembers, int numDeclaredMembers, const void *defaults,
            const hkCustomAttributes *attributes, u32 flags, u32 describedVersion);

    /* Whether the class's name is on a list of names (0x4270; FUN_00017f40
     * compares them). derived name. */
    bool FUN_00004270(const NameList00004270 *list) const;

    /* The counts over the class and its parents: implemented interfaces
     * (0x42b0) and members (0x4350). derived names. */
    int FUN_000042b0() const; /* derived name */
    int FUN_00004350() const; /* derived name */
    /* A member by its index over the class and its parents, the parents'
     * first (0x4370; the XML and binary writers' walks over a class's
     * members call it, 0x19ef66, 0x1a0d5a). derived name. */
    const hkClassMember &FUN_00004370(int index) const;
    /* The same member for a class being edited (0x43d0, beside it: the
     * const lookup inline; the caller at 0x180fb6). derived name. */
    hkClassMember &FUN_000043d0(int index);
    /* The class's name, out of line (0x4200). derived name. */
    const char *FUN_00004200() const;
    /* The object's size, out of line (0x4580, one body with the other
     * classes' int getters at +0x10). derived name. */
    int FUN_00004580() const;
    /* The value of the class's attribute of a name, null when it has no
     * attributes or none of the name (0x4a40; hkTypeInfoRegistry's users
     * from 0x17e187 ask it). derived name. */
    const hkVariant *FUN_00004a40(const char *attributeName) const;
    /* The class written to a stream for its signature (0x4660): its name,
     * its members' types and its enums, recursing into the classes its
     * members hold. derived name. */
    void FUN_00004660(hkStreamWriter *writer) const;
    /* The signature: the CRC-32 of the class and its parents written by
     * 0x4660, of the class alone when bit 0 of the flags is set (0x45c0;
     * the packfile writers call it). derived name. */
    u32 FUN_000045c0(int signatureFlags) const;

    const char *name;
    const hkClass *parent;
    int objectSize;
    int numImplementedInterfaces;
    const hkClassEnum *declaredEnums;
    int numDeclaredEnums; /* derived name */
    const hkClassMember *declaredMembers;
    int numDeclaredMembers; /* derived name */
    u8 unknown34[4];
    const void *defaults;                 /* derived name */
    const hkCustomAttributes *attributes; /* derived name */
    u32 flags;                            /* derived name */
    u32 describedVersion;                 /* derived name */
};

/* Whether a class has a vtable, which its root class tells (0x45a0).
 * derived name. */
bool FUN_000045a0(const hkClass *self); /* derived name */

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
    /* Column by column, each read after the one before is written (the
     * fixed constraint's frames, 0x7be40). */
    void operator=(const hkMatrix3 &m)
    {
        col0 = m.col0;
        col1 = m.col1;
        col2 = m.col2;
    }

    /* The identity, rows 29 to 31 of the constant table (hkpRotationalConstraintData's
     * constructor, 0x83473; defined after the table). */
    void setIdentity();

    /* derived name: the rotation of a unit quaternion (0xbd30; the game
     * calls it at 0xeb1134 and four more sites): the columns from the
     * products of the quaternion with its double, the signs flipped by two
     * masks, the diagonal from one. Out of line over the inline below. */
    void FUN_0000bd30(const struct hkQuaternion &q);

    /* The same rotation inline (defined after hkQuaternion), as the world
     * object's slot 12 sets two of them (0x311f0). derived name. */
    void setRotation(const struct hkQuaternion &q);

    /* The rotation made orthonormal again: through the quaternion it
     * holds, normalized, and back (0xbf40; called at 0xb1e14). derived
     * name. */
    void FUN_0000bf40();

    /* The element at a row and a column. */
    float operator()(int row, int column) const
    {
        return reinterpret_cast<const float *>(&col0 + column)[row];
    }

    Vec4 col0; /* derived name */
    Vec4 col1; /* derived name */
    Vec4 col2; /* derived name */

    /* derived name: whether the columns are of unit length and the third
     * the cross product of the first two, within epsilon (0xbde0; the
     * constraint datas' slot 7 asks it of their frames with 1e-5). */
    bool FUN_0000bde0(float epsilon = 1e-5f) const;

    /* derived name: whether this and m differ by at most epsilon in the x,
     * y and z of each column, column by column (0x1ad50; its one caller is
     * 0x3ec40). */
    bool FUN_0001ad50(const hkMatrix3 &m, float epsilon) const;

    /* derived name: the cross-product matrix of r, so that this times v is
     * r cross v (0x1aca0; called at 0xb1c72, 0xb1c89 and 0x1576eb). */
    void FUN_0001aca0(const Vec4 &r);

    /* derived name: this set to the inverse of m, from the cross products
     * of its columns over the determinant; zero and HK_FAILURE when the
     * determinant is within a tolerance of zero (0x1ae40). */
    hkResult FUN_0001ae40(const hkMatrix3 &m);

    /* derived name: this set to a * b (0x1a9f0: each column of b
     * transformed by a). */
    void FUN_0001a9f0(const hkMatrix3 &a, const hkMatrix3 &b);

    /* derived name: this set to a times the transpose of b (0x1abb0; its
     * callers 0x262a2, 0x26507 and 0x6e2a7): every column of both read
     * first, then each result column from the same lane of b's columns. */
    void FUN_0001abb0(const hkMatrix3 &a, const hkMatrix3 &b);

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

/* hkMassProperties (hkClass 0x57bcfa0 built at 0x23c7d: 0x50 bytes, member
 * records at 0x1691b50): volume and mass (hkReal) at +0 and +4,
 * centerOfMass at +0x10, inertiaTensor (hkMatrix3) at +0x20. */
struct hkMassProperties {
    /* The mass set from the volume at a density, the inertia scaled with
     * it (0x2a560; the compound shape's mass build at 0x421da asks it of
     * each child's properties). derived name. */
    void FUN_0002a560(const Vec4 &density);

    /* The mass set, the inertia scaled by the new mass over the old: inline,
     * so its scale is a local of the inlined body and the inliner brackets it
     * with lifetime markers (docs/COOKBOOK.md). */
    void scaleToMass(const Vec4 &newMass) /* derived name */
    {
        const Vec4 scale = _mm_div_ps(newMass, _mm_set1_ps(mass));
        mass = _mm_cvtss_f32(newMass);
        inertiaTensor.FUN_0001ac70(scale);
    }

    float volume;
    float mass;
    Vec4 centerOfMass;
    hkMatrix3 inertiaTensor;
};

extern const hkClassMember D_1691b50[]; /* derived name: hkMassProperties's records */

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
/* Whether a and b differ by at most epsilon in every element of their three
 * columns' x, y and z (0x1add0). derived name. */
bool FUN_0001add0(const hkMatrix3 &a, const hkMatrix3 &b, const Vec4 &epsilon);

struct hkTransform {
    /* derived name: a usable transform, its translation's x, y and z
     * numbers (not NaN) and its rotation orthonormal (0x10ce0; the game
     * checks a body's transform with it, 0xeae90b). */
    bool FUN_00010ce0() const;

    /* derived name: the transform as a matrix, as hkMatrix4's FUN_00010a70
     * builds it (0x10a10; called at 0x115b9 and from the game at
     * 0xeabd43). */
    void FUN_00010a10(struct hkMatrix4 &out) const;

    /* derived name: set to the inverse of a rigid transform (0x10ad0;
     * called at 0x4f52a and from the geometry code at 0xda921). */
    void FUN_00010ad0(const hkTransform &t);

    /* derived name: set to a's inverse times b, a being rigid: b's columns
     * and its translation less a's taken into a's frame (0x10c30; called
     * at 0x74fb2 and 0x159f0b). */
    void FUN_00010c30(const hkTransform &a, const hkTransform &b);

    /* derived name: whether every column of the other transform is within
     * epsilon of this one's in x, y and z (0x10e70; the world's body
     * update asks it at 0x5d711, the game at 0xeaf6b7). */
    hkBool32 FUN_00010e70(const hkTransform &other, const Vec4 &epsilon) const;

    /* derived name: whether the other transform is within epsilon of this
     * one, the rotation by FUN_0001add0 and then the translation, in x, y
     * and z (0x10de0; the game asks it at 0xeaeec5). */
    bool FUN_00010de0(const hkTransform &other, float epsilon) const;

    /* The identity: the rotation's, a zero translation (inline in
     * hkpPointToPlaneConstraintData's constructor, 0x7bb2b). Defined after
     * hkMatrix3's. derived name. */
    inline void setIdentity();

    hkMatrix3 rotation; /* derived name */
    Vec4 translation;   /* derived name */
};

/* derived name: the point v under t, its x, y and z broadcast and scaling
 * the rotation's columns, summed y-first, the translation added (inline in
 * the curve's slot 14, 0x7feb4; FUN_00010f50 is the same body out of
 * line). */
inline Vec4 transformPosition(const hkTransform &t, const Vec4 &v)
{
    const Vec4 x = _mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0));
    const Vec4 y = _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1));
    const Vec4 z = _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2));
    const Vec4 rotated =
        _mm_add_ps(_mm_mul_ps(z, t.rotation.col2),
                   _mm_add_ps(_mm_mul_ps(x, t.rotation.col0), _mm_mul_ps(y, t.rotation.col1)));
    return _mm_add_ps(rotated, t.translation);
}

/* hkMatrix4 (the reflection's type name): four columns of four floats. */
struct hkMatrix4 {
    /* derived name: the matrix of a transform, the rotation's columns with
     * w zero and the translation with w one (row 3 of the constant table)
     * (0x10a70; the game calls it at 0xea114d). */
    void FUN_00010a70(const hkTransform &transform);

    Vec4 col0; /* derived name */
    Vec4 col1; /* derived name */
    Vec4 col2; /* derived name */
    Vec4 col3; /* derived name */
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

    /* The member flags, the reflection's own item names and values (the
     * enum records at 0x168ce88 and 0x16a7108). */
    enum FlagValues {
        ALIGN_8 = 128,
        ALIGN_16 = 256,
        NOT_OWNED = 512,
        SERIALIZE_IGNORED = 1024,
        ALIGN_32 = 2048,
        ALIGN_REAL = 256,
    };

    enum DeprecatedFlagValues {
        DEPRECATED_SIZE_8 = 8,
        DEPRECATED_ENUM_8 = 8,
        DEPRECATED_SIZE_16 = 16,
        DEPRECATED_ENUM_16 = 16,
        DEPRECATED_SIZE_32 = 32,
        DEPRECATED_ENUM_32 = 32,
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

    /* The member's size in bytes (0x7d60): its type's size, an enum's or
     * flags' storage size, or a struct's object size, times its C array
     * size (one when it is not an array); -1 for a type without a size of
     * its own. derived name. */
    int FUN_00007d60() const;

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
    /* The ninth record of hkClassMember's own member table (built at
     * 0x7c13, its name the string at 0x14b2aa0); the records are 0x28
     * bytes. */
    const hkCustomAttributes *attributes;
};

/* derived name: a member record brought up to date (0x19f210, the
 * callback the versioning walk at 0x19ef97 runs on every declared member
 * of a version 4 or older): a TYPE_ZERO member becomes its subtype and is
 * not serialized, an enum's or flags' deprecated size flag becomes its
 * storage subtype. */
void FUN_0019f210(hkClassMember *member);

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

/* hkBaseObject's hkClass, built by the reflection initializer at 0xe270
 * (name "hkBaseObject", size 8, one implemented interface). */
extern const hkClass D_57b86c0; /* hkBaseObject's hkClass */

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

    /* A copy is a new object too: the original's size and count are not
     * copied (the analog status's copy, 0x151d5b). */
    hkReferencedObject(const hkReferencedObject &) : hkBaseObject(), memSizeAndRefCount(0xffff0001)
    {
    }

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

    /* The allocation size recorded in the top 16 bits by compare-and-swap,
     * the reference count kept (`movzx; or SIZE << 16; lock cmpxchg` after
     * the stores of the constructor that calls it: 0x199ef0, 0x3c640,
     * 0x78360). derived name. */
    void setMemSize(u16 numBytes)
    {
        /* volatile: as in addReference. */
        volatile u32 *sizeAndCount = &memSizeAndRefCount;
        u32 oldValue, newValue;
        do {
            oldValue = *sizeAndCount;
            newValue = (u32(numBytes) << 16) | u16(oldValue);
        } while (__sync_val_compare_and_swap(sizeAndCount, oldValue, newValue) != oldValue);
    }

    /* One reference fewer, the same way; the last one deletes the object
     * through slot 4 (the character context's destructor, 0x3e96e).
     * derived name. */
    void removeReference() const
    {
        if ((memSizeAndRefCount & 0xffff0000) != 0) {
            /* volatile: as in addReference. */
            volatile u32 *count = &memSizeAndRefCount;
            u32 oldValue, newValue;
            do {
                oldValue = *count;
                newValue = (oldValue & 0xffff0000) | u16(oldValue - 1);
            } while (__sync_val_compare_and_swap(count, oldValue, newValue) != oldValue);
            if (u16(newValue) == 0) {
                FUN_000069a0();
            }
        }
    }

    /* The same release with the word read once into a named value for the
     * test, which keeps that read its own instruction under the debug
     * information (D30): the platform object writer's release of its copier
     * (0x19ac0c) and 26 other releases of the region (0x68db8 in
     * hknpTyremarksInfo's destructor, 0x19a570 the parsed node's), against
     * the folded test of removeReference. derived name. */
    void releaseReference() const
    {
        const u32 sizeAndCount = memSizeAndRefCount;
        if ((sizeAndCount & 0xffff0000) != 0) {
            /* volatile: as in addReference. */
            volatile u32 *count = &memSizeAndRefCount;
            u32 oldValue, newValue;
            do {
                oldValue = *count;
                newValue = (oldValue & 0xffff0000) | u16(oldValue - 1);
            } while (__sync_val_compare_and_swap(count, oldValue, newValue) != oldValue);
            if (u16(newValue) == 0) {
                FUN_000069a0();
            }
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

    /* One reference fewer on each of numObjects objects, their pointers
     * pointerStriding bytes apart (0x69c0, beside slot 4; hknpLodShape's
     * levels at 0x681c7 and 0x682b6). derived name. */
    static void FUN_000069c0(const hkReferencedObject *const *objects, int numObjects,
                             int pointerStriding);

    /* mutable: a const object still takes references. */
    mutable u32 memSizeAndRefCount;
};

/* A small record inside hkReferencedObjectLock (derived names): at +0x14
 * of the lock its creator 0x6800 stores -15 and the half word 0x8000 at
 * +8, then FUN_00006b90 resets it (-15 and 0) unless the half word is
 * non-negative and the pointer at 0x57b7b90 is set. Nothing in the
 * executable writes that pointer. */
struct Record00006b90 /* derived name */
{
    int value; /* derived name */
    u8 unknown4[4];
    s16 count; /* derived name */
};

extern void *D_57b7b90; /* derived name */

void FUN_00006b90(Record00006b90 *self); /* derived name */

/* Havok's check of a POSIX call that must succeed, as the critical
 * section's calls show it (0x1853 to 0x1942, 0x6706): on a non-zero result
 * the place is printed ("%s:%d:%s\n": the file, the line and the function's
 * name), then the call's own text through perror, then the trap. The file
 * and the line are the library build's __FILE__ and __LINE__, which this
 * tree's paths cannot give, so they are passed as the executable has them. */
#define HK_POSIX_CHECK(file, line, call)                                                           \
    do {                                                                                           \
        if ((call) != 0) {                                                                         \
            printf("%s:%d:%s\n", file, line, __FUNCTION__);                                        \
            perror(#call);                                                                         \
            HK_BREAKPOINT(0);                                                                      \
        }                                                                                          \
    } while (0)

/* Havok's null pointer, as the checks' texts spell it (0x14b40d0). */
#define HK_NULL 0

/* The file the thread's checks name (the string at 0x14b4071). */
#define HK_POSIX_THREAD_CPP                                                                        \
    "Y:\\NightlyJobs\\20141121-01\\Source\\Common\\Base\\Thread\\Thread\\Posix\\hkPosixThread.cpp"

/* The file the critical section's checks name (the string at 0x14b2812). */
#define HK_POSIX_CRITICAL_SECTION_INL                                                              \
    "..\\..\\Common/Base/Thread/CriticalSection/Posix/hkPosixCriticalSection.inl"

/* hkCriticalSection (the name from its checks' function strings), the
 * POSIX build: a recursive mutex and the spin count its constructor
 * (FUN_00001830) keeps at +8. The destructor is inline (line 28 of the
 * file): the mutex destroyed and checked. */
class hkCriticalSection
{
  public:
    /* 0x1830: the mutex made recursive, each step checked (lines 16 to 19
     * of the file), and the spin count kept. */
    hkCriticalSection(int spinCount = 0);

    /* The class allocator: a block of the thread's heap (0x183ca9; defined
     * beside the router). */
    static void *operator new(unsigned long numBytes);
    /* Back to the thread's heap at the class's size (0x183888). */
    static void operator delete(void *object, unsigned long numBytes);

    ~hkCriticalSection()
    {
        HK_POSIX_CHECK(HK_POSIX_CRITICAL_SECTION_INL, 28, pthread_mutex_destroy(&m_mutex));
    }

    pthread_mutex_t m_mutex; /* the name the check's text gives */
    int spinCount;           /* derived name */
};

/* hkRefPtr, a counted reference (the reflection's TYPE_POINTER members a
 * class holds this way): its destructor releases the object and clears the
 * pointer (hknpConstraintCinfo's cleanup 0x369a0, after the name). The
 * target must be a reference-counted class where it is destroyed. */
template <typename T> struct hkRefPtr {
    ~hkRefPtr()
    {
        if (pntr) {
            pntr->removeReference();
        }
        pntr = 0;
    }

    /* A new object held: a reference taken on it before the old one's is
     * released (the modifier manager's filter, 0x667b0). */
    void operator=(T *e)
    {
        if (e) {
            e->addReference();
        }
        if (pntr) {
            pntr->removeReference();
        }
        pntr = e;
    }

    /* Another counted reference's object held the same way, its pointer
     * read again after the release (a skinned mesh's bone section copied
     * out, 0xae6b0, reloads it). */
    void operator=(const hkRefPtr &other)
    {
        if (other.pntr) {
            other.pntr->addReference();
        }
        if (pntr) {
            pntr->removeReference();
        }
        pntr = other.pntr;
    }

    T *operator->() const
    {
        return pntr;
    }

    operator T *() const
    {
        return pntr;
    }

    T *pntr; /* derived name */
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

    /* The reference-counted class delete (tlg_lib_unknown.h): its deleting
     * destructor 0x6740 frees at the recorded size, 0x30 by default. */
    static void operator delete(void *object, unsigned long numBytes);

    int lockMode; /* derived name */
    int unknown10;
    Record00006b90 record14;           /* derived name */
    hkCriticalSection criticalSection; /* derived name */
};

extern hkReferencedObjectLock *D_57b7b50; /* hkReferencedObjectLock's instance */

/* The instance's reference released and the pointer cleared (0x68e0; the
 * base system's quit calls it at 0x9bc0). derived name. */
void FUN_000068e0(); /* derived name */

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

extern hkDummySingleton *D_57b80c8; /* hkDummySingleton's instance */

/* A singleton's registration record (derived names): its name, its create
 * function (null for a singleton made by hand), the list's next record and
 * the address of the instance pointer; each record links itself at the
 * head of the list at 0x57b80b8 as it is built (0x1010 for hkError's,
 * 0x9c50 for hkDummySingleton's: name, create function, instance address,
 * then the link). */
struct SingletonRecord;            /* derived name */
extern SingletonRecord *D_57b80b8; /* the list's head; derived name */

struct SingletonRecord /* derived name */
{
    typedef hkReferencedObject *(*CreateFunction)(); /* derived name */

    SingletonRecord(const char *name_, CreateFunction create_, void **instance_)
        : name(name_), create(create_), instance(instance_)
    {
        next = D_57b80b8;
        D_57b80b8 = this;
    }

    const char *name;      /* derived name */
    CreateFunction create; /* derived name */
    SingletonRecord *next; /* derived name */
    void **instance;       /* derived name */
};

/* hkUuidPseudoRandomGenerator's create function (0xdaf0, the record's at
 * 0x57b8610: a 0x30-byte object from the thread's heap, vtable 0x168d8a0,
 * seeded from the clock). derived name. */
hkReferencedObject *FUN_0000daf0(); /* derived name */

/* A pointer-sized object its constructor clears (derived name): the
 * uuid file's initializer (0xdc50) clears two after its registration, at
 * 0x57b8638 and 0x57b8630, which nothing else in the library reads. */
struct ClearedPointer0000dc50 /* derived name */
{
    ClearedPointer0000dc50() : pointer(0) {}

    void *pointer; /* derived name */
};

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
 * destructor (0xe5d0, frees the string when bit 0 of the pointer marks it
 * owned) are out of line. */
/* The string library's formatted print into a buffer of size bytes, a
 * wrapper over vsnprintf on a copy of the caller's argument list (0x17e20;
 * the error reports at 0x87bd and 0x119d6 pass their own). */
int FUN_00017e20(char *buffer, int size, const char *format, va_list args); /* derived name */
/* The string library's length (derived name; a wrapper over strlen). */
int FUN_00017fe0(const char *s); /* derived name */
/* The string library's copy (derived name; a wrapper over strcpy,
 * 0x17fc0). */
char *FUN_00017fc0(char *destination, const char *source); /* derived name */
/* The string library's comparison (derived name; a wrapper over strcmp,
 * 0x17f40). */
int FUN_00017f40(const char *a, const char *b); /* derived name */

/* The items searched in order (the loop tested at the top, cookbook 60). */
inline const hkVariant *hkCustomAttributes::getAttribute(const char *attributeName) const
{
    int i = -1;
    while (++i < numAttributes) {
        if (FUN_00017f40(attributes[i].name, attributeName) == 0) {
            return &attributes[i].value;
        }
    }
    return 0;
}

/* Whether a string ends with a suffix (0x181c0; derived name): both
 * lengths taken with strlen, then the tail compared. */
hkBool FUN_000181c0(const char *string, const char *suffix); /* derived name */
/* Whether a directory entry's name passes a listing's pattern (0x1a770,
 * called at 0x1bf00 after each sceFiosDHReadSync): never an empty name, "."
 * or "..", every name without a pattern, else the names ending with what
 * follows the pattern's first character. derived name. */
bool FUN_0001a770(const char *name, const char *pattern); /* derived name */

struct hkStringPtr;
void FUN_0000e5c0(hkStringPtr *self, hkFinishLoadedObjectFlag flag); /* derived name */

struct hkStringPtr {
    /* Out of line (0xe3d0): a null string. Called on each new element by
     * the array growers at 0xc93b to 0xcb23, and by 0x3a575, 0x6c66c and
     * 0x17f386; an inline one would be folded into its callers, which the
     * base calls (hkXmlParser's constructor tail-calls it, 0x19d8e0). */
    hkStringPtr();

    /* The finish constructor, as a member initializer runs it (the out-of-line
     * body is FUN_0000e5c0; hknpFirstPersonGun's finish constructor runs it
     * before its next member's). */
    hkStringPtr(hkFinishLoadedObjectFlag flag)
    {
        FUN_0000e5c0(this, flag);
    }

    /* Out of line (0xe3e0): a copy of the string from the thread's heap,
     * owned (bit 0 set), or null. */
    hkStringPtr(const char *string);

    /* Out of line (0xe550): a copy of the other's characters, owned, or
     * null. */
    hkStringPtr(const hkStringPtr &other);

    /* A copy of length characters of a string (FUN_0000e540, defined after
     * it). */
    inline hkStringPtr(const char *string, int length);

    /* Out of line (0xe620): a string other than its own, the old one given
     * back first when owned, then a copy of the new one, owned, or null. */
    hkStringPtr &operator=(const char *string);

    /* Out of line (0xe6c0): the other's string assigned as a C string, the
     * assignment above inline. */
    hkStringPtr &operator=(const hkStringPtr &other);

    /* Out of line (0xe5d0): an owned string (bit 0 of the pointer) goes
     * back to the thread's heap and the pointer is cleared. Members are
     * destroyed after the destructor body of the class holding them, so
     * a class's arrays declared after its name are given back first
     * (hkxMaterialEffect's destructor 0x89b60). */
    ~hkStringPtr();

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

/* A growable character buffer (derived name): 128 characters in place
 * (0x90 bytes; the constructor 0x11690 points the array at +0x10).
 * FUN_000116c0 assigns a C string to it (length, grow through the
 * allocator, copy), FUN_00011900 formats into it. */
struct hkStringBuf /* derived name */
{
    hkStringBuf(const hkStringPtr &source);

    /* Out of line (0x115f0; the image loader's at 0x1885ad and the XML
     * reader's at 0x19e1c1): a copy of a C string, null read as empty. */
    hkStringBuf(const char *s);

    /* The characters' length, without the terminator the array holds. */
    int getLength() const
    {
        return string.size - 1;
    }

    /* Every letter A to Z made lower case, in place (0x11db0; the image
     * loader lowers a file's extension with it at 0x1885b5). derived
     * name. */
    void FUN_00011db0();

    /* Whether the string ends with a suffix, nonzero when it does (0x11870;
     * the image loader asks it of a lowered file name at 0x1885c4).
     * derived name. */
    int FUN_00011870(const char *suffix) const;

    hkInplaceArray<char, 128> string; /* derived name */
};

/* The buffer set to a C string as its constructor sets it, null read as
 * empty; the buffer returned (0x116c0). derived name. */
hkStringBuf &FUN_000116c0(hkStringBuf *self, const char *string); /* derived name */
/* Formatted into the buffer, printf style (0x11900). derived name. */
void FUN_00011900(hkStringBuf *self, const char *format, ...); /* derived name */

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
class StreamReader;

class hkXmlParser : public hkReferencedObject /* derived name */
{
  public:
    /* A node the reads return (derived names): reference counted, its kind
     * at +0xc (1 for an element). The parser deletes the ones handed back
     * through their deleting destructor (the call at 0x19da40). */
    struct Node : public hkReferencedObject {
        /* A new node of a kind: 1 a start element, 2 an end element, 3
         * character data. */
        Node(int kind) : kind(kind) {}

        /* The thread heap's block in place (0x19e07b), as hkHardwareInfo's
         * (defined in tlg_lib_unknown.h). */
        static void *operator new(unsigned long numBytes);

        int kind; /* derived name */
    };

    hkXmlParser();
    /* Out of line (0x19da00, slot 0): the nodes handed back deleted, then
     * the members; the deleting destructor (0x19d920, slot 1) frees through
     * the class's delete. */
    virtual ~hkXmlParser();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    /* Slot 5 (0x19da90): the next node of the stream (a handed-back one
     * first), or a failure with its message in lastError. derived name. */
    virtual hkResult FUN_0019da90(Node **nodeOut, StreamReader *stream);

    /* Slot 6 (0x19e6b0): a node handed back, to be returned again by the
     * next read. derived name. */
    virtual void FUN_0019e6b0(Node *node);

    virtual void unknownVirtual7(); /* vtable slot 7 (0x19e700) */

    hkArray<Node *> pendingNodes; /* derived name */
    hkStringPtr lastError;        /* derived name */
};

/* hkxEnvironment::Variable (type info "hkxEnvironmentVariable" 0x57c8100,
 * hkClass 0x57c80b0, both built by 0x8da60: size 0x10, no vtable; member
 * records at 0x16a2950): name and value, string
 * pointers at +0 and +8. Its finish callback is FUN_0008d9e0, its cleanup
 * callback FUN_0008da10 (hkMemoryResourceHandle::ExternalLink's type info,
 * 0x57c8620, cites the same two). */
struct hkxEnvironmentVariable {
    hkxEnvironmentVariable(hkFinishLoadedObjectFlag flag) : name(flag), value(flag) {}

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

inline hkStringPtr::hkStringPtr(const char *string, int length)
{
    FUN_0000e540(this, string, length);
}

/* The string set from (string, length), forwarded to FUN_0000e450 (0xeab0;
 * the XML reader's attribute names and values, 0x19e3ac). derived name. */
void FUN_0000eab0(hkStringPtr *self, const char *string, int length); /* derived name */

/* The string set from a printf-style format (0xe790; the XML reader's
 * errors, 0x19de52). derived name. */
void FUN_0000e790(hkStringPtr *self, const char *format, ...); /* derived name */

/* The string library's bounded compare (0x17f50, over strncmp). derived
 * name. */
int FUN_00017f50(const char *a, const char *b, unsigned int n); /* derived name */

/* The XML reader's entities decoded from src into dst (0x19d710; the reader
 * passes one buffer as both): the length written, -1 for a bad one.
 * derived name. */
int FUN_0019d710(char *dst, const char *src); /* derived name */

/* Sets the string from (string, length): drops an owned copy, then stores a
 * new one (copied through the arena of the thread's block) or null; the
 * constructor at 0xe540 clears the pointer and tail-calls it. */
void FUN_0000e450(hkStringPtr *self, const char *string, int length); /* derived name */

/* What a load or save reports when it fails (derived names): an error id at
 * +0 (0: none yet) and a message at +8. The deprecated serializer's stubs set
 * id 7 and their message when nothing was reported before. */
struct SerializeErrorDetails /* derived name */
{
    int id;                     /* derived name */
    hkStringPtr defaultMessage; /* derived name */
};

/* hkSerializeDeprecated, the singleton registered by that name (record
 * 0x57c89e8 filled by 0x19a680, instance pointer 0x57c89e0; its create function 0x19a5f0 builds a static
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

/* hkMonitorStreamColorTable::ColorPair, 16 bytes: colorName (hkStringPtr) at
 * +0, then color. */
struct hkMonitorStreamColorTableColorPair {
    hkStringPtr colorName;
    u32 color;
};

/* The polymorphic table of color pairs; its vtable is 0x168c1b0 (its finish
 * callback FUN_000002c0 stores 0x168c1c0), its destructor the first slot:
 * the pairs (16 bytes each, their names destroyed from the last) at +0x10,
 * 0x28 bytes (the deleting destructor's default size). */
class hkMonitorStreamColorTable : public hkReferencedObject
{
  public:
    hkMonitorStreamColorTable(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), colorPairs(flag)
    {
    }

    /* Out of line (0x100, slot 0); the deleting destructor (0x1a0, slot 1)
     * frees through the class's delete. */
    virtual ~hkMonitorStreamColorTable();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    /* The member names from the type's records (0x14b260c on). */
    hkArray<hkMonitorStreamColorTableColorPair> colorPairs;
    u32 defaultColor;
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
struct hkMonitorStreamStringMap {
    hkArray<hkMonitorStreamStringMapStringMap> map;
};

/* The cleanup callback of its type info (0x57af550, set at 0xa1b): the map
 * destroyed in place, each string given back, then the array. derived
 * name. */
void FUN_00000360(void *object); /* derived name */

void FUN_0000d500(hkMonitorStreamStringMap *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* hkUuid, 16 bytes: data, four 32-bit unsigned ints (type 0x08, array of
 * 4). Its finish constructor is out of line and empty (FUN_0000dbc0). */
struct hkUuid;
void FUN_0000dbc0(hkUuid *self, hkFinishLoadedObjectFlag flag); /* derived name */

struct hkUuid {
    hkUuid() = default;

    /* The finish constructor, as a member initializer runs it (hkxNode's,
     * 0x8b4b0, between its name's and its user properties'). */
    hkUuid(hkFinishLoadedObjectFlag flag)
    {
        FUN_0000dbc0(this, flag);
    }

    u32 data[4];
};

/* hkUuidObject, 32 bytes and polymorphic: uuid (an hkUuid) at +0xc. Its
 * finish constructor is out of line (FUN_0000dc40: stores the vtable
 * 0x168d870 and leaves the uuid as loaded); the finish callback 0x3eb0
 * calls it by its address. */
class hkUuidObject : public hkReferencedObject
{
  public:
    hkUuidObject(hkFinishLoadedObjectFlag flag);

    /* Empty (the shared 0xd940); the deleting destructor 0xd990 frees the
     * object through the class allocator (tlg_lib_unknown.h). */
    virtual ~hkUuidObject();

    static void operator delete(void *object, unsigned long numBytes);

    hkUuid uuid;
};

void FUN_0000dc40(hkUuidObject *self, hkFinishLoadedObjectFlag flag); /* derived name */

/* hkRefCountedProperties, 16 bytes: entries, an array (type 0x16) of
 * hkRefCountedProperties::Entry, at +0 (type info at 0x57b85d8, registered
 * by the initializer at 0xd390). Its finish constructor (FUN_0001c1e0,
 * empty) and destructor (0x1c1f0, releases each entry) are out of
 * line. */
struct hkRefCountedProperties {
    /* 16 bytes: the referenced object at +0 (the destructor 0x1c1f0 drops a reference
     * on each) and the key at +8 that FUN_0001c2c0 searches by. */
    struct Entry {
        /* The cleanup callback of its type info (0xd300, registered by
         * 0xd390; the type infos of hkMultipleVertexBuffer::VertexBufferInfo
         * and two others, whose first member is also a counted reference,
         * cite the same body). derived name. */
        static void FUN_0000d300(void *object);

        hkReferencedObject *object; /* derived name */
        u16 key;                    /* derived name */
        u8 unknownA[6];
    };

    /* Out of line at 0x1c1b0: the callers at 0x38551 and 0x44c93
     * allocate the 16 bytes from the thread's allocator and construct. */
    hkRefCountedProperties();

    /* Out of line (0x1c1f0): each entry's reference released, the array
     * given back. */
    ~hkRefCountedProperties();

    /* The class delete: back to the thread's heap at the class's size, no
     * null test (inline in hknpShape's destructor, 0x6fb82; defined in
     * tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    /* The object under a key, the last entry first (0x1c550; the shapes ask
     * for key 0xf100 at 0x384be and 0x157118); null when none has it.
     * derived name. */
    hkReferencedObject *FUN_0001c550(u16 key) const;

    hkArray<Entry> entries;
};

void FUN_0001c1e0(hkRefCountedProperties *self, hkFinishLoadedObjectFlag flag); /* derived name */

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
    hkStringObject(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag), string(flag) {}

    virtual ~hkStringObject();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkStringPtr string;
};

class hkLocalFrameGroup;

/* hkLocalFrame (hkClass 0x57b7698, built at 0x38aa: size 0x10, parent
 * hkReferencedObject's 0x57b8640, no members): a frame of a tree of named
 * frames. Its vtable slots 5 to 16 are the frames' interface; the one
 * implementation the executable holds is hkSimpleLocalFrame's (address
 * point 0x168d8f0), whose bodies are named there. No vtable of this class
 * is in the executable. */
class hkLocalFrame : public hkReferencedObject
{
  public:
    hkLocalFrame(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    virtual void unknownVirtual5();  /* vtable slot 5 */
    virtual void unknownVirtual6();  /* vtable slot 6 */
    virtual void unknownVirtual7();  /* vtable slot 7 */
    virtual void unknownVirtual8();  /* vtable slot 8 */
    virtual void unknownVirtual9();  /* vtable slot 9 */
    virtual void unknownVirtual10(); /* vtable slot 10 */
    virtual void unknownVirtual11(); /* vtable slot 11 */
    /* Slots 12 and 13: the number of child frames and a child by index
     * (hkSimpleLocalFrame's 0xe160 and 0xe170). derived names. */
    virtual int numChildFrames() const;
    virtual hkLocalFrame *childFrame(int index) const;
    virtual void unknownVirtual14(); /* vtable slot 14 */
    virtual void unknownVirtual15(); /* vtable slot 15 */
    /* Slot 16 (0xdd20): every frame below this one appended, each child
     * before its own children. derived name. */
    virtual void FUN_0000dd20(hkArray<hkLocalFrame *> &descendants, AllocatorBase &allocator) const;
};

/* hkLocalFrameGroup (hkClass 0x57b76f0, built at 0x3914: size 0x18, parent
 * hkReferencedObject's 0x57b8640, one member record at 0x168c7a0): name
 * (hkStringPtr) at +0x10. The finish callback 0x37b0 constructs it in
 * place; the complete destructor 0x3710 destroys the name. */
class hkLocalFrameGroup : public hkReferencedObject
{
  public:
    hkLocalFrameGroup(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag), name(flag) {}

    virtual ~hkLocalFrameGroup();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkStringPtr name;
};

class hkSimpleLocalFrame : public hkLocalFrame
{
  public:
    hkSimpleLocalFrame(hkFinishLoadedObjectFlag flag)
        : hkLocalFrame(flag), children(flag), name(flag)
    {
    }

    void FUN_0000df30(Mat4 &out) const;          /* vtable slot 5; derived name */
    void FUN_0000df60(const Mat4 &newTransform); /* vtable slot 6; derived name */
    void FUN_0000df90(Vec4 &position) const;     /* vtable slot 7; derived name */
    const char *FUN_0000dcb0() const;            /* vtable slot 9; derived name */
    int FUN_0000e160() const;                    /* vtable slot 12; derived name */
    hkLocalFrame *FUN_0000e170(int index) const; /* vtable slot 13; derived name */
    /* Slot 15 (0xe0b0): the group set, its reference taken and the old
     * one's released. derived name. */
    void FUN_0000e0b0(hkLocalFrameGroup *newGroup);

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

    /* Out of line (0x1d070, slot 0; 0x1d0e0, slot 1, the deleting one at
     * the recorded size): the debugger's reference released and the
     * pointer cleared. */
    virtual ~hkcdPlanarEntity();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkReferencedObject *debugger;
};

/* hkcdFractureEngine (hkClass 0x57b9d20, built at 0x1c740: size 0x10,
 * parent hkReferencedObject's, no members): its four enums, SplitResult,
 * Type, ExecutionFlagValues and Topology, are the records at 0x168ede0. */
class hkcdFractureEngine : public hkReferencedObject
{
};

extern const hkClassEnum D_168ede0[]; /* derived name */

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
/* From its record table at 0x168eec0: storage (an array of int) at +0x10,
 * primaryBitmap at +0x20, secondaryBitmaps (26) at +0x24 and freeBlocks
 * (832) at +0x8c. Its destructor (0x1c8e0, slot 0; the polygon
 * collection's slot 0 too, which adds nothing to destroy) gives the storage
 * back. */
extern const hkClass D_57b9df0;         /* hkcdPlanarGeometryPrimitivesCollection28's hkClass */
extern const hkClassMember D_168eec0[]; /* derived name: its records */

class hkcdPlanarGeometryPrimitivesCollection28 : public hkReferencedObject
{
  public:
    hkcdPlanarGeometryPrimitivesCollection28(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), storage(flag)
    {
    }

    /* Inline: the polygon collection's deleting destructor (0x95f10) holds
     * it; the type info's finish callback emits it beside its own body. */
    virtual ~hkcdPlanarGeometryPrimitivesCollection28() {}

    /* The class delete: the object back to the thread's heap at its size,
     * no null test (the deleting destructor 0x1c930, slot 1). */
    static void operator delete(void *object, unsigned long numBytes)
    {
        FUN_0000bcf0(object, numBytes);
    }

    hkArray<s32> storage;
    u32 primaryBitmap;
    u32 secondaryBitmaps[26];
    u32 freeBlocks[832];
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

    /* Out of line (its D1 the linker folded into the base's 0x1c8e0; the
     * deleting one 0x95f10, slot 1). */
    virtual ~hkcdPlanarGeometryPolygonCollection();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);
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
    /* hkcdPlanarSolid::Node (the scoped name a string of the executable,
     * hkClass 0x57ba310): 0x28 bytes (the node storage's free, 0x1d529),
     * its members not read. */
    struct Node {
        u8 unknown0[0x28];
    };

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
/* What hkcdPlanarGeometry's vertices point to (derived names): a
 * reference-counted array of 32-byte vertices, built in FUN_0009a8a0
 * (0x20 bytes from the heap at 0x9a90b, value-initialized, its vtable
 * 0x16a36b0 stored at 0x9a95b; no type info names the class, and the
 * vtable has the five slots of hkReferencedObject's). The array is its
 * second base: the destructors (0x9a760, and 0x9a7b0 deleting) store no
 * vptr, which a member array would make them do. */
struct hkcdPlanarGeometryVertex { /* derived name */
    u8 unknown0[0x20];
};

class hkcdPlanarGeometryVertexStorage /* derived name */
    : public hkReferencedObject,
      public hkArray<hkcdPlanarGeometryVertex>
{
  public:
    /* Slot 0 (0x9a760); the deleting destructor 0x9a7b0 runs it inline and
     * frees through the class's delete. */
    virtual ~hkcdPlanarGeometryVertexStorage();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);
};

struct hkcdPlanarGeometry : public hkcdPlanarEntity {
    hkcdPlanarGeometry(hkFinishLoadedObjectFlag flag);
    virtual ~hkcdPlanarGeometry();

    /* 0x9a8a0, a large member (derived name). */
    void FUN_0009a8a0(int argument);

    hkcdPlanarGeometryPlanesCollection *planes;
    hkcdPlanarGeometryPolygonCollection *polys;
    void *vertices;
};

/* Its members from the records at 0x168f620: storage (the nodes) at +0x10,
 * aabbs at +0x20, firstFreeNodeId (hkUint32) at +0x30. */
class hkcdPlanarSolid::NodeStorage : public hkReferencedObject
{
  public:
    NodeStorage(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), storage(flag), aabbs(flag)
    {
    }

    /* The arrays given back (0x1d4c0, slot 0; the deleting destructor
     * 0x1d550 holds the same body). Inline, emitted with the vtable: the
     * executable holds the complete destructor before the deleting one
     * (cookbook 187). */
    inline virtual ~NodeStorage() {}

    /* The reference-counted class delete (freeReferencedObject in
     * tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<Node> storage;
    hkArray<struct hkAabb> aabbs;
    u32 firstFreeNodeId;
};

/* Reference-counted classes whose finish constructors are inline in their
 * finish callbacks and store only the vtable (vtable, callback): */
/* hknpDynamicCompoundShapeData: vtable 0x1692990, finish callback FUN_000343e0. */
class hknpDynamicCompoundShapeData : public hkReferencedObject
{
  public:
    hknpDynamicCompoundShapeData(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), nodes(flag)
    {
    }

    /* Out of line (0x342c0, slot 0): the nodes given back. */
    virtual ~hknpDynamicCompoundShapeData();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    /* The tree's nodes from +0x10, each an AABB whose max's w the tree
     * keeps its own data in (the shape's slot 32, 0xf04a0, reads a leaf's
     * and clears that w). derived name. */
    hkArray<struct hkAabb> nodes;
    /* The rest of its one member, aabbTree (an hknpDynamicCompoundShapeTree,
     * record 0x1692a50, from +0x10), to the class's 0x30 bytes (its hkClass
     * built at 0x345bb). */
    u8 unknown20[0x10];
};

/* hknpCompressedMeshShapeInternals (its own members not yet read) and its
 * nested KeyMask (scoped name "hknpCompressedMeshShapeInternals::KeyMask",
 * vtable 0x1692ab0, finish callback FUN_00034e00; defined after
 * hknpShapeKeyMask, its parent). */
struct hknpCompressedMeshShapeInternals {
    class KeyMask;
};

/* hknpVehicleVelocityDamper, the velocity dampers' interface (its hkClass
 * at 0x57c2428, built by the reflection initializer at 0x69890: size 0x10,
 * parent hkReferencedObject's, no members). */
class hknpVehicleVelocityDamper : public hkReferencedObject
{
  public:
    hknpVehicleVelocityDamper(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

extern const hkClass D_57c2428; /* hknpVehicleVelocityDamper's hkClass */

/* hknpVehicleDefaultVelocityDamper: vtable 0x1695890, finish callback FUN_00035c60;
 * members from its records (0x1692ef0): three floats from +0xc. */
class hknpVehicleDefaultVelocityDamper : public hknpVehicleVelocityDamper
{
  public:
    hknpVehicleDefaultVelocityDamper(hkFinishLoadedObjectFlag flag)
        : hknpVehicleVelocityDamper(flag)
    {
    }

    float normalSpinDamping;
    float collisionSpinDamping;
    float collisionThreshold;
};

/* hknpCharacterRigidBodyCinfo is defined after hkQuaternion, which it holds. */
class hknpCharacterRigidBodyCinfo;

/* hknpMaterialPalette: vtable 0x16937b0, finish callback FUN_000377c0;
 * its one member from its record (0x16937f0): an array of material
 * descriptors (hkClass 0x57c1f70) at +0x10. */
struct hknpMaterialDescriptor;

class hknpMaterialPalette : public hkReferencedObject
{
  public:
    hknpMaterialPalette(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag), entries(flag) {}

    hkArray<hknpMaterialDescriptor> entries;
};

/* hknpVehicleDriverInputAnalogStatus: vtable 0x16a4420, finish callback
 * FUN_000378e0; members (records from 0x16938c0) positionX and positionY
 * (floats) at +0xc and +0x10, handbrakeButtonPressed and
 * reverseButtonPressed (hkBool) at +0x14 and +0x15. */
class hknpVehicleDriverInputAnalogStatus : public hkReferencedObject
{
  public:
    hknpVehicleDriverInputAnalogStatus(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    /* The class allocator, inline: the thread's heap (0x151d58;
     * tlg_lib_unknown.h); placement stays available beside it (the finish
     * callback 0x378e0). */
    static void *operator new(unsigned long numBytes);

    static void *operator new(unsigned long, void *where)
    {
        return where;
    }

    /* Slot 5 (0x151d30): a new status with this one's values. derived
     * name. */
    hknpVehicleDriverInputAnalogStatus *FUN_00151d30() const;

    float positionX;
    float positionY;
    hkBool handbrakeButtonPressed;
    hkBool reverseButtonPressed;
};

class hknpVehicleInstance;

/* hknpVehicleDefaultAnalogDriverInput: vtable 0x16a43c0, finish callback
 * FUN_000378b0; members (records from 0x1693820) slopeChangePointX,
 * initialSlope and deadZone (floats) at +0xc to +0x14, autoReverse (hkBool)
 * at +0x18. Slot 6 (FUN_00151d90) is the accelerator input, slot 7
 * (FUN_00151de0) the brake input. */
/* The driver's input filtered for a step, which the driver input's slot 5
 * fills (derived names; the pedals, the steering, the handbrake and whether
 * the driver is trying to reverse, at +0, +4, +8, +0xc and +0xd). */
struct hknpVehicleFilteredDriverInput /* derived name */
{
    float acceleratorPedalInput;
    float brakePedalInput;
    float steeringWheelInput;
    hkBool handbrakeOn;
    hkBool tryingToReverse;
};

class hknpVehicleDefaultAnalogDriverInput : public hkReferencedObject
{
  public:
    hknpVehicleDefaultAnalogDriverInput(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    /* Slot 5 (0x152010): the filtered input from slots 6 to 9 and the
     * status's handbrake. derived name. */
    virtual void FUN_00152010(float deltaTime, const hknpVehicleInstance *vehicle,
                              const hknpVehicleDriverInputAnalogStatus *status,
                              hknpVehicleFilteredDriverInput &output);
    /* Slot 6 (0x151d90): the accelerator. derived name. */
    virtual float FUN_00151d90(float deltaTime, const hknpVehicleInstance *vehicle,
                               const hknpVehicleDriverInputAnalogStatus *status,
                               hknpVehicleFilteredDriverInput &output) const;
    /* Slot 7 (0x151de0): the brake. derived name. */
    virtual float FUN_00151de0(float deltaTime, const hknpVehicleInstance *vehicle,
                               const hknpVehicleDriverInputAnalogStatus *status,
                               hknpVehicleFilteredDriverInput &output) const;
    /* Slot 8 (0x151ea0): whether the driver is trying to reverse. derived
     * name. */
    virtual hkBool FUN_00151ea0(float deltaTime, const hknpVehicleInstance *vehicle,
                                const hknpVehicleDriverInputAnalogStatus *status,
                                hknpVehicleFilteredDriverInput &output) const;
    /* Slot 9 (0x151e10): the steering input from the stick's x, nothing
     * inside the dead zone, the initial slope up to the change point and a
     * straight line to full beyond it. derived name. */
    virtual float FUN_00151e10(float deltaTime, const hknpVehicleInstance *vehicle,
                               const hknpVehicleDriverInputAnalogStatus *status,
                               hknpVehicleFilteredDriverInput &output) const;

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
    /* The engine speed slot 9 (0x680b0) shifts by. derived name. */
    float transmissionRPM;
    /* Slot 6's torque, shared to the wheels by their ratios. derived
     * name. */
    float mainTransmittedTorque;
    float *wheelsTransmittedTorque; /* derived name */
    u8 unknown10;
    hkBool isReversing; /* derived name */
    s8 currentGear;     /* derived name */
    /* Set while the gear changes: slot 6 (0x67ffc) passes no torque then.
     * derived name. */
    hkBool isInGearChange;
    /* The time left of a gear change (slot 9 counts it down from the
     * clutch delay). derived name. */
    float gearChangeTimeLeft;
};

/* hknpVehicleTransmission, the transmissions' interface (its hkClass at
 * 0x57bff10, built by the reflection initializer at 0x3cbd0: size 0x10,
 * parent hkReferencedObject's, no members). */
class hknpVehicleTransmission : public hkReferencedObject
{
};

extern const hkClass D_57bff10; /* hknpVehicleTransmission's hkClass */

/* hknpVehicleDefaultTransmission: vtable 0x1699b90, finish callback FUN_00037a90. */
class hknpVehicleDefaultTransmission : public hkReferencedObject
{
  public:
    hknpVehicleDefaultTransmission(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), gearsRatio(flag), wheelsTorqueRatio(flag)
    {
    }

    /* The arrays given back (0x67da0, slot 0; the deleting destructor
     * 0x67e20 holds the same body). Inline: the executable holds the
     * complete destructor before the deleting one, as the vtable's emission
     * gives them (cookbook 187), in the translation unit of the key
     * function, slot 5 (0x67f40). */
    inline virtual ~hknpVehicleDefaultTransmission() {}

    /* The reference-counted class delete (freeReferencedObject in
     * tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    /* Slots 5 to 10 (0x67f40, 0x67ff0, 0x68030, 0x68130, 0x680b0,
     * 0x67ef0); slot 6 asks slot 10 for the ratio through the vtable. */
    /* Slot 5 (0x67f40): the output filled from slots 8, 6 and 7, each
     * wheel's torque its ratio of the main one, then slot 9's shift. derived
     * name. */
    virtual void FUN_00067f40(float deltaTime, const hknpVehicleInstance *vehicle,
                              hknpVehicleTransmissionOutput &output) const;
    /* Slot 6: the torque passed on, none while the gear changes. derived
     * name. */
    virtual float FUN_00067ff0(const hknpVehicleInstance *vehicle,
                               const hknpVehicleTransmissionOutput &output) const;
    /* Slot 7 (0x68030): the wheels' spin in revolutions a minute, each by
     * its share of the torque, through the gear's ratio, never negative.
     * derived name. */
    virtual float FUN_00068030(const hknpVehicleInstance *vehicle,
                               const hknpVehicleTransmissionOutput &output) const;
    virtual bool FUN_00068130(
        const hknpVehicleInstance *vehicle,
        const hknpVehicleTransmissionOutput &output) const; /* vtable slot 8; derived name */
    /* Slot 9 (0x680b0): the gear change's time counted down, then outside
     * reverse one gear down below the downshift speed or up above the
     * upshift speed, each starting a change. derived name. */
    virtual void FUN_000680b0(float deltaTime, const hknpVehicleInstance *vehicle,
                              hknpVehicleTransmissionOutput &output) const;
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

/* hkReferencedObject's hkClass (built at 0xe222) and its one member's
 * record (0x168d980). */
extern const hkClass D_57b8640;         /* hkReferencedObject's hkClass */
extern const hkClassMember D_168d980[]; /* derived name: hkReferencedObject's records */

/* hknpVehicleAerodynamics, the aerodynamics' interface (its hkClass at
 * 0x57bf880, built by the reflection initializer at 0x3a040: size 0x10,
 * parent hkReferencedObject's, no members). */
class hknpVehicleAerodynamics : public hkReferencedObject
{
  public:
    hknpVehicleAerodynamics(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

extern const hkClass D_57bf880; /* hknpVehicleAerodynamics's hkClass */

/* hknpVehicleDefaultAerodynamics: vtable 0x1695ac0, finish callback
 * FUN_0003a0d0. Members from its records (0x1695170 onward): airDensity,
 * frontalArea, dragCoefficient and liftCoefficient (floats) from +0xc,
 * extraGravityws (a vector) at +0x20. Slot 6 (0x3bf20) is the drag at a
 * speed, slot 7 (FUN_0003bf60) the lift. */
class hknpVehicleDefaultAerodynamics : public hknpVehicleAerodynamics
{
  public:
    hknpVehicleDefaultAerodynamics(hkFinishLoadedObjectFlag flag) : hknpVehicleAerodynamics(flag) {}

    float FUN_0003bf20(float speed) const; /* vtable slot 6; derived name */
    float FUN_0003bf60(float speed) const; /* vtable slot 7; derived name */

    float airDensity;
    float frontalArea;
    float dragCoefficient;
    float liftCoefficient;
    Vec4 extraGravityws;
};

/* hknpGroupCollisionFilter: vtable 0x16952a0, finish callback FUN_0003a3b0;
 * 0xa0 bytes (its deleting destructor's size). */
class hknpGroupCollisionFilter : public hkReferencedObject
{
  public:
    hknpGroupCollisionFilter(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    /* Empty (the shared 0x396a0); the deleting destructor 0x3a350, after
     * the class's slots 5 to 8 (0x3a1b0 to 0x3a2f0), is the body the
     * vtables of the 0xa0-byte reference-counted classes with empty
     * destructors cite (D15). */
    virtual ~hknpGroupCollisionFilter();

    static void operator delete(void *object, unsigned long numBytes);

    u8 unknownC[0x94];
};

struct hknpBody;

/* What a query is filtered with (derived names): the collision filter
 * info at +4. */
struct hknpQueryFilterData /* derived name */
{
    u16 materialId;
    u32 collisionFilterInfo;
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

    /* Slot 7 (0x3a290, the group filter's too): a query against a body.
     * Inside one system group other than 0 the subsystem ids decide, else
     * the layers' lookup table. derived name. */
    bool FUN_0003a290(int queryType, const hknpQueryFilterData &filterData,
                      const hknpBody &body) const;

    /* Slot 8 (0x3a2f0): two query filter datas against each other, the
     * same test as slot 7's; the third argument is not read. derived name. */
    bool FUN_0003a2f0(int queryType, bool argument2, const hknpQueryFilterData &filterDataA,
                      const hknpQueryFilterData &filterDataB) const;

    /* The test of two filter infos, nonzero when they collide (inline in
     * slot 7: its two paths' values meet in one test). derived name. */
    hkBool32 isCollisionEnabled(u32 infoA, u32 infoB) const
    {
        const u32 zeroIfSameSystemGroup = (infoA ^ infoB) & 0x7fff8000;
        if (zeroIfSameSystemGroup == 0) {
            if ((infoA & 0x7fff8000) != 0) {
                const int idA = (infoA >> 5) & 0x1f;
                const int dontCollideB = (infoB >> 10) & 0x1f;
                if (idA == dontCollideB) {
                    return 0;
                }
                const int idB = (infoB >> 5) & 0x1f;
                const int dontCollideA = (infoA >> 10) & 0x1f;
                return idB - dontCollideA;
            }
        }
        const u32 layerBitsA = collisionLookupTable[infoA & 0x1f];
        const u32 layerBitsB = u32(1 << (infoB & 0x1f));
        return layerBitsA & layerBitsB;
    }

    u8 unknownC[8];
    u32 collisionLookupTable[32]; /* derived name */
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

/* Its one enum, Space (its records at 0x1699770). */
extern const hkClassEnum D_1699770[]; /* derived name */

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

/* hknpVehicleSuspension (hkClass 0x57c2f98 built at 0x78090, the string
 * 0x14bf7d2: 0x20 bytes, parent hkReferencedObject, members at 0x169b640;
 * vtable 0x16a4000, stored only by destructors, slot 5 pure). */
class hknpVehicleSuspension : public hkReferencedObject
{
  public:
    /* hknpVehicleSuspension::SuspensionWheelParameters (hkClass 0x57c2f18
     * built at 0x77fed: 0x30 bytes, records at 0x169b5c0). */
    struct SuspensionWheelParameters {
        hkVector4 hardpointChassisSpace;
        hkVector4 directionChassisSpace;
        float length;
    };

    hknpVehicleSuspension(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), wheelParams(flag)
    {
    }

    /* Inline (the default suspension's destructors hold it, 0x14dd7d and
     * 0x14de1e): the wheels' parameters given back. Its own copies, slot 0
     * (0x14deb0) and the deleting destructor (0x14df10, slot 1, freeing at
     * the recorded size, 0x20 by default), are emitted with the vtable where
     * a derived class's destructor uses it. */
    virtual ~hknpVehicleSuspension() {}

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    /* Slot 5, pure; named after the default suspension's overrider
     * (0x14dfa0), its parameters not recovered. derived name. */
    virtual void FUN_0014dfa0() = 0;

    hkArray<SuspensionWheelParameters> wheelParams;
};

/* hknpVehicleDefaultSuspension: vtable 0x16a4040, finish callback FUN_0003e590. */
class hknpVehicleDefaultSuspension : public hknpVehicleSuspension
{
  public:
    /* hknpVehicleDefaultSuspension::WheelSpringSuspensionParameters (the
     * names from the executable's strings; 12 bytes, the order derived). */
    struct WheelSpringSuspensionParameters {
        float strength;
        float dampingCompression;
        float dampingRelaxation;
    };

    hknpVehicleDefaultSuspension(hkFinishLoadedObjectFlag flag)
        : hknpVehicleSuspension(flag), wheelSpringParams(flag)
    {
    }

    /* Out of line (0x14dd30, slot 0): the springs' parameters given back,
     * then the base's; the deleting destructor (0x14ddd0, slot 1) frees at
     * the recorded size, 0x30 by default. */
    virtual ~hknpVehicleDefaultSuspension();

    /* Slot 5 (0x14dfa0). derived name. */
    virtual void FUN_0014dfa0();

    hkArray<WheelSpringSuspensionParameters> wheelSpringParams;
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

/* Built by the reflection initializer at 0x3cc60. */
extern const hkClass D_57bff60; /* hknpVehicleEngine's hkClass */

class hknpVehicleBrake : public hkReferencedObject
{
  public:
    hknpVehicleBrake(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* Built by the reflection initializers at 0x6b620 and 0x618b0. */
extern const hkClass D_57c26f8; /* hknpVehicleBrake's hkClass */
extern const hkClass D_57c1988; /* hknpVehicleSteering's hkClass */

class hknpVehicleInstance;

class hknpVehicleSteering : public hkReferencedObject
{
  public:
    /* The steering a step's input gives (derived names): the main angle,
     * then one angle per wheel. */
    struct SteeringAnglesOutput {
        float mainSteeringAngle;
        hkArray<float> wheelsSteeringAngle;
    };

    hknpVehicleSteering(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    /* Slot 5: the step's steering from the filtered driver input. derived
     * name. */
    virtual void calcSteering(float deltaTime, const hknpVehicleInstance *vehicle,
                              const void *filteredInfoOutput,
                              SteeringAnglesOutput &steeringOutput) const = 0;
};

/* hknpVehicleDefaultEngine (hkClass 0x57c1310, 0x38 bytes, parent
 * hknpVehicleEngine): vtable 0x16a4d90, finish callback FUN_00046b70. */
class hknpVehicleDefaultEngine : public hknpVehicleEngine
{
  public:
    hknpVehicleDefaultEngine(hkFinishLoadedObjectFlag flag) : hknpVehicleEngine(flag) {}

    /* Empty (the shared 0x158a30); the deleting destructor 0x15c430,
     * beside the class's slots, is the body only this vtable cites
     * (D15). */
    virtual ~hknpVehicleDefaultEngine();

    static void operator delete(void *object, unsigned long numBytes);

    u8 unknownC[0x2c];
};

/* hknpVehicleDefaultBrake (hkClass 0x57c15e0 built at 0x5b433: 0x28 bytes,
 * parent hknpVehicleBrake, members from the record table 0x1699460):
 * vtable 0x16a5350, finish callback FUN_0005b300; wheelBrakingProperties
 * at +0x10, wheelsMinTimeToBlock at +0x20. */
class hknpVehicleDefaultBrake : public hknpVehicleBrake
{
  public:
    /* hknpVehicleDefaultBrake::WheelBrakingProperties (hkClass 0x57c1560
     * built at 0x5b38d: 0xc bytes, records at 0x16993e0). */
    struct WheelBrakingProperties {
        float maxBreakingTorque;
        float minPedalInputToBlock;
        hkBool isConnectedToHandbrake;
    };

    hknpVehicleDefaultBrake(hkFinishLoadedObjectFlag flag)
        : hknpVehicleBrake(flag), wheelBrakingProperties(flag)
    {
    }

    /* Out of line (0x16a3b0, slot 0): the wheels' properties given back;
     * the deleting destructor (0x16a410, slot 1) frees at the recorded
     * size, 0x28 by default. */
    virtual ~hknpVehicleDefaultBrake();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<WheelBrakingProperties> wheelBrakingProperties;
    float wheelsMinTimeToBlock;
};

/* hknpRefMassDistribution: defined after hkQuaternion, whose vector its
 * member's hkClass holds. */
class hknpRefMassDistribution;

/* hknpVehicleDefaultSteering (parent hknpVehicleSteering): vtable 0x16a5750,
 * finish callback FUN_00077d60. Members from the record table 0x169b4a0:
 * maxSteeringAngle at +0xc (in hkReferencedObject's tail),
 * maxSpeedFullSteeringAngle at +0x10, doesWheelSteer (an array of hkBool)
 * at +0x18. */
class hknpVehicleDefaultSteering : public hknpVehicleSteering
{
  public:
    hknpVehicleDefaultSteering(hkFinishLoadedObjectFlag flag)
        : hknpVehicleSteering(flag), doesWheelSteer(flag)
    {
    }

    /* Out of line (0x16f980, slot 0): the array given back; the deleting
     * destructor (0x16f9e0, slot 1) runs it and frees through the class's
     * delete. */
    virtual ~hknpVehicleDefaultSteering();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    /* Slot 5 (0x16fb70): the main angle through slot 6, then each wheel
     * that steers takes it and the others none. derived name. */
    virtual void calcSteering(float deltaTime, const hknpVehicleInstance *vehicle,
                              const void *filteredInfoOutput,
                              SteeringAnglesOutput &steeringOutput) const;

    /* Slot 6 (0x16fa80): the main angle. derived name. */
    virtual void calcMainSteeringAngle(float deltaTime, const hknpVehicleInstance *vehicle,
                                       const void *filteredInfoOutput,
                                       SteeringAnglesOutput &steeringOutput) const;

    float maxSteeringAngle;
    float maxSpeedFullSteeringAngle;
    hkArray<hkBool> doesWheelSteer;
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

    /* Empty and inline (the shared 0x3b640; hknpVehicleData's destructor
     * 0x6df00 has nothing of it): the deleting destructor 0x691d0, beside
     * the finish callback of hknpVehicleData (which holds a friction
     * description at +0xb0, and whose file emits the vtable with it), is
     * the body the vtables of the 0xe0-byte reference-counted classes with
     * empty destructors cite (D15). */
    virtual ~hkpVehicleFrictionDescription() {}

    static void operator delete(void *object, unsigned long numBytes);

    /* To the class's 0xe0 bytes (its deleting destructor's size, and the
     * room hknpVehicleData gives it, +0xb0 to +0x190). */
    u8 unknownC[0xd4];
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
/* hknpVehicleData::WheelComponentParams (the string at 0x14be995; its
 * hkClass built at 0x692fd, size 0x28): members not typed yet. */
struct hknpVehicleDataWheelComponentParams {
    u8 unknown0[0x28];
};

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

/* hkxSpline::ControlPoint (hkClass 0x57c5f00, size 0x40; its five member
 * records are built at run time by 0x85fc0). */
struct hkxSplineControlPoint {
    u8 unknown0[0x40];
};

/* From its record table at 0x16a08c0: controlPoints (an array of
 * ControlPoint) at +0x10, isClosed (hkBool) at +0x20. */
class hkxSpline : public hkReferencedObject
{
  public:
    hkxSpline(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag), controlPoints(flag) {}

    /* Out of line (0x85e90, slot 0): the control points given back. */
    virtual ~hkxSpline();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<hkxSplineControlPoint> controlPoints;
    hkBool isClosed;
};

/* From its hkClass (0x57c6580, size 0x28; records built at run time by 0x86d90): vectors (an array of reals) at +0x10, hint at +0x20. */
class hkxAnimatedVector : public hkReferencedObject
{
  public:
    hkxAnimatedVector(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag), vectors(flag) {}

    /* Out of line (0x86c80, slot 0): the array given back. */
    virtual ~hkxAnimatedVector();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<float> vectors;
    u8 hint; /* an enum of hkUint8 (its record's type and subtype, 0x86e37) */
};

/* From its record table at 0x16a0d80: selectedTriangles (an array of int) at +0x10. */
class hkxTriangleSelectionChannel : public hkReferencedObject
{
  public:
    hkxTriangleSelectionChannel(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), selectedTriangles(flag)
    {
    }

    /* Out of line (0x86f10, slot 0): the array given back. */
    virtual ~hkxTriangleSelectionChannel();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<s32> selectedTriangles;
};

/* From its record table at 0x16a0e30: perVertexVectors (an array of reals) at +0x10. */
class hkxVertexVectorDataChannel : public hkReferencedObject
{
  public:
    hkxVertexVectorDataChannel(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), perVertexVectors(flag)
    {
    }

    /* Out of line (0x873a0, slot 0): the array given back. */
    virtual ~hkxVertexVectorDataChannel();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<float> perVertexVectors;
};

/* hkxSparselyAnimatedBool (type info 0x57c8280, size 0x30, hkClass parent
 * hkReferencedObject, built at 0x8e2fd, member records at 0x16a2b70): bools
 * (an array of hkBool) at +0x10 and times (an array of reals) at +0x20. The
 * finish callback FUN_0008e280 runs the inline finish constructor. */
class hkxSparselyAnimatedBool : public hkReferencedObject
{
  public:
    hkxSparselyAnimatedBool(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), bools(flag), times(flag)
    {
    }

    /* The arrays given back (0x8e120, slot 0; the deleting destructor
     * 0x8e1b0 holds the same body). Inline, emitted with the vtable: the
     * executable holds the complete destructor before the deleting one
     * (cookbook 187). */
    inline virtual ~hkxSparselyAnimatedBool() {}

    /* The reference-counted class delete (freeReferencedObject in
     * tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<hkBool> bools;
    hkArray<float> times;
};

/* Members from its records (0x16a0ea0): strings (an array of hkStringPtr)
 * at +0x10, times (an array of reals) at +0x20. */
class hkxSparselyAnimatedString : public hkReferencedObject
{
  public:
    hkxSparselyAnimatedString(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), strings(flag), times(flag)
    {
    }

    hkArray<hkStringPtr> strings;
    hkArray<float> times;
};

/* From its hkClass (0x57c6850, size 0x28; records built at run time by 0x87b70): perVertexFloats (an array of reals) at +0x10, dimensions at +0x20. */
class hkxVertexFloatDataChannel : public hkReferencedObject
{
  public:
    hkxVertexFloatDataChannel(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), perVertexFloats(flag)
    {
    }

    /* Out of line (0x87a60, slot 0): the array given back. */
    virtual ~hkxVertexFloatDataChannel();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<float> perVertexFloats;
    u8 dimensions; /* an enum of hkUint8 (its record's type and subtype, 0x87c1e) */
};

/* From its record table at 0x16a12a0: perVertexInts (an array of int) at +0x10. */
class hkxVertexIntDataChannel : public hkReferencedObject
{
  public:
    hkxVertexIntDataChannel(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), perVertexInts(flag)
    {
    }

    /* Out of line (0x88000, slot 0): the array given back. */
    virtual ~hkxVertexIntDataChannel();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<s32> perVertexInts;
};

/* Its members from the records the initializer 0x88350 builds at
 * 0x57c6b20: indexType (an enum of hkUint8) at +0xc, indices16 and
 * indices32 (arrays of hkUint16 and hkUint32) at +0x10 and +0x20,
 * vertexBaseOffset and length (hkUint32) at +0x30 and +0x34. */
class hkxIndexBuffer : public hkReferencedObject
{
  public:
    hkxIndexBuffer(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), indices16(flag), indices32(flag)
    {
    }

    /* The arrays given back (0x881d0, slot 0; the deleting destructor
     * 0x88260 holds the same body). Inline, emitted with the vtable: the
     * executable holds the complete destructor before the deleting one
     * (cookbook 187). */
    inline virtual ~hkxIndexBuffer() {}

    /* The reference-counted class delete (freeReferencedObject in
     * tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    u8 indexType; /* an enum of hkUint8; its items not read */
    hkArray<u16> indices16;
    hkArray<u32> indices32;
    u32 vertexBaseOffset;
    u32 length;
};

/* From its record table at 0x16a13d0: quaternions (an array of reals) at +0x10. */
class hkxAnimatedQuaternion : public hkReferencedObject
{
  public:
    hkxAnimatedQuaternion(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), quaternions(flag)
    {
    }

    /* Out of line (0x885e0, slot 0): the array given back. */
    virtual ~hkxAnimatedQuaternion();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<float> quaternions;
};

/* From its record table at 0x16a1440 (hkClass 0x57c6c68, 0x30 bytes): ints
 * (an array of int) at +0x10, times (an array of float) at +0x20. */
class hkxSparselyAnimatedInt : public hkReferencedObject
{
  public:
    hkxSparselyAnimatedInt(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), ints(flag), times(flag)
    {
    }

    /* The arrays given back (0x887b0, slot 0; the deleting destructor
     * 0x88830 holds the same body). Inline, emitted with the vtable: the
     * executable holds the complete destructor before the deleting one
     * (cookbook 187). */
    inline virtual ~hkxSparselyAnimatedInt() {}

    /* The reference-counted class delete (freeReferencedObject in
     * tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<s32> ints;
    hkArray<float> times;
};

/* From its record table at 0x16a1520: selectedEdges (an array of int) at +0x10. */
class hkxEdgeSelectionChannel : public hkReferencedObject
{
  public:
    hkxEdgeSelectionChannel(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), selectedEdges(flag)
    {
    }

    /* Out of line (0x88bc0, slot 0): the array given back. */
    virtual ~hkxEdgeSelectionChannel();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<s32> selectedEdges;
};

/* From its hkClass (0x57c6df0, size 0x28; records built at run time by 0x88ea0): matrices (an array of reals) at +0x10, hint at +0x20. */
class hkxAnimatedMatrix : public hkReferencedObject
{
  public:
    hkxAnimatedMatrix(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag), matrices(flag) {}

    /* Out of line (0x88d90, slot 0): the array given back. */
    virtual ~hkxAnimatedMatrix();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<float> matrices;
    u8 hint; /* an enum of hkUint8 (its record's type and subtype, 0x88f47) */
};

/* hkxEnum::Item (hkClass 0x57c6fc0, built at 0x899b1: size 0x10): value
 * (INT32) at +0, name (STRINGPTR) at +8. */
struct hkxEnumItem {
    int value;
    hkStringPtr name;
};

/* hkxEnum (hkClass 0x57c7040, built at 0x89a5a: size 0x20, parent
 * hkReferencedObject's): items (an array of hkxEnum::Item) at +0x10. */
class hkxEnum : public hkReferencedObject
{
  public:
    hkxEnum(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag), items(flag) {}

    /* Out of line (0x89740, slot 0); the deleting destructor (0x897e0,
     * slot 1) frees through the class's delete. */
    virtual ~hkxEnum();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<hkxEnumItem> items;
};

/* hkxCamera: 0x50 bytes (its deleting destructor's size). */
class hkxCamera : public hkReferencedObject
{
  public:
    hkxCamera(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    /* Empty (the shared 0x83250); the deleting destructor 0x8a210, before
     * the finish callback 0x8a270, is the body the vtables of the 0x50-byte
     * reference-counted classes with empty destructors cite (D15). */
    virtual ~hkxCamera();

    static void operator delete(void *object, unsigned long numBytes);

    u8 unknownC[0x44];
};

/* hkxAttributeHolder (hkClass 0x57c76b0, built at 0x8b422: size 0x20,
 * parent hkReferencedObject's 0x57b8640, one member record at 0x16a1f70):
 * attributeGroups (an array of hkxAttributeGroup, class 0x57c6ce8) at
 * +0x10. */
/* hkxAttributeGroup (hkClass 0x57c6ce8, built at 0x88b6d: size 0x18, no
 * parent, its two members from the records at 0x16a1490). */
struct hkxAttribute;

struct hkxAttributeGroup {
    /* The name finished, the attributes left as loaded (the type info's
     * finish callback, folded with hknpMaterialDescriptor's, 0x6c800). */
    hkxAttributeGroup(hkFinishLoadedObjectFlag flag) : name(flag), attributes(flag) {}

    hkStringPtr name;
    hkArray<hkxAttribute> attributes;
};

extern const hkClassMember D_16a1490[]; /* derived name: hkxAttributeGroup's records */

/* Its type info's cleanup (0x88a00): the group destroyed in place. derived
 * name. */
void FUN_00088a00(void *object); /* derived name */

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

/* hkxNode (vtable 0x16a25e0, member records 0x16a1ff0 to 0x16a2158; parent
 * hkxAttributeHolder): name at +0x20, uuid at +0x28, object (a pointer) at
 * +0x38, the arrays keyFrames (hkMatrix4), children (pointers to hkxNode),
 * annotations (AnnotationData: time and description, records 0x16a1fa0 and
 * 0x16a1fc8) and linearKeyFrameHints (hkReal) from +0x40, userProperties
 * at +0x80, selected and bone (hkBool) at +0x88 and +0x89. */
class hkxNode : public hkxAttributeHolder
{
  public:
    struct AnnotationData {
        float time;
        hkStringPtr description;
    };

    /* The finish constructor, out of line (0x8b4b0): the two strings and
     * the uuid finished, the arrays left as loaded. */
    hkxNode(hkFinishLoadedObjectFlag flag);

    hkStringPtr name;
    hkUuid uuid;
    void *object;
    hkArray<Mat4> keyFrames;
    hkArray<hkxNode *> children;
    hkArray<AnnotationData> annotations;
    hkArray<float> linearKeyFrameHints;
    hkStringPtr userProperties;
    hkBool selected;
    hkBool bone;
};

/* hkxMaterial (hkClass 0x57c61d0, built at 0x86bf1: size 0xe0, parent
 * hkxAttributeHolder's; its member records are written at run time from
 * 0x57c6220, name (hkStringPtr) first, then stages, the four colours,
 * subMaterials, extraData and the rest): the finish callback 0x86350 finishes
 * only the name at +0x20. */
class hkxMaterial : public hkxAttributeHolder
{
  public:
    hkxMaterial(hkFinishLoadedObjectFlag flag) : hkxAttributeHolder(flag), name(flag) {}

    hkStringPtr name;
    /* To the record's 0xe0 bytes (its member records are built at run
     * time; the deleting destructor 0x870e0 frees 0xe0). */
    u8 unknown28[0xb8];
};

/* hkxMaterialEffect (hkClass 0x57c7140, built at 0x89e36: size 0x30,
 * parent hkReferencedObject's; member records written at run time from
 * 0x57c71c0: name, type, data): the finish callback 0x89c70 finishes the
 * name at +0x10. */
class hkxMaterialEffect : public hkReferencedObject
{
  public:
    hkxMaterialEffect(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), data(flag), name(flag)
    {
    }

    /* Out of line (0x89b60, slot 0; 0x89bc0, slot 1): the data given back,
     * then the name. */
    virtual ~hkxMaterialEffect();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkStringPtr name;
    u8 unknown18[8];
    hkArray<u8> data;
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
        : hkxAttributeHolder(flag), selectedNodes(flag), name(flag)
    {
    }

    hkArray<hkxNode *> selectedNodes;
    hkStringPtr name;
};

/* From its record table at 0x16a2540: selectedVertices (an array of int) at +0x10. */
class hkxVertexSelectionChannel : public hkReferencedObject
{
  public:
    hkxVertexSelectionChannel(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), selectedVertices(flag)
    {
    }

    /* Out of line (0x8bbe0, slot 0): the array given back. */
    virtual ~hkxVertexSelectionChannel();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<s32> selectedVertices;
};

/* hkxBlob (hkClass 0x57c7a80, built at 0x8be52: size 0x20, one member
 * record at 0x16a2570): data, an array of bytes, at +0x10. */
class hkxBlob : public hkReferencedObject
{
  public:
    hkxBlob(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag), data(flag) {}

    /* Out of line (0x85c40, slot 0): the bytes given back; the deleting
     * destructor (0x85ca0, slot 1) runs it and frees through the class's
     * delete. */
    virtual ~hkxBlob();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkArray<u8> data;
};

class hkxSparselyAnimatedEnum : public hkxSparselyAnimatedInt
{
  public:
    hkxSparselyAnimatedEnum(hkFinishLoadedObjectFlag flag) : hkxSparselyAnimatedInt(flag) {}
};

/* hknpCharacterProxyCinfo: vtable 0x1696e90, finish callback FUN_00040510;
 * 0xb0 bytes (its deleting destructor's size). */
class hknpCharacterProxyCinfo : public hkReferencedObject
{
  public:
    hknpCharacterProxyCinfo(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    /* Empty (the shared 0x3b640); the deleting destructor 0x404b0, before
     * the finish callback, is the body the vtable of the one 0xb0-byte
     * class that cites it holds (D15). */
    virtual ~hknpCharacterProxyCinfo();

    static void operator delete(void *object, unsigned long numBytes);

    u8 unknownC[0xa4];
};

class hknpTyremarksWheel;

/* hknpTyremarksInfo: vtable 0x169a080, finish callback FUN_00042a20; from
 * its record table at 0x1697b80 (hkClass 0x57c1210, 0x28 bytes):
 * minTyremarkEnergy and maxTyremarkEnergy at +0xc and +0x10, tyremarksWheel
 * (an array of pointers to hknpTyremarksWheel) at +0x18. */
class hknpTyremarksInfo : public hkReferencedObject
{
  public:
    hknpTyremarksInfo(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), tyremarksWheel(flag)
    {
    }

    /* Slot 6 (0x69150): a wheel's points as strips, left and right of each
     * point in turn, from the oldest. derived name. */
    void FUN_00069150(const hknpVehicleInstance *vehicle, int wheel, Vec4 *stripsOut) const;

    float minTyremarkEnergy;
    float maxTyremarkEnergy;
    hkArray<hknpTyremarksWheel *> tyremarksWheel;
};

/* hknpTyremarksWheel: vtable 0x1697af0, finish callback FUN_00042a50. */
/* hknpTyremarkPoint (hkClass 0x57c1190, size 0x20, record table at
 * 0x1697b30): pointLeft and pointRight. */
struct hknpTyremarkPoint {
    Vec4 pointLeft;
    Vec4 pointRight;
};

/* From its record table at 0x1697c00: currentPosition (int) at +0xc, in
 * hkReferencedObject's tail, numPoints (int) at +0x10, tyremarkPoints (an
 * array of hknpTyremarkPoint) at +0x18. */
class hknpTyremarksWheel : public hkReferencedObject
{
  public:
    hknpTyremarksWheel(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), tyremarkPoints(flag)
    {
    }

    /* Out of line (0x42900, slot 0): the points given back. */
    virtual ~hknpTyremarksWheel();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    /* A point counted from the oldest: the points are a ring that starts
     * at currentPosition (inline in 0x69150). derived name. */
    const hknpTyremarkPoint &getTyremarkPoint(int point) const
    {
        return tyremarkPoints.data[(currentPosition + point) % numPoints];
    }

    int currentPosition;
    int numPoints;
    hkArray<hknpTyremarkPoint> tyremarkPoints;
};

/* hkcdFourAabb (hkClass 0x57ba890 built at 0x1e100: 0x60 bytes, six
 * member records at 0x168fc60): four boxes as six vectors of their
 * bounds, lx, hx, ly, hy, lz and hz. */
struct hkcdFourAabb {
    /* All four boxes empty: the minima the largest value, the maxima its
     * negation (rows 33 and 38 of the vector constants; the simd tree's
     * finish constructor, 0x21a7f). derived name. */
    void setEmpty(); /* derived name */

    hkVector4 lx;
    hkVector4 hx;
    hkVector4 ly;
    hkVector4 hy;
    hkVector4 lz;
    hkVector4 hz;
};

extern const hkClassMember D_168fc60[]; /* derived name: hkcdFourAabb's records */
extern const hkClassEnum D_168fdb0[];   /* derived name: its one enum */

/* hkcdSimdTree (type info 0x57bb3e0, vtable 0x1690d60): 0x18 bytes, its
 * nodes an hkArray at +8 (member record 0x1690270). Its finish constructor
 * (0x21a20) is out of line: the type info's finish callback FUN_0001f360
 * jumps to it, and hknpExternMeshShapeData's finish constructor calls it on
 * its member. */
class hkcdSimdTree
{
  public:
    /* hkcdSimdTree::Node (hkClass 0x57bb310 built at 0x1f407 under the name
     * hkcdSimdTreeNode: 0x70 bytes over hkcdFourAabb, one member record at
     * 0x16901e0): four hkUint32 of data at +0x60. */
    struct Node : public hkcdFourAabb {
        /* Empty boxes and no data (derived name). */
        void clear()
        {
            setEmpty();
            data[0] = data[1] = data[2] = data[3] = 0;
        }

        u32 data[4];
    };

    /* Out of line (0x21a20): a finished tree has its two root nodes at
     * least, cleared when it had fewer. */
    hkcdSimdTree(hkFinishLoadedObjectFlag flag);

    /* A new tree: its two root nodes, cleared (inline in 0xea610). */
    hkcdSimdTree()
    {
        clear();
    }

    /* Back to the two root nodes, cleared. derived name. */
    void clear()
    {
        nodes.setSize(2);
        nodes[0].clear();
        nodes[1].clear();
    }

    /* Inline: the nodes' storage given back. hknpExternMeshShapeData's
     * destructor (0x35310) holds it; 0x21920 (slot 0) is the copy kept
     * beside the finish constructor, and the deleting destructor (0x21980,
     * slot 1) frees the 0x18 bytes on the thread's heap. */
    virtual ~hkcdSimdTree() {}

    static void operator delete(void *object, unsigned long numBytes);

    hkArray<Node> nodes;
};

/* Polymorphic classes whose finish constructors are out of line, each
 * storing the class's vtable (and clearing a few members): */
class hkSkinnedRefMeshShape;     /* 0xaa660, vtable 0x16a38c0 */
class hkMemoryMeshShape;         /* 0x2a940, vtable 0x1692540 */
class hkMemoryMeshMaterial;      /* 0xaccf0, vtable 0x16a3920 */
class hkStorageSkinnedMeshShape; /* 0xae680, vtable 0x16a3b00 */
class hkMemoryMeshVertexBuffer;  /* 0x274e0, vtable 0x16921b0 */
class hknpDynamicCompoundShape;  /* 0x469a0, vtable 0x1697ef0 */
class hknpMaskedShape;           /* 0x37b90, vtable 0x1693a90 */

void FUN_0001cf40(hkcdShape *self, hkFinishLoadedObjectFlag flag); /* derived name */

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
/* hkMeshBoneIndexMapping (type info "!hkMeshBoneIndexMapping", hkClass
 * 0x57bd388 built by 0x24490): an array of 16-bit indices at +0. The
 * cleanup callback of its type info (0x24440) frees it. */
struct hkMeshBoneIndexMapping {
    static void FUN_00024440(void *object); /* derived name */

    hkArray<s16> mapping; /* derived name */
};

/* hkMeshSectionCinfo (type info "!hkMeshSectionCinfo", hkClass 0x57bd7a0
 * built by 0x26600, 0x40 bytes, nine members whose records 0x26600 writes
 * at 0x57bd9e0): vertexBuffer and material (pointers) at +0 and +8,
 * boneMatrixMap (struct hkMeshBoneIndexMapping) at +0x10, primitiveType
 * (enum of hkUint8) at +0x20, numPrimitives (hkInt32) at +0x24, indexType
 * (enum of hkUint8) at +0x28, indices (pointer, not serialized) at +0x30,
 * vertexStartIndex and transformIndex (hkInt32) at +0x38 and +0x3c. The
 * cleanup callback of its type info (0x265a0) destroys it in place. */
struct hkMeshSectionCinfo {
    static void FUN_000265a0(void *object); /* derived name */

    void *vertexBuffer;
    void *material;
    hkMeshBoneIndexMapping boneMatrixMap;
    u8 primitiveType;
    int numPrimitives;
    u8 indexType;
    const void *indices;
    int vertexStartIndex;
    int transformIndex;
};

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

    /* derived name: the elements put in canonical order (0x27180). */
    void FUN_00027180();

    struct Element;

    /* derived name: an element added at the end, unless the format is full
     * (32) or already has one of its usage and sub-usage (0x271f0, which
     * inlines 0x27130; called at 0x25a82). */
    void FUN_000271f0(const Element &element);

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

/* derived name: the sort of a range of elements under an order (0x26f20,
 * recursive: a quick sort from the middle element). */
void FUN_00026f20(hkVertexFormat::Element *elements, int low, int high,
                  bool (*less)(const hkVertexFormat::Element &a, const hkVertexFormat::Element &b));

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

    /* What a lock asks for (derived names): the first vertex and the number
     * of vertices (all from the first when negative, 0x279b0), the access
     * flags at +0xc (FLAG_WRITE, 2, makes the lock a write lock). */
    struct LockInput {
        int startVertex; /* derived name */
        int numVertices; /* derived name */
        u8 unknown8[4];
        int lockFlags; /* derived name */
    };

    /* What a partial lock asks for besides (derived names): the number of
     * elements, their indices into the format (0x27a40 reads them) and each
     * one's access flags (the multiple buffer's slot 10, 0x25e27). */
    struct PartialLockInput {
        int numLockElements;    /* derived name */
        int elementIndices[32]; /* derived name */
        u8 lockFlags[32];       /* derived name */
    };

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
    /* hkMultipleVertexBuffer::LockedElement (records from 0x1691a30, 7 bytes):
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

    /* hkMultipleVertexBuffer::ElementInfo (records from 0x16919e0, 2
     * bytes): where an element of the format comes from. */
    struct ElementInfo {
        u8 vertexBufferIndex;
        u8 elementIndex;
    };

    /* hkMultipleVertexBuffer::VertexBufferInfo (hkClass 0x57bcda0, built
     * at 0x23975: 0x18 bytes, records from 0x16917a0). */
    struct VertexBufferInfo {
        hkMeshVertexBuffer *vertexBuffer;
        void *lockedVertices; /* not serialized */
        hkBool isLocked;
    };

    hkMultipleVertexBuffer(hkFinishLoadedObjectFlag flag);
    virtual ~hkMultipleVertexBuffer();

    const hkClass *getClassType() const;                /* vtable slot 3, FUN_000238c0 */
    bool FUN_00024bd0() const;                          /* vtable slot 6; derived name */
    void FUN_00024be0(hkVertexFormat &formatOut) const; /* vtable slot 7; derived name */
    int FUN_00024bf0() const;                           /* vtable slot 8; derived name */
    /* Slot 9 (0x25670): every element of the format locked, none when
     * the buffer is locked already (0); the locked elements set from the
     * element infos, then the lock proper (0x25700). derived names. */
    int FUN_00025670(const LockInput &input, LockedVertices &lockedVerticesOut);
    int FUN_00025700(const LockInput &input, LockedVertices &lockedVerticesOut);
    /* Slot 10 (0x25dc0): the elements the partial input names locked, none
     * when the buffer is locked already (0); a write lock when any of
     * their flags asks for writing. derived names. */
    int FUN_00025dc0(const LockInput &input, const PartialLockInput &partialInput,
                     LockedVertices &lockedVerticesOut);

    hkVertexFormat vertexFormat;
    hkArray<LockedElement> lockedElements;
    hkMeshVertexBuffer *lockedBuffer;
    hkArray<ElementInfo> elementInfos;
    hkArray<VertexBufferInfo> vertexBufferInfos;
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
struct hkMeshSection {
    u8 unknown0[0x28];
    /* The section's material (hkMemoryMeshShape's slot 7 keeps a reference
     * to it). derived name. */
    class hkMeshMaterial *material;
    u8 unknown30[8];
    int sectionIndex; /* derived name */

    /* The enum PrimitiveType (its hkClassEnum 0x1692178 beside
     * MeshSectionIndexType's, after the class name's string at 0x14b7f7f):
     * names and values from its items at 0x1692100. Fields not typed yet. */
    enum PrimitiveType {
        PRIMITIVE_TYPE_UNKNOWN,
        PRIMITIVE_TYPE_POINT_LIST,
        PRIMITIVE_TYPE_LINE_LIST,
        PRIMITIVE_TYPE_TRIANGLE_LIST,
        PRIMITIVE_TYPE_TRIANGLE_STRIP
    };
};

/* 0xaa570 (called by FUN_0002abd0): the number of indices numPrimitives
 * primitives of the type take, 0 for an unknown type. derived name. */
int FUN_000aa570(hkMeshSection::PrimitiveType primitiveType, int numPrimitives); /* derived name */

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
    /* Set by the memory buffer's lock, whose elements share one vertex
     * stride (0x279ca). derived name. */
    hkBool isInterleaved;
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

    /* Out of line (0x27770, slot 0): the vertex memory given back; the
     * deleting destructor (0x276d0, slot 1) frees at the recorded size,
     * 0x1b0 by default. */
    virtual ~hkMemoryMeshVertexBuffer();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

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
    /* Slot 9 (0x279a0): every element locked over the vertex memory from
     * the first vertex asked for, unless the buffer is locked already (0).
     * derived name. */
    int FUN_000279a0(const hkMeshVertexBuffer::LockInput &input,
                     hkMeshVertexBuffer::LockedVertices &lockedVerticesOut);
    /* Slot 10 (0x27a40): the elements the partial input names locked over
     * the vertex memory from the first vertex asked for, unless the buffer
     * is locked already (0). derived name. */
    int FUN_00027a40(const hkMeshVertexBuffer::LockInput &input,
                     const hkMeshVertexBuffer::PartialLockInput &partialInput,
                     hkMeshVertexBuffer::LockedVertices &lockedVerticesOut);
    void FUN_00027b10(); /* vtable slot 15; derived name */

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

/* hkMeshBody's one enum, PickDataIdentifier (its records at 0x1691e50). */
extern const hkClassEnum D_1691e50[]; /* derived name */

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
struct hkcdPlanarGeometryPrimitivesPlane {
    /* The members from the records at 0x168f9a0 (hkClass 0x57ba490, built
     * at 0x1d98d), the second not serialized. */
    s64 iEqn[4];
    s64 dEqn[4];
};

extern const hkClassMember D_168f9a0[]; /* derived name: the plane's records */

void FUN_00095ab0(hkcdPlanarGeometryPrimitivesPlane *self); /* derived name */

/* The finish callback of the plane's type info (0x1d900). */
void FUN_0001d900(void *object, int finishing); /* derived name */

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
 * constructor (one shared body) and an out-of-line destructor. Its members
 * are not typed yet. */
struct hkcdStaticMeshTreeBase {
    /* hkcdStaticMeshTreeBase::Connectivity (type info 0x57bc2e0, size 0x30;
     * members from the records at 0x1690b30): headers, localLinks
     * (hkUint8) and globalLinks (hkUint32). Its type info's cleanup
     * (0x209b0) destroys it in place, the arrays from the last. */
    struct Connectivity {
        /* hkcdStaticMeshTreeBase::Connectivity::SectionHeader (8 bytes);
         * its members are not typed yet. */
        struct SectionHeader {
            u8 unknown0[8];
        };

        hkArray<SectionHeader> headers;
        hkArray<u8> localLinks;
        hkArray<u32> globalLinks;
    };

    u8 unknown0[0x70];
};

void FUN_000209b0(void *object); /* derived name */

void FUN_000a9140(hkcdStaticMeshTreeBase *self, hkFinishLoadedObjectFlag flag); /* derived name */
void FUN_00020700(hkcdStaticMeshTreeBase *self);                                /* derived name */

/* The library's table of vector constants (derived name), extern, reached
 * through its GOT slot: row 33 (+0x210) holds the largest float less a few
 * units in each lane (0x7f7fffee), row 34 (+0x220) a large value
 * (0x5f7ffff0, about 1.8e19), row 38 row 33 negated. 58 rows: the
 * type names' strings start at row 58 (0x14b2400). Its size lets LICM hoist
 * a row's load out of a loop where the loop reads it only under a branch
 * (hknpLodShape's 0x68500 keeps the half in a register). */
extern const Vec4 D_14b2060[58];

inline void hkcdFourAabb::setEmpty()
{
    lx.quad = D_14b2060[33];
    ly.quad = D_14b2060[33];
    lz.quad = D_14b2060[33];
    hx.quad = D_14b2060[38];
    hy.quad = D_14b2060[38];
    hz.quad = D_14b2060[38];
}

/* hkPackedVector3 (hkClass 0x57b98e0, built at 0x1560d: 8 bytes, one
 * member record at 0x168e770, values, four hkInt16 aligned to 8): a
 * vector as three 16-bit mantissas over a shared exponent in the fourth. */
struct alignas(8) hkPackedVector3 {
    /* The vector packed (0x92ef0; FUN_00026100 packs two). derived
     * name. */
    void FUN_00092ef0(const Vec4 &v);

    s16 values[4];
};

/* Two in every lane (derived name): the Newton step of the reciprocal. */
extern const Vec4 D_14b4380;

/* One half and three in every lane (derived names): the Newton step of the
 * reciprocal square root. */
extern const Vec4 D_14b4360;
extern const Vec4 D_14b4390;

/* Two pi, pi and four over pi in every lane (derived names): the sine
 * approximation's wrap and slope (0x1a012 to 0x1a042). */
extern const Vec4 D_14b42f0;
extern const Vec4 D_14b4300;
extern const Vec4 D_14b4320;

/* A vector's length over x, y and z, as Havok's hkVector4::length<3> is on
 * this platform at its default accuracy: the square root of the squared
 * length taken as the squared length times its reciprocal square root (an
 * estimate refined by one Newton step), zero where the squared length is
 * not positive (the vehicle's speeds, 0x165890 and 0x165910). derived
 * name. */
inline Vec4 length3(const Vec4 &v)
{
    const Vec4 lengthSquared = _mm_dp_ps(v, v, 0x7F);
    const Vec4 e = _mm_rsqrt_ps(lengthSquared);
    const Vec4 invLength =
        _mm_mul_ps(_mm_mul_ps(e, D_14b4360),
                   _mm_sub_ps(D_14b4390, _mm_mul_ps(lengthSquared, _mm_mul_ps(e, e))));
    return _mm_andnot_ps(_mm_cmple_ps(lengthSquared, _mm_setzero_ps()),
                         _mm_mul_ps(lengthSquared, invLength));
}

/* A vector scaled to unit length over x, y and z by the same reciprocal
 * square root, zero where the squared length is not positive, as Havok's
 * hkVector4::normalize<3> is on this platform at its default accuracy (the
 * scaled convex shape's slot 17, 0x16ad80). derived name. */
inline Vec4 normalized3(const Vec4 &v) /* derived name */
{
    const Vec4 lengthSquared = _mm_dp_ps(v, v, 0x7F);
    const Vec4 e = _mm_rsqrt_ps(lengthSquared);
    const Vec4 invLength =
        _mm_mul_ps(_mm_mul_ps(e, D_14b4360),
                   _mm_sub_ps(D_14b4390, _mm_mul_ps(lengthSquared, _mm_mul_ps(e, e))));
    return _mm_mul_ps(v, _mm_andnot_ps(_mm_cmple_ps(lengthSquared, _mm_setzero_ps()), invLength));
}

/* A unit vector perpendicular to v, w zero: v's x, y and z turned a
 * quarter about z, or about y when that is longer, then normalized (0x1a360;
 * called at 0x73ef9). derived name. */
void FUN_0001a360(Vec4 &perpendicularOut, const Vec4 &v); /* derived name */

/* A vector's reciprocal, zero where a lane is zero, as Havok's
 * hkVector4::setReciprocal with its set-zero mode is on this platform: the
 * estimate refined by one Newton step, r(2 - vr), the lanes equal to zero
 * masked off (0x5f530; FUN_00187750's 0x188540 spells it out). derived
 * name. */
inline Vec4 reciprocalOrZero(const Vec4 &v) /* derived name */
{
    const Vec4 r = _mm_rcp_ps(v);
    const Vec4 refined = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(v, r)));
    return _mm_andnot_ps(_mm_cmpeq_ps(v, _mm_setzero_ps()), refined);
}

/* Four hkHalf read as a vector: each into the top 16 bits of its lane,
 * the 8 bytes loaded as one double (`vmovsd; vpunpcklwd` from zero,
 * 0x5f56a). derived name. */
inline Vec4 loadHalves(const hkHalf *halves) /* derived name */
{
    const __m128i packed = _mm_castpd_si128(_mm_load_sd(reinterpret_cast<const double *>(halves)));
    return _mm_castsi128_ps(_mm_unpacklo_epi16(_mm_setzero_si128(), packed));
}

/* A vector stored as four hkHalf, rounded by row 47 of the constant table
 * (1 + 1/256 in every lane) and truncated as hkHalf::setReal does, the 8
 * bytes stored as one double (`vmovlpd`, 0x5f592). derived name. */
inline void storeHalves(hkHalf *halves, const Vec4 &v) /* derived name */
{
    __m128i bits = _mm_srai_epi32(_mm_castps_si128(_mm_mul_ps(v, D_14b2060[47])), 16);
    bits = _mm_packs_epi32(bits, bits);
    _mm_storel_pd(reinterpret_cast<double *>(halves), _mm_castsi128_pd(bits));
}

inline void hkMatrix3::setIdentity()
{
    col0 = D_14b2060[29];
    col1 = D_14b2060[30];
    col2 = D_14b2060[31];
}

inline void hkTransform::setIdentity()
{
    rotation.setIdentity();
    translation = _mm_setzero_ps();
}

/* The identity transform, rows 29 to 32 of the constant table read as one
 * (hknpShape's slot 28 default asks its bounds under it, 0x6fc9c). derived
 * name. */
inline const Mat4 &identityTransform() /* derived name */
{
    return reinterpret_cast<const Mat4 &>(D_14b2060[29]);
}

struct hkAabb;
/* The bounds handed on with both of slot 28's arguments (0x168230; the
 * shapes' slot 28 default calls it). derived names. */
void FUN_00168230(const void *argument1, const hkAabb &aabb, void *argument2); /* derived name */

/* hkQuaternion (the reflection's TYPE_QUATERNION, its name a string of the
 * executable): four floats in one vector. Field name derived. */
struct hkQuaternion {
    /* Whether the four lanes are ordered numbers and the length's square
     * is within epsilon of one (0x1a180; the game asks it at 0xeaeda1 and
     * 0xeaf9f0 and tests the int). Row 3 of the constant table is one in
     * each lane. derived name. */
    int FUN_0001a180(float epsilon) const;

    /* The rotation about a unit axis by an angle (every lane the angle),
     * the sine and cosine approximated (0x19ff0; the caller at 0x17885b).
     * derived name. */
    void FUN_00019ff0(const Vec4 &axis, const Vec4 &angle);

    /* The quaternion of a rotation (inline in 0xbf40; out of line at
     * 0x1a1c0): from the trace when it is positive, otherwise from the
     * largest diagonal element, each lane written into an array on the
     * stack and the four read back as one vector. derived name. */
    void setFromRotation(const hkMatrix3 &r);
    /* The same, out of line (0x1a1c0). derived name. */
    void FUN_0001a1c0(const hkMatrix3 &r);

    /* Scaled to unit length by the reciprocal square root refined by one
     * Newton step, over all four lanes (0xc0b2). derived name. */
    void normalize();

    Vec4 vec; /* derived name */
};

/* hkSweptTransformf (hkClass 0x57b94e0, built at 0x149fd: size 0x50, no
 * parent, five member records at 0x168e4e0). */
struct hkSweptTransformf {
    Vec4 centerOfMass0;
    Vec4 centerOfMass1;
    hkQuaternion rotation0;
    hkQuaternion rotation1;
    Vec4 centerOfMassLocal;
};

class hknpShape;
struct hknpWorld;

/* hknpCharacterRigidBodyCinfo: vtable 0x1692f70, finish callback FUN_000361c0;
 * 0x90 bytes (its deleting destructor's size); members from the record
 * table at 0x1692fb0. */
class hknpCharacterRigidBodyCinfo : public hkReferencedObject
{
  public:
    hknpCharacterRigidBodyCinfo(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    /* Out of line (0x176380): a 75 kg character without friction, upright
     * on y, climbing up to 60 degrees, with no shape, world or body yet. */
    hknpCharacterRigidBodyCinfo();

    /* Empty (the shared 0x1c1e0); the deleting destructor 0x36160, beside
     * the finish callback, is the body the vtables of the 0x90-byte
     * reference-counted classes with empty destructors cite (D15). */
    virtual ~hknpCharacterRigidBodyCinfo();

    static void operator delete(void *object, unsigned long numBytes);

    u32 collisionFilterInfo;
    const hknpShape *shape;
    hknpWorld *world;
    Vec4 position;
    hkQuaternion orientation;
    float mass;
    float dynamicFriction;
    float staticFriction;
    float weldingTolerance;
    hknpBodyId reservedBodyId;
    u8 additionMode;
    u8 activationMode;
    Vec4 up;
    float maxSlope;
    float maxForce;
    float maxSpeedForSimplexSolver;
    float supportDistance;
    float hardSupportDistance;
};

/* A scalar square root in the SSE unit (`vsqrtss` of a vector with the
 * upper lanes zero). derived name. */
inline float sqrtScalar(float value) /* derived name */
{
    return _mm_cvtss_f32(_mm_sqrt_ss(_mm_set_ss(value)));
}

inline void hkQuaternion::setFromRotation(const hkMatrix3 &r)
{
    alignas(16) float lanes[4];
    const float trace = r(0, 0) + r(1, 1) + r(2, 2);
    if (trace > 0.0f) {
        const float s = sqrtScalar(trace + 1.0f);
        const float t = 0.5f / s;
        lanes[0] = (r(2, 1) - r(1, 2)) * t;
        lanes[1] = (r(0, 2) - r(2, 0)) * t;
        lanes[2] = (r(1, 0) - r(0, 1)) * t;
        lanes[3] = 0.5f * s;
    } else {
        const int next[] = {1, 2, 0};
        int i = 0;
        if (r(1, 1) > r(0, 0)) {
            i = 1;
        }
        if (r(2, 2) > r(i, i)) {
            i = 2;
        }
        const int j = next[i];
        const int k = next[j];
        const float s = sqrtScalar(r(i, i) - (r(j, j) + r(k, k)) + 1.0f);
        const float t = 0.5f / s;
        lanes[i] = 0.5f * s;
        lanes[3] = (r(k, j) - r(j, k)) * t;
        lanes[j] = (r(j, i) + r(i, j)) * t;
        lanes[k] = (r(k, i) + r(i, k)) * t;
    }
    vec = _mm_load_ps(lanes);
}

inline void hkQuaternion::normalize()
{
    const Vec4 lengthSquared = _mm_dp_ps(vec, vec, 0xff);
    const Vec4 e = _mm_rsqrt_ps(lengthSquared);
    const Vec4 invLength =
        _mm_mul_ps(_mm_mul_ps(e, D_14b4360),
                   _mm_sub_ps(D_14b4390, _mm_mul_ps(lengthSquared, _mm_mul_ps(e, e))));
    vec = _mm_mul_ps(vec, invLength);
}

inline void hkMatrix3::setRotation(const hkQuaternion &quaternion)
{
    const Vec4 q = quaternion.vec;
    const Vec4 q2 = _mm_add_ps(q, q);
    const Vec4 t0 = _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(3, 3, 3, 2)),
                               _mm_shuffle_ps(q2, q2, _MM_SHUFFLE(0, 1, 2, 2)));
    const Vec4 t1 = _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(1, 0, 0, 1)),
                               _mm_shuffle_ps(q2, q2, _MM_SHUFFLE(2, 2, 1, 1)));
    const Vec4 mask0 =
        _mm_castsi128_ps(_mm_setr_epi32(0, int(0x80000000), int(0x80000000), int(0x80000000)));
    const Vec4 mask1 =
        _mm_castsi128_ps(_mm_setr_epi32(int(0x80000000), 0, int(0x80000000), int(0x80000000)));
    const Vec4 a = _mm_xor_ps(t1, mask0);
    const Vec4 b = _mm_xor_ps(t0, mask1);
    const Vec4 one = D_14b2060[29];
    const Vec4 c = _mm_add_ss(b, one);
    col0 = _mm_sub_ps(c, a);
    const Vec4 xx2 = _mm_mul_ss(q, q2);
    const Vec4 f = _mm_sub_ps(_mm_xor_ps(c, mask0), _mm_move_ss(a, xx2));
    col1 = _mm_shuffle_ps(f, f, _MM_SHUFFLE(2, 3, 0, 1));
    const Vec4 g = _mm_movehl_ps(col0, col1);
    const Vec4 h = _mm_sub_ss(_mm_sub_ss(one, xx2), t1);
    col2 = _mm_shuffle_ps(g, h, _MM_SHUFFLE(2, 0, 3, 1));
}

/* The cross product of a and b in the first three lanes (derived name). */
inline Vec4 cross3(const Vec4 &a, const Vec4 &b) /* derived name */
{
    const Vec4 t = _mm_sub_ps(_mm_mul_ps(a, _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1))),
                              _mm_mul_ps(b, _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))));
    return _mm_shuffle_ps(t, t, _MM_SHUFFLE(3, 0, 2, 1));
}

/* A direction rotated by a quaternion: twice the sum of v by w * w - 1/2,
 * the imaginary part by its dot product with v and the cross product of the
 * imaginary part and v by w (row 18 of the constant table is one half in
 * each lane). Out of line at 0x11060, inline in hknpMotion's angular
 * velocity getter (0x157510). derived name. */
inline Vec4 rotatedDir(const hkQuaternion &q, const Vec4 &v) /* derived name */
{
    const Vec4 real = _mm_shuffle_ps(q.vec, q.vec, _MM_SHUFFLE(3, 3, 3, 3));
    const Vec4 q2minus1 = _mm_sub_ps(_mm_mul_ps(real, real), D_14b2060[18]);
    Vec4 result = _mm_mul_ps(v, q2minus1);
    const Vec4 imagDotDir = _mm_dp_ps(q.vec, v, 0x7f);
    result = _mm_add_ps(result, _mm_mul_ps(q.vec, imagDotDir));
    const Vec4 imagCrossDir = cross3(q.vec, v);
    result = _mm_add_ps(result, _mm_mul_ps(imagCrossDir, real));
    return _mm_add_ps(result, result);
}

/* The inverse rotation: the cross product taken the other way round (out
 * of line at 0x110c0, inline in the angular velocity setter 0x157630).
 * derived name. */
inline Vec4 rotatedInverseDir(const hkQuaternion &q, const Vec4 &v) /* derived name */
{
    const Vec4 real = _mm_shuffle_ps(q.vec, q.vec, _MM_SHUFFLE(3, 3, 3, 3));
    const Vec4 q2minus1 = _mm_sub_ps(_mm_mul_ps(real, real), D_14b2060[18]);
    Vec4 result = _mm_mul_ps(v, q2minus1);
    const Vec4 imagDotDir = _mm_dp_ps(q.vec, v, 0x7f);
    result = _mm_add_ps(result, _mm_mul_ps(q.vec, imagDotDir));
    const Vec4 imagCrossDir = cross3(v, q.vec);
    result = _mm_add_ps(result, _mm_mul_ps(imagCrossDir, real));
    return _mm_add_ps(result, result);
}

/* hkQTransformf (hkClass 0x57b7f68, built at 0x8ced: size 0x20, no parent,
 * its two members from the records at 0x168d1c0): a rotation as a
 * quaternion and a translation. */
struct hkQTransformf {
    hkQuaternion rotation;
    Vec4 translation;
};

/* hkQTransform (hkClass 0x57b99f0, built at 0x17daf: size 0x20, parent
 * hkQTransformf's, no members of its own). */
struct hkQTransform : public hkQTransformf {
    /* Whether two transforms are within epsilon of each other: the
     * quaternions in every lane, the second's sign flipped to the first's
     * side, and the translations in x, y and z (0x903d0; the world asks it
     * at 0x4c0e7 and 0x4f79a). derived name. */
    bool FUN_000903d0(const hkQTransform &other, float epsilon) const;
};

/* derived name: out = the point v under the transform, rotated by its
 * quaternion and moved by its translation (0x10fe0; called at 0x4f19a,
 * 0x5c660, 0x15743a and 0x15b2ef). */
void FUN_00010fe0(Vec4 &out, const hkQTransform &t, const Vec4 &v);

/* hknpMassDistribution (hkClass 0x57c24f8, 0x30 bytes, no parent, built at
 * 0x69aa0 from the record table 0x169a860): centerOfMassAndVolume
 * (hkVector4) at +0, majorAxisSpace (hkQuaternion) at +0x10, inertiaTensor
 * (hkVector4) at +0x20. */
struct hknpMassDistribution {
    hkVector4 centerOfMassAndVolume;
    hkQuaternion majorAxisSpace;
    hkVector4 inertiaTensor;
};

/* hknpRefMassDistribution (hkClass 0x57c2578, 0x40 bytes, parent
 * hkReferencedObject, one member in its record table 0x169a8e0): vtable
 * 0x169a820, finish callback FUN_00069a80. */
class hknpRefMassDistribution : public hkReferencedObject
{
  public:
    hknpRefMassDistribution(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    /* Empty; the deleting destructor is 0x1ba80, the body every vtable of a
     * 0x40-byte reference-counted class with an empty destructor cites
     * (D15: no citing class has other members beside it, and this vtable is
     * the lowest-address citer). */
    virtual ~hknpRefMassDistribution();

    static void operator delete(void *object, unsigned long numBytes);

    hknpMassDistribution massDistribution;
};

/* hkAabb (hkClass 0x57b9c20): two hkVector4 bounds. Field names derived.
 * FUN_0014a1f0 empties it (min the largest value, max its negation, so any
 * point extends it); FUN_0014a220 makes it the whole space. */
struct hkAabb {
    /* Empty: the minimum the largest value, the maximum the most negative,
     * so that any point extends it (out of line at 0x14a1f0). derived
     * name. */
    void setEmpty()
    {
        Vec4 largest = D_14b2060[33];
        min = largest;
        max = _mm_xor_ps(largest, _mm_set1_ps(-0.0f));
    }

    /* Extended to hold a point. derived name. */
    void includePoint(const Vec4 &point)
    {
        min = _mm_min_ps(min, point);
        max = _mm_max_ps(max, point);
    }

    void FUN_0014a1f0(); /* derived name */
    void FUN_0014a220(); /* derived name */
    /* Whether the box is valid: min at most max in x, y and z, and both
     * corners ordered numbers there (0x184660; the geometry processing's
     * 0xb86e0 asks it). derived name. */
    bool FUN_00184660() const;

    Vec4 min; /* derived name */
    Vec4 max; /* derived name */
};

/* hkcdAdf (hkClass 0x57bb290, built at 0x1f260: size 0x80, seven members
 * from the records at 0x16900c0): an adaptive distance field over a box,
 * its nodes and its 16-bit voxels in two arrays. FUN_0001f1e0 is its type
 * info's cleanup callback. */
struct hkcdAdf {
    /* The cleanup callback (0x1f1e0): the field destroyed in place, its
     * voxels' storage given back, then its nodes'. derived name. */
    static void FUN_0001f1e0(void *object);

    float accuracy;
    hkAabb domain;
    Vec4 origin;
    Vec4 scale;
    float range[2];
    hkArray<u32> nodes;
    hkArray<u16> voxels;
};

extern const hkClassMember D_16900c0[]; /* derived name: hkcdAdf's records */

/* The nibble mask {15, 15, 15, 0} the box codecs read (a global copied
 * from 0x14c6be0 by its file's initializer 0xa9f80). derived name. */
extern Vec4 D_57c87c0;

/* derived name: a box inside a parent from four bytes of code, each byte's
 * high nibble moving the minimum in and its low nibble the maximum by the
 * nibble squared in 255ths of the parent's extent (0xa9f10; the geometry
 * code's 0xcf7af encodes with 0xa9da0 and decodes with it). */
void FUN_000a9f10(const hkAabb &parent, const u8 *codes, hkAabb &aabbOut); /* derived name */

/* derived name: the box around count points, their w lanes cleared when
 * there is one at least (0x93f30; the geometry processing calls it at
 * 0xb8628 and 0xba156). */
void FUN_00093f30(const Vec4 *points, int numPoints, hkAabb &aabbOut);

/* hkAabbUint32 (hkClass 0x57b9ca0 built at 0x1c6de: 0x20 bytes, six member
 * records at 0x168ebc0): a box in integer coordinates, min (three
 * hkUint32), expansionMin (three hkUint8) and expansionShift at +0xc, max,
 * expansionMax and shapeKeyByte at +0x1c. */
struct hkAabbUint32 {
    u32 min[3];
    u8 expansionMin[3];
    u8 expansionShift;
    u32 max[3];
    u8 expansionMax[3];
    u8 shapeKeyByte;
};

/* derived name: an AABB as integer coordinates that sort as its floats do
 * (each float's bits with the sign flipped, or every bit for a negative
 * one, halved; max one more), with the key in the fourth word of min
 * (0x184e20; the broad phase's 0x189540 converts every body's box). */
void FUN_00184e20(hkAabbUint32 *aabbOut, const hkAabb &aabb, int key);

/* derived name: how far inner lies inside outer, the smallest of the six
 * margins in every lane (negative when it sticks out); 0x14a2b0, called at
 * 0x75526 and 0x173aca. */
Vec4 FUN_0014a2b0(const hkAabb &inner, const hkAabb &outer);

/* derived name: whether inner lies in outer in x, y and z while the
 * counter still runs, the counter stepped down then, else set to 0xff
 * (0x14a2e0, called at 0x7514a and 0x1734ab). */
bool FUN_0014a2e0(const hkAabb &inner, const hkAabb &outer, u8 &counter);

/* derived name: the bounds of an AABB under a transform (0x94060: the
 * centre transformed, the half extents through the rotation's absolute
 * values); the compound and LOD shapes' slot 7 calls it on their own. */
void FUN_00094060(const Mat4 &transform, const hkAabb &aabb, hkAabb &aabbOut); /* derived name */

/* derived name: the same with every bound pushed out by a radius, a vector
 * the caller holds in memory (0x93fa0; the shapes' slot 7 asks it with a
 * zero radius, 0x12aabc). */
void FUN_00093fa0(const Mat4 &transform, const hkAabb &aabb, const Vec4 &extraRadius,
                  hkAabb &aabbOut); /* derived name */

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

    /* The 5-byte and 6-byte node codecs (type info "!hkcdStaticTree::
     * Codec3Axis5" and "...Codec3Axis6"; the sizes are the cleanup
     * callbacks' element sizes). */
    struct Codec3Axis5 {
        u8 unknown0[5];
    };

    struct Codec3Axis6 {
        u8 unknown0[6];
    };

    /* hkcdStaticTree::DefaultTreeStorage5 and DefaultTreeStorage6 (type
     * infos registered by 0x1e340): their nodes at +0 (derived name). The
     * cleanup callbacks of their type infos, 0x1e200 and 0x1e270, are also
     * the callbacks of the static trees over the dynamic storages 5 and 6.
     * derived names. */
    struct DefaultTreeStorage5 {
        static void FUN_0001e200(void *object);

        hkArray<Codec3Axis5> nodes; /* derived name */
    };

    /* 0x30 bytes (its hkClass, built at 0x1e5ac). */
    struct DefaultTreeStorage6 {
        DefaultTreeStorage6(hkFinishLoadedObjectFlag flag) : nodes(flag) {}

        /* A new one: no nodes, the domain empty. */
        DefaultTreeStorage6()
        {
            domain.setEmpty();
        }

        /* The class delete: back to the thread's heap at its size, no null
         * test (the static AABB tree's destructor, 0x22847; defined in
         * tlg_lib_unknown.h). */
        static void operator delete(void *object, unsigned long numBytes);

        static void FUN_0001e270(void *object);

        hkArray<Codec3Axis6> nodes; /* derived name */
        hkAabb domain;              /* derived name */
    };
};

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

    /* Out of line (0x227f0, slot 0; 0x22730, slot 1, the deleting one at
     * the recorded size): the tree deleted when the object owns it. */
    virtual ~hkcdStaticAabbTree();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkBool shouldDeleteTree;
    hkcdStaticTree::DefaultTreeStorage6 *treePtr;
};

/* hknpStaticCompoundShapeTree (hkClass 0x57be120 built at 0x347ba: 0x30
 * bytes over hkcdStaticTree::DefaultTreeStorage6, no members of its own). */
struct hknpStaticCompoundShapeTree : public hkcdStaticTree::DefaultTreeStorage6 {
    hknpStaticCompoundShapeTree(hkFinishLoadedObjectFlag flag)
        : hkcdStaticTree::DefaultTreeStorage6(flag)
    {
    }
};

/* hknpStaticCompoundShapeData (vtable 0x1692950, finish callback
 * FUN_00034440; hkClass 0x57be0a0 built at 0x3470d: 0x40 bytes, one member
 * record at 0x1692a80): aabbTree at +0x10. */
class hknpStaticCompoundShapeData : public hkReferencedObject
{
  public:
    hknpStaticCompoundShapeData(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), aabbTree(flag)
    {
    }

    /* Out of line (0x341d0, slot 0): the tree's nodes given back; the
     * deleting destructor (0x34230, slot 1) frees at the recorded size,
     * 0x40 by default. */
    virtual ~hknpStaticCompoundShapeData();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hknpStaticCompoundShapeTree aabbTree;
};

/* hkcdDynamicTree's default storage over its raw-ulong codec (type info
 * "!hkcdDynamicTreeDefaultDynamicStoragehkcdDynamicTreeCodecRawUlong_typename"
 * at 0x14b5e99, hkClass built by 0x1f750: size 0x18): the nodes, 64 bytes
 * each, at +0 (derived names). */
struct hkcdDynamicTree {
    /* The 64-byte codec, over CodecRaw<unsigned long> (records 0x1690040:
     * aabb, parent at +0x20 and children at +0x28, each an hkUlong). */
    struct CodecRawUlong {
        typedef hkUlong Index;

        u8 unknown0[0x40];
    };

    /* The 48-byte codec (type info "!hkcdDynamicTree::CodecRawUint"; the
     * size the cleanup callback 0x1f5f0's element size), over
     * hkcdDynamicTree::CodecRaw<unsigned int>, whose records (0x168ffc0)
     * name its members: a node's box, its parent and its two children, node
     * indices with 0 for none. A leaf has no first child and its data in
     * the second; a free node holds the next free one's index in its first
     * word (0x22600 links them). */
    struct CodecRawUint {
        typedef u32 Index;

        hkAabb aabb;
        u32 parent;
        u32 children[2];
    };

    /* The dynamic storage of a codec's nodes, with the members its parent
     * hkcdDynamicTree::DynamicStorage0 records (0x16902f0 for the raw-uint
     * codec): the nodes and the first free node. It has a constructor, so
     * a class over it lays its members out in its tail padding (the tree's
     * numLeaves at +0x14), and 3.3 types that base as a byte array, which
     * the stack protector counts as a large array (0xea610's frame). */
    template <typename CODEC> struct DefaultDynamicStorage {
        /* Empty: the nodes given back and none free (the stack trees of
         * 0xea610 store the size before the data, the constructor's stores
         * overwritten by the clear's). */
        DefaultDynamicStorage()
        {
            clear();
        }

        /* derived name. */
        void clear()
        {
            nodes.clearAndDeallocate();
            firstFree = 0;
        }

        /* The cleanup callback of its type info (0x1f650 for the raw-ulong
         * codec; the other storages with 64-byte nodes cite the same body).
         * derived name. */
        static void FUN_0001f650(void *object);
        /* The cleanup callback for the raw-uint codec (0x1f5f0; also the
         * callback of the dynamic storages over 48-byte nodes the same
         * registrations, 0x1f750 and 0x201a0, cite). derived name. */
        static void FUN_0001f5f0(void *object);

        /* numNodes more nodes linked into the free list, the array grown
         * as needed (0x22600 for the raw-uint codec): HK_FAILURE when it
         * cannot grow. derived name. */
        hkResult FUN_00022600(int numNodes);

        /* A node by its index, the index unsigned (zero-extended where
         * 0xea610 reaches a node; its free link is read through the
         * array's int index). derived name. */
        CODEC &getNode(typename CODEC::Index index)
        {
            return nodes.data[index];
        }

        hkArray<CODEC> nodes;
        typename CODEC::Index firstFree;
    };

    /* hkcdDynamicTree::DynamicStorage32 (hkClass 0x57bb890: 0x18 bytes, no
     * members of its own). */
    struct DynamicStorage32 : public DefaultDynamicStorage<CodecRawUint> {};

    /* hkcdDynamicTree::Tree over a storage (hkClass 0x57bbbb0 for
     * DynamicStorage32: 0x20 bytes, its three members from the records at
     * 0x1690530). */
    template <typename STORAGE> struct Tree : public STORAGE {
        /* An empty tree. */
        Tree() : numLeaves(0), path(0), root(0) {}

        u32 numLeaves;
        u32 path;
        u32 root;
    };

    /* hkcdDynamicTree::DefaultTree48Storage (hkClass 0x57bbb60 built at
     * 0x20246 onward: 0x20 bytes, no members of its own, its parent the
     * tree over DynamicStorage32). */
    struct DefaultTree48Storage : public Tree<DynamicStorage32> {
        /* The class delete: back to the thread's heap at its size, no null
         * test (the dynamic AABB tree's destructor, 0x9fd57; defined in
         * tlg_lib_unknown.h). */
        static void operator delete(void *object, unsigned long numBytes);

        /* The subtree of a node rebuilt (0x9db50; the extern mesh's builder
         * hands it the root, 1, 32 and 16). derived name. */
        hkResult FUN_0009db50(u32 node, int argument2, int argument3, int argument4);

        /* The tree's nodes copied into another storage from its root down,
         * the root at index 1 (0xbd460). derived name. */
        void FUN_000bd460(DefaultTree48Storage &treeOut) const;
    };
};

/* A static tree built from a dynamic tree's nodes (0xdea80; the extern
 * mesh's builder). derived name. */
void FUN_000dea80(hkcdStaticTree::DefaultTreeStorage6 *self,
                  const hkcdDynamicTree::DefaultTree48Storage &tree); /* derived name */

/* A simd tree built from a static tree (0xded30; the extern mesh's
 * builder). derived name. */
void FUN_000ded30(hkcdSimdTree *self,
                  const hkcdStaticTree::DefaultTreeStorage6 &tree); /* derived name */

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

    /* Out of line (0x9fd00, slot 0; 0x9fc40, slot 1, the deleting one at
     * the recorded size): the tree deleted when the object owns it. */
    virtual ~hkcdDynamicAabbTree();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkBool shouldDeleteTree;
    hkcdDynamicTree::DefaultTree48Storage *treePtr; /* the record's class, 0x57bbb60 */
};

/* hknpCompressedMeshShapeTree (type info 0x57be2f0, size 0xa0) and the
 * hkcdStaticMeshTree instance it is built on (type info 0x57be570) register
 * one finish callback; the finish constructor is the shared empty body. Its
 * static tree's domain (hkAabb) is at +0x10, as in every hkcdStaticTree
 * record table (0x168fde0 to 0x16900e8). */
struct hknpCompressedMeshShapeTree;

void FUN_000a9140(hknpCompressedMeshShapeTree *self,
                  hkFinishLoadedObjectFlag flag); /* derived name */

/* What the mesh tree's walk (0x104000, its per-section pass 0x104110) asks
 * of the query it is given (derived names): slot 2 whether a key is wanted
 * (called at 0x10454b), slot 3 the work on one primitive of a section, with
 * the walk's collector (0x10456f), slot 4 a vector the walk reads
 * (0x104a3f). The one query read so far is the compressed mesh shape's slot
 * 29 (0x127a50). */
class MeshTreeQuery00104000 /* derived name */
{
  public:
    virtual ~MeshTreeQuery00104000() {}

    virtual bool unknownVirtual2(u32 key) const = 0;
    virtual void unknownVirtual3(const void *section, int primitiveIndex, void *collector) = 0;
    virtual const Vec4 *unknownVirtual4() const = 0;
};

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

    /* The filter rebuilt for the tree (0xa9150): its storage given back,
     * then a bit for each of the tree's keys, all set. derived name. */
    void FUN_000a9150(hkArray<u32> &filter) const;

    /* A key's bit in the filter set or cleared (0xa9410), and read
     * (0xa9550); the key is the part below the shape's own bits. derived
     * names. */
    void FUN_000a9410(hkArray<u32> &filter, u32 key, bool enabled) const;
    bool FUN_000a9550(const hkArray<u32> &filter, u32 key) const;

    /* The walk over every section of the tree (0x104000) with a query: the
     * collector reset unless asked to keep it, its two arrays grown for the
     * sections' counts, each section passed (0x104110), and the collector
     * finished when asked. derived name. */
    void FUN_00104000(void *collector, MeshTreeQuery00104000 *query, bool keepCollector,
                      bool finishCollector, bool argument6) const;

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
 * low two bits are flags), each slot's slot 1 destroying it. */
struct Signal00093530 /* derived name */
{
    /* No slots (the finish constructors of the libraries clear their
     * unserialized signals). */
    Signal00093530() : slots(0) {}

    /* Out of line (0x93530): the slots deleted once the memory system is
     * up. Every holder's destructor calls it, member by member (the
     * libraries' 0x36c80, 0x61380 and 0x70f50, the shape signals' cleanup
     * 0x69960). */
    ~Signal00093530();

    /* Every slot of an object unsubscribed (0x933e0; the constraint
     * filter's and the character proxy's destructors, 0x159700 to
     * 0x176bd3): unlinked and deleted, or only flagged while the signal
     * fires. derived name. */
    void FUN_000933e0(const void *object);

    /* The slot of an object and a member-function pointer of size bytes
     * unsubscribed (0x93470; 0x155b10 drops its two): the first whose
     * object is the object and whose slot 2 recognizes the method, unlinked
     * and deleted, or flagged while the signal fires; whether one was.
     * derived name. */
    bool FUN_00093470(const void *object, const void *method, int size);

    /* An object's member function unsubscribed by its pointer, as the
     * subscriber passes it (0x155b10). derived name. */
    template <typename Object, typename Method> bool unsubscribe(Object *object, Method method)
    {
        return FUN_00093470(object, &method, sizeof(method));
    }

    void *slots; /* derived name */
};

/* Every slot deleted (its slot 1) and the list emptied (0x93570; the
 * destructor runs it once the memory system is up, FUN_00009c10). derived
 * name. */
void FUN_00093570(Signal00093530 *self); /* derived name */

/* A signal whose slots take no argument (derived name): fire calls slot 3
 * of each slot with nothing but the slot (0x416c5 and 0x37ca5 load no
 * argument register), defined after hkSlot. */
struct hkSignal0 : public Signal00093530 /* derived name */
{
    /* Every slot called in turn, the list marked firing meanwhile (the
     * low bit of the head); a slot whose link is flagged, before its call
     * or after it, is unlinked and deleted, its predecessor's flags kept.
     * The head's flags are cleared at the end (0x416ee). */
    void fire();
};

/* hknpShapeSignals, a reflected struct (hkClass at 0x57c2478); at most 16
 * bytes, the member after it in hknpMaskedShape sitting at +0x60: two
 * signals, each a pointer to its slot list (hknpScaledConvexShape's finish
 * constructor clears both; the shape watcher subscribes to the first, which
 * passes a byte of change flags (the masked shape's slot 32 fires it with 2,
 * 0x37e35), and the second, fired with no argument by the shapes'
 * destructors, hknpCompoundShape's at 0x416b0 and the masked shape's at
 * 0x37c90). Field names derived. */
/* A signal whose slots take one argument (derived name): fire calls slot 3
 * of each slot with the argument (the masked shape's slot 32 fires its
 * mutation signal with 2, 0x37e35); defined after hkSlot. */
template <typename P0> struct hkSignal1 : public Signal00093530 /* derived name */ {
    void fire(P0 p0);
};

struct hknpShapeSignals {
    hkSignal1<u8> shapeMutated; /* derived name */
    hkSignal0 shapeDestroyed;   /* derived name */
};

/* hknpShapeSignals's type info (0x57c24c8, built with its hkClass by
 * 0x69980): no finish callback, the cleanup callback FUN_00069960, size
 * 0x10. */
void FUN_00069960(void *object); /* derived name */

extern const hkClassMember D_169a770[]; /* derived name: hknpShapeSignals's records */
extern const hkClassEnum D_169a7f0[];   /* derived name: its one enum */

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
    /* The cleanup callback of its type info (0x3caa0, registered at
     * 0x3cb95): the shape's reference released. derived name. */
    static void FUN_0003caa0(void *object);

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

    /* The instance's leaf in the dynamic compound's tree: the low half of
     * the same word (0xf04b3). derived name. */
    int getLeafIndex() const
    {
        return u16(reinterpret_cast<const int *>(&transform.translation)[3]);
    }

    /* The first rotation column's w holds the instance's flags, written
     * with the same six bits from bit 24 set (`or 0x3f000000` at 0x3ece8
     * and 0x3ed73) and read with them masked off. derived names. */
    enum Flags {
        HAS_SCALE = 0x8,         /* derived name */
        FLIP_ORIENTATION = 0x10, /* derived name */
        SCALE_SURFACE = 0x20     /* derived name */
    };

    int getFlags() const /* derived name */
    {
        return reinterpret_cast<const int *>(&transform.rotation.col0)[3] & ~FLAGS_MASK;
    }

    void setFlags(int flags) /* derived name */
    {
        reinterpret_cast<int *>(&transform.rotation.col0)[3] = flags | FLAGS_MASK;
    }

    /* The scale set with the flags it implies, the surface flag for mode 0
     * (0x3ed10; the game calls it at 0xea5b04 and 0xea6214). derived
     * name. */
    void FUN_0003ed10(const Vec4 &newScale, int scaleMode);

    /* The inverse of the scaled transform (0x3ead0; the compound shapes'
     * queries from 0xd162e call it): the rotation transposed and each row
     * divided by the scale (its reciprocal refined once), the translation
     * carried back through it and negated. derived name. */
    void FUN_0003ead0(hkTransform &inverseOut) const;

    /* The free-list operations (the instances' array names the instance
     * as its own): a free instance has 0xff in the fifth byte of its
     * padding (the compound's add, 0x41223) and a live one zero there. */
    static hkBool32 isEmpty(const hknpShapeInstance &instance)
    {
        return instance.padding[4] != 0;
    }

    hkTransform transform;
    Vec4 scale;
    hkRefPtr<const hknpShape> shape;
    u16 shapeTag;
    u16 destructionTag;
    u8 padding[30];
};

extern const hkClassMember D_1695f50[]; /* derived name: hknpShapeInstance's records */
extern const hkClassEnum D_16960b0[];   /* derived name: its one enum */

/* derived name: what slot 24 of hknpShape does by default (0x169e50, 0x51d
 * bytes): bounds the shape by slot 7 under the fourth argument's transform
 * and tests the first argument's point (+0x20) and distance (+0x30) against
 * the bounds before the query proper. */
void FUN_00169e50(const void *argument1, const void *argument2, const hknpShape *shape,
                  const void *argument3, const void *argument4, void *argument5); /* derived name */

class hknpShapeKeyMask;

/* What a shape's mass properties are built from (derived names; the
 * second member's name is a string of the executable, m_inertiaFactor):
 * the quality at +0, the inertia factor at +4, the mass, or a density
 * negated, at +8 (the sphere's mass properties, 0x168340). */
struct MassConfig00168340 /* derived name */
{
    int quality;
    float inertiaFactor;
    float massOrNegativeDensity;
};

/* Mass properties with the inertia diagonalized (derived names): the
 * volume and the mass at +0 and +4, the centre of mass at +0x10, the
 * inertia's diagonal at +0x20 and the rotation to its principal axes at
 * +0x30. */
struct DiagonalizedMassProperties00168340 /* derived name */
{
    float volume;
    float mass;
    u8 unknown8[8];
    Vec4 centerOfMass;
    Vec4 inertiaTensor;
    Vec4 majorAxisSpace; /* a quaternion */
};

/* A solid sphere's mass properties, a failure for a radius not above zero
 * (0x168340; the sphere shape's mass properties at 0x3c694 fall back to
 * hknpShape's on a failure). derived name. */
hkResult FUN_00168340(const MassConfig00168340 &config, const Vec4 &center, float radius,
                      DiagonalizedMassProperties00168340 &propertiesOut); /* derived name */

/* What slot 21's fourth argument points to (derived names): 24 bytes, a
 * key at +0 (the convex shapes' slot 21 copies it out), the number of its
 * bits in use at +4 and a key mask at +8, which the masked shape replaces
 * with its own (0x380b0); the LOD shape reads a level of detail at +0x10
 * and appends its own bits to the key (0x68380). */
struct ShapeKeyQuery000380b0 /* derived name */
{
    u32 key;
    int keySize;
    const hknpShapeKeyMask *mask;
    int levelOfDetail;
    u8 unknown14[4];

    /* A sub-key appended below the key's bits in use: the key's leading
     * bits kept, the sub-key plus one in the next numBits and every bit
     * below it set (the LOD shape's 0x68380). derived name. */
    inline void appendSubKey(int subKey, int numBits); /* derived name */

    /* A copy of another with a different mask: the record copied whole,
     * then the mask set (the masked shape's 0x380b0 builds one in its
     * call). derived name. */
    ShapeKeyQuery000380b0(const ShapeKeyQuery000380b0 &other, const hknpShapeKeyMask *newMask)
    {
        *this = other;
        mask = newMask;
    }
};

/* The masks of a key's leading bits, by the number of bits (derived name):
 * none for 0, every bit for 32. */
extern const u32 D_14ca040[33];

inline void ShapeKeyQuery000380b0::appendSubKey(int subKey, int numBits)
{
    const int size = keySize; /* derived name */
    key = (key & D_14ca040[size]) | (((subKey + 1) << (32 - numBits - size)) - 1);
    keySize = size + numBits;
}

/* The arguments of the shapes' slot 27, a level of detail chosen for a
 * shape (derived names): a context whose vector at +0x70 scales the size,
 * and a query whose first pointer leads to a 16-bit size at +0x76
 * (hknpCompoundShape's 0x426b0, hknpLodShape's 0x68500). */
struct LodContext000426b0 /* derived name */
{
    u8 unknown0[0x70];
    Vec4 scale; /* derived name */
};

struct LodSource000426b0 /* derived name */
{
    u8 unknown0[0x76];
    u16 size; /* derived name */
};

struct LodQuery000426b0 /* derived name */
{
    const LodSource000426b0 *source; /* derived name */
};

/* A face's minimum half angle as slot 14 hands it out (derived names): one
 * byte, its low seven bits the angle in steps of pi / 255 (the polytope's
 * slot 17, 0x1540a0). It is a struct: every caller's out object sits on an
 * 8-byte boundary (0x45af0's at -0x30 below the guard at -0x28, 0x18f430's
 * two at -0x850 and -0x848, 0x1540a0's at -0x48 below a plane at -0x40),
 * the preferred alignment the data layout gives an aggregate (a0:0:64),
 * where a lone byte local takes any address (0x1887a0's at -0x171 to
 * -0x174). */
struct hknpFaceAngle /* derived name */
{
    u8 value; /* derived name */
};

/* Aligned to 16 bytes: its hkClass is 0x30 bytes with members to +0x28,
 * hknpDecoratorShape's 0x40 with members to +0x34 and hknpCompositeShape's
 * 0x60 with members to +0x54 (the hkClass sizes, built at 0x38fd9,
 * 0x38b95 and 0x71755). */
class alignas(16) hknpShape : public hkReferencedObject
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

    /* A new shape of a dispatch type: no properties, key bits, user data,
     * radius or flags, stored in this order (inlined in hknpDecoratorShape's
     * 0x3b0a0, 0x3b0aa to 0x3b0d3). */
    hknpShape(u8 dispatchType_) : properties(0)
    {
        dispatchType = dispatchType_;
        numShapeKeyBits = 0;
        userData = 0;
        convexRadius = 0.0f;
        flags = 0;
    }

    virtual ~hknpShape();

    /* The reference-counted class delete (freeReferencedObject in
     * tlg_lib_unknown.h): the shapes' deleting destructors free through it
     * (hknpShape's own 0x6faa0, the capsule's 0x72ec0). */
    static void operator delete(void *object, unsigned long numBytes);

    /* Slots 5 and 6: the defaults (0x6e3d0, 0x6e510) report "Not
     * implemented" and return 22 and 0. */
    virtual int unknownVirtual5() const;
    virtual int unknownVirtual6() const;
    /* Slot 7: the shape's bounds under a transform. */
    virtual void unknownVirtual7(const Mat4 &transform, hkAabb &aabbOut) const;
    /* Slot 8: the shape's signals (the default 0x42d0 has none; the shape
     * watcher's 0x155b10 unsubscribes from both). */
    virtual hknpShapeSignals *unknownVirtual8() const;
    virtual int unknownVirtual9() const;
    virtual const Vec4 *unknownVirtual10(Vec4 *buffer, int bufferSize) const;
    virtual void unknownVirtual11(const Vec4 &direction, Vec4 *vertexOut) const;
    virtual void unknownVirtual12(const u8 *ids, int numIds, Vec4 *verticesOut) const;
    virtual int unknownVirtual13() const;
    virtual void unknownVirtual14(int faceIndex, Vec4 *planeOut, hknpFaceAngle *angleOut) const;
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
    /* Slot 20: a new key mask for the shape (hknpStaticCompoundShape's
     * 0xdea30 builds one; the decorator's forwards). */
    virtual hknpShapeKeyMask *unknownVirtual20() const;
    virtual int unknownVirtual21(void *argument1, int argument2, int argument3,
                                 const ShapeKeyQuery000380b0 &argument4) const;
    /* Slot 22: a leaf of the shape by a path of shape keys, into an output
     * (the LOD shape's 0x68440 hands its level the keys shifted by its key
     * bits, at most ten of them). derived names. */
    virtual void unknownVirtual22(const u32 *keys, int numKeys, void *argument3) const;
    virtual void unknownVirtual23(const void *argument1, const void *argument2,
                                  const void *argument3, const void *argument4,
                                  void *argument5) const;
    /* Slot 24: five arguments, which the default (FUN_0006fa60) hands on
     * with the shape third to FUN_00169e50; its fourth holds at +0x20 the
     * transform slot 7 takes. */
    virtual void unknownVirtual24(const void *argument1, const void *argument2,
                                  const void *argument3, const void *argument4,
                                  void *argument5) const;
    /* Slots 25 and 26: seven arguments, the fifth a record of slot 23's
     * kind, which the masked shape copies with its mask (0x37e90, 0x37f50). */
    virtual void unknownVirtual25(const void *argument1, const void *argument2,
                                  const void *argument3, const void *argument4,
                                  const void *argument5, const void *argument6,
                                  void *argument7) const;
    virtual void unknownVirtual26(const void *argument1, const void *argument2,
                                  const void *argument3, const void *argument4,
                                  const void *argument5, const void *argument6,
                                  void *argument7) const;
    virtual int unknownVirtual27(const LodContext000426b0 &context, const LodQuery000426b0 &query,
                                 int currentLod) const;
    virtual void unknownVirtual28(const void *argument1, void *argument2) const;
    /* Slot 28's default (0x6fc70, kept by nine shape vtables): the shape's
     * slot 7 bounds under a fixed transform, handed with both arguments to
     * FUN_00168230; the sphere's slot 28 falls back to it. derived name. */
    void FUN_0006fc70(const void *argument1, void *argument2) const;
    /* Slot 29: a value the masked shape's override (0x38130) hands back
     * from the core shape's. */
    virtual int unknownVirtual29(const void *argument1, void *argument2) const;
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
    /* Destroyed and freed by the destructor when the shape was allocated
     * (a size in the high half of +8), not loaded in place. derived
     * name. */
    hkRefCountedProperties *properties;
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
    /* 0x3b0a0 (called at 0x16a6bb): a decorator of the shape's dispatch
     * type; coreShapeSize is left unset. */
    hknpDecoratorShape(const hknpShape *coreShape_);

    hknpDecoratorShape(hkFinishLoadedObjectFlag flag); /* 0x3b0f0 */

    virtual ~hknpDecoratorShape();

    void FUN_0003b120(const Mat4 &transform,
                      hkAabb &aabbOut) const;                     /* vtable slot 7; derived name */
    hknpShapeSignals *FUN_0003b280() const;                       /* vtable slot 8; derived name */
    int FUN_0003b130() const;                                     /* vtable slot 9; derived name */
    const Vec4 *FUN_0003b140(Vec4 *buffer, int bufferSize) const; /* vtable slot 10; derived name */
    void FUN_0003b150(const Vec4 &direction,
                      Vec4 *vertexOut) const; /* vtable slot 11; derived name */
    void FUN_0003b160(const u8 *ids, int numIds,
                      Vec4 *verticesOut) const; /* vtable slot 12; derived name */
    int FUN_0003b170() const;                   /* vtable slot 13; derived name */
    void FUN_0003b180(int faceIndex, Vec4 *planeOut,
                      hknpFaceAngle *angleOut) const; /* vtable slot 14; derived name */
    int FUN_0003b190(int faceIndex, Vec4 *planeOut,
                     Vec4 *verticesOut) const; /* vtable slot 15; derived name */
    int FUN_0003b1a0(const void *argument1, const void *argument2, void *argument3, bool argument4,
                     int argument5) const; /* vtable slot 16; derived name */
    float FUN_0003b1c0() const;            /* vtable slot 17; derived name */
    void FUN_0003b1d0(const void *argument1,
                      void *argument2) const; /* vtable slot 18; derived name */
    void FUN_0003b1e0(const void *argument1, const void *argument2, int argument3, float argument4,
                      void *argument5, void *argument6) const; /* vtable slot 19; derived name */
    hknpShapeKeyMask *FUN_0003b1f0() const;                    /* vtable slot 20; derived name */
    int
    FUN_0003b200(void *argument1, int argument2, int argument3,
                 const ShapeKeyQuery000380b0 &argument4) const; /* vtable slot 21; derived name */
    void FUN_00037e80(const u32 *keys, int numKeys,
                      void *argument3) const; /* vtable slot 22; derived name */
    void FUN_0003b220(const void *argument1, const void *argument2, const void *argument3,
                      const void *argument4,
                      void *argument5) const; /* vtable slot 23; derived name */
    void FUN_0003b230(const void *argument1, const void *argument2, const void *argument3,
                      const void *argument4,
                      void *argument5) const; /* vtable slot 24; derived name */
    void FUN_0003b240(const void *argument1, const void *argument2, const void *argument3,
                      const void *argument4, const void *argument5, const void *argument6,
                      void *argument7) const; /* vtable slot 25; derived name */
    void FUN_0003b250(const void *argument1, const void *argument2, const void *argument3,
                      const void *argument4, const void *argument5, const void *argument6,
                      void *argument7) const; /* vtable slot 26; derived name */
    int FUN_0003b210(const LodContext000426b0 &context, const LodQuery000426b0 &query,
                     int currentLod) const; /* vtable slot 27; derived name */
    void FUN_0003b260(const void *argument1,
                      void *argument2) const; /* vtable slot 28; derived name */
    int FUN_0003b270(const void *argument1,
                     void *argument2) const; /* vtable slot 29; derived name */

    const hknpShape *coreShape;
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
    hknpShapeKeyMask() {}

    hknpShapeKeyMask(hkFinishLoadedObjectFlag flag) : hkBaseObject(flag) {}

    /* The class allocator: a block of the thread's heap (0xdea4d; defined
     * in tlg_lib_unknown.h beside the router), and its placement form, which
     * the finish callbacks construct in place with. */
    static void *operator new(unsigned long numBytes);

    static void *operator new(unsigned long, void *where)
    {
        return where;
    }

    /* Its delete: the object back to the thread's heap at the class's size,
     * no null test (the compressed mesh mask's deleting destructor 0x34a00
     * frees 0x20 bytes; defined in tlg_lib_unknown.h beside the new). */
    static void operator delete(void *object, unsigned long numBytes);

    virtual void FUN_000381b0(u32 key, bool enabled) = 0; /* derived name */
    virtual bool FUN_000381d0() = 0;                      /* derived name */
    virtual bool FUN_000381f0(u32 key) const = 0;         /* derived name */
    virtual int FUN_00038210() const = 0;                 /* derived name */
};

/* Built by the reflection initializer at 0x62080. */
extern const hkClass D_57c1aa8; /* hknpShapeKeyMask's hkClass */

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

    /* Slots 0 and 1, 0x338d0 and 0x33990 (func_00033d30.cpp). Declared
     * inline: the deleting destructor holds the whole body, which only the
     * inliner's hinted threshold admits. */
    inline virtual ~hknpCompoundShapeInternalsKeyMask();

    /* The class delete: back to the thread's heap at the class's size,
     * after a null test (0x33a58; defined in tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    void FUN_000381b0(u32 key, bool enabled); /* vtable slot 3 (0x33a90); derived name */
    bool FUN_000381d0();                      /* vtable slot 4 (0x1bad0); derived name */
    bool FUN_000381f0(u32 key) const;         /* vtable slot 5 (0x33ca0); derived name */
    int FUN_00038210() const;                 /* vtable slot 6 (0x33d20); derived name */

    /* vtable slot 7 (0x33d30): the instance's bit in the filter. derived name. */
    int FUN_00033d30(hknpShapeInstanceId instanceId) const;

    /* The instance's bit in the filter, read and set or cleared (inline in
     * slots 7, 5 and 3: 0x33d30, 0x33cdc on, 0x33acc on). derived names. */
    bool isInstanceEnabled(hknpShapeInstanceId instanceId) const;
    void setInstanceEnabled(hknpShapeInstanceId instanceId, bool enabled);

    const hknpCompoundShape *shape;
    hkArray<hknpShapeKeyMask *> instanceMasks;
    hkArray<u32> filter;
};

/* hknpStaticCompoundShapeKeyMask (hkClass 0x57bdea0, built at 0x34162: size
 * 0x30, parent hknpCompoundShapeInternalsKeyMask's 0x57bdf20, no members):
 * vtable 0x1692790, finish callback FUN_00034000. */
class hknpStaticCompoundShape;

class hknpStaticCompoundShapeKeyMask : public hknpCompoundShapeInternalsKeyMask
{
  public:
    /* 0xcfa20: the mask of a shape, its arrays empty, sized for the
     * shape's instances. */
    hknpStaticCompoundShapeKeyMask(const hknpStaticCompoundShape *shape_);

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

    /* A mask bound to no shape, its filter empty (inline in the shape's slot
     * 20, 0x117200). */
    KeyMask() : shape(0) {}

    /* Out of line (0x349b0, slot 0): the filter given back. */
    virtual ~KeyMask();

    void FUN_000381b0(u32 key, bool enabled); /* vtable slot 3 (0x34a80); derived name */
    bool FUN_000381d0();                      /* vtable slot 4 (0x34ac0); derived name */
    bool FUN_000381f0(u32 key) const;         /* vtable slot 5 (0x34ae0); derived name */
    int FUN_00038210() const;                 /* vtable slot 6 (0x2b020); derived name */

    const hknpCompressedMeshShape *shape;
    hkArray<u32> filter;
};

/* What slot 23 of the shapes takes fourth (derived names): 0x60 bytes on a
 * 16-byte boundary, a shape key mask at +0x28, which the masked shape
 * replaces with its own (0x38010). Its copy goes field by field, the vectors
 * before the float at +0x38, as both copies in the executable have it (the
 * masked shape's 0x38010 and hknpLodShape's slot 23, 0x68810, which builds
 * the same record around a new key). */
struct alignas(16) ShapeQuery00038010 /* derived name */
{
    ShapeQuery00038010(const ShapeQuery00038010 &other)
        : unknown0(other.unknown0), unknown8(other.unknown8), unknown10(other.unknown10),
          unknown18(other.unknown18), unknown20(other.unknown20), mask(other.mask),
          unknown30(other.unknown30), unknown34(other.unknown34)
    {
        unknown40 = other.unknown40;
        unknown50 = other.unknown50;
        unknown38 = other.unknown38;
    }

    const void *unknown0;
    const void *unknown8;
    const void *unknown10;
    u64 unknown18;
    const void *unknown20;
    const hknpShapeKeyMask *mask;
    u8 unknown30;
    int unknown34;
    float unknown38;
    Vec4 unknown40;
    Vec4 unknown50;
};

/* What slot 29 of the shapes takes first (derived names): 0x50 bytes on a
 * 16-byte boundary (the masked shape's 0x38130 copies it in four vector
 * moves and two words), a shape key mask at +8, which the masked shape
 * replaces with its own; hknpLodShape's slot 29 reads a level of detail
 * at +0x10. */
struct alignas(16) ShapeQuery00038130 /* derived name */
{
    const void *unknown0;
    const hknpShapeKeyMask *mask;
    int levelOfDetail;
    u8 unknown14[0x2c];
    const void *unknown40;
    const void *unknown48;
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

    /* Out of line (0x37b90): the finish callback 0x367b0 jumps to it. */
    hknpMaskedShape(hkFinishLoadedObjectFlag flag);
    virtual ~hknpMaskedShape();

    virtual void FUN_00037d80(); /* vtable slot 31; derived name */
    virtual bool FUN_00037dd0(); /* vtable slot 32; derived name */

    /* Slot 23 (0x38010): the core shape's slot 23 asked with the shape's
     * mask in a copy of the fourth argument's record. derived name. */
    void FUN_00038010(const void *argument1, const void *argument2, const void *argument3,
                      const ShapeQuery00038010 &argument4, void *argument5) const;

    /* Slot 21 (0x380b0): the core shape's slot 21 asked with the shape's
     * mask in a copy of the fourth argument's record. derived name. */
    int FUN_000380b0(void *argument1, int argument2, int argument3,
                     const ShapeKeyQuery000380b0 &argument4) const;

    hknpShapeSignals *FUN_00038120(); /* vtable slot 8; derived name */

    /* Slots 25 and 26 (0x37e90, 0x37f50): the core shape's same slot asked
     * with the shape's mask in a copy of the fifth argument's record.
     * derived names. */
    void FUN_00037e90(const void *argument1, const void *argument2, const void *argument3,
                      const void *argument4, const ShapeQuery00038010 &argument5,
                      const void *argument6, void *argument7) const;
    void FUN_00037f50(const void *argument1, const void *argument2, const void *argument3,
                      const void *argument4, const ShapeQuery00038010 &argument5,
                      const void *argument6, void *argument7) const;

    /* Slot 29 (0x38130): the core shape's slot 29 asked with the shape's
     * mask in a copy of the first argument's record. derived name. */
    int FUN_00038130(const ShapeQuery00038130 &argument1, void *argument2) const;

    hknpShapeKeyMask *mask;
    MaskWrapper maskWrapper;
    hknpShapeSignals mutationSignals;
    s32 maskSize;
    /* To the record's 0x70 bytes (the deleting destructor 0x37bf0 frees
     * them). */
    u8 unknown64[0xc];
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

extern const hkClass D_57c0cb0;                 /* hknpCollisionFilter's hkClass */
void FUN_0003e340(void *object, int finishing); /* derived name: its type info's finish callback */

/* A collision cache that keeps properties beside its contact data
 * (derived names): FUN_0017a0a0 reserves a property under a key (a bit of
 * the byte at +0x17 marks each key in use) of a size and an alignment, and
 * returns it, or null when the key is taken or the cache is full. */
struct hknpManifoldCollisionCache /* derived name */
{
    /* A property reserved under a key, or null (the modifiers' slot 7 at
     * 0x15d7f0 reads key 1, 0x1570a0 key 2): the properties sit from the
     * byte offset at +0x16 in 16-byte units, each key's own offset in
     * 4-byte units in its four bits of the word at +0x18. derived name. */
    template <typename T> T *accessProperty(int key)
    {
        if (propertyKeysUsed & (1 << key)) {
            const int offset =
                propertyBufferOffset * 16 + ((propertyOffsets >> (key * 4)) & 0xf) * 4;
            return reinterpret_cast<T *>(reinterpret_cast<char *>(this) + offset);
        }
        return 0;
    }

    u8 unknown0[9];
    /* The size in 16-byte quads (the 16-byte cache's header byte at +9;
     * the detector's slots look past the first two quads only from three).
     * derived name. */
    u8 sizeInQuads;
    u8 unknownA[0xc];
    u8 propertyBufferOffset; /* derived name */
    u8 propertyKeysUsed;     /* derived name */
    u32 propertyOffsets;     /* derived name */
    u8 unknown1c[6];
    /* Flags; bits 0 and 2 together ask the modifier slot 0x161f10 for its
     * event. derived name. */
    u16 flags22;
    /* The modifier bits the cache asks for (the collision detector's slot
     * 3, 0x72d5a, tests each modifier's mask against it). derived name. */
    u32 enabledModifiers;
    /* The cache's solver record, a block's address and the record's byte
     * offset in it (0x72dec adds them; slot 4 clears both). derived
     * names. */
    u8 *solverBlock;
    u16 solverOffset;
    u8 unknown32[6];
    /* Set when the manifold is created from the bodies' materials (the
     * modifier slot 0x15db20): the smaller maxContactImpulse as a half and
     * the smaller fractionOfClippedImpulseToApply in 255ths. derived
     * names. */
    hkHalf maxImpulse;
    u8 fractionOfClippedImpulseToApply;
    /* The count of each of the three float arrays past the properties,
     * each padded to 16 bytes (FUN_0017a0a0 moves all three up when it
     * reserves a property). derived name. */
    u8 pointValueCount;

    /* A property's address without the in-use test (0x156e90 reads key 2
     * so). derived name. */
    template <typename T> T *getProperty(int key)
    {
        const int offset = propertyBufferOffset * 16 + ((propertyOffsets >> (key * 4)) & 0xf) * 4;
        return hkAddByteOffset(reinterpret_cast<T *>(this), offset);
    }

    /* The bytes the properties take: 64 once full (bit 0 of the keys byte,
     * which FUN_0017a0a0 sets when the end reaches 64), else key 0's
     * nibble, the end in 4-byte units, padded to 16; without a branch, as
     * the base computes it at 0x156ec7 (a mask from the bit, not a
     * select, which 3.3 makes a cmov). derived name. */
    int propertyBufferSize() const
    {
        const int full = propertyKeysUsed & 1;
        return full * 64 + ((((propertyOffsets & 0xf) * 4 + 15) & ~15) & -(1 - full));
    }

    /* One of the three float arrays past the properties, the offset
     * applied through the pointer's integer value (hkAddByteOffset), so the
     * address is opaque to the loop strength reduction of a walk over it
     * (0x156e90). derived name. */
    float *pointValues(int index)
    {
        return hkAddByteOffset(reinterpret_cast<float *>(this),
                               propertyBufferOffset * 16 + propertyBufferSize() +
                                   index * ((pointValueCount + 3) & ~3) * sizeof(float));
    }
};

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

/* A body as the modifiers receive it (derived names): its material at
 * +0x20 (0x15db20 reads both bodies' there). */
struct hknpMaterial;

struct hknpMotion;

struct hknpCdBody /* derived name */
{
    const hknpBody *body;       /* derived name */
    const hknpShape *rootShape; /* derived name: null where 0x30ca0 builds one */
    const hknpMotion *motion;   /* derived name */
    /* The shape collided, the body's own (0x31026 reads it at +0x48). */
    const hknpShape *leafShape;   /* derived name */
    const hknpMaterial *material; /* derived name */
    u32 shapeKey;                 /* derived name: -1 for the whole shape */
};

/* The modifier of vtable 0x16a4e50 (address point 0x16a4e60, no type info,
 * 8 bytes: slot 1 is the shared 0xd900; derived name), built by FUN_00048b20
 * at 0x49d51 among the world's twenty: slot 2 (0x15db10) returns its mask
 * 0x81; slot 3 (0x15db20), called when a manifold is created, fills the
 * cache's impulse limit from the bodies' materials; slot 11 (0x15db70). */
class Modifier16a4e60 /* derived name */
{
  public:
    void FUN_0015db20(const void *threadContext, const void *sharedData, const hknpCdBody *bodyA,
                      const hknpCdBody *bodyB,
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

    /* Out of line (0x665c0; the world's destructor calls it at 0x4b4d5
     * before freeing the 0x570 bytes): the filter's reference released. */
    ~hknpModifierManager();

    u8 unknown0[0x4e0];
    void *objects4e0[NUM_TYPES_4E0];                                      /* derived name */
    hknpCollisionDetector *collisionDetectors[NUM_COLLISION_CACHE_TYPES]; /* derived name */
    /* The world's collision filter, a reference kept by FUN_000667b0.
     * derived name. */
    hkRefPtr<hknpCollisionFilter> collisionFilter;
};

/* The reference-counted object at +0x6c8 (set by the constructor at
 * 0x49619) hands out the signals of world events (derived names):
 * FUN_0006bdf0 the signal of an event type for one body (hknpCharacterProxy
 * subscribes to type 1 of its own body at 0x1766d8 and 0x176bc8),
 * FUN_0006bf60 the signal of an event type for all (type 2 at 0x1596f5),
 * each created on first use. FUN_0004fbd0 and FUN_0004fbe0 forward to
 * them. */
struct hknpEventSignal : public Signal00093530 /* derived name */
{};

class hknpEventDispatcher /* derived name */
{
  public:
    /* A body's signals, one entry per event type, chained from the body's
     * first entry through next; free entries chain from firstFreeEntry
     * (0x6bdf0 takes one, or a new one, for a type the body has none of).
     * derived names. */
    struct BodySignalEntry {
        u16 next;
        u16 eventType;
        hknpEventSignal signal;
    };

    hknpEventSignal *FUN_0006bdf0(int eventType, int bodyId); /* derived name */
    hknpEventSignal *FUN_0006bf60(int eventType);             /* derived name */

    /* A removed body's signals (0x6c050; the world's body removal calls it
     * at 0x4e9fe): the body's first entry kept for later while removals
     * are deferred, else every slot of each of its signals deleted and its
     * entries put back on the free list. derived name. */
    void FUN_0006c050(hknpBodyId bodyId);

    u8 unknown0[0x30];
    u16 firstFreeEntry;               /* derived name */
    hkArray<BodySignalEntry> entries; /* derived name */
    hkArray<u16> bodyFirstEntry;      /* derived name */
    hkBool deferRemovals;             /* derived name */
    hkArray<u16> pendingRemovals;     /* derived name */
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

/* The 0x1a0-byte one (derived name; vtable 0x16a4380, constructor
 * FUN_00150240): its destructor 0x14e100 is out of line, and its deleting
 * destructor 0x14e0b0 runs it and frees the 0x1a0 bytes unless null
 * (written as calls while the class is opaque, cookbook 15). */
/* The world's integer space (derived names, after Havok's
 * hkIntSpaceUtil): the broad phase's box and the offsets and scales that
 * map it to 15 bits; the world's constructor sets it from its description
 * at 0x4995b. */
struct hkIntSpaceUtil /* derived name */
{
    /* Set from a box (0x936a0): the scale 32767 over the span (its
     * reciprocal refined once, w one before the scale and zero after), the
     * offsets the box's minimum negated and that plus a step's span, the
     * scale's reciprocal; every w zero. derived name. */
    void FUN_000936a0(const hkAabb &newAabb);

    Vec4 bitOffsetLow;
    Vec4 bitOffsetHigh;
    Vec4 bitScale;
    Vec4 bitScaleInv;
    hkAabb aabb;
};

struct hknpWorld;

class hknpWorldObject1d0Large : public hknpWorldObject1d0 /* derived name */
{
  public:
    /* Slot 5 (0x151c80): the world's streams of a thread checked, the
     * checks empty in this build. derived name. */
    void FUN_00151c80(hknpWorld *world, int threadIndex);
};

void FUN_0014e100(hknpWorldObject1d0Large *self); /* derived name */
void FUN_0014e0b0(hknpWorldObject1d0Large *self); /* derived name */

/* hkAabb16 (the reflection's class name, the string at 0x14b826d; hkClass
 * 0x57b9460, built at 0x1372d, its four records at 0x168e3c0 name the
 * fields): a box in 16-bit coordinates, the three minimum coordinates and a
 * key in the low eight bytes, the three maximum coordinates and a second
 * key in the high eight, read and written as one aligned vector
 * (FUN_00185460). */
struct alignas(16) hkAabb16 {
    u16 min[3];
    u16 key;
    u16 max[3];
    u16 key1;
};

/* hknpBody (reflected, record table at 0x1695350): 0x90 bytes as the
 * world's body array is indexed; motionId at +0x68. */
/* hknpBody (hkClass 0x57bfa50, 0x90 bytes, record table 0x1695350):
 * transform at +0, flags at +0x40, motionId at +0x68. The w lanes of the
 * transform's rotation columns hold the center of mass in the body's space
 * (FUN_0003a670 stores it there; the caller at 0x5f45b passes a world point
 * rotated into the body). */
struct hknpBody {
    /* The flag bits the world's tests read (derived names): a static body
     * and an active one (0x4d436 tests both, `test 9`). */
    enum { IS_STATIC = 1 << 0, IS_ACTIVE = 1 << 3 };

    void FUN_0003a670(const Vec4 &centerOfMassLocal); /* derived name */

    hkTransform transform;
    int flags;
    u32 collisionFilterInfo; /* derived name */
    const hknpShape *shape;  /* derived name */
    /* The body's box in the broad phase's coordinates (0x161400 copies it
     * whole). derived name. */
    hkAabb16 aabb;
    u32 id;
    /* The next body of an attached group, the body itself when alone
     * (0x4c720 compares the two). */
    u32 nextAttachedBodyId;
    int motionId;
    u32 broadPhaseId; /* -1 while the body is not in the broad phase */
    u8 unknown70[2];
    /* Its quality, an index into the world's body quality library
     * (0x5b4ef). derived name. */
    u8 qualityId;
    /* Two values 0x161400 clears when it resets a body's flags. derived
     * names. */
    u8 byte73;
    u16 word74;
    u8 unknown76[2];
    /* The body's index into the body manager's active list, 0x7fffffff when
     * it has none (0x1615a0 and 0x4c720 store that). */
    u32 indexIntoActiveListOrDeactivatedIslandId;
    u8 unknown7c[3];
    /* A byte the world's object at +0x4f8 records with the body's id
     * (0x63956). derived name. */
    u8 byte7f;
    u8 unknown80[0x10];
};

extern const hkClassMember D_1695350[]; /* derived name: hknpBody's records */
extern const hkClassEnum D_16956b0[];   /* derived name: its one enum */

/* What the world holds at +0x10 (derived name after hknpBodyManager.cpp, the
 * file 0x1607c0 cites; the callers at 0x6c953 and 0x18d0c0 pass the
 * world's +0x10): the bodies' array from +0x10, the ids of the active
 * bodies from +0xa0. FUN_001612a0 fetches every active body ahead of the
 * solver. */
struct hknpMotionManager;

struct hknpBodyManager /* derived name */
{
    /* A body change scheduled for the next step (derived name): the body's
     * id at +0, 12 bytes. */
    struct ScheduledBodyChange {
        int bodyId;    /* derived name */
        u16 flags;     /* derived name; bits 0 and 1: on the lists at +0xe0 and +0xf0 */
        int listIndex; /* derived name; 0x7fffffff when on neither */
    };

    void FUN_001612a0() const; /* derived name */

    /* derived name: each active body's box copied into its previous box,
     * the body and the box eight ids ahead fetched into the cache
     * (0x161350, called at 0x6c9b9 and 0x18d5b0). */
    void FUN_00161350();

    /* The active bodies' ids, four zeros written past the last (the
     * solver's SIMD reads run over by up to three; 0x1612e0, called by
     * 0x6d690 and the solve data task 0x16e0e0, which round the count up
     * to four). derived name. */
    const hkArray<u32> &FUN_001612e0();

    /* derived name: every scheduled change dropped, each body's index into
     * them reset to the invalid 0x7fffffff (0x161740; the world's step
     * runs it in its "clearAllScheduledBodyChanges" timer, 0x5107f). */
    void FUN_00161740();

    /* derived name: both kinds' lists emptied, every scheduled change taken
     * off them (0x161910; the world's step calls it at 0x4fee6 and
     * 0x50001). */
    void FUN_00161910();

    /* derived names: a body taken off the active list (0x1615a0: the last
     * active body moved into its slot, its flags marked, its index reset),
     * and every body of the attached group a body starts taken off in turn
     * (0x161630, which walks nextAttachedBodyId back to the first). */
    void FUN_001615a0(int bodyId);
    void FUN_00161630(int bodyId);
    /* derived name: a body put on the active list (0x161490, called at
     * 0x4c65d): its flags marked, its index the list's end, its motion's
     * cell recorded under its id. */
    void FUN_00161490(int bodyId);
    /* derived name: every body of the attached group a body starts that is
     * in the broad phase or on a list put on the active list as 0x161490
     * puts one (flag 8), then the group's motion into its cell's list
     * (0x1614f0, called at 0x63dc6). */
    void FUN_001614f0(int bodyId);

    /* derived name: for every scheduled change marked 4 whose body exists,
     * a body with flag 1 has its box recorded in the boxes at +0x28, its
     * flags 0x3c00 cleared and its bytes at +0x73 and +0x74 zeroed
     * (0x161400; the collide stage at 0x6dc9d and the solver factory task
     * at 0x14eade). */
    void FUN_00161400();

    /* A body's entry (derived names): a half at +0, -1 by default, and a
     * 16-bit value at +2, 0xffff by default. */
    struct BodyEntry {
        BodyEntry()
        {
            half.setReal(-1.0f);
            value = 0xffff;
        }

        hkHalf half;
        u16 value;
    };

    /* derived name: a body's value set in its entry (0x160f30, called at
     * 0x5f9da): the entries grown to the bodies' capacity first, the new
     * ones the defaults, unless the value is the default 0xffff. */
    void FUN_00160f30(u32 bodyId, u16 value);

    u8 unknown0[8];
    hknpMotionManager *motionManager; /* derived name */
    hkArray<hknpBody> bodies;         /* derived name */
    u8 unknown20[8];
    hkAabb16 *previousAabbs; /* derived name: by body id */
    u8 unknown30[8];
    hkArray<BodyEntry> bodyEntries; /* derived name: by body id */
    u8 unknown48[0x58];
    hkArray<u32> activeBodyIds;                        /* derived name */
    hkArray<u8> activeBodyCellIndices;                 /* derived name: by body id */
    hkArray<ScheduledBodyChange> scheduledBodyChanges; /* derived name */
    hkArray<int> scheduledBodyChangeIndices;           /* derived name */
    /* The bodies of the two kinds of scheduled change (0x161790 appends to
     * the first for kind 1, the second for kind 2; 4-byte elements, the
     * destructor 0x160270 frees both). */
    hkArray<u32> bodiesOfChange1; /* derived name */
    hkArray<u32> bodiesOfChange2; /* derived name */
};

/* hknpMotion (reflected, record table at 0x16945d0): 0x80 bytes as the
 * world's motion array is indexed; cellIndex (one byte) at +0x3e. */
struct hknpMotion {
    /* The angular velocity in world space: the local one rotated by the
     * orientation (0x157510; the callers 0x4bd56, 0x4f142, 0x163cac).
     * derived name. */
    void FUN_00157510(Vec4 &angularVelocityOut) const;

    /* The angular velocity set from a world-space one, rotated into the
     * motion's frame by the inverse of its orientation (0x157630). derived
     * name. */
    void FUN_00157630(const Vec4 &newAngularVelocity);

    /* The velocity of a point moving with the motion: the linear velocity
     * plus the world angular velocity crossed with the point's offset from
     * the centre of mass (0x157580). derived name. */
    void FUN_00157580(const Vec4 &position, Vec4 &velocityOut) const;

    /* Back to the unused state (inlined in 0x476a0): every vector zero, the
     * orientation the identity, no cell, no motion properties, not in use,
     * no solver id. derived name. */
    void reset()
    {
        hkString::memSet16(this, &D_14b2060[2], sizeof(*this) / 16);
        orientation.vec = D_14b2060[32];
        cellIndex = 0xff;
        motionPropertiesId = 0;
        unknown3f = 0;
        solverId = 0x7fffffff;
    }

    union {
        u8 unknown0[0x10];
        /* A free motion's link to the next free one (0x476a0 stores the
         * manager's first free id over the cleared motion). derived name. */
        u32 nextFreeMotionId;
        /* A motion's centre of mass in world space (0x157580 measures a
         * point's offset from it). derived name. */
        Vec4 centerOfMass;
    };

    hkQuaternion orientation; /* derived name */
    /* The inverse inertia in the first three, the w kept when 0x5f530 sets
     * them (Havok keeps the inverse mass there). derived name. */
    hkHalf inverseInertia[4];
    u8 unknown28[4];
    /* The motion's place in its cell's list of active motions, 0x7fffffff
     * when it is in none (0x47790). */
    u32 solverId;
    u8 unknown30[6];
    /* A speed the velocity scale scales too (0x157bfa). derived name. */
    hkHalf half36;
    u16 motionPropertiesId; /* derived name: 0x476a0 clears it */
    u8 unknown3a[4];
    u8 cellIndex;
    u8 unknown3f;
    /* The vector FUN_0005df00 hands out for a body: its linear velocity,
     * by the next getter (0x5df30), which rotates the vector at +0x50 by
     * the quaternion at +0x10, the angular one. derived name. */
    Vec4 linearVelocity;
    Vec4 angularVelocity; /* derived name: in the motion's frame */
    /* The velocities of the previous step (derived names): the velocity
     * scale scales them and moves the motion by them (0x157be0). */
    hkVector4 previousLinearVelocity;
    hkVector4 previousAngularVelocity;
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

    /* A motion given back (0x476a0, called at 0x4c5bc): reset, put at the
     * head of the free list, one fewer in use. derived name. */
    void FUN_000476a0(int motionId);

    u8 unknown0[8];
    hkArray<hknpMotion> motions;
    u32 unknown18;
    u32 firstFreeMotionId; /* derived name: invalid when none is free */
    u32 numUsedMotions;    /* derived name */
    u32 peakMotionIndex;
    /* Per cell, the ids of its active motions; a motion's solverId is its
     * place in its cell's list. derived name. */
    hkArray<hkArray<u32>> activeMotionsPerCell;

    /* A motion out of its cell's list (0x47790; six callers): the cell's
     * last id moves into its place, unless it was the last. derived
     * name. */
    void FUN_00047790(hknpMotion &motion);

    /* A motion into its cell's list (0x47720; the cell changes at 0xcd57c
     * after the removal above): its place the list's size, then its id
     * appended. derived name. */
    void FUN_00047720(hknpMotion &motion, u32 motionId);
};

/* The object at +0x4f8 of the world (derived names): the world at +0, the
 * object at +8 whose 16-byte records it indexes by a body's int at +0x68;
 * FUN_00062b20 takes a body id and a bool, reads the body's flags at +0x40
 * (bit 2 first) and sets or clears a byte at +0xb of the body's record. */
struct hknpWorld;

/* hknpConstraint (hkClass 0x57c2b78, built at 0x706c5: size 0x40; its
 * member records are built at run time, from 0x70200): bodyUidA and
 * bodyUidB (hkUint64) at +0 and +8, whose halves at +4 and +0xc the
 * constraint filter reads as the bodies' ids; data (a pointer) at +0x10,
 * id, immediateId, flags and type from +0x18, atoms at +0x20 and their
 * sizes, runtimeSize at +0x2e, runtime at +0x30, userData at +0x38. The
 * names after the bodies' are the records'. */
class hkpConstraintData;

struct hknpConstraint {
    /* Inline where its type info's cleanup (0x700d0) runs it (defined in
     * tlg_lib_unknown.h, after the thread's memory router). */
    inline ~hknpConstraint();

    u8 unknown0[4];
    u32 bodyIdA; /* derived name */
    u8 unknown8[4];
    u32 bodyIdB; /* derived name */
    hkRefPtr<hkpConstraintData> data;
    u32 id;
    u16 immediateId;
    u8 flags;
    u8 type;
    void *atoms;
    u16 sizeOfAtoms;
    u16 sizeOfSchemas;
    u8 numSolverResults;
    u8 numSolverElemTemps;
    u16 runtimeSize;
    void *runtime;
    u64 userData;
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

/* Storage a triangle shape is built in (derived names): 0xe0 bytes, the
 * triangle hknpGlobals keeps at +0x10 copied in and its convex radius (at
 * +0x14) set, by 0x78160. */
void FUN_00078160(void *buffer, float convexRadius); /* derived name */

struct InplaceTriangle00078160 /* derived name */
{
    InplaceTriangle00078160(float convexRadius)
    {
        FUN_00078160(buffer, convexRadius);
    }

    Vec4 buffer[14];
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
        /* Out of line (0x167cd0): no index, the two triangles built with
         * a radius of 0.01, the entries empty and the three words at
         * +0x39c, +0x3a0 and +0x3b0 cleared. */
        Context();

        int index;
        u8 unknown4[0x4c];
        InplaceTriangle00078160 triangle0; /* derived name */
        InplaceTriangle00078160 triangle1; /* derived name */
        u8 unknown210[0x90];
        hkInplaceArrayAligned16<u64, 24> entries; /* derived name */
        u8 unknown380[0x1c];
        int unknown39c;
        void *unknown3a0;
        u8 unknown3a8[8];
        int unknown3b0;
        u8 unknown3b4[0xc];
    };

    /* A free context taken from the head of the list (0x16ff90): the head
     * moves to its successor with the tag advanced, and the taken one's
     * link is marked 0xf. */
    Context *FUN_0016ff90();

    /* A context back on the list, at its own index (0x16ffe0). */
    void FUN_0016ffe0(const Context *context);

    u8 unknown0[0x10];
    Context contexts[8];
    u32 freeHead;
    /* volatile: the links change under other threads' takes and gives
     * back, so a take reads its successor afresh on every attempt (0x16ffad,
     * a load of its own, not folded into the `or`). */
    volatile int next[8];
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

/* What slot 20 (0x30c10) and the slots at 0x30ca0 and 0x31320 hand to
 * FUN_0002b6c0 (derived names). The pair's output at +0xa8 of the second
 * argument records the writer's range and the count of what the call
 * wrote past its start; the writer's range is two ints copied together
 * (0x30c58), its two counters bumped at the call's end (0x2d74e). The
 * 0x40-byte info whose first byte the callers clear is not read by the
 * callee. */
struct hknpWorldObject380Range /* derived name */
{
    int start; /* derived name */
    int end;   /* derived name */
};

struct hknpWorldObject380Writer /* derived name */
{
    u8 unknown0[8];
    hknpWorldObject380Range range; /* derived name */
    int unknown10;
    int unknown14;
};

struct hknpWorldObject380Output /* derived name */
{
    u8 unknown0[0x28];
    hknpWorldObject380Range range; /* derived name */
    u16 count;                     /* derived name */
};

struct hknpWorldObject380Pair /* derived name */
{
    u8 unknown0[0x90];
    /* How the bodies' properties are combined, 0 to 3 (the switches at
     * 0x30e5a and 0x31378). derived name. */
    u8 combineType;
    u8 unknown91[0x17];
    hknpWorldObject380Output *output; /* derived name */
    u8 unknownB0[0x10];
    /* Added to the bodies' centres of mass (0x30f36, 0x315ba). derived
     * names. */
    Vec4 offsetA;
    Vec4 offsetB;
};

/* 0x40 bytes (0x30c10's frame: the info fills the 0x40 below its guard),
 * only the flag set by its three builders and nothing read by FUN_0002b6c0
 * (its fourth argument is overwritten unread at 0x2b6fc). It holds no
 * array: the stack protector's layout puts it among the address-taken
 * objects after inertias (0x30ca0, -0x200 below -0x1c0, D35), where an
 * array member would have put it nearer the guard. The members past the
 * flag are not recovered. */
struct hknpWorldObject380Info /* derived name */
{
    hkBool flag; /* derived name */
    Vec4 unknown10;
    Vec4 unknown20;
    Vec4 unknown30;
};

int FUN_0002b6c0(void *argument0, hknpWorldObject380Pair *pair, void *argument2,
                 hknpWorldObject380Info *info, void *argument4, void *argument5, void *argument6,
                 hknpWorldObject380Writer *writer); /* derived name */

/* What slot 12 (0x311f0) fills from two motions (derived names): their
 * centres of mass and their orientations as rotations. */
struct hknpWorldObject380Bodies /* derived name */
{
    Vec4 centerOfMassA;  /* derived name */
    Vec4 centerOfMassB;  /* derived name */
    hkMatrix3 rotationA; /* derived name */
    hkMatrix3 rotationB; /* derived name */
    /* Two scalars broadcast (100 and -0.05 in 0x30ca0, the floats at
     * 0x16dc5e0 and 0x16dc5e4 in 0x31320). derived names. */
    Vec4 vector80;
    Vec4 vector90;
    /* The combined properties, by the pair's combine type (0x30e5a). */
    hkHalf halfA0; /* derived name */
    u8 byteA2;     /* derived name */
    u8 unknownA3;
    hkHalf halfA4; /* derived name */
    hkHalf halfA6; /* derived name */
    hkHalf halfA8; /* derived name */
    u8 unknownAA[2];
    u32 flags;   /* derived name */
    u16 valueB0; /* derived name */
    u8 unknownB2[6];
    const void *pointerB8; /* derived name */
    const void *pointerC0; /* derived name */
    u8 unknownC8[8];
};

/* What slot 12 (0x311f0) fills: the bodies' part at +0x10, which slot 14
 * (0x31320) hands to FUN_0002b6c0 (derived names). */
struct hknpWorldObject380MotionPair /* derived name */
{
    u8 unknown0[0x10];
    hknpWorldObject380Bodies bodies; /* derived name */
};

/* The fourth argument of FUN_0002b6c0 (derived names): the two motions'
 * inverse inertias and masses as vectors, and four pointers (into the
 * pair's output in 0x31320, to stack arrays in 0x30ca0). */
struct hknpWorldObject380Inertias /* derived name */
{
    Vec4 inverseInertiaA; /* derived name */
    Vec4 inverseInertiaB; /* derived name */
    void *pointer20;      /* derived name */
    Vec4 *pointer28;      /* derived name */
    Vec4 *pointer30;      /* derived name */
    Vec4 *pointer38;      /* derived name */
};

/* The first argument of FUN_0002b6c0 (derived names): two floats whose
 * product scales the pair's inverse mass (0x30fbf). */
struct hknpWorldObject380StepInfo /* derived name */
{
    u8 unknown0[0x40];
    float value40; /* derived name */
    u8 unknown44[0x80];
    float valueC4; /* derived name */
};

/* The third argument of 0x30ca0 (derived names): kept in the bodies' part
 * with the pointer at its +0x38. */
struct hknpWorldObject380Source /* derived name */
{
    u8 unknown0[0x38];
    const void *pointer38; /* derived name */
};

/* The pair processed with its bodies' part built on the stack (0x30ca0;
 * called by slot 14, 0x314fc, and by 0x76c7b): the motions' centres of
 * mass and rotations, the properties combined by the pair's combine type,
 * the inverse masses' reciprocal scaled into a stack array, two bodies
 * described, then FUN_0002b6c0. derived name. */
int FUN_00030ca0(hknpWorldObject380Pair *pair, const hknpWorldObject380StepInfo *stepInfo,
                 const hknpWorldObject380Source *source, u32 flags, u16 valueB0,
                 const hknpBody *bodyA, float value0, float value1, float value2,
                 const hknpMotion *motionA, const hknpMaterial *materialA, const hknpBody *bodyB,
                 const hknpMotion *motionB, const hknpMaterial *materialB,
                 hknpWorldObject380Writer *writer); /* derived name */

class hknpWorldObject380 : public hkReferencedObject /* derived name */
{
  public:
    /* Slot 12 (0x311f0): the centres of mass copied and the orientations
     * set as rotations, the third argument unread. derived name. */
    void FUN_000311f0(hknpWorldObject380MotionPair *out, const hknpMotion &motionA,
                      const void *argument2, const hknpMotion &motionB);
    /* Slot 20 (0x30c10): the pair processed through FUN_0002b6c0, its
     * output given the writer's range and the count written past it.
     * derived name. */
    void FUN_00030c10(void *argument0, hknpWorldObject380Pair *pair, void *argument2,
                      void *argument4, void *argument5, void *argument6,
                      hknpWorldObject380Writer *writer);
    /* Slot 8 (0x310f0): count records in one block from the allocator at
     * 0x57b8480, their addresses stored in order. derived name. */
    void FUN_000310f0(int count, hknpWorldObject380Record **recordsOut);
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
    /* A pair of bodies recorded (0x655b0; the world's 0x4d400 tail-calls
     * it with a constraint's two bodies). derived name. */
    void FUN_000655b0(int bodyIdA, int bodyIdB);
    /* Runs 0x63a40 on each id of an array (0x64070; the island activation
     * under the timer "TtActivateIslands" at 0x15ba28 and the step at
     * 0x6ca67 call it). derived names. */
    void FUN_00063a40(int id);
    void FUN_00064070(const hkArray<int> &ids);
    /* Whether any of the ids' entries of the array at +0x18 is one of the
     * pointers of the array at +0x58 (0x640b0; the prepare-new-pairs task
     * asks it over its ids at 0x15b84f). derived name. */
    bool FUN_000640b0(const hkArray<int> &ids) const;

    /* A body's byte at +0x7f and its id, recorded at +0x38. derived names. */
    struct BodyRecord {
        HK_DECLARE_POD_TYPE();

        int byte7f;
        hknpBodyId bodyId;
    };

    /* A body whose flags have bit 3 recorded (0x63930; the body changes
     * the world applies, 0x16f077, and the game call it). derived name. */
    void FUN_00063930(int bodyId);

    /* A 16-byte record by motion id; its byte at +0xb is cleared when a
     * body of the motion is taken and the byte is not 0xff (0x639e0).
     * derived names. */
    struct MotionRecord {
        /* The record set up (0x66860; the world's constructor sets the
         * first at 0x49be0 with 0 and true): a zero vector packed into
         * three 10-bit fields, the identity quaternion into four bytes,
         * the two-bit value and the byte 0 when the flag is set, else
         * 0xff. derived name. */
        void FUN_00066860(int value, bool flag);

        u32 packedVector;     /* derived name */
        u8 packedRotation[4]; /* derived name */
        u8 unknown8[2];
        u8 byteA; /* derived name */
        u8 byteB;
        u8 unknownC[4];
    };

    /* What the array at +0x18 points to (derived names): the id of the
     * next one at +0x54, an id at +0x58 the walk of a body's entry starts
     * from, and a flag at +0x61 set once 0x63a40 has run for it. */
    struct Entry18 {
        u8 unknown0[0x50];
        int id50;    /* derived name; appended to the array at +0x68 by 0x63620 */
        int nextId;  /* 0x7fffffff ends the walk */
        int firstId; /* derived name */
        /* Where its id went in the array at +0x68, less the int at +0x80
         * (0x63620). derived name. */
        int index5c;
        u8 unknown60;
        bool flag61;
    };

    /* An entry's group walked from its first id, each entry not yet
     * flagged given its flag and run through 0x63a40 (0x639b0, 0x655b0 and
     * 0x656e0 hold the walk inline). derived name. */
    void activateGroup(const Entry18 *entry) /* derived name */
    {
        if (entry) {
            int id = entry->firstId;
            do {
                Entry18 *current = unknown18[id];
                const int nextId = current->nextId;
                if (!current->flag61) {
                    current->flag61 = true;
                    FUN_00063a40(id);
                }
                id = nextId;
            } while (id != 0x7fffffff);
        }
    }

    /* Every entry of the group whose first id is `first` given `newFirst`
     * as its first id, nothing done when the two are one (0x656e0 holds it
     * inline after linking the groups: the early-out its caller has already
     * settled is a third way into the caller's join until the late
     * SimplifyCFG, so GVN leaves the join's loads in place, cookbook 205).
     * derived name. */
    void setGroupFirstId(int first, int newFirst) /* derived name */
    {
        if (first != newFirst) {
            Entry18 *entry = unknown18[first];
            for (;;) {
                entry->firstId = newFirst;
                const int nextId = entry->nextId;
                if (nextId == 0x7fffffff) {
                    break;
                }
                entry = unknown18[nextId];
            }
        }
    }

    /* Two entries' groups joined (0x656e0; 0x655b0 tail-calls it with a
     * pair's two entries): the first group's last entry linked to the second
     * group, whose entries take the first group's first id, and the joined
     * group activated when either entry was. derived name. */
    void FUN_000656e0(int indexA, int indexB);

    /* Each pending entry of the array at +0x58 given its place and its id
     * appended to the array at +0x68, then the pending array emptied
     * (0x63620; the step at 0x6d49e and 0x14fcc8 call it). derived name. */
    void FUN_00063620();

    hknpWorld *world;            /* derived name */
    MotionRecord *motionRecords; /* derived name */
    u8 unknown10[8];
    hkArray<Entry18 *> unknown18;
    u8 unknown28[0x10];
    hkArray<BodyRecord> bodyRecords; /* derived name */
    u8 unknown48[0x10];
    hkArray<Entry18 *> unknown58;
    hkArray<int> ids68; /* derived name */
    u8 unknown78[8];
    int int80; /* derived name */
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

    /* The class allocator's delete: the thread's heap takes the block back
     * with its size (0x47cc0 frees 0x18, 0x47d10 0x28; defined in
     * tlg_lib_unknown.h beside the router). */
    static void operator delete(void *object, unsigned long numBytes);

    /* Slot 2, pure here (0x1698f00 holds __cxa_pure_virtual): whether a
     * member-function pointer of size bytes is the one the slot holds
     * (0x47d60 in the member-function slots). */
    virtual int FUN_00047d60(const void *otherMethod, int size) const = 0;

    hkSlot *next; /* derived name */
    void *object; /* derived name */
};

/* A slot of a signal without arguments (derived name): slot 3 calls it. */
class hkSlot0 : public hkSlot /* derived name */
{
  public:
    virtual void call() = 0; /* derived name */
};

/* A slot of a signal with one argument (derived name): slot 3 calls it. */
template <typename P0> class hkSlot1 : public hkSlot /* derived name */
{
  public:
    virtual void call(P0 p0) = 0; /* derived name */
};

/* The two flag bits a slot link keeps low (derived names). */
inline hkSlot *untagSlotLink(const void *link) /* derived name */
{
    return reinterpret_cast<hkSlot *>(reinterpret_cast<hkUlong>(link) & ~hkUlong(3));
}

inline hkUlong slotLinkFlags(const void *link) /* derived name */
{
    return reinterpret_cast<hkUlong>(link) & 3;
}

/* The head is walked as the first link: prevLink starts at the signal
 * itself, the address the signal's destructor is then called on
 * (hknpCompoundShape's 0x4166f keeps it in %r14 for both). The link it
 * patches is a tagged word, read and written as an integer. */
inline void hkSignal0::fire()
{
    hkUlong *prevLink = reinterpret_cast<hkUlong *>(this);
    hkSlot *slot = untagSlotLink(slots);
    slots = reinterpret_cast<void *>(reinterpret_cast<hkUlong>(slot) | 1);
    while (slot) {
        hkSlot *next = untagSlotLink(slot->next);
        if (slotLinkFlags(slot->next) == 0) {
            static_cast<hkSlot0 *>(slot)->call();
            if (slotLinkFlags(slot->next) == 0) {
                prevLink = reinterpret_cast<hkUlong *>(&slot->next);
                slot = next;
                continue;
            }
        }
        /* Unsubscribed, before the call or during it: unlinked and
         * deleted, the predecessor's flags kept. */
        delete slot;
        *prevLink = (*prevLink & 3) | reinterpret_cast<hkUlong>(next);
        slot = next;
    }
    slots = untagSlotLink(slots);
}

/* The same walk, each slot called with the argument. */
template <typename P0> inline void hkSignal1<P0>::fire(P0 p0)
{
    hkUlong *prevLink = reinterpret_cast<hkUlong *>(this);
    hkSlot *slot = untagSlotLink(slots);
    slots = reinterpret_cast<void *>(reinterpret_cast<hkUlong>(slot) | 1);
    while (slot) {
        hkSlot *next = untagSlotLink(slot->next);
        if (slotLinkFlags(slot->next) == 0) {
            static_cast<hkSlot1<P0> *>(slot)->call(p0);
            if (slotLinkFlags(slot->next) == 0) {
                prevLink = reinterpret_cast<hkUlong *>(&slot->next);
                slot = next;
                continue;
            }
        }
        delete slot;
        *prevLink = (*prevLink & 3) | reinterpret_cast<hkUlong>(next);
        slot = next;
    }
    slots = untagSlotLink(slots);
}

/* hknpMaterialId, the material library's 16-bit handle (the template
 * argument of hknpMaterialFreeListArray in the scoped type names, 0x14bf3cf):
 * passed by value as a two-byte struct, so a callee widens it itself or
 * masks it. Field name derived. */
struct hknpMaterialId {
    /* Assigned by its value, as the body id is (the closest-hit collector's
     * copy of a hit, 0x6970f, moves it on its own). */
    void operator=(const hknpMaterialId &other)
    {
        value = other.value;
    }

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
    /* Empty, with no free element (hknpMotionPropertiesLibrary's
     * constructor, 0x36d90). */
    hkFreeListArray() : firstFree(-1) {}

    /* A loaded image's array is left as loaded. */
    hkFreeListArray(hkFinishLoadedObjectFlag flag) : elements(flag) {}

    /* The elements in use destroyed, the free ones left alone; the array
     * then gives its storage back with none left to destroy (the material
     * library's 0x612f0 and hknpCompoundShape's 0x41720: one walk, then
     * the size cleared and the storage freed). Declared inline:
     * hknpCompoundShape's destructor holds it, past the threshold a
     * function without the keyword gets (0x41650). */
    inline ~hkFreeListArray()
    {
        for (int i = 0; i < elements.getSize(); i++) {
            if (!Ops::isEmpty(elements[i])) {
                elements[i].~T();
            }
        }
        elements.setSizeUnchecked(0);
    }

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

    /* The entries, then the signals in reverse (0x612c0, slot 0; the
     * deleting destructor 0x61380 holds the same body). Inline, emitted with
     * the vtable where the object is built (the finish callback 0x61480):
     * the executable holds the complete destructor before the deleting one
     * (cookbook 187). */
    inline virtual ~hknpMaterialLibrary() {}

    /* The reference-counted class delete (freeReferencedObject in
     * tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

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

    /* Empty: its deleting destructor (0x47d10, which vtable 0x1698eb0's
     * 0x28-byte slot shares) runs hkSlot's inline and frees 0x28. */
    virtual ~hknpWorldMaterialSlot();

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
/* The jacobian helpers take it too (FUN_0002b180, FUN_0002b3b0 and
 * FUN_0003d7d0's neighbours pass the world's +0x390): vectors at +0x20,
 * +0x40 and +0x120, floats at +0x110 and +0x130. */
struct hknpSolverInfo /* derived name */
{
    /* The step's times from a time step and a number of sub steps
     * (0x61b30, called at 0x48f07): the time step and its half, the count
     * in every lane, each divided by the count and the count by each, the
     * sub step's in the vectors at +0xf0 and +0x100 (w zero) and, scaled
     * by +0x50, at +0x110 and (negated, from the half) +0x120. derived
     * name. */
    void FUN_00061b30(float timeStep, float numSubSteps);

    float timeStep;     /* derived name */
    float halfTimeStep; /* derived name */
    u8 unknown8[8];
    Vec4 numSubStepsSplat; /* derived name */
    u8 unknown20[0x20];
    Vec4 vector40; /* derived name; 0x2b620 reads its first lane */
    float value50; /* derived name */
    u8 unknown54[0x60];
    /* The steps and the micro steps of each (the solve loop at 0x3fbab
     * counts them from the world's +0x444 and +0x44c). derived names. */
    int numSteps;
    u8 unknownB8[4];
    int numMicroSteps;
    u8 unknownC0[0x30];
    Vec4 vectorF0;
    Vec4 vector100;
    Vec4 vector110; /* derived name; 0x2b670 reads its first lane */
    Vec4 vector120;
    float value130; /* derived name; read by 0x2b620 */
    float value134;
    float value138;
    float value13c;
    u8 unknown140[0x20];
};

/* One step of the solve (derived names): its index, the step's scale from
 * the settings' vector at +0xf0 (row 3 of the constant table added, one in
 * each lane) and its flags, 1 for the first micro step of the first step, 2
 * for the last of the last (0x6c260, called at 0x3fc06, 0x198cc2 and
 * 0x198fe2). */
struct hknpSolverStep /* derived name */
{
    void FUN_0006c260(const hknpSolverInfo &info, int step, int microStep); /* derived name */

    int stepIndex; /* derived name */
    Vec4 vector10;
    int flags; /* derived name */
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

/* The same with the world's bodies and motions (derived names: one caller,
 * 0x6cf08, fills it on its stack with FUN_00167c20 and hands it on with
 * three block streams). */
struct CollideSharedData : public ModifierSharedData /* derived name */
{
    /* The shared data from the world as 0x167c90 takes it, with the
     * object at +0x1f0 stored before the select, then the bodies and
     * motions, and the pair at +0x68 reset (0x167c20). */
    void FUN_00167c20(const hknpWorld *world);

    const hknpBody *bodies;    /* derived name */
    const hknpMotion *motions; /* derived name */
    const void *object40;
    u8 unknown48[0x20];
    int int68;
    int int6c;
};

struct hknpWorldStepContextf6a90 /* derived name */
{
    u8 unknown0[8];
    hknpWorld *world; /* derived name */
};

/* What the world holds at +0x1e0 (derived names): its slot 13 casts a ray
 * over the world's bodies (the world's 0x35d40 hands it the query, the
 * bodies, the world, the world's +0x1f0 and the collector). */
class hknpCollisionQueryCollector;

class hknpWorldObject1e0 /* derived name */
{
  public:
    virtual void unknownVirtual0();
    virtual void unknownVirtual1();
    virtual void unknownVirtual2();
    virtual void unknownVirtual3();
    virtual void unknownVirtual4();
    virtual void unknownVirtual5();
    virtual void unknownVirtual6();
    virtual void unknownVirtual7();
    virtual void unknownVirtual8();
    virtual void unknownVirtual9();
    virtual void unknownVirtual10();
    virtual void unknownVirtual11();
    virtual void unknownVirtual12();
    virtual void
    castRay(const void *query, const hknpBody *bodies, const hknpWorld *world, const void *context,
            hknpCollisionQueryCollector *collector) const; /* vtable slot 13; derived name */
    virtual void unknownVirtual14();
    /* Slot 15: a shape cast over the world's bodies (the world's 0x35de0
     * hands it the query and the shape's orientation, the bodies, the
     * world, the world's +0x1f0 and the two collectors). derived names. */
    virtual void castShape(const void *query, const void *queryShapeOrientation,
                           const hknpBody *bodies, const hknpWorld *world, const void *context,
                           hknpCollisionQueryCollector *collector,
                           hknpCollisionQueryCollector *startPointCollector) const;
};

/* The world's streams at +0x260 (hknpWorldStreams260, defined after
 * hkBlockStream below). */
struct hknpWorldStreams260;

/* The world's stream checks, empty in this build: two functions the linker
 * gives one empty body (0x175a80), called with five and seven arguments by
 * the large object's slot 5 (0x151c80). derived names. */
void FUN_00175a80(const hknpWorld *world, int threadIndex, const void *streamA, const void *streamB,
                  const void *array, const void *unknown, int flags);
void FUN_00175a80(const hknpWorld *world, int threadIndex, const void *streamA, const void *streamB,
                  const void *array);

struct hknpBodyQualityLibrary;
struct hknpBodyQuality;

/* derived name: one body integrated over a step (0xcd040; the attached
 * bodies' walk 0x5b490 runs it on each): the body, the step's argument, its
 * quality, then the world's vector at +0x250, its solver settings and its
 * data at +0x1f0. */
void FUN_000cd040(hknpBody *body, void *argument, const hknpBodyQuality *quality,
                  const Vec4 *vector, const hknpSolverInfo *solverInfo, void *data1f0);

struct hknpWorld {
    /* A body's angular velocity in world space: its motion's local one
     * rotated by the motion's orientation (0x5df30; the caller at
     * 0x16126e). derived name. */
    void FUN_0005df30(int bodyId, Vec4 &angularVelocityOut) const;

    /* Each body attached to a body integrated in turn, the first one
     * included (0x5b490). derived name. */
    void FUN_0005b490(int firstBodyId, void *argument);

    /* Two of the step's stages, run by the solve tasks under the timer
     * "Physics" (0x50fd0 by hknpPostSolveTask, 0x509f0 by hknpPreSolveTask).
     * derived names. */
    void FUN_00050fd0();
    /* A ray cast over the bodies under the "WorldCastRay" timer (0x35d40;
     * the projectile gun's 0x158bca and the game's casts call it). derived
     * name. */
    void FUN_00035d40(const void *query, hknpCollisionQueryCollector *collector) const;
    /* A shape cast over the bodies under the "WorldCastShape" timer
     * (0x35de0; the shape phantom's 0x156bd2 and 0x179440 call it).
     * derived names. */
    void FUN_00035de0(const void *query, const void *queryShapeOrientation,
                      hknpCollisionQueryCollector *collector,
                      hknpCollisionQueryCollector *startPointCollector) const;
    void FUN_000509f0();
    /* The stage after the collide tasks (0x505f0, run by
     * hknpPostCollideTask under the timer "StCollide"). derived name. */
    void FUN_000505f0();
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
    /* A constraint's bodies recorded with the object at +0x4f8 when the
     * flag at +0x4f0 is set (0x4d400, called at 0x4d329 and 0x4fc4f); unless
     * the third argument says not to, each of the two bodies that is in the
     * world, neither static nor active, is handed over first. derived
     * name. */
    void FUN_0004d400(const hknpConstraint *constraint, hkBool32 keepInactive);
    /* A body's motion's linear velocity, by reference (0x5df00). derived
     * name. */
    const Vec4 &FUN_0005df00(int bodyId) const; /* derived name */
    /* A body's motion's linear velocity and its angular velocity in world
     * space (0x5dbc0). derived name. */
    void FUN_0005dbc0(int bodyId, Vec4 &linearVelocityOut, Vec4 &angularVelocityOut) const;
    /* A motion's inverse inertia set from an inertia, its w kept (0x5f530;
     * the command dispatcher at 0x16efc4 passes the command's id and
     * vector). derived name. */
    void FUN_0005f530(int motionId, const Vec4 &inertia); /* derived name */

    /* Takes a body off the active list when it is active (flags bit 3), its
     * whole attached group when it heads one alone (0x4c720, called at
     * 0x5b725 and 0x5baf4). derived name. */
    void FUN_0004c720(const hknpBody *body);

    u8 unknown0[0x10];
    /* The bodies and their active list (0x4c720 passes +0x10 to the body
     * manager's functions and indexes the bodies at +0x20); FUN_0004c170 (in
     * this file's range) stores a body's motionId and indexes the bodies and
     * the motions. */
    hknpBodyManager bodyManager; /* derived name */
    u8 unknown110[8];
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
    hknpWorldObject1e0 *object1e0; /* derived name */
    u8 unknown1e8[8];
    u8 unknown1f0[0x60]; /* CollideSharedData's object40 points here */
    Vec4 vector250;
    /* Built by FUN_00174590 at 0x49ca9. derived name. */
    struct hknpWorldStreams260 *streams260;
    /* Handed first to the broad phase's pair walk (0x174eea). derived
     * name. */
    void *pointer268;
    u8 unknown270[8];
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
    u8 unknown500[0x128];
    /* The step's current stage (hknpPostCollideTask's work sets 8 before
     * its stage, 0x489ad). derived name. */
    int simulationStage;
    u8 unknown62c[4];
    /* The constructor copies it from hknpWorldCinfo's gravity (record at
     * 0x1698370, +0x60) at 0x48d84, and 0x4ae7e copies it back. */
    Vec4 gravity; /* derived name */
    u8 unknown640[8];
    /* The material library: the constructor subscribes 0x4bc60 to its
     * materialAddedSignal and 0x4bc40 to its materialModifiedSignal. */
    hknpMaterialLibrary *materialLibrary; /* derived name */
    u8 unknown650[8];
    hknpBodyQualityLibrary *qualityLibrary; /* derived name */
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
    /* To the 0x720 bytes its deleting destructor (0x4aff0) frees. */
    u8 unknown6d0[0x50];
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

    /* The class allocator's delete, for the guns derived from it too:
     * their deleting destructors free at the recorded size (0x156680 for
     * this class, 0x157ea0, 0x159600 and 0x1668a0 for the ball gun, the
     * projectile gun and the mounted ball gun). */
    static void operator delete(void *object, unsigned long numBytes);

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

    /* Its members from the records 0x3cd10 builds at 0x57c0080 (size
     * 0x38): type (enum of hkUint8, not serialized) at +0xc, name
     * (hkStringPtr) at +0x10, which slot 9 returns, keyboardKey (enum of
     * hkUint8) at +0x18, listeners (array of pointers, not serialized) at
     * +0x20 and collisionFilterInfo (hkUint32, not serialized) at +0x30.
     * hknpProjectileGun's first member sits at +0x34, in this class's
     * tail. */
    hkEnum<Type, u8> type;
    hkStringPtr name;
    u8 keyboardKey; /* an enum of hkUint8; its items not read */
    hkArray<void *> listeners;
    u32 collisionFilterInfo;
};

/* A projectile of a projectile gun (derived name): a reference-counted
 * object whose flags at +0xc mark it destroyed (bit 0; slot 13 of the gun
 * sets it after the projectile's slot 5) and touched in a step (bit 1,
 * cleared each step by 0x1598f0), its age at +0x14 (the gun's step adds the
 * time step before the projectile's slot 7). derived names. */
class hknpGunProjectile : public hkReferencedObject /* derived name */
{
  public:
    enum {
        FLAG_DESTROYED = 1 /* derived name */
    };

    /* Destroyed once: slot 5, then the flag (the gun's slots 10 and 13,
     * 0x159750 and 0x1597f0, inline it). derived name. */
    void destroy(hknpWorld *world)
    {
        if (!(flags & FLAG_DESTROYED)) {
            onDestroy(world);
            flags |= FLAG_DESTROYED;
        }
    }

    virtual void onDestroy(hknpWorld *world); /* vtable slot 5; derived name */
    virtual void unknownVirtual6();
    virtual void update(hknpWorld *world); /* vtable slot 7; derived name */

    u8 flags; /* derived name */
    u8 unknownD[7];
    float existenceTime; /* derived name */
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
    /* Slot 13 (0x1597f0): every projectile older than the time destroyed,
     * once. derived name. */
    virtual void FUN_001597f0(float time);
    /* Slot 10 (0x159750): every projectile destroyed in the gun's world and
     * released, the array emptied; the world argument is not read. */
    virtual void reset(hknpWorld *world);

    int maxProjectiles;
    float reloadTime;
    float reload;
    hkArray<hknpGunProjectile *> projectiles;
    hknpWorld *npWorld;
};

/* A ring of elements (derived name; Havok's queue, no string names it):
 * the storage at +0, its capacity at +8, the head and the tail at +0xc
 * and +0x10, the count at +0x14. The ball gun keeps its bullets' body ids
 * in one, made by its finish constructor (0x157e53). */
template <typename T>
struct hkQueue /* derived name */
{
    hkQueue() : data(0), capacity(0), head(0), tail(0), elementsInUse(0) {}

    /* From the thread's heap (tlg_lib_unknown.h). */
    static void *operator new(unsigned long numBytes);

    /* Room for n elements (0x157ca0 for body ids): a larger block, the
     * elements copied over in order from the head, the old block freed.
     * derived name. */
    void setCapacity(int n); /* derived name */

    T *data;           /* derived name */
    int capacity;      /* derived name */
    int head;          /* derived name */
    int tail;          /* derived name */
    int elementsInUse; /* derived name */
};

class hknpBallGun : public hknpFirstPersonGun
{
  public:
    /* The finish constructor, out of line (0x157e00). */
    hknpBallGun(hkFinishLoadedObjectFlag flag);

    virtual ~hknpBallGun();

    /* The record's members (0x1699d10), the first in hknpFirstPersonGun's
     * tail; the last five are not serialized (flags 0x400). */
    float bulletRadius;
    float bulletVelocity;
    float bulletMass;
    float damageMultiplier;
    int maxBulletsInWorld;
    Vec4 bulletOffsetFromCenter;
    hkQueue<hknpBodyId> *addedBodyIds;
    u16 materialId;
    u16 motionPropertiesId;
    void *bulletShape;
    u32 raiseContactEvents;
};

class hknpMountedBallGun : public hknpBallGun
{
  public:
    /* The finish constructor, out of line (0x166900). */
    hknpMountedBallGun(hkFinishLoadedObjectFlag flag);

    virtual ~hknpMountedBallGun();

    /* The record's member (0x1696c90). */
    Vec4 position;
};

/* hknpMotionProperties (type info 0x57bf510, no vtable; the shared empty
 * body FUN_000396a0 finishes it): 0x40 bytes, its hkClass's size (0x57bf4c0,
 * built at 0x39653), the members from its twenty records at 0x16948a0. */
struct hknpMotionProperties {
    u32 isExclusive;
    u32 flags;
    float gravityFactor;
    float timeFactor;
    float maxLinearSpeed;
    float maxAngularSpeed;
    float linearDamping;
    float angularDamping;
    float solverStabilizationSpeedThreshold;
    float solverStabilizationSpeedReduction;
    float maxDistSqrd;
    float maxRotSqrd;
    float invBlockSize;
    s16 pathingUpperThreshold;
    s16 pathingLowerThreshold;
    u8 numDeactivationFrequencyPasses;
    u8 deactivationVelocityScaleSquare;
    u8 minimumPathingVelocityScaleSquare;
    u8 spikingVelocityScaleThresholdSquared;
    u8 minimumSpikingVelocityScaleSquared;
};

/* The defaults its hkClass carries (0x14ba280): an offset into the block per
 * member, -1 for none and -2 for zero (derived reading), then the three
 * values under their members' record names. The rows are generated from
 * the executable (D18). */
struct hknpMotionPropertiesDefaults /* derived name */
{
    int defaultOffsets[20];
    float gravityFactor;
    float timeFactor;
    float solverStabilizationSpeedThreshold;
};

extern const hkClassMember D_16948a0[];         /* derived name: hknpMotionProperties's records */
extern const hkClassEnum D_1694c40[];           /* derived name: its two enums */
void FUN_000395c0(void *object, int finishing); /* derived name: its type info's finish callback */

/* hknpMotionPropertiesId, the motion properties library's handle (the
 * template argument of its free-list array in the scoped type names,
 * 0x14bf45a); fields not typed yet. */
struct hknpMotionPropertiesId;

/* The library's free-list operations (the name the scoped type names
 * spell): a free entry holds the next free index in its first word and
 * 0xff in numDeactivationFrequencyPasses (the library's add, 0x3718f and
 * 0x37195). */
struct hknpMotionPropertiesFreeListArrayOperations {
    static hkBool32 isEmpty(const hknpMotionProperties &element)
    {
        return element.numDeactivationFrequencyPasses == 0xff;
    }
};

/* hknpMotionPropertiesLibrary (type info 0x57bf0a0, vtable 0x1693770):
 * entryAddedSignal, entryModifiedSignal and entryRemovedSignal at +0x10,
 * +0x18 and +0x20 (not serialized, record flags 0x400, records from
 * 0x1694290) and entries, the motion properties' free-list array, at
 * +0x28. Its finish constructor 0x36de0 is out of line, jumped to by the
 * type info's finish callback 0x38c10 and called by the reflection
 * initializer at 0x38cc0; the signals start empty. */
struct hknpMotionPropertiesLibrary : public hkReferencedObject {
    /* 0x36d90: no entries, the signals empty. */
    hknpMotionPropertiesLibrary();

    hknpMotionPropertiesLibrary(hkFinishLoadedObjectFlag flag);

    /* Out of line (0x36c80, slot 0): the entries' storage, then the
     * signals; the deleting destructor (0x36cf0, slot 1) runs it and frees
     * through the class's delete. */
    virtual ~hknpMotionPropertiesLibrary();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

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

/* hkCompressedMassProperties (hkClass 0x57bc9e0, 0x20 bytes, no parent,
 * built at 0x22a90 from the record table 0x1691090): centerOfMass, inertia
 * and majorAxisSpace (hkInt16[4]) at +0, +8 and +0x10, mass and volume
 * (hkReal) at +0x18 and +0x1c. */
/* What hkCompressedMassProperties packs (derived names; no string names the
 * class): volume and mass at +0 and +4, the centre of mass at +0x10, the
 * diagonal of the inertia at +0x20 and its axes as a quaternion at +0x30
 * (0x26100 reads them so). */
struct hkDiagonalizedMassProperties /* derived name */
{
    /* Unpacked into full mass properties (0x26490; seven callers, the
     * shapes' mass builds among them): the inertia rebuilt as the axes'
     * rotation scaled by the diagonal times the rotation's transpose, then
     * the volume, the centre of mass and the mass. derived name. */
    void FUN_00026490(hkMassProperties &out) const;

    float volume;
    float mass;
    u8 unknown8[8];
    Vec4 centerOfMass;
    Vec4 inertiaTensor;
    hkQuaternion majorAxisSpace;
};

/* Every lane's sign bit (derived name), shared by the library's vector code. */
extern const Vec4 D_14b41d0;

struct hkCompressedMassProperties {
    /* Packed from the diagonalized properties (0x26100; the shapes' mass
     * builds call it): the centre of mass and the inertia as packed vectors,
     * the axes' quaternion in 16 bits a lane (30000 for one), the mass and
     * the volume as they are. derived name. */
    void FUN_00026100(const hkDiagonalizedMassProperties &properties);

    /* Unpacked into the diagonalized properties (0x263e0; the callers at
     * 0x157132, 0x161a9d and 0x161c1d): the two packed vectors, each lane's
     * 16 bits scaled by the exponent in the fourth, the mass and the volume,
     * and the quaternion back from its 16 bits a lane, normalized. derived
     * name. */
    void FUN_000263e0(hkDiagonalizedMassProperties &properties) const;

    s16 centerOfMass[4];
    s16 inertia[4];
    s16 majorAxisSpace[4];
    float mass;
    float volume;
};

/* hknpShapeMassProperties (hkClass 0x57bf240, 0x30 bytes, parent
 * hkReferencedObject; type info 0x57bf290, vtable 0x1693ef0): its finish
 * constructor 0x6fa80 is out of line, jumped to by the finish callback
 * FUN_00038d60 and called by the reflection initializer at 0x39094; it
 * stores only the vtable. One member in its record table 0x1694330,
 * compressedMassProperties at +0x10. */
class hknpShapeMassProperties : public hkReferencedObject
{
  public:
    hknpShapeMassProperties(hkFinishLoadedObjectFlag flag);

    /* Empty; the deleting destructor is 0x383f0, the body every vtable of a
     * 0x30-byte reference-counted class with an empty destructor cites
     * (D15: no citing class has other members beside it, and this vtable is
     * the lowest-address citer). */
    virtual ~hknpShapeMassProperties();

    static void operator delete(void *object, unsigned long numBytes);

    hkCompressedMassProperties compressedMassProperties;
};

/* hknpPhysicsSceneData (hkClass 0x57bf310, 0x28 bytes, parent
 * hkReferencedObject, two members in its record table at 0x1694550; type
 * info 0x57bf360, vtable 0x1697ea0): its finish constructor 0x46790 is out of
 * line, jumped to by the finish callback FUN_00039190 and called by the
 * reflection initializer at 0x39288; it stores only the vtable. */
class hknpPhysicsSystemData;
class hknpRefWorldCinfo;

class hknpPhysicsSceneData : public hkReferencedObject
{
  public:
    hknpPhysicsSceneData(hkFinishLoadedObjectFlag flag);
    virtual ~hknpPhysicsSceneData();

    /* The record's two members: an array of reference pointers to the
     * systems at +0x10, a reference pointer to the world's construction
     * info at +0x20; the destructor 0x467f0 (slot 0) releases each, the
     * array's last element first. */
    hkArray<hknpPhysicsSystemData *> systemDatas;
    hknpRefWorldCinfo *worldCinfo;
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

/* hknpMotionCinfo (records from 0x1696b00, type uint16 for the id): the
 * construction info of a body's motion, 0x60 bytes. */
struct hknpMotionCinfo {
    /* Out of line (0x1590a0, called by the world at 0x4e3af, 0x4f14e and
     * 0x5c618, and by the game): no motion properties, deactivation on, a
     * unit mass and inertia, no limit to speak of, at rest at the origin
     * with no rotation (rows 3 and 32 of the vector constant table). */
    hknpMotionCinfo();

    u16 motionPropertiesId;
    hkBool enableDeactivation;
    float inverseMass;
    float maxLinearAccelerationDistancePerStep;
    float maxRotationPerStep;
    Vec4 inverseInertiaLocal;
    Vec4 centerOfMassWorld;
    hkQuaternion orientation;
    Vec4 linearVelocity;
    Vec4 angularVelocity;
};

/* Its members' defaults (the hkClass's, at 0x14bb668): each member's offset
 * into the values, -1 for one without a default, then the values, a vector
 * as four floats. derived name. */
struct hknpMotionCinfoDefaults /* derived name */
{
    int defaultOffsets[10];
    bool enableDeactivation;
    float inverseMass;
    float maxLinearAccelerationDistancePerStep;
    float maxRotationPerStep;
    float centerOfMassWorld[4];
    float orientation[4];
    float linearVelocity[4];
    float angularVelocity[4];
};

extern const hkClassMember D_1696b00[]; /* derived name: hknpMotionCinfo's records */

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

    /* Slot 10 (0x16ae20, the vtables 0x16a5390 and 0x16a54a0): the core
     * convex shape's vertices scaled and moved into the buffer, each
     * keeping its w; the buffer is returned. derived name. */
    const Vec4 *FUN_0016ae20(Vec4 *HK_RESTRICT buffer, int bufferSize) const;

    /* Slot 17 (0x16ad80, both vtables): the core shape's value scaled by
     * the smallest magnitude of the scale's direction. derived name. */
    float FUN_0016ad80() const;

    /* Slot 12 (0x16ae80, both vtables): the core convex shape's vertices by
     * index, then each of the count scaled and moved, its w kept. derived
     * name. */
    void FUN_0016ae80(const u8 *indices, int numIndices, Vec4 *verticesOut) const;

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
    enum { DONT_DEALLOCATE_FLAG = int(0x80000000) }; /* derived name */

    /* A 12-byte entry (derived names): the pair of body ids it is keyed
     * by, both 0x7fffffff when the slot is empty (0x167b64 stops its probe
     * at one), and the value. */
    struct Pair {
        u32 bodyIdA;
        u32 bodyIdB;
        u32 value;
    };

    /* An empty map: no storage, no elements, the hash modulus -1. */
    hknpPairCollisionFilterMapPairFilterKeyOverrideType() : elem(0), numElems(0), hashMod(-1) {}

    /* Every slot emptied and the count zeroed, the storage kept; each entry
     * read once for both halves of its key (0x167193). derived name. */
    void clear()
    {
        const int capacity = hashMod + 1;
        for (int i = 0; i < capacity; i++) {
            Pair &entry = elem[i];
            entry.bodyIdA = 0x7fffffff;
            entry.bodyIdB = 0x7fffffff;
        }
        numElems &= DONT_DEALLOCATE_FLAG;
    }

    /* Every slot emptied and the storage given back to the allocator
     * unless the map does not own it, then no storage (0x167170, called by
     * the constraint filter's destructor at 0x159c6f with the containers'
     * allocator). derived name. */
    void FUN_00167170(AllocatorBase &allocator);

    Pair *elem;
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

    /* How far past an owner the elements end (the polytope's size, 0x1520f0,
     * takes the farthest of its arrays'). derived name. */
    int endOffset(const void *owner) const
    {
        return int(reinterpret_cast<const char *>(this) - static_cast<const char *>(owner)) +
               offset + size * int(sizeof(T));
    }

    /* The elements, `offset` bytes from the array itself, the address
     * computed as an integer (the scaled shapes' slot 10, 0x16ae30, adds
     * the offset to it, not it to the offset). */
    const T *begin() const
    {
        return reinterpret_cast<const T *>(hkUlong(this) + offset);
    }

    /* The same through a character pointer, the offset added to the
     * array's address (the convex shape's finish constructor, 0x42ec4,
     * folds the array's place into its loop's start). derived name. */
    T *beginBytes()
    {
        return reinterpret_cast<T *>(reinterpret_cast<char *>(this) + offset);
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
    int mode;     /* derived name */
    hkBool flag4; /* the compressed mesh's walk's last argument (0x127a97); derived name */
    u8 unknown5[0x1b];
    Vec4 scale;  /* derived name */
    int value30; /* the compressed mesh's query's +0x20 (0x127a70); derived name */
    u8 unknown34[0xc];
    Vec4 offset; /* derived name */
};

class hknpConvexShape;

/* derived names: a count the convex shape's vertices give (0x1707d0,
 * from the vertex count in 32-vertex blocks), and a build over a set of
 * vertices with a radius that reports whether it failed (0x168d90). The
 * convex and scaled convex shapes' slot 28 call both (0x45a20, 0x16cd81). */
int FUN_001707d0(const hknpConvexShape *shape);
hkResult FUN_00168d90(const void *argument1, const Vec4 *vertices, int numVertices, void *argument2,
                      float convexRadius);

/* A table of byte masks (derived name; 00 00 00 ff ff ff in the image)
 * the convex shapes' slot 12 reads at a position and the one after. */
extern const u8 D_16dc600[];

/* Three vertices by their indices, the second and third masked by the
 * table from a position (derived name): the convex shapes' slot 12 and the
 * scaled convex shapes' (0x16aeac, inline) take them this way. */
inline void verticesByIndex(const Vec4 *v, const u8 *indices, int position,
                            Vec4 *verticesOut) /* derived name */
{
    const Vec4 v0 = v[indices[0]];
    const Vec4 v1 = v[indices[1] & D_16dc600[position + 1]];
    const Vec4 v2 = v[indices[2] & D_16dc600[position]];
    verticesOut[0] = v0;
    verticesOut[1] = v1;
    verticesOut[2] = v2;
}

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
    /* Slot 15 (0x45af0; also the sphere's): a face's plane through slot 14
     * and its four vertices, the face's index a byte per vertex, the
     * highest first; four back. derived name. */
    int FUN_00045af0(int faceIndex, Vec4 *planeOut, Vec4 *verticesOut) const;
    /* Slot 12 (0x3c4e0; also the sphere's, triangle's and convex
     * polytope's): three of the vertices by the indices, the second and
     * third masked by the table at 0x16dc600 from a position. derived
     * name. */
    void FUN_0003c4e0(const u8 *indices, int position, Vec4 *verticesOut) const;
    int
    FUN_00045a80(u32 *argument1, int argument2, int argument3,
                 const ShapeKeyQuery000380b0 &argument4) const; /* vtable slot 21; derived name */
    void FUN_00045aa0(const u32 *keys, int numKeys,
                      hknpShapeSlot22Output *output) const; /* vtable slot 22; derived name */
    /* Slot 28 (0x45a20; also the convex polytope's): the vertices handed
     * to FUN_00168d90 with the convex radius, the shape's default (0x6fc70)
     * when that fails. derived name. */
    void FUN_00045a20(const void *argument1, void *argument2) const;
    /* Slot 29, kept by the convex, triangle, convex polytope and scaled
     * convex shapes' vtables. */
    void FUN_000430f0(const hknpShapeSlot29Input &input,
                      void *output) const; /* vtable slot 29; derived name */

    hkRelArray<Vec4> vertices;
};

/* The settings a convex shape is built under (derived name; 0x451e0 tests
 * the byte at +4, the vertex builder 0x44710 copies all 0x38 bytes). Its
 * constructor 0x42f50 sets the defaults (the library's builder at 0x178912
 * and the game's at 0xea52df and six more sites build one on the stack);
 * the fields' meanings are not read yet. derived names. */
struct ConvexBuildConfig000451e0 /* derived name */
{
    ConvexBuildConfig000451e0();

    float unknown0;
    hkBool unknown4;
    float unknown8;
    hkBool unknownC;
    hkBool unknownD;
    int unknown10;
    float unknown14;
    float unknown18;
    void *unknown20;
    int unknown28;
    int unknown2c;
    hkBool unknown30;
    hkBool unknown31;
    hkBool unknown32;
};

/* derived names: a convex shape of the box between an AABB's corners with a
 * convex radius (0x451e0), and of the box of half extents about the origin,
 * through it (0x45190, called by the game at 0xea6a21, 0xea6f1f and
 * 0xeaabb8). */
hknpConvexShape *FUN_000451e0(const hkAabb &aabb, float convexRadius,
                              const ConvexBuildConfig000451e0 &config);
hknpConvexShape *FUN_00045190(const Vec4 &halfExtents, float convexRadius,
                              const ConvexBuildConfig000451e0 &config);

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

    /* Out of line (0x72e50, slot 0 of its vtable and of the capsule's and
     * the triangle's): the connectivity's reference released, then
     * hknpShape's destructor. */
    virtual ~hknpConvexPolytopeShape();

    /* hknpConvexPolytopeShape::Face (records from 0x1694e60): firstIndex
     * (hkUint16) at +0, numIndices and minHalfAngle (hkUint8) at +2 and
     * +3. */
    struct Face {
        u16 firstIndex;
        u8 numIndices;
        u8 minHalfAngle;
    };
    class Connectivity;

    /* Slot 6 (0x1520f0): the object's size, to the end of the farthest of
     * its four arrays rounded up to 16, never less than the class. derived
     * name. */
    int FUN_001520f0() const;
    int FUN_00072f70() const; /* vtable slot 13; derived name */
    /* Slot 14 (0x72f80, kept by the capsule and triangle shapes): a face's
     * plane and its minimum half angle. derived name. */
    void FUN_00072f80(int faceIndex, Vec4 &planeOut, hknpFaceAngle &minAngleOut) const;

    /* Slot 17 (0x1540a0, kept by the triangle shape): the smallest face
     * angle. derived name. */
    float FUN_001540a0() const;

    /* The bytes a polytope shape of a class of sizeOfBaseClass bytes
     * needs with its vertices, faces, planes and indices after it, each
     * block rounded up to 16 (0x1542f0). derived names. */
    static int FUN_001542f0(int numVertices, int numFaces, int numIndices,
                            int sizeOfBaseClass); /* derived name */

    hkRelArray<Vec4> planes;
    hkRelArray<Face> faces;
    hkRelArray<u8> indices;
    /* A counted reference: the destructor releases it. */
    hkRefPtr<Connectivity> connectivity;
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

    /* Slot 10 (0x731a0): eight points evenly along the segment from a to b,
     * each with its index in the w lane (the 0.5 exponent bits over it).
     * derived name. */
    const Vec4 *FUN_000731a0(Vec4 *buffer, int bufferSize) const;

    /* Slot 28 (0x73110): the capsule's own answer from its segment and
     * convex radius; the shape's default when that fails. derived name. */
    void FUN_00073110(const void *argument1, void *argument2) const;

    Vec4 a;
    Vec4 b;
};

/* The capsule's counterpart of FUN_00168340 (0x1683d0): 1 when it cannot
 * answer and nothing is written. derived names. */
int FUN_001683d0(const void *argument1, const Vec4 &a, const Vec4 &b, float radius,
                 void *argument2); /* derived name */

/* hknpSphereShape (type info 0x57c2798, vtable 0x1695c10) over
 * hknpConvexShape, and hknpTriangleShape (type info 0x57c0838, vtable
 * 0x169b670) over hknpConvexPolytopeShape: finish constructors out of line
 * (0x3c540, 0x78230), jumped to by the finish callbacks FUN_0006b6b0 and
 * FUN_0003e730. */
/* Fills the second argument from the first for a sphere of a centre and a
 * radius (0x168340; the sphere's slot 28 is its one caller): 1 when the
 * radius is not positive and nothing is written, 0 otherwise. derived
 * names. */
int FUN_00168340(const void *argument1, const Vec4 &center, float radius,
                 void *argument2); /* derived name */

class hknpSphereShape : public hknpConvexShape
{
  public:
    hknpSphereShape(hkFinishLoadedObjectFlag flag);

    /* Slot 28 (0x3c670): the sphere's own answer from its centre, the first
     * vertex, and its convex radius; the shape's default when that fails.
     * derived name. */
    void FUN_0003c670(const void *argument1, void *argument2) const;
};

/* The triangle's and the quad's counterparts of FUN_00168340 (0x1684a0 over
 * three vertices, 0x168590 over four): 1 when they cannot answer. derived
 * names. */
int FUN_001684a0(const void *argument1, const Vec4 *vertices, float radius,
                 void *argument2); /* derived name */
int FUN_00168590(const void *argument1, const Vec4 *vertices, float radius,
                 void *argument2); /* derived name */

class hknpTriangleShape : public hknpConvexPolytopeShape
{
  public:
    hknpTriangleShape(hkFinishLoadedObjectFlag flag);

    /* The vertices as the triangle's own code reaches them: the array's
     * byte offset added to its address as a character pointer, where
     * hkRelArray::begin() sums integers. The base's triangle functions
     * hold the offset as the base register (0x78393, 0x78511) where the
     * sphere's and the convex shape's hold the shape (0x3c683, 0x45a38);
     * the character pointer gives the triangle's form, the integer sum the
     * scaled shapes' (0x16ae30). derived name. */
    const Vec4 *getVertices() const
    {
        return reinterpret_cast<const Vec4 *>(reinterpret_cast<const char *>(&vertices) +
                                              vertices.offset);
    }

    /* A quad when the fourth vertex is its own: its index, the 16 bits of
     * the w lane's low half, is 3 (a triangle repeats a vertex there).
     * derived name. */
    bool isQuad() const
    {
        return reinterpret_cast<const s16 *>(&getVertices()[3])[6] == 3;
    }

    /* Slot 28 (0x78380): the triangle's or quad's own answer from its
     * vertices and convex radius; the shape's default when that fails.
     * derived name. */
    void FUN_00078380(const void *argument1, void *argument2) const;
};

/* hknpConvexPolytopeShape::Connectivity (scoped name of the type info;
 * vtable 0x1694e20, finish callback FUN_00039ae0): the shape's
 * connectivity pointer at +0x38 refers to one. */
class hknpConvexPolytopeShape::Connectivity : public hkReferencedObject
{
  public:
    /* hknpConvexPolytopeShape::Connectivity::Edge (hkClass 0x57bf610,
     * built at 0x39c56: 4 bytes, records 0x1694ee0). */
    struct Edge {
        u16 faceIndex;
        u8 edgeIndex;
    };

    Connectivity(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), vertexEdges(flag), faceLinks(flag)
    {
    }

    /* The arrays given back (0x39950, slot 0; the deleting destructor
     * 0x399d0 holds the same body). Inline, emitted with the vtable where
     * the object is built (the finish callback 0x39ae0): the executable
     * holds the complete destructor before the deleting one (cookbook
     * 187). */
    inline virtual ~Connectivity() {}

    /* The reference-counted class delete (freeReferencedObject in
     * tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    /* From its records at 0x1694f30 (hkClass 0x57bf690, 0x30 bytes). */
    hkArray<Edge> vertexEdges;
    hkArray<Edge> faceLinks;
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

/* Its type info's callbacks (0x46c60, 0x46c70): the finish constructor and
 * the destructor above. derived names. */
void FUN_00046c60(void *object, int finishing); /* derived name */
void FUN_00046c70(void *object);                /* derived name */

/* The defaults its hkClass carries (0x14bd370): an offset into the block per
 * member, -1 for none and -2 for zero (derived reading), then the values,
 * each under its member's record name; the booleans one byte each, the
 * gravity four floats. The rows are generated from the executable (D18). */
struct hknpWorldCinfoDefaults /* derived name */
{
    int defaultOffsets[33];
    int bodyBufferCapacity;
    int motionBufferCapacity;
    int constraintBufferCapacity;
    u8 simulationType;
    int numSplitterCells;
    float gravity[4];
    u8 enableContactCaching;
    u8 mergeEventsBeforeDispatch;
    float collisionTolerance;
    float solverTau;
    float solverDamp;
    int solverIterations;
    int solverMicrosteps;
    float defaultSolverTimestep;
    float maxApproachSpeedForHighQualitySolver;
    u8 enableDeactivation;
    float unitScale;
    u8 applyUnitScaleToStaticConstants;
};

extern const hkClassMember D_1698190[]; /* derived name: hknpWorldCinfo's records */
extern const hkClassEnum D_1698770[];   /* derived name: its enum */

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

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

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

/* hknpMalleableConstraintData's finish constructor (0x67960, the class's
 * constructor below), called by name from its finish callback while the
 * class has pure slots this header does not override (as the breakable
 * data's). derived name. */
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

    /* The reference-counted class delete (tlg_lib_unknown.h): its deleting
     * destructor 0x70f70 frees at the recorded size, 0x220 by default. */
    static void operator delete(void *object, unsigned long numBytes);

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

extern const hkClassMember D_168d1c0[]; /* derived name: hkQTransformf's records */
extern const hkClass D_57b7f68;         /* hkQTransformf's hkClass */

/* hkMultiThreadCheck (hkClass 0x57b75a0, built at 0x1490: size 0xc, no
 * parent, two enums and four members, none serialized, from the records at
 * 0x168c5b0 and 0x168c4c0). */
struct hkMultiThreadCheck {
    u32 threadId;
    int stackTraceId;
    u16 markCount;
    u16 markBitStack;
};

extern const hkClassMember D_168c4c0[]; /* derived name: hkMultiThreadCheck's records */
extern const hkClassEnum D_168c5b0[];   /* derived name: its two enums */

/* hkUFloat8 (the reflection's type name in the material's records; hkClass
 * 0x57b7620, built at 0x156d: size 1, its one record at 0x168c600 names
 * value): an unsigned float in eight bits. */
struct hkUFloat8 {
    /* Out of line (0x935b0, called by the material's constructor and the
     * constraint datas' at 0x77650 to 0x17b2e2): the code of the nearest
     * value not above the float. derived name. */
    hkUFloat8 &operator=(const float &value);

    u8 value;
};

/* hkContactPointMaterial (hkClass 0x57b7d98, built at 0x8073: size 0x10, no
 * parent, one enum and five members from the records at 0x168cfc0, their
 * defaults at 0x14b31d0, version 1). */
struct hkContactPointMaterial {
    hkUlong userData;
    hkUFloat8 friction;
    u8 restitution;
    hkUFloat8 maxImpulse;
    u8 flags;
};

/* Its members' defaults: each member's offset into the values, -1 for one
 * without a default and -2 for zero (no values follow). derived name. */
struct hkContactPointMaterialDefaults /* derived name */
{
    int defaultOffsets[5];
};

extern const hkClassMember D_168cfc0[]; /* derived name: hkContactPointMaterial's records */
extern const hkClassEnum D_168d0d0[];   /* derived name: its one enum */

/* hkMotionState (hkClass 0x57b9138, built at 0x107fd: size 0xb0, no parent,
 * version 3, ten member records at 0x168df50). */
struct hkMotionState {
    hkTransform transform;
    Vec4 sweptTransform[5];
    Vec4 deltaAngle;
    float objectRadius;
    hkHalf linearDamping;
    hkHalf angularDamping;
    hkHalf timeFactor;
    hkUFloat8 maxLinearVelocity;
    hkUFloat8 maxAngularVelocity;
    u8 deactivationClass;
};

extern const hkClassMember D_168df50[]; /* derived name: hkMotionState's records */

/* hknpMaterial (type info 0x57c1f40, no vtable, cleanup 0x300) and
 * hknpMaterialDescriptor (type info 0x57c1fc0, no vtable, cleanup 0x66e80):
 * each finish constructor (FUN_0006c6f0, FUN_0006c800) runs hkStringPtr's on
 * the name at +0. */
struct hknpMaterial {
    /* Inline where hknpRefMaterial's finish constructor and destructor run
     * them (0x6c7e0, 0x6c5d0 finish and destroy the name directly). */
    hknpMaterial(hkFinishLoadedObjectFlag flag) : name(flag) {}

    /* Out of line (0x6c700; the material library's copies at 0x776d0,
     * 0x77976 and 0x77a8f): the name copied as a string, the rest as bytes. */
    hknpMaterial(const hknpMaterial &other);

    /* Out of line (0x6c650): the default material (its values in the
     * definition). */
    hknpMaterial();

    /* The trigger types and the combine policies (the items of the enums
     * TriggerType and CombinePolicy, 0x1699970 and 0x16999b0). */
    enum TriggerType {
        TRIGGER_TYPE_NONE,
        TRIGGER_TYPE_BROAD_PHASE,
        TRIGGER_TYPE_NARROW_PHASE,
        TRIGGER_TYPE_CONTACT_SOLVER
    };

    enum CombinePolicy { COMBINE_AVG, COMBINE_MIN, COMBINE_MAX };

    /* The flags the material keeps in step with its values (bits 20 to
     * 25, 0x6c740); the rest of the word is the user's. derived names. */
    enum Flags {
        ENABLE_RESTITUTION = 1 << 20,      /* derived name */
        ENABLE_TRIGGER = 1 << 21,          /* derived name */
        ENABLE_IMPULSE_CLIPPING = 1 << 22, /* derived name */
        ENABLE_MASS_CHANGER = 1 << 23,     /* derived name */
        ENABLE_SOFT_CONTACTS = 1 << 24,    /* derived name */
        ENABLE_SURFACE_VELOCITY = 1 << 25, /* derived name */
        AUTO_FLAGS_MASK = 0x3f << 20       /* derived name */
    };

    /* The automatic flags set from the values (0x6c740; the library's
     * copies at 0x776d8 and 0x77a97 call it after each copy). derived
     * name. */
    void FUN_0006c740();

    /* The members from the records 0x66f10 builds (names and offsets from
     * its stores, 0x66f10 to 0x676a0). */
    hkStringPtr name;
    u32 isExclusive;
    u32 flags;
    u8 triggerType; /* an enum of hkUint8, TRIGGER_TYPE_NONE first */
    hkUFloat8 triggerManifoldTolerance;
    hkHalf dynamicFriction;
    hkHalf staticFriction;
    hkHalf restitution;
    u8 frictionCombinePolicy;    /* an enum of hkUint8 */
    u8 restitutionCombinePolicy; /* an enum of hkUint8 */
    hkHalf weldingTolerance;
    float maxContactImpulse;
    float fractionOfClippedImpulseToApply;

    /* massChangerCategory (an hkEnum of hkUint8, its items from 0x16999e0)
     * and massChangerHeavyObjectFactor (hkHalf) at +0x24 and +0x26, from the
     * records 0x66f10 builds (0x673ad, 0x6740b). */
    enum MassChangerCategory { MASS_CHANGER_IGNORE, MASS_CHANGER_DEBRIS, MASS_CHANGER_HEAVY };

    u8 massChangerCategory;
    u8 unknown25;
    hkHalf massChangerHeavyObjectFactor;
    hkHalf softContactForceFactor;
    hkHalf softContactDampFactor;
    hkUFloat8 softContactSeperationVelocity; /* the record's spelling */
    u8 unknown2d[3];
    hknpSurfaceVelocity *surfaceVelocity;
    hkHalf disablingCollisionsBetweenCvxCvxDynamicObjectsDistance;
    u8 unknown3a[6];
    u64 userData;
    hkBool isShared;
    u8 unknown49[7];
};

/* The material library's free-list operations (the name the scoped type
 * names spell): a free material has a negative maxContactImpulse (the
 * library's destructor skips those, 0x612f8). */
struct hknpMaterialFreeListArrayOperations {
    static hkBool32 isEmpty(const hknpMaterial &material)
    {
        return material.maxContactImpulse < 0.0f;
    }
};

class hknpRefMaterial;

/* Members from its record table at 0x16998c0: name, material (a
 * reference-counted pointer) and materialId. */
struct hknpMaterialDescriptor {
    /* The cleanup callback of its type info (0x66e80; hkxAttribute's, the
     * same layout to +0x10, holds the same body): the material's
     * reference released, then the name destroyed. derived name. */
    static void FUN_00066e80(void *object);

    /* The material's reference released (after hknpRefMaterial, below);
     * the name is destroyed after it. */
    inline ~hknpMaterialDescriptor();

    hkStringPtr name;
    hknpRefMaterial *material;
    u16 materialId;
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

    /* The reference-counted class delete (tlg_lib_unknown.h): its deleting
     * destructor 0x6c5f0 frees at the recorded size, 0x60 by default. */
    static void operator delete(void *object, unsigned long numBytes);

    hknpMaterial material;
};

inline hknpMaterialDescriptor::~hknpMaterialDescriptor()
{
    if (material) {
        material->removeReference();
    }
    material = 0;
}
class hknpBallGun; /* 0x57c20c0; FUN_00157e00 runs hknpFirstPersonGun's, vtable 0x16a48d0 */
class hknpBreakableConstraintData; /* 0x57c23f8; FUN_0003c240 runs 0x7d520, vtable 0x1695b10 */
class hknpCompressedMeshShape;     /* 0x57c26c8; its finish constructor 0x158610 (below) */

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

/* hknpCompositeShape: its hkClass at 0x57c2cf8 (parent 0x57bf1c0) is built by
 * the reflection initializer at 0x71732, whose type info names the vtable
 * 0x1697c80 (address point 0x1697c90), the intermediate base whose vtable the
 * finish constructors of hknpLodShape, hknpCompressedHeightFieldShape and
 * hknpCompressedMeshShape store before their own. Slot 3 (FUN_00042e80)
 * returns it, and six derived vtables (0x1699c10, 0x16a3e40, 0x16a49a0,
 * 0x16a5180, 0x16a5990, 0x16ca050) keep it. */
extern const hkClass D_57c2cf8; /* hknpCompositeShape's hkClass */

/* hknpSparseCompactMap<hkUint16> (hkClass 0x57bef50, built at 0x38a8d:
 * 0x28 bytes, no parent; records at 0x16941a0). The second member's
 * spelling is the record's string. */
template <typename T> struct hknpSparseCompactMap {
    /* An empty map: the arrays empty, then the key mask all ones and no
     * secondary key bits (inline in hknpCompositeShape's constructor,
     * 0x42e34 to 0x42e67). */
    hknpSparseCompactMap()
    {
        secondaryKeyMask = 0xffffffff;
        sencondaryKeyBits = 0;
    }

    /* A loaded image's map is left as loaded. */
    hknpSparseCompactMap(hkFinishLoadedObjectFlag flag)
        : primaryKeyToIndex(flag), valueAndSecondaryKeys(flag)
    {
    }

    u32 secondaryKeyMask;
    u32 sencondaryKeyBits;
    hkArray<u16> primaryKeyToIndex;
    hkArray<u16> valueAndSecondaryKeys;
};

/* The cleanup callback of its type info (0x57befa0): the map destroyed in
 * place (0x389a0). derived name. */
void FUN_000389a0(void *object); /* derived name */

extern const hkClassMember D_16941a0[]; /* derived name: the map's records */

class hknpCompositeShape : public hknpShape
{
  public:
    /* Inline: the type info's finish callback FUN_00071690 runs it, and
     * hknpLodShape's finish constructor (0x68160) inlines it before storing
     * its own vtable. */
    /* A new composite shape, out of line (0x42e00; hknpCompoundShape's
     * constructor 0x412a0 and hknpExternMeshShape's 0x166010 call it):
     * dispatch type 2, an empty edge welding map, no shape tag codec. */
    hknpCompositeShape();

    hknpCompositeShape(hkFinishLoadedObjectFlag flag) : hknpShape(flag), edgeWeldingMap(flag)
    {
        if (flag.finishing) {
            flags |= 4;
        }
    }

    /* Inline: hknpCompoundShape's destructor holds it (0x417cc, the
     * vtable, then the edge welding map's arrays); the vtable's slot 0 is
     * the copy every user emits (0x42c90, beside the constructor). */
    virtual ~hknpCompositeShape() {}

    const hkClass *getClassType() const; /* vtable slot 3, FUN_00042e80 */

    /* The members from the records at 0x169b1d0 (the hkClass is 0x60
     * bytes, its members end at +0x54; a derived class's first member
     * goes in the tail from +0x54, hknpLodShape's numLevelsOfDetail). */
    hknpSparseCompactMap<u16> edgeWeldingMap;
    u32 shapeTagCodecInfo; /* hkUint32 in the record */
};

/* hknpCompressedMeshShape (its records at 0x169aa40: data, a pointer to
 * hknpCompressedMeshShapeData, at +0x58; quadIsFlat and triangleIsInterior
 * at +0x60 and +0x78; numTriangles at +0x90): FUN_0010bf40 returns the mesh
 * tree's domain, which slot 7 of its vtable (0x158840, address point
 * 0x16a49a0) transforms into the AABB it reports (0x94060). */
class hknpCompressedMeshShape : public hknpCompositeShape
{
  public:
    /* The finish constructor, out of line (0x158610; the row of the
     * vtable's type info names it). */
    hknpCompressedMeshShape(hkFinishLoadedObjectFlag flag);

    virtual ~hknpCompressedMeshShape();

    /* What a loaded shape sets up after its members: the word at +0x90
     * cleared and the data's triangles walked (0x10be70). derived name. */
    void FUN_0010be70();

    const hkAabb *FUN_0010bf40() const; /* derived name */
    /* Slot 20 (0x117200): a new key mask over the shape, its filter built
     * by the mesh tree with every key enabled. derived name. */
    hknpShapeKeyMask *FUN_00117200() const;
    void FUN_00158840(const Mat4 &transform,
                      hkAabb &aabbOut) const; /* vtable slot 7; derived name */
    /* Slot 29 (0x127a50): the mesh tree walked with a query over the input.
     * derived name. */
    int FUN_00127a50(const hknpShapeSlot29Input &input, void *collector) const;

    hknpCompressedMeshShapeData *data;
    /* The rest of the record's members (0x169aa40); the counts are not
     * serialized (flags 0x400). */
    hkBitField quadIsFlat;
    hkBitField triangleIsInterior;
    int numTriangles;
    int numConvexShapes;
    u8 unknown98[8]; /* to the record's 0xa0 bytes */
};

float FUN_00073940(const hknpCapsuleShape *self); /* derived name */

/* hknpExternMeshShape (type info 0x57c28e8, size 0x70): its finish
 * constructor runs hknpShape's, stores 0x1697c80, sets bit 2 of the byte at
 * +0x10 when finishing, then stores its own vtable 0x16a5170. Its records
 * (0x169abc0, the hkClass 0x57c2898 built at 0x6c4f8 over
 * hknpCompositeShape's): geometry (a pointer to hknpExternMeshShape::Geometry)
 * at +0x60, boundingVolumeData (a pointer to hknpExternMeshShapeData) at
 * +0x68. */
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

    hknpBroadPhaseConfig() {}

    hknpBroadPhaseConfig(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}

    virtual ~hknpBroadPhaseConfig();
};

class hknpDefaultBroadPhaseConfig : public hknpBroadPhaseConfig
{
  public:
    /* 0x154da0 (the world's constructor builds one at 0x499bf when its
     * description gives none): the four layers filled. */
    hknpDefaultBroadPhaseConfig();

    hknpDefaultBroadPhaseConfig(hkFinishLoadedObjectFlag flag);

    Layer *FUN_00154e00(hkUlong layerIndex); /* vtable slot 6; derived name */
    /* Slot 7 (0x154e10): each body's layer from its flags, by the first
     * of bits 8, 3 and 0 it has: 1, 0, 3, and 2 for none. derived name. */
    void FUN_00154e10(const struct hknpBodyId *bodyIds, int numBodyIds, const hknpBody *bodies,
                      u8 *layersOut) const;

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

    /* A new constraint data: no user data (inline in hkpWrappedConstraintData's
     * constructor, 0x7d557). */
    hkpConstraintData() : userData(0) {}

    /* The class allocator's delete, which the constraint data classes
     * share (tlg_lib_unknown.h's reference-counted form): their deleting
     * destructors free through it (0x7b3b0 for the 0xc0-byte ones). */
    static void operator delete(void *object, unsigned long numBytes);

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

    u8 unknownC[4];
    hkUlong userData; /* the record's member (0x169d660) */
};

extern const hkClass D_57c45a8; /* hkpConstraintData's hkClass */
/* Its one enum and its one member record (userData), which the
 * reflection initializer 0x7f3f0 passes. */
extern const hkClassEnum D_169d860[];   /* derived name */
extern const hkClassMember D_168c370[]; /* derived name: hkFloat16Transform's records */
extern const hkClassMember D_168c3e0[]; /* derived name: hkSphere's records */
extern const hkClassMember D_168c600[]; /* derived name: hkUFloat8's records */
extern const hkClassMember D_168d280[]; /* derived name: hkTraceStreamTitle's records */
extern const hkClassMember D_168d650[]; /* derived name: hkFourTransposedPointsf's records */
extern const hkClassMember D_168d9b0[]; /* derived name: hkContactPoint's records */
extern const hkClassMember D_168e150[]; /* derived name: hkAabbHalf's records */
extern const hkClassMember D_168e3c0[]; /* derived name: hkAabb16's records */
extern const hkClassMember D_168e4e0[]; /* derived name: hkSweptTransformf's records */
extern const hkClassMember D_168eb40[]; /* derived name: hkFloat16's records */
extern const hkClassMember D_1691090[]; /* derived name: hkCompressedMassProperties's records */
extern const hkClassMember D_16945d0[]; /* derived name: hknpMotion's records */
extern const hkClassMember D_16a2bc0[]; /* derived name: hkPackfileHeader's records */
extern const hkClassMember D_16a2dd0[]; /* derived name: hkPackfileSectionHeader's records */
extern const hkClassMember D_169d660[]; /* derived name */

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
    /* AtomType (its items from 0x169ea70), the ones the constructors
     * store. */
    enum AtomType {
        TYPE_BRIDGE = 1,
        TYPE_SET_LOCAL_TRANSFORMS = 2,
        TYPE_SET_LOCAL_TRANSLATIONS = 3,
        TYPE_SET_LOCAL_ROTATIONS = 4,
        TYPE_BALL_SOCKET = 5,
        TYPE_STIFF_SPRING = 6,
        TYPE_LIN = 7,
        TYPE_2D_ANG = 12,
        TYPE_ANG = 13,
        TYPE_ANG_LIMIT = 14,
        TYPE_ANG_FRICTION = 17,
        TYPE_PULLEY = 20,
        TYPE_RACK_AND_PINION = 21,
        TYPE_COG_WHEEL = 22,
        TYPE_SETUP_STABILIZATION = 23
    };

    enum SolvingMethod { METHOD_STABILIZED = 0, METHOD_OLD = 1 };
};

/* hkpAngConstraintAtom (hkClass 0x57c4750, built at 0x807b0: 0x10 bytes,
 * records 0x169d9a0): constrainedAxes (three hkUint8) at +2,
 * numConstrainedAxes at +5, padding (ten bytes, not serialized) at +6. */
struct hkpAngConstraintAtom {
    u16 type; /* derived name */
    u8 constrainedAxes[3];
    u8 numConstrainedAxes;
    u8 padding[10];
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
    hkUFloat8 velocityStabilizationFactor;
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

/* hkpLinLimitConstraintAtom (records 0x169e1f0): axisIndex (hkUint8) at
 * +2, min and max (hkReal) at +4 and +8, padding at +0xc. */
struct hkpLinLimitConstraintAtom {
    u16 type; /* derived name */
    u8 axisIndex;
    u8 unknown3;
    float min;
    float max;
    u8 padding[4];
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
        u8 unknownC0[0x30]; /* ang, lin0, lin1 */
        hkpLinLimitConstraintAtom linLimit;
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

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    /* Slot 7 (0x7e8a0): valid when both frames are orthonormal and the
     * limit's minimum is not above its maximum. */
    /* The motor set (0x7e7c0; the game at 0xeb15fa), the references
     * swapped. derived name. */
    void FUN_0007e7c0(hkpConstraintMotor *motor);
    hkBool unknownVirtual7() const;

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

/* hkpCogWheelConstraintAtom (0x10 bytes, member records from 0x169dc60). */
struct hkpCogWheelConstraintAtom {
    u16 type; /* derived name */
    float cogWheelRadiusA;
    float cogWheelRadiusB;
    hkBool isScrew;
    s8 memOffsetToInitialAngleOffset;
    s8 memOffsetToPrevAngle;
    s8 memOffsetToRevolutionCounter;
};

/* hkpCogWheelConstraintData (hkClass 0x57c3e88, built at 0x7cb3b, 0xc0 bytes, parent hkpConstraintData; vtable 0x169c2b0): atoms at +0x20 (record table 0x169ca30: transforms at +0, cogWheels at +0x90). */
class hkpCogWheelConstraintData : public hkpConstraintData
{
  public:
    /* 0xa0 bytes at +0x20 (what slot 6 hands on). */
    struct Atoms {
        hkpSetLocalTransformsConstraintAtom transforms;
        hkpCogWheelConstraintAtom cogWheels;
    };

    /* The finish constructor (0x7c9d0): the atoms are left as loaded. */
    hkpCogWheelConstraintData(hkFinishLoadedObjectFlag flag);

    /* A new one (0x7b400): both frames the identity, both wheels of radius
     * 1, the runtime offsets of the angles and the revolution counter. */
    hkpCogWheelConstraintData();

    /* Empty (the shared 0x3b640); the deleting destructor 0x7b3b0, beside
     * the class's slots 6 and 20 (0x7b570, 0x7b590), is the body the
     * vtables of the 0xc0-byte reference-counted classes with empty
     * destructors cite (D15). */
    virtual ~hkpCogWheelConstraintData();

    /* Slot 7 (0x7b4c0): both frames orthonormal and neither wheel's radius
     * zero. */
    hkBool unknownVirtual7() const;

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

    /* A new spring (0x7d660, called at 0x79847): the atoms typed, the
     * pivots at the origin, the stabilization on with no limits, no length
     * and no spring (-1). */
    hkpStiffSpringConstraintData();

    /* Empty (the shared 0x3b640); the deleting destructor 0x7d610
     * (beside the class's slots) is the body the vtables of the reference-counted classes of
     * its size with empty destructors cite (D15). */
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

    /* A new pulley (0x82510, called at 0x798f2): both atoms typed, the
     * pivots at the origin, no rope, a leverage of one. */
    hkpPulleyConstraintData();

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

    /* Empty (the shared 0x3b640); the deleting destructor 0x82e90
     * (beside the class's slots) is the body the vtables of the reference-counted classes of
     * its size with empty destructors cite (D15). */
    virtual ~hkpDeformableFixedConstraintData();

    void FUN_00083000(
        hkpConstraintData::ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    void FUN_00083020(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

    Atoms atoms;
};

/* hkpAngLimitConstraintAtom (hkClass 0x57c4850, built at 0x809a2: 0x20
 * bytes, its nine members from the records at 0x169daf0, after the atom's
 * type; the hinge's slot 7, 0x79278, tests isEnabled). */
struct hkpAngLimitConstraintAtom {
    u16 type; /* derived name */
    u8 isEnabled;
    u8 limitAxis;
    u8 cosineAxis;
    u8 padding2[3];
    float minAngle;
    float maxAngle;
    float angularLimitsTauFactor;
    float angularLimitsDampFactor;
    u8 padding[8];
};

/* hkp2dAngConstraintAtom (the name a string of the executable): 0x10 bytes,
 * its type and the free axis it leaves the bodies (the hinge limits'
 * constructor stores 0 at +2). derived field names. */
struct hkp2dAngConstraintAtom {
    u16 type;            /* derived name */
    u8 freeRotationAxis; /* derived name */
    u8 padding[13];      /* derived name */
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
        hkpAngLimitConstraintAtom angLimit;
        hkp2dAngConstraintAtom twoDAng; /* the record's 2dAng */
    };

    /* The finish constructor (0x82250): the atoms are left as loaded. */
    hkpHingeLimitsData(hkFinishLoadedObjectFlag flag);

    /* A new one (0x83060): both rotations the identity, the angle limited
     * to between -pi and pi about the first axis. */
    hkpHingeLimitsData();

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

    /* Empty (the shared 0x3b640); the deleting destructor 0x17cae0
     * (beside the class's slots) is the body the vtables of the reference-counted classes of
     * its size with empty destructors cite (D15). */
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
        hkpAngConstraintAtom ang;
    };

    /* The finish constructor (0x7b5f0): the atoms are left as loaded. */
    hkpRotationalConstraintData(hkFinishLoadedObjectFlag flag);

    /* A new rotational constraint (0x83440, called at 0x79939): both
     * frames the identity, all three axes constrained. */
    hkpRotationalConstraintData();

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
    u8 unknown7[1];
    float minAngle;
    float maxAngle;
    float angularLimitsTauFactor;
    u8 unknown14[0xc];
};

/* hkpTwistLimitConstraintAtom (its name a string of the executable,
 * 0x14c1212): minAngle and maxAngle at +8 and +0xc (the ragdoll limits'
 * validity test 0x7c937), 0x20 bytes in the atoms that hold it. */
struct hkpTwistLimitConstraintAtom {
    u8 unknown0[8];
    float minAngle;
    float maxAngle;
    u8 unknown10[0x10];
};

/* hkpRagdollLimitsData (parent hkpConstraintData, 0xf0 bytes): atoms at
 * +0x20 (records 0x169b8f8, 0x169b920 and 0x169b948: twistLimit at +0x70,
 * coneLimit at +0x90, planesLimit at +0xb0). Its finish constructor, inline
 * in the finish callback 0x788f0, re-enables the cone's stabilization
 * through FUN_0007c860 when the loaded offset is nonzero. */
class hkpRagdollLimitsData : public hkpConstraintData
{
  public:
    struct Atoms {
        hkpSetLocalRotationsConstraintAtom rotations;
        hkpTwistLimitConstraintAtom twistLimit;
        hkpConeLimitConstraintAtom coneLimit;
        /* A cone limit atom too (its angles at +0xd8 and +0xdc). */
        hkpConeLimitConstraintAtom planesLimit;
    };

    hkpRagdollLimitsData(hkFinishLoadedObjectFlag flag) : hkpConstraintData(flag)
    {
        if (flag.finishing) {
            if (atoms.coneLimit.memOffsetToAngleOffset) {
                FUN_0007c860(true);
            }
        }
    }

    /* Empty (the shared 0x3b640); the deleting destructor 0x7c6c0
     * (beside the class's slots 5, 6, 7 and 20) is the body the vtables of the reference-counted classes of
     * its size with empty destructors cite (D15). */
    virtual ~hkpRagdollLimitsData();

    int unknownVirtual5() const;                                            /* slot 5 (0x7c980) */
    void unknownVirtual6(hkpConstraintData::ConstraintInfo &infoOut) const; /* slot 6 (0x7c890) */
    hkBool unknownVirtual7() const;                                         /* slot 7 (0x7c8c0) */
    void unknownVirtual20(hkBool wantRuntime,
                          ConstraintRuntimeInfo &infoOut) const; /* slot 20 (0x7c8b0) */

    void FUN_0007c860(hkBool enable); /* derived name */

    Atoms atoms;
};

/* hkpPointToPlaneConstraintData (type info registered at 0x7bab4; hkClass
 * 0x57c3be8, built at 0x7ba6b: size 0xc0, parent hkpConstraintData; vtable
 * 0x169c530, address point 0x169c540): atoms at +0x20 (transforms at +0,
 * lin at +0x90, record table 0x169c4b0). Its slot 20 (0x7bb90), kept by
 * hkpStiffSpringConstraintData and hkpPulleyConstraintData, wants 8 bytes
 * of runtime and one solver result, or none. */
/* hkpLinConstraintAtom (its member name a string of the executable):
 * axisIndex (hkUint8) at +2 after the atom's type, 0x10 bytes. */
struct hkpLinConstraintAtom {
    u16 type; /* derived name */
    u8 axisIndex;
    u8 padding[0xd];
};

class hkpPointToPlaneConstraintData : public hkpConstraintData
{
  public:
    struct Atoms {
        hkpSetLocalTransformsConstraintAtom transforms;
        hkpLinConstraintAtom lin;
    };

    /* The finish constructor (0x7b900): the atoms are left as loaded. */
    hkpPointToPlaneConstraintData(hkFinishLoadedObjectFlag flag);

    /* A new constraint (0x7bae0, called at 0x798c0): both frames the
     * identity, the plane's normal the first axis. */
    hkpPointToPlaneConstraintData();

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
        hkpLinFrictionConstraintAtom friction0;
        hkpLinFrictionConstraintAtom friction1;
        hkpLinFrictionConstraintAtom friction2;
        hkpAngConstraintAtom ang;
        hkpLinLimitConstraintAtom linLimit0;
        hkpLinLimitConstraintAtom linLimit1;
        hkpLinLimitConstraintAtom linLimit2;
    };

    /* The finish constructor (0x7ac70; hkClass built at 0x7ad45, parent
     * hkpConstraintData's 0x57c45a8): the atoms finish themselves. */
    hkpLinearClearanceConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpLinearClearanceConstraintData();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    void FUN_000839f0(
        hkpConstraintData::ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    /* Slot 7 (0x83a20): both frames' rotations orthonormal, each linear
     * limit's range in order and fewer than four angular axes. */
    hkBool unknownVirtual7() const;
    void FUN_00083a10(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */

    Atoms atoms;
};

/* hkpRackAndPinionConstraintData (hkClass 0x57c4188, built at 0x7d1ee, 0xc0
 * bytes, parent hkpConstraintData; vtable 0x16a0200): atoms at +0x20 (record
 * table 0x169cd00: transforms at +0, rackAndPinion at +0x90). */
/* hkpRackAndPinionConstraintAtom (0x10 bytes, member records from
 * 0x169e420). */
struct hkpRackAndPinionConstraintAtom {
    u16 type; /* derived name */
    float pinionRadiusOrScrewPitch;
    hkBool isScrew;
    s8 memOffsetToInitialAngleOffset;
    s8 memOffsetToPrevAngle;
    s8 memOffsetToRevolutionCounter;
    u8 padding[4];
};

class hkpRackAndPinionConstraintData : public hkpConstraintData
{
  public:
    struct Atoms {
        hkpSetLocalTransformsConstraintAtom transforms;
        hkpRackAndPinionConstraintAtom rackAndPinion;
    };

    /* The finish constructor (0x7d080): the atoms are left as loaded. */
    hkpRackAndPinionConstraintData(hkFinishLoadedObjectFlag flag);

    /* A new one (0x83570; 0x799f9 builds one): both frames the identity, a
     * pinion of radius 1, the runtime offsets of the angles and the
     * revolution counter. */
    hkpRackAndPinionConstraintData();

    virtual ~hkpRackAndPinionConstraintData();

    /* Slot 7 (0x83630): both frames orthonormal and the pinion's radius or
     * the screw's pitch not zero. */
    hkBool unknownVirtual7() const;

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

class ConstraintData169ffe0 : public hkpConstraintData /* derived name */
{
  public:
    /* The constructor's stores: local transforms (type 2) at +0, both
     * identity, and an angular friction atom (type 0x11) at +0x90. */
    struct Atoms {
        hkpSetLocalTransformsConstraintAtom transforms;
        hkpAngFrictionConstraintAtom angFriction; /* derived name */
    };

    /* Out of line (0x831a0): both frames the identity, friction on the
     * three axes from the first, no torque. */
    ConstraintData169ffe0();

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
 * name. constraintData is a counted reference to the constraint data
 * (hkpConstraintData: the cleanup releases it). */
struct hknpConstraintCinfo {
    hknpConstraintCinfo(hkFinishLoadedObjectFlag flag) : name(flag) {}

    /* The cleanup callback of its type info (0x369a0, registered by the
     * initializer at 0x36c62): the cinfo destroyed in place, the name, then
     * the data's reference. derived name. */
    static void FUN_000369a0(void *object);

    hkRefPtr<hkpConstraintData> constraintData;
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
    hknpBodyCinfo(hkFinishLoadedObjectFlag flag) : name(flag) {}

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

/* Its members' defaults (the hkClass's, at 0x14b97d4): each member's offset
 * into the values, -1 for one without a default, then the orientation's
 * four floats and the mass. derived name. */
struct hknpBodyCinfoDefaults /* derived name */
{
    int defaultOffsets[19];
    float orientation[4];
    float mass;
};

extern const hkClassMember D_1693bf0[]; /* derived name: hknpBodyCinfo's records */

/* Its type info's callbacks: the finish (0x38250) and the cleanup
 * (0x38260), the cinfo destroyed in place. derived names. */
void FUN_00038250(void *object, int finishing); /* derived name */
void FUN_00038260(void *object);                /* derived name */

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

    /* The class allocator, which the motors share: a block of the thread's
     * heap (the clones, 0x17b054), and the reference-counted delete
     * (tlg_lib_unknown.h). */
    static void *operator new(unsigned long numBytes);
    static void operator delete(void *object, unsigned long numBytes);

    /* Its placement form, which the finish callbacks construct in place
     * with. */
    static void *operator new(unsigned long, void *where)
    {
        return where;
    }

    hkEnum<MotorType, s8> type; /* derived name */
};

extern const hkClass D_57c3af0; /* hkpConstraintMotor's hkClass */

class hkpLimitedForceConstraintMotor : public hkpConstraintMotor
{
  public:
    hkpLimitedForceConstraintMotor() {}

    hkpLimitedForceConstraintMotor(hkFinishLoadedObjectFlag flag) : hkpConstraintMotor(flag) {}

    float minForce; /* name from the executable's strings; offset derived */
    float maxForce; /* name from the executable's strings; offset derived */
};

/* Its member records, minForce and maxForce (the reflection initializer
 * 0x825d0 passes them). */
extern const hkClassMember D_169f6e0[]; /* derived name */

/* hkpPositionConstraintMotor (hkClass 0x57c30e8), hkpVelocityConstraintMotor
 * (hkClass 0x57c32e8) and hkpCallbackConstraintMotor (hkClass 0x57c3cc0),
 * each with hkpLimitedForceConstraintMotor as its parent: vtables 0x169f5b0,
 * 0x169c790 and 0x16a5ff0, finish callbacks FUN_000787d0, FUN_00079330 and
 * FUN_0007c410. */
class hkpPositionConstraintMotor : public hkpLimitedForceConstraintMotor
{
  public:
    /* 0x82430: a limited-force motor of the position type with a force
     * range of a million each way, tau 0.8, damping 1, a proportional
     * recovery velocity of 2 and a constant one of 1. */
    hkpPositionConstraintMotor();

    hkpPositionConstraintMotor(hkFinishLoadedObjectFlag flag) : hkpLimitedForceConstraintMotor(flag)
    {
    }

    /* Slot 5 (0x82480): a copy from the thread's heap, each level's
     * members copied after its vtable is stored. derived name. */
    hkpConstraintMotor *FUN_00082480() const;

    /* Names and offsets from the member records 0x169b830 to 0x169b8a8. */
    float tau;
    float damping;
    float proportionalRecoveryVelocity;
    float constantRecoveryVelocity;
};

class hkpVelocityConstraintMotor : public hkpLimitedForceConstraintMotor
{
  public:
    hkpVelocityConstraintMotor(hkFinishLoadedObjectFlag flag) : hkpLimitedForceConstraintMotor(flag)
    {
    }

    /* Empty (the shared 0x3b640); the deleting destructor 0x7c0b0, beside
     * the class's other slots, is the body the vtables of the 0x28-byte
     * reference-counted classes with empty destructors cite (D15). */
    virtual ~hkpVelocityConstraintMotor();

    /* Slot 5 (0x7c100): a copy from the thread's heap, each level's
     * members copied after its vtable is stored. derived name. */
    hkpConstraintMotor *FUN_0007c100() const;

    /* From its records at 0x169bbc0 (hkClass 0x57c32e8, 0x28 bytes). */
    float tau;
    float velocityTarget;
    hkBool useVelocityTargetFromConstraintTargets;
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

    /* Slot 5 (0x17d0f0): a copy from the thread's heap, each level's
     * members copied after its vtable is stored. derived name. */
    hkpConstraintMotor *FUN_0017d0f0() const;

    CalcMotorDataCallbackFunc callbackFunc; /* name from the strings; offset derived */
    hkEnum<CallbackType, u32> callbackType; /* name from the strings; offset derived */
    /* The user's values (names from the strings; offsets from the copy,
     * 0x17d0f0, which copies the 0x40 bytes). */
    hkUlong userData0;
    hkUlong userData1;
    hkUlong userData2;
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

    /* Slot 5 (0x17b030): a copy from the thread's heap, each level's
     * members copied after its vtable is stored. derived name. */
    hkpConstraintMotor *FUN_0017b030() const;

    float springConstant; /* name from the strings; offset derived */
    float springDamping;  /* name from the strings; offset derived */
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
    hkBool isEnabled;
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
class hkpRagdollConstraintData : public hkpConstraintData
{
  public:
    struct Atoms {
        /* Out of line (0x7dae0): when finishing, the motors' offsets into
         * the runtime are set. */
        Atoms(hkFinishLoadedObjectFlag flag);

        hkpSetLocalTransformsConstraintAtom transforms;
        hkpSetupStabilizationAtom setupStabilization;
        hkpRagdollMotorConstraintAtom ragdollMotors;
        hkpAngFrictionConstraintAtom angFriction;
        hkpTwistLimitConstraintAtom twistLimit;
        hkpConeLimitConstraintAtom coneLimit;
        /* A cone limit atom too, as the ragdoll limits' (0x7dda4). */
        hkpConeLimitConstraintAtom planesLimit;
        hkpBallSocketConstraintAtom ballSocket;
    };

    /* The finish constructor (0x82c70, the type info's finish function):
     * the atoms finish themselves, and a cone loaded with its stabilization
     * on gets it again. */
    hkpRagdollConstraintData(hkFinishLoadedObjectFlag flag);

    virtual ~hkpRagdollConstraintData();

    /* Slot 7 (0x7dd30): as the ragdoll limits' test, after the ball and
     * socket's stabilized method asks for the stabilization atom, the
     * cone's maximum allowed up to pi itself. */
    hkBool unknownVirtual7() const;

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

    /* The three motors set (0x7dff0, 0x7e170, 0x7e0b0; the game at 0xeb16a0
     * to 0xeb16d3): a reference taken on the new one before the old one's
     * is released. derived names. */
    void FUN_0007dff0(hkpConstraintMotor *motor);
    void FUN_0007e170(hkpConstraintMotor *motor);
    void FUN_0007e0b0(hkpConstraintMotor *motor);

    /* What the solver keeps for the constraint (derived names): its first
     * twelve solver results are the motors' and the friction's. */
    struct Runtime {
        hkpSolverResults solverResults[12];
    };

    /* The motors enabled or not, the friction the opposite, and the
     * runtime's results reset (0x7e220; the game jumps to it at
     * 0xeb1a10). derived name. */
    void FUN_0007e220(void *runtimeIn, hkBool isEnabled);

    hkpConstraintMotor *FUN_0007dfc0() const; /* derived name */
    hkpConstraintMotor *FUN_0007e0a0() const; /* derived name */
    hkpConstraintMotor *FUN_0007e160() const; /* derived name */

    /* derived name: target_bRca = target * transformA's rotation. */
    void FUN_0007df80(const hkMatrix3 &target);

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

    /* A new one (0x7c1d0): the stabilization off with no limits, the ball
     * socket solved by the old method, both pivots at the origin. */
    hkpBallAndSocketConstraintData();

    /* Empty (the shared 0x3b640); the deleting destructor 0x7c180
     * (beside the class's slots) is the body the vtables of the reference-counted classes of
     * its size with empty destructors cite (D15). */
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
        hkpAngLimitConstraintAtom angLimit;
        u8 unknownF0[0x10]; /* 2dAng */
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

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    void FUN_000791f0(
        hkpConstraintData::ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    /* Slot 7 (0x79220): valid when the stabilized method has its setup
     * enabled, both frames are orthonormal and an enabled motor has its
     * limit enabled. */
    /* The motor set (0x79140; the game at 0xeb159e), the references
     * swapped. derived name. */
    void FUN_00079140(hkpConstraintMotor *motor);
    hkBool unknownVirtual7() const;
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
    /* A bridge atom (type 1) with no data yet; the owner's constructor
     * initializes it (0x79dc0). */
    hkpBridgeConstraintAtom() : type(1), constraintData(0) {}

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
    hkpBridgeAtoms() {}

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

    /* Inline: the wrapped data's reference released and the pointer
     * cleared. The derived classes' destructors inline it after their own
     * empty bodies (hknpBreakableConstraintData's 0x3c100,
     * hknpMalleableConstraintData's 0x67a90, which this class's slot 0
     * cites too: one body). */
    virtual ~hkpWrappedConstraintData()
    {
        if (constraintData) {
            constraintData->removeReference();
        }
        constraintData = 0;
    }

    /* The reference-counted class delete (tlg_lib_unknown.h): the deleting
     * destructor 0x7d480, beside the constructors, frees at the recorded
     * size, 0x20 by default. */
    static void operator delete(void *object, unsigned long numBytes);

    void FUN_0007d5b0(ConstraintInfo &infoOut) const; /* vtable slot 6; derived name */
    hkBool FUN_00067c60() const;                      /* vtable slot 7; derived name */
    void FUN_0007d600(const void *argument1, const void *argument2, const void *argument3,
                      Vec4 &out) const; /* vtable slot 19; derived name */
    void FUN_00067b30(hkBool wantRuntime,
                      ConstraintRuntimeInfo &infoOut) const; /* vtable slot 20; derived name */
    void *FUN_0007d5d0(void *runtime) const;                 /* vtable slot 21; derived name */

    hkpConstraintData *constraintData;
};

/* Its one member record, constraintData (the reflection initializer 0x7e350
 * passes it). */
extern const hkClassMember D_169d1c0[]; /* derived name */

/* hknpBridgeConstraintAtom (hkClass 0x57c1808, built at 0x61667, 0x18
 * bytes, parent hkpConstraintAtom's 0x57c4650; records 0x1699620):
 * numSolverResults at +4, constraintData at +8 (not owned, flags 0x200),
 * padding (four bytes, not serialized) at +0x10. */
struct hknpBridgeConstraintAtom {
    u16 type; /* derived name */
    u8 unknown2[2];
    int numSolverResults;
    hkpConstraintData *constraintData;
    u8 padding[4];
};

/* hknpMalleableConstraintData, polymorphic, 0x40 bytes (type info 0x57c18d8,
 * vtable 0x1699a90; its finish constructor 0x67960 runs
 * hkpWrappedConstraintData's 0x7d520): members atom (an
 * hknpBridgeConstraintAtom) at +0x20, wantsRuntime at +0x38 and strength
 * (float) at +0x3c (record table 0x16996a0); FUN_00067c40 writes the
 * strength. Slot 6 (FUN_00067b00) takes the wrapped data's info and puts its
 * own atom in place of the atoms. */
class hknpMalleableConstraintData : public hkpWrappedConstraintData
{
  public:
    /* The finish constructor, out of line (0x67960): when finishing, the
     * atom is bridged to this object again. */
    hknpMalleableConstraintData(hkFinishLoadedObjectFlag flag);

    /* The constructor, out of line (0x678e0): over the data it wraps, a
     * bridge atom, a strength of 0.01, the atom bridged to this object. */
    hknpMalleableConstraintData(hkpConstraintData *constraintData, bool wantRuntime);

    virtual ~hknpMalleableConstraintData();

    /* The atom bridged to this object, its solver results counted from the
     * wrapped data's runtime info (inline in both constructors, 0x6792d
     * and 0x6799b). derived name. */
    void bridgeAtom(bool wantRuntime)
    {
        atom.constraintData = this;
        ConstraintRuntimeInfo info;
        constraintData->unknownVirtual20(wantRuntime, info);
        atom.numSolverResults = info.numSolverResults;
    }

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

    /* The pivot frames in each body's space (0x7be40). derived name. */
    void FUN_0007be40(const hkTransform &pivotA, const hkTransform &pivotB);

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

    /* Slot 7 (0x7f020): valid when a stabilized ball and socket has its
     * stabilization set up and both frames are orthonormal. */
    hkBool unknownVirtual7() const;

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
    /* Slot 19 (0x17d010): the friction and slip impulses along the wheel's
     * two axes (the first frame's second and third columns) under a
     * rotation, summed. derived name. */
    void FUN_0017d010(const hkMatrix3 *rotation, const void *argument2,
                      const hkpSolverResults *results, Vec4 &out) const;
    void unknownVirtual20(hkBool wantRuntime,
                          ConstraintRuntimeInfo &infoOut) const; /* slot 20 (0x17cf30) */

    Atoms atoms;
};

void FUN_0007b110(void *object, int finishing); /* derived name */

/* hkpEllipticalLimitConstraintAtom (hkClass 0x57c4cf0, 0x30 bytes in
 * hkp6DofConstraintData's blueprints): the two limit angles at +8 and +0xc,
 * each within [0, pi] for a valid constraint (0x17ba2f). derived names. */
struct hkpEllipticalLimitConstraintAtom {
    u8 unknown0[8];
    float maxAngle0;
    float maxAngle1;
    u8 unknown10[0x20];
};

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

    /* Its members from the records at 0x169f730. */
    struct Blueprints {
        /* Out of line (0x17b0d0; the finish callback 0x82660 jumps to it):
         * the motors' runtime offsets reset by their own finish
         * constructors, then, when finishing, set to where the compiled
         * runtime keeps them. */
        Blueprints(hkFinishLoadedObjectFlag flag);

        hkBool linearIsFixed[3];
        u8 padding3[0xd];
        hkpSetLocalTransformsConstraintAtom transforms;
        hkpSetupStabilizationAtom setupStabilization;
        hkpRagdollMotorConstraintAtom ragdollMotors;
        hkpAngFrictionConstraintAtom angFriction;
        hkpTwistLimitConstraintAtom twistLimit;
        hkpEllipticalLimitConstraintAtom ellipticalLimit;
        u8 unknown170[0x20]; /* stiffSpring */
        hkpLinMotorConstraintAtom linearMotor0;
        hkpLinMotorConstraintAtom linearMotor1;
        hkpLinMotorConstraintAtom linearMotor2;
        hkpBallSocketConstraintAtom ballSocket;
    };

    virtual ~hkp6DofConstraintData();

    /* An angular motor by index; MOTOR_ALL gives the twist motor (0x17bb20;
     * the constraint's builder at 0x79bd5 asks for each). derived name. */
    hkpConstraintMotor *FUN_0017bb20(MotorIndex index) const;

    void FUN_0017b910(float newBreachImpulse); /* vtable slot 10; derived name */
    float FUN_0017b920() const;                /* vtable slot 13; derived name */
    void FUN_0017b930(int bodyIndex);          /* vtable slot 14; derived name */
    u8 FUN_0017b950() const;                   /* vtable slot 15; derived name */
    /* Slot 7 (0x17b9e0): whether the constraint is valid. derived name. */
    hkBool FUN_0017b9e0() const;
    /* Slot 17 (0x17bb80): the ball-socket atom's inertia stabilization
     * factor, clamped to [0, 1], copied into the compiled atoms unless
     * they are to be rebuilt. derived name. */
    hkResult FUN_0017bb80(float factor);
    hkResult FUN_0017bb70(float &factorOut) const; /* vtable slot 18; derived name */
    /* Slot 19 (0x17ca80): the impulses of the three linear results the
     * runtime map gives, zero for one it has none for. derived name. */
    void FUN_0017ca80(const void *argument1, const void *argument2, const hkpSolverResults *results,
                      Vec4 &out) const; /* vtable slot 19; derived name */
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

        /* Out of line (0x87cf0; the type info's cleanup 0x87e20 and the
         * buffer's destructor 0x89fd0 call it): the arrays from the last. */
        ~VertexData();

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

    /* Out of line (0x89fd0, slot 0; the deleting destructor 0x8a080, slot
     * 1): the description's elements, then the vertex data. */
    virtual ~hkxVertexBuffer();

    /* The reference-counted class delete (freeReferencedObject). */
    static void operator delete(void *object, unsigned long numBytes);

    VertexData data;
    hkxVertexDescription desc;
};

/* hkxVertexAnimation (hkClass 0x57c7dc0, built at 0x8cd70: size 0xb8,
 * parent hkReferencedObject's, member records at 0x16a2700): time (float)
 * at +0xc, vertData (hkxVertexBuffer) at +0x10, vertexIndexMap (an array of
 * hkInt32) at +0x98, componentMap (an array of class 0x57c7d40) at +0xa8.
 * The finish callback 0x8cb10 constructs it in place. */
/* hkxVertexAnimation::UsageMap (the string at 0x14c3679; its hkClass
 * built at 0x8ccca, size 4, three member records): members not typed yet. */
struct hkxVertexAnimationUsageMap {
    u8 unknown0[4];
};

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
class hkxMeshSection;

class hkxMesh : public hkReferencedObject
{
  public:
    class UserChannelInfo;

    hkxMesh(hkFinishLoadedObjectFlag flag);
    /* 0x8bf00 (slot 0; the deleting destructor 0x8beb0 frees 0x30). */
    virtual ~hkxMesh();

    /* The record's members (0x16a1620): arrays of pointers to its sections
     * and its user channels' descriptions. */
    hkArray<hkxMeshSection *> sections;
    hkArray<UserChannelInfo *> userChannelInfos;
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
    UserChannelInfo(hkFinishLoadedObjectFlag flag)
        : hkxAttributeHolder(flag), name(flag), className(flag)
    {
    }

    /* Out of line (0x89020, slot 0); the deleting destructor (0x89060,
     * slot 1) runs it and frees through the class's delete. */
    virtual ~UserChannelInfo();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

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
    hkxTextureInplace(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), data(flag), name(flag), originalFilename(flag)
    {
    }

    /* Out of line (0x8aa90, slot 0): the members destroy themselves; the
     * deleting destructor (0x8ab00, slot 1) frees at the recorded size. */
    virtual ~hkxTextureInplace();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

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
    hkxScene(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag), modeller(flag), asset(flag)
    {
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

    /* The reference-counted class delete (tlg_lib_unknown.h): its deleting
     * destructor 0x17d4b0 frees at the recorded size, 0x20 by default. */
    static void operator delete(void *object, unsigned long numBytes);

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

/* hkxMaterialShader (hkClass 0x57c7340, size 0x48, parent
 * hkReferencedObject; records built at run time by 0x8a4f0): name at +0x10,
 * type at +0x18, vertexEntryName, geomEntryName and pixelEntryName at
 * +0x20, +0x28 and +0x30, data (an array of bytes) at +0x38. Its finish
 * constructor is inline in its finish callback FUN_0008a490: the four
 * strings finished in order. */
class hkxMaterialShader : public hkReferencedObject
{
  public:
    hkxMaterialShader(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), name(flag), vertexEntryName(flag), geomEntryName(flag),
          pixelEntryName(flag), data(flag)
    {
    }

    /* Slot 0 (0x8a350): the data given back, then the four strings, the
     * last first; the deleting destructor 0x8a3d0 is slot 1. */
    virtual ~hkxMaterialShader();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    hkStringPtr name;
    u8 unknown18[8]; /* type, its width not read */
    hkStringPtr vertexEntryName;
    hkStringPtr geomEntryName;
    hkStringPtr pixelEntryName;
    hkArray<u8> data;
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
    hkxSkinBinding(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), nodeNames(flag), bindPose(flag)
    {
    }

    /* Slot 0 (FUN_0008a830) runs the out-of-line FUN_0008a890; the
     * deleting destructor 0x8a840 frees 0x80. */
    virtual ~hkxSkinBinding();

    /* The record's members (0x16a1cf0). */
    hkxMesh *mesh;
    hkArray<hkStringPtr> nodeNames;
    hkArray<hkMatrix4> bindPose;
    hkMatrix4 initSkinTransform;
};

/* hkxMeshSection (hkClass parent hkReferencedObject, built at 0x8e07d):
 * its finish callback FUN_0008e000 runs the inline finish constructor,
 * which has nothing to fix up but the vtable. */
class hkxMeshSection : public hkReferencedObject
{
  public:
    hkxMeshSection(hkFinishLoadedObjectFlag flag)
        : hkReferencedObject(flag), indexBuffers(flag), userChannels(flag), vertexAnimations(flag),
          linearKeyFrameHints(flag), boneMatrixMap(flag)
    {
    }

    /* Slot 0 (FUN_0008dbf0) runs the out-of-line FUN_0008dc50; the
     * deleting destructor 0x8dc00 frees 0x70. */
    virtual ~hkxMeshSection();

    /* The record's members (0x16a2a10). */
    hkxVertexBuffer *vertexBuffer;
    hkArray<hkxIndexBuffer *> indexBuffers;
    hkxMaterial *material;
    hkArray<hkReferencedObject *> userChannels;
    hkArray<hkxVertexAnimation *> vertexAnimations;
    hkArray<float> linearKeyFrameHints;
    hkArray<hkMeshBoneIndexMapping> boneMatrixMap;
};

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

/* hkxAttribute's members from its record table at 0x16a23e0: name
 * (hkStringPtr) at +0, value at +8; one enum, its records at 0x16a2490.
 * Its type info's cleanup is this destructor, a body the linker folded
 * with hknpMaterialDescriptor's (0x66e80): the value's reference released,
 * then the name destroyed. */
struct hkxAttribute {
    inline ~hkxAttribute();

    hkStringPtr name;
    hkRefVariant value;
};

inline hkxAttribute::~hkxAttribute()
{
    if (value.object) {
        value.object->removeReference();
    }
    value.object = 0;
}

extern const hkClassMember D_16a23e0[];         /* derived name: hkxAttribute's records */
extern const hkClassEnum D_16a2490[];           /* derived name: hkxAttribute's enum */
void FUN_0008b870(void *object, int finishing); /* derived name: its type info's finish callback */

/* hkxEnvironment (hkClass 0x57c8130, parent hkReferencedObject, built at
 * 0x8db07): its finish constructor 0x17d6f0 is out of line, jumped to by the
 * finish callback FUN_0008da40 and called by the reflection initializer at
 * 0x8db93. */
class hkxEnvironment : public hkReferencedObject
{
  public:
    hkxEnvironment(hkFinishLoadedObjectFlag flag);

    /* Out of line (0x17d560, slot 0; the deleting destructor 0x17d600,
     * slot 1): the variables destroyed from the last, each value before
     * its name, and their storage given back. */
    virtual ~hkxEnvironment();

    hkArray<hkxEnvironmentVariable> variables; /* the record's member (0x16a29a0) */
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

    /* The variant's reference released; the strings are destroyed after
     * it, the class name first. */
    ~NamedVariant()
    {
        if (variant) {
            variant->removeReference();
        }
        variant = 0;
    }

    /* The cleanup callback of its type info (0x8e540, registered at
     * 0x8e75e): the entry destroyed in place. derived name. */
    static void FUN_0008e540(void *object);

    hkStringPtr name;
    hkStringPtr className;
    hkReferencedObject *variant;
};
struct hkMemoryResourceContainer;

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

    /* The interface's slots 5 to 15, in the vtable order of
     * hkMemoryResourceHandle (0x16a6280), whose overriders the tree names
     * on that class; slot 15 is named after its overrider (0x17f770). Only
     * slot 15 is called through the interface so far (the container's
     * 0x17fa0e). derived names. */
    virtual void unknownVirtual5();
    virtual void unknownVirtual6();
    virtual void unknownVirtual7();
    virtual void unknownVirtual8();
    virtual void unknownVirtual9();
    virtual void unknownVirtual10();
    virtual void unknownVirtual11();
    virtual void unknownVirtual12();
    virtual void unknownVirtual13();
    virtual void unknownVirtual14();
    virtual void FUN_0017f770(void *argument);
};

/* hkMemoryResourceHandle::ExternalLink (hkClass 0x57c85d0, built at
 * 0x8e9fc: size 0x10, member records at 0x16a3130): memberName and
 * externalId (hkStringPtr) at +0 and +8. */
/* An external link (the names from the strings at 0x14c7caf and
 * 0x14c7cba, in that order; hkxEnvironment::Variable's type info cites the
 * same callbacks, the same layout). */
struct hkMemoryResourceHandleExternalLink {
    hkStringPtr memberName;
    hkStringPtr externalId;
};

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
    /* Slot 11 (0x17f330): an external link appended, its member name and
     * id copied. derived name. */
    void FUN_0017f330(const char *memberName, const char *externalId);
    /* Slot 14 (0x17f270): every external link destroyed, the storage kept.
     * derived name. */
    void FUN_0017f270();
    /* Slot 12 (0x17f3e0): the first external link of a member name
     * removed. derived name. */
    void FUN_0017f3e0(const char *memberName);

    hkRefVariant variant;
    hkStringPtr name;
    hkArray<hkMemoryResourceHandleExternalLink> references;
};

/* hkResourceContainer (hkClass 0x57c8550, built at 0x8ebbc: size 0x10,
 * parent hkResourceBase, no members): the abstract container. */
class hkResourceContainer : public hkResourceBase
{
  public:
    hkResourceContainer(hkFinishLoadedObjectFlag flag) : hkResourceBase(flag) {}

    /* Every resource of this container and of its children, recursively,
     * appended (0x17fa60, called directly). derived name. */
    void FUN_0017fa60(hkArray<hkResourceHandle *> &handlesOut);
};

/* hkMemoryResourceContainer (hkClass 0x57c84b0, built at 0x8e94d: size
 * 0x40, parent hkResourceContainer; vtable 0x16a6300, slot 0 the complete
 * destructor 0x17fc20): members from its record table at 0x16a3010: name
 * (hkStringPtr) at +0x10, parent (not serialized) at +0x18, resourceHandles
 * and children (arrays of pointers) at +0x20 and +0x30. */
class hkMemoryResourceContainer : public hkResourceContainer
{
  public:
    /* Out of line (0x17fb60): the members finished, and when finishing
     * each child pointed back at this container. */
    hkMemoryResourceContainer(hkFinishLoadedObjectFlag flag);

    /* Slot 15 (0x1806b0): the first child after the previous one given
     * (from the first when none) whose name is the one given, or the next
     * child at all when no name is given; null when none is left. derived
     * name. */
    hkMemoryResourceContainer *FUN_001806b0(const char *childName,
                                            const hkMemoryResourceContainer *previous);

    /* Slot 17 (0x17f9b0): every resource, recursively, handed the argument
     * through its slot 15. derived name. */
    void FUN_0017f9b0(void *argument);

    hkStringPtr name;
    hkMemoryResourceContainer *parent;
    hkArray<hkMemoryResourceHandle *> resourceHandles;
    hkArray<hkMemoryResourceContainer *> children;
};

/* hkxVertexDescription::ElementDecl (type info 0x57c7f10, size 0x18, no
 * vtable; its records, built at run time by the initializer from 0x8cf60,
 * name byteStride and channelID, the hkStringPtr at +0x10). Its finish
 * constructor finishes the channel name, its destructor destroys it. */
struct hkxVertexDescriptionElementDecl {
    hkxVertexDescriptionElementDecl(hkFinishLoadedObjectFlag flag) : channelID(flag) {}

    u8 unknown0[0x10];
    hkStringPtr channelID;
};

void FUN_0008c990(hkxVertexAnimation *self);                                  /* derived name */
void FUN_0008dc50(hkxMeshSection *self);                                      /* derived name */
void FUN_0017d790(hkxAttribute *self, hkFinishLoadedObjectFlag flag);         /* derived name */
void FUN_0017de10(hkRootLevelContainer *self, hkFinishLoadedObjectFlag flag); /* derived name */

void FUN_0008a890(hkxSkinBinding *self); /* derived name */
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

    /* The constructor, out of line (0x79dc0; the constraint's builder at
     * 0x79629): no path, no friction, no orientation constraint (NONE),
     * both frames the identity, and the bridge atom over the data
     * itself. */
    hkpPointToPathConstraintData();

    /* The path set (0x79f70, from the constraint's builder at 0x79656): a
     * reference taken on the new one before the old one's is released. */
    void setPath(hkpParametricCurve *newPath); /* derived name */

    enum OrientationConstraintType {
        CONSTRAIN_ORIENTATION_INVALID,
        CONSTRAIN_ORIENTATION_NONE,
        CONSTRAIN_ORIENTATION_ALLOW_SPIN,
        CONSTRAIN_ORIENTATION_TO_PATH,
        CONSTRAIN_ORIENTATION_MAX_ID
    };

    virtual ~hkpPointToPathConstraintData();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    int unknownVirtual5() const;                                            /* slot 5 (0x3e420) */
    void unknownVirtual6(hkpConstraintData::ConstraintInfo &infoOut) const; /* slot 6 (0x7a020) */
    hkBool unknownVirtual7() const;                                         /* slot 7 (0x7a590) */
    void unknownVirtual20(hkBool wantRuntime,
                          ConstraintRuntimeInfo &infoOut) const; /* slot 20 (0x7a050) */

    hkpBridgeAtoms atoms;
    hkpParametricCurve *path;
    float maxFrictionForce;
    hkEnum<OrientationConstraintType, s8> angularConstrainedDOF;
    /* The member record built at 0x7f2xx under "transform_OS_KS"
     * (0x14c072f): two transforms, to the class's 0xd0 bytes. */
    hkTransform transform_OS_KS[2];
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
    /* Slot 14 (0xad1f0): the texture at an index replaced, the new one's
     * reference taken and the old one's released. derived name. */
    void FUN_000ad1f0(int index, hkMeshTexture *texture);
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

    /* Empty and inline: hkMemoryMeshTexture's destructor (0xad490) calls
     * nothing after its members'. */
    virtual ~hkMeshTexture() {}
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
    hkMemoryMeshTexture(hkFinishLoadedObjectFlag flag)
        : hkMeshTexture(flag), data(flag), filename(flag)
    {
    }

    /* Out of line (0xad490, slot 0); the deleting destructor (0xad4f0,
     * slot 1) frees through the class's delete. */
    virtual ~hkMemoryMeshTexture();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    const hkClass *getClassType() const; /* vtable slot 3, FUN_000247f0 */
    void FUN_000ad620(u8 *&dataOut, int &sizeOut,
                      Format &formatOut); /* vtable slot 5; derived name */
    /* Slot 6 (0xad640): raw data copied into the texture's own array, any
     * other format's data kept where it is, unowned. derived name. */
    void FUN_000ad640(u8 *newData, int numBytes, Format newFormat);
    Format FUN_000ad6e0() const;                      /* vtable slot 8; derived name */
    bool FUN_000ad710() const;                        /* vtable slot 11; derived name */
    void FUN_000ad720(bool newHasMipMaps);            /* vtable slot 12; derived name */
    FilterMode FUN_000ad730() const;                  /* vtable slot 13; derived name */
    void FUN_000ad740(FilterMode newFilterMode);      /* vtable slot 14; derived name */
    TextureUsageType FUN_000ad750() const;            /* vtable slot 15; derived name */
    void FUN_000ad760(TextureUsageType newUsageHint); /* vtable slot 16; derived name */
    int FUN_000ad770() const;                         /* vtable slot 17; derived name */
    void FUN_000ad780(int newTextureCoordChannel);    /* vtable slot 18; derived name */
    class ImageSource *FUN_000ad7c0() const;          /* vtable slot 7; derived name */

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

/* derived name: zero bytes written until the writer's position is a
 * multiple of the alignment (0x1a1e80; its scratch from the thread's stack
 * allocator). */
void FUN_001a1e80(hkStreamWriter *writer, int alignment);

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

/* A stream writer that keeps a running checksum (derived name): the value
 * at +0xc, set by this base's constructor, so before the derived class's
 * vtable is stored (0x45c0 stores +0xc at 0x45e5 and the vptr after it, at
 * 0x45f7; a member of the class that owns the vtable is set after the vptr). */
class CrcStreamWriter : public hkStreamWriter /* derived name */
{
  public:
    explicit CrcStreamWriter(u32 initialCrc) : crc(initialCrc) {}

    u32 crc; /* derived name */
};

/* A stream writer that only computes the CRC-32 of what it is given
 * (derived name; vtable 0x168c980, address point 0x168c990, no type info,
 * built on the stack by 0x45c0, which returns the complement of the CRC):
 * the running CRC starting at all ones; slot 5 (0x40b0) answers true, slot 6
 * (0x40c0) folds each byte in with the reflected polynomial 0xedb88320. */
class Crc32StreamWriter : public CrcStreamWriter /* derived name */
{
  public:
    /* The running CRC starts at all ones (0x45e5). */
    Crc32StreamWriter() : CrcStreamWriter(0xffffffff) {}

    /* Empty and inline (the shared 0x270): 0x45c0 destroys its writer on
     * the stack without a call. The deleting destructor 0x4060 frees the
     * object through the class allocator (tlg_lib_unknown.h), the body every
     * vtable of a 16-byte reference-counted class with an empty destructor
     * cites (D15). */
    virtual ~Crc32StreamWriter() {}

    static void operator delete(void *object, unsigned long numBytes);

    /* Slot 5: always usable (the shared 0x40b0). */
    virtual hkBool isOk() const
    {
        return true;
    }

    /* Slot 6 (0x40c0): each byte folded into the CRC, eight shifts with the
     * reflected polynomial; the count is returned. The class's key
     * function: its vtable and deleting destructor are emitted with it. */
    virtual int write(const void *buffer, int size);
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
    /* derived name: one byte written to the stream (0xa420). */
    void FUN_0000a420(char c);
    /* derived name: a 16-bit value written (0xa480), swapped when the
     * archive swaps. */
    void FUN_0000a480(u16 value);
    /* derived name: a 32-bit value written (0xa7a0), swapped when the
     * archive swaps. */
    void FUN_0000a7a0(int value);

    /* An array of elements written, each element's bytes reversed first
     * when the archive swaps (out of line at 0xa520; inline in the writes of
     * one value): copied through a 512-byte buffer a chunk at a time, the
     * last chunk the remainder. Declared `inline`: the 32-bit write (0xa7a0)
     * holds it at a cost between 225 and 250, which needs the hint's 325.
     * derived name. */
    inline void writeArrayGeneric(const void *array, int elemSize, int arraySize)
    {
        if (byteSwap) {
            char buffer[512];
            const int elemsPerBuffer = 512 / elemSize;
            int numBytes = arraySize * elemSize;
            const int lastBytes = numBytes % 512;
            const int lastElems = lastBytes / elemSize;
            const char *src = static_cast<const char *>(array);
            while (numBytes > 0) {
                int chunkBytes = 512;
                int chunkElems = elemsPerBuffer;
                if (numBytes < 512) {
                    chunkBytes = lastBytes;
                    chunkElems = lastElems;
                }
                FUN_00017e70(buffer, src, chunkBytes);
                char *p = buffer;
                switch (elemSize) {
                case 8:
                    for (int i = 0; i < chunkElems; i++, p += 8) {
                        char t0 = p[0];
                        p[0] = p[7];
                        p[7] = t0;
                        char t1 = p[1];
                        p[1] = p[6];
                        p[6] = t1;
                        char t2 = p[2];
                        p[2] = p[5];
                        p[5] = t2;
                        char t3 = p[3];
                        p[3] = p[4];
                        p[4] = t3;
                    }
                    break;
                case 4:
                    for (int i = 0; i < chunkElems; i++, p += 4) {
                        char t0 = p[0];
                        p[0] = p[3];
                        p[3] = t0;
                        char t1 = p[1];
                        p[1] = p[2];
                        p[2] = t1;
                    }
                    break;
                case 2:
                    for (int i = 0; i < chunkElems; i++, p += 2) {
                        char t0 = p[0];
                        p[0] = p[1];
                        p[1] = t0;
                    }
                    break;
                }
                writer->write(buffer, chunkBytes);
                src += chunkBytes;
                numBytes -= chunkBytes;
            }
        } else {
            writer->write(array, elemSize * arraySize);
        }
    }

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
    /* The constructor (0x80c0, called at 0xdb5 and 0xf0a): a new stream
     * over the writer, whose reference it takes. */
    hkOstream(hkStreamWriter *writer);

    virtual ~hkOstream();

    /* The reference-counted class delete (tlg_lib_unknown.h): the deleting
     * destructor 0x8270 frees at the recorded size. */
    static void operator delete(void *object, unsigned long numBytes);

    const hkClass *getClassType() const;            /* vtable slot 3, FUN_00008a20 */
    void FUN_000089e0();                            /* derived name */
    int FUN_000089f0(const void *buffer, int size); /* derived name */
    /* derived name: the writer at +0x10 (out of line, folded with every
     * other getter of a pointer at +0x10 into 0x7f80; the packfile
     * writer's name record calls it, 0x1a3530). */
    hkStreamWriter *FUN_00007f80() const;

    /* derived name: the operator<< of a C string (0x8440): writes its
     * strlen bytes, or "(null)" for a null pointer, and returns the
     * stream. */
    hkOstream &FUN_00008440(const char *string);

    /* derived name: the operator<< of a string buffer (0x89a0, called six
     * times by 0xadd80): its characters without the terminator, or
     * "(null)" for a buffer with none, and the stream returned. */
    hkOstream &FUN_000089a0(const hkStringBuf &string);

    /* derived name: the operator<< of a string pointer (0x8940, called at
     * 0x180abf and 0x180add): its characters, or "(null)" for a null
     * string, and the stream returned. */
    hkOstream &FUN_00008940(const hkStringPtr &string);

    /* derived name: the operator<< of an unsigned int (0x8550): formatted
     * with "%u" into a buffer on the stack, written, and the stream
     * returned. */
    hkOstream &FUN_00008550(unsigned int value);

    /* derived names: the operator<< of an int (0x84c0, "%i") and of a
     * float (0x8600, "%f", widened for the variadic call), each formatted
     * into the same buffer on the stack. */
    hkOstream &FUN_000084c0(int value);
    hkOstream &FUN_00008600(float value);

    /* derived name: the operator<< of a bool (0x83a0): "true" or "false",
     * its strlen bytes, and the stream returned. */
    hkOstream &FUN_000083a0(hkBool b);

    /* derived name: the operator<< of a char (0x83f0): the one byte
     * written, and the stream returned. */
    hkOstream &FUN_000083f0(char c);

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

/* A body's activation or deactivation event (derived name, after the text
 * its print writes, "BodyActivationEvent "): the body's id at +0xc and
 * whether it was activated at +0x10. The event dispatcher's print
 * (0x6c110, a switch on the event type at +4) jumps to its print. */
struct hknpBodyActivationEvent /* derived name */
{
    /* The event written to a stream (0x155430). derived name. */
    void FUN_00155430(hknpWorld *world, hkOstream &stream) const;

    u8 unknown0[0xc];
    u32 bodyId;     /* derived name */
    bool activated; /* derived name */
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
    /* Out of line (0xda0): the stream over size bytes at buffer. */
    BufferOstream(char *buffer, int size);
    virtual ~BufferOstream();

    /* The reference-counted delete (tlg_lib_unknown.h): the deleting
     * destructor (0xe40, slot 1) frees at the recorded size, 0x18 by
     * default. */
    static void operator delete(void *object, unsigned long numBytes);
};

/* Havok's error report (its HK_ERROR), as the "Not implemented" defaults of
 * hknpShape.cpp expand it (0x6e470 on): the text streamed into a buffer of
 * 512 bytes on the stack, handed to hkError's report with the id, the file
 * and the line, and the trap when the report asks for it. The file and the
 * line are the library build's __FILE__ and __LINE__, passed as the
 * executable has them (as HK_POSIX_CHECK's). */
#define HK_ERROR(id, file, line, text)                                                             \
    do {                                                                                           \
        char assertBuf[512];                                                                       \
        BufferOstream ostr(assertBuf, sizeof(assertBuf));                                          \
        ostr.FUN_00008440(text);                                                                   \
        if (hkError::FUN_00014cb0(id, assertBuf, file, line)) {                                    \
            HK_BREAKPOINT(0);                                                                      \
        }                                                                                          \
    } while (0)

/* The file hknpShape.cpp's reports name (the string at 0x14bf150). */
#define HK_NP_SHAPE_CPP                                                                            \
    "Y:\\NightlyJobs\\20141121-01\\Source\\Physics\\Physics\\Collide\\Shape\\hknpShape.cpp"

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

/* A body's debug event: the body's id at +0xc and its text from +0x10
 * (its length not recovered). */
struct hknpUnaryBodyDebugEvent /* derived name */
{
    void FUN_00155550(hknpWorld *world, hkOstream &out) const; /* derived name */

    u8 unknown0[0xc];
    u32 bodyId;  /* derived name */
    char text[]; /* derived name */
};

/* The two-body form, printed by the dispatcher at 0x6c165 (derived
 * names): the ids at +0xc and +0x14, the text from +0x18. */
struct hknpBinaryBodyDebugEvent /* derived name */
{
    void FUN_001554f0(hknpWorld *world, hkOstream &out) const; /* derived name */

    u8 unknown0[0xc];
    u32 bodyIdA; /* derived name */
    u8 unknown10[4];
    u32 bodyIdB; /* derived name */
    char text[]; /* derived name */
};

/* A trigger's event (derived name, after the text its print writes,
 * "TriggerEvent bodyIds="): the two bodies' ids at +0xc and +0x14 and
 * whether the body left the trigger at +0x19. */
struct hknpTriggerEvent /* derived name */
{
    void FUN_00040b70(hknpWorld *world, hkOstream &out) const; /* derived name */

    u8 unknown0[0xc];
    u32 bodyIdA; /* derived name */
    u8 unknown10[4];
    u32 bodyIdB; /* derived name */
    u8 unknown18;
    bool exited; /* derived name */
};

struct hknpBodyBreachedExpandedAabbEvent /* derived name */
{
    void FUN_001554c0(hknpWorld *world, hkOstream &out) const; /* derived name */

    u8 unknown0[0xc];
    u32 bodyId; /* derived name */
};

/* A body's integration clipped: its id at +0xc and the stolen velocity at
 * +0x10. */
struct hknpLinearIntegrationClippedCommand /* derived name */
{
    void FUN_0003ddd0(hknpWorld *world, hkOstream &out) const; /* derived name */

    u8 unknown0[0xc];
    u32 bodyId;          /* derived name */
    Vec4 stolenVelocity; /* derived name */
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
    /* derived names: the writer over a caller's memory (0x8f50): no stream
     * to flush to, nothing written, and when the memory is to hold a string
     * one byte kept back for its terminator and the memory zeroed. */
    hkBufferedStreamWriter(void *memory, int memorySize, hkBool memoryIsString);
    /* derived names: the writer over a stream it holds a reference to,
     * with a buffer of its own of bufferSize bytes from the thread's heap,
     * aligned to 64 (0x8eb0). */
    hkBufferedStreamWriter(hkStreamWriter *stream_, int bufferSize_);

    /* The class allocator, inline: the thread's heap (the file system's
     * 0x1a886; tlg_lib_unknown.h); placement stays available beside it
     * (BufferOstream's constructor, 0xda0). */
    static void *operator new(unsigned long numBytes);

    static void *operator new(unsigned long, void *where)
    {
        return where;
    }

    hkBool FUN_00009260() const; /* vtable slot 5; derived name */
    /* Slot 7 (0x91f0): the buffer written out, then the stream flushed.
     * derived name. */
    void FUN_000091f0();
    hkBool FUN_00009280() const; /* vtable slot 8; derived name */

    /* The buffered bytes written to the stream until it takes no more;
     * emptied when all went (0x91f0 inline). derived name. */
    void flushBuffer()
    {
        if (stream) {
            const int bytesLeft = bufferSize;
            int bytesWritten = 0;
            while (bytesWritten < bytesLeft) {
                const int thisWrite =
                    stream->write(buffer + bytesWritten, bytesLeft - bytesWritten);
                bytesWritten += thisWrite;
                if (thisWrite == 0) {
                    return;
                }
            }
            bufferSize = 0;
        }
    }

    int FUN_00009380() const; /* vtable slot 10; derived name */

    hkStreamWriter *stream; /* derived name */
    /* The buffer, the bytes in it and its capacity, as the constructor
     * 0x8f50 stores them and the write slot 0x90f0 reads them. */
    char *buffer;       /* derived name */
    int bufferSize;     /* derived name */
    int bufferCapacity; /* derived name */
    /* Whether the writer allocated the buffer (the constructor 0x8f50
     * clears it for a caller's memory). derived name. */
    hkBool ownsBuffer;
    /* To the 0x30 bytes the deleting destructor (0x8fa0) frees by
     * default. */
    u8 unknown29[7];
};

/* Its destructor (0x8ff0, which stores the vtable 0x168d210) and its
 * deleting destructor (slot 1, 0x8fa0), written as calls while the
 * destructor is not (cookbook 15, 97). derived names. */
void FUN_00008ff0(hkBufferedStreamWriter *self); /* derived name */
void FUN_00008fa0(hkBufferedStreamWriter *self); /* derived name */

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
    /* Slot 7 (0x2ad50): a section given back, its material kept by the
     * shape's own section, a reference taken on it before the old one's is
     * released. derived name. */
    void FUN_0002ad50(const hkMeshSection &section);

    /* A section as the shape keeps it, 0x38 bytes (the lock 0x2abd0 and
     * slot 7 index them so): its vertex buffer and material at +0 and +8.
     * derived names. */
    struct Section {
        void *vertexBuffer;
        hkMeshMaterial *material;
        u8 unknown10[0x28];
    };

    /* From its record table at 0x1691bf0: sections (array) at +0x10,
     * indices16 and indices32 (arrays) at +0x20 and +0x30, name
     * (hkStringPtr, finished by its finish constructor 0x2a940) at +0x40. */
    u8 unknownC[4];
    hkArray<Section> sections;
    u8 unknown20[0x20];
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

    /* The record's members (0x1691c90). */
    hkMeshShape *skin;
    hkArray<hkMatrix4> worldFromBoneTransforms;
    hkArray<hkStringPtr> boneNames;
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

    /* hkSkinnedMeshShape::BoneSection (its three records at 0x16923a0, 0x10
     * bytes): the mesh holding the section's bone sets and the first and
     * number of them. */
    struct BoneSection {
        hkRefPtr<hkMeshShape> meshBuffer;
        BoneSetId startBoneSetId;
        s16 numBoneSets;
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
    /* Slot 8 (0xae780): a bone set's bones copied out. derived name. */
    void FUN_000ae780(hkSkinnedMeshShape::BoneSetId boneSetId, hkArray<s16> &bonesOut) const;
    const char *FUN_000aea20() const;       /* vtable slot 12; derived name */
    void FUN_000aea30(const char *newName); /* vtable slot 13; derived name */
    void FUN_000ae860();                    /* vtable slot 16; derived name */
    /* Slot 15 (0xae9a0): a part appended. derived name. */
    void FUN_000ae9a0(const hkSkinnedMeshShape::Part &part);
    /* Slot 6 (0xae6b0): a copy of a bone section. derived name. */
    void FUN_000ae6b0(int sectionIndex, hkSkinnedMeshShape::BoneSection &sectionOut) const;
    /* Slot 10 (0xae820): a copy of a part. derived name. */
    void FUN_000ae820(int partIndex, hkSkinnedMeshShape::Part &partOut) const;

    /* From its record table at 0x1692420: bonesBuffer, boneSets,
     * boneSections and parts (arrays) from +0x10, name (hkStringPtr) at
     * +0x50. */
    u8 unknownC[4];
    hkArray<s16> bonesBuffer;
    hkArray<hkSkinnedMeshShape::BoneSet> boneSets;
    hkArray<hkSkinnedMeshShape::BoneSection> boneSections;
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

    /* The arrays given back (0x27f50, slot 0; the deleting destructor
     * 0x27fd0 holds the same body). Inline: the executable holds the
     * complete destructor before the deleting one, the order a vtable's
     * first use emits them in, where an out-of-line destructor emits the
     * deleting one first (3.3 CGCXX.cpp:232-246, cookbook 187); its
     * translation unit is one that builds the object. */
    inline virtual ~hkGeometry() {}

    /* The reference-counted class delete (freeReferencedObject in
     * tlg_lib_unknown.h): the deleting destructor frees through it. */
    static void operator delete(void *object, unsigned long numBytes);

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

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    int FUN_0003b980() const;                                      /* vtable slot 5; derived name */
    void FUN_0003b990(int triangleIndex, Vec4 *verticesOut) const; /* vtable slot 6; derived name */
    u16 FUN_0003b9e0(int triangleIndex) const;                     /* vtable slot 7; derived name */

    hkGeometry *geometry;
    /* To the 0x20 bytes of its hkClass (0x57bfc90, built at 0x3baa2), which
     * the deleting destructor frees by default (0x3b948). */
    u8 unknown18[8];
};

/* A 16-byte element of Object000ea540's array; its fields are not
 * recovered. derived name. */
struct Element000ea540 /* derived name */
{
    u8 unknown0[16];
};

/* A polymorphic object of 0x30 bytes (derived name; vtable 0x16a3cc0, three
 * slots: the destructor 0xea540, the deleting destructor 0xea590, which
 * frees 0x30 bytes on the thread's heap, and the shared empty 0xadd50). No
 * constructor is out of line: the one construction, inline in 0xea610 at
 * 0xeae3a as the base of the 0x58-byte Object000ea380, stores 1 at +0x10,
 * 0 at +0x14, 0x20 at +0x18, false at +0x1c and an empty array at +0x20. */
class Object000ea540 /* derived name */
{
  public:
    Object000ea540() : unknown10(1), unknown14(0), unknown18(32), unknown1c(false) {}

    virtual ~Object000ea540();

    /* Slot 2: empty here (the shared 0xadd50). derived name. */
    virtual void unknownVirtual2();

    /* The thread's heap (tlg_lib_unknown.h). */
    static void *operator new(unsigned long numBytes);
    static void operator delete(void *object, unsigned long numBytes);

    u8 unknown8[8];
    int unknown10;
    int unknown14;
    int unknown18;
    bool unknown1c;
    hkArray<Element000ea540> elements; /* derived name */
};

/* The 0x58-byte class over it (derived name; vtable 0x16a3c90, slots its
 * destructors 0xea380 and 0xea440 and the shared empty 0xadd50): what
 * hknpExternMeshShapeData's buildContext points to (the member is not
 * serialized, flags 0x400), built by the extern mesh's builder 0xea610
 * (0xeae0f) when the geometry's slot 8 asks for it, value-initialized: a
 * SIMD tree at +0x30 and the signals at +0x48 that slot 8 of
 * hknpExternMeshShape hands out. Its destructor is inline, emitted with the
 * vtable in the builder's file, the base's inline in it; the shape data's
 * destructor deletes it through slot 1 (0x35333). */
class Object000ea380 : public Object000ea540 /* derived name */
{
  public:
    inline virtual ~Object000ea380();

    hkcdSimdTree tree;                /* derived name */
    hknpShapeSignals mutationSignals; /* derived name */
};

/* With the hint (3.3 inlines the body into the deleting destructor 0xea440
 * only at the hinted threshold, its cost between 225 and 260). */
inline Object000ea380::~Object000ea380() {}

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
        : hkReferencedObject(flag), aabbTree(flag), simdTree(flag)
    {
        buildContext = 0;
    }

    /* A new one (inline in the builder 0xea610): empty trees, no build
     * context. */
    hknpExternMeshShapeData() : buildContext(0) {}

    /* Out of line (0x35310, slot 0; the deleting destructor 0x353c0, slot
     * 1): the build context deleted, then the trees. */
    virtual ~hknpExternMeshShapeData();

    /* The thread's heap, inline (0xeab18), and the reference-counted class
     * delete (freeReferencedObject); both in tlg_lib_unknown.h. Placement
     * stays available beside them (the finish callback, 0x354c0). */
    static void *operator new(unsigned long numBytes);

    static void *operator new(unsigned long, void *where)
    {
        return where;
    }

    static void operator delete(void *object, unsigned long numBytes);

    hkcdStaticTree::DefaultTreeStorage6 aabbTree;
    hkcdSimdTree simdTree;
    Object000ea380 *buildContext;
};

/* hknpExternMeshShape (hkClass 0x57c2898, parent hknpCompositeShape, 0x70
 * bytes): geometry (pointer) at +0x60 and boundingVolumeData (pointer to
 * hknpExternMeshShapeData) at +0x68 (records 0x169abc0, 0x169abe8). */
/* hknpMinMaxQuadTree (hkClass 0x57c1000, built at 0x40f40 by its file's
 * initializer 0x40ea0: size 0x30, no parent; member records at
 * 0x1697800): the coarse levels, then the quantization's offset and
 * scales. */
struct hknpMinMaxQuadTree {
    /* hknpMinMaxQuadTree::MinMaxLevel (hkClass 0x57c0f80, built at 0x40eef:
     * size 0x18; member records at 0x1697780): the packed minima and maxima
     * of one level and its resolution. */
    struct MinMaxLevel {
        hkArray<u32> minMaxData;
        u16 xRes;
        u16 zRes;
    };

    hknpMinMaxQuadTree(hkFinishLoadedObjectFlag flag) : coarseTreeData(flag) {}

    hkArray<MinMaxLevel> coarseTreeData;
    Vec4 offset;
    float multiplier;
    float invMultiplier;
};

/* hknpHeightFieldShape (hkClass 0x57bf540, built at 0x3993e: size 0xf0,
 * parent hknpCompositeShape's 0x57c2cf8): no type info; its vtable 0x16a3e30
 * has a ruled row (D14). Its inline finish constructor's vptr store dies
 * under the derived one (the same block, DSE). */
class hknpHeightFieldShape : public hknpCompositeShape
{
  public:
    hknpHeightFieldShape(hkFinishLoadedObjectFlag flag) : hknpCompositeShape(flag), minMaxTree(flag)
    {
    }

    /* Inline, emitted where the vtable is used (the compressed shape's
     * destructor, func_00175c00.cpp): the base destructor 0x12a8c0 stores
     * the vtable 0x16a3e30 (address point 0x16a3e40) and frees the min-max
     * tree's levels, then runs the composite shape's inline; the complete
     * destructor 0x12a850 (slot 0) is a separate jump to it, which 3.3 makes
     * only of a linkonce destructor (CGCXX.cpp TryEmitDefinitionAsAlias),
     * and the deleting one 0x12a860 (slot 1) frees 0xf0 bytes after it; the
     * base's D1 before D0 is a vtable initializer's order. Slot 7 0x12aa80
     * is shared with the compressed shape's vtable. */
    virtual ~hknpHeightFieldShape() {}

    /* The members from its ten records at 0x1694c90 (the reflection
     * initializer 0x398d0 passes them). */
    hkAabb aabb;
    Vec4 floatToIntScale;
    Vec4 intToFloatScale;
    int intSizeX;
    int intSizeZ;
    int numBitsX;
    int numBitsZ;
    hknpMinMaxQuadTree minMaxTree;
    int minMaxTreeCoarseness;
    hkBool includeShapeKeyInSdfContacts;
};

/* Its member records. */
extern const hkClassMember D_1694c90[]; /* derived name */

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

    /* Out of line (0x175c00, slot 0; the deleting destructor 0x175cb0, slot
     * 1): the two arrays freed, the shape tags first, then the height
     * field's base destructor 0x12a8c0. */
    virtual ~hknpCompressedHeightFieldShape();

    /* The members from its five records at 0x169a620, from +0xe8 (the
     * height field's tail padding). */
    hkArray<u16> storage;
    hkArray<u16> shapeTags;
    hkBool triangleFlip;
    float offset;
    float scale;
};

class hknpExternMeshShape : public hknpCompositeShape
{
  public:
    /* hknpExternMeshShape::Geometry (the name the shape's geometry record
     * gives): the mesh the shape reads its triangles from, over
     * hkReferencedObject; hknpDefaultExternMeshShapeGeometry fills slots 5
     * to 7 and keeps the shared false 0x1bad0 in slot 8. derived names. */
    class Geometry : public hkReferencedObject
    {
      public:
        virtual int unknownVirtual5() const = 0; /* the number of triangles */
        /* A triangle's three vertices. */
        virtual void unknownVirtual6(int triangleIndex, Vec4 *verticesOut) const = 0;
        virtual u16 unknownVirtual7(int triangleIndex) const = 0; /* its material */
        /* Whether the shape data gets a build context (0xead68). */
        virtual bool unknownVirtual8() const;
    };

    /* The finish constructor, out of line (0x1660e0): the finish callback
     * FUN_0006c440 jumps to it, the reflection initializer calls it at
     * 0x6c506. */
    hknpExternMeshShape(hkFinishLoadedObjectFlag flag);

    hknpShapeSignals *FUN_000eafb0(); /* vtable slot 8; derived name */

    /* The bounding volume's box in the shape's space (0xed580, out of
     * line; its one caller is slot 7). derived name. */
    void FUN_000ed580(hkAabb &aabbOut) const;

    /* Slot 7 (0x166370): that box under a transform (0x94060). derived
     * name. */
    void FUN_00166370(const Mat4 &transform, hkAabb &aabbOut) const;

    /* Aligned to 16 bytes (the record's flag 0x100, ALIGN_16), at +0x60. */
    alignas(16) void *geometry;
    hknpExternMeshShapeData *boundingVolumeData;
};

/* Whether a triangle is degenerate under a tolerance (0x185520; the extern
 * mesh's builder and 0x152406 call it): nonzero when it is. derived name. */
int FUN_00185520(const Vec4 &vertex0, const Vec4 &vertex1, const Vec4 &vertex2,
                 const Vec4 &tolerance); /* derived name */

/* The shape data for a geometry (0xea610): a dynamic tree of its
 * triangles' boxes, a triangle the tolerance finds degenerate (0x185520)
 * left out and its index added to the array when there is one; the tree
 * rebuilt and compacted, the static tree built from it, the simd tree from
 * that when asked or when the geometry wants a build context, which it then
 * gets. derived name. */
hknpExternMeshShapeData *FUN_000ea610(const hknpExternMeshShape::Geometry *geometry,
                                      bool buildSimdTree, hkArray<int> *degenerateTriangles,
                                      float tolerance); /* derived name */

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

    /* Out of line (0x41650, slot 0): the destroyed signal fired, then the
     * members; the deleting destructor (0x41600, slot 1) runs it and frees
     * through the class's delete. */
    virtual ~hknpCompoundShape();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    const hkClass *getClassType() const; /* vtable slot 3, FUN_000418b0 */
    void unknownVirtual7(const Mat4 &transform, hkAabb &aabbOut) const; /* FUN_00041870 */
    virtual void updateAabb() = 0;                                      /* slot 31; derived name */
    /* Slot 32: an instance's AABB (hknpDynamicCompoundShape's 0xf04a0). */
    virtual void unknownVirtual32(hknpShapeInstanceId instanceId, hkAabb &aabbOut) const = 0;

    hknpShapeSignals *FUN_00041890(); /* vtable slot 8; derived name */
    /* Slot 27 (0x426b0, kept by the static and dynamic compound shapes):
     * 1 when the scaled size passes 0.3, or 0.15 while the current level
     * is 1. derived name. */
    int FUN_000426b0(const LodContext000426b0 &context, const LodQuery000426b0 &query,
                     int currentLod) const;

    /* Aligned to 16 bytes (the record's flag 0x100, ALIGN_16), at +0x60. */
    alignas(16)
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

    void updateAabb(); /* vtable slot 31, FUN_000d0450 */
    void unknownVirtual32(hknpShapeInstanceId instanceId,
                          hkAabb &aabbOut) const; /* vtable slot 32 */

    /* vtable slot 20 (0xdea30, also hknpStaticCompoundShapeInternals'): a
     * new key mask over the shape. derived name. */
    hknpShapeKeyMask *FUN_000dea30() const;

    /* vtable slot 3, FUN_00038740, also of hknpStaticCompoundShapeInternals
     * (0x1692840), which does not override it */
    const hkClass *getClassType() const;

    /* Its one record (0x169ab60, a pointer to hknpStaticCompoundShapeData):
     * in the compound's tail padding, at +0xb8. */
    hknpStaticCompoundShapeData *boundingVolumeData;
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

    void updateAabb(); /* vtable slot 31, 0xefff0 */
    /* vtable slot 32 (0xf04a0): the instance's leaf of the tree, its max
     * without the tree's w. */
    void unknownVirtual32(hknpShapeInstanceId instanceId, hkAabb &aabbOut) const;

    const hkClass *getClassType() const; /* vtable slot 3, FUN_000358a0 */

    /* From hknpDynamicCompoundShape's records (0x1692e50, 0x169ab60): in
     * the compound's tail padding, at +0xb8. */
    hknpDynamicCompoundShapeData *boundingVolumeData;
};

/* hknpLodShape (type info 0x57c05b8, parent hknpCompositeShape: its finish
 * constructor FUN_00068160 stores hknpCompositeShape's vtable before its own
 * 0x1699c00): slot 7 (FUN_00068350) transforms the AABB at +0x110. */
struct hknpLodShape : public hknpCompositeShape {
    /* The finish constructor, out of line (0x68160): the finish callback
     * FUN_0003de50 jumps to it, the reflection initializer calls it at
     * 0x3dfa6. */
    hknpLodShape(hkFinishLoadedObjectFlag flag);

    /* Inline with the hint (3.3 inlines the body into the deleting
     * destructor 0x681a0 only at the hinted threshold, its cost between 260
     * and 280), emitted with the vtable where slot 7 is defined: the
     * complete destructor 0x68290 (slot 0) holds the base destructor's body,
     * the levels' shapes released, then the composite shape's inline. */
    inline virtual ~hknpLodShape();

    /* What slot 29's first argument holds at +0x10 (derived names). */
    struct Slot29Argument {
        u8 unknown0[0x10];
        int levelOfDetail; /* derived name */
    };

    void unknownVirtual7(const Mat4 &transform, hkAabb &aabbOut) const; /* FUN_00068350 */
    int FUN_00068960(const Slot29Argument *argument1,
                     void *argument2) const; /* vtable slot 29; derived name */
    /* Slot 22 (0x68440): the level the first key selects (its top key
     * bits) asked for the leaf, the keys handed on with this shape's bits
     * shifted out (each the next key's bits set below it), at most ten.
     * derived names. */
    void FUN_00068440(const u32 *keys, int numKeys, void *argument3) const;
    /* Slot 21 (0x68380): the query's level of detail, at most the last
     * level, asked with the key shifted by this shape's bits and the
     * query's key extended by the level (its bits set below it). derived
     * name. */
    int FUN_00068380(void *argument1, int argument2, int key,
                     const ShapeKeyQuery000380b0 &query) const;
    /* Slot 27 (0x68500): the finest level whose distance, halved for the
     * current level so the choice does not flicker, is below the query's
     * scaled size; 0 when none is (the context is not read). derived
     * name. */
    int FUN_00068500(const LodContext000426b0 &context, const LodQuery000426b0 &query,
                     int currentLod) const;

    /* A level's limits (derived names; 8 bytes each in the records). */
    struct LevelOfDetailInfo {
        float maxDistance;
        float maxShrink;
    };

    /* Members from the records at 0x16965c0. */
    int numLevelsOfDetail;
    LevelOfDetailInfo infos[8];
    const hknpShape *shapes[8];
    u8 unknownD8[0x38]; /* shapesMemorySizes, indexCurrentShapeOnSpu, currentShapePpuAddress */
    hkAabb aabb;        /* maximumAabb */
};

inline hknpLodShape::~hknpLodShape()
{
    hkReferencedObject::FUN_000069c0(reinterpret_cast<const hkReferencedObject *const *>(shapes),
                                     numLevelsOfDetail, sizeof(shapes[0]));
}

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

    /* Out of line (0x85b00, slot 0): the name, then the blob's bytes, the
     * blob's destructor inline; the deleting destructor (0x85b70, slot 1)
     * runs it and frees through the class's delete. */
    virtual ~hkxBlobMeshShape();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

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
    /* The finish constructor, out of line (0x878f0): the three strings
     * finished in order. */
    hkxTextureFile(hkFinishLoadedObjectFlag flag);

    /* Slot 0 (0x87830): the three strings destroyed, the last first; the
     * deleting destructor (0x87870, slot 1) runs it and frees through the
     * class's delete. */
    virtual ~hkxTextureFile();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

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
    hkxAnimatedFloat(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag), floats(flag) {}

    /* Out of line (0x8b950, slot 0): the floats given back. */
    virtual ~hkxAnimatedFloat();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    const hkClass *getClassType() const; /* vtable slot 3, FUN_0008ba30 */

    /* From its hkClass (records built at run time by 0x8ba60): floats (an
     * array of reals) at +0x10, hint at +0x20. */
    hkArray<float> floats;
    u8 hint; /* an enum of hkUint8 (its record's type and subtype, 0x8bb07) */
};

class AllocatorBase; /* tlg_lib_unknown.h */

/* hkArrayStreamWriter: its hkClass at 0x57c8750 is built by the reflection initializer at
 * 0x901fb; slot 3 of its vtable (address point 0x16a3300, FUN_0008ff00) returns it. Its hkClass has no parent (null third
 * argument at 0x90209): hkStreamWriter is not reflected. Its vtable keeps
 * the stream writer's slots: 5 true (0x40b0), 6 the write (0x90000), 7 an
 * empty flush (0x270), 8 true (0x40b0). */
extern const hkClass D_57c8750; /* hkArrayStreamWriter's hkClass */

class hkArrayStreamWriter : public hkStreamWriter
{
  public:
    /* Who frees the array: the writer when it took it, nobody when it
     * borrowed it (hkOstream's constructor, 0x81c4, borrows). derived
     * names. */
    enum ArrayOwnership { ARRAY_TAKE = 0, ARRAY_BORROW = 1 };

    /* 0x8fe10 (slots 0 and 1 through the deleting destructor 0x8fe60): a
     * taken array goes back to the thread's heap. */
    virtual ~hkArrayStreamWriter();

    /* The class allocator's delete (the deleting destructor 0x8fe60 frees
     * at the recorded size, 0x28 by default). */
    static void operator delete(void *object, unsigned long numBytes);

    const hkClass *getClassType() const; /* vtable slot 3, FUN_0008ff00 */

    /* The members hkOstream's constructor (0x8140) gives a writer it builds
     * inline: the array, the containers' allocator, the array's size as the
     * write offset and ARRAY_BORROW. derived names. */
    /* Slot 12 (0x8ffa0; the packfile writer calls it directly at 0x1a37d6
     * and 0x1a384c): the array emptied and the offset rewound, then a
     * terminating zero kept past the end. derived name. */
    void FUN_0008ffa0();

    /* The write (0x90000): the array grown past the offset when it is
     * short, a terminating zero kept past its end either way (when there
     * is room), the bytes copied in at the offset and the offset moved on;
     * all of them written. derived name. */
    int FUN_00090000(const void *data, int numBytes);

    /* The seek (0x90100): from the start, the offset or the end (0, 1, 2;
     * any other keeps the offset); past the end the array grows, zero
     * filled with a terminating zero kept past it; a negative place fails.
     * derived name. */
    hkResult FUN_00090100(int offset, int whence);

    hkArray<char> *array;
    AllocatorBase *allocator;
    int offset;
    int ownership;
};

/* hknpVehicleInstance: hkClass 0x57c1490 (size 0x120, parent hknpUnaryAction's
 * 0x57bfbc0), built by the reflection initializer at 0x47a5d with its member
 * records at 0x1698a70; its finish callback 0x47990 stores the vtable
 * (address point 0x16a50a0, complete destructor FUN_001625d0). Members read so
 * far: world at +0x20, wheelCollide (a pointer to hknpVehicleWheelCollide)
 * at +0x68, wheelsInfo (array of hknpVehicleInstance::WheelInfo)
 * at +0x80, torque and rpm (hkReal) at +0xf8 and +0xfc, mainSteeringAngle
 * at +0x100. */
/* hkContactPoint (its member records at 0x168d9b0): position and
 * separatingNormal, the distance in the normal's w. */
struct hkContactPoint {
    Vec4 position;
    Vec4 separatingNormal;
};

/* What a wheel collide reports for a wheel (derived names, after the
 * wheel info's members it fills): the contact point, the friction, the
 * body and shape key, the suspension's length, its closing speed and its
 * scaling factor. */
struct WheelCollideOutput /* derived name */
{
    hkContactPoint contactPoint;
    float contactFriction;
    hknpBodyId contactBodyId;
    u32 contactShapeKey;
    float currentSuspensionLength;
    float suspensionClosingSpeed;
    float suspensionScalingFactor;
};

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

/* Its hkClass (0x57c1510), its one enum, WheelCollideType (0x16993b0), and
 * its member records (0x16992b0), which the reflection initializer 0x5b250
 * passes. */
extern const hkClass D_57c1510;         /* hknpVehicleWheelCollide's hkClass */
extern const hkClassEnum D_16993b0[];   /* derived name */
extern const hkClassMember D_16992b0[]; /* derived name */

/* hknpVehicleRayCastWheelCollide (type info at 0x7604a, vtable 0x16a4aa0)
 * and hknpVehicleLinearCastWheelCollide (0x38 bytes, type info at 0x708de,
 * vtable 0x16a5bd0). */
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

    /* Slot 15 (0x159010): a wheel's output when its ray hits nothing: at
     * the ray's end, against the suspension's direction, the suspension
     * fully extended. derived name. */
    void FUN_00159010(const class hknpVehicleInstance *vehicle, u8 wheelIndex,
                      WheelCollideOutput &output) const;

    /* Slot 12 (0x158a40): the box around every wheel's ray, from its hard
     * point to its end point. derived name. */
    void FUN_00158a40(const class hknpVehicleInstance *vehicle, hkAabb &aabbOut) const;
};

void FUN_00075f60(void *object, int finishing); /* derived name: its type info's finish callback */

class hknpVehicleLinearCastWheelCollide : public hknpVehicleWheelCollide
{
  public:
    hknpVehicleLinearCastWheelCollide(hkFinishLoadedObjectFlag flag)
        : hknpVehicleWheelCollide(flag), wheelStates(flag)
    {
        if (flag.finishing) {
            type = LINEAR_CAST_WHEEL_COLLIDE;
        }
    }

    /* Out of line (0x178d80, slot 0; the deleting destructor 0x178c80 is
     * emitted beside it): each wheel state's shape released, then the
     * states' storage given back. */
    virtual ~hknpVehicleLinearCastWheelCollide();

    /* The reference-counted class delete (freeReferencedObject in
     * tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    /* Slot 14 (0x179700): the same body as the ray cast's slot 15, for a
     * cast that hits nothing. derived name. */
    void FUN_00179700(const class hknpVehicleInstance *vehicle, u8 wheelIndex,
                      WheelCollideOutput &output) const;

    /* Slot 11 (0x1797b0): a point moved onto the plane of the wheel's cast,
     * taken into the wheel's space, its z cleared, and brought back. derived
     * name. */
    void FUN_001797b0(const class hknpVehicleInstance *vehicle, u8 wheelIndex, Vec4 &point) const;

    /* hknpVehicleLinearCastWheelCollide::WheelState (its hkClass string at
     * 0x14bf35d, records at 0x169afc0, 0x80 bytes). */
    struct WheelState {
        hkAabb aabb;
        const hknpShape *shape;
        hkTransform transform;
        Vec4 to;
    };

    /* The members from the records at 0x169b060. */
    hkArray<WheelState> wheelStates;
    float maxExtraPenetration;
    float startPointTolerance;
    u32 chassisBody; /* an hkUint32 in the record */
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
    hknpVehicleInstance(hkFinishLoadedObjectFlag flag)
        : hknpUnaryAction(flag), world(0), wheelsInfo(flag)
    {
    }

    virtual ~hknpVehicleInstance();

    void FUN_00162540(hknpBodyId *&bodiesOut, int &numBodiesOut); /* vtable slot 5; derived name */
    void FUN_00162550(hknpBodyId removedId);                      /* vtable slot 6; derived name */
    void FUN_00165990(
        const hknpVehicleInstanceSlot8Argument *argument); /* vtable slot 8; derived name */
    void FUN_001659b0();                                   /* vtable slot 9; derived name */
    float FUN_00165880() const;                            /* vtable slot 13; derived name */
    /* Slots 14 and 15 (0x165890, 0x165910): the chassis's speed in
     * kilometres and in miles an hour. derived names. */
    float FUN_00165890() const;
    float FUN_00165910() const;

    /* What slot 16 fills (derived names): two flags, an int, vectors at
     * +0x10, +0x20 and +0x70, two pointer-sized fields at +0x30 and a
     * rotation at +0x40. */
    struct Slot16Output {
        hkBool flag0;
        hkBool flag1;
        u8 unknown2[6];
        int value8;
        Vec4 vector10;
        Vec4 vector20;
        u64 unknown30;
        u64 unknown38;
        hkMatrix3 rotation;
        Vec4 vector70;
    };

    /* Slot 16 (0x162db0): the first flag set, everything else zero and the
     * rotation the identity (rows 29 to 31 of the constant table); the
     * second argument is not read. derived name. */
    void FUN_00162db0(const void *argument1, Slot16Output &out) const;

    /* hknpVehicleInstance::WheelInfo (0xc0 bytes, member records from
     * 0x16987a0). */
    struct WheelInfo {
        hkContactPoint contactPoint;
        float contactFriction;
        hknpBodyId contactBodyId;
        u32 contactShapeKey;
        u8 unknown2c[4];
        Vec4 hardPointWs;
        Vec4 rayEndPointWs;
        float currentSuspensionLength;
        u8 unknown54[0xc];
        Vec4 suspensionDirectionWs;
        Vec4 spinAxisChassisSpace;
        Vec4 spinAxisWs;
        hkQuaternion steeringOrientationChassisSpace;
        float spinVelocity;
        float noSlipIdealSpinVelocity;
        float spinAngle;
        float skidEnergyDensity;
        float sideForce;
        float forwardSlipVelocity;
        float sideSlipVelocity;
        u8 unknownBc[4];
    };

    hknpWorld *world;
    hknpVehicleData *data;
    u8 unknown30[0x28];
    hknpVehicleSuspension *suspension;
    u8 unknown60[8];
    hknpVehicleWheelCollide *wheelCollide;
    u8 unknown70[0x10];
    hkArray<WheelInfo> wheelsInfo;
    u8 unknown90[0x64];
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
    u8 unknown78[8]; /* to the 0x80 bytes its deleting destructor 0x176b20 frees */
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

/* A query result as the collectors keep them (derived names): 0x60 bytes,
 * a position, a normal and a fraction, then what the query and the hit
 * each touched: a body, its shape's material, a shape key, the shape's
 * filter info and user data. A hit is assigned member by member (the
 * closest-hit collector's 0x696e0: the two ids each on their own, the
 * words after them together). */
struct hknpCollisionResult /* derived name */
{
    struct BodyInfo {
        /* No body, material or shape key; the filter info and user data
         * zero (inline in the closest-hit collector's reset, 0x69670 on).
         * derived name. */
        void clear()
        {
            bodyId.value = 0x7fffffff;
            shapeKey = 0xffffffff;
            shapeMaterialId.value = 0xffff;
            shapeCollisionFilterInfo = 0;
            shapeUserData = 0;
        }

        hknpBodyId bodyId;
        hknpMaterialId shapeMaterialId;
        u32 shapeKey;
        u32 shapeCollisionFilterInfo;
        u64 shapeUserData;
    };

    /* An empty result: no query type, at the origin, at the largest
     * fraction, touching nothing (0x69640). derived name. */
    void clear()
    {
        queryType = 0;
        normal.quad = _mm_setzero_ps();
        position.quad = _mm_setzero_ps();
        fraction = HK_REAL_MAX;
        queryBodyInfo.clear();
        hitBodyInfo.clear();
    }

    hkVector4 position;
    hkVector4 normal;
    float fraction;
    BodyInfo queryBodyInfo;
    BodyInfo hitBodyInfo;
    u32 queryType;
    u32 unknown5c;
};

/* A collector that keeps every hit, Havok's all-hits collector by its shape
 * (derived name, after its destructor: the vtable row D14's ruling names,
 * 0x169b100, address point 0x169b110, no type info), 0x3f0 bytes: the hits in an array
 * at +0x20 over room for ten in the object (the game builds it on the stack
 * with capacity 0x8000000a and the storage at +0x30, 0xe9c32c on). Slot 3
 * (FUN_00070a10) empties it; its destructors 0x70900 and 0x70970 empty it
 * and free the array. */
class hknpAllHitsCollector : public hknpCollisionQueryCollector /* derived name */
{
  public:
    virtual ~hknpAllHitsCollector();

    void reset(); /* vtable slot 3, FUN_00070a10 */
    /* Slot 4 (0x70a50): a hit appended. derived name. */
    void FUN_00070a50(const hknpCollisionResult &hit);

    hkInplaceArray<hknpCollisionResult, 10> hits; /* derived name */
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

    /* Slot 3 (0x69640): no hints, the early-out value the largest (row 34
     * of the constant table), the kept hit cleared and none kept. */
    void reset();

    /* Slot 4 (0x696e0): a hit nearer than the kept one kept, its fraction
     * the new early-out value. derived name. */
    void FUN_000696e0(const hknpCollisionResult &result);

    hknpCollisionResult hit; /* derived name */
    hkBool hasHit;           /* derived name */
};

/* hkpParametricCurve (hkClass 0x57c3c68, 0x10 bytes, parent
 * hkReferencedObject, no members of its own). */
class hkpParametricCurve : public hkReferencedObject
{
  public:
    hkpParametricCurve(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag) {}
};

/* Built by the reflection initializer at 0x7c030. */
extern const hkClass D_57c3c68; /* hkpParametricCurve's hkClass */

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

    /* The arrays given back (0x7f470, slot 0; the deleting destructor
     * 0x7f4f0 holds the same body). Inline, emitted with the vtable: the
     * executable holds the complete destructor before the deleting one
     * (cookbook 187). */
    inline virtual ~hkpLinearParametricCurve() {}

    /* The reference-counted class delete (freeReferencedObject in
     * tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    /* Slot 5 (0x7f5c0): the point at a parameter, between the points
     * either side of it. derived name. */
    void FUN_0007f5c0(float t, Vec4 &pointOnCurve) const;
    float FUN_0007fad0() const; /* vtable slot 9; derived name */
    /* Slot 10 (0x7fae0): the distance along the curve at a parameter,
     * interpolated in the segment the parameter falls in (the last one
     * extended past the end). derived name. */
    float FUN_0007fae0(float t) const;
    /* Slot 13 (0x7fde0): the points copied out, the output's storage
     * replaced from the containers' allocator when it is too small. derived
     * name. */
    void FUN_0007fde0(hkArray<Vec4> &pointsOut) const;
    /* Slot 14 (0x7fea0): every point moved under the transform. derived
     * name. */
    void FUN_0007fea0(const hkTransform &transform);

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
struct hkBlockStream;      /* derived name */
struct BlockCache;         /* derived name; below */
struct hkBlockStreamBlock; /* derived name; below */

struct hkBlockStreamWriter /* derived name */
{
    /* An unbound writer. */
    hkBlockStreamWriter() : blockStream(0) {}

    /* Binds the writer to a stream at its first block (0x938a0). derived
     * name. */
    void FUN_000938a0(BlockCache *cache, hkBlockStream *stream);

    /* Binds the writer to a stream to append to its last block (0x938c0):
     * the block's used bytes and elements become the writer's, and its
     * elements leave the stream's count until the writer closes the block
     * again. derived name. */
    void FUN_000938c0(BlockCache *cache, hkBlockStream *stream);

    /* Closes the current block (its header written, linked to a new block
     * from the cache, its elements added to the stream's count) and returns
     * the new block's data (0x939c0, 30 callers). derived name. */
    void *FUN_000939c0();

    /* Finishes the writer (0x93a10): the current block closed as 0x939c0
     * closes it, or given back when nothing was written to it and the
     * stream has another; the writer keeps no block. derived name. */
    void FUN_00093a10();

    /* Room for numBytes more in the current block, a new block when they
     * do not fit (0x1785a0 inline). derived name. */
    void *reserve(int numBytes);

    /* The bytes reserved counted as one element written: the count read
     * before the offset is written (every writer's advance in the region,
     * 0x31994, 0x6f64c, 0x904f0's 0x90550, keeps `mov eax, [count]; add
     * [offset], n; inc eax; mov [count], eax`). derived name. */
    void advance(int numBytes)
    {
        const int numElements = currentNumElements + 1;
        currentByteOffset += numBytes;
        currentNumElements = numElements;
    }

    hkBlockStream *blockStream;       /* derived name */
    hkBlockStreamBlock *currentBlock; /* derived name */
    int currentByteOffset;            /* derived name */
    int currentNumElements;           /* derived name */
    /* The cache the stream's new blocks come from (0x947f0 takes one from
     * it). derived name. */
    BlockCache *cache;
    /* To the 0x28 bytes the writers keep apart (the command writer's 0x38
     * bytes end 0x28 after its writer at +0x10; the pairs task's writers
     * sit 0x28 apart), not read by the writer's functions. */
    u8 unknown20[8];
};

/* The writers of the narrow phase's pairs task (derived names): a stack
 * object of its work (0x15ea30, at -0x808), every writer finalized at its
 * end in its "StFinalizeWriters" timer (0x15e030), the three from +0x128
 * only when the first of them was bound. */
struct CollideWriters0015e030 /* derived name */
{
    /* derived name */
    void FUN_0015e030();

    hkBlockStreamWriter writer0;
    hkBlockStreamWriter writer28;
    hkBlockStreamWriter writer50;
    hkBlockStreamWriter writer78;
    hkBlockStreamWriter writerA0;
    u8 unknownC8[8];
    hkBlockStreamWriter writerD0;
    u8 unknownF8[8];
    hkBlockStreamWriter writer100;
    hkBlockStreamWriter writer128;
    hkBlockStreamWriter writer150;
    hkBlockStreamWriter writer178;
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

    /* The reference-counted class delete (tlg_lib_unknown.h): the deleting
     * destructor (0x90460) frees at the recorded size, 0x38 by default. */
    static void operator delete(void *object, unsigned long numBytes);

    /* Slot 5 (0x904f0): the command copied into the stream as it is, in
     * 4-byte words, its padded size reserved and counted as one element.
     * derived name. */
    void FUN_000904f0(const struct hkCommand &command);

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

struct BlockCache /* derived name */
{
    void *FUN_0008eec0();           /* derived name */
    void FUN_0008ef10(void *block); /* derived name */
    void FUN_0008ef60();            /* derived name */
    /* A batch of blocks taken back (0x8efa0): six or more go straight to
     * the allocator, fewer join the cache, which hands six to the allocator
     * first when they would overfill it. derived name. */
    void FUN_0008efa0(hkBlockStreamBlock *const *blocks, int numBlocks);

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
        /* Written and changed as one word; the range's end point
         * (0x92220) reads the element count alone, a 16-bit load. */
        union {
            u32 numElementsAndBytesUsed; /* derived name */

            struct {
                u16 numElements; /* derived name */
                u16 bytesUsed;   /* derived name */
            };
        };

        int blockIndexInStream; /* derived name */
    };

    Header getHeader() const
    {
        return header;
    }

    Header header; /* derived name */
    /* The block after it, cleared when a writer closes the block (0x93a3b)
     * and when the block becomes the stream's last (0x9505f). derived
     * name. */
    hkBlockStreamBlock *next;
    /* The stream's pointer at +0, copied when the block joins it
     * (0x94837). derived name. */
    void *pointer10;
    u8 unknown18[8];
    u8 data[0xfe0]; /* derived name */
};

inline void *hkBlockStreamWriter::reserve(int numBytes)
{
    if (currentByteOffset + numBytes <= int(sizeof(currentBlock->data))) {
        return currentBlock->data + currentByteOffset;
    }
    return FUN_000939c0();
}

/* A 16-byte collision cache (derived names): the two bodies' ids, its type
 * and its size in 16-byte quads at +8 and +9, three 16-bit fields after.
 * FUN_001785a0 writes one of type 1 for a new pair of the broad phase's
 * walk (0x1742c3), the type and size as one 2-byte header (its `mov word
 * [rax+8], 0x101` beside the merged pair of 16-bit zeros, cookbook 139). */
struct CollisionCache001785a0 /* derived name */
{
    struct Header {
        u8 type;        /* derived name */
        u8 sizeInQuads; /* derived name */
    };

    u32 bodyIdA;
    u32 bodyIdB;
    Header header;
    u16 unknownA;
    u16 unknownC;
    u16 unknownE;
};

/* derived name: the cache of a new pair appended to the writer; the world
 * is not read. */
void FUN_001785a0(const hknpWorld *world, const hknpBody *bodyA, const hknpBody *bodyB,
                  hkBlockStreamWriter *writer); /* derived name */

struct hkBlockStreamReader; /* derived name; below */

struct hkBlockStream /* derived name */
{
    /* The blocks before the reader's current one freed (0x94d90, called
     * at 0x64cc2 and 0x64d14), 0x94df0 inline. derived name. */
    void FUN_00094d90(BlockCache *cache, const hkBlockStreamReader *reader);
    /* The stream put back in order after blocks were freed out of it
     * (0x94c60): the remaining blocks moved down and renumbered, their
     * elements counted again, and a block from the cache when none is
     * left. derived name. */
    void FUN_00094c60(BlockCache *cache);
    void FUN_00094df0(BlockCache *cache, void *block, int index); /* derived name */
    /* The last block given back to the cache and dropped, the block before
     * it returned as the new last (0x95030; the writer's finalize 0x93a10
     * drops an empty last block of a stream of two or more). derived
     * name. */
    hkBlockStreamBlock *FUN_00095030(BlockCache *cache);
    /* A block from the cache appended as the stream's last, its index
     * recorded (0x947f0; the writer's 0x939c0 opens each new block with
     * it; the stream's setup 0x94750 runs it in place). derived name. */
    hkBlockStreamBlock *FUN_000947f0(BlockCache *cache);
    /* Every block given back to the cache in one batch, the ones freed
     * while it was read dropped from the list first, and the stream left
     * empty (0x94990, forty callers). derived name. */
    void FUN_00094990(BlockCache *cache);
    /* The stream emptied down to one block, the others given back to the
     * cache (0x94880). derived name. */
    void FUN_00094880(BlockCache *cache);

    /* The stream set up over a cache (0x94750): the cache's allocator
     * kept, nothing counted or freed, the zeroing chosen, and its first
     * block appended (0x947f0 inline). derived name. */
    void FUN_00094750(BlockCache *cache, hkBool zero);

    /* The cache's allocator, taken when the stream is set up (0x9475a) and
     * copied into each new block's +0x10 (0x94837). derived name. */
    BlockStreamAllocator *allocator;
    int numTotalElements; /* derived name */
    u8 unknownC[0xc];
    hkBool partiallyFreed; /* derived name */
    /* A new block cleared whole when set, else only its first 32 bytes
     * (0x94805). derived name. */
    hkBool zeroNewBlocks;
    u8 unknown1a[6];
    hkArray<hkBlockStreamBlock *> blocks; /* derived name */
};

/* A block stream that keeps its first 24 block pointers in place (derived
 * name): the stream, the inline storage its array starts in, 0x100 bytes. */
struct hkBlockStreamInplace /* derived name */
{
    hkBlockStream stream;
    hkBlockStreamBlock *inlineBlocks[24];
    u8 unknownF0[0x10];
};

/* The world's streams at +0x260 (derived names; built by FUN_00174590):
 * twelve block streams of 0x100 bytes, named by their offsets, then three
 * arrays at +0xc00, +0xc10 (16-byte elements) and +0xc20. The streams go in
 * pairs (the checks of 0x151c80 take +0, +0x100 and +0x400, +0x500 and
 * +0x200, +0x300). */
struct hknpWorldStreams260 /* derived name */
{
    /* Every stream's blocks given back to the cache (0x174de0; the world's
     * teardown at 0x4b3ad), the first of each pair before the second, the
     * pairs in the order 0, 2, 1, 4, 3, 5. derived name. */
    void FUN_00174de0(BlockCache *cache);

    hkBlockStreamInplace stream000;
    hkBlockStreamInplace stream100;
    hkBlockStreamInplace stream200;
    hkBlockStreamInplace stream300;
    hkBlockStreamInplace stream400;
    hkBlockStreamInplace stream500;
    hkBlockStreamInplace stream600;
    hkBlockStreamInplace stream700;
    hkBlockStreamInplace stream800;
    hkBlockStreamInplace stream900;
    hkBlockStreamInplace streamA00;
    hkBlockStreamInplace streamB00;
    hkArray<u8> arrayC00;
    hkArray<Vec4> arrayC10;
    hkArray<u8> arrayC20;
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
    /* Ends the range where a writer is (0x92220): its count until then
     * (the start stored it negated), and a start at the end of a full block
     * moved to the next block. derived name. */
    void FUN_00092220(const hkBlockStreamWriter *HK_RESTRICT writer);

    const hkBlockStreamBlock *startBlock; /* derived name */
    u16 startByteOffset;                  /* derived name */
    u16 startBlockNumElements;            /* derived name */
    int numElements;                      /* derived name */
};

/* hknpCollisionDispatchType (an enum the reflection names, its items'
 * names and values from its records): a shape's dispatch type, the index
 * of the cache creators' table. */
struct hknpCollisionDispatchType {
    enum Enum { NONE = 0, CONVEX = 1, COMPOSITE = 2, DISTANCE_FIELD = 3, USER = 4, NUM_TYPES = 5 };
};

/* hknpCollisionDispatcher (its file's report names it, 0x174050): the
 * world's +0x268 object, 0xd0 bytes from the thread's heap (0x49a83), a
 * table of cache creators by the two shapes' dispatch types. derived
 * names but the class's. */
struct hknpCollisionDispatcher {
    /* A creator of a pair's collision caches; the arguments are not
     * recovered (0x1743b0 appends to a stream writer it takes fourth).
     * derived name. */
    typedef void (*CacheCreatorFunc)(const void *argument1, const void *argument2,
                                     const void *argument3, void *argument4);

    /* Out of line (0x173f90): every pair unregistered, nothing for a shape
     * without a dispatch type, then the creators of the pairs it knows. */
    hknpCollisionDispatcher();

    /* A creator for a pair of types, either way round. derived name. */
    void registerCacheCreator(hknpCollisionDispatchType::Enum typeA,
                              hknpCollisionDispatchType::Enum typeB, CacheCreatorFunc func)
    {
        dispatchTable[typeA][typeB] = func;
        dispatchTable[typeB][typeA] = func;
    }

    /* The bytes a creator may write for one pair (0x1743b0 reserves 0x50
     * of the writer's block). derived name. */
    int maxCacheSize;
    CacheCreatorFunc dispatchTable[hknpCollisionDispatchType::NUM_TYPES]
                                  [hknpCollisionDispatchType::NUM_TYPES]; /* derived name */
};

/* The creators the dispatcher registers (derived names): no cache for a
 * shape without a dispatch type (the shared empty body 0x16a370), the
 * unregistered pair's report (0x174050), and the convex, composite and
 * distance field pairs'. */
void FUN_0016a370(const void *argument1, const void *argument2, const void *argument3,
                  void *argument4);
void FUN_00174050(const void *argument1, const void *argument2, const void *argument3,
                  void *argument4);
void FUN_00179c80(const void *argument1, const void *argument2, const void *argument3,
                  void *argument4);
void FUN_00199b00(const void *argument1, const void *argument2, const void *argument3,
                  void *argument4);
void FUN_00199970(const void *argument1, const void *argument2, const void *argument3,
                  void *argument4);
void FUN_001743b0(const void *argument1, const void *argument2, const void *argument3,
                  void *argument4);

/* The broad phase's pair walk (0x174100, also the caller of the reader's
 * FUN_00093830 at 0x174184): the world's +0x268 object, the world (its
 * material library's +0x28), the range of pairs to read, the writer and an
 * optional array of 16-byte entries it appends to. derived name. */
void FUN_00174100(void *argument1, hknpWorld *world, const hkBlockStreamRange *range,
                  hkBlockStreamWriter *writer, void *entries);

/* An object with a block stream at +0x400 that 0x174ea0 appends the walk's
 * output to (the simulation's 0x6cb88 and 0x15bcc8 pass it). derived name. */
struct Streams00174ea0 /* derived name */
{
    u8 unknown0[0x400];
    hkBlockStream stream400; /* derived name */
};

/* The walk over a range written to the end of the object's stream through
 * a writer of its own (0x174ea0). derived name. */
void FUN_00174ea0(Streams00174ea0 *self, hknpWorld *world, BlockCache *cache,
                  const hkBlockStreamRange *range, void *entries);

/* A motion moved on by a time step (0xcd870; the caller 0x157be0 passes
 * the motion's scaled velocities): its centre of mass along the linear
 * velocity, its orientation turned by the half-angle quaternion of the
 * angular velocity and renormalized. derived name. */
void FUN_000cd870(const Vec4 &linearVelocity, const Vec4 &angularVelocity, const Vec4 &deltaTime,
                  hknpMotion &motion); /* derived name */

/* What 0x167f70 resets for the simulation (derived names; the loop at
 * 0x170770 runs it over an object's +0x10 with the owner's +0x250 and
 * +0x258): a cache of its own at +0x258, a command stream at +0x280, the
 * command writer at +0x380 and the range its commands start at, +0x390. */
struct CommandStreams00167f70 /* derived name */
{
    /* The stream emptied with the cache given; a writer present is bound to
     * it again and the range started where the writer is: its block, the
     * offset and count in that block, and the stream's count so far
     * negated, all read before the range is written. derived name. */
    void FUN_00167f70(void *argument1, BlockCache *streamCache);

    /* A motion's previous-step velocities scaled, and the speed at +0x36 with
 * them, the motion moved by the old ones over the part of the step the
 * scale adds, (factor - 1) times the step (0x157be0; the world's 0x5dad1
 * passes its step's time). derived name. */
    void FUN_00157be0(hknpMotion &motion, const Vec4 &factor, const Vec4 &deltaTime);

    u8 unknown0[0x258];
    BlockCache *cache; /* derived name */
    u8 unknown260[0x20];
    hkBlockStream commands; /* derived name */
    u8 unknown2b0[0xd0];
    hkBlockStreamCommandWriter *commandWriter; /* derived name */
    u8 unknown388[8];
    hkBlockStreamRange commandRange; /* derived name */
};

/* The caches a thread's streams are emptied with (derived names): the
 * first at +0x258, as CommandStreams00167f70 keeps its own, and a second
 * at +0x260 (the step's callers 0x14f5a0 and 0x15000c pass it). */
struct StreamCaches0015e980 /* derived name */
{
    u8 unknown0[0x258];
    BlockCache *cache;       /* derived name */
    BlockCache *secondCache; /* derived name */
};

/* Seven block streams of a step (derived names; an array of them hangs off
 * +0x108 of the callers' object, each in use when its byte at +0x700 is
 * set, 0x14f58e), each 0x100 bytes from the last: what follows a stream in
 * its 0x100 is not yet read. FUN_0015e980 empties the first four, and in
 * mode 1 the other three, the last with the second cache. */
struct StepStreams0015e980 /* derived name */
{
    struct Slot {
        hkBlockStream stream;
        u8 unknown30[0xd0];
    };

    void FUN_0015e980(const StreamCaches0015e980 *caches, int mode); /* derived name */

    Slot slot0;
    Slot slot1;
    Slot slot2;
    Slot slot3;
    Slot slot4;
    Slot slot5;
    Slot slot6;
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
    /* The next block made current (0x93bf0, five callers): its elements,
     * as many as are still to read, and its data returned; null at the
     * end, the reader emptied. derived name. */
    const void *FUN_00093bf0();
    /* The same, the block after the new one and the new one's second
     * cache line prefetched (0x93830, nineteen callers, the broad phase's
     * pair walk 0x174184 among them). derived name. */
    const void *FUN_00093830();

    /* The element read now, null at the end. derived name. */
    const void *access() const
    {
        return currentByteLocation;
    }

    /* The next element of a size: within the block, or the next block's
     * first (0x65f80 to 0x65fa3). derived name. */
    const void *advance(int elementSize)
    {
        numElementsToReadInThisBlock--;
        if (numElementsToReadInThisBlock > 0) {
            currentByteLocation = hkAddByteOffsetConst(currentByteLocation, elementSize);
            return currentByteLocation;
        }
        return FUN_00093830();
    }

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
    /* Starting at a range (0x93ab0): the same over the range, the
     * reader's start written out (the range's count read once, before the
     * stream's flag is stored); the third argument is not read. derived
     * name. */
    void FUN_00093ab0(BlockCache *cache, hkBlockStream *stream, hkBlockStream *argument3,
                      const hkBlockStreamRange *range); /* derived name */

    /* The next block made current as the reader's FUN_00093830 makes it
     * (0x93b10, inline there), then the block left freed as far as this
     * consumer consumed it: back to the stream when every element was,
     * else the consumed ones taken off its count. derived name. */
    const void *FUN_00093b10();

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
    /* Slot 6: the command written to a stream. derived name. */
    virtual void print(const hkCommand &command, hkOstream &stream) const = 0;
};

/* A body command (derived names): primary type 4, secondary type 20, the
 * body's id after the header; 16 bytes padded. Slot 12 of the vtable at
 * 0x16a5870 (FUN_00171180) builds one on its stack for the executor at
 * +0x380 of its second argument. */
struct BodyCommand00171180 : public hkCommand /* derived name */
{
    /* The header filled in order, then the id, taken by value. */
    BodyCommand00171180(u32 id)
    {
        sizePaddedTo16 = 16;
        unknown2 = 0;
        primaryType = 4;
        secondaryType = 20;
        bodyId = id;
    }

    u32 bodyId; /* derived name */
};

struct CommandOwner00171180 /* derived name */
{
    u8 unknown0[0x380];
    hkSecondaryCommandDispatcher *dispatcher; /* derived name */
};

/* An event of two bodies entering or leaving each other's manifold (derived
 * names; primary type 4, secondary type 0, 0x30 bytes padded): each body as
 * its byte at +0x7f and its id, the status at +0x19 (0 when the manifold is
 * created, 1 when it goes), and two keys left at -1. */
struct ManifoldEvent169b1a0 : public hkCommand /* derived name */
{
    enum Status /* derived names */
    {
        STATUS_CREATED = 0,
        STATUS_DESTROYED = 1
    };

    /* The header filled in order, then the bodies' words, the status and
     * the keys. */
    ManifoldEvent169b1a0(u32 bodyByte7fA, u32 idA, u32 bodyByte7fB, u32 idB, Status manifoldStatus)
    {
        sizePaddedTo16 = 0x30;
        unknown2 = 0;
        primaryType = 4;
        secondaryType = 0;
        byte7fA = bodyByte7fA;
        bodyIdA = idA;
        byte7fB = bodyByte7fB;
        bodyIdB = idB;
        unknown18 = 0;
        status = u8(manifoldStatus);
        keyA = 0xffffffff;
        keyB = 0xffffffff;
    }

    /* The same with the byte at +0x18 and the bodies' shape keys given
     * (the modifier slot 0x1622a0 posts one when a manifold's cache goes). */
    ManifoldEvent169b1a0(u32 bodyByte7fA, u32 idA, u32 bodyByte7fB, u32 idB, u8 value18,
                         Status manifoldStatus, u32 shapeKeyA, u32 shapeKeyB)
    {
        sizePaddedTo16 = 0x30;
        unknown2 = 0;
        primaryType = 4;
        secondaryType = 0;
        byte7fA = bodyByte7fA;
        bodyIdA = idA;
        byte7fB = bodyByte7fB;
        bodyIdB = idB;
        unknown18 = value18;
        status = u8(manifoldStatus);
        keyA = shapeKeyA;
        keyB = shapeKeyB;
    }

    u32 byte7fA;
    u32 bodyIdA;
    u32 byte7fB;
    u32 bodyIdB;
    u8 unknown18;
    u8 status;
    u32 keyA;
    u32 keyB;
};

/* An event of two bodies (derived names; primary type 4, secondary type 2,
 * 0x40 bytes): each body as its byte at +0x7f and its id, as the manifold
 * events give them, then a zero word, the byte 2, a zero int and a vector
 * (the table's third, D_14b2060[2]). The modifier slot 0x161f10 posts one. */
struct BodyPairEvent00161f10 : public hkCommand /* derived name */
{
    /* The header filled in order, then the bodies' words and the rest. */
    BodyPairEvent00161f10(u32 bodyByte7fA, u32 idA, u32 bodyByte7fB, u32 idB)
    {
        sizePaddedTo16 = 0x40;
        unknown2 = 0;
        primaryType = 4;
        secondaryType = 2;
        byte7fA = bodyByte7fA;
        bodyIdA = idA;
        byte7fB = bodyByte7fB;
        bodyIdB = idB;
        unknown18 = 0;
        unknown20 = 2;
        unknown24 = 0;
        vector30 = D_14b2060[2];
    }

    u32 byte7fA;
    u32 bodyIdA;
    u32 byte7fB;
    u32 bodyIdB;
    u64 unknown18;
    u8 unknown20;
    u32 unknown24;
    Vec4 vector30;
};

/* A manifold's state as the modifier of vtable 0x169b190 tracks it (derived
 * names): 0 before the manifold is created, 1 once it is, 2 once it goes;
 * the creation also resets the 16-bit value at +0xe. */
struct ManifoldCache169b1a0 /* derived name */
{
    u8 unknown0[0xa];
    u8 state;
    u8 unknownB[3];
    u16 valueE;
};

/* A modifier of the world's default set (vtable 0x169b190, address point
 * 0x169b1a0, no type info; 16 bytes, slot 1 the shared 0x13e50; built at
 * 0x49e00 among the twenty): slot 2 (0x71520) and slot 3 (0x715d0) post an
 * event to the context's dispatcher when a manifold is created and when it
 * goes, once each. derived name. */
class Modifier169b1a0 /* derived name */
{
  public:
    virtual ~Modifier169b1a0();
    /* Slot 2 (0x71520). derived name. */
    virtual void FUN_00071520(CommandOwner00171180 *context, const void *sharedData,
                              const hknpCdBody *cdBodyA, const void *argument4,
                              const hknpCdBody *cdBodyB, const void *argument6,
                              ManifoldCache169b1a0 *cache);
    /* Slot 3 (0x715d0). derived name. */
    virtual void FUN_000715d0(CommandOwner00171180 *context, const void *sharedData,
                              ManifoldCache169b1a0 *cache, const void *argument4,
                              const void *argument5, const hknpCdBody *cdBodyA,
                              const hknpCdBody *cdBodyB);

    int unknown8;
};

void FUN_00171180(void *self, CommandOwner00171180 *owner, const u32 &bodyId); /* derived name */

/* The executors by primary type (derived name), eight references (the
 * constructor 0x90570 clears them; the simulation builds one on the stack
 * at 0x17008b and runs each command of a stream through it, 0x170396). */
class hkPrimaryCommandDispatcher /* derived name */
{
  public:
    void FUN_00090830(const hkCommand &command); /* derived name */

    /* The executor of a primary type set, its reference taken and the
     * previous one's released (0x90780; the world's constructor sets
     * three, 0x49771 to 0x497a7). derived name. */
    void FUN_00090780(u32 primaryType, hkSecondaryCommandDispatcher *dispatcher);

    hkSecondaryCommandDispatcher *dispatchers[8]; /* derived name */
};

/* hkDebugDisplay, the singleton registered by that name (the string at
 * 0x14cbaa4; record 0x57c88c8 filled by 0x183cd0, instance pointer
 * 0x57c88c0): 0x28 bytes from the thread's heap (0x183c69), vtable 0x16a64f0
 * (no type info; slots 0 and 1 its destructors 0x183810 and 0x1837c0).
 * FUN_001839d0 draws a line: start, end, colour, an id and a tag. derived
 * names but the class's. */
class hkDebugDisplay : public hkReferencedObject
{
  public:
    /* An empty array and a lock of 1000 spins (0x183c40). */
    hkDebugDisplay() : lock(new hkCriticalSection(1000)) {}

    /* The lock deleted, then the array (0x183810); the deleting destructor
     * is 0x1837c0. */
    virtual ~hkDebugDisplay();

    /* The class allocator: a block of the thread's heap (defined beside the
     * router). */
    static void *operator new(unsigned long numBytes);
    static void operator delete(void *object, unsigned long numBytes);

    void FUN_001839d0(const hkVector4 &start, const hkVector4 &end, int color, int id,
                      int tag); /* derived name */

    /* Pointer-sized elements, freed without destruction (0x1838ac). */
    hkArray<void *> handlers; /* derived name */
    hkCriticalSection *lock;  /* derived name; freed at 0x10 bytes (0x183888) */
};

/* Its create function, the record's (0x183c40). derived name. */
hkReferencedObject *FUN_00183c40(); /* derived name */

extern hkDebugDisplay *D_57c88c0; /* hkDebugDisplay's instance */

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
    virtual void print(const hkCommand &command, hkOstream &stream) const;
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

    /* Out of line (0x91590): sixteen entries from the containers'
     * allocator, every byte 0xff (a hash of -1 marks a free slot), none
     * used. */
    StringMap();

    /* Out of line (0x915e0): the entries go back to the allocator at
     * 0x57b8480 at (hashMod + 1) * 24 bytes; a holder's destructor runs it
     * as its member's. */
    ~StringMap();

    Entry *entries;
    int numEntries;
    int hashMod;
    /* Eight bytes the constructor leaves alone: both registries holding a
     * map place what follows it 0x18 bytes on (hkTypeInfoRegistry's flag at
     * +0x28 after its map at +0x10; hkDefaultClassNameRegistry's 0x30 bytes
     * end 0x18 after its map at +0x18). derived name. */
    u8 unknown10[8];

    void FUN_00091ac0();                      /* derived name */
    Iterator FUN_00091600() const;            /* derived name */
    Iterator FUN_00091650(Iterator it) const; /* derived name */
    /* The slot of a key, or one past the hash mask when the key is not in
     * the map (0x91840; called at 0x181f03). derived name. */
    Iterator FUN_00091840(const char *key) const;
    bool FUN_00013890(Iterator it) const;        /* derived name */
    const char *FUN_00091630(Iterator it) const; /* derived name */
    hkUlong FUN_00091640(Iterator it) const;     /* derived name */
    /* Sets the value of a key, adding the entry when it is new (0x91690). */
    void FUN_00091690(const char *key, hkUlong value);                 /* derived name */
    hkUlong FUN_00091900(const char *key, hkUlong defaultValue) const; /* derived name */
    /* A key's value through the out pointer: HK_FAILURE, the out left
     * alone, when the key is not in the map (0x919e0). derived name. */
    hkResult FUN_000919e0(const char *key, hkUlong *valueOut) const;
    /* Every key's string freed to the containers' allocator, then the map
     * emptied through 0x91ac0: the map owns copies of its keys (0x180bf0;
     * 0x19b0c6 calls it). derived name. */
    void FUN_00180bf0();
};

/* The map over values of a type (derived names): each value kept as the
 * pointer-sized word, read back through a word of the lookup's own and
 * converted. The word is a local of the inlined lookup, so the inliner marks
 * its lifetime; the packfile writer's section test (0x19d0d0) holds it at
 * -0x28 beside the guard, and the marked frame leaves the guard's address
 * read again at the check (3.3 StackColoring.cpp:709, :519-531: two markers
 * and 16 bytes of frame clear the memory operands MachineCSE needs to share
 * the GOT load). */
template <typename V>
struct StringMapOf : public StringMap /* derived name */
{
    hkResult get(const char *key, V *valueOut) const /* derived name */
    {
        hkUlong value;
        if (FUN_000919e0(key, &value) == HK_SUCCESS) {
            *valueOut = V(value);
            return HK_SUCCESS;
        }
        return HK_FAILURE;
    }

    void insert(const char *key, V value) /* derived name */
    {
        FUN_00091690(key, hkUlong(value));
    }
};

/* A map from pointers to pointer-sized values (derived name): 16-byte
 * entries (key, value; a key of -1 marks a free slot) at +0, the count at +8
 * and the hash mask at +0xc. FUN_00013b30 looks a key up (the hash
 * (key >> 4) * 0x9e3779b1) and returns its value or the default. */
/* hkContainerHeapAllocator, the allocator argument of the bit field's
 * hkArray in the scoped type names (0x14b7368): its allocator is
 * D_57b8480 (the bit field's resize 0x47b30 passes it), handed out by
 * reference, so the calls through it are virtual (0x915e0's `jmpq *%rcx`). */
struct hkContainerHeapAllocator {
    /* Defined in tlg_lib_unknown.h, after the allocator's class. */
    static AllocatorBase &get(); /* derived name */
};

/* The temporary allocator (derived name, after the heap allocator's): the
 * router's first static allocator, D_57b8470, which the string buffer's
 * array grows from (0x115f0 passes it). */
struct hkContainerTempAllocator /* derived name */ {
    /* Defined in tlg_lib_unknown.h, after the allocator's class. */
    static AllocatorBase &get(); /* derived name */
};

/* A map from 16-bit keys to pointer-sized values, hashed and probed as
 * PointerMap is (derived names): an empty entry's key is 0xffff. The lookup
 * and the insert are member templates over the value's type, as Havok's
 * typed maps keep theirs: the lookups of 0x1659e7, 0x176ebc and 0x177394
 * get the pointer itself back, with no integer cast for CodeGenPrepare to
 * sink into each block that uses it (0x1659c0's critical edge to its end
 * is split as the base holds it only when the value its phi takes is the
 * one the grow path passes on). Their files instantiate them for the bit
 * field map's blocks. */
struct U16PointerMap /* derived name */
{
    struct Pair {
        u16 key;
        hkUlong value;
    };

    /* derived name: the value of a key, or the default (0x199520). */
    template <typename V> V FUN_00199520(u16 key, V defaultValue) const;
    /* derived name: the value of a key set, the table rebuilt first when
     * more than half full (0x1992f0, as the pointer map's 0x138a0); nonzero
     * when the key was new. */
    template <typename V> int FUN_001992f0(AllocatorBase &allocator, u16 key, V value);
    /* derived name: the table rebuilt at a new capacity (0x199390). */
    void FUN_00199390(AllocatorBase &allocator, int newCapacity);

    Pair *entries;
    int numEntries;
    int hashMod;

    /* A slot as an iterator, as the pointer map's (derived names): the
     * first used slot, the next used one after a slot, one past the hash
     * mask at the end. The first slot's walk increments before its test
     * (its latch exits, so LoopRotate leaves it, cookbook 185); each key is
     * read into a named value. */
    struct IteratorTag;
    typedef IteratorTag *Iterator;

    Iterator getIterator() const
    {
        int i = 0;
        while (i <= hashMod) {
            const int index = i++;
            const u16 key = entries[index].key;
            if (key != 0xffff) {
                i = index;
                break;
            }
        }
        return reinterpret_cast<Iterator>(hkUlong(i));
    }

    Iterator getNext(Iterator it) const
    {
        int i = static_cast<int>(reinterpret_cast<hkUlong>(it));
        for (i += 1; i <= hashMod; i++) {
            const u16 key = entries[i].key;
            if (key != 0xffff) {
                break;
            }
        }
        return reinterpret_cast<Iterator>(hkUlong(i));
    }

    bool isValid(Iterator it) const
    {
        return static_cast<int>(reinterpret_cast<hkUlong>(it)) <= hashMod;
    }

    hkUlong getValue(Iterator it) const
    {
        return entries[static_cast<int>(reinterpret_cast<hkUlong>(it))].value;
    }
};

/* A map of bit fields (derived names): each value a block from the
 * thread's heap that records its own size first (0x199770 frees one at
 * that size, 0x199880 frees them all), the field after it; 0x199600 builds
 * one. */
struct BitFieldMap00199770 /* derived name */
{
    struct Block {
        int numBytes;
        int elementSize; /* derived name */
        hkBitField bits;
        /* One element per bit, set with it (0x1659c0). derived name. */
        void **elements;
    };

    /* One bit cleared in every field long enough to hold it (0x1997d0; the
     * callers at 0x1608ef and 0x16dc62). derived name. */
    void FUN_001997d0(int bitIndex);

    /* A bit set in the field of a key, its element stored beside it; the
     * field made, or remade as large as the map's size and the old one
     * given back, when it cannot hold the bit (0x1659c0; the world's body
     * setup at 0x17668b). derived name. */
    void FUN_001659c0(u32 bitIndex, u16 key, void *const &element);

    int numBits; /* derived name: the size a new field is made at */
    u8 unknown4[4];
    U16PointerMap fields;
};

/* A field of a map made from the thread's heap: its header, the bits for
 * numElements and the elements of elementSize bytes after them, cleared,
 * then what an old field holds copied in (0x199600). derived names. */
BitFieldMap00199770::Block *FUN_00199600(int elementSize, int numElements,
                                         const BitFieldMap00199770::Block *copyFrom);

struct PointerMap /* derived name */
{
    /* An entry: an empty one's key is -1. derived names. */
    struct Pair {
        hkUlong key;
        hkUlong value;
    };

    /* An empty map: no entries, none in use, the hash mask -1
     * (hkVtableClassRegistry's creation, 0x1845f5). */
    PointerMap() : entries(0), numEntries(0), hashMod(-1) {}

    /* The count's top bit: the map does not own its entries. derived
     * name. */
    enum { DONT_DEALLOCATE_FLAG = int(0x80000000) };

    /* Every entry marked empty and the count zeroed, the entries kept
     * (inline in 0x13db0). derived name. */
    void clear()
    {
        const int capacity = hashMod + 1;
        for (int i = 0; i < capacity; i++) {
            entries[i].key = hkUlong(-1);
        }
        numEntries &= DONT_DEALLOCATE_FLAG;
    }

    Pair *entries;
    int numEntries;
    int hashMod;

    struct IteratorTag;
    typedef IteratorTag *Iterator;

    /* The slot of a key, or one past the hash mask when it is absent
     * (0x13ad0). derived name. */
    Iterator FUN_00013ad0(hkUlong key) const; /* derived name */

    bool isValid(Iterator it) const
    {
        return static_cast<int>(reinterpret_cast<hkUlong>(it)) <= hashMod;
    }

    /* The value at a valid slot. derived name. */
    hkUlong getValue(Iterator it) const
    {
        return entries[static_cast<int>(reinterpret_cast<hkUlong>(it))].value;
    }

    hkUlong FUN_00013b30(hkUlong key, hkUlong defaultValue) const; /* derived name */
    /* A key's value into out, HK_FAILURE when the key is absent (0x13b90,
     * the lookup 0x13ad0 inline). derived name. */
    hkResult FUN_00013b90(hkUlong key, hkUlong &out) const;
    /* The entry at a slot removed (0x13c10). derived name. */
    void FUN_00013c10(Iterator it);
    /* A key's entry removed, HK_FAILURE when there is none (0x13d10, the
     * lookup 0x13ad0 inline). derived name. */
    hkResult FUN_00013d10(hkUlong key);
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

/* A pointer map that gives its entries back to the containers' heap when it
 * is destroyed, then runs the map's own destructor (Object0000b330's member
 * at +0x10; its destructor 0xb1a0 ends with the two calls). derived
 * name. */
struct OwnedPointerMap : public PointerMap /* derived name */
{
    ~OwnedPointerMap()
    {
        FUN_00013db0(hkContainerHeapAllocator::get());
        FUN_0000e5c0(this);
    }
};

/* hkPackfileWriter (derived name: the file of its strings is
 * hkPackfileWriter.cpp, 0x14cce52; vtable 0x16a6960, constructor
 * FUN_0019be50, destructor FUN_0019c150; slot 9 pure), the reference-counted
 * base of the binary packfile writer: an array at +0x10 and pointer maps at
 * +0x20, +0x30 and +0x40, a string map from +0x50. */
class hkVtableClassRegistry;

struct hkPackfileWriter : public hkReferencedObject /* derived name */
{
    /* The options it is built over (0x19bff0 to 0x19c050 read an int at +0,
     * +4, bytes at +8 and +9, pointers at +0x10 and +0x18 and an int at
     * +0x20). derived name. */
    struct Options;

    hkPackfileWriter(const Options &options); /* 0x19be50 */

    /* Out of line (0x19c150): the vtable restored, the arrays and maps
     * from +0x78 on freed. */
    virtual ~hkPackfileWriter();

    /* Slot 5 (0x19c3c0): the contents, their class, a vtable class
     * registry (the built-in one's when null) and a fourth argument handed
     * on to FUN_0019c480. derived names. */
    virtual void FUN_0019c3c0(const void *object, const hkClass &klass,
                              const hkVtableClassRegistry *registry, void *argument4);
    /* An object added with what it points to, in the section of a tag
     * (0x19c480; slot 5 adds the contents to "__data__"). derived names. */
    void FUN_0019c480(const void *object, const hkClass &klass,
                      const hkVtableClassRegistry *registry, void *argument4,
                      const char *sectionTag);
    /* Slot 6 (0x19cc20): slot 5 with the built-in type registry's vtable
     * class registry. derived name. */
    virtual void FUN_0019cc20(const void *object, const hkClass &klass, void *argument3);

    /* Slot 7 (0x19cc80): a pair added to the map at +0x30, the key's
     * index in the map at +0x20 replaced by -2 and its entry there marked
     * -2 too. derived name. */
    virtual void FUN_0019cc80(const void *key, const void *value);
    /* Slot 8 (0x19cd00): a pair added to the map at +0x40. derived name. */
    virtual void FUN_0019cd00(const void *key, const void *value);

    /* Slot 9, pure here: the save, over a stream writer and the save
     * options (the binary writer's 0x183350). derived name. */
    virtual void FUN_00183350(void *writer, const void *options) = 0;

    /* Slot 10 (0x19d0d0): a section added by its tag. derived name. */
    virtual void FUN_0019d0d0(const char *sectionTag);
    virtual void FUN_0019d190(); /* slot 11; derived name, arguments not read */
    /* Slot 12 (0x19d280): the objects of a class placed in the section of
     * a tag. derived name. */
    virtual void FUN_0019d280(const hkClass &klass, const char *sectionTag);

    /* An entry of the array at +0x10 (derived names): 40 bytes, an index
     * at +0x20 that slot 7 sets to -2. */
    struct Entry28 {
        u8 unknown0[0x20];
        int index20;
        u8 unknown24[4];
    };

    hkArray<Entry28> array10; /* derived name */
    PointerMap map20;         /* derived name */
    PointerMap map30;         /* derived name */
    PointerMap map40;         /* derived name */
    u8 unknown50[0x28];       /* derived name */
    /* The sections' tags, each a copy the writer owns, and each tag's
     * index among them (slot 10, 0x19d0d0). derived names. */
    hkArray<char *> sectionTags;
    StringMapOf<int> sectionTagToIndex;
    u8 unknownA0[0x10]; /* derived name */
    /* The contents' and their class's indices in the map at +0x20 (slot
     * 5, 0x19c3c0). derived names. */
    int contentsIndex;
    int contentsClassIndex;
    u8 unknownB8[0x80]; /* to the size its deleting destructor 0x19c100 frees */
};

/* Its out-of-line destructor body: restores the vtable, frees the arrays and
 * maps from +0x78 on. derived name. */
void FUN_0019c150(hkPackfileWriter *self); /* derived name */

/* The section tags (derived names): pointers to the strings "__classnames__"
 * (0x14cb9fc) and "__types__" (0x14cb791). */
extern const char *D_16dcb70;
extern const char *D_16dcbb8;
extern const char *D_16dcbb0; /* "__data__" (0x14ccdc2) */

/* The reflection's own classes (each built with its name, 0x11ec4 for
 * hkClassEnumItem's; the others are the classes of hkClass's members
 * parent, declaredEnums and declaredMembers, 0x3ada to 0x3b01). */
extern const hkClass D_57b77f0; /* hkClass's hkClass */
extern const hkClass D_57b7d18; /* hkClassMember's hkClass */
extern const hkClass D_57b93e0; /* hkClassEnum's hkClass */
extern const hkClass D_57b92c0; /* hkClassEnumItem's hkClass */

/* hkBinaryPackfileWriter (derived name; vtable 0x16a6470), the writer
 * hkSerializeUtil's savePackfile builds on its stack (0x17dc2a): it adds
 * nothing to destroy (its complete destructor FUN_00181bf0 runs the base's)
 * and its deleting destructor 0x181ba0 frees 0x140 bytes. */
struct hkBinaryPackfileWriter : hkPackfileWriter /* derived name */
{
    /* 0x181b10: the class names' section, and the reflection's own
     * classes in the types' section. */
    hkBinaryPackfileWriter(const Options &options);

    virtual ~hkBinaryPackfileWriter(); /* 0x181bf0 */

    virtual void FUN_00183350(void *writer, const void *options); /* slot 9 */

    u8 unknown138[0x8];
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

    /* A type's registration, built by its file's static initializer
     * (hkBaseObject's at 0x6a60: the fields stored in order). */
    hkTypeInfo(const char *typeName_, const char *scopedName_, FinishLoadedObjectFunction finish,
               CleanupLoadedObjectFunction cleanup, const void *vtable_, hkUlong size_)
        : typeName(typeName_), scopedName(scopedName_), finishFunction(finish),
          cleanupFunction(cleanup), vtable(vtable_), size(size_)
    {
    }

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
    /* Inline in its creator (0x184e80): the map empty, both flags set. */
    hkTypeInfoRegistry() : finishFlag(1), unknown2c(1) {}

    virtual ~hkTypeInfoRegistry();

    /* The class allocator inline, as hkHardwareInfo's (0x184ea5). */
    static void *operator new(unsigned long numBytes);

    /* The reference-counted class delete (tlg_lib_unknown.h): its deleting
     * destructor 0x17d850 frees at the recorded size, 0x30 by default. */
    static void operator delete(void *object, unsigned long numBytes);

    virtual void FUN_0017d8b0(const hkTypeInfo *info); /* vtable slot 5; derived name */
    /* Slot 6: finishes a loaded object of a named type with the flag at
     * +0x28 and returns the type info, or null when no type of that name
     * is registered. */
    const hkTypeInfo *FUN_0017d8d0(void *object, const char *typeName) const; /* derived name */
    /* Slot 7: cleans up a loaded object of a named type and returns the
     * type info, or null when no type of that name is registered. */
    const hkTypeInfo *FUN_0017d920(void *object, const char *typeName) const; /* derived name */
    /* Slot 8: every type info of another registry registered here too.
     * derived name. */
    void FUN_0017d7a0(const hkTypeInfoRegistry *other);
    const hkTypeInfo *FUN_0017d960(const char *typeName) const; /* vtable slot 9; derived name */

    StringMap map;  /* derived name */
    int finishFlag; /* derived name; 1 on creation (0x184ed3) */
    int unknown2c;  /* 1 on creation */
};

/* hkDefaultClassNameRegistry (vtable address point 0x16a6180) over the
 * dynamic class name registry (derived name, vtable address point 0x16a6200,
 * which the constructor 0x184f40 stores first): a name at +0x10 (the string
 * 0x14b3b02) and the classes by name at +0x18. Slot 6 of both vtables
 * (FUN_0017ec90) looks a class up. */
class hkDynamicClassNameRegistry : public hkReferencedObject /* derived name */
{
  public:
    /* Inline in the creators (0x184f40, 0x17e9a0): the name stored, the map
     * built out of line. */
    hkDynamicClassNameRegistry(const char *registryName) : name(registryName) {}

    virtual ~hkDynamicClassNameRegistry();

    /* The class allocator inline, as hkTypeInfoRegistry's (0x184f65). */
    static void *operator new(unsigned long numBytes);

    /* The reference-counted class delete (tlg_lib_unknown.h): its deleting
     * destructor 0x17ec30 (hkDefaultClassNameRegistry's slot 1 too) frees at the recorded size, 0x30 by default. */
    static void operator delete(void *object, unsigned long numBytes);

    virtual void unknownVirtual5(); /* the folded 0x7f80: the name at +0x10 */
    virtual const hkClass *
    FUN_0017ec90(const char *className) const; /* vtable slot 6; derived name */
    /* Slot 7 (0x17eca0): every class the registry holds appended. derived
     * name. */
    virtual void FUN_0017eca0(hkArray<const hkClass *> &classesOut) const;
    virtual void unknownVirtual8(); /* FUN_0017ed60: sets the name */
    /* Slot 9 (0x17ed70): registers a class under a name, the class's own
     * when none is given. derived name. */
    virtual void FUN_0017ed70(const hkClass *klass, const char *className);
    /* Slot 10 (0x17edb0): registers each class of a null-terminated list
     * under its own name, through slot 9. derived name. */
    virtual void FUN_0017edb0(const hkClass *const *classes);
    /* Slot 11 (0x17edf0): registers every class of a map of names to
     * classes under its own name, through slot 9. derived name. */
    virtual void FUN_0017edf0(const StringMap &classes);
    /* Slot 12 (0x17ee60): every class of another registry registered under
     * its own name, through slot 9. derived name. */
    virtual void FUN_0017ee60(const hkDynamicClassNameRegistry &other);

    const char *name; /* derived name */
    StringMap map;    /* derived name */
};

class hkDefaultClassNameRegistry : public hkDynamicClassNameRegistry
{
  public:
    /* Named for the Havok version (the string 0x14b3b02 at +0x10). */
    hkDefaultClassNameRegistry() : hkDynamicClassNameRegistry("hk_2014.2.0-r1") {}

    virtual ~hkDefaultClassNameRegistry();
};

/* The classes of a null-terminated list finished for a class version
 * (0x19aff0, out of line). derived name. */
void FUN_0019aff0(const hkClass *const *classes, int classVersion); /* derived name */

/* derived names: a class brought up to a class version (0x19eee0, the done
 * map keeping each class it has seen), and each class of a null-terminated
 * list brought up through one map (0x19f270, the first step of 0x19aff0). */
void FUN_0019eee0(const hkClass *klass, PointerMap &done, int classVersion);
void FUN_0019f270(const hkClass *const *classes, int classVersion);

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

    /* The list's classes finished once, before the first lookup (inline in
     * slots 6 and 7). derived name. */
    void checkIfReady() const
    {
        if (!ready) {
            FUN_0019aff0(classes, classVersion);
            ready = 1;
        }
    }

    /* Slot 6 (0x181940): the listed class of a name, null when none is.
     * derived name. */
    const hkClass *FUN_00181940(const char *className) const;

    const char *name;              /* derived name */
    const hkClass *const *classes; /* derived name */
    int classVersion;              /* derived name */
    /* Set by the lookups, which are const. derived name. */
    mutable int ready;
};

/* hkVtableClassRegistry, 0x20 bytes, vtable address point 0x16a6580: the
 * classes by vtable at +0x10 (an empty map on creation: no entries, count 0,
 * hash mask -1). Slot 6 (FUN_00184410) looks a vtable's class up. */
class hkVtableClassRegistry : public hkReferencedObject
{
  public:
    hkVtableClassRegistry() {}

    /* The class allocator, inline: the thread's heap (0x1845c7). */
    static void *operator new(unsigned long numBytes);

    /* Slot 0 (0x184360): the map's entries given back to the container
     * allocator, then the map's destructor; the deleting destructor
     * (0x1843a0, slot 1) runs it and frees through the class's delete. */
    virtual ~hkVtableClassRegistry();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    virtual void FUN_00184520(const void *vtable,
                              const hkClass *klass);               /* vtable slot 5; derived name */
    virtual const hkClass *FUN_00184410(const void *vtable) const; /* vtable slot 6; derived name */
    /* Slot 7: the singleton's callers reach it through the vtable
     * (0x902f0's `jmpq *%rax` after the slot load at +0x38). */
    virtual const hkClass *FUN_00184420(const void *object) const; /* vtable slot 7; derived name */

    /* Registers the vtable of each type info under the class beside it in
     * a second list, both lists ending at a null (0x184540; the builtin
     * registry passes its type infos 0x16c82b0 and classes 0x16c9060 at
     * 0x17ec05 and 0x17f067). derived name. */
    void FUN_00184540(const hkTypeInfo *const *infos, const hkClass *const *classes);

    PointerMap map; /* derived name */
};

extern hkTypeInfoRegistry *D_57c8938;         /* hkTypeInfoRegistry's instance */
extern hkDefaultClassNameRegistry *D_57c8960; /* hkDefaultClassNameRegistry's instance */
extern hkVtableClassRegistry *D_57c8910;      /* hkVtableClassRegistry's instance */
/* The create function of hkVtableClassRegistry's singleton record
 * (0x1845b0): a new, empty registry. derived name. */
hkReferencedObject *FUN_001845b0(); /* derived name */

/* hkBuiltinTypeRegistry's instance (vtable address point 0x16a6120, 0x10
 * bytes, created by 0x17ef90 once the three registries above exist): slots
 * 5 to 7 (FUN_0017e970 to FUN_0017e990) return the three registries, slot 8
 * (0x17ef10) adds a type, slot 9 (0x17e9a0) rebuilds the registries. */
class hkBuiltinTypeRegistry : public hkReferencedObject
{
  public:
    virtual ~hkBuiltinTypeRegistry();

    virtual hkTypeInfoRegistry *FUN_0017e970();         /* vtable slot 5; derived name */
    virtual hkDefaultClassNameRegistry *FUN_0017e980(); /* vtable slot 6; derived name */
    virtual hkVtableClassRegistry *FUN_0017e990();      /* vtable slot 7; derived name */
    /* Slot 8 (0x17ef10): a type added to the three registries, its class
     * by its name, its type info, and its vtable when the class has one
     * (an interface counted over it and its parents). derived name. */
    virtual void FUN_0017ef10(const hkTypeInfo *info, const hkClass *klass);
};

extern hkBuiltinTypeRegistry *D_57c8898; /* hkBuiltinTypeRegistry's instance */

/* Its create function, the record's (0x17ef90): the registry once the
 * three registries it hands out exist. derived name. */
hkReferencedObject *FUN_0017ef90(); /* derived name */

/* The builtin classes, a null-terminated list (derived name). */
extern const hkClass *const D_16c9060[];

/* The registry over them (0x57c8870), built by the builtin registry's
 * file's static initializer 0x17f080 (derived name). */
extern hkStaticClassNameRegistry D_57c8870;

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
    /* The second signal's handler (0x155b10): both handlers unsubscribed,
     * the shape dropped, the owner marked changed. derived name. */
    void FUN_00155b10(); /* derived name */

    ShapeWatcherOwner *owner; /* derived name */
    const hknpShape *shape;   /* derived name */
    u8 unknown10[0x10];
    u8 changeFlags; /* derived name */
};

/* The nodes the XML reader at 0x19da90 returns are hkXmlParser::Node's
 * (derived names: no string names the reader or its nodes). The reader
 * allocates an end element (vtable 0x16a6a20, kind 2, 0x18 bytes, its name
 * at +0x10, built at 0x19e1eb from the text after "</"), character data
 * (vtable 0x16a6a60, kind 3, 0x18 bytes, its text at +0x10, built at
 * 0x19e08c and 0x19e28b) and a start element (vtable 0x16a69e0, kind 1,
 * built at 0x19e52b). */
/* A start element's attribute (derived names): its name and its value,
 * 16 bytes, destroyed value first (0x19d490); the reader fills one on its
 * stack (0x19e353) and copies it into the array. */
struct XmlAttribute /* derived name */
{
    hkStringPtr name;  /* derived name */
    hkStringPtr value; /* derived name */
};

/* The start element (vtable 0x16a69e0), 0x28 bytes: built in place by the
 * reader at 0x19e52b, node type 1. */
class XmlStartElement : public hkXmlParser::Node /* derived name */
{
  public:
    XmlStartElement(const char *name) : Node(1), name(name) {}

    /* Slot 0 (0x19d450): the attributes destroyed from the last and their
     * storage given back, then the name. Inline, with the keyword: the
     * class has no other virtual of its own, so its vtable and destructors
     * are emitted where it is built (the reader, func_0019da90.cpp), the D1
     * before the D0 as the base holds them, and the deleting destructor
     * (0x19d500, slot 1) holds this body, which the inliner admits only
     * with the hint (cookbook 164). */
    inline virtual ~XmlStartElement() {}

    /* The reference-counted class delete (tlg_lib_unknown.h): its deleting
     * destructor 0x19d500 frees at the recorded size, 0x28 by default. */
    static void operator delete(void *object, unsigned long numBytes);

    hkStringPtr name;                 /* derived name */
    hkArray<XmlAttribute> attributes; /* derived name */
};

class XmlEndElement : public hkXmlParser::Node /* derived name */
{
  public:
    XmlEndElement(const char *name) : Node(2), name(name) {}

    virtual ~XmlEndElement();

    /* The reference-counted class delete (tlg_lib_unknown.h): its deleting
     * destructor 0x19d600 frees at the recorded size, 0x18 by default. */
    static void operator delete(void *object, unsigned long numBytes);

    hkStringPtr name; /* derived name */
};

class XmlCharacters : public hkXmlParser::Node /* derived name */
{
  public:
    XmlCharacters(const char *text) : Node(3), text(text) {}

    /* The text of a length (0x19e0a7, FUN_0000e540 the string's
     * constructor of a length). */
    XmlCharacters(const char *text, int length) : Node(3), text(text, length) {}

    virtual ~XmlCharacters();

    /* The reference-counted class delete (tlg_lib_unknown.h): its deleting
     * destructor 0x19d680 frees at the recorded size, 0x18 by default. */
    static void operator delete(void *object, unsigned long numBytes);

    hkStringPtr text; /* derived name */
};

/* hkPackfileSectionHeader, a reflected struct (member records 0x16a2dd0 to
 * 0x16a2f38): 0x40 bytes in this file version, the pad at +0x30 the last
 * member; the versions before 11 lay their section headers out without it,
 * 0x30 bytes apart. */
struct hkPackfileSectionHeader {
    char sectionTag[19];
    char nullByte;
    s32 absoluteDataStart;
    s32 localFixupsOffset;
    s32 globalFixupsOffset;
    s32 virtualFixupsOffset;
    s32 exportsOffset;
    s32 importsOffset;
    s32 endOffset;
    s32 pad[4];
};

/* hkPackfileHeader, a reflected struct (member records 0x16a2bc0 to
 * 0x16a2da0), 0x40 bytes; the section headers follow it, after the
 * predicate array in file versions 10 and 11. */
struct hkPackfileHeader {
    /* 0x180ea0 (called at 0x17e488 and 0x17e889 with the header as both
     * arguments): the header of section i of the packfile whose header
     * packfileData points to, null when it has no sections. derived name. */
    const hkPackfileSectionHeader *getSectionHeader(const void *packfileData,
                                                    int i) const; /* derived name */

    s32 magic[2];
    s32 userTag;
    s32 fileVersion;
    u8 layoutRules[4];
    s32 numSections;
    s32 contentsSectionIndex;
    s32 contentsSectionOffset;
    s32 contentsClassNameSectionIndex;
    s32 contentsClassNameSectionOffset;
    char contentsVersion[16];
    s32 flags;
    u16 maxpredicate;
    u16 predicateArraySizePlusPadding;
};

/* The world's space splitter (derived names after the timer
 * "TtUpdateSpaceSplitter", 0x14c9b0a; the pointer at +0x1d8 of the world):
 * its kind at +0x18 picks the cell lookup (0xcd4f6: 0 one cell, 1
 * FUN_00061060, 2 the grid's FUN_00060c10). The grid's fields from that
 * lookup: two axes at +0x60 and +0x70 with their offsets at +0x40 and
 * +0x50, the cells in a row at +0x80 and the index mask at +0x84. */
/* The space splitters' base (derived name; vtable 0x16994b0, D14): 0x28
 * bytes; its constructor 0x605b0 stores the kind. The derived splitters'
 * vtables 0x16994e0 and 0x1699510 keep its destructors. */
class hknpSpaceSplitter : public hkBaseObject /* derived name */
{
  public:
    /* Out of line (0x605b0): the vtable, an empty array and the kind; it
     * also fills the 17 by 17 byte table at 0x57c1660. */
    hknpSpaceSplitter(int type);

    /* Out of line (0x604d0, slot 0): the array given back; the deleting
     * destructor (0x60530, slot 1) frees the 0x28 bytes. */
    virtual ~hknpSpaceSplitter();

    static void operator delete(void *object, unsigned long numBytes);

    /* Slot 3, pure: the splitter moved by an offset; named after the
     * grid's overrider (0x61280, which adds it to the vectors at +0x70).
     * derived name. */
    virtual void FUN_00061280(const Vec4 &offset) = 0;

    /* The pairs of numCells cells built into cellPairs (0x60a10, through
     * a temporary array and FUN_000606d0). derived name. */
    void FUN_00060a10(int numCells);

    /* The pairs of cells, one 2-byte entry each, the first cell in the
     * high byte (FUN_00060a10 fills them for the cells it is given).
     * derived name. */
    hkArray<u16> cellPairs;
    int type;         /* derived name */
    int numCells;     /* derived name */
    int numCellPairs; /* derived name: numCells * (numCells + 1) / 2 */
    int unknown24;
};

/* The single-cell splitter (derived name after its constructor; vtable
 * 0x16994e0, D14): kind 0, one cell and its one pair. The world builds it
 * (0x49933, in 0x28 bytes) unless its cinfo's byte at +0x50 is 1. Slot 3
 * is the shared empty body 0x3b640. */
class SpaceSplitter00060b90 : public hknpSpaceSplitter /* derived name */
{
  public:
    SpaceSplitter00060b90();

    virtual void FUN_00061280(const Vec4 &offset);
};

/* A 32-byte record the splitter's count walks (derived names): count
 * entries of stride bytes from data, each with a word at +0xc. */
struct SplitterRecord0018e380 /* derived name */
{
    int stride;
    u8 unknown4[0xc];
    int count;
    u8 unknown14[4];
    const u8 *data;
};

struct hknpGridSpaceSplitter /* derived name */
{
    /* The cell of a position: its offset coordinate on each axis truncated
     * and masked, rows of numCellsPerRow (0x60c10; called at 0xcd518,
     * 0x148d40 and 0x1572ed). derived name. */
    void FUN_00060c10(const Vec4 &position, int *cellOut) const;

    /* The number of the records' entries whose word at +0xc is set, over
     * every record, plus the count at +0x1c (0x18e380; the solver's setup
     * asks it of the world's splitter over three records at 0x14e678).
     * derived name. */
    int FUN_0018e380(const struct SplitterRecord0018e380 *records, int numRecords) const;

    u8 unknown0[0x18];
    int type; /* derived name */
    int unknown1c;
    u8 unknown20[0x20];
    Vec4 offsetX;       /* derived name */
    Vec4 offsetY;       /* derived name */
    Vec4 axisX;         /* derived name */
    Vec4 axisY;         /* derived name */
    int numCellsPerRow; /* derived name */
    int cellMask;       /* derived name */
};

/* derived name: the union of count boxes (FUN_00185460). */
void FUN_00185460(hkAabb16 *aabbOut, const hkAabb16 *aabbs, int count);

/* What receives the keys a tree query finds, a batch at a time (derived
 * names): slot 2 takes the keys and their count. */
class TreeKeyCollector001876e0 /* derived name */
{
  public:
    virtual ~TreeKeyCollector001876e0();

    virtual void addKeys(const u32 *keys, int numKeys) = 0; /* vtable slot 2; derived name */
};

/* The keys of a query batched on the stack, 64 at a time, for a collector
 * (derived names): flushed to it when the batch is full and once at the
 * end. */
struct TreeKeyBatch001876e0 /* derived name */
{
    void flush()
    {
        if (numKeys > 0) {
            collector->addKeys(keys, numKeys);
            numKeys = 0;
        }
    }

    u32 keys[64];
    int numKeys;
    TreeKeyCollector001876e0 *collector;
};

/* derived names: the tree query proper (0x1856f0, 0x1afc bytes: the box's
 * overlaps walked into the batch), and its entry point 0x1876e0, which
 * batches the keys for a collector (called at 0x10dd88 with a fifth
 * argument, 1, it does not read). */
void FUN_001856f0(const void *tree, const void *argument2, TreeKeyBatch001876e0 *batch,
                  const hkAabb &aabb); /* derived name */
void FUN_001876e0(const void *tree, const void *argument2, TreeKeyCollector001876e0 *collector,
                  const hkAabb &aabb, int argument5); /* derived name */

/* Three arrays the solver's setup describes for its tasks (derived names;
 * the object at +0x10 of the step's context, 0x6dba1): elements of 0x40
 * bytes at +0x10 and +0x20, of 0x30 bytes at +0x30. */
struct SolverArrays0003f820 /* derived name */
{
    struct Element40 {
        u8 unknown0[0x40];
    };

    struct Element30 {
        u8 unknown0[0x30];
    };

    /* What 0x3f820 writes of one array (derived names): its element size,
     * its count and its data. */
    struct ArrayInfo {
        int elementSize;
        u8 unknown4[0xc];
        int numElements;
        u8 unknown14[4];
        void *data;
    };

    /* The access mode in the low two bits and an id at +4 (derived
     * names). */
    struct Access {
        u32 mode : 2;
        u32 unknownBits : 30;
        u8 id;
        u8 unknown5[3];
    };

    /* The three arrays described, the last first, each with its access
     * (0x3f820; the solver's setup calls it at 0x6dbb9 and 0x16e559).
     * derived name. */
    void FUN_0003f820(ArrayInfo *infosOut, Access *accessOut) const;

    u8 unknown0[0x10];
    hkArray<Element40> arrayA; /* derived name */
    hkArray<Element40> arrayB; /* derived name */
    hkArray<Element30> arrayC; /* derived name */
};

/* derived name: the box around the boxes' centres (FUN_001854b0; called at
 * 0x13e807, which then clears the result's key). */
void FUN_001854b0(hkAabb16 *aabbOut, const hkAabb16 *aabbs, int count);

#endif
