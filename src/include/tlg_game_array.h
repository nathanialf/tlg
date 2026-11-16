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
#include "tlg_libc.h"
#include "tlg_game_block.h"

template <class T> class Array05943280 /* derived name */
{
  public:
    /* an empty array whose first block will come from the calling thread's
     * heap, or from the table's first owner on a thread that has none
     * (0x12adab9 to 0x12adadb and 0xc1ac94 to 0xc1acbd: the block, the count
     * and the capacity cleared in one 16-byte store, `mov rcx, [D_16dc090];
     * xor eax, eax; test rcx, rcx; je; mov eax, [rcx+0x18]`, the index
     * stored at +0x10) */
    Array05943280() : data(0), count(0), capacity(0), allocator(D_16dc090 ? D_16dc090->index : 0) {}

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

    /* appends a copy of the value unless an element equals it; the block
     * grows through the owner its header names (FUN_00ce22e0: the elements
     * compared first, `cmp [rax+rcx*8], r15; je`, then the count raised and
     * the growth's reallocation with the owner looked up with a null
     * default) */
    void pushUnique(T value) /* derived name */
    {
        if (contains(value))
            return;
        unsigned index = count++;
        if (count > capacity)
            growOwned(count);
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
     * other path `cmp [rbx+0x90], 0` before its own loop). The byte count
     * and the array's owner are worked out before the block is read (the
     * base's `lea eax, [r14*4]` before the table's `lea` at 0xa18aa4, and the
     * owner's index read before the block at 0x13d28c8 and 0x13fb338). */
    void resize(unsigned size)
    {
        count = 0;
        if (capacity != size) {
            capacity = size;
            const unsigned bytes = size * sizeof(T);
            Owner05943280 *first = D_5943280[allocator];
            data = static_cast<T *>(reallocateBlock(data, bytes, alignof(T), first));
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

    /* empties the array and gives its block back: the elements destroyed
     * first to last, the array and the count read again at each one, the
     * count cleared, then a capacity that is not zero cleared and the block
     * reallocated to no bytes (FUN_00326670 and its copies, one for each
     * element class: `mov [r14+8], 0; cmp [r14+0xc], 0; je; mov [r14+0xc],
     * 0`, then the reallocation with `xor edx, edx` or `xor esi, esi`) */
    void clear()
    {
        for (unsigned i = 0; i < count; ++i)
            data[i].~T();
        count = 0;
        if (capacity != 0) {
            capacity = 0;
            data = static_cast<T *>(reallocateBlock(data, 0, alignof(T), D_5943280[allocator]));
        }
    }

    /* empties the array and lets its block go: the count cleared, the
     * block released, then the pointer and the capacity cleared (ten arrays
     * of FUN_00fbe380's class, each `mov dword [r14+0x218], 0`, the release
     * of the block at +0x210, `mov qword [r14+0x210], 0; mov dword
     * [r14+0x21c], 0`). The arrays it is seen on have elements with no
     * destructor. */
    void freeBlock() /* derived name */
    {
        count = 0;
        releaseBlock(data);
        data = 0;
        capacity = 0;
    }

    /* the element at a signed index (`movsxd rcx, eax; shl rcx, 4` inside
     * the loops at 0xf1a990 and 0xfc56e0, whose counter is compared
     * unsigned) */
    const T &at(int index) const /* derived name */
    {
        return data[index];
    }

    /* the same of an array that is written through (0x231057: `movsxd rax,
     * r13d; imul rbx, rax, 0xe0` under `cmp r13d, eax; jb`) */
    T &at(int index) /* derived name */
    {
        return data[index];
    }

    /* the index of the first element equal to `key`, or -1 (`test eax,
     * eax; js` on the result at 0xf1a9a9) */
    template <class K> int find(const K &key) const /* derived name */
    {
        for (unsigned i = 0; i < count; ++i)
            if (at(i) == key)
                return i;
        return -1;
    }

    /* whether an element equals `key` (the elements indexed unsigned:
     * `cmp [rax+rcx*8], r15; je; inc rcx` at 0xce2320) */
    template <class K> bool contains(const K &key) const /* derived name */
    {
        for (unsigned i = 0; i < count; ++i)
            if (data[i] == key)
                return true;
        return false;
    }

    /* the element at `index` destroyed and the ones after it moved down
     * (0xf1a9ad to 0xf1a9ff: the size in 32 bits, `shl edx, 4; sub edx,
     * ebx`, and worked out before the two addresses: the source is a `lea`
     * of its own at 0xf1a9ef) */
    void removeAt(unsigned index) /* derived name */
    {
        data[index].~T();
        const unsigned size = (count - index - 1) * unsigned(sizeof(T));
        memmove(&data[index], &data[index + 1], size);
        --count;
    }

    /* the element at `index` replaced by the last one (assigned, unless it
     * is the last itself), the last one destroyed and the count lowered;
     * returns 1 when an element was moved, as an int (0x1351240 over references another
     * thread may replace: `mov eax, [r15+8]; dec eax; cmp eax, esi; jbe`,
     * the assignment's exchange, `mov r14d, 1`, then the last element's
     * release and `dec dword [r15+8]`) */
    int removeSwap(unsigned index) /* derived name */
    {
        int moved = 0;
        if (index < count - 1) {
            data[index] = data[count - 1];
            moved = 1;
        }
        data[count - 1].~T();
        --count;
        return moved;
    }

    /* every element destroyed and the count cleared, the block and the
     * capacity kept (0x1343a80, 0x13544e0) */
    void removeAll() /* derived name */
    {
        for (unsigned i = 0; i < count; ++i)
            data[i].~T();
        count = 0;
    }

    /* every element destroyed and the count cleared, then the block given
     * back and the block and the capacity cleared (0x1392310, a function of
     * its own over an array of counted references: `mov dword [r14+8], 0`,
     * the block's release, `mov qword [r14], 0; mov dword [r14+0xc], 0`) */
    void release() /* derived name */
    {
        for (unsigned i = 0; i < count; ++i)
            data[i].~T();
        count = 0;
        releaseBlock(data);
        data = 0;
        capacity = 0;
    }

    /* every element destroyed, first to last, the count and the block left
     * as they are: a function of its own over the 32-byte entries at +0x118
     * of two holders (0x13ceda0, called before the count is cleared at
     * 0xf3de6b and before the block is released at 0x13d2338) */
    void destroyElements() /* derived name */
    {
        for (unsigned i = 0; i < count; ++i)
            data[i].~T();
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
        step = step < unsigned(0x400000 / sizeof(T)) ? step : unsigned(0x400000 / sizeof(T));
        unsigned target = size + step;
        target = target < 0x1fffffffu ? target : 0x1fffffffu;
        capacity = target;
        data = static_cast<T *>(
            reallocateBlock(data, target * sizeof(T), alignof(T), D_5943280[allocator]));
    }

    /* grow() through reallocateOwnedBlock (provisional: see its comment;
     * pushUnique, FUN_00ce22e0, is its only user) */
    void growOwned(unsigned size) /* derived name */
    {
        unsigned step = size / 2 + 1;
        step = step < unsigned(0x400000 / sizeof(T)) ? step : unsigned(0x400000 / sizeof(T));
        unsigned target = size + step;
        target = target < 0x1fffffffu ? target : 0x1fffffffu;
        capacity = target;
        data = static_cast<T *>(
            reallocateOwnedBlock(data, target * sizeof(T), alignof(T), D_5943280[allocator]));
    }

    T *data;            /* +0x0 */
    unsigned count;     /* +0x8 */
    unsigned capacity;  /* +0xc */
    unsigned allocator; /* +0x10 */
};

#endif
