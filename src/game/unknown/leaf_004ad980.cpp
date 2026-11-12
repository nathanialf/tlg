/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aa040
 * (config/vtables.derived.base.txt, stored by FUN_004ad800), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own
 * (declared; their bodies are not written here). Its own fields (from +0x24)
 * are not traced. */
class Object016aa040 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016aa040();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */
};

/* derived name: the complete destructor: the body is empty and the base's
 * destructor is inlined (its vptr store, then the two names). FUN_004ada00,
 * slot 1, is the deleting one. The destructor is the class's key function,
 * so this file emits the vtable. */
Object016aa040::~Object016aa040() {}
