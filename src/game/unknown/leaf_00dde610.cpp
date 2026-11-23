/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the VM's "fileReader" (the name from its assertion
 * message, vm-aux.cpp line 695), Lua's getF over a file the record reaches
 * through +0x8: a pending extra line answers "\n" from the record's own
 * buffer (+0x10) once; then null at the file's end, else a read of up to
 * 0x800 bytes into the buffer, answered with its size (null for none). The
 * state must not be null. */
struct HksFile00dde610 { /* derived name */
    FILE *file;          /* +0x0 */
};

struct HksFileReader {     /* derived name */
    int extraLine;         /* +0x0 */
    HksFile00dde610 *file; /* +0x8 */
    char buffer[0x800];    /* +0x10 */
};

const char *FUN_00dde610(lua_State *s, void *ud, size_t *size) /* derived name */
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1e673432, "s != NULL", "fileReader", "Parameter 's' must be a valid state pointer",
               HKS_VM_AUX_FILE, 695);
        __builtin_trap();
    }
    HksFileReader *reader = static_cast<HksFileReader *>(ud);
    if (reader->extraLine) {
        reader->extraLine = 0;
        reader->buffer[0] = '\n';
        reader->buffer[1] = 0;
        *size = 1;
        return reader->buffer;
    }
    if (feof(reader->file->file))
        return 0;
    *size = fread(reader->buffer, 1, sizeof(reader->buffer), reader->file->file);
    return *size > 0 ? reader->buffer : 0;
}
