/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00c55550.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16d24f8
 * (config/vtables.derived.base.txt, stored by FUN_00d63f10 FUN_013ba440 FUN_013ba530), derived from
 * Object00c55550 (the class whose destructor is 0xc55550): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_013ba440 tears them
 * down (the counted reference at +0x240, the Name at +0x238); the rest are not traced. */
class Object016d24f8 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object016d24f8();

  private:
    u8 unknown8[0x230];
    Name name238; /* +0x238: released by the destructor (`mov eax, [rbx+0x238]; shl 5`) */
    u8 unknown23c[0x4];
    /* +0x240: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held240;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00c55550 runs as a tail call. FUN_013ba530, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
// NONMATCHING (the deleting destructor FUN_013ba530 only): an inline-cost margin: the build calls this
// destructor where the base inlines it (its vptr store is in FUN_013ba530 too)
Object016d24f8::~Object016d24f8() {}
