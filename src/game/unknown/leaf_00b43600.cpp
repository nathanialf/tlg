/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the 64-byte element of the array at +0x50 of the class
 * below: a block at +0x20 and a counted reference at +0x38, released for
 * each element when the array is destroyed (0xb43816: `mov r13, rbx; shl
 * r13, 6; mov r14, [r12+r13+0x38]`). The rest is not traced. */
struct Element00b43600 { /* derived name */
    u8 unknown0[0x20];
    OwnedBlock05943280 block20; /* +0x20 */
    u8 unknown28[0x10];
    Ref00503fb0<Node00503fb0> ref38; /* +0x38 */
};

/* derived names: the class whose vtable is at 0x16b5f18
 * (config/vtables.derived.base.txt, stored by FUN_00b433c0 FUN_00b43600),
 * derived from Object016b9108: its destructor FUN_00b43600 ends with that
 * class's (the vtable 0x16b9108 stored, the Names at +0x10 and +0xc
 * released). Its members are traced only where the destructor releases
 * them: an array of counted references at +0x38 (an instantiation of its own: its destructor is inlined), an array of 64-byte elements at +0x50, an array of Names at +0x70, counted references at +0x90 and +0xa0 and a Name at +0x98. */
class Object016b5f18 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b5f18();

  private:
    u8 unknown24[0x14];
    Array05943280<AtomicRef0045c470<Node00503fb0>>
        refs38; /* +0x38: an array of counted references (an instantiation of its own: its destructor is inlined, where the one at +0x30 is called) */
    Array05943280<Element00b43600> array50; /* +0x50: an array of 64-byte elements */
    u8 unknown68[0x8];
    Array05943280<Name> names70; /* +0x70: an array of Names */
    u8 unknown88[0x8];
    AtomicRef0045c470<Node00503fb0> held90; /* +0x90: a counted reference */
    Name name98;                            /* +0x98 */
    AtomicRef0045c470<Node00503fb0> helda0; /* +0xa0: a counted reference */
};

/* derived name: the complete destructor: nothing of its own; the members
 * are released, last first, then the base's. FUN_00b43ac0, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
// NONMATCHING: the complete destructor: 1214 bytes in the base, 988 here: an array's destructor is called where the
// base inlines it (the same class as 0x8bf4b0's)
Object016b5f18::~Object016b5f18() {}
