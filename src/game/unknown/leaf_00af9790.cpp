/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16b45a8
 * (config/vtables.derived.base.txt, stored by FUN_00af95f0 FUN_00af9790 FUN_00af9830), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 6 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_00af9790 tears them down
 * (the record at +0x30); the rest are not traced. */
class Object016b45a8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b45a8();
    virtual void slot5(); /* derived name; FUN_001af750, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    u8 unknown24[0xc];
    /* +0x30: torn down by the destructor (`lea rdi, [rbx+0x30]; call 0x134f620`) */
    Object0134f620 record30;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_00af9830, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b45a8::~Object016b45a8() {}
