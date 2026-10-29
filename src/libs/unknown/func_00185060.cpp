/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The stream over the reader the file system opens for a file name (the
 * flag asks for it buffered); the reader's reference becomes the
 * stream's. */
Object00185000::Object00185000(const char *name) : reader(0)
{
    StreamReader *newReader = D_57b9b70->FUN_0001bb50(name, 1);
    if (reader) {
        reader->removeReference();
    }
    reader = newReader;
}
