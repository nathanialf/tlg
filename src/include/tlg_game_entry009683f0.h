/* src/include/tlg_game_entry009683f0.h: an entry of the list at +0x50 of
 * Object016b1208 (leaf_009683f0.cpp, leaf_0092d740.cpp) (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_ENTRY009683F0_H
#define TLG_GAME_ENTRY009683F0_H

#include "tlg_types.h"

/* derived names: the node at +0x40 of an entry: its flags at +0x38 (bit 0
 * set by FUN_0092d740 before and after FUN_00d24260 empties it); the
 * rest is not traced */
struct Node0092d740 { /* derived name */
    u8 unknown0[0x38];
    int flags38; /* +0x38 */
};

/* derived names: the objects an entry holds at +0x68: slot 1 is called on
 * each, last first; not traced */
class Item0092d740 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
};

/* derived names: one 0x100-byte entry of Object016b1208's list at +0x50
 * (leaf_009683f0.cpp): the node at +0x40, the objects at +0x68 and their
 * count at +0x70, an int at +0xe0, the flags at +0xe4 (bit 5 once stopped,
 * bits 0 to 3 cleared on the way) and an int at +0xf0 */
struct Entry009683f0 { /* derived name */
    u8 unknown0[0x40];
    Node0092d740 *node; /* +0x40 */
    u8 unknown48[0x20];
    Item0092d740 **items; /* +0x68 */
    u32 count;            /* +0x70 */
    u8 unknown74[0x6c];
    int unknowne0; /* +0xe0 */
    u32 flags;     /* +0xe4 */
    u8 unknowne8[0x8];
    int unknownf0; /* +0xf0 */
    u8 unknownf4[0xc];
};

#endif
