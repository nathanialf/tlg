/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the slot at 0x16a7f10 of a vtable (no class yet), written as
 * a free function: false when the int at +0x2bc is 1; when the int at +0x280
 * is 0 and bit 3 of the byte at +0x284 is set, whether the int at +0x2b8 is
 * 1; otherwise whether the int at +0x258 is set. */
struct Object002b0f20 /* derived name */
{
    u8 unknown0[0x258];
    int unknown258; /* +0x258 */
    u8 unknown25c[0x24];
    int unknown280; /* +0x280 */
    u8 unknown284;  /* +0x284 */
    u8 unknown285[0x33];
    int unknown2b8; /* +0x2b8 */
    int unknown2bc; /* +0x2bc */
};

// NONMATCHING: FoldTwoEntryPHINode, the base keeps the result a phi of the constants 0
// and 1 (`mov eax, 1` before each branch to the return); here the compares fold to setcc.
bool FUN_002b0f20(const Object002b0f20 *self) /* derived name */
{
    if (self->unknown2bc == 1)
        return false;
    if (self->unknown280 == 0 && (self->unknown284 & 8)) {
        if (self->unknown2b8 == 1)
            return true;
    } else if (self->unknown258 != 0) {
        return true;
    }
    return false;
}
