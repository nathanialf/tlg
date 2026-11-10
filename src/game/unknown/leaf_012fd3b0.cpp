/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: maps the byte its argument points to: 4 gives 3, 2 gives 1,
 * anything else 0; called by FUN_001ada10. The meaning of the values is not
 * traced. */
// NONMATCHING: list-ilp order: the byte in ecx and the movzx of the sete placed before mov eax, 3 (the base: the byte in eax, the movzx after it)
int FUN_012fd3b0(const u8 *kind) /* derived name */
{
    if (*kind == 4) {
        return 3;
    }
    return *kind == 2;
}
