/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_speed.h"

/* derived names: a node of the kind FUN_00596a00 is given: bit 0 of its
 * flags at +0x28 skips it, the mode and the children FUN_00c0f8b0 runs, and
 * the speed at +0x48 their answer sets */
struct SpeedNode00596a00 { /* derived name */
    u8 unknown0[0x28];
    u8 flags; /* +0x28 */
    u8 unknown29[3];
    int mode;              /* +0x2c */
    Node583950 **children; /* +0x30 */
    unsigned count;        /* +0x38 */
    u8 unknown3c[0xc];
    float speed; /* +0x48 */
};

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x525868): the node made the current one and its state byte read (no
 * check for a node not in the list); a state of 0 becomes 1, and in either
 * state, unless bit 0 of the node's flags is set, the fourth of the game's
 * speeds becomes the node's speed when its children answer, else 1, and
 * the state is left at +0xd8. Returns 0. Handler unknown. */
int FUN_00596a00(Owner583950 *self, SpeedNode00596a00 *node) /* derived name */
{
    u8 *state = self->selectState(node);
    switch (*state) {
    case 0:
        *state = 1;
    case 1:
        if (!(node->flags & 1)) {
            float speed =
                self->runChildren(node->mode, node->children, node->count) ? node->speed : 1.0f;
            D_57c9390->setSpeed(3, speed);
            self->unknownd8 = *state;
        }
        break;
    }
    return 0;
}
