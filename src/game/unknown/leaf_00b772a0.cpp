/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b6c20.h"
#include "tlg_game_object016b85e0.h"

/* derived name: what slot 12 finds and tests: its ints at +0x58 and +0xb0 */
class Held00b772a0 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x34];
    int unknown58; /* +0x58 */
    u8 unknown5c[0x54];
    int unknownb0; /* +0xb0 */
};

struct Object05938c40_b0; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0xb0];
    Object05938c40_b0 *unknownb0; /* +0xb0 */
};

extern Object05938c40 *D_5938c40;

/* derived names: the component of the node's of D_5946a58's type into the
 * reference (FUN_009f5540 itself); the call slot 12 makes with what it
 * found */
void FUN_009f5540(Ref00503fb0<Object016b9108> *reference, void *node); /* derived name */
void FUN_00ce2a80(Object05938c40_b0 *target, Held00b772a0 *held, const Float4A *first,
                  const Float4A *second, const Float4A *position, const Float4A *direction,
                  int on); /* derived name */

/* derived names: slot 12 of the vtables at 0x16b6c20 and 0x16b6c98; the
 * last argument is clear bit 1 of the int at +0x68 */
void Object016b6c20::slot12()
{
    FUN_009f5540(&held60, unknown28);
    Held00b772a0 *held = static_cast<Held00b772a0 *>(held60.get());
    if (held && held->unknown58 && held->unknownb0) {
        Object016b85e0 *node = static_cast<Object016b85e0 *>(unknown28);
        FUN_00ce2a80(D_5938c40->unknownb0, held, &unknown40, &unknown50, &node->unknown120,
                     &node->unknown140, !((unknown68 >> 1) & 1));
    }
}
