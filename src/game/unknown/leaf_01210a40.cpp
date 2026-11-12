/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_record00f4dab0.h"

/* derived names: the class whose vtable is at 0x16c1eb8
 * (config/vtables.derived.base.txt, stored by FUN_011f8030), which owns a
 * Record00f4dab0 through +0x10. The other fields are not traced. */
class Object016c1eb8 /* derived name */
{
  public:
    virtual ~Object016c1eb8();

  private:
    u8 unknown8[8];
    Record00f4dab0 *record10; /* +0x10: owned */
};

/* derived name: the complete destructor: it deletes the record and clears
 * the pointer. FUN_01210ad0, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. */
Object016c1eb8::~Object016c1eb8()
{
    if (record10 != 0) {
        delete record10;
        record10 = 0;
    }
}
