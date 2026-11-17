/* src/include/tlg_game_object016a96d0.h: the class whose vtable is at 0x16a96d0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A96D0_H
#define TLG_GAME_OBJECT016A96D0_H

#include "tlg_game_block.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16a96d0
 * (config/vtables.derived.base.txt, stored by FUN_003fbc60 and
 * FUN_003fc620), derived from Object016b9108; slot 19 (FUN_003fcfb0) is FUN_00301db0 of the class at 0x16a8430, byte for byte.
 * Slots 5 to 18 are not traced.
 * The creator FUN_003f70d0 allocates 0x650 bytes (`mov edi, 0x650` before operator new). */
class Object016a96d0 : public Object016b9108 /* derived name */
{
  public:
    Object016a96d0(const Name &name);  /* FUN_003fbc60, its row named after it (D15) */
    virtual void slot5();              /* derived name; not traced */
    virtual void slot6();              /* derived name; not traced */
    virtual void slot7();              /* derived name; not traced */
    virtual void slot8();              /* derived name; not traced */
    virtual void slot9();              /* derived name; not traced */
    virtual void slot10();             /* derived name; not traced */
    virtual void slot11();             /* derived name; not traced */
    virtual void slot12();             /* derived name; not traced */
    virtual void slot13();             /* derived name; not traced */
    virtual void slot14();             /* derived name; not traced */
    virtual void slot15();             /* derived name; not traced */
    virtual void slot16();             /* derived name; not traced */
    virtual void slot17();             /* derived name; not traced */
    virtual void slot18();             /* derived name; not traced */
    virtual void beforeInterestTick(); /* derived name: slot 19 */

  private:
    u8 unknown24[0x6c];
    int state; /* +0x90: 1 skips the script call (derived name) */
    u8 unknown94[0x7c];
    Owner05943280 *heap; /* +0x110: the thread's heap while the slot runs (derived name) */
    u8 unknown118[0x538];
};

#endif
