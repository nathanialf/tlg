/* src/include/tlg_game_base016b4560.h: a class between Object016b9108 and
 * six game classes (game region; docs/TARGETS.md). Every name here is
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

#endif
