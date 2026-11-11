/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <stdlib.h>

#include "tlg_types.h"

/* derived names: the complete destructor of a record holding one block
 * pointer at +0x0, registered with __cxa_atexit for the globals FUN_0082f0e0
 * (0x581bdc8 among them) and FUN_00c15880 initialize: releases the block as
 * the release functions of the record at 0x168c108 do (leaf_001afc60.cpp):
 * for a block that is not null whose 16-byte header has the tag 10, slot 6 of
 * the owner the table at 0x5943280 gives for the index at +0x2 of the header,
 * with the block and 1, a tail call; any other block, or one whose owner is
 * null, goes to free. Written as a free function on the record, as the
 * region's other complete destructors of globals are. */
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

struct Object01370420 /* derived name */
{
    void *unknown0; /* +0x0: the block it releases */
};

void FUN_01370420(Object01370420 *self) /* derived name */
{
    void *block = self->unknown0;
    if (!block)
        return;
    const BlockHeader05943280 *header = static_cast<BlockHeader05943280 *>(block) - 1;
    if (header->tag == 10) {
        Owner05943280 *owner = D_5943280[header->owner];
        if (owner) {
            owner->slot6(block, 1);
            return;
        }
    }
    free(block);
}
