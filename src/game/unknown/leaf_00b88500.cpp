/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b70b0
 * (config/vtables.derived.base.txt, stored by FUN_00b87da0 FUN_00b88500 FUN_00b885c0), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_00b88500 tears them down
 * (the Name at +0x34); the rest are not traced. */
class Object016b70b0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b70b0();
    virtual void slot5(); /* derived name; FUN_00b88680, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */

  private:
    u8 unknown24[0x10];
    Name name34; /* +0x34: released by the destructor (`mov eax, [rbx+0x34]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_00b885c0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b70b0::~Object016b70b0() {}
