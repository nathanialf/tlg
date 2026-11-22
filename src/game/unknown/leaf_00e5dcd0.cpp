/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bdc60.h"

/* derived names: slot 9 of the vtable at 0x16bdc60: an open file's dates in
 * seconds and two of its flags, 1 when the status is read; on an error the
 * information is cleared and the error's text dumped into a 0x40-byte local.
 * The object (this) is not read. */
int Object016bdc60::FUN_00e5dcd0(SceFiosFH fh, FileInfo016bdc60 *info) const
{
    char message[0x40];
    SceFiosStat stat;
    const int result = sceFiosFHStatSync(0, fh, &stat);
    if (result == 0) {
        info->accessed = stat.accessDate / 1000000000;
        info->created = stat.creationDate / 1000000000;
        info->modified = stat.modificationDate / 1000000000;
        info->flags = 0;
        if (stat.statFlags & 2)
            info->flags |= 1;
        if (stat.statFlags & 4)
            info->flags |= 2;
        return 1;
    }
    if (result < 0) {
        memset(info, 0, sizeof *info);
        sceFiosDebugDumpError(result, message, sizeof message);
    }
    return 0;
}
