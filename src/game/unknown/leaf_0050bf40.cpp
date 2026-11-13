/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16aae40
 * (config/vtables.derived.base.txt, stored by FUN_0050b7f0 FUN_0050bf40), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_0050bf40 tears them
 * down (the counted reference at +0x60, the Names at +0x48, +0x40, +0x3c, +0x28, +0x24); the rest are not traced. */
class Object016aae40 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016aae40();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    Name name28; /* +0x28: released by the destructor (`mov eax, [rbx+0x28]; shl 5`) */
    u8 unknown2c[0x10];
    Name name3c; /* +0x3c: released by the destructor (`mov eax, [rbx+0x3c]; shl 5`) */
    Name name40; /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
    u8 unknown44[0x4];
    Name name48; /* +0x48: released by the destructor (`mov eax, [rbx+0x48]; shl 5`) */
    u8 unknown4c[0x14];
    /* +0x60: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held60;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_0050c160, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016aae40::~Object016aae40() {}
