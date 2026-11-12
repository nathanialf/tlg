/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16cdbc8
 * (config/vtables.derived.base.txt, stored by FUN_009b55d0 FUN_013862f0 FUN_01386390), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_013862f0 tears them down
 * (the records at +0x58, +0x40); the rest are not traced. */
class Object016cdbc8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cdbc8();

  private:
    u8 unknown24[0x1c];
    /* +0x40: torn down by the destructor (`lea rdi, [rbx+0x40]; call FUN_0134f620`) */
    Object0134f620 record40;
    u8 unknown50[0x8];
    /* +0x58: torn down by the destructor (`lea rdi, [rbx+0x58]; call FUN_0134f620`) */
    Object0134f620 record58;
};

/* derived name: the complete destructor: the records, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_01386390, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016cdbc8::~Object016cdbc8()
{
    FUN_0134f620(&record58);
    FUN_0134f620(&record40);
}
