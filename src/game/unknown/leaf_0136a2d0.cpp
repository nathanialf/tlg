/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the destructor of a record without a vtable: its members
 * are destroyed from the last to the first, each a counted reference
 * dropped with its pointer cleared first. The callers show a destructor
 * (0x136a2d0 runs where a member, a local or an array's element is destroyed).
 * The record's other fields and the referenced objects' classes are not
 * traced. */
struct Object0136a2d0 /* derived name */
{
    ~Object0136a2d0();

    u8 unknown0[0xc8];
    Ref00503fb0<Node00503fb0> unknownc8; /* +0xc8 */
    u8 unknownd0[0xa8];
    Ref00503fb0<Node00503fb0> unknown178; /* +0x178 */
};

Object0136a2d0::~Object0136a2d0() {}
