/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bdc60.h"

/* derived names: slot 21 of the vtable at 0x16bdc60: creates the directory
 * at the name's path, 1 when it is made or already there (0x80820023). Bit 1
 * of flags drops the path's last component first (after its last '/', else
 * its last '\\'); bit 0 creates every parent directory first, at each
 * separator not after a ':', 0 when one of them fails. */
// NONMATCHING: 88/138, same control flow; the base reloads the stack guard's address in each of the
// return block's predecessors (after the last call on each path) where this loads it in the return
// block, and its registers follow (flags in ebx, the result in ebx; here r14 and r12)
int Object016bdc60::FUN_00e5f050(const char *name, int flags) const
{
    char path[0x400];
    char copy[0x400];
    char parent[0x400];
    makePath(path, sizeof(path), name);
    if (flags & 2) {
        strcpy(copy, path);
        char *last = strrchr(copy, '/');
        if (!last)
            last = strrchr(copy, '\\');
        if (!last)
            last = copy;
        *last = 0;
        strcpy(path, copy);
    }
    if (flags & 1) {
        for (s64 i = 0; path[i]; ++i) {
            if ((path[i] == '/' || path[i] == '\\') && i > 0 && path[i - 1] != ':') {
                strncpy(parent, path, i);
                parent[i] = 0;
                const int result = sceFiosDirectoryCreateSync(0, parent);
                if (result != 0 && result != static_cast<int>(0x80820023))
                    return 0;
            }
        }
    }
    if (!path[0])
        return 1;
    const int result = sceFiosDirectoryCreateSync(0, path);
    if (result != 0 && result != static_cast<int>(0x80820023))
        return 0;
    return 1;
}
