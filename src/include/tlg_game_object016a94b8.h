/* src/include/tlg_game_object016a94b8.h: the class whose vtable is at 0x16a94b8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A94B8_H
#define TLG_GAME_OBJECT016A94B8_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16a94b8
 * (config/vtables.derived.base.txt, stored by FUN_003eebc0 FUN_003ef3d0), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 9 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_003ef3d0 tears them down
 * (the array of Names at +0x28, the Names at +0x74, +0x70, +0x5c, +0x58, +0x54, +0x50, +0x4c, +0x48, +0x44, +0x40); the rest are not traced.
 * The creator FUN_003eea60 allocates 0x80 bytes (`mov edi, 0x80` before operator new). */
class Object016a94b8 : public Object016b9108 /* derived name */
{
  public:
    Object016a94b8(const Name &name); /* FUN_003eebc0, its row named after it (D15) */
    virtual ~Object016a94b8();
    virtual void slot5(); /* derived name; FUN_003ef730, not traced */
    virtual void slot6(); /* derived name; FUN_003ef740, not traced */
    virtual void slot7(); /* derived name; FUN_003ef750, not traced */
    virtual void slot8(); /* derived name; FUN_003f0640, not traced */
    virtual void slot9(); /* derived name; FUN_003f0c00, not traced */

  private:
    u8 unknown24[0x4];
    /* +0x28: an array of Names (the block at +0x28, the count at +0x30): the destructor releases each
     * (`mov r12, [r14+0x28]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> names28;
    Name name40; /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
    Name name44; /* +0x44: released by the destructor (`mov eax, [rbx+0x44]; shl 5`) */
    Name name48; /* +0x48: released by the destructor (`mov eax, [rbx+0x48]; shl 5`) */
    Name name4c; /* +0x4c: released by the destructor (`mov eax, [rbx+0x4c]; shl 5`) */
    Name name50; /* +0x50: released by the destructor (`mov eax, [rbx+0x50]; shl 5`) */
    Name name54; /* +0x54: released by the destructor (`mov eax, [rbx+0x54]; shl 5`) */
    Name name58; /* +0x58: released by the destructor (`mov eax, [rbx+0x58]; shl 5`) */
    Name name5c; /* +0x5c: released by the destructor (`mov eax, [rbx+0x5c]; shl 5`) */
    u8 unknown60[0x10];
    Name name70; /* +0x70: released by the destructor (`mov eax, [rbx+0x70]; shl 5`) */
    Name name74; /* +0x74: released by the destructor (`mov eax, [rbx+0x74]; shl 5`) */
    u8 unknown78[0x8];
};

#endif
