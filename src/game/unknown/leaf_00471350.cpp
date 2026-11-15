/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16a9b50
 * (config/vtables.derived.base.txt, stored by FUN_004710c0 FUN_00471350), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's). Its own fields
 * from +0x34 are traced only where its destructor FUN_00471350 tears them down
 * (the Names at +0x78, +0x74, +0x38, +0x34); the rest are not traced. */
class Object016a9b50 : public Object01343880 /* derived name */
{
  public:
    virtual ~Object016a9b50();

  private:
    Name name34; /* +0x34: released by the destructor (`mov eax, [rbx+0x34]; shl 5`) */
    Name name38; /* +0x38: released by the destructor (`mov eax, [rbx+0x38]; shl 5`) */
    u8 unknown3c[0x38];
    Name name74; /* +0x74: released by the destructor (`mov eax, [rbx+0x74]; shl 5`) */
    Name name78; /* +0x78: released by the destructor (`mov eax, [rbx+0x78]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_004714a0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a9b50::~Object016a9b50() {}
