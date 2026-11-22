/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hksi_luaL_error (the name from its assertion message, FUN_00d9cfb0, its
 * body not written) */
int FUN_00d9cfb0(lua_State *s, const char *format, ...);

/* hksi_lua_yield (the name from its assertion message): a running thread
 * (status 2) outside a metamethod or C call that is not the main state
 * suspended (status 3), the frame's values moved down to its base; an error
 * otherwise. The count is the frame's, read before the timer; `nresults` is
 * not read. The call timed. */
int FUN_00ded070(lua_State *s, int nresults)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xf211238a, "s != NULL", "hksi_lua_yield",
               "Parameter 's' must be a valid state pointer", HKS_VM_CORE_FILE, 1726);
        __builtin_trap();
    }
    const int count = argumentCount(s);
    HksApiTimer timer(s);
    if (s->status == 3) {
        FUN_00d9cfb0(s, "attempt to yield a yielded coroutine");
    } else if (s->status == 2) {
        if (s->unknown98 >= 2) {
            FUN_00d9cfb0(s, "attempt to yield across metamethod/C-call boundary");
        } else if (s->global->mainThread == s) {
            FUN_00d9cfb0(s, "You cannot yield the main state");
        } else {
            for (int i = 0; i < count; ++i)
                s->base[i] = (s->top - count)[i];
            s->top = s->base + count;
            s->status = 3;
        }
    } else {
        FUN_00d9cfb0(s, "attempt to yield a paused coroutine");
    }
    return -234325;
}
