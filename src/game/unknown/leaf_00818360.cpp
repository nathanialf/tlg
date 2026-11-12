/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ae6a0
 * (config/vtables.derived.base.txt, stored by FUN_008181f0 FUN_00818360 FUN_00818450), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_00818360 tears them down
 * (the Names at +0x40, +0x3c); the rest are not traced. */
class Object016ae6a0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ae6a0();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_00818540, not traced */
    virtual void slot8(); /* derived name; FUN_00818720, not traced */

  private:
    u8 unknown24[0x18];
    Name name3c; /* +0x3c: released by the destructor (`mov eax, [rbx+0x3c]; shl 5`) */
    Name name40; /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_00818450, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ae6a0::~Object016ae6a0() {}
