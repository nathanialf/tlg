/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00c55550.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16ae370
 * (config/vtables.derived.base.txt, stored by FUN_0080ab20 FUN_0080b220), derived from
 * Object00c55550 (the class whose destructor is 0xc55550): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_0080b220 tears them
 * down (the counted references at +0x268, +0x238, the Name at +0x31c); the rest are not traced. */
class Object016ae370 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object016ae370();

  private:
    u8 unknown8[0x230];
    /* +0x238: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held238;
    u8 unknown240[0x28];
    /* +0x268: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held268;
    u8 unknown270[0xac];
    Name name31c; /* +0x31c: released by the destructor (`mov eax, [rbx+0x31c]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00c55550 runs as a tail call. FUN_0080b390, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ae370::~Object016ae370() {}
