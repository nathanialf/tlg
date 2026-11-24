/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hksi_lua_setupvalue (the name from its assertion message): the stack's
 * top value popped into the n-th upvalue of the function at an index, the
 * collector's barrier passed for it, and the upvalue's name returned (as
 * hksi_lua_getupvalue names it); nothing set and null for an upvalue the
 * function lacks; the call timed */
// NONMATCHING: the base reads the popped value's two words before it stores the stack's top and
// stores the tag first (a copy split into its words); the build stores the top first, and the C
// function's barrier reads the popped slot again where the base keeps its address
// Round 560C, link-stage IR cut and compiled alone: case 9 is the base's with top - 1's type and
// value loaded first, then the upvalue and its value pointer, the top stored, the type and then the
// value stored (0.931 to 0.956); case 10's barrier is left (the base reads the type through r14 =
// top - 1, the build at [rax-16], a sunk address). The popped value copied whole into a local keeps
// it on the stack (as FUN_00db5b50): reverted.
const char *FUN_00db5d80(lua_State *s, int funcindex, int n)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x20039436, "s != NULL", "hksi_lua_setupvalue",
               "Parameter 's' must be a valid state pointer", HKS_VM_DEBUG_FILE, 997);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    if (!(argumentCount(s) >= 1)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xab100167, "hksi_lua_gettop(s) >= 1", "hksi_lua_setupvalue",
               "Insufficent objects on stack", HKS_VM_DEBUG_FILE, 1000);
        __builtin_trap();
    }
    const char *name = 0;
    const HksObject *function = indexToHksObjectFast(s, funcindex);
    switch (function->type & 0xf) {
    case 10: {
        HksCClosure *closure = static_cast<HksCClosure *>(function->value.pointer);
        if (n > 0 && n <= closure->upvalueCount) {
            HksObject *value = s->top - 1;
            closure->upvalues[n - 1] = *value;
            gcBarrier(s, reinterpret_cast<HksGcObject *>(closure), value);
            s->top = value;
            name = "";
        }
        break;
    }
    case 9: {
        const HksClosure *closure = static_cast<const HksClosure *>(function->value.pointer);
        const HksProto *proto = closure->proto;
        if (n > 0 && n <= proto->upvalueCount) {
            HksUpvalue *upvalue = closure->upvalues[n - 1];
            const HksObject *top = --s->top;
            HksObject *value = upvalue->value;
            value->value = top->value;
            value->type = top->type;
            gcBarrier(s, reinterpret_cast<HksGcObject *>(upvalue), upvalue->value);
            const HksDebugInfo *debugInfo = proto->debugInfo;
            name = debugInfo && debugInfo->upvalueNameCount ? debugInfo->upvalueNames[n - 1]->data
                                                            : "(*stripped)";
        }
        break;
    }
    }
    return name;
}
