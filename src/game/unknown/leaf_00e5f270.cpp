/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bdc60.h"

/* derived names: slot 22 of the vtable at 0x16bdc60: whether a directory
 * exists at the name's path. */
int Object016bdc60::FUN_00e5f270(const char *name) const
{
    char path[0x400];
    makePath(path, sizeof(path), name);
    return sceFiosDirectoryExistsSync(0, path);
}
