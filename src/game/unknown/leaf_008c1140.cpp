/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b0178
 * (config/vtables.derived.base.txt, stored by FUN_008c0fe0 FUN_008c1140 FUN_008c1230 FUN_008c17c0), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slot 5 its own (declared; its body is not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_008c1140 tears them down
 * (the Names at +0x30, +0x2c); the rest are not traced. */
class Object016b0178 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b0178();
    virtual void slot5(); /* derived name; FUN_000042d0, not traced */

  private:
    u8 unknown24[0x8];
    Name name2c; /* +0x2c: released by the destructor (`mov eax, [rbx+0x2c]; shl 5`) */
    Name name30; /* +0x30: released by the destructor (`mov eax, [rbx+0x30]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_008c1230, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016b0178::~Object016b0178() {}
