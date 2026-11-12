/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16a7df0
 * (config/vtables.derived.base.txt, stored by FUN_002a9d20 FUN_002a9e40 FUN_002a9fc0), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_002a9e40 tears them down
 * (the Name at +0x24, the blocks at +0x60, +0x48, +0x30); the rest are not traced. */
class Object016a7df0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a7df0();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    u8 unknown28[0x8];
    /* +0x30: an owned block, released by the destructor (`mov rax, [rbx+0x30]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block30;
    u8 unknown38[0x10];
    /* +0x48: an owned block, released by the destructor (`mov rax, [rbx+0x48]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block48;
    u8 unknown50[0x10];
    /* +0x60: an owned block, released by the destructor (`mov rax, [rbx+0x60]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block60;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_002a9fc0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a7df0::~Object016a7df0() {}
