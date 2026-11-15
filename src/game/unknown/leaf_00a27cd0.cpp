/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the 0x58-byte element of the array at +0x38 of
 * Object016b1c50, destroyed by FUN_0138bfe0, which the array's destructor
 * calls for each one (0xa27e30: `mov eax, ebx; imul rdi, rax, 0x58; add
 * rdi, [r15+0x38]; call 0x138bfe0`: the row named as its destructor, D15).
 * Not traced. */
class Object0138bfe0 /* derived name */
{
  public:
    ~Object0138bfe0();

  private:
    u8 unknown0[0x58];
};

/* derived names: the class whose vtable is at 0x16b1c50
 * (config/vtables.derived.base.txt, stored by FUN_00a27090 FUN_00a27cd0),
 * derived from Object016b9108: its destructor FUN_00a27cd0 ends with that
 * class's (the vtable 0x16b9108 stored, the Names at +0x10 and +0xc
 * released). Its members are traced only where the destructor releases
 * them: a counted reference at +0x28, the array of 0x58-byte elements at
 * +0x38, an array of Names at +0x50 and three Names from +0x68. */
class Object016b1c50 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b1c50();

  private:
    AtomicRef0045c470<Node00503fb0> held28; /* +0x28: a counted reference */
    u8 unknown30[0x8];
    Array05943280<Object0138bfe0> array38; /* +0x38 */
    Array05943280<Name> names50;           /* +0x50 */
    Name name68;                           /* +0x68 */
    Name name6c;                           /* +0x6c */
    Name name70;                           /* +0x70 */
};

/* derived name: the complete destructor: nothing of its own; the members
 * are released, last first, then the base's. FUN_00a27f80, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b1c50::~Object016b1c50() {}
