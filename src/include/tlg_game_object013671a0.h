/* src/include/tlg_game_object013671a0.h: the class whose destructor is
 * 0x13671a0, a base of other game classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT013671A0_H
#define TLG_GAME_OBJECT013671A0_H

#include "tlg_game_object00ced570.h"

/* derived names: the class whose complete destructor is 0x13671a0 (its row
 * named for it, D15), derived from Object00ced570 (0x13671bf tail-calls
 * 0xced570). The classes derived from it tail-call that destructor from
 * their own (the files that include this header). The destructor is not
 * written, so nothing here emits the vtable; its own slots and its fields
 * (counted references at +0x68 and +0x70, released by its destructor) are
 * not traced. */
class Object013671a0 : public Object00ced570 /* derived name */
{
  public:
    virtual ~Object013671a0();
};

#endif
