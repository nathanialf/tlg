/* src/include/tlg_game_object016b01f0.h: the class whose vtable is at
 * 0x16b01f0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B01F0_H
#define TLG_GAME_OBJECT016B01F0_H

#include "tlg_game_name.h"
#include "tlg_game_object016b0178.h"

/* derived names: the class whose vtable is at 0x16b01f0
 * (config/vtables.derived.base.txt, stored by FUN_008c1650 FUN_008c17c0),
 * derived from Object016b0178: its creator FUN_008c1650 inlines the base's
 * constructor (the 16 bytes at +0x24 from the constants at 0x1539230), then
 * stores this class's vptr and clears the two Names (`mov qword [r15+0x34],
 * 0`). 0x40 bytes (`mov edi, 0x40` before operator new). Slot 5
 * (FUN_01373a50) overrides the base's, slot 6 (FUN_01373a70) returns the
 * address of the Name at +0x38; both are written as free functions
 * (leaf_01373a50.cpp, leaf_01373a70.cpp). The destructor FUN_008c17c0 is
 * the key function; FUN_008c1920, the deleting one, calls it. */
class Object016b01f0 : public Object016b0178 /* derived name */
{
  public:
    Object016b01f0(const Name &name) : Object016b0178(name) {}

    virtual ~Object016b01f0();
    virtual void slot5(); /* derived name; FUN_01373a50 */
    virtual void slot6(); /* derived name; FUN_01373a70 */

  private:
    Name name34; /* +0x34: empty from the constructor, released by the destructor */
    Name name38; /* +0x38: empty from the constructor, released by the destructor first */
};

#endif
