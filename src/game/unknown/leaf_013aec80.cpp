/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: the destructor of an array of 24-byte elements, each a
 * counted reference at +0x0 and 16 bytes that need no destruction
 * (tlg_game_array.h: every reference dropped, the block given back), out of
 * line: the array's own member, instantiated here until a holder of the
 * array is written. The element's other members and the referenced class
 * are not traced. */
class Value013aec80 : public Node00503fb0 /* derived name */
{
};

struct Element013aec80 {                 /* derived name */
    Ref00503fb0<Value013aec80> unknown0; /* +0x0 */
    u8 unknown8[16];
};

template Array05943280<Element013aec80>::~Array05943280();
