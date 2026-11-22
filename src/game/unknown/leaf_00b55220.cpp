/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: a class derived from the root with no members of its own
 * and no slots of its own (its vtable, constructed by FUN_00b550b0, holds
 * the root's slots 2 to 4): its destructor, the class's key function, is
 * empty, so the root's destructor is all of it (the root's vptr store,
 * then the two names), and the deleting one (0xb552a0, slot 1) inlines it.
 * This file emits the vtable. */
class Object016b69f0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b69f0();
};

Object016b69f0::~Object016b69f0() {}
