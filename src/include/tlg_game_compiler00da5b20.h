/* src/include/tlg_game_compiler00da5b20.h: the script compiler's stack of
 * expressions (game region; docs/TARGETS.md), pushed by the slots of the
 * vtable at 0x16bb0c0 in src/game/unknown/leaf_00da5b20.cpp and its copies.
 * Every name here is derived. */
#ifndef TLG_GAME_COMPILER00DA5B20_H
#define TLG_GAME_COMPILER00DA5B20_H

#include "tlg_libc.h"
#include "tlg_types.h"

/* derived names: the script compiler's stack of 0x70-byte expressions in the
 * record its pointer at +0x7dc8 holds (the family of FUN_00dacb80, home
 * BytecodeReader.cpp; the expression on top at +0x16f0, as FUN_00da7a00
 * reads it): chunks of 0x380 bytes (eight expressions), each followed by its
 * start, the next chunk and the previous one, allocated from the pointer at
 * +0x1340 by FUN_013bd790 (size and an int tag 0x21), with the chunk in use
 * at +0x16e8, the next free expression at +0x16f8, the count at +0x1700 and
 * the capacity at +0x1704. */
struct ExpressionChunk00da5b20 { /* derived name */
    u8 expressions[0x380];
    u8 *start;                     /* +0x380 */
    ExpressionChunk00da5b20 *next; /* +0x388 */
    ExpressionChunk00da5b20 *prev; /* +0x390 */
};

struct FuncState00da5b20 { /* derived name */
    u8 unknown0[0x1340];
    void *heap; /* +0x1340 */
    u8 unknown1348[0x3a0];
    ExpressionChunk00da5b20 *chunk; /* +0x16e8 */
    u8 *top;                        /* +0x16f0 */
    u8 *free;                       /* +0x16f8 */
    u32 count;                      /* +0x1700 */
    u32 capacity;                   /* +0x1704 */
};

struct Compiler00da5b20 { /* derived name */
    u8 unknown0[0x7dc8];
    FuncState00da5b20 *funcState; /* +0x7dc8 */
};

void *FUN_013bd790(void *heap, size_t size, int tag); /* derived name */

/* derived name: pushes an expression of 0x70 bytes, the next free one
 * moving to the next chunk (allocated and linked after the one in use when
 * there is none) when the chunk is full */
static inline void pushExpression(FuncState00da5b20 *fs)
{
    fs->top = fs->free;
    fs->free += 0x70;
    ExpressionChunk00da5b20 *chunk = fs->chunk;
    if (fs->free >= chunk->start + sizeof(chunk->expressions)) {
        if (chunk->next) {
            fs->chunk = chunk->next;
        } else {
            ExpressionChunk00da5b20 *added = static_cast<ExpressionChunk00da5b20 *>(
                FUN_013bd790(fs->heap, sizeof(ExpressionChunk00da5b20), 0x21));
            ExpressionChunk00da5b20 *last = fs->chunk;
            added->start = added->expressions;
            added->next = 0;
            added->prev = last;
            last->next = added;
            fs->chunk = added;
            fs->capacity += 8;
        }
        fs->free = fs->chunk->start;
    }
    ++fs->count;
}

#endif
