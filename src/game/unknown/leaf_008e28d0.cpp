/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16b0370
 * (config/vtables.derived.base.txt, stored by FUN_008e2730 FUN_008e28d0 FUN_008e29a0), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_008e28d0 tears them down
 * (the Name at +0x24, the record at +0x30); the rest are not traced. */
class Object016b0370 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b0370();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    u8 unknown28[0x8];
    /* +0x30: torn down by the destructor (`lea rdi, [rbx+0x30]; call FUN_0134f620`) */
    Object0134f620 record30;
};

/* derived name: the complete destructor: the records, last first, then the other members in reverse, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_008e29a0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b0370::~Object016b0370()
{
    FUN_0134f620(&record30);
}
