/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node holding a node at +0x58 and a word of flags at
 * +0x84 whose bit 23 FUN_00589500 reads and writes. */
struct FlagNode589500 /* derived name */
{
    u8 unknown0[0x58];
    Node583950 *child58; /* +0x58 */
    u8 unknown60[0x24];
    unsigned unknown84 : 23; /* +0x84 */
    unsigned flag : 1;
    unsigned unknown84b : 8;
};

/* derived names: a handler whose address FUN_005f2b90 takes (lea at
 * 0x5f2f6f): while the owner's +0x1dc is set, adds its node's flag to the
 * owner's +0x1d8; sets the node's flag to whether +0x1d8 is set, dispatches
 * the node at +0x58 through the owner's handler table and restores +0x1d8;
 * returns 0. Handler unknown. */
int FUN_00589500(FrameOwner583950 *self, void *arg) /* derived name */
{
    FlagNode589500 *node = static_cast<FlagNode589500 *>(arg);
    const int saved = self->unknown1d8;
    int flag = saved;
    if (self->unknown1dc) {
        flag = saved | node->flag;
        self->unknown1d8 = flag;
    }
    if (flag == 0)
        node->flag = 0;
    else
        node->flag = 1;
    self->dispatch(node->child58);
    self->unknown1d8 = saved;
    return 0;
}
