/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bdc60.h"

/* derived names: slot 8 of the vtable at 0x16bdc60: the size of the file at
 * the name's path, 0 on an error, whose text is dumped into a 0x40-byte local
 * first. */
SceFiosSize Object016bdc60::FUN_00e5dbc0(const char *name) const
{
    char path[0x400];
    makePath(path, sizeof(path), name);
    const SceFiosSize size = sceFiosFileGetSizeSync(0, path);
    if (size < 0) {
        char message[0x40];
        sceFiosDebugDumpError(size, message, sizeof message);
    }
    return size < 0 ? 0 : size;
}
