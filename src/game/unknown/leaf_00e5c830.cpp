/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: whether its second argument names a directory (stat
 * succeeds and the mode has S_IFDIR); slot 24 of the vtable at 0x16bdb40 (its
 * pointer at 0x16bdc00), FUN_00e5bc00's class. The object itself is not
 * read. */
struct Object00e5c830; /* derived name */

// NONMATCHING: FoldTwoEntryPHINode: the base keeps the masked mode test as a
// branch to `mov eax, 1` or `xor eax, eax`, the build folds it into `and; shr`
// (also with FUN_00e5bde0's three-way body inlined and compared with 1: the same)
bool FUN_00e5c830(Object00e5c830 *, const char *path) /* derived name */
{
    struct stat status;
    return stat(path, &status) == 0 && (status.st_mode & S_IFDIR) != 0;
}
