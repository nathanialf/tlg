/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_textbuffer00d705f0.h"

// NONMATCHING: the file's pointer: the base reads it once before the length is tested (`mov rcx,
// [rbx]; test r12d, r12d; je`) and tests that register again where the block may grow; this build
// reads it only when the length is set and compares memory (`cmp qword [rbx], 0`) at the second test
void TextBuffer00d705f0::FUN_00d705f0(const char *text)
{
    const u32 size = strlen(text);
    const u32 offset = reserve(size);
    memcpy(block + offset, text, size);
}
