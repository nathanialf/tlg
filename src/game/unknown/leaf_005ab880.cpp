/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16abab8
 * (config/vtables.derived.base.txt, stored by FUN_005ab650 FUN_005ab880 FUN_005ab930), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 6 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_005ab880 tears them down
 * (the records at +0x78, +0x58, +0x30); the rest are not traced. */
class Object016abab8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016abab8();
    virtual void slot5(); /* derived name; FUN_001af750, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    u8 unknown24[0xc];
    /* +0x30: torn down by the destructor (`lea rdi, [rbx+0x30]; call 0x134f620`) */
    Object0134f620 record30;
    u8 unknown40[0x18];
    /* +0x58: torn down by the destructor (`lea rdi, [rbx+0x58]; call 0x134f620`) */
    Object0134f620 record58;
    u8 unknown68[0x10];
    /* +0x78: torn down by the destructor (`lea rdi, [rbx+0x78]; call 0x134f620`) */
    Object0134f620 record78;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_005ab930, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016abab8::~Object016abab8() {}
