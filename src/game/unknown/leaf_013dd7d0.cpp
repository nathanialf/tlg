/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the destructor of an object that holds counted references
 * at +0x0, +0x8, +0x10, +0x18: each dropped, the last declared first. A function of its own in
 * the executable (no vtable pointer is stored: not a virtual destructor).
 * The object's other members and the referenced class are not traced. */
class Value013dd7d0 : public Node00503fb0 /* derived name */
{
};

struct Object013dd7d0 { /* derived name */
    ~Object013dd7d0();

    Ref00503fb0<Value013dd7d0> unknown0;  /* +0x0 */
    Ref00503fb0<Value013dd7d0> unknown8;  /* +0x8 */
    Ref00503fb0<Value013dd7d0> unknown10; /* +0x10 */
    Ref00503fb0<Value013dd7d0> unknown18; /* +0x18 */
};

Object013dd7d0::~Object013dd7d0() {}
