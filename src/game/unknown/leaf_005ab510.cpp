/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016cb168.h"

/* derived names: the class whose vtable is at 0x16aba80
 * (config/vtables.derived.base.txt, stored by FUN_005ab380), derived from
 * Object016cb168 (the destructor FUN_005ab510 stores that class's vptr,
 * 0x16cb178, tears its record at +0x28 down and goes on to Object016b9108's
 * names): its five slots are the destructors and Object016b9108's three. It
 * has no member with a destructor of its own; its fields are not traced. */
class Object016aba80 : public Object016cb168 /* derived name */
{
  public:
    virtual ~Object016aba80();
};

/* derived name: the complete destructor: the body is empty and the base's
 * destructor is inlined. FUN_005ab5b0, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
Object016aba80::~Object016aba80() {}
