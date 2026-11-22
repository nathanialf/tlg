/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"
#include "tlg_types.h"

struct Target007961f0; /* derived name; not traced */

/* derived names: the object at +0x1f0 of FUN_00786cb0's owner, set from the
 * owner's points at +0x160 and its values at +0x158, +0x184, +0x208 and
 * +0x188 (0x78a22a to 0x78a25f) */
class Object007961f0 /* derived name */
{
  public:
    void set(float weight, const Array05943280<Float4A> &points, int mode, int count, float speed,
             Target007961f0 *target); /* derived name */

  private:
    u8 unknown0[0xc];
    float weight;                  /* +0xc */
    Array05943280<Float4A> points; /* +0x10 */
    int count;                     /* +0x28 */
    float speed;                   /* +0x2c */
    u8 unknown30[0x4];
    int mode; /* +0x34 */
    u8 unknown38[0x28];
    Target007961f0 *target; /* +0x60 */
};

/* derived names: the fields stored in their order, the points copied whole
 * (one block of 16-byte vectors, `shl r14d, 4` and memcpy); called from
 * 0x78a25f */
// NONMATCHING: the points' copy: the base copies the block with one memcpy of the count
// times 16 (`mov [rbx+0x18], r14d; shl r14d, 4`, memcpy), the build's Array::operator= loops
// up to the count read again (lead: the original assignment copies trivially copyable
// elements as one block; a header-wide question, every row over operator= to re-measure)
void Object007961f0::set(float weight, const Array05943280<Float4A> &points, int mode, int count,
                         float speed, Target007961f0 *target)
{
    this->weight = weight;
    this->points = points;
    this->count = count;
    this->speed = speed;
    this->mode = mode;
    this->target = target;
}
