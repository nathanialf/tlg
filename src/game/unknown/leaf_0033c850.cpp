/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16a86d8
 * (config/vtables.derived.base.txt, stored by FUN_0033c780 FUN_0033c850), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_0033c850 tears them down
 * (the blocks at +0x408, +0x398, +0x328, +0x2b8, +0x248, +0x1d8, +0x168, +0xf8, +0x88); the rest are not traced. */
class Object016a86d8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a86d8();

  private:
    u8 unknown24[0x64];
    /* +0x88: an owned block, released by the destructor (`mov rax, [rbx+0x88]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block88;
    u8 unknown90[0x68];
    /* +0xf8: an owned block, released by the destructor (`mov rax, [rbx+0xf8]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 blockf8;
    u8 unknown100[0x68];
    /* +0x168: an owned block, released by the destructor (`mov rax, [rbx+0x168]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block168;
    u8 unknown170[0x68];
    /* +0x1d8: an owned block, released by the destructor (`mov rax, [rbx+0x1d8]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block1d8;
    u8 unknown1e0[0x68];
    /* +0x248: an owned block, released by the destructor (`mov rax, [rbx+0x248]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block248;
    u8 unknown250[0x68];
    /* +0x2b8: an owned block, released by the destructor (`mov rax, [rbx+0x2b8]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block2b8;
    u8 unknown2c0[0x68];
    /* +0x328: an owned block, released by the destructor (`mov rax, [rbx+0x328]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block328;
    u8 unknown330[0x68];
    /* +0x398: an owned block, released by the destructor (`mov rax, [rbx+0x398]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block398;
    u8 unknown3a0[0x68];
    /* +0x408: an owned block, released by the destructor (`mov rax, [rbx+0x408]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block408;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_0033cb30, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a86d8::~Object016a86d8() {}
