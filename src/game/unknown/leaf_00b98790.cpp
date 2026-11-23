/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

#include "tlg_game_object01388080.h"
#include "tlg_game_object0139e050.h"

/* CreateBlob (its message's name for it): the named file read whole
 * through the game's file system into a new blob; a file that does not open
 * is printed and gives no blob. */
/* The base stores no Object0130acb0 vptr between the serial's `lock xadd`
 * and the device count's `lock inc` (0xb98813 to 0xb98831): the count is
 * taken up relaxed (tlg_game_object0130acb0.h), and the blob, only
 * returned, is not captured, so the dead store pass removes the vptr store
 * across it (BasicAA: the new'd object against a loaded pointer); the
 * creators that hand their object out through a pointer keep it. */
Object0139e050 *CreateBlob(const char *name)
{
    FileSystem05938c40 *fileSystem = D_5938c40->fileSystem;
    void *file = fileSystem->open(name, 0);
    if (file == nullptr) {
        printf("CreateBlob: Error. Cannot open file %s.\n", name);
        return nullptr;
    }
    u64 size = fileSystem->size(file);
    Object0139e050 *blob = new Object0139e050();
    blob->data = malloc(size);
    blob->size = size;
    fileSystem->read(file, blob->data, size);
    fileSystem->close(file);
    return blob;
}
