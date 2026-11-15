/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b6058
 * (config/vtables.derived.base.txt, stored by FUN_00b44ae0), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's). Its own fields (from +0x34)
 * are not traced. */
class Object016b6058 : public Object01343880 /* derived name */
{
  public:
    virtual ~Object016b6058();
};

/* derived name: the complete destructor: the body is empty and the base's
 * destructor is inlined (its vptr store, then the two names). FUN_00b44ce0,
 * slot 1, is the deleting one. The destructor is the class's key function,
 * so this file emits the vtable. */
Object016b6058::~Object016b6058() {}
