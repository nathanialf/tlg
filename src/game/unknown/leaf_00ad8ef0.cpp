/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01358d70.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b3b08
 * (config/vtables.derived.base.txt, stored by FUN_00ad8d30 FUN_00ad8ef0), derived from
 * Object01358d70 (the class whose destructor is 0x1358d70): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_00ad8ef0 tears them
 * down (the counted references at +0x1b0, +0x190, the Names at +0x1a4, +0x198); the rest are not traced. */
class Object016b3b08 : public Object01358d70 /* derived name */
{
  public:
    virtual ~Object016b3b08();

  private:
    u8 unknown8[0x188];
    /* +0x190: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held190;
    Name name198; /* +0x198: released by the destructor (`mov eax, [rbx+0x198]; shl 5`) */
    u8 unknown19c[0x8];
    Name name1a4; /* +0x1a4: released by the destructor (`mov eax, [rbx+0x1a4]; shl 5`) */
    u8 unknown1a8[0x8];
    /* +0x1b0: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held1b0;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_01358d70 runs as a tail call. FUN_00ad90a0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b3b08::~Object016b3b08() {}
