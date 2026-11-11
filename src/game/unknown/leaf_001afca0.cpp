/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <stdlib.h>

#include "tlg_types.h"

/* derived names: one of the four release functions of the 0x70-byte record at
 * 0x168c108 (its size, 0x70, at +0x0; the eight function pointers from
 * 0x168c118: four allocating functions, 0x1afa60 to 0x1afbe0, then the four
 * release functions; this one in the slot at 0x168c140; FUN_001afc60, FUN_001afce0, FUN_001afd20 have the
 * same body). For a block that is not null whose 16-byte header has the tag
 * 10, calls slot 6 of the owner the table at 0x5943280 gives for the index at
 * +0x2 of the header, with the block and 1, a tail call; any other block, or
 * one whose owner is null, goes to free. The header and the owner are
 * leaf_013cbf80.cpp's. */
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

void FUN_001afca0(void *block) /* derived name */
{
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
