/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bdc60.h"

/* derived names: slot 10 of the vtable at 0x16bdc60: the dates in seconds and
 * two of the flags of the name's path, 1 when its status is read; on an error
 * the information is cleared. */
int Object016bdc60::FUN_00e5ddc0(const char *name, FileInfo016bdc60 *info) const
{
    char path[0x400];
    makePath(path, sizeof(path), name);
    SceFiosStat stat;
    const int result = sceFiosStatSync(0, path, &stat);
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
    if (result < 0)
        memset(info, 0, sizeof *info);
    return 0;
}
