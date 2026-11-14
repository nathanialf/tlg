/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the destructor of a record without a vtable: its members
 * are destroyed from the last to the first, each a counted reference
 * dropped with its pointer cleared first. The callers show a destructor
 * (0x13f7ea0 runs where a member, a local or an array's element is destroyed).
 * The record's other fields and the referenced objects' classes are not
 * traced. */
struct Object013f7ea0 /* derived name */
{
    ~Object013f7ea0();

    u8 unknown0[0x18];
    Ref00503fb0<Node00503fb0> unknown18; /* +0x18 */
    u8 unknown20[0xa8];
    Ref00503fb0<Node00503fb0> unknownc8; /* +0xc8 */
};

Object013f7ea0::~Object013f7ea0() {}
