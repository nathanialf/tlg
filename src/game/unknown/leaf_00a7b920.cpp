/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object0134a810.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b2430
 * (config/vtables.derived.base.txt, stored by FUN_00a7b670 and its two
 * destructors), derived from Object016b9108: its slots 2 to 4 are the
 * base's. Its own fields from +0x24 are traced only where its destructor
 * FUN_00a7b920 tears them down (the record at +0x60, the blocks at +0x78 and
 * +0x90, the Object0134a810 member at +0xf0 whose block is at +0x158); the
 * rest are not traced. */
class Object016b2430 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b2430();

  private:
    u8 unknown24[0x3c];
    /* +0x60: emptied by the destructor's body (`lea r14, [rbx+0x60]; xor esi, esi; call 0x138c8d0`), torn down last (`mov rdi, r14; call 0x134f620`) */
    Object0134f620 record60;
    u8 unknown70[0x8];
    /* +0x78: an owned block, released by the destructor (`mov rax, [rbx+0x78]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block78;
    u8 unknown80[0x10];
    /* +0x90: an owned block, released by the destructor (`mov rax, [rbx+0x90]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block90;
    u8 unknown98[0x58];
    /* +0xf0: destroyed first (`lea rax, [0x16c7338]; mov [rbx+0xf0], rax`, its block at +0x158 released) */
    Object0134a810 memberf0;
};

/* derived name: the complete destructor: the body empties the record at
 * +0x60 (FUN_0138c8d0 with 0); then the members are destroyed, last first
 * (the Object0134a810 at +0xf0 with its destructor inlined, the blocks at
 * +0x90 and +0x78, the record), then the base's destructor is inlined (its
 * vptr store, then the two names). FUN_00a7ba90, slot 1, is the deleting
 * one. The destructor is the class's key function, so this file emits the
 * vtable. */
Object016b2430::~Object016b2430()
{
    record60.FUN_0138c8d0(0);
}
