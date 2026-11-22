/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bdc60.h"

/* derived names: slot 5 of the vtable at 0x16bdc60: deletes the name's path
 * when a file exists there, an error's text dumped into a 0x40-byte local. */
void Object016bdc60::FUN_00e5d9a0(const char *name)
{
    char path[0x400];
    makePath(path, sizeof(path), name);
    if (sceFiosFileExistsSync(0, path)) {
        const int result = sceFiosDeleteSync(0, path);
        if (result < 0) {
            char message[0x40];
            sceFiosDebugDumpError(result, message, sizeof message);
        }
    }
}
