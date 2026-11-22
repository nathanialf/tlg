/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bdc60.h"

/* derived names: slot 12 of the vtable at 0x16bdc60: bit 0 of the status
 * flags of the name's path (whether it is a directory), -1 when the status
 * is not read; an error's text is dumped into a 0x40-byte local. */
int Object016bdc60::FUN_00e5df70(const char *name) const
{
    char path[0x400];
    char message[0x40];
    makePath(path, sizeof(path), name);
    SceFiosStat stat;
    const int result = sceFiosStatSync(0, path, &stat);
    if (result == 0)
        return stat.statFlags & 1;
    if (result < 0)
        sceFiosDebugDumpError(result, message, sizeof message);
    return -1;
}
