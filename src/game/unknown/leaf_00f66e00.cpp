/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3ad0.h"

/* FUN_00f66fd0: slot 2, the key function: the base's slot 2, then the
 * vector at +0x110 and the int at +0x124 cleared. FUN_00f66e00 (D1) and
 * FUN_00f66ef0 (D0), the implicit destructor, are emitted with it; the base
 * class's inline destructor (FUN_013d65a0, FUN_013d6640) is emitted with the
 * base's vtable, in the unit of its key function (slot 2, func_00f6d1a0.cpp). */
void Object016ca148::slot2()
{
    Object016d3ad0::slot2();
    unknown110 = _mm_setzero_ps();
    unknown124 = 0;
}

/* derived name: the work slot 4 of each class derived from Object016ca148
 * hands its two constants to (a tail call) */
void FUN_00f67000(Object016ca148 *self, int, u64); /* derived name */

/* derived names: the first of the thirteen classes over Object016ca148
 * (vtables 0x16bf440 to 0x16bf800, made by FUN_00f59e00), each giving slot
 * 4 and nothing else. Slot 4 is the key function: the vtable and the
 * implicit destructor are emitted with it, the complete one 0x13d63d0
 * (Object016ca148's inlined after its own vptr store, which is dead under
 * the base's) and the deleting one 0x13d64c0; the thirteen classes'
 * destructors are that one body in every vtable. */
class Object016bf440 : public Object016ca148 /* derived name */
{
  public:
    virtual void slot4();
};

/* FUN_00f68e00 */
void Object016bf440::slot4()
{
    FUN_00f67000(this, 1, 3);
}
