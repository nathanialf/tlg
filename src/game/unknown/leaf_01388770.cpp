/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ce088.h"

/* derived names: the complete destructor of a class derived from
 * Object016ce088, its own body empty, so the base destructor runs as a tail
 * call; slot 0 of the vtable at 0x16ce088, slot 1 (0x1388850) the deleting
 * destructor calling 0x1388780 before operator delete. The class form:
 * Object01388770 derives from Object016ce088, whose destructor is the one at
 * 0x1388780 (its row named for it, D15, defined in leaf_01388780.cpp), and its own
 * destructor is defined empty out of line. */
class Object01388770 : public Object016ce088 /* derived name */
{
  public:
    virtual ~Object01388770();
};

Object01388770::~Object01388770() {}
