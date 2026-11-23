/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ce038.h"

/* derived names: the complete destructor of a class derived from
 * Object016ce038, its own body empty, so the base destructor runs as a tail
 * call; slot 0 of the vtable at 0x16ce038, slot 1 (0x1388750) the deleting
 * destructor calling 0x1388680 before operator delete. The class form:
 * Object01388670 derives from Object016ce038, whose destructor is the one at
 * 0x1388680 (its row named for it, D15, defined in leaf_01388680.cpp), and its own
 * destructor is defined empty out of line. */
class Object01388670 : public Object016ce038 /* derived name */
{
  public:
    virtual ~Object01388670();
};

Object01388670::~Object01388670() {}
