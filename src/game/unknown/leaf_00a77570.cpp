/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16b2388
 * (config/vtables.derived.base.txt, stored by FUN_00a773b0 FUN_00a77570), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_00a77570 tears them down
 * (the Names at +0x9c, +0x98, +0x94, the blocks at +0x128, +0x110); the rest are not traced. */
class Object016b2388 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b2388();

  private:
    u8 unknown24[0x70];
    Name name94; /* +0x94: released by the destructor (`mov eax, [rbx+0x94]; shl 5`) */
    Name name98; /* +0x98: released by the destructor (`mov eax, [rbx+0x98]; shl 5`) */
    Name name9c; /* +0x9c: released by the destructor (`mov eax, [rbx+0x9c]; shl 5`) */
    u8 unknowna0[0x70];
    /* +0x110: an owned block, released by the destructor (`mov rax, [rbx+0x110]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block110;
    u8 unknown118[0x10];
    /* +0x128: an owned block, released by the destructor (`mov rax, [rbx+0x128]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block128;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_00a77730, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b2388::~Object016b2388() {}
