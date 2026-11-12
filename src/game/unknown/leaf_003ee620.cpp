/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9458
 * (config/vtables.derived.base.txt, stored by FUN_003ee550 FUN_003ee620 FUN_003ee6e0), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 9 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_003ee620 tears them down
 * (the Name at +0x24); the rest are not traced. */
class Object016a9458 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a9458();
    virtual void slot5(); /* derived name; FUN_003ee7a0, not traced */
    virtual void slot6(); /* derived name; FUN_003ee7b0, not traced */
    virtual void slot7(); /* derived name; FUN_003ee7c0, not traced */
    virtual void slot8(); /* derived name; FUN_000058a0, not traced */
    virtual void slot9(); /* derived name; FUN_001af750, not traced */

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_003ee6e0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a9458::~Object016a9458() {}
