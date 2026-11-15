/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_math.h"

/* derived names: FUN_01347370 empties an array of 96-byte elements aligned on
 * 16 bytes, each holding a counted reference at +0x58, and makes its
 * capacity the argument exactly (tlg_game_array.h's clear(unsigned)), out
 * of line: the array's own member, instantiated here until a caller of it
 * is written. The element's other members and the referenced class are not
 * traced. */
class Value01347370 : public Node00503fb0 /* derived name */
{
};

struct Element01347370 { /* derived name */
    Float4A
        unknown0; /* +0x0: derived from the alignment alone (the block is asked for on 16 bytes) */
    u8 unknown10[0x48];
    Ref00503fb0<Value01347370> unknown58; /* +0x58 */
};

template void Array05943280<Element01347370>::clear(unsigned);
