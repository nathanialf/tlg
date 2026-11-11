/* src/include/tlg_game_block.h: a block of the game's heaps and its release.
 * derived names throughout. A block carries a 16-byte header before it: a
 * tag byte, then at +0x2 the index of its owner in the table at 0x5943280. A
 * block tagged 10 whose owner is set goes back through slot 6 of the owner
 * with 1; any other goes to free. The release callback FUN_00ebf3f0
 * (leaf_00ebf3f0.cpp) is this body, and the destructors that own a block
 * inline it. */
#ifndef TLG_GAME_BLOCK_H
#define TLG_GAME_BLOCK_H

#include <stdlib.h>

#include "tlg_types.h"

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

inline void releaseBlock(void *block) /* derived name */
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

/* derived names: the class whose vtable is at 0x16d3868
 * (config/vtables.derived.base.txt): its destructor (FUN_013d2f90,
 * leaf_013d2f90.cpp) releases the block it holds at +0x18. Also a member at
 * +0x10 of the classes whose vtables are 0x16bf020 and 0x16c1e40. The other
 * members are not traced. */
class Object013d2f90 /* derived name */
{
  public:
    virtual ~Object013d2f90();

  private:
    u8 unknown8[0x10];
    void *unknown18; /* +0x18: owned block */
};

#endif
