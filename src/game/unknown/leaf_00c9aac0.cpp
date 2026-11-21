/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00c9aac0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_creation.h"

/* derived names: a table of 0x1000 objects by number at 0x593b140 under the
 * spin lock at 0x593b138, filled and emptied under the same lock by the
 * unwritten functions at 0xc99f90 and 0xc9b6e0 (their `lea` of the table at
 * 0xc9a091 and 0xc9b7f3); FUN_00c9aac0 reads one entry (the callers at
 * 0xba1e63 and 0xd2d708), none where the number is out of range. The
 * objects' class is not traced. */
struct Object0593b140; /* derived name */

extern Lock059458a4 D_593b138;            /* derived name */
extern Object0593b140 *D_593b140[0x1000]; /* derived name */

Object0593b140 *FUN_00c9aac0(u32 number) /* derived name */
{
    D_593b138.lock();
    Object0593b140 *object = number < 0x1000 ? D_593b140[number] : nullptr;
    D_593b138.unlock();
    return object;
}
