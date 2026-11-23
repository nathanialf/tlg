/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_dispatcher00c644d0.h"
#include "tlg_game_object016a7620.h"

/* derived names: the record the pointer at 0x5938c40 holds. */
struct Object05938c40 {
    u8 unknown0[0xd0];
    Dispatcher00c644d0 *unknownd0; /* +0xd0 */
};

extern Object05938c40 *D_5938c40;

/* derived names: three names posted to the dispatcher, which is read
 * before the names are copied (`mov rax, [rax+0xd0]` first) */
void FUN_00948040(const Name &a, const Name &b, const Name &c) /* derived name */
{
    D_5938c40->unknownd0->post(a, b, c);
}
