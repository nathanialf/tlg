/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks_string.h"

/* hksi_hks_setfname (the name from its assertion message): the function on
 * the stack's top given a name: a C function's own, a script function's in
 * its code's debug information (which must be there), the collector's
 * barrier passed for the object that keeps it; the call timed */
// NONMATCHING: needs FUN_00dc6090's body in the module (the base reuses the name's word across the
// stores into the function, as when that callee does not capture the value: measured with a scratch
// stub), and the base reloads the stack guard's address at the end where the build keeps it in r15
void FUN_00db6800(lua_State *s, const char *name)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x13f384b6, "s != NULL", "hksi_hks_setfname",
               "Parameter 's' must be a valid state pointer", HKS_VM_DEBUG_FILE, 1219);
        __builtin_trap();
    }
    if (!(name != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x13f384b7, "name != NULL", "hksi_hks_setfname",
               "Parameter 'name' must be a valid C string", HKS_VM_DEBUG_FILE, 1220);
        __builtin_trap();
    }
    if (!(hksi_lua_type(s, -1) == 6)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x13f384b8, "hksi_lua_type(s, -1) == LUA_TFUNCTION", "hksi_hks_setfname",
               "There must be a function on the top of the stack.", HKS_VM_DEBUG_FILE, 1221);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    pushString(s, name);
    const HksObject string = s->top[-1];
    const HksObject function = s->top[-2];
    HksGcObject *parent;
    if (typeAt(s, -2) == 10) {
        HksCClosure *closure = static_cast<HksCClosure *>(function.value.pointer);
        closure->name = static_cast<HksString *>(string.value.pointer);
        parent = reinterpret_cast<HksGcObject *>(closure);
    } else {
        HksProto *method = static_cast<HksClosure *>(function.value.pointer)->proto;
        HksDebugInfo *debugInfo = method->debugInfo;
        if (!(debugInfo != 0)) {
            printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
                   "%s() : \"%s\"\n\tat %s(%d)\n",
                   0xfa110009, "(method->m_debug != NULL)", "hksi_hks_setfname",
                   "Cannot set name of a function whose debug information has been stripped",
                   HKS_VM_DEBUG_FILE, 1242);
            __builtin_trap();
        }
        debugInfo->name = static_cast<HksString *>(string.value.pointer);
        parent = reinterpret_cast<HksGcObject *>(method);
    }
    gcBarrier(s, parent, &string);
    pop(s, 1);
}
