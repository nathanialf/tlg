/* src/include/tlg_game_object00afd410.h: the base of the camera classes
 * FixCamera and FollowCamera (game region; docs/TARGETS.md). Every name here
 * is derived. */
#ifndef TLG_GAME_OBJECT00AFD410_H
#define TLG_GAME_OBJECT00AFD410_H

#include "tlg_game_name.h"

/* derived names: the class whose complete destructor is 0xafd410 (its row
 * named for it, D15; it stores the vtable at 0x16c7d08, no row). The camera
 * classes derived from it tail-call that destructor from their own; the
 * name at +0xc is the base's, released there. The destructor is not
 * written, so nothing here emits the vtable. */
class Object00afd410 /* derived name */
{
  public:
    virtual ~Object00afd410();

    u8 unknown8[4];
    Name unknownC; /* +0xc */
};

#endif
