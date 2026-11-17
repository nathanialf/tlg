/* src/include/tlg_game_object016a8430.h: the class whose vtable is at 0x16a8430
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8430_H
#define TLG_GAME_OBJECT016A8430_H

#include "tlg_game_block.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16a8430
 * (config/vtables.derived.base.txt, stored by FUN_002f9860 and
 * FUN_002fed80), derived from Object016b9108; slot 19 (FUN_00301db0) is FUN_003fcfb0 of the class at 0x16a96d0, byte for byte.
 * Slots 5 to 18 are not traced.
 * The creator FUN_002ef8b0 allocates 0x1a90 bytes (`mov edi, 0x1a90` before operator new). */
class Object016a8430 : public Object016b9108 /* derived name */
{
  public:
    Object016a8430(const Name &name);  /* FUN_002f9860, its row named after it (D15) */
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
    u8 unknown118[0x1978];
};

#endif
