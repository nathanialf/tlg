/* src/include/tlg_game_array.h: the game's growable array. derived names
 * throughout. The block at +0x0 comes from the heaps of tlg_game_block.h;
 * the count at +0x8, the capacity at +0xc, and at +0x10 the index in
 * D_5943280 of the owner that gives a first block. An append that passes the
 * capacity grows it by half the count plus one, at most 4 MiB of elements a
 * step and 0x1fffffff elements in all (the 64-byte arrays step by 0x10000,
 * the 8-byte ones by 0x80000: 0x342e4c and 0x1b59fb), the block reallocated
 * by its own owner or first allocated by the array's. 103 appends of
 * counted references are this body (FUN_001b59d0 and its copies). */
#ifndef TLG_GAME_ARRAY_H
#define TLG_GAME_ARRAY_H

#include <new>

#include "tlg_types.h"
#include "tlg_game_block.h"

template <class T> class Array05943280 /* derived name */
{
  public:
    /* appends a copy of the value, growing the block first when it is full */
    void push(const T &value)
    {
        unsigned index = count++;
        if (count > capacity)
            grow(count);
        new (&data[index]) T(value);
    }

  private:
    /* the owner is read before the new capacity is stored (the base keeps
     * the load above the store, in the block of the growth) */
    void grow(unsigned size)
    {
        unsigned owner = allocator;
        unsigned step = size / 2 + 1;
        if (step > 0x400000 / sizeof(T))
            step = 0x400000 / sizeof(T);
        unsigned target = size + step;
        if (target > 0x1fffffff)
            target = 0x1fffffff;
        capacity = target;
        data = static_cast<T *>(reallocateBlock(data, target * sizeof(T), 8, owner));
    }

    T *data;            /* +0x0 */
    unsigned count;     /* +0x8 */
    unsigned capacity;  /* +0xc */
    unsigned allocator; /* +0x10 */
};

#endif
