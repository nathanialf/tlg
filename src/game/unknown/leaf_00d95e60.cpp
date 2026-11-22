/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: the call of the function below the frame's top nargs
 * values (FUN_00dd60c0, its body not written) */
void FUN_00dd60c0(lua_State *state, s64 nargs, int nresults, int unknown);

/* vm_call (the name from its assertion message), inlined: the function and
 * its arguments must be in the frame */
inline void vm_call(lua_State *s, int nargs, int nresults)
{
    if (!(argumentCount(s) >= nargs + 1)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xaaabbbce, "S_API_STACK_FRAMESIZE(s) >= nargs+1", "vm_call",
               "Parameters not passed", HKS_VM_CORE_INL_FILE, 38);
        __builtin_trap();
    }
    FUN_00dd60c0(s, nargs, nresults, 0);
}

/* hksi_lua_call (the name from its assertion message); the call timed */
void FUN_00d95e60(lua_State *s, int nargs, int nresults)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x991abc5, "s != NULL", "hksi_lua_call",
               "Parameter 's' must be a valid state pointer", HKS_VM_CORE_FILE, 818);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    vm_call(s, nargs, nresults);
}
