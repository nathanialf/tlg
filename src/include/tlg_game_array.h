/* src/include/tlg_game_array.h: the game's growable array. derived names
 * throughout. The block at +0x0 comes from the heaps of tlg_game_block.h;
 * the count at +0x8, the capacity at +0xc, and at +0x10 the index in
 * D_5943280 of the owner that gives a first block. An append that passes the
 * capacity grows it by half the count plus one, at most 4 MiB of elements a
 * step and 0x1fffffff elements in all (the 64-byte arrays step by 0x10000,
 * the 8-byte ones by 0x80000: 0x342e4c and 0x1b59fb), the block reallocated
 * by its own owner or first allocated by the array's. 103 appends of
 * counted references are this body (FUN_001b59d0 and its copies).
 * The block's release by site: an array of elements with no destructor
 * gives its block back through the release's own copy, FUN_00ebf3f0
 * (tlg_game_block.h; the destructor below). Its two exceptions found by
 * round 492C were the holders, not the arrays: Object016cd3c0 (+0xc0) and
 * Object016d2558 (+0x48) cost 300 and 280 at the unit stage with the call,
 * between the limits of 225 and 325, and the base's `jmp D2` rules the
 * hint out: each declares its destructor in its body (round 497C). The
 * base's base-object destructors (0x1382f90, 0x13ba2b0) hold exactly the
 * members the classes model.
 */
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
     * release of the block at +0x28). An array of elements with no
     * destructor gives its block back through the release's own copy,
     * FUN_00ebf3f0 (tlg_game_block.h), the trait the game's ChunkStack
     * tests too (tlg_game_chunkstack.h): at the unit stage that is a call,
     * so its holders' complete destructors stay cheap enough for their
     * deleting destructors to hold them (0x2a9970, 0x2a9fc0, 0x472110,
     * 0xbf0290, 0x13e40a0, 0x13ef0d0: arrays of 32-bit values and of
     * vectors); the link inlines the copy. Measured over the whole module
     * (round 485C): this form changes those six deleting destructors and no
     * matched row, where the call for the arrays of elements with a
     * destructor loses 275 matched rows: those hold the release in line. */
    ~Array05943280()
    {
        if (__has_trivial_destructor(T)) {
            FUN_00ebf3f0(data);
            return;
        }
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

    /* puts a copy of the value before the first element: an empty array
     * appends it, else the count is raised, the block grown when it is full
     * and the elements moved up one (FUN_006e0240, over floats: the bytes
     * moved worked out from the old count before it is raised, `lea r15d,
     * [rax*4]; inc eax`, the value read after the move and assigned, read
     * before the block: `mov eax, [r14]; mov rcx, [rbx]`) */
    void pushFront(const T &value) /* derived name */
    {
        if (count == 0) {
            push(value);
            return;
        }
        const unsigned size = count * unsigned(sizeof(T));
        ++count;
        if (count > capacity)
            grow(count);
        memmove(&data[1], &data[0], size);
        data[0] = value;
    }

    /* the count raised and the block grown when it is full, the new last
     * slot returned unconstructed for the caller's placement new (0x8e848a
     * to 0x8e8578: `lea eax, [rbx+1]; mov [r12+0xa0], eax; cmp eax,
     * [r12+0xa4]; jbe`, the growth, then the element's constructor in the
     * slot with no temporary) */
    T *append() /* derived name */
    {
        unsigned index = count++;
        if (count > capacity)
            grow(count);
        return &data[index];
    }

    /* appends a copy of the value, growing the block first when it is full,
     * and returns the new element's index (FUN_013dfb60: the old count kept
     * in r15d across the growth and the element's out-of-line copy
     * constructor, then returned) */
    unsigned add(const T &value) /* derived name */
    {
        unsigned index = count++;
        if (count > capacity)
            grow(count);
        new (&data[index]) T(value);
        return index;
    }

    /* appends a default element, growing the block first when it is full,
     * and returns its index (FUN_00ea4bf0: the old count kept in r14d, the
     * element's constructor's stores in the new slot, `mov eax, r14d`) */
    unsigned add() /* derived name */
    {
        unsigned index = count++;
        if (count > capacity)
            grow(count);
        new (&data[index]) T;
        return index;
    }

    /* appends `number` default elements, growing the block once when it is
     * too small (FUN_00220c10, over 0x70-byte elements: the old count kept
     * in ebx, `lea eax, [rbx+r15]` stored as the count, the growth, then
     * the constructors' loop counted down, the block read again at each
     * element) */
    void addDefault(unsigned number) /* derived name */
    {
        unsigned index = count;
        count += number;
        if (count > capacity)
            grow(count);
        for (; number; --number)
            new (&data[index++]) T;
    }

    /* appends copies of another array's elements: room made for both
     * counts first, then each element appended in turn, the other's count
     * read again and its block once (FUN_0136ae70 over ints and
     * FUN_01350e40 over vectors: `mov ecx, [r14+8]; mov eax, [r15+8]; add
     * eax, ecx; cmp [r15+0xc], eax; jae`, the reallocation, then `mov rbx,
     * [r14]` and the bytes left counted down, the append inlined). Over
     * Names and counted references the append stays a call (FUN_0134cea0
     * calling FUN_01344a20, FUN_013a6db0 calling FUN_0138e360): the
     * reference's copy raises its count out of line (tlg_game_node.h's
     * raiseReference), which makes the append cost 225 at stage 1, the
     * threshold; over Names the build still inlines it (cost 200) and
     * FUN_0134cea0 is not claimed. */
    void append(const Array05943280 &other) /* derived name */
    {
        reserve(count + other.count);
        for (const T *value = other.begin(), *last = other.end(); value != last; ++value)
            add(*value);
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

    /* appends a copy of the value unless an element equals it, growing the
     * block first when it is full (FUN_002db990, FUN_005a42c0 and three more
     * over counted references: the elements compared first, `cmp [rcx+rsi*8],
     * rdx; je` with the value read once, then the count raised, the growth
     * and the value read again for the copy). The new slot is the count read
     * after the search, the append's body written out here: the read is the
     * loop's own test of the count, which the rotated loop carries out as
     * one value from its guard and one from its latch, and the guard's,
     * known to be 0, becomes 0 (`xor r15d, r15d` before the search, `mov
     * r15d, eax` after it). Through a call of push() the append over
     * references is not inlined in the unit and the count is read once
     * (`test rbx, rbx`). */
    void addUnique(const T &value) /* derived name */
    {
        for (unsigned i = 0; i < count; ++i)
            if (data[i] == value)
                return;
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
     * count read again). The emptying is clear(size): over Names the
     * elements are released first, by the out-of-line FUN_01344d90
     * (FUN_00464d20, FUN_004bb5f0). Elements with a trivial copy go over
     * in one memcpy of the other's count as read first, the byte count
     * 32-bit (FUN_00cfa640, 12-byte elements: `shl r15d, 2; lea edx,
     * [r15+r15*2]`; FUN_00d417d0: `shl r14d, 2; mov rdx, r14`), the other's
     * block read before the array's own (`mov rsi, [r14]; mov rdi, [rbx +
     * 0xc8]`), the trait the destructor tests. */
    void operator=(const Array05943280 &other)
    {
        if (this == &other)
            return;
        unsigned size = other.count;
        clear(size);
        if (size) {
            count = size;
            const T *values = other.data;
            if (__has_trivial_copy(T)) {
                memcpy(data, values, size * unsigned(sizeof(T)));
                return;
            }
            for (unsigned i = 0; i < count; ++i)
                new (&data[i]) T(values[i]);
        }
    }

    /* sets the count: the array is emptied (its elements destroyed first
     * to last, as clear(size) does: FUN_013e71b0's lists each give their
     * block back in line before `mov [r15+8], 0`), the capacity made the
     * count exactly (the block reallocated when it differs) and, for a
     * count that is not zero, the count stored and the elements
     * default-constructed one by one. FUN_013fb000 (0x70-byte elements): `mov [rbx+8], 0; cmp
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
        for (unsigned i = 0; i < count; ++i)
            data[i].~T();
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
     * je; mov [r15+0xc], ebx; shl ebx, 3`, the reallocation). Not inlined
     * at stage 1 (cost 315 over counted references, threshold 225): about 40
     * sites call it with 0 (0xa7b920). Where every caller of one
     * instantiation passes 0, the link folds the 0 in and drops the argument:
     * FUN_00f2b550, called with no size by seven table functions
     * (FUN_00f27820). */
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
     * 0`, then the reallocation with `xor edx, edx` or `xor esi, esi`).
     * Declared inline: with the hint (threshold 325) the body over counted
     * references (cost 320) is inlined into the twenty holders' destructors
     * that the base shows with it (0xae7530, 0xaeae40, 0x57edc0: `mov
     * [r15+0x38], 0; cmp [r15+0x3c], 0; je; mov [r15+0x3c], 0`, 459 bytes),
     * whose deleting destructors then call them (28 bytes), where clear(0)
     * stays a call and the deleting destructor inlines the holder's. */
    inline void clear()
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

    /* the index of the first element equal to `key`, or -1, the elements
     * indexed unsigned (0x4b6fe0: `cmp [rdx+rcx*8], rbx; je; inc rcx; cmp
     * ecx, eax; jb`, the index kept in r15d, -1 before the search), where
     * find() indexes them through at(int) */
    template <class K> int indexOf(const K &key) const /* derived name */
    {
        for (unsigned i = 0; i < count; ++i)
            if (data[i] == key)
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

    /* the element at `index` destroyed and the ones after it moved down;
     * the source is the element's own address plus one (`lea rsi,
     * [rax+r15*8+8]` at 0xf7093f and 0x617b8f, formed from the 32-bit index
     * widened, not from index + 1), the block read again after the
     * destruction and before the count (0xf70934, 0x617b84) */
    void removeAt(unsigned index) /* derived name */
    {
        data[index].~T();
        memmove(&data[index], &data[index] + 1, (count - index - 1) * unsigned(sizeof(T)));
        --count;
    }

    /* every element whose object is `object` destroyed and the ones after
     * it moved down, the last first: the index a signed 64-bit count taken
     * from the int count (`movsxd r14, dword [rbx+0xc8]; test r14, r14;
     * jle` at 0xf70873), the element read at `[rax+r14*8-8]` and the
     * removal given the narrowed index (`mov r15d, r12d`); an int index
     * counted down from count - 1 stays 32-bit in the build. The count is
     * taken as an int first: the base widens it signed (`movsxd`), where the
     * unsigned count itself is widened with a plain `mov` */
    template <class U> void removeEvery(const U *object) /* derived name */
    {
        const int references = count;
        for (s64 i = references; i > 0; --i)
            if (data[i - 1].get() == object)
                removeAt(i - 1);
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

    /* the last `number` elements destroyed and the count lowered by it
     * (FUN_00c0a9f0, over floats: `sub ecx, eax` into the count) */
    void removeLast(unsigned number) /* derived name */
    {
        for (unsigned i = 0; i < number; ++i)
            data[count - 1 - i].~T();
        count -= number;
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

    T *begin()
    {
        return data;
    }

    const T *begin() const
    {
        return data;
    }

    T *end()
    {
        return data + count;
    }

    const T *end() const
    {
        return data + count;
    }

  protected:
    /* the fields of a copy of another array, its block not made yet: no
     * block, the count and the capacity the other's count, read once for
     * each, and the owner the calling thread's (0x8e3910 to 0x8e394f: `mov
     * qword [rbx], 0; mov eax, [r14+8]; mov [rbx+8], eax; mov eax, [r14+8];
     * mov [rbx+0xc], eax`, then the owner's index). The block is made and
     * the elements copied by the derived array once it has made its own
     * members (tlg_game_array01343a80.h). */
    Array05943280(const Array05943280 &other)
        : data(0), count(other.count), capacity(other.count),
          allocator(D_16dc090 ? D_16dc090->index : 0)
    {
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

  protected:
    T *data;            /* +0x0 */
    unsigned count;     /* +0x8 */
    unsigned capacity;  /* +0xc */
    unsigned allocator; /* +0x10 */
};

#endif
