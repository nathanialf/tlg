/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_simd.h"

/* derived names: an object with an array of vectors at +0x17f0 and a vector
 * after it at +0x1810, each moved with aligned vector moves; the rest is not
 * traced */
struct Object0045f620 {                                 /* derived name */
    void addPoint(const Vec4 &point, const Vec4 &last); /* derived name */

    u8 unknown0[0x17f0];
    Array05943280<Vec4> points; /* +0x17f0 */
    Vec4 unknown1810;           /* +0x1810 */
};

/* derived name: the vector appended to the array (the count raised, the
 * block grown when it is full, then one aligned move), the second one
 * stored at +0x1810 */
void Object0045f620::addPoint(const Vec4 &point, const Vec4 &last)
{
    points.push(point);
    unknown1810 = last;
}
