/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hksi_lua_setlocal (the name from its assertion messages): the n-th local
 * variable of the call ar describes set to the value popped from the
 * stack's top, its name returned (null and nothing popped without one or
 * with an empty frame); the call timed */
// NONMATCHING: the base loads the popped value's type and value before it stores the new top; the
// build stores the top first
// Round 560C, link-stage IR cut and compiled alone: with the popped value's type and value loaded
// before the top's store and the slot's two stores after it, the function is equal (127/127, the
// entry's registers too). Compiled in the module, `const HksObject value = s->top[-1]; --s->top;
// *slot = value;` keeps the copy on the stack (a canary and a 0x38 frame; 135 instructions):
// reverted.
const char *FUN_00db5b50(lua_State *s, const lua_Debug *ar, int n)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x12338436, "s != NULL", "hksi_lua_setlocal",
               "Parameter 's' must be a valid state pointer", HKS_VM_DEBUG_FILE, 968);
        __builtin_trap();
    }
    if (!(ar != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x23045657, "ar != NULL", "hksi_lua_setlocal",
               "Parameter 'ar' must be a valid lua_Debug pointer", HKS_VM_DEBUG_FILE, 969);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    const char *name = 0;
    if (argumentCount(s) > 0) {
        name = FUN_00ddb700(s, ar, n);
        if (name) {
            HksObject *slot = &(*frameBaseSlot(s, ar->i_ci))[n - 1];
            const HksObject *value = --s->top;
            slot->type = value->type;
            slot->value = value->value;
        }
    }
    return name;
}
