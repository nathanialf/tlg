/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bdc60.h"

/* derived names: slot 3 of the vtable at 0x16bdc60: the name's path opened
 * in one of four modes (the low two bits: read; write, created and
 * truncated; read and write, created; append), the handle returned, 0 when
 * the open fails; an error's text is dumped into a 0x40-byte local. */
// NONMATCHING: registers only (12/101 counted, the streams one instruction apart from the
// ninth): the base keeps mode in r14 and rematerialises the path's address for memset and
// strncpy; here the address stays in r14 and mode is spilled
s64 Object016bdc60::FUN_00e5d580(const char *name, unsigned mode) const
{
    char path[0x400];
    makePath(path, sizeof(path), name);
    SceFiosOpenParams params;
    memset(&params, 0, sizeof params);
    switch (mode & 3) {
    case 0:
        params.openFlags = 1;
        break;
    case 1:
        params.openFlags = 0x1a;
        break;
    case 2:
        params.openFlags = 0xb;
        break;
    case 3:
        params.openFlags = 4;
        break;
    default:
        return 0;
    }
    SceFiosFH fh = 0;
    const int result = sceFiosFHOpenSync(0, &fh, path, &params);
    if (result < 0) {
        char message[0x40];
        sceFiosDebugDumpError(result, message, sizeof message);
        if (result == static_cast<int>(0x80820013))
            return 0;
    }
    return result == 0 ? fh : 0;
}
