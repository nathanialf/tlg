/* src/include/tlg_game_object016a79e8.h: the class whose vtable is at
 * 0x16a79e8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A79E8_H
#define TLG_GAME_OBJECT016A79E8_H

#include "tlg_game_object016c7cb8.h"

/* derived names: the class whose vtable is at 0x16a79e8
 * (config/vtables.derived.base.txt, stored by FUN_00296100 FUN_002962e0),
 * derived from Object016c7cb8. 0x70 bytes (`mov edi, 0x70` before operator
 * new in the creator). Its destructor (FUN_002962e0, a loop over the
 * reference's records before the base's destructor) is not written, so
 * nothing here emits the vtable. */
class Object016a79e8 : public Object016c7cb8 /* derived name */
{
  public:
    /* inlined in the creator: the base built, the vptr, the 16 bytes at
     * +0x60 cleared (`vmovdqu [r15+0x60], xmm0`: two pointers) */
    Object016a79e8(const Name &name) : Object016c7cb8(name), unknown60(0), unknown68(0) {}

    virtual ~Object016a79e8();

  private:
    void *unknown60; /* +0x60: null from the constructor; not traced */
    void *unknown68; /* +0x68: null from the constructor; not traced */
};

#endif
