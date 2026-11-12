/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00332190 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 27 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00332190): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15654c6[42];
extern const char D_15654f0[42];
extern const char D_156551a[47];
extern const char D_1565549[47];
extern const char D_1565578[43];
extern const char D_15655a3[39];
extern const char D_15655ca[38];
extern const char D_15655f0[47];
extern const char D_156561f[41];
extern const char D_1565648[50];
extern const char D_156567a[36];
extern const char D_156569e[35];
extern const char D_15656c1[37];
extern const char D_15656e6[39];
extern const char D_156570d[37];
extern const char D_1565732[16];
extern const char D_1565742[22];
extern const char D_1565758[29];
extern const char D_1565775[32];
extern const char D_1565795[16];
extern const char D_15657a5[17];
extern const char D_15657b6[30];
extern const char D_15657d4[29];
extern const char D_15ca420[7];
extern const char D_15cb0f3[13];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57cde60(D_15cb5dd, false);
Name D_57cdccc(D_15cb5e6, false);
Name D_57cdcb4(D_15ca420, false);
Name D_57cdd20(D_15654c6);
Name D_57cdd24(D_15654f0);
Name D_57cdd28(D_156551a);
Name D_57cdd2c(D_1565549);
Name D_57cdd30(D_1565578);
Name D_57cdcc8(D_15655a3);
Name D_57cdcfc(D_15655ca);
Name D_57cdcb0(D_15655f0);
Name D_57cdd04(D_156561f);
Name D_57cdd00(D_1565648);
Name D_57cdcd0(D_156567a);
Name D_57cde64(D_156569e);
Name D_57cdcc4(D_15656c1);
Name D_57cdcf8(D_15656e6);
Name D_57cdcf4(D_156570d);
Name D_57cdc98(D_1565732);
Name D_57cdc9c(D_1565742);
Name D_57cdca0(D_1565758);
Name D_57cdca4(D_1565775);
Name D_57cdca8(D_1565795);
Name D_57cdcac(D_15657a5);
Name D_57cdd08(D_15cb0f3);
Name D_57cdd34(D_15657b6);
Name D_57cdd38(D_15657d4);

/* derived names: FUN_00331950 passes the member at +0xd8 of its second
 * argument to FUN_01344a20 with one of this file's names by the kind at +0x70
 * (an eight-case jump table, 0x1557df8): 1 D_57cdd20, 2 D_57cdd24, 3 and 5
 * D_57cdd28, 4 and 6 D_57cdd2c, 7 D_57cdd30, 8 the object's own name at +0x84
 * when it is not empty; any other kind does nothing. Class and method
 * unknown. */
struct Object00331950 /* derived name */
{
    u8 unknown0[0x70];
    int kind; /* +0x70 */ /* derived name */
    u8 unknown74[0x10];
    Name name; /* +0x84 */ /* derived name */
};

struct Target00331950 /* derived name */
{
    u8 unknown0[0xd8];
    u8 unknownd8[1]; /* +0xd8: its extent not traced */
};

void FUN_01344a20(void *member, const Name *name); /* derived name */

void FUN_00331950(const Object00331950 *self, Target00331950 *target) /* derived name */
{
    switch (self->kind) {
    case 1:
        FUN_01344a20(target->unknownd8, &D_57cdd20);
        break;
    case 2:
        FUN_01344a20(target->unknownd8, &D_57cdd24);
        break;
    case 3:
    case 5:
        FUN_01344a20(target->unknownd8, &D_57cdd28);
        break;
    case 4:
    case 6:
        FUN_01344a20(target->unknownd8, &D_57cdd2c);
        break;
    case 7:
        FUN_01344a20(target->unknownd8, &D_57cdd30);
        break;
    case 8:
        if (self->name.index != 0)
            FUN_01344a20(target->unknownd8, &self->name);
        break;
    }
}
