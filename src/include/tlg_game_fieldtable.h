/* src/include/tlg_game_fieldtable.h: fields of bits in words a component
 * of the type at 0x57ca3d0 holds, and the table at 0x57ca430 that
 * describes them (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_FIELDTABLE_H
#define TLG_GAME_FIELDTABLE_H

#include "tlg_game_node.h"

/* derived names: a field of bits in a word, its shift and its width */
struct BitField0057ca430 { /* derived name */
    int shift;
    int width;
};

/* derived names: the table's 40-byte records, each with its field at +0x18
 * (the static initializer FUN_0021c350 sets them) */
struct FieldRecord0057ca430 { /* derived name */
    u8 unknown0[0x18];
    BitField0057ca430 field; /* +0x18 */
    u8 unknown20[0x8];
};

extern FieldRecord0057ca430 D_57ca430[]; /* derived name */

/* the component's type (Object016a7870's, registered by leaf_002188b0.cpp) */
extern const Type00503fb0 *D_57ca3d0;

/* the object at +0x20 of a source: its words at +0x30 */
struct Table0057ca430 { /* derived name */
    u8 unknown0[0x30];
    unsigned *words; /* +0x30 */
};

struct Source0057ca430 { /* derived name */
    u8 unknown0[0x20];
    Table0057ca430 *table; /* +0x20 */
};

/* the object the component holds at +0x38: the words are its own at +0x50
 * unless a source at +0x38 is set and the mode at +0x40 is neither 1 nor
 * 2, the source's then (`dec; cmp 2; jae` at 0x7260d2 and 0x75e8f6) */
struct Words0057ca430 { /* derived name */
    u8 unknown0[0x38];
    Source0057ca430 *source; /* +0x38 */
    int mode;                /* +0x40 */
    u8 unknown44[0xc];
    unsigned *own; /* +0x50 */

    unsigned *words() const /* derived name */
    {
        return (!source || unsigned(mode - 1) < 2) ? own : source->table->words;
    }
};

/* the found component's view (Object016a7870's reference at +0x38) */
struct Fields0057ca430 { /* derived name */
    u8 unknown0[0x38];
    Words0057ca430 *held; /* +0x38 */
};

#endif
