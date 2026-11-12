/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b83b8
 * (config/vtables.derived.base.txt, stored by FUN_00c250f0), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields (from
 * +0x24) are not traced. */
class Object016b83b8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b83b8();
};

/* derived name: the complete destructor: the body is empty and the base's
 * destructor is inlined (its vptr store, then the two names). FUN_00c252d0,
 * slot 1, is the deleting one. The destructor is the class's key function,
 * so this file emits the vtable. */
Object016b83b8::~Object016b83b8() {}
