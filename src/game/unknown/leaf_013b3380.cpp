/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013671a0.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b9a30
 * (config/vtables.derived.base.txt, stored by FUN_00cf2bb0 FUN_013b3380 FUN_013b3430), derived from
 * Object013671a0 (the class whose destructor is 0x13671a0): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_013b3380 tears them
 * down (the counted reference at +0x100); the rest are not traced. */
class Object016b9a30 : public Object013671a0 /* derived name */
{
  public:
    virtual ~Object016b9a30();

  private:
    u8 unknown8[0xf8];
    /* +0x100: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held100;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_013671a0 runs as a tail call. FUN_013b3430, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b9a30::~Object016b9a30() {}
