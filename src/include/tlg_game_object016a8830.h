/* src/include/tlg_game_object016a8830.h: the class whose vtable is at 0x16a8830
 * and the class between it and Object016c7948 (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8830_H
#define TLG_GAME_OBJECT016A8830_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016c7948.h"

/* derived names: the class whose vtable is at 0x16c7608
 * (config/vtables.derived.base.txt), derived from Object016c7948: FUN_00344a60
 * stores it after 0x16c7948 and sets the int at +0x298 to 1 next. Its
 * destructor is the empty one folded at 0x511160 (leaf_00511160.cpp). Its
 * other fields are not traced. */
class Object016c7608 : public Object016c7948 /* derived name */
{
  public:
    virtual ~Object016c7608();

  protected:
    int unknown298; /* +0x298 */
};

/* derived names: the class whose vtable is at 0x16a8830
 * (config/vtables.derived.base.txt, stored last by its constructor
 * FUN_00344a60, its row named for it, D15), derived from Object016c7608.
 * 0x2f0 bytes (`mov edi, 0x2f0` before operator new in its creator
 * FUN_00344900). Its fields are not traced. */
class Object016a8830 : public Object016c7608 /* derived name */
{
  public:
    Object016a8830(const Name &name); /* FUN_00344a60 */
    virtual ~Object016a8830();

  private:
    u8 unknown29c[0x54];
};

#endif
