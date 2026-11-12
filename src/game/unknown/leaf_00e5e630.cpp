/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_sce_fios.h"

/* derived names: slot 14 of the vtable at 0x16bdc60 (its pointer at
 * 0x16bdce0), FUN_00e5e090's class, the read twin of slot 18
 * (FUN_00e5e6a0): reads length bytes of the file into buffer and returns the
 * count read, 0 for no buffer or no length and on an error, whose text is
 * dumped into a 0x40-byte local first. The object (this) is not read. Class
 * and method unknown. */
SceFiosSize FUN_00e5e630(void *, SceFiosFH fh, void *buffer, SceFiosSize length) /* derived name */
{
    if (buffer == 0 || length == 0)
        return 0;
    SceFiosSize read = sceFiosFHReadSync(0, fh, buffer, length);
    if (read < 0) {
        char message[0x40];
        sceFiosDebugDumpError(read, message, sizeof message);
    }
    return read < 0 ? 0 : read;
}
