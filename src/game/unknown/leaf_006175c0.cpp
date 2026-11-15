/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16abdb8
 * (config/vtables.derived.base.txt, stored by FUN_00617420 FUN_006175c0 FUN_006176b0), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's). Its own fields
 * from +0x34 are traced only where its destructor FUN_006175c0 tears them down
 * (the Names at +0x78, +0x40); the rest are not traced. */
class Object016abdb8 : public Object01343880 /* derived name */
{
  public:
    virtual ~Object016abdb8();

  private:
    u8 unknown34[0xc];
    Name name40; /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
    u8 unknown44[0x34];
    Name name78; /* +0x78: released by the destructor (`mov eax, [rbx+0x78]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_006176b0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016abdb8::~Object016abdb8() {}
