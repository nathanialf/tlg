/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: every field set, the path copied as a string (called at
 * 0x1bc53 and 0x1bf75). */
void FileSystemEntry::FUN_0001a700(hkReferencedObject *fileSystem, const char *path, int flags,
                                   s64 value10, s64 value18)
{
    this->fileSystem = fileSystem;
    this->path = path;
    this->flags = flags;
    this->value10 = value10;
    this->value18 = value18;
}
