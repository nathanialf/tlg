/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c3be0.h"

/* derived names: the class whose vtable is at 0x16c3c30
 * (config/vtables.derived.base.txt; built by FUN_01307080), over
 * Object016c3be0. Its complete destructor (0x1324580) hands back the base's
 * entries and its own at +0x138, the first to the list at +0x100e8 (its
 * count +0x100b0) when its state at +0x19c is 3, then runs the base's as a
 * tail call. The other fields are not traced. */
class Object016c3c30 : public Object016c3be0 /* derived name */
{
  public:
    virtual ~Object016c3c30();

  private:
    u8 unknown128[0x10];
    void *entry138; /* +0x138 */
    u8 unknown140[0x5c];
    int state19c; /* +0x19c */
};

Object016c3c30::~Object016c3c30()
{
    if (entry30) {
        JsDevice *owner = D_5adaaa8;
        if (state19c == 3) {
            FUN_0131e2d0(owner->unknown100e8, entry30);
            __sync_fetch_and_add(&owner->unknown100b0, 1);
        } else {
            FUN_0131e2d0(owner->unknown100b8, entry30);
            __sync_fetch_and_add(&owner->unknown100a0, 1);
        }
    }
    returnEntry(entry40);
    returnEntry(entry48);
    returnEntry(entry58);
    returnEntry(entry138);
}
