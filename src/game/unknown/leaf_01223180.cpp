/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d6a90.h"

/* derived name: slot 2 of the base class (0x16d6a90), this file's copy of the
 * fade's update of its entries (func_01225a30.cpp), called on the object
 * directly */
void FUN_01478b40(Object016d6a90 *self); /* derived name */

/* FUN_01223180: slot 2, the key function: the base's slot 2, then the
 * vector at +0x110 and the int at +0x124 cleared (also slot 2 of the eight
 * classes derived from this one, 0x16c2118 to 0x16c2348). FUN_01222fb0 (D1)
 * and FUN_012230a0 (D0), the implicit destructor, are emitted with it; the
 * base class's inline destructor (FUN_0147a4d0, FUN_0147a570) with them. */
void Object016ca810::slot2()
{
    FUN_01478b40(this);
    unknown110 = _mm_setzero_ps();
    unknown124 = 0;
}

/* derived name: the work slot 4 of each class derived from Object016ca810
 * hands its two constants to (a tail call; the same 0x1e00-byte body as
 * FUN_00f67000, the second kept as 32 bits, the third as 64) */
void FUN_012231b0(Object016ca810 *self, int, u64); /* derived name */

/* derived names: the first of the eight classes over Object016ca810
 * (vtables 0x16c2118 to 0x16c2348, made by FUN_0121a680), each giving slot 4
 * and nothing else. Slot 4 is the key function: the vtable and the implicit
 * destructor are emitted with it, the complete one 0x147a300
 * (Object016ca810's inlined after its own vptr store, which is dead under
 * the base's) and the deleting one 0x147a3f0; the eight classes'
 * destructors are that one body in every vtable. */
class Object016c2118 : public Object016ca810 /* derived name */
{
  public:
    virtual void slot4();
};

/* FUN_01224fb0 */
void Object016c2118::slot4()
{
    FUN_012231b0(this, 0, 5);
}
