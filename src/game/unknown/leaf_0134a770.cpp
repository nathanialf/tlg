/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16c7388
 * (config/vtables.derived.base.txt): its complete destructor 0x134a770 stores
 * the vtable and destroys the Name at +0x20 (the reference released, the index
 * cleared); the deleting one 0x134a7c0 is the compiler's (the cleared index is a
 * dead store before operator delete there). The destructor is the class's key
 * function, so this file emits the vtable. The other members are not
 * traced. */
class Object0134a7c0 /* derived name */
{
  public:
    virtual ~Object0134a7c0();

  private:
    u8 unknown8[0x18];
    Name unknown20; /* +0x20 */
};

Object0134a7c0::~Object0134a7c0() {}
