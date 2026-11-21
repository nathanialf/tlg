/* src/include/tlg_game_object016ca768.h: two classes of the same form, over
 * Object016d3ef8 and Object016d6b08 (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_OBJECT016CA768_H
#define TLG_GAME_OBJECT016CA768_H

#include "tlg_game_array.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object016d3ef8.h"
#include "tlg_game_object016d6b08.h"

/* derived names: the kinds of pool the classes below refer to; nothing of
 * them is traced but their base */
class Pool016ca768 : public Pool01343090 /* derived name */
{
};

class Pool016cab48 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16ca768
 * (config/vtables.derived.base.txt; its constructor FUN_013e34f0 stores
 * it), derived from Object016d3ef8. Its destructor 0x13e2310 gives up the
 * pool its reference at +0x228 holds (PoolRef01343090::shutdown(); the
 * constructor creates it with FUN_002054d0), then the members go last
 * first: the block of the array at +0x230 (three 4-byte elements reserved by
 * the constructor), the reference, the blocks of the arrays at +0xa8, +0x90
 * and +0x78, and the base's part inlined. Slot 0 of the vtable is the tail
 * call to it shared with eight derived classes (0x13e4950,
 * leaf_013e4950.cpp). The arrays' elements are not traced (nothing to
 * destroy); the rest is not traced. */
class Object016ca768 : public Object016d3ef8 /* derived name */
{
  public:
    virtual ~Object016ca768();

  private:
    u8 unknown34[0x44];
    Array05943280<u8> array78; /* +0x78 */
    Array05943280<u8> array90; /* +0x90 */
    Array05943280<u8> arraya8; /* +0xa8 */
    u8 unknownc0[0x168];
    PoolRef01343090<Pool016ca768> pool; /* +0x228 */
    Array05943280<u32> values230;       /* +0x230 */
};

/* derived names: the same form over Object016d6b08, its vtable at 0x16cab48
 * (config/vtables.derived.base.txt; stored by FUN_0147e1f0), its destructor
 * 0x147d810 the same bytes as 0x13e2310's but for the addresses, slot 0 the
 * tail call to it (0x147f020, leaf_0147f020.cpp) */
class Object016cab48 : public Object016d6b08 /* derived name */
{
  public:
    virtual ~Object016cab48();

  private:
    u8 unknown34[0x44];
    Array05943280<u8> array78; /* +0x78 */
    Array05943280<u8> array90; /* +0x90 */
    Array05943280<u8> arraya8; /* +0xa8 */
    u8 unknownc0[0x168];
    PoolRef01343090<Pool016cab48> pool; /* +0x228 */
    Array05943280<u32> values230;       /* +0x230 */
};

#endif
