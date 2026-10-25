/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: frees a block with the 16-byte header (owner, size) that
 * FUN_0000bc30 put before it, through the allocator's blockFree; nothing for
 * a null block. */
void FUN_0000bc80(AllocatorBase &allocator, void *block); /* derived name */

/* derived names: the string library's free of a string duplicated into an
 * allocator (the duplicate beside it, 0x180c0, allocates strlen + 1 bytes
 * with FUN_0000bc30); the string map walk at 0x180bf0 frees each value with
 * it. */
void FUN_00018090(char *string, AllocatorBase &allocator) /* derived name */
{
    FUN_0000bc80(allocator, string);
}
