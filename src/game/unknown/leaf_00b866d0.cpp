/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b7058
 * (config/vtables.derived.base.txt, stored by FUN_00b85c60 FUN_00b866d0), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies
 * are not written here).
 * Its own fields are traced only where its destructor FUN_00b866d0 tears them
 * down (the counted reference at +0x38, the Names at +0x44, +0x40); the rest are not traced. */
class Object016b7058 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b7058();
    virtual void slot5(); /* derived name; FUN_00b86870, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_00b87d60, not traced */
    virtual void slot8(); /* derived name; FUN_00b87d80, not traced */

  private:
    u8 unknown24[0x14];
    /* +0x38: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held38;
    Name name40; /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
    Name name44; /* +0x44: released by the destructor (`mov eax, [rbx+0x44]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_00b86850, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b7058::~Object016b7058() {}
