/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address five handler tables take (leas
 * at 0x525a9e in FUN_00525530, 0x58d497, 0xaef9a3, 0xbe7762, 0xc10c1b):
 * makes its argument the owner's current node; returns 0. One of the six
 * byte-identical copies of FUN_00583980. Handler unknown. */
int FUN_00c06380(Owner583950 *self, void *arg) /* derived name */
{
    self->select(arg);
    return 0;
}
