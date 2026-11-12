/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16a95d8
 * (config/vtables.derived.base.txt, stored by FUN_003f3110 FUN_003f3bf0), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 9 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_003f3bf0 tears them down
 * (the arrays of Names at +0x70, +0x58, +0x40, +0x28, the Names at +0x94, +0x90, +0x8c, +0x88); the rest are not traced. */
class Object016a95d8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a95d8();
    virtual void slot5(); /* derived name; FUN_003f3ff0, not traced */
    virtual void slot6(); /* derived name; FUN_003f4000, not traced */
    virtual void slot7(); /* derived name; FUN_003f4010, not traced */
    virtual void slot8(); /* derived name; FUN_000058a0, not traced */
    virtual void slot9(); /* derived name; FUN_001af750, not traced */

  private:
    u8 unknown24[0x4];
    /* +0x28: an array of Names (the block at +0x28, the count at +0x30): the destructor releases each
     * (`mov r12, [r14+0x28]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> names28;
    /* +0x40: an array of Names (the block at +0x40, the count at +0x48): the destructor releases each
     * (`mov r12, [r14+0x40]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> names40;
    /* +0x58: an array of Names (the block at +0x58, the count at +0x60): the destructor releases each
     * (`mov r12, [r14+0x58]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> names58;
    /* +0x70: an array of Names (the block at +0x70, the count at +0x78): the destructor releases each
     * (`mov r12, [r14+0x70]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> names70;
    Name name88; /* +0x88: released by the destructor (`mov eax, [rbx+0x88]; shl 5`) */
    Name name8c; /* +0x8c: released by the destructor (`mov eax, [rbx+0x8c]; shl 5`) */
    Name name90; /* +0x90: released by the destructor (`mov eax, [rbx+0x90]; shl 5`) */
    Name name94; /* +0x94: released by the destructor (`mov eax, [rbx+0x94]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_003f3fd0, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016a95d8::~Object016a95d8() {}
