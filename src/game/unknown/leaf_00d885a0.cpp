/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0139d760.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16bae38
 * (config/vtables.derived.base.txt, stored by FUN_00d88310 FUN_00d885a0), derived from
 * Object0139d760 (the class whose destructor is 0x139d760): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_00d885a0 tears them
 * down (the counted reference at +0x170, the Name at +0x1c4); the rest are not traced. */
class Object016bae38 : public Object0139d760 /* derived name */
{
  public:
    virtual ~Object016bae38();

  private:
    u8 unknown8[0x168];
    /* +0x170: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held170;
    u8 unknown178[0x4c];
    Name name1c4; /* +0x1c4: released by the destructor (`mov eax, [rbx+0x1c4]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_0139d760 runs as a tail call. FUN_00d88690, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016bae38::~Object016bae38() {}
