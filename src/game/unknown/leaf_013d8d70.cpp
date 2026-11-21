/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3e10.h"

/* derived names: the class whose vtable is at 0x16d3df0
 * (config/vtables.derived.base.txt), 0x50 bytes (its creator FUN_013d93b0
 * allocates them): an Object016d3e10 member at +0x10, which its destructor
 * empties before the member's own destructor runs (0x13d8e40, called with
 * this + 0x10). The other fields are not traced: the creator clears +0x28
 * and stores a constant point at +0x30. */
class Object016d3df0 /* derived name */
{
  public:
    virtual ~Object016d3df0();

  private:
    u8 unknown8[0x8];
    Object016d3e10 holder10; /* +0x10 */
    u8 unknown20[0x30];
};

// NONMATCHING: the member's address (this + 0x10) is formed after the exchange loop and kept
// across the release (`add r14, 0x10` before `test rbx, rbx`; the deleting destructor keeps
// it in r12 beside this); the base forms it at the call (`add r14, 0x10` / `lea rdi,
// [r14 + 0x10]` after the release). 25 of 55 equal.
Object016d3df0::~Object016d3df0()
{
    holder10.reset();
}
