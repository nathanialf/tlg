/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_commandbuffer.h"
#include "tlg_sce_gnm.h"
#include "tlg_types.h"

/* derived names: slot 11 of the vtable at 0x16c3808 (its pointer at
 * 0x16c3870): FUN_01300e30 first; then, when the byte at +0x1c7c is set,
 * FUN_0132f9a0 for the member at +0xa0 and the byte at +0x1a18 shifted to
 * bit 3 of the modifier; then a dispatch of the three counts of thread
 * groups written into the command buffer at +0x60 when there is room for its
 * nine words, bit 0 of the word at +0x88 in the modifier's bit 0; then the
 * count of dispatches at +0x34 raised and the groups' product added to the
 * total at +0x3c. */
struct Member01302150 {  /* derived name */
    u8 unknown0[0x1978]; /* not traced */
};

struct Object01302150 { /* derived name */
    u8 unknown0[0x34];
    int dispatches; /* +0x34 */
    u8 unknown38[4];
    u32 groups; /* +0x3c */
    u8 unknown40[0x20];
    CommandBuffer01496a80 commands; /* +0x60 */
    u32 unknown88;                  /* +0x88: bit 0 */
    u8 unknown8c[0x14];
    Member01302150 memberA0; /* +0xa0: handed to FUN_0132f9a0 */
    u8 unknown1a18;          /* +0x1a18 */
    u8 unknown1a19[0x263];
    bool unknown1c7c; /* +0x1c7c */
};

void FUN_01300e30(Object01302150 *self);   /* derived name */
void FUN_0132f9a0(Member01302150 *member); /* derived name */

void FUN_01302150(Object01302150 *self, u32 groupsX, u32 groupsY, u32 groupsZ) /* derived name */
{
    FUN_01300e30(self);
    u32 modifier = 0;
    if (self->unknown1c7c) {
        FUN_0132f9a0(&self->memberA0);
        modifier = self->unknown1a18 << 3;
    }
    CommandBuffer01496a80 &commands = self->commands;
    if (commands.remaining() >= 9 || commands.reserve(&commands, 9, commands.userData)) {
        if (sceGnmDispatchDirect(commands.cursor, 9, groupsX, groupsY, groupsZ,
                                 (self->unknown88 & 1) | modifier) == 0)
            commands.cursor += 9;
    }
    ++self->dispatches;
    self->groups += groupsX * groupsY * groupsZ;
}
