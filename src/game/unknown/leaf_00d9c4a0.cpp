/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: the state of a chunk's dump (Lua's DumpState as the VM's
 * dumper reads it, FUN_00d9c580 and FUN_00dba580): the writer and its data,
 * whether the sizes are written byte-swapped, the writer's first nonzero
 * result, after which nothing more is written, and the bytes written */
struct HksDumpState { /* derived name */
    lua_State *state;
    int (*writer)(lua_State *state, const void *block, size_t size, void *data); /* +0x8 */
    void *data;                                                                  /* +0x10 */
    u8 unknown18[0x4];
    int swapBytes; /* +0x1c */
    int status;    /* +0x20 */
    u8 unknown24[0x1c];
    u64 written; /* +0x40 */
};

static inline void dumpBlock(const void *block, size_t size, HksDumpState *dump) /* derived name */
{
    if (dump->status == 0) {
        dump->status = dump->writer(dump->state, block, size, dump->data);
        dump->written += size;
    }
}

/* derived name: Lua's DumpString: the size with its terminator (0 for no
 * string), swapped when the dump swaps, then the characters */
void FUN_00d9c4a0(HksDumpState *dump, const HksString *string) /* derived name */
{
    if (string) {
        size_t size = (string->lengthAndFlags & 0x3fffffffffffffffULL) + 1;
        size_t stored = dump->swapBytes == 0 ? size : __builtin_bswap64(size);
        dumpBlock(&stored, sizeof stored, dump);
        dumpBlock(string->data, size, dump);
    } else {
        size_t size = 0;
        dumpBlock(&size, sizeof size, dump);
    }
}
