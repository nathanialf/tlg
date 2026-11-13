/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00c55550.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16b87c8
 * (config/vtables.derived.base.txt, stored by FUN_00c7f410 FUN_00c7fb50), derived from
 * Object00c55550 (the class whose destructor is 0xc55550): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_00c7fb50 tears them
 * down (the counted references at +0x3a0, +0x398, +0x378, +0x300, the Name at +0x360, the record at +0x380); the rest are not traced. */
class Object016b87c8 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object016b87c8();

  private:
    u8 unknown8[0x2f8];
    /* +0x300: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held300;
    u8 unknown308[0x58];
    Name name360; /* +0x360: released by the destructor (`mov eax, [rbx+0x360]; shl 5`) */
    u8 unknown364[0x14];
    /* +0x378: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held378;
    /* +0x380: torn down by the destructor (`lea rdi, [rbx+0x380]; call 0x134f620`) */
    Object0134f620 record380;
    u8 unknown390[0x8];
    /* +0x398: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held398;
    /* +0x3a0: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held3a0;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00c55550 runs as a tail call. FUN_00c7fdd0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b87c8::~Object016b87c8() {}
