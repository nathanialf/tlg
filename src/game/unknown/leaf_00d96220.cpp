/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hksi_lua_getupvalue (the name from its assertion message): the n-th
 * upvalue of the function at an index pushed and its name returned: a
 * script function's from its debug information ("(*stripped)" without
 * one), "" for a C function's; nothing pushed and null for an upvalue the
 * function lacks; the call timed */
const char *FUN_00d96220(lua_State *s, int funcindex, int n)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x23290136, "s != NULL", "hksi_lua_getupvalue",
               "Parameter 's' must be a valid state pointer", HKS_VM_DEBUG_FILE, 904);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    const char *name = 0;
    const HksObject *function = indexToHksObjectFast(s, funcindex);
    switch (function->type & 0xf) {
    case 10: {
        const HksCClosure *closure = static_cast<const HksCClosure *>(function->value.pointer);
        if (n > 0 && n <= closure->upvalueCount) {
            const HksObject *value = &closure->upvalues[n - 1];
            HksObject *top = s->top;
            *top = *value;
            s->top = top + 1;
            name = "";
        }
        break;
    }
    case 9: {
        const HksClosure *closure = static_cast<const HksClosure *>(function->value.pointer);
        const HksProto *proto = closure->proto;
        if (n > 0 && n <= proto->upvalueCount) {
            const HksObject *value = closure->upvalues[n - 1]->value;
            HksObject *top = s->top;
            *top = *value;
            s->top = top + 1;
            const HksDebugInfo *debugInfo = proto->debugInfo;
            name = debugInfo && debugInfo->upvalueNameCount ? debugInfo->upvalueNames[n - 1]->data
                                                            : "(*stripped)";
        }
        break;
    }
    }
    return name;
}
