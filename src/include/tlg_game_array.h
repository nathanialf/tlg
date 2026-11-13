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
    /* the elements destroyed first to last, the array and the count read
     * again at each one, then the block released (0x1373420, an array of
     * Names at +0x28 of its holder: `mov r12, [r14+0x28]; mov ebx, ebx;
     * mov ecx, [r12+rbx*4]` ... `inc ebx; cmp ebx, eax; jb`, then the
     * release of the block at +0x28) */
    ~Array05943280()
    {
        for (unsigned i = 0; i < count; ++i)
            data[i].~T();
        releaseBlock(data);
    }

    /* appends a copy of the value, growing the block first when it is full */
    void push(const T &value)
    {
        unsigned index = count++;
        if (count > capacity)
            grow(count);
        new (&data[index]) T(value);
    }

    /* copies another array: the array is emptied, the capacity made the
     * other's count exactly and, for a count that is not zero, the count
     * stored and the elements copy-constructed one by one from the other's
     * block, read once (FUN_003431f0: `cmp rbx, r14; je`, `mov r15d,
     * [r14+8]; mov [rbx+8], 0`, the reallocation, `test r15d, r15d; je; mov
     * [rbx+8], r15d; xor ecx, ecx; mov rax, [r14]`, then the loop up to the
     * count read again). */
    void operator=(const Array05943280 &other)
    {
        if (this == &other)
            return;
        unsigned size = other.count;
        count = 0;
        if (capacity != size) {
            capacity = size;
            data = static_cast<T *>(
                reallocateBlock(data, size * sizeof(T), alignof(T), D_5943280[allocator]));
        }
        if (size) {
            count = size;
            const T *values = other.data;
            for (unsigned i = 0; i < count; ++i)
                new (&data[i]) T(values[i]);
        }
    }

    /* sets the count: the array is emptied, the capacity made the count
     * exactly (the block reallocated when it differs) and, for a count that
     * is not zero, the count stored and the elements default-constructed
     * one by one. FUN_013fb000 (0x70-byte elements): `mov [rbx+8], 0; cmp
     * [rbx+0xc], r14d; je`, the reallocation, `test r14d, r14d; je`, then
     * `mov [rbx+8], r14d` and the constructors' loop up to the count read
     * again. Over ints the loop is nothing and the caller clears them itself
     * (FUN_00a18a70: `test r14d, r14d; je; mov [rbx+0x90], r14d`, and on the
     * other path `cmp [rbx+0x90], 0` before its own loop). */
    void resize(unsigned size)
    {
        count = 0;
        if (capacity != size) {
            capacity = size;
            data = static_cast<T *>(
                reallocateBlock(data, size * sizeof(T), alignof(T), D_5943280[allocator]));
        }
        if (size) {
            count = size;
            for (unsigned i = 0; i < count; ++i)
                new (&data[i]) T;
        }
    }

    /* empties the array and makes the capacity `size` exactly: the elements
     * destroyed first to last, the array and the count read again at each
     * one, the count cleared, then the block reallocated where the capacity
     * differs (FUN_0138c8d0 over counted references: the loop of the
     * destructor, `mov ebx, [rbp-0x2c]; mov [r15+8], 0; cmp [r15+0xc], ebx;
     * je; mov [r15+0xc], ebx; shl ebx, 3`, the reallocation). Twenty
     * holders' destructors hold it inlined with 0 (0x57edc0: `mov
     * [r15+0x58], 0; cmp [r15+0x5c], 0; je; mov [r15+0x5c], 0`); 42 sites
     * call it with 0 (0xa7b920). */
    void clear(unsigned size)
    {
        for (unsigned i = 0; i < count; ++i)
            data[i].~T();
        count = 0;
        if (capacity != size) {
            capacity = size;
            data = static_cast<T *>(
                reallocateBlock(data, size * sizeof(T), alignof(T), D_5943280[allocator]));
        }
    }

    T &operator[](unsigned index)
    {
        return data[index];
    }

    /* makes room for `size` elements: a smaller capacity becomes the size
     * exactly and the block is reallocated (FUN_0134cdf0: `cmp [r15+0xc],
     * eax; jae`, then the capacity stored and the growth's reallocation) */
    void reserve(unsigned size)
    {
        if (capacity < size) {
            capacity = size;
            data = static_cast<T *>(
                reallocateBlock(data, size * sizeof(T), alignof(T), D_5943280[allocator]));
        }
    }

    unsigned size() const
    {
        return count;
    }

    const T *begin() const
    {
        return data;
    }

    const T *end() const
    {
        return data + count;
    }

  private:
    /* the capacity is stored first, then the block and the array's owner
     * are read for the reallocation (FUN_001b59d0: `mov [rbx+0xc], eax` at
     * 0x1b5a1b, then `mov rsi, [rbx]; mov edx, [rbx+0x10]`); the block is
     * aligned as its elements are (8 for the references, 16 for the 64-byte
     * elements at 0x342e8d) */
    void grow(unsigned size)
    {
        unsigned step = size / 2 + 1;
        if (step > 0x400000 / sizeof(T))
            step = 0x400000 / sizeof(T);
        unsigned target = size + step;
        if (target > 0x1fffffff)
            target = 0x1fffffff;
        capacity = target;
        data = static_cast<T *>(
            reallocateBlock(data, target * sizeof(T), alignof(T), D_5943280[allocator]));
    }

    T *data;            /* +0x0 */
    unsigned count;     /* +0x8 */
    unsigned capacity;  /* +0xc */
    unsigned allocator; /* +0x10 */
};

#endif
