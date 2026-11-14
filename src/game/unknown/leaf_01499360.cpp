/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object05adaaa8.h"

/* derived names: passes the pointer at +0x10238 of the object the pointer at
 * 0x5adaaa8 holds, its second argument and the int the table at 0x1525560
 * holds at the index its third argument gives (unsigned: zero-extended) to
 * FUN_01305ce0, a tail call; slot 27 of the vtable at 0x16c39b8 (its pointer
 * at 0x16c3aa0), stored by FUN_0130c660 and FUN_0130dea0. The object itself is
 * not read. The table is the game's (declared; its content not claimed), and
 * the types of the callee's parameters beyond their widths are not traced. */
struct Object01499360; /* derived name */

extern const int D_1525560[];

void FUN_01305ce0(Member05adaaa8_10238 *member, void *argument, int value); /* derived name */

void FUN_01499360(Object01499360 *, void *argument, unsigned index) /* derived name */
{
    int value = D_1525560[index];
    FUN_01305ce0(D_5adaaa8->unknown10238, argument, value);
}
