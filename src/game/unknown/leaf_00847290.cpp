/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00818d10.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16aef90
 * (config/vtables.derived.base.txt, stored by FUN_00846c90 FUN_00847290), derived from
 * Object00818d10 (the class whose destructor is 0x818d10): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_00847290 tears them
 * down (the counted reference at +0xc0, the Names at +0x11c, +0x118, +0x110, +0x10c, +0x108, +0x104, +0x100, +0xa0); the rest are not traced. */
class Object016aef90 : public Object00818d10 /* derived name */
{
  public:
    virtual ~Object016aef90();

  private:
    u8 unknown8[0x98];
    Name namea0; /* +0xa0: released by the destructor (`mov eax, [rbx+0xa0]; shl 5`) */
    u8 unknowna4[0x1c];
    /* +0xc0: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> heldc0;
    u8 unknownc8[0x38];
    Name name100; /* +0x100: released by the destructor (`mov eax, [rbx+0x100]; shl 5`) */
    Name name104; /* +0x104: released by the destructor (`mov eax, [rbx+0x104]; shl 5`) */
    Name name108; /* +0x108: released by the destructor (`mov eax, [rbx+0x108]; shl 5`) */
    Name name10c; /* +0x10c: released by the destructor (`mov eax, [rbx+0x10c]; shl 5`) */
    Name name110; /* +0x110: released by the destructor (`mov eax, [rbx+0x110]; shl 5`) */
    u8 unknown114[0x4];
    Name name118; /* +0x118: released by the destructor (`mov eax, [rbx+0x118]; shl 5`) */
    Name name11c; /* +0x11c: released by the destructor (`mov eax, [rbx+0x11c]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00818d10 runs as a tail call. FUN_00847530, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016aef90::~Object016aef90() {}
