/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16a9d18
 * (config/vtables.derived.base.txt, stored by FUN_00472640 FUN_00472d70 FUN_00472e10), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_00472d70 tears them down
 * (the records at +0x50, +0x28); the rest are not traced. */
class Object016a9d18 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a9d18();

  private:
    u8 unknown24[0x4];
    /* +0x28: torn down by the destructor (`lea rdi, [rbx+0x28]; call FUN_0134f620`) */
    Object0134f620 record28;
    u8 unknown38[0x18];
    /* +0x50: torn down by the destructor (`lea rdi, [rbx+0x50]; call FUN_0134f620`) */
    Object0134f620 record50;
};

/* derived name: the complete destructor: the records, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_00472e10, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a9d18::~Object016a9d18()
{
    FUN_0134f620(&record50);
    FUN_0134f620(&record28);
}
