/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16b1d40
 * (config/vtables.derived.base.txt, stored by FUN_00a2a0f0 FUN_00a2b780 FUN_00a2b820), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_00a2b780 tears them down
 * (the record at +0x38); the rest are not traced. */
class Object016b1d40 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b1d40();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */

  private:
    u8 unknown24[0x14];
    /* +0x38: torn down by the destructor (`lea rdi, [rbx+0x38]; call FUN_0134f620`) */
    Object0134f620 record38;
};

/* derived name: the complete destructor: the records, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_00a2b820, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b1d40::~Object016b1d40()
{
    FUN_0134f620(&record38);
}
