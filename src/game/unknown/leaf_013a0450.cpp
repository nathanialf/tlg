/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16d0300
 * (config/vtables.derived.base.txt, stored by FUN_00bfa840 FUN_00bfb1c0 FUN_00bfbb40 and 17 more), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_013a0450 tears them down
 * (the block at +0x28); the rest are not traced. */
class Object016d0300 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d0300();

  private:
    u8 unknown24[0x4];
    /* +0x28: an owned block, released by the destructor (`mov rax, [rbx+0x28]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block28;
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_013a0520, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016d0300::~Object016d0300() {}
