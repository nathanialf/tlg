/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: a chunk reader, passed with its state record
 * (lea at 0xddbc4e; the record's function at +0x8 is the caller's own reader,
 * called with the words at +0x0 and +0x10 and the size's address): when no
 * block is pending (the int at +0x18), reads the next one into +0x20 (its size
 * into +0x28); stores the size through the third argument, clears the
 * pending flag and returns the block. The state argument is not read. */
struct Reader00d9c0a0 {                                   /* derived name */
    void *unknown0;                                       /* +0x0: the reader's first argument */
    const char *(*unknown8)(void *a, void *b, u64 *size); /* +0x8: the reader */
    void *unknown10;                                      /* +0x10: its second argument */
    int unknown18;                                        /* +0x18: a block pending */
    const char *unknown20;                                /* +0x20: the block */
    u64 unknown28;                                        /* +0x28: its size */
};

const char *FUN_00d9c0a0(lua_State *, Reader00d9c0a0 *reader, u64 *size) /* derived name */
{
    if (reader->unknown18 == 0)
        reader->unknown20 =
            reader->unknown8(reader->unknown0, reader->unknown10, &reader->unknown28);
    *size = reader->unknown28;
    const char *block = reader->unknown20;
    reader->unknown18 = 0;
    return block;
}
