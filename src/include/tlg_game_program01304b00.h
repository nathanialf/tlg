/* src/include/tlg_game_program01304b00.h: an object the render's classes
 * hold at +0x30 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_PROGRAM01304B00_H
#define TLG_GAME_PROGRAM01304B00_H

#include "stdlib.h"

#include "tlg_game_object016c3be0.h"
#include "tlg_sce_record001af730.h"

/* derived names: the object at +0x30 of the classes whose vtables are at
 * 0x16c3940 and 0x16c3b18 (leaf_01304b00.cpp, leaf_0131f080.cpp): an SDK record (tlg_sce_record001af730.h) at its start, an entry
 * at +0x88 handed back to the list at +0x100b8 of the object 0x5adaaa8 points
 * at, one at +0xf0 to the list at +0x100e8, and a block at +0x98 freed
 * through the C library's free (0x14b0238); the record's out-of-line
 * destructor (0x1af750) runs last. The other fields are not traced. */
struct Program01304b00 /* derived name */
{
    ~Program01304b00()
    {
        returnEntry(entry88);
        returnEntryE8(entryf0);
        free(block98);
    }

    Record001af730 record; /* +0x0 */
    u8 unknown80[0x8];
    void *entry88; /* +0x88 */
    u8 unknown90[0x8];
    void *block98; /* +0x98 */
    u8 unknowna0[0x50];
    void *entryf0; /* +0xf0 */
};

#endif
