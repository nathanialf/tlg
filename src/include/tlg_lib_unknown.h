/* Library-region objects of unknown class, each reached by two matched
 * accessors of one field, the pair shown by a caller that uses both on the
 * same object. derived names throughout. */
#ifndef TLG_LIB_UNKNOWN_H
#define TLG_LIB_UNKNOWN_H

#include "tlg_hk_reflect.h"
#include "tlg_simd.h"
#include "tlg_types.h"

/* FUN_00180f50 reads +0x10 through FUN_00004580 and, when it differs from
 * the value it computed, writes it through FUN_00004590. */
struct Value10Owner {
    u8 unknown0[0x10];
    s32 value;
};

/* FUN_0000b660 and FUN_0000b670 sit in adjacent vtable slots (0x168d600,
 * 0x168d608): a setter and a getter of the int at +0x40. FUN_00061f40
 * compares the value against 1. */
struct Mode40Owner {
    u8 unknown0[0x40];
    s32 mode;
};

/* FUN_0003d7d0 reads +8 through FUN_00010650 and +0xc through FUN_00034840
 * on the same object (its own +0x18) and sign-extends the first.
 * FUN_00161cc0 reads the byte at +2 (FUN_000348c0), +8, +0xc and the byte
 * at +5 (FUN_00034890) of one object. The functions at 0x2b010 to 0x2b120
 * walk `count` 32-byte entries from +0x40 (floats at +0xc and +0x1c of
 * each); FUN_0002b0b0 sets the byte at +5 to 3, FUN_00072dc0 then clears
 * the pointer at +0x38 through FUN_00034950, and FUN_0002b180 adds into the
 * object it points to. The forwarders at 0x34810 to 0x34970 call the
 * 0x2b0xx functions from another file. */
struct Pair08Target; /* a u16 at +0x20 and a 16-byte sum at +0x40 */

struct Pair08Owner {
    u8 unknown0[2];
    u8 count;
    u8 unknown3[2];
    u8 state;
    u8 unknown6[2];
    s32 first;
    s32 second;
    u8 unknown10[0x28];
    Pair08Target *target;
};

float *FUN_0002b010(Pair08Owner *self, int index);                /* derived name */
float *FUN_0002b030(Pair08Owner *self, int index);                /* derived name */
void FUN_0002b040(Pair08Owner *self, float scaleA, float scaleB); /* derived name */
void FUN_0002b0b0(Pair08Owner *self);                             /* derived name */
void FUN_0002b0c0(Pair08Owner *self, int mode, float value);      /* derived name */
void FUN_0002b0f0(Pair08Owner *self, float scale);                /* derived name */
void FUN_0002b120(Pair08Owner *self, float scale);                /* derived name */
void FUN_0002b390(Pair08Owner *self,
                  bool enable); /* derived name: sets or clears bit 2 of the byte at +1 */

/* FUN_000ae6a0 and FUN_000ae810 sit in slots 5 and 9 of one vtable
 * (0x16a3b00): getters of the ints at +0x38 and +0x48. FUN_000ae6a0 also
 * fills a slot of the vtables at 0x16a6330 and 0x16b1500, so +0x38 belongs
 * to a class those share. */
struct Values38Owner {
    u8 unknown0[0x38];
    s32 value38;
    u8 unknown3c[0xc];
    s32 value48;
};

/* The two polymorphic bases of the allocators below: the primary, whose slot
 * 12 (the shared FUN_00001620) returns the object as its second base, and a
 * second interface of eleven slots at +8. The interface's slots 2 to 10 are
 * overridden by every allocator met so far, so its vtable in each holds the
 * this-adjusting thunks of the overriders (or their folded bodies). Slot 8
 * returns a byte count (TwoBaseAllocator: FUN_000022d0, thunk FUN_00002300;
 * LargeBlockAllocator: FUN_00012e20, thunk FUN_00012e30). */
class AllocatorBase /* derived name */
{
  public:
    virtual ~AllocatorBase();

    /* Slots 2 and 3 allocate and free a block of a given size; slots 4 and
     * 5 (FUN_00008d70, FUN_00008d80) are defaults the allocators keep that
     * forward to them (the layout of Havok's hkMemoryAllocator). */
    virtual void *blockAlloc(int numBytes) = 0;              /* slot 2; derived name */
    virtual void blockFree(void *pointer, int numBytes) = 0; /* slot 3; derived name */
    virtual void *FUN_00008d70(int &numBytes);               /* slot 4; derived name */
    virtual void FUN_00008d80(void *pointer, int numBytes);  /* slot 5; derived name */
};

class AllocatorInterface /* derived name */
{
  public:
    virtual ~AllocatorInterface();

    virtual void *FUN_00003580() const = 0; /* slot 5; derived name */
    virtual u64 allocatedBytes() const = 0; /* slot 8; derived name */
};

/* An allocator (vtable address points 0x168c640 and, for the second base,
 * 0x168c708), both stored by its constructor FUN_00001960. Its complete
 * destructor is FUN_00001fb0, its deleting destructor (slot 1) FUN_00001f90;
 * slot 12 (FUN_00001620) returns the object as its second base. Slot 15
 * (0x34a0, also reached through the second base by the thunk 0x3570) stores
 * a pointer at +0xb50 under the spinning mutex at +0x10; slot 16
 * (FUN_00003580) reads it. Primary slots 13 to 21 override the interface's
 * slots 2 to 10 in order; the second base's vtable holds their
 * this-adjusting thunks (0x32d0, 0x3490, 0x3570, 0x3590, 0x2280, 0x3130,
 * 0x2300, 0x2400, 0x3700). */
class TwoBaseAllocator : public AllocatorBase, public AllocatorInterface
{
  public:
    virtual ~TwoBaseAllocator();
    virtual AllocatorInterface *FUN_00001620();

    virtual void *FUN_00003580() const; /* vtable slot 16; derived name */

    u8 unknown10[0xb40];
    void *pointerB50; /* derived name */
};

/* An allocator of blocks with a 0x20-byte header (vtable address points
 * 0x168e2a0 and, for the second base, 0x168e360), both stored by its
 * constructor FUN_00012160. The allocation paths add a block's size to the
 * total at +0x1a0 and its size less the header to the total at +0x1a8, the
 * free (slot 3, 0x133e0) subtracts both. Primary slots 13 to 18 override the
 * interface's slots 2 to 7, slot 19 its slot 10, slot 20 (FUN_00012e20) its
 * slot 8 and slot 21 its slot 9. */
/* Each block of LargeBlockAllocator sits after a 0x20-byte chunk header
 * whose second word holds the chunk's size, with flags in its low two bits
 * (derived names). */
struct LargeBlockChunk /* derived name */
{
    u64 prevFoot;          /* derived name */
    u64 head;              /* derived name */
    LargeBlockChunk *next; /* derived name */
    LargeBlockChunk *prev; /* derived name */
};

class LargeBlockAllocator : public AllocatorBase, public AllocatorInterface /* derived name */
{
  public:
    virtual ~LargeBlockAllocator();

    /* Slot 10 (Havok's getAllocatedSize): the usable size of a block, its
     * chunk's size less the header. */
    int FUN_00013500(const void *pointer, int numBytes) const; /* derived name */

    virtual u64 allocatedBytes() const; /* vtable slot 20, FUN_00012e20; derived name */

    u8 unknown10[0x190];
    u64 totalBlockBytes;   /* derived name */
    u64 totalPayloadBytes; /* derived name */
};

void FUN_00001fb0(TwoBaseAllocator *self); /* derived name */

/* Primary slots 13, 14, 15, 18 and 21 (interface slots 2, 3, 4, 7 and 10),
 * each run under the spinning mutex at +0x10; reached through the second
 * base by the thunks 0x32d0, 0x3490, 0x3570, 0x3130 and 0x3700. Slot 15
 * stores its pointer at +0xb50 and returns 0. */
void FUN_00003140(TwoBaseAllocator *self);                          /* derived name */
void FUN_000032e0(TwoBaseAllocator *self, int value);               /* derived name */
int FUN_000034a0(TwoBaseAllocator *self, void *pointer);            /* derived name */
int FUN_00002f10(TwoBaseAllocator *self, void *a, void *b);         /* derived name */
int FUN_000035a0(TwoBaseAllocator *self, void *pointer, int value); /* derived name */

/* LargeBlockAllocator's primary slots 13 and 19 (interface slots 2 and 10),
 * reached through the second base by the thunks 0x133d0 and 0x13190. */
void FUN_000131a0(LargeBlockAllocator *self);                          /* derived name */
int FUN_00013060(LargeBlockAllocator *self, void *pointer, int value); /* derived name */

/* A reference-counted allocator of 4096-byte pages (vtable address point
 * 0x168e8f0; constructor FUN_000195c0: a lock at +0x10, an array of every
 * page at +0x20, an array of free pages at +0x30, the peak of the bytes in
 * use at +0x40; FUN_00019640 allocates the pages, 128-byte aligned, and adds
 * each to both arrays). Slot 5 (0x198a0) hands out pages, growing by at
 * least slot 9's amount, and updates the peak from slot 7; slot 6 (0x199f0)
 * takes them back; slot 8 (0xb670) returns the peak. */
class PageAllocator : public hkReferencedObject /* derived name */
{
  public:
    enum { PAGE_SIZE = 4096 }; /* derived name */

    int FUN_00019b30() const; /* vtable slot 7; derived name */
    int FUN_00019b50() const; /* vtable slot 9; derived name */

    u8 unknownC[0x14];
    hkArray<void *> pages;     /* derived name */
    hkArray<void *> freePages; /* derived name */
};

/* A global state word (derived name) and its setter FUN_00006640: the
 * allocation paths at 0x2958 and 0x2bde (TwoBaseAllocator's: the byte count
 * of the object at +0x38, less the base at +0x20, against the value at
 * +0xb50) set it to 1 when the limit is reached. */
extern int D_57b7b18;
void FUN_00006640(int state); /* derived name */

/* The base system's initialised flag (derived name): the initialiser at
 * 0x98d0 returns at once when it is set and sets it at the end, the
 * shutdown at 0x9ad0 does nothing unless it is set and clears it, and
 * FUN_00009c10 returns it (tested by 0x9353a before a teardown walk). */
extern bool D_57b80c0;
bool FUN_00009c10(); /* derived name */

/* Primary slot 20 (interface slot 9): stores its int argument into the
 * global at 0x16dc128 under the spinning mutex at +0x10. */
void FUN_00002330(TwoBaseAllocator *self, int value); /* derived name */

/* An arena that hands out blocks with a 16-byte header before the payload
 * (owner, size): FUN_0000bc30 allocates through the third virtual method,
 * FUN_0000bc60 reads the size back, FUN_0000bc70 finds the header. */
struct ArenaVtable {
    void *slot0;
    void *slot1;
    void *(*allocate)(void *self, int size);
};

struct Arena {
    ArenaVtable *vtable;
};

struct ArenaBlockHeader {
    Arena *owner;
    s32 size;
    s32 unknown;
};

/* The memory system with vtable 0x168d690, whose slot 4 (FUN_0000c590)
 * loads the path of hkFreeListMemorySystem.cpp (config/homes.base.txt). Its
 * constructor FUN_0000c270 stores its second, third and fourth arguments at
 * +8, +0x18 and +0x20; the object at +0x20 is called through its fifth and
 * sixth virtual slots (FUN_0000d230, FUN_0000d250). Complete destructor
 * FUN_0000c360, deleting destructor FUN_0000c350. */
struct MemorySystemAllocator;

struct MemorySystem {
    u8 unknown0[0x18];
    MemorySystemAllocator *allocator18;
};

void FUN_0000c360(MemorySystem *self); /* derived name */

/* A polymorphic class with an empty virtual destructor and the global
 * operator delete: its deleting destructor FUN_00021a00 (beside hkcdSimdTree's
 * code) is one shared body in slot 1 of 175 vtables, whose slot 0 is an
 * empty complete destructor (FUN_0003b640, FUN_000add50, FUN_001af750, ...). */
class PlainPolymorphic
{
  public:
    virtual ~PlainPolymorphic();
};

/* A reference-counted object, 0x50 bytes (vtable 0x16969d0, constructor
 * FUN_0003e840: takes a counted reference to the object at +0x10, stores the
 * int argument at +0x18 and +0x1c, clears the int at +0xc and the vector at
 * +0x30). The game code at 0xeaa625 sets +0xc to 1 through FUN_0003ea60;
 * FUN_0003ea80 returns the address of the vector. */
struct Object0003ea60 {
    u8 unknown0[0xc];
    s32 value;
    u8 unknown10[0x20];
    Vec4 vector; /* +0x30 */
};
/* A reference-counted object (vtable 0x1698f40, constructor FUN_00092280)
 * holding four arrays (16-, 4- and 8-byte elements at +0x10, +0x20, +0x30)
 * and an array of counted references at +0x40. Its out-of-line destructor
 * FUN_00048040 restores the vtable, releases the references and frees the
 * arrays. */
struct RefArrays00048040; /* derived name */

void FUN_00048040(RefArrays00048040 *self); /* derived name */
/* A reference-counted object, 0x70 bytes (vtable 0x169ab20, constructor
 * FUN_0006bc50) holding arrays at +0x38 (16-byte elements, each releasing
 * the object at +8 of the element), +0x48 and +0x60. Its out-of-line
 * destructor FUN_0005a230 restores the vtable and frees the arrays; the
 * destructors of two derived classes (vtable 0x1699260 at 0x5a150, and
 * 0x5a14b's) end by running it. */
struct RefArrays0005a230; /* derived name */

void FUN_0005a230(RefArrays0005a230 *self); /* derived name */
/* An object of 0x160 bytes with its own class allocator (vtable 0x169b460,
 * constructor FUN_000763a0) holding an array of 0x500-byte elements at
 * +0x140 (count at +0x148). Its out-of-line destructor FUN_000760c0
 * restores the vtable and destroys the elements. A derived class
 * (vtable 0x169b410, constructor FUN_000768c0: a pointer at +0x150) adds
 * nothing to destroy, so both vtables share the complete destructor
 * FUN_00076060 and the deleting destructor FUN_00076070. */
struct Elements000760c0; /* derived name */

void FUN_000760c0(Elements000760c0 *self); /* derived name */
/* Reads the processor's time-stamp counter (rdtscp, edx:eax joined into 64
 * bits); its only caller is FUN_00092200, whose caller (0xdb64) mixes the
 * low half into a random seed with the time and a process value. */
u64 FUN_00184cf0(); /* derived name */

/* A four-byte structure layout description (FUN_00180ee0, FUN_00180ef0):
 * the rules {8, 1, 1, 1} and {8, 1, 0, 1} sit in rodata at 0x14cb8f6 and
 * 0x14cb8fa, just before the assert string of hkStructureLayout.cpp; the
 * class is likely hkStructureLayout (the file of FUN_001814f0), not
 * established. */
struct LayoutRules00180ef0 {
    u8 bytesInPointer;
    u8 littleEndian;
    u8 reusePadding;
    u8 emptyBaseOptimization;
};

struct Layout00180ef0 {
    LayoutRules00180ef0 rules;
};

/* The object copier (derived name, from hkObjectCopier.cpp, the home of
 * its neighbours 0x1a0890 and 0x1a0b40): a reference-counted object
 * (vtable address point 0x16a75e0) whose constructor 0x1a0840 copies the
 * source layout to +0xc and the target layout to +0x10, stores the flags
 * at +0x14 and sets +0x18 when the two byte orders differ. */
class hkObjectCopier : public hkReferencedObject /* derived name */
{
  public:
    Layout00180ef0 layoutIn;  /* derived name */
    Layout00180ef0 layoutOut; /* derived name */
};

/* The platform object writer (derived name): a reference-counted object
 * (vtable address point 0x16a6920, constructor 0x19a950) that builds an
 * object copier from the host layout {8, 1, 1, 1} to the target one and
 * keeps it at +0x10. FUN_0019ab00 returns the copier's target layout; the
 * packfile writer at 0x183261 compares its byte order with the host's. */
class hkPlatformObjectWriter : public hkReferencedObject /* derived name */
{
  public:
    const Layout00180ef0 &FUN_0019ab00() const; /* derived name */

    hkObjectCopier *copier; /* derived name */
};

/* A polymorphic pool (vtables 0x168cbb0 and 0x16d3390, the second a
 * game-region class sharing every slot from 2): slot 9 (FUN_00007880)
 * returns the count at +0x328, the number of 64-byte records that slot 6
 * (FUN_000076d0) walks after storing the callback FUN_00007730 and its
 * argument at +0x310. Slot 13 (FUN_000075d0) sets the flag at +0x330, which
 * the worker loop at 0x7337 tests after each callback; the code at 0x70a1
 * clears it with the byte after it. */
class Pool00007880 /* derived name */
{
  public:
    virtual ~Pool00007880();

    int FUN_00007880() const; /* vtable slot 9; derived name */
    void FUN_000075d0();      /* vtable slot 13; derived name */

    u8 unknown8[0x320];
    int count; /* derived name */
    u8 unknown32c[4];
    bool flag330; /* derived name */
};

/* A Mersenne twister (MT19937): 624 words of state in a block of 2496 bytes
 * the seeding (FUN_000106e0, multiplier 1812433253) allocates on first use
 * and FUN_00010690 frees, the index at +0. The constructor (FUN_00010680)
 * only clears the state pointer; 0xdaf0 builds one at +0x10 of a new
 * reference-counted object and seeds it from the time. */
struct MersenneTwister /* derived name */
{
    u16 index;  /* derived name */
    u32 *state; /* derived name */
};

/* A free list of fixed-size elements: the head of the free elements at +0
 * (each holds the next), the element size at +8, the bump pointer and the
 * end of the current block at +0x40 and +0x48, the free count at +0x68.
 * FUN_00019230 adds a block, FUN_00018770 frees them all, FUN_00019440
 * fills a statistics record. */
struct FreeList /* derived name */
{
    void *freeHead;  /* derived name */
    u64 elementSize; /* derived name */
};

/* An allocator's statistics, six signed byte counts (the copy in slot 9 of
 * the allocator at 0x16a3230, FUN_0008f470; its allocation path keeps the
 * third as the maximum of the second). Field names derived. */
struct MemoryStatistics /* derived name */
{
    s64 allocated;      /* derived name */
    s64 inUse;          /* derived name */
    s64 peakInUse;      /* derived name */
    s64 available;      /* derived name */
    s64 totalAvailable; /* derived name */
    s64 largestBlock;   /* derived name */
};

void FUN_00019440(const FreeList *self, MemoryStatistics &statistics); /* derived name */

/* An allocator of fixed-size blocks over the free list at +8 (vtable address
 * point 0x168e5c0, slots 0 and 1 the one destructor 0x14a50): blockAlloc and
 * bufAlloc are one body (0x14aa0), blockFree and bufFree another (0x14af0);
 * slot 9 (FUN_00014c40) reports the free list's statistics. */
class FixedSizeAllocator : public AllocatorBase /* derived name */
{
  public:
    void FUN_00014c40(MemoryStatistics &statistics) const; /* vtable slot 9; derived name */

    FreeList freeList; /* derived name */
};

/* An allocator that draws its blocks from another allocator and keeps them
 * on a list (vtable 0x16a3220, address point 0x16a3230; constructor
 * FUN_0008f180, destructor FUN_0008f120 in slots 0 and 1): a critical
 * section at +8 (spin count 1000), the parent allocator at +0x18, its
 * statistics at +0x20 and the list head at +0x50, each block with a 16-byte
 * header (next, rounded size, requested size). Slots 2 and 3 (0x8f220,
 * 0x8f330) allocate and free under the lock, slot 9 (0x8f470) copies the
 * statistics, slot 11 resets the peak. */
class BlockListAllocator : public AllocatorBase /* derived name */
{
  public:
    void FUN_0008f560(); /* vtable slot 11; derived name */

    u8 unknown8[0x18];
    MemoryStatistics statistics; /* derived name */
    void *blocks;                /* derived name */
};

#endif
