/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: a script C function (FUN_00ded030 passes it, lea at
 * 0xded03e): the object the value below the frame's base points to (the
 * function being run), when the type at its +0x30 is 8, gives its pointer at
 * +0x38 (else none); with it and the count of arguments (the frame's bytes
 * over 16, unsigned) calls FUN_00ded540, and a negative result
 * goes to FUN_00db3c80 with -100 before it is returned. The callees, the
 * type 8 object and the C function's own name are not traced. */
struct Function00ded4f0 { /* derived name */
    u8 unknown0[0x30];
    int type30; /* +0x30 */
    u8 unknown34[4];
    void *unknown38; /* +0x38 */
};

int FUN_00ded540(lua_State *state, void *pointer, unsigned long count); /* derived name */
void FUN_00db3c80(lua_State *state, int code);                          /* derived name */

int FUN_00ded4f0(lua_State *state) /* derived name */
{
    const Function00ded4f0 *function =
        static_cast<Function00ded4f0 *>(state->base[-1].value.pointer);
    void *pointer = 0;
    if ((function->type30 & 0xf) == 8)
        pointer = function->unknown38;
    unsigned long count =
        (unsigned long)((char *)state->top - (char *)state->base) / sizeof(HksObject);
    int result = FUN_00ded540(state, pointer, count);
    if (result < 0)
        FUN_00db3c80(state, -100);
    return result;
}
