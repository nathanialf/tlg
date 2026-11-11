/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: allocates a 0x328-byte Object00eb3c90 and constructs it with
 * its constructor FUN_00eb3c90 (config/vtables.derived.base.txt names the
 * class from that constructor's vtable store), returning it; its address is at
 * 0x16bead8 (no constructor stores that table). The class's fields are not
 * traced here. */
class Object00eb3c90 /* derived name */
{
  public:
    Object00eb3c90();
    virtual ~Object00eb3c90();

  private:
    u8 unknown8[0x320];
};

Object00eb3c90 *FUN_00eb3c60() /* derived name */
{
    return new Object00eb3c90;
}
