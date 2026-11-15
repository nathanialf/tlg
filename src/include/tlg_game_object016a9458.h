/* src/include/tlg_game_object016a9458.h: the class whose vtable is at
 * 0x16a9458 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9458_H
#define TLG_GAME_OBJECT016A9458_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9458
 * (config/vtables.derived.base.txt, stored by FUN_003ee550 FUN_003ee620
 * FUN_003ee6e0), derived from Object016b9108: its slots 2 to 4 are the
 * base's, slots 5 to 9 its own (declared; their bodies are not written
 * here). 0x28 bytes (`mov edi, 0x28` before operator new in its creator
 * FUN_003ee3f0). The destructor is the class's key function
 * (leaf_003ee620.cpp), so that unit emits the vtable. */
class Object016a9458 : public Object016b9108 /* derived name */
{
  public:
    Object016a9458(const Name &name); /* FUN_003ee550 */
    virtual ~Object016a9458();        /* FUN_003ee620 */
    virtual void slot5();             /* derived name; FUN_003ee7a0, not traced */
    virtual void slot6();             /* derived name; FUN_003ee7b0, not traced */
    virtual void slot7();             /* derived name; FUN_003ee7c0, not traced */
    virtual void slot8();             /* derived name; FUN_000058a0, not traced */
    virtual void slot9();             /* derived name; FUN_001af750, not traced */

  private:
    Name
        name24; /* +0x24: set by the constructor, released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
};

#endif
