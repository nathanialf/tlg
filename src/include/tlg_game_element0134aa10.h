/* src/include/tlg_game_element0134aa10.h: the 0xd0-byte element of the array
 * that 0x134aa10 destroys and 0x134a8c0 clears (game region;
 * docs/TARGETS.md), and the class its counted reference names. Every name
 * here is derived. */
#ifndef TLG_GAME_ELEMENT0134AA10_H
#define TLG_GAME_ELEMENT0134AA10_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_math.h"

class Value0134aa10 : public Object016b9108 /* derived name */
{
};

/* derived names: aligned on 16 bytes, holding a counted reference at +0xa8
 * and nothing else that needs destruction. The other members and the
 * referenced class are not traced. */
struct Element0134aa10 { /* derived name */
    Float4A
        unknown0; /* +0x0: derived from the alignment alone (the block is asked for on 16 bytes) */
    u8 unknown10[0x98];
    Ref00503fb0<Value0134aa10> unknowna8; /* +0xa8 */
    u8 unknownb0[0x20];
};

#endif
