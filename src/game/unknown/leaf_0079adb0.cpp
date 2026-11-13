/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00774560.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16ad930
 * (config/vtables.derived.base.txt, stored by FUN_0079ab40 FUN_0079adb0), derived from
 * Object00774560: slots 2 to 22 are the base's or override them.
 * Its own fields are traced only where its destructor FUN_0079adb0 tears them
 * down (the counted references at +0x138, +0x108, the Name at +0xfc); the rest are not traced. */
class Object016ad930 : public Object00774560 /* derived name */
{
  public:
    virtual ~Object016ad930();

  private:
    u8 unknowne8[0x14];
    Name namefc; /* +0xfc: released by the destructor (`mov eax, [rbx+0xfc]; shl 5`) */
    u8 unknown100[0x8];
    /* +0x108: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held108;
    u8 unknown110[0x28];
    /* +0x138: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held138;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00774560 runs as a tail call. FUN_0079af20, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ad930::~Object016ad930() {}
