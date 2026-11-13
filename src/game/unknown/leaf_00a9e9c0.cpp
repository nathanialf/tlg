/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b2d48
 * (config/vtables.derived.base.txt, stored by FUN_00a9adc0 FUN_00a9e9c0), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_00a9e9c0 tears them
 * down (the counted references at +0x98, +0x30, +0x28, the Names at +0x74, +0x44, +0x40, +0x3c, +0x38); the rest are not traced. */
class Object016b2d48 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b2d48();

  private:
    u8 unknown24[0x4];
    /* +0x28: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held28;
    /* +0x30: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held30;
    Name name38; /* +0x38: released by the destructor (`mov eax, [rbx+0x38]; shl 5`) */
    Name name3c; /* +0x3c: released by the destructor (`mov eax, [rbx+0x3c]; shl 5`) */
    Name name40; /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
    Name name44; /* +0x44: released by the destructor (`mov eax, [rbx+0x44]; shl 5`) */
    u8 unknown48[0x2c];
    Name name74; /* +0x74: released by the destructor (`mov eax, [rbx+0x74]; shl 5`) */
    u8 unknown78[0x20];
    /* +0x98: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held98;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_00a9ece0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b2d48::~Object016b2d48() {}
