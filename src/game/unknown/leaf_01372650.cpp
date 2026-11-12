/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16cc260
 * (config/vtables.derived.base.txt, stored by FUN_008785d0 FUN_01372650 FUN_01372760), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_01372650 tears them down
 * (the blocks at +0x40, +0x28, the record at +0x58); the rest are not traced. */
class Object016cc260 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cc260();

  private:
    u8 unknown24[0x4];
    /* +0x28: an owned block, released by the destructor (`mov rax, [rbx+0x28]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block28;
    u8 unknown30[0x10];
    /* +0x40: an owned block, released by the destructor (`mov rax, [rbx+0x40]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block40;
    u8 unknown48[0x10];
    /* +0x58: torn down by the destructor (`lea rdi, [rbx+0x58]; call 0x134f620`) */
    Object0134f620 record58;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_01372760, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016cc260::~Object016cc260() {}
