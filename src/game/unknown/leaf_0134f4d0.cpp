/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object016b9108.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16a9168 (config/vtables.derived.base.txt): it stores the vtable and releases
 * the block the pointer at +0x18 holds (tlg_game_block.h). The destructor is
 * the class's key function, so this file emits the vtable; the deleting one
 * is the compiler's. The other members are not traced. */
class Object0134f4d0 : public Counted00c14bc0 /* derived name */
{
  public:
    virtual ~Object0134f4d0();

  private:
    u8 unknownc[0xc];
    void *unknown18; /* +0x18: owned block */
};

Object0134f4d0::~Object0134f4d0()
{
    FUN_00ebf3f0(unknown18);
}
