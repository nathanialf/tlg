/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: slot 8 of the vtables at 0x16bab08 and 0x16bae38 (their
 * pointers at 0x16bab58 and 0x16bae88): when the pointer at +0xd0 is set,
 * the counted reference at +0xd8 is emptied by compare-and-swap and the
 * pointer at +0xe8 cleared. Class and fields not traced further. */
struct Object00d731c0 /* derived name */
{
    u8 unknown0[0xd0];
    void *unknownd0;                          /* +0xd0 */
    AtomicRef0045c470<Object016b9108> heldd8; /* +0xd8 */
    u8 unknowne0[0x8];
    void *unknowne8; /* +0xe8 */
};

void FUN_00d731c0(Object00d731c0 *self) /* derived name */
{
    if (self->unknownd0) {
        self->heldd8.clear();
        self->unknowne8 = 0;
    }
}
