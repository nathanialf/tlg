/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00774560.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16accb0
 * (config/vtables.derived.base.txt, stored by FUN_0076e4a0 FUN_0076e620), derived from
 * Object00774560: slots 2 to 22 are the base's or override them.
 * Its own fields are traced only where its destructor FUN_0076e620 tears them
 * down (the counted references at +0x188, +0x180, the Names at +0x14c, +0x148, +0x100); the rest are not traced. */
class Object016accb0 : public Object00774560 /* derived name */
{
  public:
    virtual ~Object016accb0();

  private:
    u8 unknowne8[0x18];
    Name name100; /* +0x100: released by the destructor (`mov eax, [rbx+0x100]; shl 5`) */
    u8 unknown104[0x44];
    Name name148; /* +0x148: released by the destructor (`mov eax, [rbx+0x148]; shl 5`) */
    Name name14c; /* +0x14c: released by the destructor (`mov eax, [rbx+0x14c]; shl 5`) */
    u8 unknown150[0x30];
    /* +0x180: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held180;
    /* +0x188: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held188;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00774560 runs as a tail call. FUN_0076e800, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016accb0::~Object016accb0() {}
