/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16cae00
 * (config/vtables.derived.base.txt): its complete destructor 0x1388080 stores
 * the vtable and destroys the Name at +0x10 (the reference released, the index
 * cleared); the deleting one 0x13880d0 is the compiler's (the cleared index is a
 * dead store before operator delete there). The destructor is the class's key
 * function, so this file emits the vtable. The other members are not
 * traced. */
class Object01388080 /* derived name */
{
  public:
    virtual ~Object01388080();

  private:
    u8 unknown8[0x8];
    Name unknown10; /* +0x10 */
};

Object01388080::~Object01388080() {}
