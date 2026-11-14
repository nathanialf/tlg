/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the destructor of a record without a vtable: its members
 * are destroyed from the last to the first, each a counted reference
 * dropped with its pointer cleared first. The callers show a destructor
 * (0x1382e60 runs where a member, a local or an array's element is destroyed).
 * The record's other fields and the referenced objects' classes are not
 * traced. */
struct Object01382e60 /* derived name */
{
    ~Object01382e60();

    u8 unknown0[0x8];
    Ref00503fb0<Node00503fb0> unknown8;  /* +0x8 */
    Ref00503fb0<Node00503fb0> unknown10; /* +0x10 */
};

Object01382e60::~Object01382e60() {}
