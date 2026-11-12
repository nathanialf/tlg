/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: through the record FUN_00468e60 reaches (+0x18 of the
 * record at +0x50 of the record at +0x900 of the object at +0x38 of the
 * object the pointer at 0x57c9390 holds): unless FUN_004ba970 says so of it
 * or its ints at +0x508 (count at +0x510) hold the int at 0x582c768, hands
 * the object at 0x582c76c to FUN_01344a20 with the member at +0xd8 of the
 * record its pointer at +0x4e0 holds. The fields' meaning is not traced. */
struct Value057c9390_38_900_50_18_4e0 { /* derived name */
    u8 unknown0[0xd8];
    u8 unknownd8[1]; /* +0xd8: its extent not traced */
};

struct Escape057c9390_38_900_50_18 { /* derived name */
    u8 unknown0[0x4e0];
    Value057c9390_38_900_50_18_4e0 *unknown4e0; /* +0x4e0 */
    u8 unknown4e8[0x20];
    const int *unknown508; /* +0x508 */
    unsigned unknown510;   /* +0x510 */
};

struct Member057c9390_38_900_50 { /* derived name */
    u8 unknown0[0x18];
    Escape057c9390_38_900_50_18 *unknown18; /* +0x18 */
};

struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x50];
    Member057c9390_38_900_50 *unknown50; /* +0x50 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Member057c9390_38_900 *unknown900; /* +0x900 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38; /* +0x38 */
};

extern Object057c9390 *D_57c9390;
extern int D_582c768;
extern u8 D_582c76c;

bool FUN_004ba970(Escape057c9390_38_900_50_18 *escape); /* derived name */
void FUN_01344a20(void *member, void *value);           /* derived name */

static inline int find(const Escape057c9390_38_900_50_18 *escape,
                       const int &value) /* derived name */
{
    for (int i = 0; i < escape->unknown510; ++i)
        if (escape->unknown508[i] == value)
            return i;
    return -1;
}

void FUN_00ad1c10() /* derived name */
{
    Escape057c9390_38_900_50_18 *escape = D_57c9390->unknown38->unknown900->unknown50->unknown18;
    if (!escape || FUN_004ba970(escape))
        return;
    if (find(escape, D_582c768) >= 0)
        return;
    if (Value057c9390_38_900_50_18_4e0 *value = escape->unknown4e0)
        FUN_01344a20(value->unknownd8, &D_582c76c);
}
