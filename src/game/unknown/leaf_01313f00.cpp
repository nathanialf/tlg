/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_commandbuffer.h"
#include "tlg_sce_gnm.h"
#include "tlg_types.h"

/* derived names: slot 11 of the vtable at 0x16c39b8 (its pointer at
 * 0x16c3a20), the dispatch of FUN_01302150's class with its buffer at
 * +0x47c0: nothing for no groups across; else FUN_01313b00 and FUN_0132eb10
 * for the member at +0x4aa8 first, the dispatch written when there is room
 * for its nine words (the byte at +0x13029 in bit 3 of the modifier, bit 0
 * of the word at +0x47e8 in its bit 0); then, when the byte at +0x13005 is
 * set, the two-word packet 0xc0008500 written into the member's own buffer
 * and the bytes at +0x13005 and +0x13006 made 0 and 1; then the count of
 * dispatches at +0x34 raised and the groups' product added to the total at
 * +0x3c. */
struct Member01313f00 {              /* derived name */
    CommandBuffer01496a80 *commands; /* +0x0; the rest not traced */
};

struct Object01313f00 { /* derived name */
    u8 unknown0[0x34];
    int dispatches; /* +0x34 */
    u8 unknown38[4];
    u32 groups; /* +0x3c */
    u8 unknown40[0x4780];
    CommandBuffer01496a80 commands; /* +0x47c0 */
    u32 unknown47e8;                /* +0x47e8: bit 0 */
    u8 unknown47ec[0x2bc];
    Member01313f00 member4aa8; /* +0x4aa8 */
    u8 unknown4ab0[0xe555];
    u8 flags13005;     /* +0x13005: bit 0 tested */
    bool unknown13006; /* +0x13006 */
    u8 unknown13007[0x22];
    u8 unknown13029; /* +0x13029 */
};

void FUN_01313b00(Object01313f00 *self);   /* derived name */
void FUN_0132eb10(Member01313f00 *member); /* derived name */

// NONMATCHING: greedy's assignment: the modifier's `or` is tied to the masked word in r9d where the
// base ties it to the shifted byte in r14d and copies it to r9d, and the member's buffer pointer is
// loaded into r13 where the base uses r14; the rest equal.
void FUN_01313f00(Object01313f00 *self, u32 groupsX, u32 groupsY, u32 groupsZ) /* derived name */
{
    if (!groupsX)
        return;
    FUN_01313b00(self);
    FUN_0132eb10(&self->member4aa8);
    const u32 modifier = self->unknown13029 << 3;
    CommandBuffer01496a80 &commands = self->commands;
    if (commands.remaining() >= 9 || commands.reserve(&commands, 9, commands.userData)) {
        if (sceGnmDispatchDirect(commands.cursor, 9, groupsX, groupsY, groupsZ,
                                 (self->unknown47e8 & 1) | modifier) == 0)
            commands.cursor += 9;
    }
    if (self->flags13005 & 1) {
        CommandBuffer01496a80 &member = *self->member4aa8.commands;
        if (member.remaining() >= 2 || member.reserve(&member, 2, member.userData)) {
            *reinterpret_cast<u64 *>(member.cursor) = 0xc0008500;
            member.cursor += 2;
        }
        self->flags13005 = 0;
        self->unknown13006 = true;
    }
    ++self->dispatches;
    self->groups += groupsX * groupsY * groupsZ;
}
