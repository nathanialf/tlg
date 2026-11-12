/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cad28
 * (config/vtables.derived.base.txt, stored by FUN_00429840 FUN_013509e0 FUN_01350aa0), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_013509e0 tears them down
 * (the Name at +0x24); the rest are not traced. */
class Object016cad28 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cad28();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_01350aa0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016cad28::~Object016cad28() {}
