/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16b01b8
 * (config/vtables.derived.base.txt, stored by FUN_008c1320 FUN_008c14b0 FUN_008c1580), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_008c14b0 tears them down
 * (the Name at +0x40, the record at +0x28); the rest are not traced. */
class Object016b01b8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b01b8();

  private:
    u8 unknown24[0x4];
    /* +0x28: torn down by the destructor (`lea rdi, [rbx+0x28]; call 0x134f620`) */
    Object0134f620 record28;
    Name name40; /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_008c1580, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b01b8::~Object016b01b8() {}
