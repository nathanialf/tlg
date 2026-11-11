/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: FUN_008a4490 (0x3e57 bytes) builds seventeen names from
 * strings (looked up, not interned) and hands eight of the lists it makes of
 * them out as guarded function-local statics, each destroyed by the array
 * destructor the compiler writes for it (0x8ad9f0, 0x8ada40, 0x8adb40,
 * 0x8adb90, 0x8adc10, 0x8adc60, 0x8adce0, 0x8add30, registered with
 * __cxa_atexit in that order, the guard 8 bytes below each list as
 * cookbook 1194). */
struct Owner008a4490; /* derived name */

extern const char D_159b7f6[22];
extern const char D_159b80c[23];
extern const char D_159b823[23];
extern const char D_159b83a[16];
extern const char D_159b84a[29];
extern const char D_159b867[23];
extern const char D_159b87e[17];
extern const char D_159b88f[17];
extern const char D_159b8a0[23];
extern const char D_159b8b7[27];
extern const char D_159b8d2[26];
extern const char D_159b8ec[31];
extern const char D_159b90b[31];
extern const char D_159b92a[31];
extern const char D_159b949[25];
extern const char D_159b962[25];
extern const char D_159b97b[25];

// NONMATCHING: written as far as the eight static lists (0x8a4490 to
// 0x8a4a5a); the rest of the function (to 0x8a82e7) is not written, and its
// two parameters (rdi kept in r12, esi in r14d) are not read yet.
void FUN_008a4490(Owner008a4490 *self, int unknown) /* derived name */
{
    Name name1(D_159b7f6, false);
    Name name2(D_159b80c, false);
    Name name3(D_159b823, false);
    Name name4(D_159b83a, false);
    Name name5(D_159b84a, false);
    Name name6(D_159b867, false);
    Name name7(D_159b87e, false);
    Name name8(D_159b88f, false);
    Name name9(D_159b8a0, false);
    Name name10(D_159b8b7, false);
    Name name11(D_159b8d2, false);
    Name name12(D_159b8ec, false);
    Name name13(D_159b90b, false);
    Name name14(D_159b92a, false);
    Name name15(D_159b949, false);
    Name name16(D_159b962, false);
    Name name17(D_159b97b, false);
    static Name D_581ee30[] = {name4};
    static Name D_581ee40[] = {name5, name6, name7, name8};
    static Name D_581ee58[] = {name9};
    static Name D_581ee68[] = {name10, name11};
    static Name D_581ee78[] = {name12};
    static Name D_581ee88[] = {name13, name14};
    static Name D_581ee98[] = {name15};
    static Name D_581eea8[] = {name16, name17};
}
