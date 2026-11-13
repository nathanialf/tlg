/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00774560.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16ac990
 * (config/vtables.derived.base.txt, stored by FUN_00763020 FUN_007631b0), derived from
 * Object00774560: slots 2 to 22 are the base's or override them.
 * Its own fields are traced only where its destructor FUN_007631b0 tears them
 * down (the counted references at +0x120, +0x118, +0x110, the Names at +0x100, +0xfc); the rest are not traced. */
class Object016ac990 : public Object00774560 /* derived name */
{
  public:
    virtual ~Object016ac990();

  private:
    u8 unknowne8[0x14];
    Name namefc;  /* +0xfc: released by the destructor (`mov eax, [rbx+0xfc]; shl 5`) */
    Name name100; /* +0x100: released by the destructor (`mov eax, [rbx+0x100]; shl 5`) */
    u8 unknown104[0xc];
    /* +0x110: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held110;
    /* +0x118: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held118;
    /* +0x120: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held120;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00774560 runs as a tail call. FUN_007633d0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ac990::~Object016ac990() {}
