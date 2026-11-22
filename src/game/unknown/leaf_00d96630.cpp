/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hksi_lua_pushvfstring (the name from its assertion message, FUN_00dd44b0,
 * its body not written) */
const char *FUN_00dd44b0(lua_State *s, const char *format, va_list arguments);

/* hksi_lua_pushfstring (the name from its assertion message): the text
 * formatted and pushed; the call timed */
// NONMATCHING: register assignment only: the base keeps the mark in r12d and reads the stack guard's
// address again at the end (0xd967ca); the compile keeps the guard's address in r12 and spills the mark
const char *FUN_00d96630(lua_State *s, const char *format, ...)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1a01a376, "s != NULL", "hksi_lua_pushfstring",
               "Parameter 's' must be a valid state pointer", HKS_VM_CORE_FILE, 1170);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    va_list arguments;
    va_start(arguments, format);
    const char *text = FUN_00dd44b0(s, format, arguments);
    va_end(arguments);
    return text;
}
