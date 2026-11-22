/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3ef8.h"

/* derived names: the class whose vtable is at 0x16ca518
 * (config/vtables.derived.base.txt), derived from Object016d3ef8: slot 2 is
 * its own (FUN_013e1b20: the base's slot 2 alone, a tail call), slot 7
 * FUN_00fac240 (not traced); 0x16d4090 is derived from it, the rest the
 * base's. The class of 0x16ca5b8 (Object013e4a90's base, leaf_013e4a90.cpp)
 * and those of 0x16d48f0 and 0x16d4948 derived from it hold the same slot 2:
 * two bodies of one form the link folded, claimed from the lower vtable. Its
 * destructor is the implicit one (slots 0 and 1 hold the base's pair): slot 2
 * is the key function, so this file emits the vtable. */
class Object016ca518 : public Object016d3ef8 /* derived name */
{
  public:
    virtual void slot2(); /* derived name */
};

void Object016ca518::slot2()
{
    Object016d3ef8::slot2();
}
