/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16d0158
 * (config/vtables.derived.base.txt): its complete destructor 0x139d500 stores
 * the vtable and destroys the Name at +0xc (the reference released, the index
 * cleared); the deleting one 0x139d550 is the compiler's (the cleared index is a
 * dead store before operator delete there). The destructor is the class's key
 * function, so this file emits the vtable. The other members are not
 * traced. */
class Object0139d500 /* derived name */
{
  public:
    virtual ~Object0139d500();

  private:
    u8 unknown8[0x4];
    Name unknownc; /* +0xc */
};

Object0139d500::~Object0139d500() {}

/* derived names: the two classes over Object0139d500 whose vtables are at
 * 0x16d0130 and 0x16d0108 (config/vtables.derived.base.txt; stored by their
 * constructors 0xb73b40 and 0xb72c10): each a counted reference at +0x20,
 * dropped by the destructor before the base's (0x139d340 and 0x139d5a0, the
 * deleting ones 0x139d420 and 0x139d680). The other members are not
 * traced. */
class Object016d0130 : public Object0139d500 /* derived name */
{
  public:
    ~Object016d0130();

  private:
    u8 unknown10[0x10];
    Ref00503fb0<Object016b9108> unknown20; /* +0x20 */
};

Object016d0130::~Object016d0130() {}

class Object016d0108 : public Object0139d500 /* derived name */
{
  public:
    ~Object016d0108();

  private:
    u8 unknown10[0x10];
    Ref00503fb0<Object016b9108> unknown20; /* +0x20 */
};

Object016d0108::~Object016d0108() {}
