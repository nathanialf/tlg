/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a base class at +0x30 of the classes whose vtables are at
 * 0x16cc478 and 0x16cc5b8 (both built by FUN_009232e0): its own function is
 * slot 3 of that base's part of both vtables (0x16cc570, 0x16cc678), so it
 * reads its fields from the base. A count of at least four: the int at
 * +0x7c, doubled and two added when the field at +0x350 is set. Nothing
 * else of the class is traced. */
class Object013747a0 /* derived name */
{
  public:
    int FUN_013747a0() const;

  private:
    u8 unknown0[0x7c];
    int unknown7c; /* +0x7c */
    u8 unknown80[0x2d0];
    int unknown350; /* +0x350 */
};

int Object013747a0::FUN_013747a0() const
{
    int count = unknown7c;
    if (unknown350) {
        count = count * 2 + 2;
        return count < 4 ? 4 : count;
    }
    return count < 4 ? 4 : count;
}
