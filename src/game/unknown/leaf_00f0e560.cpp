/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00f0e560.h"

/* FUN_00f0e560 */
// NONMATCHING: the base's vtable stored last (`lea rcx, [0x16d3680]; mov [rdi], rcx` at 0xf0e591):
// Object013cd310's destructor has an empty body, which clang skips the store for
// (CanSkipVTablePointerInitialization), and its own out-of-line copy 0x13cd310 stores it too: what
// its body or fields hold is not known. FUN_00f0e5a0, the deleting destructor, drops the store and
// is equal.
Object00f0e560::~Object00f0e560()
{
    if (next18)
        next18->link10 = link10;
    if (link10)
        *link10 = next18;
    link10 = 0;
    next18 = 0;
}

/* derived names: the classes whose vtables are at 0x16beca8 and 0x16bed98
 * (config/vtables.derived.base.txt), entries of an intrusive list over
 * Object00f0e560: each destructor runs the class's own function first
 * (0xf0e0d0, 0xf0e430: not written), then the base's, inlined (the entry
 * taken out of its list). */
class Object016beca8 : public Object00f0e560 /* derived name */
{
  public:
    virtual ~Object016beca8();

    void FUN_00f0e0d0();
};

class Object016bed98 : public Object00f0e560 /* derived name */
{
  public:
    virtual ~Object016bed98();

    void FUN_00f0e430();
};

/* FUN_00f0e070; its deleting destructor FUN_00f0e1c0 */
// NONMATCHING: the base's vtable stored last, as FUN_00f0e560 (0xf0e0b9)
Object016beca8::~Object016beca8()
{
    FUN_00f0e0d0();
}

/* FUN_00f0e3d0; its deleting destructor FUN_00f0e500 */
// NONMATCHING: the base's vtable stored last, as FUN_00f0e560 (0xf0e419)
Object016bed98::~Object016bed98()
{
    FUN_00f0e430();
}
