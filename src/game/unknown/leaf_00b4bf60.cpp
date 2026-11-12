/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16b6590
 * (config/vtables.derived.base.txt, stored by FUN_00b4bda0 FUN_00b4bf60), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 10 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_00b4bf60 tears them down
 * (the array of Names at +0x60, the Names at +0x78, +0x54, +0x50); the rest are not traced. */
class Object016b6590 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b6590();
    virtual void slot5();  /* derived name; FUN_000058a0, not traced */
    virtual void slot6();  /* derived name; FUN_01343880, not traced */
    virtual void slot7();  /* derived name; FUN_00b4c530, not traced */
    virtual void slot8();  /* derived name; FUN_00b4c750, not traced */
    virtual void slot9();  /* derived name; FUN_00b4c160, not traced */
    virtual void slot10(); /* derived name; FUN_00b4c150, not traced */

  private:
    u8 unknown24[0x2c];
    Name name50; /* +0x50: released by the destructor (`mov eax, [rbx+0x50]; shl 5`) */
    Name name54; /* +0x54: released by the destructor (`mov eax, [rbx+0x54]; shl 5`) */
    u8 unknown58[0x8];
    /* +0x60: an array of Names (the block at +0x60, the count at +0x68): the destructor releases each
     * (`mov r12, [r14+0x60]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> names60;
    Name name78; /* +0x78: released by the destructor (`mov eax, [rbx+0x78]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_00b4c130, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016b6590::~Object016b6590() {}
