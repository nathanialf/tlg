/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_sce_fios.h"

/* derived names: slot 18 of the vtable at 0x16bdc60 (its pointer at
 * 0x16bdd00), FUN_00e5e090's class: writes length bytes of buffer to the
 * file and returns the count written, 0 on an error, whose text is dumped
 * into a 0x40-byte local first. The object (this) is not read. Class and
 * method unknown. */
SceFiosSize FUN_00e5e6a0(void *, SceFiosFH fh, const void *buffer,
                         SceFiosSize length) /* derived name */
{
    SceFiosSize written = sceFiosFHWriteSync(0, fh, buffer, length);
    if (written < 0) {
        char message[0x40];
        sceFiosDebugDumpError(written, message, sizeof message);
    }
    return written < 0 ? 0 : written;
}
