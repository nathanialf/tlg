/* src/include/tlg_game_chunkstack.h: the script VM's stacks kept in chunks
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_CHUNKSTACK_H
#define TLG_GAME_CHUNKSTACK_H

#include "tlg_game_object013c8500.h"
#include "tlg_libc.h"
#include "tlg_types.h"

void *FUN_013bd790(void *heap, size_t size, int tag); /* derived name */

/* derived names: a stack of elements in chunks of N, the first chunk inside
 * the stack and the others from its heap (tag 0x21), linked after it: each
 * chunk's elements, then their start, the next chunk and the one before
 * (the expressions' stack of tlg_game_compiler00da5b20.h is one, written
 * out there). The constructors (FUN_00db4100: the first chunk's start at
 * itself, the first and current chunk and the next free element at it, a
 * capacity of N) are not written. The destructor runs the elements'
 * destructors from the first chunk's start up to the next free element
 * (none when the stack is empty: `cmp [top], 0`), for elements that have
 * one (the stacks of plain entries and items keep no walk, the records'
 * stack of 0xda4250 an empty one), then gives the chunks after the first
 * back, the first chunk's next tested before the walk of them (0xda4250,
 * 0xdb4280) */
template <class T, int N> struct ChunkStack {
    struct Chunk {
        u8 elements[N * sizeof(T)];
        T *start;
        Chunk *next;
        Chunk *prev;

        Chunk() : start(reinterpret_cast<T *>(elements)), next(0), prev(0) {}
    };

    HksState00dd1740 *heap; /* +0x0 */
    Chunk chunk0;           /* +0x8 */
    Chunk *first;
    Chunk *current;
    T *top;
    T *free;
    u32 count;
    u32 capacity;

    /* derived name: an empty stack over a heap: every field cleared in
     * order, then the first chunk made the one in use (FUN_00db4100 is an
     * instance kept out of line) */
    explicit ChunkStack(HksState00dd1740 *heap)
        : heap(heap), first(0), current(0), top(0), free(0), count(0), capacity(0)
    {
        first = &chunk0;
        current = &chunk0;
        free = chunk0.start;
        capacity = N;
    }

    /* derived name: pushes an element, the next free one moving to the next
     * chunk (allocated and linked after the one in use when there is none)
     * when the chunk is full; returns the element pushed (the script
     * compiler's pushes, tlg_game_scriptcode.h) */
    T *push()
    {
        T *element = free;
        top = element;
        free = element + 1;
        Chunk *chunk = current;
        if (free >= chunk->start + N) {
            if (chunk->next) {
                current = chunk->next;
            } else {
                Chunk *added = static_cast<Chunk *>(FUN_013bd790(heap, sizeof(Chunk), 0x21));
                Chunk *last = current;
                added->start = reinterpret_cast<T *>(added->elements);
                added->next = 0;
                added->prev = last;
                last->next = added;
                current = added;
                capacity += N;
            }
            free = current->start;
        }
        ++count;
        return element;
    }

    /* derived name: pushes a copy of a value: the value copied into the
     * next free element before it is pushed */
    void push(const T &value)
    {
        *free = value;
        push();
    }

    /* derived name: the element at an index, found in the chunk in use when
     * the index falls in the chunk the count falls in, else by walking from
     * the first chunk */
    T &at(u32 index)
    {
        u32 chunkIndex = index / N;
        u32 slot = index % N;
        if (count / N == chunkIndex)
            return current->start[slot];
        Chunk *chunk = first;
        for (u32 i = 0; i < chunkIndex; ++i)
            chunk = chunk->next;
        return chunk->start[slot];
    }

    ~ChunkStack()
    {
        if (!__has_trivial_destructor(T) && top) {
            Chunk *chunk = first;
            T *element = chunk->start;
            while (element) {
                element->~T();
                if (element == chunk->start + (N - 1)) {
                    chunk = chunk->next;
                    element = chunk ? chunk->start : 0;
                } else
                    ++element;
                if (element == free) {
                    element = 0;
                    chunk = 0;
                }
            }
        }
        if (Chunk *chunk = first->next) {
            do {
                Chunk *next = chunk->next;
                externalFree(heap, chunk, sizeof(Chunk), 0x21);
                chunk = next;
            } while (chunk);
        }
    }
};

#endif
