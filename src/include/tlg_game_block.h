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
    u32 size;  /* +0x4: the block's size rounded to its alignment (FUN_00ca2540) */
    u32 total; /* +0x8: that size and the header's 16 bytes (FUN_00ca2540) */
    u8 unknownc[0x4];
};

class Owner05943280 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void *slot4(unsigned size, unsigned alignment,
                        int flags); /* derived name: an allocation */
    virtual void *slot5(void *block, unsigned size, unsigned alignment,
                        int flags); /* derived name: a reallocation of a block it gave */
    virtual void slot6(void *block, int value); /* derived name; not traced */

    u8 unknown8[0x10];
    unsigned index; /* +0x18: the owner's index in the table (0x12adad8: what a new array keeps) */
};

extern Owner05943280 *D_5943280[];

extern __thread Owner05943280 *D_16dc090; /* derived name: the calling thread's heap */

/* derived names: the calling thread's heap (the table's first when the
 * thread has none yet, kept from then on) replaced by another for a scope,
 * put back when the scope ends (FUN_00301db0 and FUN_003fcfb0: the new heap
 * is read before the thread's, as the constructor's argument) */
class ThreadHeapScope05943280
{
  public:
    explicit ThreadHeapScope05943280(Owner05943280 *heap)
    {
        saved = D_16dc090;
        if (!saved) {
            saved = D_5943280[0];
            D_16dc090 = saved;
        }
        D_16dc090 = heap;
    }

    ~ThreadHeapScope05943280()
    {
        D_16dc090 = saved;
    }

  private:
    Owner05943280 *saved;
};

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

/* derived name: a block grown or first allocated: an existing block goes
 * back to its own owner (slot 5); with none, the owner the caller looked up
 * gives a new one (slot 4). The caller indexes the table: at each growth site
 * the table's address is formed once above the block's null test and the
 * holder's index is read there (FUN_001b59d0: `lea rcx, [D_5943280]` at
 * 0x1b5a04, `mov edx, [rbx+0x10]` at 0x1b5a24 above `test rsi, rsi`), and
 * the entry itself is loaded only in the arm that allocates (`mov rdi,
 * [rcx+rdx*8]` at 0x1b5a4f); the other arm indexes the same table by the
 * header's owner (0x1b5a2c). */
inline void *reallocateBlock(void *block, unsigned size, unsigned alignment,
                             Owner05943280 *first) /* derived name */
{
    if (block) {
        const BlockHeader05943280 *header = static_cast<BlockHeader05943280 *>(block) - 1;
        return D_5943280[header->owner]->slot5(block, size, alignment, 1);
    }
    return first->slot4(size, alignment, 1);
}

/* derived name: the same where the block's owner is looked up with a
 * null default: an owner only for a header tagged 10, else null (0xce237d:
 * `movzx edx, byte [rsi-0x10]; xor edi, edi; cmp edx, 0xa; jne; movzx edx,
 * word [rsi-0xe]; mov rdi, [rcx+rdx*8]`, then slot 5 of what was found;
 * 312E counted 39 such sites). PROVISIONAL: a second spelling of the one
 * lookup the base has (`tag == 10 ? D_5943280[owner] : 0`, whose null arm
 * the compiler folds at 1,955 sites and keeps at 1,215: rounds 315E and
 * 321E); what splits the two is open (round 324E). Kept only so that
 * FUN_00ce22e0's row holds; to be removed when the split is explained, and
 * no other function uses it. */
inline void *reallocateOwnedBlock(void *block, unsigned size, unsigned alignment,
                                  Owner05943280 *first) /* derived name */
{
    if (block) {
        const BlockHeader05943280 *header = static_cast<BlockHeader05943280 *>(block) - 1;
        Owner05943280 *owner = 0;
        if (header->tag == 10)
            owner = D_5943280[header->owner];
        return owner->slot5(block, size, alignment, 1);
    }
    return first->slot4(size, alignment, 1);
}

/* derived name: a member that owns a block and releases it when its holder
 * is destroyed, after the members declared below it (FUN_013e4b40 releases
 * its block at +0x18 after the destructor of its member at +0x30). */
class OwnedBlock05943280
{
  public:
    ~OwnedBlock05943280()
    {
        releaseBlock(block);
    }

  private:
    void *block;
};

#endif
