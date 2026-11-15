/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the destructor of an object that holds counted references
 * at +0x8, +0x70, +0x78: each dropped, the last declared first. A function of its own in
 * the executable (no vtable pointer is stored: not a virtual destructor).
 * The object's other members and the referenced class are not traced. */
class Value01365470 : public Node00503fb0 /* derived name */
{
};

struct Object01365470 { /* derived name */
    ~Object01365470();

    u8 unknown0[0x8];
    Ref00503fb0<Value01365470> unknown8; /* +0x8 */
    u8 unknown10[0x60];
    Ref00503fb0<Value01365470> unknown70; /* +0x70 */
    Ref00503fb0<Value01365470> unknown78; /* +0x78 */
};

Object01365470::~Object01365470() {}
