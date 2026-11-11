/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: for a block that is not null, calls slot 6 of the owner the
 * table at 0x5943280 gives for the index at +0x2 of the 16-byte header before
 * the block, with the block and 1, a tail call; slot 3 of the vtable at
 * 0x16d3308 (its pointer at 0x16d3330), stored by FUN_00e99520. The object
 * itself is not read. The table is the game's object; the owner's class and
 * the return type are not traced. FUN_00911660 is the same call on its first
 * argument. */
/* The 16-byte header before a block the table at 0x5943280 types: a tag byte,
 * then at +0x2 the index of the block's owner in that table. derived names. */
struct BlockHeader05943280 { /* derived name */
    u8 tag;
    u8 unknown1;
    u16 owner;
    u8 unknown4[0xc];
};

class Owner05943280 /* derived name */
{
  public:
    virtual void slot0();                       /* derived name; not traced */
    virtual void slot1();                       /* derived name; not traced */
    virtual void slot2();                       /* derived name; not traced */
    virtual void slot3();                       /* derived name; not traced */
    virtual void slot4();                       /* derived name; not traced */
    virtual void slot5();                       /* derived name; not traced */
    virtual void slot6(void *block, int value); /* derived name; not traced */
};

extern Owner05943280 *D_5943280[];

struct Object013cbf80; /* derived name */

void FUN_013cbf80(Object013cbf80 *, void *block) /* derived name */
{
    if (block)
        D_5943280[(static_cast<BlockHeader05943280 *>(block) - 1)->owner]->slot6(block, 1);
}
