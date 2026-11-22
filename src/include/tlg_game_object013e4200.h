/* src/include/tlg_game_object013e4200.h: two classes of one form, over
 * Object016d3ef8 and Object016d6b08, each the base of three classes that own
 * an object at +0x460 (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_OBJECT013E4200_H
#define TLG_GAME_OBJECT013E4200_H

#include "tlg_game_object016d3ef8.h"
#include "tlg_game_object016d6b08.h"
#include "tlg_simd.h"
#include "tlg_types.h"

/* derived name: the object at +0x460 of the classes below, deleted by the
 * destructors of the classes derived from them through its virtual deleting
 * destructor (slot 1 of its vtable, skipped for null); not traced beyond it */
class Owned013e4200 /* derived name */
{
  public:
    virtual ~Owned013e4200();
};

/* derived names: the class whose destructor is FUN_013e4200 (its row named
 * for it, D15), the one that stores the vtable at 0x16ca608
 * (config/vtables.derived.base.txt), derived from Object016d3ef8: the
 * destructor gives back the blocks of the arrays at +0x538, +0x520, +0x4a0,
 * +0x488, +0x470, +0xa8, +0x90 and +0x78 and runs the base's. Slot 2
 * (FUN_013e2050, leaf_013e2050.cpp) is the base's slot 2, then the vector at
 * +0x510 cleared; the classes of 0x16ca660, 0x16ca6b8 and 0x16ca710 derived
 * from it keep it, and each of their destructors deletes the object at
 * +0x460. The rest is not traced. */
class Object013e4200 : public Object016d3ef8 /* derived name */
{
  public:
    virtual ~Object013e4200();
    virtual void slot2(); /* derived name */

  protected:
    u8 unknown70[0x3f0];
    Owned013e4200 *unknown460; /* +0x460: deleted by the derived classes' destructors */
    u8 unknown468[0xa8];
    Vec4 unknown510; /* +0x510: cleared by slot 2 */
};

/* derived names: the same form over Object016d6b08: the class whose
 * destructor is FUN_0147ec30 (its row named for it, D15), the one that
 * stores the vtable at 0x16caa98, the same bytes as FUN_013e4200's but for
 * the addresses; slot 2 FUN_0147d7c0 (leaf_0147d7c0.cpp) */
class Object0147ec30 : public Object016d6b08 /* derived name */
{
  public:
    virtual ~Object0147ec30();
    virtual void slot2(); /* derived name */

  protected:
    u8 unknown70[0x3f0];
    Owned013e4200 *unknown460; /* +0x460: deleted by the derived classes' destructors */
    u8 unknown468[0xa8];
    Vec4 unknown510; /* +0x510: cleared by slot 2 */
};

#endif
