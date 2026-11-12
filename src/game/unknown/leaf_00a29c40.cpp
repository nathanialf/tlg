/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b1c88
 * (config/vtables.derived.base.txt, stored by FUN_00a28440), derived from
 * Object016b9108: its slots 2 to 4 are the base's. One instance exists at a
 * time: D_5827308 names it (stored at 0xa29bdb, read at 0xa28602 and
 * 0xa29c0a) and its destructor clears the pointer. Its own fields from
 * +0x24 are not traced. */
class Object016b1c88 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b1c88();
};

extern Object016b1c88 *D_5827308;

/* derived name: the complete destructor: the body clears the instance
 * pointer (`mov qword [0x5827308], 0`, between the base vptr's `lea` and its
 * store: the class's own vptr store is dead); no member has a destructor;
 * then the base's destructor is inlined (its vptr store, then the two
 * names). FUN_00a29cd0, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. */
Object016b1c88::~Object016b1c88()
{
    D_5827308 = 0;
}
