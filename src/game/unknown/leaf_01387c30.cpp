/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16cd388
 * (config/vtables.derived.base.txt, stored by FUN_00991780 FUN_01387c30 FUN_01387d00), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_01387c30 tears them down
 * (the block at +0x50); the rest are not traced. */
class Object016cd388 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cd388();

  private:
    u8 unknown24[0x2c];
    /* +0x50: an owned block, released by the destructor (`mov rax, [rbx+0x50]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block50;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_01387d00, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016cd388::~Object016cd388() {}
