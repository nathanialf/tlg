/* src/include/tlg_game_object016ba190.h: the class whose vtable is at
 * 0x16ba190 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BA190_H
#define TLG_GAME_OBJECT016BA190_H

#include "tlg_game_name.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16ba190
 * (config/vtables.derived.base.txt, stored by FUN_00d23490 FUN_00d237d0),
 * derived from Object01343880: its constructor calls Object016b9108's with
 * the name, clears +0x28 and +0x30 and only then stores its vptr
 * (0xd234c3, 0xd234cb, 0xd234d5), as the classes over Object01343880 do;
 * slots 5 and 6 are 0x58a0 and 0x1343880. Its objects come from a pool of
 * 0x108-byte blocks, not from operator new (FUN_00d1fb50: a free block's
 * link at +0x100, the class's last word). The pools of
 * tlg_game_object013d35e0.h derive from it (0x204080: 0x540 bytes,
 * `call 0xd23490` at 0x204188). */
class Object016ba190 : public Object01343880 /* derived name */
{
  public:
    Object016ba190(const Name &name); /* FUN_00d23490 */
    virtual ~Object016ba190();

    u8 unknown34[0x14];
    /* +0x48: zero from the constructor (0xd2356c); a pool's constructor
     * makes it 16 (0x20418d), and its holders 16 less the pool's bit 1 at
     * +0x100 before they close the pool (0x325f1a) */
    int unknown48;
    u8 unknown4c[0xb4];
    unsigned unknown100; /* +0x100: not set by the constructor */
    u8 unknown104[0x4];
};

/* derived name: takes a block from the class's pool under the pool's own
 * spin lock (0x5948194), growing the pool by an allocation of count times
 * size plus 0x10 bytes when it is empty; the block's next link is at +0x100 */
void *FUN_00d1fb50();

#endif
