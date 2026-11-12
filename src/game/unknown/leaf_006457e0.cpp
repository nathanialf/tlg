/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: whether the name list of the record at +0x40 of the object
 * the pointer at 0x57c9390 holds contains the name the string at 0x158ad06 interns
 * (the list's Names at +0x1210, its count at +0x1218). Its address is taken
 * (a callback whose table is not traced); it reads no argument. */
struct NameList0158ad06 { /* derived name */

    bool contains(const Name &name) const
    {
        for (int i = 0; i < count; i++)
            if (names[i] == name)
                return true;
        return false;
    }

    u8 unknown0[0x1210];
    Name *names;    /* +0x1210 */
    unsigned count; /* +0x1218 */
};

struct Object057c9390 { /* derived name: the object, seen from here */
    u8 unknown0[0x40];
    NameList0158ad06 *unknown40; /* +0x40 */
};

extern Object057c9390 *D_57c9390;
extern const char D_158ad06[13];

// NONMATCHING: the index kept int and sign-extended each iteration (`movsxd rdi, edx; inc edx`, IndVarSimplify), the build widens it; and the false result set before the count test (`mov ebx, 0`)
bool FUN_006457e0() /* derived name */
{
    Name name(D_158ad06);
    return D_57c9390->unknown40->contains(name);
}
