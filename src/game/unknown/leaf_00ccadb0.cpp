/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_shared.h"

/* derived names: the class whose vtable is at 0x16b9280
 * (config/vtables.derived.base.txt), a 0x210-byte object made by
 * FUN_00cca460 (`mov edi, 0x210`, the vtable stored, the flags at +0x8 and
 * the blocks up to +0x210 cleared): flags at +0x8 whose bits 0x1, 0x8 and
 * 0x10 say whether the references at +0x150, +0x1b0 and +0x1f0 are dropped
 * first, and five references to shared objects. FUN_00ccadb0, slot 0, is
 * the complete destructor and FUN_00ccafc0, slot 1, the deleting one. The
 * destructor is the class's key function, so this file emits the vtable.
 * The other fields are not traced. */
class Object016b9280 /* derived name */
{
  public:
    virtual ~Object016b9280();

  private:
    u32 flags; /* +0x8 */
    u8 unknownc[0x64];
    SharedRef00901550<Shared00901550> shared70; /* +0x70 */
    u8 unknown78[0x98];
    SharedRef00901550<Shared00901550> shared110; /* +0x110 */
    u8 unknown118[0x38];
    SharedRef00901550<Shared00901550> shared150; /* +0x150 */
    u8 unknown158[0x58];
    SharedRef00901550<Shared00901550> shared1b0; /* +0x1b0 */
    u8 unknown1b8[0x38];
    SharedRef00901550<Shared00901550> shared1f0; /* +0x1f0 */
    u8 unknown1f8[0x18];
};

/* FUN_00ccadb0: the references at +0x70 and +0x110 dropped, the three the
 * flags name, then the members' own destructors, last first (the one at
 * +0x1f0 already dropped on either path, so its test of bit 0x10 is left
 * with no branch: `test al, 0x10` at 0xccaeb2) */
Object016b9280::~Object016b9280()
{
    shared70.reset();
    shared110.reset();
    if (flags & 0x1)
        shared150.reset();
    if (flags & 0x8)
        shared1b0.reset();
    if (flags & 0x10)
        shared1f0.reset();
}
