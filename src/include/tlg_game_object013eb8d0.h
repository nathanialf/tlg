/* src/include/tlg_game_object013eb8d0.h: a class of the tree of vtables 0x16c0938 shares its
 * destructors with (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_OBJECT013EB8D0_H
#define TLG_GAME_OBJECT013EB8D0_H

struct Axes01000aa0; /* tlg_game_axes01000aa0.h */

/* derived names: the complete destructor of a class derived from the one
 * whose destructor is 0x13eb8e0, its own body empty, so the base destructor
 * runs as a tail call; slot 0 of the vtables at 0x16c0938 (stored by
 * FUN_00fe2710); 0x16d4de8 (stored by FUN_00fe2710 0x13eb8e0), slot 1
 * (0x13ebcd0) the deleting destructor calling 0x13eb8e0 before operator
 * delete. One body for the 2 vtables. The class form: Object013eb8d0 derives
 * from Object013eb8e0, whose destructor is the one at 0x13eb8e0 (its row
 * named for it, D15), and its own destructor is defined empty out of line. */
class Object013eb8e0 /* derived name */
{
  public:
    virtual ~Object013eb8e0();
};

class Object013eb8d0 : public Object013eb8e0 /* derived name */
{
  public:
    virtual ~Object013eb8d0();

    /* slot 2 of the vtable at 0x16c0938: the axes' six directions (FUN_01000aa0, in
     * func_01000ba0.cpp for its copies of the axes) */
    virtual Axes01000aa0 slot2() const; /* derived name */
};

#endif
