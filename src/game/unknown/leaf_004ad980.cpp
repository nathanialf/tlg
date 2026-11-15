/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16aa040
 * (config/vtables.derived.base.txt, stored by FUN_004ad800), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's). Its own fields (from +0x34)
 * are not traced. */
class Object016aa040 : public Object01343880 /* derived name */
{
  public:
    virtual ~Object016aa040();
};

/* derived name: the complete destructor: the body is empty and the base's
 * destructor is inlined (its vptr store, then the two names). FUN_004ada00,
 * slot 1, is the deleting one. The destructor is the class's key function,
 * so this file emits the vtable. */
Object016aa040::~Object016aa040() {}
