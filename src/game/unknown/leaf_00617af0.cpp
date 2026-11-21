/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_object016b9108.h"

class Object016abe10;

/* derived names: the cameras the object at +0x40 of the one the pointer at
 * 0x57c9390 holds keeps: every camera (+0x1d0), one slot per kind (+0x1e8)
 * and the current one (+0x210). Nothing else of either is traced. */
struct Cameras00617af0 { /* derived name */
    u8 unknown0[0x1d0];
    Array05943280<Object016abe10 *> cameras; /* +0x1d0 */
    Object016abe10 *slots[5];                /* +0x1e8 */
    Object016abe10 *current;                 /* +0x210 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x40];
    Cameras00617af0 *cameras40; /* +0x40 */
};

extern Object057c9390 *D_57c9390;

/* derived names: the class whose vtable is at 0x16abe10
 * (config/vtables.derived.base.txt, stored by FUN_00617960), a camera over
 * the root class, of the kind at +0x34. Its complete destructor (0x617af0;
 * the deleting one 0x617c20) takes it out of the cameras when they hold it:
 * the current camera cleared when it is this kind's, the kind's slot
 * cleared, the camera removed from the list; then the root's destructor is
 * inlined (the two names). The destructor is the class's key function, so
 * this file emits the vtable. The other fields are not traced. */
class Object016abe10 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016abe10();

  private:
    u8 unknown24[0x10];
    int kind; /* +0x34 */
};

Object016abe10::~Object016abe10()
{
    if (D_57c9390 && D_57c9390->cameras40) {
        Cameras00617af0 *cameras = D_57c9390->cameras40;
        int index = -1;
        for (unsigned i = 0; i < cameras->cameras.size(); ++i) {
            if (cameras->cameras[i] == this) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            Object016abe10 *&slot = cameras->slots[kind];
            if (cameras->current == slot)
                cameras->current = 0;
            slot = 0;
            cameras->cameras.removeAt(index);
        }
    }
}
