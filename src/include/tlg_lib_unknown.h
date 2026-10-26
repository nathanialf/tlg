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
    u8 unknown0;
    u8 flags; /* bit 2 set and cleared by FUN_0002b390; derived name */
    u8 count;
    u8 unknown3[2];
    u8 state;
    u8 unknown6[2];
    s32 first;
    s32 second;
    u8 unknown10[0x28];
    Pair08Target *target;
};

/* One of the 32-byte entries after the owner's 0x40 bytes: FUN_0002b0f0
 * scales valueA of each, FUN_0002b120 valueB where it is positive;
 * FUN_0002b010 and FUN_0002b030 return their addresses by index. */
struct Pair08Entry {
    u8 unknown0[0xc];
    float valueA; /* derived name */
    u8 unknown10[0xc];
    float valueB; /* derived name */
};

float *FUN_0002b010(Pair08Owner *self, int index);                /* derived name */
float *FUN_0002b030(Pair08Owner *self, int index);                /* derived name */
void FUN_0002b040(Pair08Owner *self, float scaleA, float scaleB); /* derived name */
void FUN_0002b0b0(Pair08Owner *self);                             /* derived name */
void FUN_0002b0c0(Pair08Owner *self, int mode, float value);      /* derived name */
void FUN_0002b0f0(Pair08Owner *self, float scale);                /* derived name */
void FUN_0002b120(Pair08Owner *self, float scale);                /* derived name */
/* What follows the record's entries (derived names): FUN_0002af30 returns
 * its address (past the 32-byte entries from +0x40 and a size the table at
 * 0x14b8690 gives for the byte at +3), FUN_0002af50 the address of an int
 * in it, 16 bytes further for each of the conditions its byte at +4 tells
 * (nonzero, bit 1, bit 0). */
struct Pair08Tail; /* derived name */

Pair08Tail *FUN_0002af30(const Pair08Owner *self); /* derived name */
const s32 *FUN_0002af50(const Pair08Tail *tail);   /* derived name */
s32 FUN_00034850(const Pair08Owner *self);         /* derived name */
s32 FUN_00034870(const Pair08Owner *self);         /* derived name */

/* One vector per entry of the record (derived names): FUN_00031740 writes
 * one vector per entry (its count) from the two motions' vectors at +0x40
 * and +0x50 and the record's vector at +0x20; FUN_000348a0, called at
 * 0x15d8e5, forwards to it with the record's count, its fourth argument
 * unused. */
void FUN_00031740(const Pair08Owner *self, int count, const hknpMotion *motionA,
                  const hknpMotion *motionB, Vec4 *out); /* derived name */
void FUN_000348a0(const Pair08Owner *self, const hknpMotion *motionA, const hknpMotion *motionB,
                  const void *argument4, Vec4 *out); /* derived name */

void FUN_0002b390(Pair08Owner *self,
                  bool enable); /* derived name: sets or clears bit 2 of the byte at +1 */

/* The object handed to FUN_0002b180 and FUN_0002b3b0 before the record
 * (FUN_0003d7d0 passes the one embedded at +0x390 of its second argument):
 * vectors at +0x20, +0x40 and +0x120, a float at +0x130. */
struct Info0002b180; /* derived name */

/* FUN_0002b3b0's output: an int at +0, a float at +4, a vector at +0x10,
 * floats from +0x30 and vectors from +0x40, one per entry. */
struct Output0002b3b0; /* derived name */

void FUN_0002b180(const Info0002b180 *info, Pair08Owner *self, const Vec4 &a,
                  const Vec4 &b); /* derived name */
void FUN_0002b3b0(const Info0002b180 *info, Pair08Owner *self, const hknpMotion *motionA,
                  const hknpMotion *motionB, Output0002b3b0 *out); /* derived name */

/* The cell index of the motion of the record's first and second body (the
 * ints at +8 and +0xc index the world's bodies). */
u8 FUN_0002afa0(const hknpWorld *world, const Pair08Owner *self); /* derived name */
u8 FUN_0002afd0(const hknpWorld *world, const Pair08Owner *self); /* derived name */

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
class AllocatorInterface;

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
    /* Slots 6 to 11, signatures not recovered (6 to 8 the defaults 0x8d90,
     * 0x8e00 and 0x8e50, 9 the statistics, 11 the peak reset). */
    virtual void unknownVirtual6();
    virtual void unknownVirtual7();
    virtual void unknownVirtual8();
    virtual void unknownVirtual9();
    virtual void unknownVirtual10();
    virtual void unknownVirtual11();
    /* Slot 12: the allocator's second interface, null by default (the
     * shared 0x42d0); named after TwoBaseAllocator's overrider, which
     * returns its second base. */
    virtual AllocatorInterface *FUN_00001620();
};

/* The interface's slots 2 to 10 in their vtable order, each named after
 * TwoBaseAllocator's overrider (primary slots 13 to 21) and typed from its
 * body. The executable holds no vtable of the interface itself (no run of
 * nine __cxa_pure_virtual slots after two destructors), and every allocator
 * met so far overrides all nine, so they are pure. */
class AllocatorInterface /* derived name */
{
  public:
    virtual ~AllocatorInterface();

    virtual void FUN_00003140() = 0;                        /* slot 2; derived name */
    virtual void FUN_000032e0(int value) = 0;               /* slot 3; derived name */
    virtual int FUN_000034a0(void *pointer) = 0;            /* slot 4; derived name */
    virtual void *FUN_00003580() const = 0;                 /* slot 5; derived name */
    virtual bool FUN_00002230(int numBytes) = 0;            /* slot 6; derived name */
    virtual int FUN_00002f10(void *a, void *b) = 0;         /* slot 7; derived name */
    virtual u64 allocatedBytes() const = 0;                 /* slot 8; derived name */
    virtual void FUN_00002330(int value) = 0;               /* slot 9; derived name */
    virtual int FUN_000035a0(void *pointer, int value) = 0; /* slot 10; derived name */
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

/* The allocator over one block at +0x138 of LargeBlockAllocator (derived
 * name; vtable 0x168e210, address point 0x168e220, stored in place by the
 * constructor FUN_00012160 at 0x12194, which clears +8 to +0x20; slots 0
 * and 1 the shared 0x4ac0): the block's start at +8 and the end of what is
 * handed out at +0x20. Slot 4 (0x120d0) hands out the whole block when
 * nothing is out, slot 5 (FUN_00012100) takes it back, slot 9 (0x12120)
 * reports its use. */
class SingleBlockAllocator : public AllocatorBase /* derived name */
{
  public:
    void FUN_00012100(void *pointer, int numBytes); /* vtable slot 5; derived name */

    char *start; /* derived name */
    u8 unknown10[0x10];
    char *top; /* derived name */
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

/* The memory system (derived name): a polymorphic object whose instance
 * the global at 0x57b7ba0 holds. The startup at 0x11c3 installs it through
 * FUN_00006c40 and the shutdown at 0x17ae6 clears it; FUN_00006c50 returns
 * it to the callers of its slots (13 at 0x7350, 17 at 0xecb6, 4 at 0x8f5c5,
 * and the game code at 0xe993e5). */
class hkMemorySystem; /* derived name */

extern hkMemorySystem *D_57b7ba0;
void FUN_00006c40(hkMemorySystem *system); /* derived name */
hkMemorySystem *FUN_00006c50();            /* derived name */

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

/* The allocator interface at +0x20 of the memory system (derived names):
 * slots 0 and 1 its destructors, slot 2 collects its garbage (called by
 * FUN_0000d0a0). */
class MemoryExtendedInterface /* derived name */
{
  public:
    virtual ~MemoryExtendedInterface();
    virtual void garbageCollect() = 0; /* derived name */
    virtual void unknownVirtual3() = 0;
    /* Slot 4: takes a 64-bit value (the memory system's slot 6, FUN_0000d230,
     * widens its int with movslq) and returns an int. */
    virtual int unknownVirtual4(s64 value) = 0;
    /* Slot 5: returns a 64-bit value, which the memory system's slot 7
     * (FUN_0000d250) truncates to an int, keeping the call: the return is
     * duplicated into a tail call only when the phi's incoming value is the
     * call itself (tools/cc/src/llvm-3.3.src/lib/Transforms/Scalar/
     * CodeGenPrepare.cpp:761, DupRetToEnableTailCallOpts), and here it is the
     * trunc. */
    virtual s64 unknownVirtual5() = 0;
    /* Slot 6: a bool the memory system's slot 9 (FUN_0000d290) hands back. */
    virtual bool unknownVirtual6() = 0;
    virtual void unknownVirtual7() = 0;
    virtual void unknownVirtual8() = 0;
    /* Slot 9: takes an int; the allocator at 0x57af9c0, whose second base
     * this is, does it under its spinning mutex (0x2330, through the thunk
     * FUN_00002400). */
    virtual void unknownVirtual9(int value) = 0;
};

/* An allocator over one fixed buffer (derived name; vtable address point
 * 0x16a3470, slots 0 and 1 0x909a0 and 0x90930, slots 2 to 5 0x90b20 to
 * 0x90dc0): the buffer's start at +8 and end at +0x10, the end of what is in
 * use at +0x18 and the peak use at +0x28. Slot 9 (0x910a0) reports the
 * buffer size, the free and used bytes and the peak; slot 11 (0x910d0)
 * resets the peak to the current use. FUN_00091090, not a slot, tells
 * whether the whole buffer could hold a block of a size; the memory system's
 * wrapper at 0xd270 asks it of the allocator at its +0x100. */
class BufferAllocator : public AllocatorBase /* derived name */
{
  public:
    void *blockAlloc(int numBytes);              /* slot 2 (0x90b20); derived name */
    void blockFree(void *pointer, int numBytes); /* slot 3 (0x90d90); derived name */
    bool FUN_00091090(int numBytes) const;       /* derived name */
    void FUN_000910d0();                         /* vtable slot 11; derived name */

    char *bufferStart; /* derived name */
    char *bufferEnd;   /* derived name */
    char *currentEnd;  /* derived name */
    u8 unknown20[8];
    hkUlong peakUse; /* derived name */
};

struct MemorySystem {
    u8 unknown0[0x18];
    MemorySystemAllocator *allocator18;
    MemoryExtendedInterface *extended20; /* derived name */
    u8 unknown28[0xd8];
    /* The buffer allocator at +0x100 (slot 8, FUN_0000d270, asks it). */
    BufferAllocator bufferAllocator; /* derived name */
    u8 unknown130[0x6e30];
    /* Set by the constructor from its fifth argument; bit 2 gives each
     * thread its own allocator (FUN_0000c590). */
    s32 flags; /* derived name */
};

struct hkMemoryRouter;

/* Slot 13 of the memory system's vtable: with a thread allocator per
 * thread (flags bit 2), runs slot 13 of the router's one. derived name. */
void FUN_0000d080(MemorySystem *self, hkMemoryRouter &router); /* derived name */

void FUN_0000d0a0(MemorySystem *self); /* derived name */
/* Slots 6 and 7 of the memory system's vtable: hand an int to slot 4 of
 * the allocator interface at +0x20, and read slot 5 back as an int; 0
 * without one. derived names. */
int FUN_0000d230(MemorySystem *self, int value); /* derived name */
int FUN_0000d250(MemorySystem *self);            /* derived name */
bool FUN_0000d290(MemorySystem *self);           /* derived name */

/* Slot 8 of the memory system's vtable: whether its buffer allocator could
 * hold a block of a size. derived name. */
bool FUN_0000d270(MemorySystem *self, int numBytes); /* derived name */

/* Slot 20: hands an int to slot 9 of the allocator interface at +0x20, when
 * there is one. derived name. */
void FUN_0000d2c0(MemorySystem *self, int value); /* derived name */

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
/* A 12-byte record (derived name) kept in an array at +0xd0 (count at
 * +0xd8) of the objects FUN_0004d650 and FUN_0005b680 grow, each new one
 * built by the out-of-line constructor FUN_001618f0: the ids at +0 and +8
 * start invalid (0x7fffffff), the u16 at +4 at zero; the caller then stores
 * the first id. */
struct Object001618f0 /* derived name */
{
    Object001618f0();

    u32 first;  /* derived name */
    u16 second; /* derived name */
    u32 third;  /* derived name */
};

/* An object with an array of 0x90-byte entries at +0x20 (derived name):
 * FUN_0005d6b0 works on the entry of an index with a pointer and an int. */
struct Object0005d6b0; /* derived name */

void FUN_0005d6b0(Object0005d6b0 *self, int index, const void *argument3,
                  int argument4); /* derived name */

/* The object whose FUN_00178580 the game calls (0xeb055f, 0xeb0e90): an
 * index at +0xc into the entries of the object at +0x18 (derived names). */
struct Object00178580 /* derived name */
{
    u8 unknown0[0xc];
    s32 index; /* derived name */
    u8 unknown10[8];
    Object0005d6b0 *owner; /* derived name */
};

void FUN_00178580(Object00178580 *self, const void *argument); /* derived name */

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

/* The same class as an object (derived name): 0x50 bytes, the four arrays
 * after the reference-counted object's header. Its destructor is
 * FUN_00048040's body (the row keeps the FUN_ name until the class's vtable
 * 0x1698f40 has a ruling, D14, and the row is renamed, D15). */
class RefArrays /* derived name */ : public hkReferencedObject
{
  public:
    ~RefArrays();

    hkArray<Vec4> array10;                    /* derived name */
    hkArray<int> array20;                     /* derived name */
    hkArray<void *> array30;                  /* derived name */
    hkArray<hkReferencedObject *> references; /* derived name */
};

/* The interface at +0x10 of Object0014e4b0 (derived name): four slots, the
 * destructors, 0x14e840 (forwards to the owner's slot 5) and 0x14e760. */
class Interface0014e7b0 /* derived name */
{
  public:
    virtual ~Interface0014e7b0() {}

    virtual void unknownVirtual2();
    virtual void unknownVirtual3();
};

/* An object of 0x90 bytes (derived name; vtable 0x16a4080, address point
 * 0x16a4090, no type info; the second base's vtable at 0x16a40c8, address
 * point 0x16a40d8), built inline by FUN_00151250 at 0x1515a1: the
 * reference-counted object, the interface at +0x10, pointers at +0x18,
 * +0x20 and +0x28 and +0x30 from the builder, the arrays object at +0x38.
 * Destructors 0x14e4b0 (and its thunk 0x14e7b0), deleting 0x14e4d0
 * (0x14e7d0). */
class Object0014e4b0 /* derived name */ : public hkReferencedObject, public Interface0014e7b0
{
  public:
    virtual ~Object0014e4b0();

    /* slot 5 (0x14e540), also the interface's slot 2 through the thunk
     * 0x14e840 */
    virtual void unknownVirtual2();
    /* slot 6: 0x14e760, the same body as the interface's slot 3 */
    virtual void unknownVirtual6();

    void *unknown18;  /* derived name */
    void *unknown20;  /* derived name */
    void *unknown28;  /* derived name */
    void *unknown30;  /* derived name */
    RefArrays arrays; /* derived name */
    u8 unknown88[8];
};
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
 * at +0x14 and sets +0x18 when the two byte orders differ. Slot 6
 * (0x1a0b20) tells whether a member of one layout can be copied to one of
 * the other. */
class hkObjectCopier : public hkReferencedObject /* derived name */
{
  public:
    int FUN_001a0b20(const hkClassMember &src,
                     const hkClassMember &dst); /* vtable slot 6; derived name */

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
 * clears it with the byte after it. That byte (+0x331) is set by slots 5
 * and 6 (0x7600, 0x7660, 0x76d0) when they hand the workers a callback,
 * tested by the waits at 0x7402 and 0x774d, and read by slot 7
 * (FUN_000077a0) as a test against zero (hkBool). */
/* It is reference-counted: its constructor 0x6d70 stores 0xffff0001 at +8
 * and slots 2 to 4 are hkReferencedObject's (0x270, 0x42d0, 0x69a0). From
 * +0x10, up to eleven 64-byte worker records (0x7890 starts at most 11
 * threads): the pool at +0, the thread at +8 (constructed by 0x104b0 and
 * started by 0x10580 on FUN_00007180 with the record as its argument), the
 * worker's index plus one at +0x18. Slot 14 (0x71a0) is a worker's loop,
 * taking its index (it reads the record's +0x18 at index * 64). */
class Pool00007880 : public hkReferencedObject /* derived name */
{
  public:
    struct WorkerRecord /* derived name */
    {
        Pool00007880 *pool; /* derived name */
        u8 unknown8[0x10];
        int threadId; /* derived name */
        u8 unknown1c[0x24];
    };

    virtual ~Pool00007880();

    virtual void unknownVirtual5();
    virtual void unknownVirtual6();
    virtual bool FUN_000077a0() const; /* vtable slot 7; derived name */
    virtual void unknownVirtual8();
    virtual int FUN_00007880() const; /* vtable slot 9; derived name */
    virtual void unknownVirtual10();
    virtual void unknownVirtual11();
    virtual void unknownVirtual12();
    virtual void FUN_000075d0();                /* vtable slot 13; derived name */
    virtual void FUN_000071a0(int workerIndex); /* vtable slot 14; derived name */

    u8 unknownC[4];
    WorkerRecord workers[11]; /* derived name */
    u8 unknown2d0[0x58];
    int count; /* derived name */
    u8 unknown32c[4];
    bool flag330;   /* derived name */
    hkBool running; /* derived name */
};

/* derived name: the start function of a pool's worker thread (0x7890
 * passes it to 0x10580 with the worker's record): runs the pool's worker
 * loop for the record's index. */
void *FUN_00007180(void *argument); /* derived name */

/* A singly linked node (derived name): the next node at +0. FUN_000188a0
 * counts a list's nodes; 0x1630 sums the counts of the two lists at +0x18
 * and +0x20 of each of its objects before it allocates eight bytes per
 * node. */
struct ListNode000188a0 /* derived name */
{
    ListNode000188a0 *next; /* derived name */
};

int FUN_000188a0(const ListNode000188a0 *node); /* derived name */

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
    /* Sets the free list up (0x186a0): frees what it held, then keeps the
     * element size rounded up to the alignment, the block size and the two
     * allocators, a null block allocator taking the thread's router's
     * temporary allocator. */
    void FUN_000186a0(u64 elementSize, u64 alignment, u64 blockSize, AllocatorBase *blockAllocator,
                      AllocatorBase *elementAllocator); /* derived name */

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
    /* Sets the free list up with an alignment of at least 32 and no element
     * allocator (the caller at 0x1b92 passes 32, 8 and the block size). */
    void FUN_00014a80(u64 elementSize, u64 alignment, u64 blockSize,
                      AllocatorBase *blockAllocator);      /* derived name */
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

/* A thread's allocator (derived name; vtable 0x168e460, address point
 * 0x168e470, constructor FUN_000143a0): the memory system keeps one per
 * thread, 0x1a8 bytes apart from its +0x550, and when its flags have bit 2
 * hands the thread's one to the router as its temporary allocator (+0x58,
 * FUN_0000c590). It adds slot 13 (0x14690) to the allocator's slots. */
class ThreadMemory : public AllocatorBase /* derived name */
{
  public:
    virtual void FUN_00014690(); /* vtable slot 13; derived name */

    /* Gives the thread's allocator the allocator it draws from and how many
     * blocks each free list may keep (FUN_0000c590 passes 8); a null
     * allocator only clears it. */
    void FUN_00014610(AllocatorBase *memory, int maxNumElemsOnFreeList); /* derived name */

    AllocatorBase *memory;     /* derived name; slot 13 returns blocks to it */
    int maxNumElemsOnFreeList; /* derived name */
};

/* A union-find over node indices (derived name; the stage timer of its
 * caller at 0x6dcf3 is "StUnionFind"), 0x18 bytes, built by FUN_0008f640:
 * the parents (an object whose +0 points to the int array; -1 marks a root)
 * at +0, the node count at +8, an int at +0xc set to 1 there and cleared
 * by FUN_00065f10, -1 at +0x10 and 0 at +0x14. FUN_0008f710 joins two
 * nodes. */
struct UnionFindParents /* derived name */
{
    int *data; /* derived name */
};

struct UnionFind /* derived name */
{
    UnionFindParents *parents; /* derived name */
    int numNodes;              /* derived name */
    int state;                 /* derived name */
};

/* A 32-byte record of the union-find's owner: a bit field (the callers at
 * 0x6d79e and 0x16e475 resize it with FUN_00047b30) and eight bytes the
 * constructor leaves alone. */
struct Record00065f00 /* derived name */
{
    hkBitField bits; /* derived name */
    u8 unknown18[8];
};

/* The union-find's owner (constructor FUN_00065b70, destructor
 * FUN_00065de0): the union-find at +0 (freed with 0x18 bytes) and its
 * parents at +8 (0x10 bytes), twelve 32-byte records from +0x10 (each
 * starting with an empty hkBitField; FUN_00065f00 returns one by index), the
 * node count at +0x190 and a second count at +0x194; the constructor sets
 * the flag at +0x198, FUN_00065f20 clears it (called at 0x6dd1f and
 * 0x14e946, after the records are filled). */
struct Object00065f20 /* derived name */
{
    UnionFind *unionFind;       /* derived name */
    UnionFindParents *parents;  /* derived name */
    Record00065f00 records[12]; /* derived name */
    u8 unknown190[8];
    bool open; /* derived name */
};

void FUN_00065f10(Object00065f20 *self);                       /* derived name */
void FUN_00065f20(Object00065f20 *self);                       /* derived name */
Record00065f00 *FUN_00065f00(Object00065f20 *self, int index); /* derived name */

/* An allocator over the system heap (vtable address point 0x168ca00):
 * slot 2 (0x4ad0) adds the size atomically to the bytes in use at +0xc,
 * raises the peak at +0x10 to it and allocates with the alignment at +8;
 * slot 3 (FUN_00004af0) subtracts and frees; slot 9 (0x4b00) reports both
 * counts widened to 64 bits; slot 11 (FUN_00004b10) resets the peak to the
 * current use (also called directly from six places in the game region). */
class Allocator00004b10 /* derived name */
{
  public:
    virtual ~Allocator00004b10();

    void *FUN_00004ad0(int numBytes);                      /* vtable slot 2; derived name */
    void FUN_00004af0(void *pointer, int numBytes);        /* vtable slot 3; derived name */
    void FUN_00004b00(MemoryStatistics &statistics) const; /* vtable slot 9; derived name */
    void FUN_00004b10();                                   /* vtable slot 11; derived name */

    int alignment;  /* derived name */
    u32 bytesInUse; /* derived name: updated atomically by every thread */
    u32 peakInUse;  /* derived name */
};

/* A stack tracer (derived name), built on the stack by the error report at
 * 0xb680 (constructor FUN_0000d8f0 stores the vtable address point
 * 0x168d850, destructor the empty FUN_0000d940). On this platform it has no
 * trace: collecting one (the shared FUN_000042d0) finds no frames and
 * printing one (FUN_0000d890) reports the fact through the caller's print
 * function. */
class StackTracer /* derived name */
{
  public:
    typedef void (*PrintFunction)(const char *text, void *context); /* derived name */

    StackTracer();
    virtual ~StackTracer();

    void FUN_0000d890(const hkUlong *trace, int numTrace, PrintFunction print,
                      void *context) const; /* derived name */
};

/* An image loaded from a file (derived name): FUN_00188560 opens the file a
 * name gives, checks its extension against "tga" and returns what the
 * loader at 0x1887a0 builds, or null. */
struct LoadedImage; /* derived name */

/* The pixels the loader reads into (derived names): built on its stack
 * (0x18882d) by FUN_001a0470, the width and height at +0 and +4 (from the
 * TGA header's 16-bit fields at 0x188832) and the bytes from +8; the
 * reference-counted image 0x1a04d0 builds copies the three. */
struct RawImage /* derived name */
{
    RawImage();

    int width;          /* derived name */
    int height;         /* derived name */
    hkArray<u8> pixels; /* derived name */
};

LoadedImage *FUN_00188560(const char *fileName); /* derived name */

/* A reference-counted source of an image (derived name; vtable address
 * point 0x16a6620, constructor FUN_00188e90, slots 5 and 6 pure), and the
 * one that names a file (derived name; vtable address point 0x16a3ab0,
 * 0x18 bytes as the copier at 0xad7c0 allocates it, destructors 0xad590 and
 * 0xad5b0): its file name (hkStringPtr) at +0x10; slot 5 is the empty
 * 0xa9140, slot 6 (FUN_000ad7b0) loads the file. */
class ImageSource : public hkReferencedObject /* derived name */
{
  public:
    ImageSource();
};

class FileImageSource : public ImageSource /* derived name */
{
  public:
    virtual ~FileImageSource();

    LoadedImage *FUN_000ad7b0(); /* vtable slot 6; derived name */

    hkStringPtr fileName; /* derived name */
};

/* A stream reader (derived name), the object a buffered reader reads from:
 * slot 5 tells whether it can be read (the buffered reader's 0x94580: data
 * still buffered, or its stream's answer); its slot 9 returns the stream
 * itself when it can seek and tell, else null, slot 10 seeks and slot 11
 * tells. */
class StreamReader : public hkReferencedObject /* derived name */
{
  public:
    virtual hkBool isOk() const; /* vtable slot 5; derived name */
    virtual void unknownVirtual6();
    virtual void unknownVirtual7();
    virtual void unknownVirtual8();
    virtual StreamReader *unknownVirtual9();
    virtual int seek(int offset, int whence); /* vtable slot 10; derived name */
    virtual int tell() const;                 /* vtable slot 11; derived name */
};

/* An input stream over a reader (derived name; vtable 0x16a65d0, address
 * point 0x16a65e0, with only the reference-counted object's slots; the
 * constructor 0x185060 opens the reader of a file name through the file
 * system at 0x57b9b70): the reader at +0x10. The image loader builds one on
 * the stack (0x18858c) and tests it with FUN_00185230 before reading. */
class InputStream : public hkReferencedObject /* derived name */
{
  public:
    hkBool FUN_00185230() const; /* derived name */

    StreamReader *reader; /* derived name */
};

/* The file system the library installs (derived name; vtable 0x168ea90,
 * address point 0x168eaa0, built as a bare reference-counted object by
 * FUN_000098d0 and stored in the slot at 0x57b9b70, the singleton the
 * string "hkFileSystem" names): slot 7 removes a file and slot 8 creates a
 * directory through Fios. */
class FiosFileSystem : public hkReferencedObject /* derived name */
{
  public:
    hkResult FUN_0001bbc0(const char *path); /* vtable slot 7; derived name */
    hkResult FUN_0001bbe0(const char *path); /* vtable slot 8; derived name */
};

/* A reader interface whose slot 9 seeks and slot 10 tells (derived names):
 * the object of the vtable at 0x16a6400 (address point 0x16a6410; no type
 * info names it), built on the stack by FUN_00183350, implements it over
 * another at +0x10, offset by the int at +0x18: slots 5 to 8 forward to the
 * same slots of the inner reader (the folded forwarders 0xabf0, 0x89f0,
 * 0x89e0 and 0xaa530), slot 9 (FUN_00181ad0) seeks it, moving an absolute
 * position by the offset, slot 10 (FUN_00181af0) tells its position less
 * the offset, slot 11 is the shared false 0x1bad0. Slots 5 to 8 are not
 * recovered. */
class SeekableReader : public hkReferencedObject /* derived name */
{
  public:
    virtual void unknownVirtual5();
    virtual void unknownVirtual6();
    virtual void unknownVirtual7();
    virtual void unknownVirtual8();
    virtual int seek(int offset, int whence) = 0; /* vtable slot 9; derived name */
    virtual int tell() const = 0;                 /* vtable slot 10; derived name */
};

class OffsetSeekableReader : public SeekableReader /* derived name */
{
  public:
    int FUN_00181ad0(int offset, int whence); /* vtable slot 9; derived name */
    int FUN_00181af0() const;                 /* vtable slot 10; derived name */

    SeekableReader *reader; /* derived name */
    int start;              /* derived name */
};

/* A buffered stream reader (derived names; vtable address point 0x16a35d0,
 * constructor 0x94170, the reference-counted object's slots 2 to 4): the
 * stream at +0x10 (its reference count raised), what the stream's slot 9
 * returned at +0x18, the buffer at +0x20, the read position and the bytes in
 * the buffer at +0x28 and +0x2c, the buffer size at +0x30. Slot 9
 * (FUN_000946f0) returns the reader when the stream can seek; slot 10
 * (0x94700) empties the buffer and seeks the stream, slot 11 (0x94720) tells
 * the stream's position less what is still buffered; slot 5 (0x94580) is
 * readable while bytes are buffered, else asks the stream. */
class BufferedStreamReader : public hkReferencedObject /* derived name */
{
  public:
    hkBool isOk() const;                      /* vtable slot 5; derived name */
    BufferedStreamReader *FUN_000946f0();     /* vtable slot 9; derived name */
    int FUN_00094700(int offset, int whence); /* vtable slot 10; derived name */

    StreamReader *stream;         /* derived name */
    StreamReader *seekableStream; /* derived name */
    char *buffer;                 /* derived name */
    int position;                 /* derived name */
    int numBuffered;              /* derived name */
    int bufferSize;               /* derived name */
};

/* A job queue (derived names): its constructor 0x56c0 sets the pop and
 * finish functions at +0x18 and +0x20 to the dispatchers FUN_00005680 and
 * FUN_000056a0, and gives each job type in use (the count at +0x28) an
 * entry of 32 bytes from +0x130 whose pop and finish functions default to
 * 0x42d0 (returns 0) and 0x58a0 (returns 1). The queue calls the pop
 * function with a job and an output job (0x5155, the result compared with
 * 1) and the finish function with the data at +0x10, a job and an output
 * (0x62a0). A job's type is its byte at +1. */
struct hkJobQueueJob /* derived name */
{
    u8 jobSubType; /* derived name */
    u8 jobType;    /* derived name */
};

struct hkJobQueue /* derived name */
{
    typedef int (*JobPopFunc)(hkJobQueue &queue, void *data, hkJobQueueJob &jobIn,
                              hkJobQueueJob &jobOut); /* derived name */
    typedef int (*FinishJobFunc)(hkJobQueue &queue, void *data, const hkJobQueueJob &jobIn,
                                 void *newJobOut); /* derived name */

    struct CustomJobType /* derived name */
    {
        u64 unknown0;
        u32 unknown8;
        JobPopFunc popJobFunc;       /* derived name */
        FinishJobFunc finishJobFunc; /* derived name */
    };

    u8 unknown0[0x18];
    JobPopFunc popJobFunc;       /* derived name */
    FinishJobFunc finishJobFunc; /* derived name */
    u8 unknown28[0x108];
    CustomJobType customJobs[15]; /* derived name */
};

int FUN_00005680(hkJobQueue &queue, void *data, hkJobQueueJob &jobIn,
                 hkJobQueueJob &jobOut); /* derived name */
int FUN_000056a0(hkJobQueue &queue, void *data, const hkJobQueueJob &jobIn,
                 void *newJobOut); /* derived name */

/* An allocator (derived name; vtable 0x168da00, address point 0x168da10,
 * no type info) built by FUN_0000ed40 at +0 of the object FUN_0000bb60
 * constructs, which then clears that object's +0x50 to +0x78: slots 0 and
 * 1 the shared 0x4ac0, 2 to 6 its own (0xef00, 0xef70, 0xef40, 0xef70,
 * 0xefd0), 7 to 12 the defaults. The pointer at +8 starts null. */
class Allocator0000ed40 : public AllocatorBase /* derived name */
{
  public:
    Allocator0000ed40();

    void *pointer8; /* derived name */
};

/* The thread's memory router (derived name): FUN_0000bb40 makes the router
 * the thread's (the %fs-relative slot at 0x16d80b8 the allocators read);
 * FUN_014aff00, in the game region, then gives the thread a 0x28-byte block
 * from the router's heap at +0x60, kept in the slot at 0x16d80d0. */
struct hkMemoryRouter /* derived name */
{
    u8 unknown0[0x58];
    /* The temporary allocator (FUN_0000c590 sets it), also the heap
     * FUN_0000bcf0 frees through. */
    AllocatorBase *temp58; /* derived name */
};

/* The thread's router, a thread-local pointer: the TLS segment's template
 * is at 0x16dc060 (0x70 bytes, 4 of them initialised, alignment 8), and the
 * GOT slot 0x16d80b8 holds this object's offset from the thread pointer,
 * -0x60, which places it at +0x10 of the template. Every reader adds that
 * slot to %fs:0. */
extern __thread hkMemoryRouter *D_16dc070;

void FUN_0000bb40(hkMemoryRouter *router); /* derived name */
void FUN_014aff00();                       /* derived name */

/* The library's formatted print into a buffer of `size` bytes (derived name):
 * FUN_00017e80 starts the argument list and hands it to the imported
 * vsnprintf with the size widened (`movslq %esi`). */
int FUN_00017e80(char *buffer, int size, const char *format, ...); /* derived name */

/* Writes the Havok SDK version string, "hk_2014.2.0-r1", into a buffer of
 * `size` bytes (derived name); FUN_00183350 fills a 16-byte name with it
 * when the object at +0x10 has none. */
void FUN_0019d370(char *buffer, int size); /* derived name */

/* The memory copies at 0x910e0 to 0x91210 (derived names), each with a
 * signed int count: FUN_000910e0 forwards to memcpy, FUN_00091100 copies
 * backwards in the widest unit the count and both pointers' alignment allow,
 * and FUN_00091210 moves overlapping memory, backwards when the destination
 * is above the source. */
void FUN_000910e0(void *dst, const void *src, int n); /* derived name */
void FUN_00091100(void *dst, const void *src, int n); /* derived name */
void FUN_00091210(void *dst, const void *src, int n); /* derived name */

/* A reference-counted object (derived name; no type info names it) whose
 * vtable 0x16997f0 (address point 0x1699800) only its constructor
 * FUN_00061f00 stores; the game builds one at 0xea9d11. Slot 6 (0x61f40),
 * when the object it is given reads mode 1 (FUN_0000b670), moves a point
 * along a direction by the float at +0xc (1.5 on construction). */
class Object00061f00 : public hkReferencedObject /* derived name */
{
  public:
    Object00061f00();
    virtual ~Object00061f00();

    float valueC; /* derived name */
};

#endif
