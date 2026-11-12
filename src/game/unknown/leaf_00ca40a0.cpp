/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b8db8
 * (config/vtables.derived.base.txt, stored by FUN_00ca3e70), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 15 its own
 * (declared; their bodies are not written here). Its own fields (from +0x24)
 * are not traced. */
class Object016b8db8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b8db8();
    virtual void slot5();  /* derived name; FUN_00ca41a0, not traced */
    virtual void slot6();  /* derived name; FUN_008f08d0, not traced */
    virtual void slot7();  /* derived name; FUN_008f08f0, not traced */
    virtual void slot8();  /* derived name; FUN_01373fc0, not traced */
    virtual void slot9();  /* derived name; FUN_013abfd0, not traced */
    virtual void slot10(); /* derived name; FUN_000042d0, not traced */
    virtual void slot11(); /* derived name; FUN_000042d0, not traced */
    virtual void slot12(); /* derived name; FUN_001af750, not traced */
    virtual void slot13(); /* derived name; FUN_00ca41b0, not traced */
    virtual void slot14(); /* derived name; FUN_001af750, not traced */
    virtual void slot15(); /* derived name; FUN_01373fd0, not traced */
};

/* derived name: the complete destructor: the body is empty and the base's
 * destructor is inlined (its vptr store, then the two names). FUN_00ca4120,
 * slot 1, is the deleting one. The destructor is the class's key function,
 * so this file emits the vtable. */
Object016b8db8::~Object016b8db8() {}
