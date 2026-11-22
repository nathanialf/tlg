/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bdc60.h"

/* derived names: slot 2 of the vtable at 0x16bdc60: the whole file at the
 * name's path read into a block of the thread's heap (aligned to 32), its
 * size stored through size; an empty file gives a 16-byte block holding an
 * empty string. Null, and a size of 0, when the file is missing or its read
 * falls short (the block released); a size's error text is dumped into a
 * 0x40-byte local. The read's flags are 0x400 (not traced). */
void *Object016bdc60::FUN_00e5d2e0(const char *name, u32 *size) const
{
    char path[0x400];
    makePath(path, sizeof(path), name);
    const SceFiosSize length = sceFiosFileGetSizeSync(0, path);
    if (length > 0) {
        void *buffer = allocateBlock(length, 0x20);
        if (buffer) {
            SceFiosOpAttr attr;
            memset(&attr, 0, sizeof attr);
            attr.opFlags = 0x400;
            if (sceFiosFileReadSync(&attr, path, buffer, length, 0) == length) {
                *size = length;
                return buffer;
            }
            FUN_00ebf3f0(buffer);
        }
    } else if (length == 0) {
        char *buffer = static_cast<char *>(allocateBlock(0x10, 0x20));
        buffer[0] = 0;
        *size = 0;
        return buffer;
    } else {
        char message[0x40];
        sceFiosDebugDumpError(length, message, sizeof message);
    }
    *size = 0;
    return 0;
}
