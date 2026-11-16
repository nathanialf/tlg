/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_libc.h"

/* derived names: the visit FUN_00d38f30 hands FUN_00cb8790 for the objects
 * of the type the registry at 0x593ab20 holds (lea at 0xd39290), with the
 * step read from +0x19c of the record the pointer at 0x5938c40 holds: an
 * object with the flag 2 at +0x16 and a speed (+0x40, +0x44) that is not
 * zero moves its offset (+0x38, +0x3c) by the speed times the step, or
 * times the record's float at +0x194 when its flag 8 at +0x60 is set, each
 * kept in [0, 1) by its floor (`vroundss` mode 1, as math.floor's,
 * FUN_00de73b0); returns 1, the walk goes on. */
struct Scroll00d42170 : Object016b9108 /* derived name */
{
    u8 unknown24[0x14]; /* from the root class's end, +0x24 */
    float offsetU;      /* +0x38 */
    float offsetV;      /* +0x3c */
    float speedU;       /* +0x40 */
    float speedV;       /* +0x44 */
    u8 unknown48[0x18];
    int flags60; /* +0x60 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x194];
    float step194; /* +0x194 */
};

extern Object05938c40 *D_5938c40;

// NONMATCHING: the speed test: the base branches on each component (`vucomiss xmm0, xmm1; jne`,
// then `vucomiss xmm1, [rdi + 0x44]; je`) and reads the second again in the body, the build loads
// both first and joins the tests (`setne al; setne cl; or cl, al`), nested or joined by `&&`
int FUN_00d42170(Scroll00d42170 *self, const float &step) /* derived name */
{
    if (self->flags16 & 2) {
        if (self->speedU != 0 || self->speedV != 0) {
            const float &time = (self->flags60 & 8) ? D_5938c40->step194 : step;
            float u = self->offsetU + self->speedU * time;
            float v = self->offsetV + self->speedV * time;
            self->offsetU = u - floorf(u);
            self->offsetV = v - floorf(v);
        }
    }
    return 1;
}
