/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_math.h"

/* derived names: FUN_01005130 empties an array of 80-byte elements aligned on
 * 16 bytes, each holding a counted reference at +0x48, and gives its block
 * back (tlg_game_array.h's clear), out of line: the array's own member,
 * instantiated here until a caller of it is written. The element's other
 * members and the referenced class are not traced. */
class Value01005130 : public Node00503fb0 /* derived name */
{
};

struct Element01005130 { /* derived name */
    Float4A
        unknown0; /* +0x0: derived from the alignment alone (the block is asked for on 16 bytes) */
    u8 unknown10[0x38];
    Ref00503fb0<Value01005130> unknown48; /* +0x48 */
};

template void Array05943280<Element01005130>::clear();
