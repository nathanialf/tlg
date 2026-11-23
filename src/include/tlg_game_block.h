/* src/include/tlg_game_block.h: a block of the game's heaps and its release.
 * derived names throughout. A block carries a 16-byte header before it: a
 * tag byte, then at +0x2 the index of its owner in the table at 0x5943280. A
 * block tagged 10 whose owner is set goes back through slot 6 of the owner
 * with 1; any other goes to free. The release has a copy of its own in the
 * executable, FUN_00ebf3f0 (leaf_00ebf3f0.cpp), which the destructors that
 * own a block call (below), as do the arrays of elements with no
 * destructor; the arrays of elements with one hold the body in line
 * (tlg_game_array.h). */
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

/* derived name: size bytes at the given alignment from the calling thread's
 * heap (the table's first when the thread has none yet, kept from then on),
 * through its slot 4 with 1; malloc when there is no heap; null for a size
 * of 0 (FUN_001afa60's body, inlined in 0xe5d2e0) */
inline void *allocateBlock(unsigned size, unsigned alignment)
{
    if (!size)
        return 0;
    Owner05943280 *heap = D_16dc090;
    if (!heap) {
        heap = D_5943280[0];
        D_16dc090 = heap;
        if (!heap)
            return malloc(size);
    }
    return heap->slot4(size, alignment, 1);
}

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

/* derived name: the release as a function of its own, the copy the
 * executable keeps at 0xebf3f0 (leaf_00ebf3f0.cpp; its address is stored at
 * 0x57ad998, and no call of it is left: the link inlines it at every site).
 * The body is releaseBlock's. Every release of a block outside the arrays
 * goes through it (round 474E, each form measured over the whole module):
 * the release is then a call at the unit stage, so
 * - a complete destructor that releases two blocks costs two calls and
 *   its deleting destructor holds it, as the base's do (0x6e14f0, 0x7b1fd0,
 *   0xa01cd0, 0xa7ba90, 0x13546c0, 0x1369d50, the six from 0x139f070 to
 *   0x13a02f0: 149 to 175 bytes each, where the inline body left a 28-byte
 *   call of the complete destructor; 0xd655d0, 0x13500e0, 0x13b2d70,
 *   0x13b93a0);
 * - a field read before the release is read again after it (the buffer's
 *   flags, `mov eax, [r14+0x34]; test al, 1` and the reload after the
 *   release: 0xbe6290, 0xd650e0, 0xe97590, 0x13b2c80, 0x13b92b0), and the
 *   release's own null test stays where the caller already proved the
 *   block (0x1350030's chain).
 * The release of an array of elements with a destructor (tlg_game_array.h)
 * is the inline body: the same call there loses 275 rows (round 485C); an
 * array of elements with none calls this. The deleting destructor of
 * a class with nine such members still calls its complete one (0x33cb30,
 * 28 bytes in the base). */
void FUN_00ebf3f0(void *block);

/* derived name: a member that owns a block and releases it when its holder
 * is destroyed, after the members declared below it (FUN_013e4b40 releases
 * its block at +0x18 after the destructor of its member at +0x30) */
class OwnedBlock05943280
{
  public:
    ~OwnedBlock05943280()
    {
        FUN_00ebf3f0(block);
    }

  private:
    void *block;
};

#endif
