/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: the VM's allocation of an object of a kind (0x1b for a
 * userdata; FUN_013bd0a0, its body not written) */
void *FUN_013bd0a0(lua_State *state, size_t size, int kind);

/* hksi_lua_newuserdata (the name from its assertion message): a userdata of
 * `size` bytes pushed, its environment the running function's (the
 * globals outside any call), linked first in the global's list; its value
 * returned; the call timed */
void *FUN_00dba890(lua_State *s, size_t size)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xf201298a, "s != NULL", "hksi_lua_newuserdata",
               "Parameter 's' must be a valid state pointer", HKS_VM_CORE_FILE, 1529);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    if (!(s->top < s->last)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xdbb05c0f, "S_STACK_NOT_FULL(s)", "hksi_lua_newuserdata", "API stack overflow",
               HKS_VM_CORE_FILE, 1535);
        __builtin_trap();
    }
    ++s->global->userdataCount;
    HksUserdata *userdata =
        static_cast<HksUserdata *>(FUN_013bd0a0(s, size + sizeof(HksUserdata), 0x1b));
    userdata->metatable = 0;
    void **environment;
    if (static_cast<int>(s->callInfo - s->callInfos) >= 0)
        environment = &static_cast<HksClosure *>(s->base[-1].value.pointer)->environment;
    else
        environment = &s->globalTable.value.pointer;
    userdata->environment = *environment;
    HksGlobal *global = s->global;
    userdata->next = global->userdata;
    global->userdata = userdata;
    HksObject *top = s->top;
    top->type = 7;
    top->value.pointer = userdata;
    s->top = top + 1;
    global = s->global;
    userdata->flags &= ~1ull;
    if (global->unknown198->next == userdata)
        global->unknown198 = userdata;
    return userdata + 1;
}
