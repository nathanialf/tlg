/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00774560.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16ad6d8
 * (config/vtables.derived.base.txt, stored by FUN_00794290 FUN_00794380), derived from
 * Object00774560: slots 2 to 22 are the base's or override them.
 * Its own fields are traced only where its destructor FUN_00794380 tears them
 * down (the counted reference at +0x100, the Name at +0xfc); the rest are not traced. */
class Object016ad6d8 : public Object00774560 /* derived name */
{
  public:
    virtual ~Object016ad6d8();

  private:
    u8 unknowne8[0x14];
    Name namefc; /* +0xfc: released by the destructor (`mov eax, [rbx+0xfc]; shl 5`) */
    /* +0x100: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held100;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00774560 runs as a tail call. FUN_00794470, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ad6d8::~Object016ad6d8() {}
