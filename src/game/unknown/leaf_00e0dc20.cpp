/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16bd668
 * (config/vtables.derived.base.txt, stored by FUN_00e0d940 FUN_00e0dc20 FUN_00e0dd10), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_00e0dc20 tears them down
 * (the Names at +0x28, +0x24); the rest are not traced. */
class Object016bd668 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016bd668();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    Name name28; /* +0x28: released by the destructor (`mov eax, [rbx+0x28]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_00e0dd10, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016bd668::~Object016bd668() {}
