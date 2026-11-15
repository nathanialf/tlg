/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the destructor of an object that holds counted references
 * at +0x88, +0x90, +0xc8: each dropped, the last declared first. A function of its own in
 * the executable (no vtable pointer is stored: not a virtual destructor).
 * The object's other members and the referenced class are not traced. */
class Value013d6ba0 : public Node00503fb0 /* derived name */
{
};

struct Object013d6ba0 { /* derived name */
    ~Object013d6ba0();

    u8 unknown0[0x88];
    Ref00503fb0<Value013d6ba0> unknown88; /* +0x88 */
    Ref00503fb0<Value013d6ba0> unknown90; /* +0x90 */
    u8 unknown98[0x30];
    Ref00503fb0<Value013d6ba0> unknownc8; /* +0xc8 */
};

Object013d6ba0::~Object013d6ba0() {}
