/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
// NONMATCHING (the deleting destructor 0x137e550 only): an inline-cost margin: the base inlines the complete destructor into it, the module calls it.
#include "tlg_game_multibase.h"

/* derived names: what FUN_00953a30 adds to the class at 0x16b10c8 for the
 * class at 0x16b1168: a base with no virtual function, declared after it,
 * so it is destroyed first; the counted reference at +0x100 its only traced
 * field. */
struct State016b1168 /* derived name */
{
    u8 unknown48[0x100 - 0x48];
    Ref00503fb0<Object016b9108> unknown100; /* +0x100 */
};

/* derived names: the class whose vtable is at 0x16b1168
 * (config/vtables.derived.base.txt; stored by FUN_00953a30), slot 6 kept
 * from the class at 0x16b10c8. Its destructor (slot 0, 0x137e3b0) stores no
 * vptr of its own: its body and fields are empty, the reference is the
 * second base's, released before Class137ba70's bases (the base at +0x30's
 * vptr and reference, then the root class's); slot 1 (0x137e550) the
 * deleting destructor. The shape of the class at 0x16b1640
 * (leaf_01381860.cpp). */
class Object016b1168 : public Class16b10c8, public State016b1168 /* derived name */
{
  public:
    virtual ~Object016b1168();
};

Object016b1168::~Object016b1168() {}
