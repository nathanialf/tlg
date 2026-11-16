/* src/include/tlg_game_array01343a80.h: an array with its own spin lock
 * (game region; docs/TARGETS.md). derived names throughout. The block at
 * +0x0, the count at +0x8, the capacity at +0xc and the owner's index at
 * +0x10 are the growable array's (tlg_game_array.h); the word at +0x14 is
 * the creation lock's class (tlg_game_creation.h), right after the array's
 * fields, inside the array's last eight bytes: taken with the creation lock's
 * wait before an append (`xor eax, eax; lock cmpxchg [r15+0x24], r14d` at
 * 0x81a961, 0x9f5a31, 0x1331d51) and given back from 1 to 0 by
 * compare-and-swap when the holder is emptied (FUN_01343a80: three of them
 * at +0x10, +0x28 and +0x48 of the holder, 0x18 bytes each); constructed
 * free after the index's store at +0x10 (0x12adade, 0xc1acc0). */
#ifndef TLG_GAME_ARRAY01343A80_H
#define TLG_GAME_ARRAY01343A80_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_creation.h"

template <class T> class Array01343a80 : public Array05943280<T> /* derived name */
{
  public:
    Array01343a80() = default;

    /* a copy: the array's fields from the other's, the lock made free,
     * then the block made and the elements copied (0x8e3910: the lock's
     * release store at +0x14 after the four fields and before the
     * allocation; the byte count and the owner worked out before the block
     * is read, as resize() does: `mov eax, [rbx+0xc]; mov edx, [rbx+0x10];
     * mov rsi, [rbx]`; the count read again after it and at each element,
     * the other's block read once: `cmp dword [rbx+8], 0; je; mov rcx,
     * [r14]`) */
    Array01343a80(const Array01343a80 &other) : Array05943280<T>(other)
    {
        if (this->count) {
            const unsigned bytes = this->capacity * sizeof(T);
            Owner05943280 *first = D_5943280[this->allocator];
            this->data = static_cast<T *>(reallocateBlock(this->data, bytes, alignof(T), first));
            const T *values = other.data;
            for (unsigned i = 0; i < this->count; ++i)
                new (&this->data[i]) T(values[i]);
        }
    }

    Lock059458a4 lock; /* +0x14 */
};

#endif
