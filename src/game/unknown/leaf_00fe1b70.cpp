/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_links00c63970.h"

/* FUN_00fe1b70: three names posted to the dispatcher the pointer at 0x59396d0
 * holds, read before the names are copied (`mov rax, [0x59396d0]` first, as
 * FUN_00948040 reads the one at +0xd0 of the object at 0x5938c40) */
void FUN_00fe1b70(const Name &first, const Name &second, const Name &third) /* derived name */
{
    D_59396d0->post(first, second, third);
}
