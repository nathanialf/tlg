/* Library-region objects of unknown class, each reached by two matched
 * accessors of one field, the pair shown by a caller that uses both on the
 * same object. derived names throughout. */
#ifndef TLG_LIB_UNKNOWN_H
#define TLG_LIB_UNKNOWN_H

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
class LargeBlockAllocator : public AllocatorBase, public AllocatorInterface /* derived name */
{
  public:
    virtual ~LargeBlockAllocator();

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
#endif
