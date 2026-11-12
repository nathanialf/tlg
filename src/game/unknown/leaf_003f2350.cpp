/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16a9578
 * (config/vtables.derived.base.txt, stored by FUN_003f2070 FUN_003f2350), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 9 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_003f2350 tears them down
 * (the array of Names at +0x28, the Name at +0x40); the rest are not traced. */
class Object016a9578 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a9578();
    virtual void slot5(); /* derived name; FUN_003f24d0, not traced */
    virtual void slot6(); /* derived name; FUN_003f24e0, not traced */
    virtual void slot7(); /* derived name; FUN_003f24f0, not traced */
    virtual void slot8(); /* derived name; FUN_000058a0, not traced */
    virtual void slot9(); /* derived name; FUN_001af750, not traced */

  private:
    u8 unknown24[0x4];
    /* +0x28: an array of Names (the block at +0x28, the count at +0x30): the destructor releases each
     * (`mov r12, [r14+0x28]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> names28;
    Name name40; /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_003f24b0, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016a9578::~Object016a9578() {}
