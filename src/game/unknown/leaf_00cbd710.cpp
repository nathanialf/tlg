/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: a qsort comparator over 4-byte indices into the table at
 * 0x17ac870 (FUN_00cbce00 passes it with the element size 4, lea at 0xcbd015):
 * compares the strings the first fields of the two 32-byte entries point to,
 * with strcmp as a tail call. The table is the game's object
 * (leaf_01373a50.cpp); its entries' other fields are not traced here. */
struct Entry017ac870 { /* derived name */
    const char *unknown0;
    u8 unknown8[0x18];
};

extern Entry017ac870 D_17ac870[];

int FUN_00cbd710(const void *a, const void *b) /* derived name */
{
    return strcmp(D_17ac870[*static_cast<const unsigned *>(a)].unknown0,
                  D_17ac870[*static_cast<const unsigned *>(b)].unknown0);
}
