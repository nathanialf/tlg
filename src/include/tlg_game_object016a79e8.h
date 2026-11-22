/* src/include/tlg_game_object016a79e8.h: the class whose vtable is at
 * 0x16a79e8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A79E8_H
#define TLG_GAME_OBJECT016A79E8_H

#include "tlg_game_links00c63970.h"
#include "tlg_game_object016c7cb8.h"

/* derived names: the class whose vtable is at 0x16a79e8
 * (config/vtables.derived.base.txt, stored by FUN_00296100 FUN_002962e0),
 * derived from Object016c7cb8. 0x70 bytes (`mov edi, 0x70` before operator
 * new in the creator). Its destructor (FUN_002962e0, leaf_002962e0.cpp: the
 * links of the object the reference at +0x28 holds taken out, then its
 * three names released, last first, before the base's destructor) is the
 * key function: that unit emits the vtable. */
class Object016a79e8 : public Object016c7cb8 /* derived name */
{
  public:
    /* inlined in the creator: the base built, the vptr, the 16 bytes at
     * +0x60 cleared (`vmovdqu [r15+0x60], xmm0`: the three names and the
     * int) */
    Object016a79e8(const Name &name) : Object016c7cb8(name), unknown6c(0) {}

    virtual ~Object016a79e8();
    /* slots 6 and 9, FUN_00296750 and FUN_00296740: free functions in
     * leaf_00296750.cpp and leaf_00296740.cpp until Object016c7cb8's slots 6
     * and 5, which they tail-call, have rows (a call to a member with no row
     * has no address for the layout) */
    void slot6(void *argument);
    void slot7(void *argument, Object016b9108 *item); /* FUN_00296a80, not written */
    void slot8();                                     /* FUN_00296460, not written */
    void slot9();
    /* slot 10, FUN_00296790 (738 bytes, not written): called by slot 6 while
     * the int at +0x6c is set */
    virtual void slot10(void *argument); /* derived name */

  private:
    /* +0x60, +0x64, +0x68: names, empty from the constructor, released by
     * the destructor (`mov eax, [rbx+0x68]; shl rax, 5` first) */
    Name name60;
    Name name64;
    Name name68;
    int unknown6c; /* +0x6c: zero from the constructor; set, slot 6 calls slot 10 first and clears it */
};

#endif
