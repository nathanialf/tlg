/* src/include/tlg_game_object00d30550.h: the class whose destructor is
 * 0xd30550, a base of other game classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT00D30550_H
#define TLG_GAME_OBJECT00D30550_H

/* derived names: the class whose complete destructor is 0xd30550 (its row
 * named for it, D15). The classes derived from it tail-call that destructor
 * from their own (the files that include this header). The destructor is
 * not written, so nothing here emits the vtable; the class's other slots
 * and its fields are not traced. */
class Object00d30550 /* derived name */
{
  public:
    virtual ~Object00d30550();
};

#endif
