/* src/include/tlg_game_object00774560.h: the class whose vtable is at
 * 0x16acd78 and whose destructor is 0x774560, a base of several game classes
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT00774560_H
#define TLG_GAME_OBJECT00774560_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16acd78
 * (config/vtables.derived.base.txt, stored by FUN_00774370 and its two
 * destructors), derived from Object016b9108: its slots 2 to 4 are the
 * base's, slots 5 to 22 its own (declared; their bodies are not written).
 * The classes of leaf_00761150.cpp, leaf_00765600.cpp and the others that
 * include this header derive from it: their destructors tail-call its
 * complete destructor (FUN_00774560, leaf_00774560.cpp), the key function.
 * Its own fields from +0x24 are traced only where that destructor releases
 * them (the Names at +0xe4, +0xe0). */
class Object00774560 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object00774560();
    virtual void slot5();  /* derived name; FUN_001af750, not traced */
    virtual void slot6();  /* derived name; FUN_00774760, not traced */
    virtual void slot7();  /* derived name; FUN_00774820, not traced */
    virtual void slot8();  /* derived name; FUN_00774890, not traced */
    virtual void slot9();  /* derived name; FUN_007748a0, not traced */
    virtual void slot10(); /* derived name; FUN_007748b0, not traced */
    virtual void slot11(); /* derived name; FUN_007748c0, not traced */
    virtual void slot12(); /* derived name; FUN_007748d0, not traced */
    virtual void slot13(); /* derived name; FUN_007748e0, not traced */
    virtual void slot14(); /* derived name; FUN_007748f0, not traced */
    virtual void slot15(); /* derived name; FUN_00774900, not traced */
    virtual void slot16(); /* derived name; FUN_00774910, not traced */
    virtual void slot17(); /* derived name; FUN_00774920, not traced */
    virtual void slot18(); /* derived name; FUN_00774930, not traced */
    virtual void slot19(); /* derived name; FUN_00774940, not traced */
    virtual void slot20(); /* derived name; FUN_00774950, not traced */
    virtual void slot21(); /* derived name; FUN_00774b50, not traced */
    virtual void slot22(); /* derived name; FUN_000058a0, not traced */

  private:
    u8 unknown24[0xbc];
    Name namee0; /* +0xe0: released by the destructor (`mov eax, [rbx+0xe0]; shl 5`) */
    Name namee4; /* +0xe4: released by the destructor (`mov eax, [rbx+0xe4]; shl 5`) */
};

#endif
