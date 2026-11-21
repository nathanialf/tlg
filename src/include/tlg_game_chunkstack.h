/* src/include/tlg_game_chunkstack.h: the script VM's stacks kept in chunks
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_CHUNKSTACK_H
#define TLG_GAME_CHUNKSTACK_H

#include "tlg_game_object013c8500.h"
#include "tlg_types.h"

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
    };

    HksState00dd1740 *heap; /* +0x0 */
    Chunk chunk0;           /* +0x8 */
    Chunk *first;
    Chunk *current;
    T *top;
    T *free;
    u32 count;
    u32 capacity;

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
