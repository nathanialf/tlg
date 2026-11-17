/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00774560.h"

void FUN_007196a0(Body0077bac0 *body); /* derived name: not traced */

/* derived names: the class whose vtable is at 0x16acf08
 * (config/vtables.derived.base.txt, stored by FUN_00777e10), derived from
 * Object00774560: a point at +0x100 and a rotation at +0x110 waiting to be
 * given to the body; only what slot 7 reads is traced */
class Object016acf08 : public Object00774560 /* derived name */
{
  public:
    virtual ~Object016acf08();
    virtual void slot7(); /* FUN_00778080 */

  private:
    u8 unknownfc[0x4];
    Float4A unknown100; /* +0x100: a point, (0, 0, 0, 1) when there is none */
    Float4A unknown110; /* +0x110: a rotation, (0, 0, 0, 1) when there is none */
};

/* derived names: slot 7 of the vtable at 0x16acf08: the body handed to
 * FUN_007196a0, then the waiting point given to the body unless its x, y
 * and z are all zero, and the waiting rotation unless it is the identity,
 * each put back to (0, 0, 0, 1) once given */
void Object016acf08::slot7()
{
    FUN_007196a0(unknown68);
    if (unknown100.x != 0.0f || unknown100.y != 0.0f || unknown100.z != 0.0f) {
        unknown68->position = unknown100;
        unknown100 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
    }
    if (unknown110.x != 0.0f || unknown110.y != 0.0f || unknown110.z != 0.0f ||
        unknown110.w != 1.0f) {
        unknown68->rotation = unknown110;
        unknown110 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
    }
}
