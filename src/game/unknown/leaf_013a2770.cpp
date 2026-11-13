/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16d06d0
 * (config/vtables.derived.base.txt, stored by FUN_00c24000 FUN_013a2770 FUN_013a2840), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_013a2770 tears them down
 * (the Name at +0x24, the records at +0x50, +0x38); the rest are not traced. */
class Object016d06d0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d06d0();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    u8 unknown28[0x10];
    /* +0x38: torn down by the destructor (`lea rdi, [rbx+0x38]; call 0x134f620`) */
    Object0134f620 record38;
    /* +0x50: torn down by the destructor (`lea rdi, [rbx+0x50]; call 0x134f620`) */
    Object0134f620 record50;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_013a2840, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016d06d0::~Object016d06d0() {}
