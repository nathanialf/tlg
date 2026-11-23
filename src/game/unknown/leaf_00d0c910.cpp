/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: the names of a set of flags, one Name for each bit from
 * bit 0, their number at +0x10 */
struct FlagNames00d0c910 { /* derived name */
    u8 unknown0[0x10];
    unsigned count; /* +0x10 */
    Name names[32]; /* +0x14 */
};

/* derived names: a text of at most 4095 characters and its length at
 * +0x1000, as the callers build it on their frames (FUN_00c727d0: the
 * length, the first and the last byte cleared) */
struct Text00d0c910 { /* derived name */
    char text[0x1000];
    unsigned length; /* +0x1000 */
};

/* derived name: the names of the flags set, from bit 0, joined by '|' into
 * the text, as many characters as it holds */
// NONMATCHING: one jump (46/54 at the base's 210 bytes): after the '|' the base falls into the test of the
// flags left (`test esi, esi` at 0xd0c9d0) where this build jumps past it to the next index; the path
// with no room for the '|' skips the test in both; written with the test in the loop's condition or as
// a break after the name, the same
void FUN_00d0c910(const FlagNames00d0c910 *names, unsigned flags,
                  Text00d0c910 *text) /* derived name */
{
    text->text[0] = '\0';
    text->length = 0;
    if (flags == 0)
        return;
    for (unsigned i = 0; i < names->count; ++i) {
        const unsigned bit = flags & 1;
        flags >>= 1;
        if (bit && names->names[i].index) {
            for (const char *c = D_17ac870[names->names[i].index].string0; *c; ++c) {
                if (text->length >= sizeof text->text - 1)
                    break;
                text->text[text->length++] = *c;
            }
            text->text[text->length] = '\0';
            if (flags == 0)
                return;
            if (text->length < sizeof text->text - 2) {
                text->text[text->length++] = '|';
                text->text[text->length] = '\0';
            }
        }
        if (flags == 0)
            return;
    }
}
