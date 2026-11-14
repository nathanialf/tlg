/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the subtitle system's state ended: when a subtitle is
 * shown (the int at +0x0) the script function "SubtitleSystem.CB_End" is
 * called with no arguments, the eight bytes at +0x0 and the ints at +0xc and
 * +0x10 are cleared and the int at +0x8 made -1; then, shown or not, the references at
 * +0x20 and +0x30 are emptied and the pointer at +0x28 cleared. The name of the
 * system is the string's; the fields are not traced. */
struct ScriptArgument00a2efa0; /* derived name */

/* derived names: calls the script function its name gives with count
 * arguments, its int result through the last pointer; nonzero on success. */
int FUN_00a2efa0(const char *name, int count, const ScriptArgument00a2efa0 *arguments, int *result);

/* the first eight bytes of the state, cleared as one (`mov qword [r14],
 * 0` at 0xb753fa) apart from the three ints behind them */
struct Shown00b753d0 { /* derived name */
    int unknown0;      /* +0x0: not zero while a subtitle is shown */
    int unknown4;      /* +0x4 */
};

struct SubtitleSystem00b753d0 { /* derived name */
    Shown00b753d0 shown;        /* +0x0 */
    int unknown8;               /* +0x8 */
    int unknownc;               /* +0xc */
    int unknown10;              /* +0x10 */
    u8 unknown14[0xc];
    AtomicRef0045c470<Node00503fb0> unknown20; /* +0x20 */
    void *unknown28;                           /* +0x28 */
    AtomicRef0045c470<Node00503fb0> unknown30; /* +0x30 */
};

void FUN_00b753d0(SubtitleSystem00b753d0 *self) /* derived name */
{
    if (self->shown.unknown0) {
        FUN_00a2efa0("SubtitleSystem.CB_End", 0, 0, 0);
        self->shown = Shown00b753d0();
        self->unknown8 = -1;
        self->unknownc = 0;
        self->unknown10 = 0;
    }
    self->unknown20.clear();
    self->unknown28 = 0;
    self->unknown30.clear();
}
