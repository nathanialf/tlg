/* src/include/tlg_game_object013d35e0.h: members of the classes over
 * Object00c1b7f0 whose destructors those classes call out of line (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT013D35E0_H
#define TLG_GAME_OBJECT013D35E0_H

#include "tlg_types.h"
#include "tlg_game_node.h"
#include "tlg_game_block.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object0139b6b0.h"

/* derived names: the member whose complete destructor is 0x13d35e0 (its row
 * named for it, D15): at +0x540 of the class whose destructor is 0x1216120
 * and at +0x690 of the one whose destructor is 0xf59820, the last member
 * of each (`lea rdi, [r14+0x540]; call 0x13d35e0`). Polymorphic; its
 * destructor is not written, and its fields are not traced. */
class Object013d35e0 /* derived name */
{
  public:
    virtual ~Object013d35e0();

  private:
    u8 unknown8[0x228];
};

/* derived names: an entry of the table below: a singly linked list from
 * each of its 0x80 buckets (`mov rbx, [rbx+0x18]` the next one); the
 * pointers at +0x0 and +0x10 are handed to FUN_002049f0 (`mov rdx, [rbx];
 * mov rcx, [rbx+0x10]; mov edi, 2; xor esi, esi`, 0x1478610). The rest is
 * not traced. */
struct Entry01343090 { /* derived name */
    void *unknown0;    /* +0x0 */
    u8 unknown8[0x8];
    void *unknown10;     /* +0x10 */
    Entry01343090 *next; /* +0x18 */
};

void FUN_002049f0(int kind, bool flag, void *first, void *second); /* derived name; not traced */

/* derived names: the table at +0x108 of the object below: a lock word at
 * +0x0 and 0x80 buckets from +0x8 (FUN_01343090 tests the count at +0x408
 * and takes the lock with `lock cmpxchg [rdi], r15d`). Not written. */
class Table01343090 /* derived name */
{
  public:
    void FUN_01343090(); /* derived name: not traced */

    int lock; /* +0x0 */
    u8 unknown4[0x4];
    Entry01343090 *buckets[0x80]; /* +0x8 */
    unsigned count;               /* +0x408 */
};

/* derived names: a counted object holding that table at +0x108 */
class Pool01343090 : public Node00503fb0 /* derived name */
{
  public:
    u8 unknown64[0xa4];
    Table01343090 table; /* +0x108 */
};

void FUN_00c5a160(Pool01343090 *pool); /* derived name: not traced */

/* derived names: a counted reference to such an object, given up by
 * shutdown(): every entry of the table handed to FUN_002049f0, the table
 * passed to FUN_01343090, the object to FUN_00c5a160, then the reference
 * emptied, all behind a test of the reference (the destructors 0x14785c0
 * and 0x13d3970 begin with it; 0x1227c70 and 0xf96800 run it on a member's
 * at +0x8d0 while their object is active). */
class PoolRef01343090 /* derived name */
{
  public:
    void shutdown() /* derived name */
    {
        if (Pool01343090 *held = pool.get()) {
            for (int i = 0; i < 0x80; ++i)
                for (Entry01343090 *entry = held->table.buckets[i]; entry; entry = entry->next)
                    FUN_002049f0(2, false, entry->unknown0, entry->unknown10);
            held->table.FUN_01343090();
            FUN_00c5a160(held);
            pool.clear();
        }
    }

  private:
    AtomicRef0045c470<Pool01343090> pool;
};

/* derived names: the polymorphic members whose complete destructors are
 * 0x14785c0 (vtable 0x16d6a50, config/vtables.derived.base.txt; at +0x340
 * of the class whose destructor is 0x1216120) and 0x13d3970 (vtable
 * 0x16d39f0; at +0x390 of the one whose destructor is 0xf59820). Each
 * destructor gives up the pool its reference at +0x168 holds
 * (PoolRef01343090::shutdown()). Not written; the rest is not traced. */
class Object016d6a50 /* derived name */
{
  public:
    virtual ~Object016d6a50();

  private:
    u8 unknown8[0x160];
    PoolRef01343090 pool; /* +0x168 */
};

class Object016d39f0 /* derived name */
{
  public:
    virtual ~Object016d39f0();

  private:
    u8 unknown8[0x160];
    PoolRef01343090 pool; /* +0x168 */
};

/* derived names: the polymorphic members whose complete destructors are
 * 0x147a620 (at +0x2d0 of the class whose destructor is 0x1227c70) and
 * 0x13dc6c0 (at +0x2f0 of the one whose destructor is 0xf96800), their rows
 * named for them (D15); the holder gives up the pool the reference at
 * +0x8d0 holds while it is active (inlined at 0x1227d41 and 0xf968d1). The
 * destructors are not written; the rest is not traced. */
class Object0147a620 /* derived name */
{
  public:
    virtual ~Object0147a620();

    u8 unknown8[0x8c8];
    PoolRef01343090 pool; /* +0x8d0 */
    u8 unknown8d8[0x18];
};

class Object013dc6c0 /* derived name */
{
  public:
    virtual ~Object013dc6c0();

    u8 unknown8[0x8c8];
    PoolRef01343090 pool; /* +0x8d0 */
    u8 unknown8d8[0x18];
};

/* derived names: the member whose complete destructor is 0x13d6ba0 (its row
 * named for it, D15): two at +0x4b0 and +0x590 of the class whose
 * destructor is 0xf71430, which calls FUN_013d6920 on each while it is
 * active and destroys them last first (`lea rdi, [r14+0x590]; lea rbx,
 * [r14+0x4b0]; call 0x13d6ba0`). Not polymorphic; not written, and its
 * fields are not traced. */
class Object013d6ba0 /* derived name */
{
  public:
    ~Object013d6ba0();

    void FUN_013d6920(); /* derived name: not traced */

  private:
    u8 unknown0[0xe0];
};

/* derived names: an object deleted while its holder is active, its
 * destructor inlined (0xf71553: the block at +0x60 released, then
 * FUN_0134f620 on +0x20 and FUN_01347230 on +0x8, then the storage): at
 * +0x680 of the class whose destructor is 0xf71430, at +0xaf20 of what the
 * pointer at +0x220 of the one whose destructor is 0x11e5830 leads to, at
 * +0x400 of Object01052d30. The rest is not traced. */
struct Owned00f71430 { /* derived name */
    u8 unknown0[0x8];
    Object01347230 array8;  /* +0x8 */
    Object0134f620 array20; /* +0x20 */
    u8 unknown38[0x28];
    OwnedBlock05943280 block60; /* +0x60 */
};

/* derived names: the object at +0x2a0 of the class whose destructor is
 * 0x1048190, deleted while that object is active (`call 0x1052d30; mov rdi,
 * rbx; call 0x14b0248`: the complete destructor, then the storage). Not
 * polymorphic. Its destructor is not written; it releases what it holds up
 * to +0x4c0. */
class Object01052d30 /* derived name */
{
  public:
    ~Object01052d30();

  private:
    u8 unknown0[0x4c8];
};

#endif
