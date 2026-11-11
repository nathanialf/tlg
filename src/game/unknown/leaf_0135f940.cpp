/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16cb338
 * (config/vtables.derived.base.txt): its complete destructor 0x135f940 stores
 * the vtable and destroys the Name at +0x20 (the reference released, the index
 * cleared); the deleting one 0x135f990 is the compiler's (the cleared index is a
 * dead store before operator delete there). The destructor is the class's key
 * function, so this file emits the vtable. The other members are not
 * traced. */
class Object0135f940 /* derived name */
{
  public:
    virtual ~Object0135f940();

  private:
    u8 unknown8[0x18];
    Name unknown20; /* +0x20 */
};

Object0135f940::~Object0135f940() {}
