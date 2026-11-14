/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: whether a text matches a pattern in which `*` stands for
 * any run of characters and `?` for any one; it calls itself (0xed1fff) and
 * FUN_00ed8380, FUN_00ef3a40 and FUN_00ef4420's neighbours call it
 * (0xed83aa, 0xed83bf, 0xef3a69, 0xef443d). */
// NONMATCHING: 12/50 alone, the compares (`*`, `?`, then 0) and the blocks are the base's; the
// base keeps the text in one register (rbx, `inc rbx` ahead of the compare with `*`), the build
// gives the `*` arm's loop its own copy (`mov rbx, r14`, `lea rbx, [rbx + 1]` after the test of the
// text's end) and reads the outer one in the other arms: the inner loop's exit value rewritten
bool FUN_00ed1fc0(const char *text, const char *pattern) /* derived name */
{
    switch (*pattern) {
    case '\0':
        return *text == '\0';
    case '*':
        return FUN_00ed1fc0(text, pattern + 1) ||
               (*text != '\0' && FUN_00ed1fc0(text + 1, pattern));
    case '?':
        return *text != '\0' && FUN_00ed1fc0(text + 1, pattern + 1);
    default:
        return static_cast<u8>(*pattern) == static_cast<u8>(*text) &&
               FUN_00ed1fc0(text + 1, pattern + 1);
    }
}
