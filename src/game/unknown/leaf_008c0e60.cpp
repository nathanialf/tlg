/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16b0140
 * (config/vtables.derived.base.txt, stored by FUN_008c0cd0 FUN_008c0e60), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_008c0e60 tears them
 * down (the counted reference at +0x28, the Name at +0x30, the record at +0x38); the rest are not traced. */
class Object016b0140 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b0140();

  private:
    u8 unknown24[0x4];
    /* +0x28: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held28;
    Name name30; /* +0x30: released by the destructor (`mov eax, [rbx+0x30]; shl 5`) */
    u8 unknown34[0x4];
    /* +0x38: torn down by the destructor (`lea rdi, [rbx+0x38]; call 0x134f620`) */
    Object0134f620 record38;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_008c0fc0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b0140::~Object016b0140() {}
