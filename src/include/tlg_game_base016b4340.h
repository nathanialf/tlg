/* src/include/tlg_game_base016b4340.h: a class between Base016b4560 and two
 * game classes (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_BASE016B4340_H
#define TLG_GAME_BASE016B4340_H

#include "tlg_game_base016b4560.h"

/* derived name: the class between Base016b4560 and the classes whose
 * vtables are 0x16b42b0, 0x16b4340 and 0x16abab8 (creators 0xaf0df0,
 * 0xaf1350, 0x5ab650): its
 * constructor, inlined, sets the kind to 0x4f and clears the int at +0x28 in
 * its body, both BEFORE the derived class's vptr store (`mov dword
 * [r15+0x24], 0x4f; mov dword [r15+0x28], 0` at 0xaf1468: two stores, as the
 * pair the code generator would merge must end a run of stores and the vptr
 * store comes after them); the base's zero kind and its own vptr store are
 * dead. The derived constructors set the kind again in their bodies (0x58,
 * 0x57, 0x51). Not traced further. */
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
