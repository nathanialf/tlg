/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: a name for a new object made from a path: the path's file
 * name (what follows its last '/'), cut before "_ibuf", then "_<number>"
 * and the suffix, the number 0, 100, 200 and on until no object this
 * thread may use is named so. Written into the buffer. Four callers, all in
 * FUN_00c2d200 (the path a Name's string: `mov rsi, [rax+rcx]` from the
 * name table at 0xc2d707). */
// NONMATCHING: the unit's LoopUnswitch splits the outer loop on the buffer's null test (Name::intern's
// `string &&`, invariant: the buffer is the parameter), so the build holds two copies of the loop
// (661 bytes against 452). The base tests the buffer inside its one loop (0xc2ee9c `test r15, r15`):
// at the unit stage its loop held no whole invariant branch or cost over the threshold of 100
// (LoopUnswitch.cpp:70, :270; the outer loop here is about 75). With the record's thread flag read
// through threadMayUse() the tests are the base's branches (`test byte [r15+0x16], 4; jne`); the
// body is otherwise the base's in order. Lead: the twin at 0xd87fd0 is the same bytes in another
// unit, which suggests a helper shared through a header; what of it is a call at the unit stage
void FUN_00c2edd0(char *name, const char *path, const char *suffix) /* derived name */
{
    const Object016b9108 *object;
    int number = 0;
    do {
        if (strchr(path, '/'))
            for (const char *slash = path; slash; slash = strchr(path, '/'))
                path = slash + 1;
        strcpy(name, path);
        if (char *mark = strstr(name, "_ibuf"))
            *mark = 0;
        char text[64];
        sprintf(text, "_%d", number);
        strcat(name, text);
        strcat(name, suffix);
        const Name made(Name::intern(name));
        const Object016b9108 *named =
            static_cast<const Object016b9108 *>(D_17ac870[made.index].record18);
        object = named && ((named->flags16 & 4) || threadMayUse()) ? named : 0;
        number += 100;
    } while (object);
}
