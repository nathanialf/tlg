/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_math.h"

/* derived names: the destructor (0x134aa10) and clear(unsigned) (0x134a8c0)
 * of an array of 0xd0-byte elements aligned on 16 bytes, each holding a
 * counted reference at +0xa8 and nothing else that needs destruction
 * (tlg_game_array.h), out of line: the array's own members, instantiated
 * here until a holder of the array is written. The element's other members
 * and the referenced class are not traced. */
class Value0134aa10 : public Node00503fb0 /* derived name */
{
};

struct Element0134aa10 { /* derived name */
    Float4A
        unknown0; /* +0x0: derived from the alignment alone (the block is asked for on 16 bytes) */
    u8 unknown10[0x98];
    Ref00503fb0<Value0134aa10> unknowna8; /* +0xa8 */
    u8 unknownb0[0x20];
};

template Array05943280<Element0134aa10>::~Array05943280();
template void Array05943280<Element0134aa10>::clear(unsigned);
