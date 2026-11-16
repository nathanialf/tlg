/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the VM's "bufferReader" (the name from its assertion
 * message, vm-aux.cpp line 768), the reader FUN_00dd4dd0 passes to the
 * loader (lea at 0xdd5020): Lua's getS. The first call answers the whole
 * buffer and its size and empties the record; a later one answers null. The
 * state must not be null. */
struct HksBuffer /* derived name */
{
    const char *string; /* +0x0 */
    size_t size;        /* +0x8 */
};

const char *FUN_00dde6d0(lua_State *s, void *ud, size_t *size) /* derived name */
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x12633472, "s != NULL", "bufferReader",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 768);
        __builtin_trap();
    }
    HksBuffer *buffer = static_cast<HksBuffer *>(ud);
    if (buffer->size == 0)
        return 0;
    *size = buffer->size;
    buffer->size = 0;
    return buffer->string;
}
