/* src/include/tlg_game_base016b4560.h: the classes between Object016b9108
 * and eight game classes (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_BASE016B4560_H
#define TLG_GAME_BASE016B4560_H

#include "tlg_game_object016b9108.h"

/* derived name: the class between Object016b9108 and the classes whose
 * vtables are 0x16b4488, 0x16b4560, 0x16b45a8, 0x16b45f0, 0x16b4638 and
 * 0x16b4680 (creators 0xaf8b40, 0xaf9310, 0xaf95f0, 0xaf98d0, 0xaf9bb0,
 * 0xaf9e90): its constructor, inlined, clears the int at +0x24 BEFORE the
 * derived class's vptr store (`mov dword [r15+0x24], 0` at 0xaf9428); its
 * own vptr store is dead. The derived constructors set the int again in
 * their bodies (0x5d, 0x59, 0x5b: a kind). Not traced further. */
class Base016b4560 : public Object016b9108 /* derived name */
{
  public:
    Base016b4560(const Name &name) : Object016b9108(name), kind(0) {}

  protected:
    int kind; /* +0x24 */ /* derived name */
};

/* derived name: the class between Base016b4560 and the classes whose
 * vtables are 0x16b4340 and 0x16abab8 (creators 0xaf1350, 0x5ab650): its
 * constructor, inlined, sets the kind to 0x4f and clears the int at +0x28 in
 * its body, both BEFORE the derived class's vptr store (`mov dword
 * [r15+0x24], 0x4f; mov dword [r15+0x28], 0` at 0xaf1468: two stores, as the
 * pair the code generator would merge must end a run of stores and the vptr
 * store comes after them); the base's zero kind and its own vptr store are
 * dead. The derived constructors set the kind again in their bodies (0x57,
 * 0x51). Not traced further. */
class Base016b4340 : public Base016b4560 /* derived name */
{
  public:
    Base016b4340(const Name &name) : Base016b4560(name)
    {
        kind = 0x4f;
        unknown28 = 0;
    }

  protected:
    int unknown28; /* +0x28: zero from the constructor; not traced */
};

#endif
