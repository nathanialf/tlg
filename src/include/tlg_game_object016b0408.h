/* src/include/tlg_game_object016b0408.h: the class whose vtable is at 0x16b0408
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B0408_H
#define TLG_GAME_OBJECT016B0408_H

#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object016b9108.h"

/* derived names: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016b0408 : public Pool01343090 /* derived name */
{
};

/* derived name: an element of the first two arrays below: 12 bytes aligned
 * to 4 (the constructor reserves four, `mov edx, 0x30; mov ecx, 4`, and
 * clears each word); not traced */
struct Element016b0408 { /* derived name */
    u32 unknown0[3];
};

/* derived names: the class whose vtable is at 0x16b0408
 * (config/vtables.derived.base.txt, stored by FUN_008e3e00 FUN_008e4270), 0xb0 bytes
 * (`mov edi, 0xb0` before operator new in its creator FUN_008e3ca0),
 * derived from Object016b9108 (its constructor 0x8e3e00 first calls 0xcb6310, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016b0408 : public Object016b9108 /* derived name */
{
  public:
    Object016b0408(const Name &name); /* 0x8e3e00, its row named after it (D15) */
    virtual ~Object016b0408();
    virtual void slot5(); /* derived name; FUN_008e45a0, an empty body */

  private:
    u8 unknown24[0x4];
    PoolRef01343090<Pool016b0408> pool; /* +0x28 */
    u8 unknown30[0x20];
    /* four reserved by the constructor, 0x18 bytes apart */
    Array05943280<Element016b0408> elements50; /* +0x50 */
    Array05943280<Element016b0408> elements68; /* +0x68 */
    Array05943280<u32> values80;               /* +0x80 */
    Array05943280<u32> values98;               /* +0x98 */
};

#endif
