/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
// NONMATCHING (the deleting destructor 0x1381a00 only): an inline-cost margin: the base inlines the complete destructor into it, the module calls it.
#include "tlg_game_multibase.h"

/* derived names: what FUN_0096a910 adds to the class at 0x16b15a0 for the
 * class at 0x16b1640: a base with no virtual function, declared after it,
 * so it is destroyed first; the counted reference at +0x170 its only traced
 * field. */
struct State016b1640 /* derived name */
{
    u8 unknown58[0x170 - 0x58];
    Ref00503fb0<Object016b9108> unknown170; /* +0x170 */
};

/* derived names: the class whose vtable is at 0x16b1640
 * (config/vtables.derived.base.txt; stored by FUN_0096a910), slot 6 kept
 * from the class at 0x16b15a0. Its destructor (slot 0, 0x1381860) stores no
 * vptr of its own: its body and fields are empty, the reference is the
 * second base's, released before Class137ba70's bases (the base at +0x30's
 * vptr and reference, then the root class's); slot 1 (0x1381a00) the
 * deleting destructor. */
class Object016b1640 : public Class16b15a0, public State016b1640 /* derived name */
{
  public:
    virtual ~Object016b1640();
};

Object016b1640::~Object016b1640() {}
