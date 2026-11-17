/* src/include/tlg_game_object016acf08.h: the class whose vtable is at 0x16acf08
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ACF08_H
#define TLG_GAME_OBJECT016ACF08_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16acf08
 * (config/vtables.derived.base.txt, stored by its creator FUN_00777e10, where
 * its constructor is inlined after Object00774560's, 0x774370, called out of
 * line), derived from Object00774560: a point at +0x100 and a rotation at
 * +0x110 waiting to be given to the body (slot 7, leaf_00778080.cpp), and an
 * int at +0x120 that slot 6 tests (func_00775420.cpp). 0x130 bytes (`mov edi,
 * 0x130` before operator new in the creator). */
class Object016acf08 : public Object00774560 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, then (0, 0, 0, 1)
     * at +0x100 and +0x110 (one 32-byte constant) and 0 at +0x120 */
    Object016acf08(const Name &name)
        : Object00774560(name), unknown100(0.0f, 0.0f, 0.0f, 1.0f),
          unknown110(0.0f, 0.0f, 0.0f, 1.0f), unknown120(0)
    {
    }

    virtual ~Object016acf08();
    virtual void slot7(Pose0077bac0 *pose); /* FUN_00778080 */

  private:
    u8 unknownfc[0x4];
    Float4A unknown100; /* +0x100: a point, (0, 0, 0, 1) when there is none */
    Float4A unknown110; /* +0x110: a rotation, (0, 0, 0, 1) when there is none */
    int unknown120;     /* +0x120: 0 from the constructor; slot 6 tests it */
};

#endif
