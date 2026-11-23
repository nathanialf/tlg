/* src/include/tlg_game_axes01000aa0.h: the six directions of the axes, which
 * slot 2 of two classes returns, each in the including unit's copies of the
 * axes (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_AXES01000AA0_H
#define TLG_GAME_AXES01000AA0_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_vector.h"

/* derived names: 0x80 bytes returned by value: 0x20 bytes slot 2 leaves
 * unset, then six directions, cleared when built (three 32-byte stores) and
 * then set lane by lane from the axes' floats (FUN_01000aa0, FUN_0126c6f0:
 * each axis two 64-bit loads, the lanes negated as integers) */
struct Axes01000aa0 { /* derived name */

    Axes01000aa0()
    {
        for (int i = 0; i < 6; ++i)
            directions[i].set(0.0f, 0.0f, 0.0f, 0.0f);
    }

    /* x, -x, -y, y, z and -z, each turned around in x, y and z only
     * (derived name) */
    static Axes01000aa0 make()
    {
        Axes01000aa0 axes;
        const Float4Data x = reinterpret_cast<const Float4Data &>(VECTOR_X);
        const Float4Data y = reinterpret_cast<const Float4Data &>(VECTOR_Y);
        axes.directions[0] = x;
        axes.directions[1].set(-x.x, -x.y, -x.z, x.w);
        axes.directions[2].set(-y.x, -y.y, -y.z, y.w);
        axes.directions[3] = y;
        const Float4Data z = reinterpret_cast<const Float4Data &>(VECTOR_Z);
        axes.directions[4] = z;
        axes.directions[5].set(-z.x, -z.y, -z.z, z.w);
        return axes;
    }

    u8 unknown0[0x20];
    Float4A directions[6]; /* +0x20 */
};

#endif
