/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_math.h"

/* derived names: FUN_004cd040 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 31 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_156f4df[23];
extern const char D_156f4f6[17];
extern const char D_156f507[30];
extern const char D_156f525[30];
extern const char D_156f543[20];
extern const char D_156f557[26];
extern const char D_156f571[20];
extern const char D_156f585[18];
extern const char D_156f597[17];
extern const char D_156f5a8[23];
extern const char D_156f5bf[10];
extern const char D_156f5c9[17];
extern const char D_156f5da[14];
extern const char D_156f5e8[13];
extern const char D_156f5f5[12];
extern const char D_156f9f8[38];
extern const char D_156fa1e[39];
extern const char D_156fa45[29];
extern const char D_156faa6[27];
extern const char D_1570079[13];
extern const char D_15701c3[12];
extern const char D_15706f8[7];
extern const char D_15abfbb[7];
extern const char D_15c627c[41];
extern const char D_15c62a5[40];
extern const char D_15ca408[10];
extern const char D_15cb21f[8];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57d8c90(D_15c627c);
Name D_57d8c94(D_15c62a5);
Name D_57d8c98(D_15cb5dd, false);
Name D_57d8c9c(D_15cb5e6, false);
Name D_57d8ca0;
Name D_57d8ca4(D_156f4df, false);
Name D_57d8ca8(D_15ca408);
Name D_57d8b94(D_15cb21f);
Name D_57d8cac(D_15cb5dd, false);
Name D_57d8cb0(D_15abfbb, false);
Name D_57d8b28(D_156f4f6, false);
Name D_57d8cb4(D_156f507, false);
Name D_57d8cb8(D_156f525, false);
Name D_57d8cbc(D_15706f8, false);
Name D_57d8b2c(D_15701c3, false);
Name D_57d8b30(D_156f543, false);
Name D_57d8b34(D_156f557, false);
Name D_57d8b38(D_156f571, false);
Name D_57d8b3c(D_156f585, false);
Name D_57d8b40(D_156f597, false);
Name D_57d8b44(D_156f5a8, false);
Name D_57d8b54(D_156f9f8);
Name D_57d8cc0(D_156fa1e);
Name D_57d8b50(D_156fa45);
Name D_57d8b90(D_156faa6);
Name D_57d8b48(D_156f5bf);
Name D_57d8b4c(D_156f5c9);
Name D_57d8b20(D_156f5da);
Name D_57d8b58(D_156f5e8);
Name D_57d8b24(D_156f5f5);
Name D_57d8cc4(D_1570079);

/* derived names: the x and the y axes of a rotation (the first two columns
 * of its matrix), each this file's VECTOR_X or VECTOR_Y with the rotation's
 * part added: twice the products, the axis's own lane less twice the other
 * two squares; w the constant's own. Called directly by the joint chains
 * (FUN_013fd580 and its copies read the y axis); called and never inlined
 * in the base, so each is defined over its own parameter types and the
 * callers' declarations (tlg_game_joint_chain.h, leaf_01403320.cpp) stay
 * declarations of another name. */
// NONMATCHING: 18/26: the arithmetic and the order are the base's; the products' operands are
// commuted (the base's `x * y`, `x * z` take x first: by Reassociate's ranks y and z are read
// before x and w there) and the registers differ (w in xmm4, x * y in xmm2); reading y and z
// first gives the operands and moves the registers further (10/26); read in the expression
// itself (y and z first) 5/26, and as products of the doubled y and z 1/26 (the doubling
// then stays in the products)
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it, and 1 draft (round 513D:
 * cause not found; not its address range, its callers' count, its cost or its unit: a single
 * block, cost 80 under the link's threshold of 262 with its bonuses, and with it outside the
 * module every row holds) */
void FUN_01353470(Float4 *axis, const Float4A &rotation) /* derived name */
{
    const float x = rotation.x, y = rotation.y, w = rotation.w, z = rotation.z;
    const float xy = x * y, wy = w * y, yy = y * y;
    const float xz = x * z, wz = w * z, zz = z * z;
    *axis = Float4(lane(VECTOR_X.v, 0) + 2.0f * (-yy - zz), lane(VECTOR_X.v, 1) + 2.0f * (xy + wz),
                   lane(VECTOR_X.v, 2) + 2.0f * (xz - wy), lane(VECTOR_X.v, 3));
}

// NONMATCHING: 19/26: as FUN_01353470 (the base's `y * x`, `y * z` take y first)
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 6 rowed callers where the base calls it (round 513D: cause not found;
 * not its address range, its callers' count, its cost or its unit: a single block, cost 80 under
 * the link's threshold of 262 with its bonuses, and with it outside the module every row holds) */
void FUN_013533f0(Float4 *axis, const Float4A &rotation) /* derived name */
{
    const float x = rotation.x, y = rotation.y, w = rotation.w, z = rotation.z;
    const float xy = x * y, wx = w * x, xx = x * x;
    const float yz = y * z, zz = z * z, wz = w * z;
    *axis = Float4(lane(VECTOR_Y.v, 0) + 2.0f * (xy - wz), lane(VECTOR_Y.v, 1) + 2.0f * (-xx - zz),
                   lane(VECTOR_Y.v, 2) + 2.0f * (yz + wx), lane(VECTOR_Y.v, 3));
}
