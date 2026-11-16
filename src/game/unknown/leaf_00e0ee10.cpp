/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16bd768
 * (config/vtables.derived.base.txt, stored by FUN_00e0eb00 FUN_00e0ee10), derived
 * from Object016b9108: its slots 2 to 4 are the base's. Its own fields from
 * +0x24 are traced only where its destructor tears them down (the array of
 * counted references at +0x28); the rest are not traced. */
class Object016bd768 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016bd768();

  private:
    u8 unknown24[0x4];
    Object0134f620 references28; /* +0x28: emptied by the destructor's body */
};

/* derived name: the complete destructor: the references are dropped and
 * the count cleared in the body (the block kept), then the array's
 * destructor FUN_0134f620 runs out of line and the base's destructor is
 * inlined (its vptr store, then the two names). FUN_00e0ef90, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016bd768::~Object016bd768()
{
    references28.removeAll();
}
