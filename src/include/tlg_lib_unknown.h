/* Library-region objects of unknown class, each reached by two matched
 * accessors of one field, the pair shown by a caller that uses both on the
 * same object. derived names throughout. */
#ifndef TLG_LIB_UNKNOWN_H
#define TLG_LIB_UNKNOWN_H

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
 * on the same object (its own +0x18) and sign-extends the first. */
struct Pair08Owner {
    u8 unknown0[8];
    s32 first;
    s32 second;
};

/* FUN_000ad770 and FUN_000ad780 sit in adjacent slots of one vtable
 * (0x16a3a78, 0x16a3a80): a getter and a setter of the int at +0x2c. The
 * slots before them read and write the bytes at +0x29 to +0x2b. */
struct Value2cOwner {
    u8 unknown0[0x2c];
    s32 value;
};

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

/* An allocator with two polymorphic bases, the primary at +0 (vtable
 * 0x168c640) and a second interface at +8 (vtable 0x168c708), both stored
 * by its constructor FUN_00001960. Its complete destructor is FUN_00001fb0,
 * its deleting destructor (slot 1) FUN_00001f90; slot 12 (FUN_00001620)
 * returns the object as its second base. */
class TwoBaseAllocatorBase
{
  public:
    virtual ~TwoBaseAllocatorBase();
};

class TwoBaseAllocatorInterface
{
  public:
    virtual ~TwoBaseAllocatorInterface();
};

class TwoBaseAllocator : public TwoBaseAllocatorBase, public TwoBaseAllocatorInterface
{
  public:
    virtual ~TwoBaseAllocator();
    virtual TwoBaseAllocatorInterface *FUN_00001620();
};

void FUN_00001fb0(TwoBaseAllocator *self); /* derived name */

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
#endif
