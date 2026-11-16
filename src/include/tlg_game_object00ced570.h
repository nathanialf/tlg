/* src/include/tlg_game_object00ced570.h: the class whose destructor is
 * 0xced570, a base of other game classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT00CED570_H
#define TLG_GAME_OBJECT00CED570_H

#include "tlg_game_object01343880.h"

class Object00ced570;

/* derived names: the object the pointer at +0x48 names; its pointer at
 * +0x20 names the holder back. Only that field is traced (the holder's
 * destructor clears both ends). */
struct Peer00ced570 /* derived name */
{
    inline void detach(); /* derived name */

    u8 unknown0[0x20];
    Object00ced570 *holder20; /* +0x20 */
};

/* derived names: the class whose complete destructor is 0xced570 (its row
 * named for it, D15) and whose vtable is 0x16b96c8: slots 5 and 6 are
 * Object01343880's, 7 and 8 its own (FUN_00cebe40, FUN_00cebf30). The
 * classes derived from it tail-call that destructor from their own (the
 * files that include this header). The destructor is the key function
 * (leaf_00ced570.cpp). Its constructor, inlined in the creators of
 * the derived classes, sets its fields BEFORE the derived class's vptr
 * store (0xceeb1f to 0xceeb4d: the base's pointer and int, the 24 bytes from
 * +0x38 cleared in `vmovdqu [r15+0x38], xmm0; mov qword [r15+0x48], 0`, a run
 * of zero stores made one memset, then 8, -1 and 1 from +0x50); a derived
 * constructor that assigns +0x50 to +0x5c again leaves those three dead
 * (0xcd6690: the four ints from a constant in one store). */
class Object00ced570 : public Object01343880 /* derived name */
{
  public:
    Object00ced570(const Name &name)
        : Object01343880(name), unknown38(0), unknown40(0), peer48(0), unknown50(8), unknown54(-1),
          unknown58(1)
    {
    }

    virtual ~Object00ced570();

    /* slot 7, FUN_00cebe40: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void FUN_001af750();
    /* slot 8, FUN_00cebf30 (leaf_00cebf30.cpp, an empty body); not traced */
    virtual void slot8();

  private:
    friend struct Peer00ced570;

    void *unknown38;      /* +0x38: null from the constructor; not traced */
    void *unknown40;      /* +0x40: null from the constructor; not traced */
    Peer00ced570 *peer48; /* +0x48: null from the constructor; detached by the destructor */

  protected:
    int unknown50; /* +0x50: 8 from the constructor; not traced */
    int unknown54; /* +0x54: -1 from the constructor; not traced */
    int unknown58; /* +0x58: 1 from the constructor; not traced */
    int unknown5c; /* +0x5c: not written by the constructor; not traced */
};

/* derived name: cuts the link from both ends where a holder is attached
 * (`mov rcx, [rax+0x20]; test rcx, rcx; je; mov qword [rcx+0x48], 0;
 * mov qword [rax+0x20], 0`). */
inline void Peer00ced570::detach()
{
    if (holder20 != 0) {
        holder20->peer48 = 0;
        holder20 = 0;
    }
}

#endif
