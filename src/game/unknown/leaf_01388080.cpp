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

/* derived names: the class of the vtable at 0x16cdf90
 * (config/vtables.derived.base.txt), derived from the one above: a second
 * Name at +0x14, in the base's tail padding. Its complete destructor
 * 0x1387f60 releases it, then runs the base's (the base's vtable stored, its
 * Name at +0x10 released); the deleting one 0x1387ff0 is the compiler's. */
class Object016cdf90 : public Object01388080 /* derived name */
{
  public:
    virtual ~Object016cdf90();

  private:
    Name unknown14; /* +0x14 */
};

Object016cdf90::~Object016cdf90() {}
