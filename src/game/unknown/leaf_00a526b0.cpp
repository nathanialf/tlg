/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b1fd0
 * (config/vtables.derived.base.txt, stored by FUN_00a524e0 FUN_00a526b0 FUN_00a52770), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_00a526b0 tears them down
 * (the Name at +0x60); the rest are not traced. */
class Object016b1fd0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b1fd0();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */

  private:
    u8 unknown24[0x3c];
    Name name60; /* +0x60: released by the destructor (`mov eax, [rbx+0x60]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_00a52770, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b1fd0::~Object016b1fd0() {}
