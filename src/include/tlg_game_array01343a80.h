/* src/include/tlg_game_array01343a80.h: an array with a state word (game
 * region; docs/TARGETS.md). derived names throughout. The block at +0x0, the
 * count at +0x8, the capacity at +0xc and the owner's index at +0x10 are the
 * growable array's (tlg_game_array.h); the int at +0x14 is put back from 1
 * to 0 by compare-and-swap when the holder is emptied (FUN_01343a80: three
 * of them at +0x10, +0x28 and +0x48 of the holder, 0x18 bytes each). */
#ifndef TLG_GAME_ARRAY01343A80_H
#define TLG_GAME_ARRAY01343A80_H

#include "tlg_types.h"
#include "tlg_game_node.h"

template <class T> class Array01343a80 /* derived name */
{
  public:
    /* empties the array and keeps its block: the elements destroyed first
     * to last, the array and the count read again at each one, then the
     * count cleared (0x1343ac0: `mov rax, [r14+0x28]; mov ebx, ebx; mov
     * r15, [rax+rbx*8]` ... `inc ebx; cmp ebx, [r14+0x30]; jb`, then `mov
     * [r14+0x30], 0`) */
    void removeAll() /* derived name */
    {
        for (unsigned i = 0; i < count; ++i)
            data[i].~T();
        count = 0;
    }

    /* the state put back from 1 to 0 (`mov eax, 1; lock cmpxchg [r14+0x24],
     * ecx` at 0x1343b6e, the value found not used) */
    void release() /* derived name */
    {
        compareAndSwap(&state, 1, 0);
    }

  private:
    T *data;            /* +0x0 */
    unsigned count;     /* +0x8 */
    unsigned capacity;  /* +0xc */
    unsigned allocator; /* +0x10 */
    int state;          /* +0x14 */
};

#endif
