/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16a9328
 * (config/vtables.derived.base.txt, stored by FUN_003ebf60 FUN_003ec8f0 FUN_003ec990), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 9 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_003ec8f0 tears them down
 * (the record at +0x28); the rest are not traced. */
class Object016a9328 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a9328();
    virtual void slot5(); /* derived name; FUN_003eca30, not traced */
    virtual void slot6(); /* derived name; FUN_003eca70, not traced */
    virtual void slot7(); /* derived name; FUN_003ecac0, not traced */
    virtual void slot8(); /* derived name; FUN_003ecb10, not traced */
    virtual void slot9(); /* derived name; FUN_003ecb60, not traced */

  private:
    u8 unknown24[0x4];
    /* +0x28: torn down by the destructor (`lea rdi, [rbx+0x28]; call 0x134f620`) */
    Object0134f620 record28;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_003ec990, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a9328::~Object016a9328() {}
