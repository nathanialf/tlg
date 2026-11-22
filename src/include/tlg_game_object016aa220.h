/* src/include/tlg_game_object016aa220.h: the class whose vtable is at 0x16aa220
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AA220_H
#define TLG_GAME_OBJECT016AA220_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aa220
 * (config/vtables.derived.base.txt, stored by FUN_004b4ea0 FUN_004b5010), 0x90 bytes
 * (`mov edi, 0x90` before operator new in its creator FUN_004b4d40),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_004b4ea0 is not written. Its destructor FUN_004b5010, the key
 * function (leaf_004b5010.cpp), empties the reference at +0x50 by
 * compare-and-swap; the other fields are not traced. */
class Object016aa220 : public Object016b9108 /* derived name */
{
  public:
    Object016aa220(const Name &name); /* FUN_004b4ea0 */
    virtual ~Object016aa220();

  private:
    u8 unknown24[0x2c];
    /* +0x50: emptied by compare-and-swap in the destructor's body, then
     * released the plain way by its own destructor */
    AtomicRef0045c470<Object016b9108> held50;
    u8 unknown58[0x38];
};

#endif
