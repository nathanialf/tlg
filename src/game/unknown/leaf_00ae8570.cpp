/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

#include "tlg_game_object016b78f0.h"

/* derived names: the complete destructor of a class derived from
 * Object016b78f0 (tlg_game_object016b78f0.h), its own body empty, so the
 * base destructor 0xbde1c0 runs as a tail call; slot 0 of the vtable at
 * 0x16b3e30 (stored by FUN_00ae8350), slot 1 (0xae8580) the deleting
 * destructor calling 0xbde1c0 before operator delete. Its own destructor
 * is defined empty out of line. */
class Object00ae8570 : public Object016b78f0 /* derived name */
{
  public:
    virtual ~Object00ae8570();
};

Object00ae8570::~Object00ae8570() {}
