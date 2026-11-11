/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"
#include <stdlib.h>

/* derived names: a reallocation callback of the script VM in the shape of
 * Lua's lua_Alloc (user data, block, old size, new size), its address taken
 * by FUN_00dbeb50, FUN_00dd2650, FUN_00dd48d0, FUN_00ddd240, FUN_00de3a70,
 * FUN_00de43d0, FUN_00de8200, FUN_00de8760 and FUN_00de89f0: a new block of
 * the new size with the old block's bytes copied into it, the old block
 * freed; a size of 0 frees only. The user data is unused. */
void *FUN_00d95b00(void *, void *block, size_t oldSize, size_t newSize) /* derived name */
{
    void *result = 0;
    if (newSize) {
        result = malloc(newSize);
        if (block)
            memcpy(result, block, oldSize);
    }
    if (block)
        free(block);
    return result;
}
