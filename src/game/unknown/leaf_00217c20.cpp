/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16a7818
 * (config/vtables.derived.base.txt, stored by FUN_00217680 FUN_00217c20), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_00217c20 tears them down
 * (the array of Names at +0x38, the Name at +0x50, the records at +0x70, +0x58); the rest are not traced. */
class Object016a7818 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a7818();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */

  private:
    u8 unknown24[0x14];
    /* +0x38: an array of Names (the block at +0x38, the count at +0x40): the destructor releases each
     * (`mov r12, [r14+0x38]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> names38;
    Name name50; /* +0x50: released by the destructor (`mov eax, [rbx+0x50]; shl 5`) */
    u8 unknown54[0x4];
    /* +0x58: torn down by the destructor (`lea rdi, [rbx+0x58]; call 0x134f620`) */
    Object0134f620 record58;
    u8 unknown68[0x8];
    /* +0x70: torn down by the destructor (`lea rdi, [rbx+0x70]; call 0x134f620`) */
    Object0134f620 record70;
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_00217d90, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016a7818::~Object016a7818() {}
