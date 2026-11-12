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
    u8 unknown1708[0xa8];
    int unknown17b0; /* +0x17b0: cleared by FUN_00dad190 */
};

/* derived names: the token the source at +0x10 returns from its slot 8:
 * its type, then the 12 bytes the slots of 0x16bb0c0 from 153 copy after it
 * (`mov rax, [token+4]; mov edx, [token+0xc]`) */
struct TokenValue016bb0c0 { /* derived name */
    int unknown0;
    int unknown4;
    int unknown8;
};

struct Token016bb0c0 {        /* derived name */
    int type;                 /* +0x0 */
    TokenValue016bb0c0 value; /* +0x4 */
};

/* derived names: the compiler's source at +0x10: slots 4 and 6 return the
 * ints the events record, slot 8 the current token; the other slots and
 * the class are not traced */
class Source016bb0c0 /* derived name */
{
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4();
    virtual void slot5();
    virtual int slot6();
    virtual void slot7();
    virtual const Token016bb0c0 *slot8();
};

/* derived names: the compiler's listener at +0x18: slot 153 + k of
 * 0x16bb0c0 passes event k on to its slot 2 + k (`call [rax + 0x10 + 8k]`),
 * after its destructors in slots 0 and 1; the slots after event 104 are not
 * traced */
class Listener016bb0c0 /* derived name */
{
  public:
    virtual ~Listener016bb0c0();
    virtual void event0();
    virtual void event1();
    virtual void event2(); /* parameters not traced */
    virtual void event3();
    virtual void event4();
    virtual void event5();
    virtual void event6();
    virtual void event7();
    virtual void event8();
    virtual void event9();
    virtual void event10();
    virtual void event11();
    virtual void event12();
    virtual void event13();
    virtual void event14();
    virtual void event15();
    virtual void event16();
    virtual void event17();
    virtual void event18();
    virtual void event19();
    virtual void event20();
    virtual void event21();
    virtual void event22();
    virtual void event23(); /* parameters not traced */
    virtual void event24();
    virtual void event25(); /* parameters not traced */
    virtual void event26();
    virtual void event27();
    virtual void event28();
    virtual void event29();
    virtual void event30();
    virtual void event31();
    virtual void event32();
    virtual void event33();
    virtual void event34();
    virtual void event35();
    virtual void event36();
    virtual void event37(); /* parameters not traced */
    virtual void event38();
    virtual void event39(); /* parameters not traced */
    virtual void event40();
    virtual void event41();
    virtual void event42();
    virtual void event43();
    virtual void event44();
    virtual void event45();
    virtual void event46();
    virtual void event47(); /* parameters not traced */
    virtual void event48(); /* parameters not traced */
    virtual void event49(); /* parameters not traced */
    virtual void event50(); /* parameters not traced */
    virtual void event51();
    virtual void event52();
    virtual void event53(); /* parameters not traced */
    virtual void event54();
    virtual void event55();
    virtual void event56();
    virtual void event57();
    virtual void event58();
    virtual void event59();
    virtual void event60(); /* parameters not traced */
    virtual void event61();
    virtual void event62();
    virtual void event63();
    virtual void event64(); /* parameters not traced */
    virtual void event65();
    virtual void event66(); /* parameters not traced */
    virtual void event67();
    virtual void event68();
    virtual void event69();
    virtual void event70(); /* parameters not traced */
    virtual void event71();
    virtual void event72();
    virtual void event73();
    virtual void event74(); /* parameters not traced */
    virtual void event75();
    virtual void event76(); /* parameters not traced */
    virtual void event77();
    virtual void event78();
    virtual void event79();
    virtual void event80(); /* parameters not traced */
    virtual void event81();
    virtual void event82();
    virtual void event83(); /* parameters not traced */
    virtual void event84();
    virtual void event85();
    virtual void event86(); /* parameters not traced */
    virtual void event87();
    virtual void event88();
    virtual void event89();
    virtual void event90();
    virtual void event91();
    virtual void event92();
    virtual void event93();
    virtual void event94();
    virtual void event95();
    virtual void event96(); /* parameters not traced */
    virtual void event97();
    virtual void event98();
    virtual void event99();
    virtual void event100(); /* parameters not traced */
    virtual void event101(); /* parameters not traced */
    virtual void event102(); /* parameters not traced */
    virtual void event103();
    virtual void event104();
};

/* derived names: the 0x30-byte event the slots of 0x16bb0c0 from 153 pass
 * by value to FUN_00db5690 (which copies it into its log, its kinds 0x7f
 * and 0x80 handled apart): the event's kind (the slot's number less 153),
 * the two ints of the source's slots 4 and 6, the current token's type, then
 * its value: the token's value and the event's arguments (an int at +0x20
 * for kind 2, FUN_013c0490), built apart and copied in (the event without
 * arguments copies all 28 bytes of the value from a local: `vmovups` from
 * [rbp-0x50] and [rbp-0x44]) */
struct EventValue016bb0c0 {        /* derived name */
    TokenValue016bb0c0 tokenValue; /* +0x0 */
    int arguments[4];              /* +0xc */
};

struct Event016bb0c0 {        /* derived name */
    int kind;                 /* +0x0 */
    int unknown4;             /* +0x4: the source's slot 4 */
    int unknown8;             /* +0x8: the source's slot 6 */
    int unknownc;             /* +0xc: not written by the events seen */
    int tokenType;            /* +0x10 */
    EventValue016bb0c0 value; /* +0x14 */
};

/* derived names: a second stack of the compiler, of 16-byte entries (a
 * pointer and an int: FUN_00dadfd0 pushes one), in chunks of four from the
 * heap at +0x4d0, kept as the expressions are (pushExpression) */
struct Entry00dadfd0 { /* derived name */
    void *value;       /* +0x0 */
    int unknown8;      /* +0x8 */
};

struct EntryChunk00dadfd0 { /* derived name */
    Entry00dadfd0 entries[4];
    Entry00dadfd0 *start;     /* +0x40 */
    EntryChunk00dadfd0 *next; /* +0x48 */
    EntryChunk00dadfd0 *prev; /* +0x50 */
};

struct Compiler00da5b20 { /* derived name */
    u8 unknown0[0x10];
    Source016bb0c0 *source;     /* +0x10 */
    Listener016bb0c0 *listener; /* +0x18 */
    u8 unknown20[0x4b0];
    void *heap4d0; /* +0x4d0: the heap of the entries' chunks */
    u8 unknown4d8[0x60];
    EntryChunk00dadfd0 *entryChunk; /* +0x538: the chunk in use */
    Entry00dadfd0 *entryTop;        /* +0x540 */
    Entry00dadfd0 *entryFree;       /* +0x548 */
    u32 entryCount;                 /* +0x550 */
    u32 entryCapacity;              /* +0x554 */
    u8 unknown558[0x7870];
    FuncState00da5b20 *funcState; /* +0x7dc8 */
};

/* derived name: records the event (its body is not written); the slots of
 * 0x16bb0c0 from 153 pass it on to the listener when this returns nonzero
 * (`test eax, eax`) */
int FUN_00db5690(Compiler00da5b20 *self, Event016bb0c0 event);

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
