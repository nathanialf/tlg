/* src/include/tlg_game_object016acbe8.h: the class whose vtable is at 0x16acbe8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ACBE8_H
#define TLG_GAME_OBJECT016ACBE8_H

#include "tlg_game_links00c63970.h"
#include "tlg_game_name.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16acbe8
 * (config/vtables.derived.base.txt, stored by FUN_00767b40 FUN_00768000), 0x280 bytes
 * (`mov edi, 0x280` before operator new in its creator FUN_007679e0),
 * derived from Object00774560 (its constructor 0x767b40 first calls 0x774370, that
 * class's constructor). Its constructor is not written, and its fields are
 * not traced. */
class Object016acbe8 : public Object00774560 /* derived name */
{
  public:
    Object016acbe8(const Name &name); /* 0x767b40, its row named after it (D15) */
    virtual ~Object016acbe8();
    void slot15(); /* FUN_0076cd70 */

  private:
    u8 unknownfc[0x210 - 0xfc];
    /* +0x210: a counted reference to an object that holds links
     * (tlg_game_links00c63970.h), emptied by slot 15 */
    AtomicRef0045c470<Object016b9108> held210;
    u8 unknown218[0x280 - 0x218];
};

#endif
