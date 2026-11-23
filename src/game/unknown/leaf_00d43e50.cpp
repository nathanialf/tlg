/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_libc.h"

/* derived names: a named callback with an int (FUN_00c83870 registers
 * FUN_00c86230 under "lua" with 3, at 0xc84586) */
struct Callback00d43e50 { /* derived name */
    const char *name;     /* +0x0 */
    int kind;             /* +0x8 */
    void *function;       /* +0x10 */
};

/* derived name: the record at +0x38 of the object at 0x5938c40, whose
 * callbacks are at +0xc8 */
struct Registry00d43e50 {
    u8 unknown0[0xc8];
    Array05943280<Callback00d43e50> callbacks; /* +0xc8 */
};

/* derived names: registers a callback unless one of the same name is
 * there (the names compared with strcmp, the count read once before the
 * search: `mov ebx, [r12+0xd0]` serves the search and the append) */
void FUN_00d43e50(Registry00d43e50 *self, const char *name, int kind, void *function)
{
    const unsigned count = self->callbacks.size();
    for (unsigned i = 0; i < count; ++i)
        if (strcmp(name, self->callbacks.at(i).name) == 0)
            return;
    Callback00d43e50 callback = {name, kind, function};
    self->callbacks.push(callback);
}
