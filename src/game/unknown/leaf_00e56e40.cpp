/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_game_shared.h"

/* derived names: the class whose vtable is at 0x16bd8e8
 * (config/vtables.derived.base.txt, stored by FUN_00e56c10), over
 * Object016b85e0: a shared object at +0x4d0 and sixteen names from +0x944.
 * Its complete destructor (0xe56e40; the deleting one 0xe56ef0) releases the
 * names last to first, drops the shared object, then runs the base's as a
 * tail call. The destructor is the class's key function, so this file emits
 * the vtable. The other fields are not traced. */
class Object016bd8e8 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016bd8e8();

  private:
    u8 unknown8[0x4c8];
    SharedRef00901550<Shared00901550> shared4d0; /* +0x4d0 */
    u8 unknown4d8[0x46c];
    Name names944[16]; /* +0x944 */
};

Object016bd8e8::~Object016bd8e8() {}
