/* src/include/tlg_game_object01481650.h: a class of the tree of vtables 0x16c2a68 shares its
 * destructors with (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_OBJECT01481650_H
#define TLG_GAME_OBJECT01481650_H

struct Axes01000aa0; /* tlg_game_axes01000aa0.h */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x1481660, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16c2a68 (stored by
 * FUN_0124f080); 0x16d74e8 (stored by FUN_0124f080 0x1481660), slot 1
 * (0x1481a50) the deleting destructor calling 0x1481660 before operator
 * delete. One body for the 2 vtables. The class form: Object01481650 derives
 * from Object01481660, whose destructor is the one at 0x1481660 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object01481660 /* derived name */
{
  public:
    virtual ~Object01481660();
};

class Object01481650 : public Object01481660 /* derived name */
{
  public:
    virtual ~Object01481650();

    /* slot 2 of the vtable at 0x16c2a68: the axes' six directions (FUN_0126c6f0, in
     * func_0126c7f0.cpp for its copies of the axes) */
    virtual Axes01000aa0 slot2() const; /* derived name */
};

#endif
