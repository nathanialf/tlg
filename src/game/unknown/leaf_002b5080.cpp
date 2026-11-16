/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16a7ea8
 * (config/vtables.derived.base.txt, stored by FUN_002ae3c0 FUN_002aec50);
 * its destructor FUN_002aec50 (the row named for it, D15) is not written,
 * and its fields are not traced. */
class Object016a7ea8 /* derived name */
{
  public:
    virtual ~Object016a7ea8();

  private:
    u8 unknown8[0x418];
};

/* derived names: the class whose vtable is at 0x16a7f18
 * (config/vtables.derived.base.txt, stored by FUN_002b4bf0 FUN_002b5080),
 * derived from Object016a7ea8. Its members are traced only where the
 * destructor releases them: two arrays of Names at +0x420 and +0x438,
 * counted references at +0x450 and +0x498 with an array of them at +0x480
 * between (an instantiation of its own: its destructor is inlined), an
 * array of counted references at +0x4a0 (FUN_0134f620) and blocks at +0x538
 * and +0x550. */
class Object016a7f18 : public Object016a7ea8 /* derived name */
{
  public:
    virtual ~Object016a7f18();

  private:
    Array05943280<Name> names420;            /* +0x420 */
    Array05943280<Name> names438;            /* +0x438 */
    AtomicRef0045c470<Node00503fb0> held450; /* +0x450 */
    u8 unknown458[0x28];
    Array05943280<AtomicRef0045c470<Node00503fb0>> refs480; /* +0x480 */
    AtomicRef0045c470<Node00503fb0> held498;                /* +0x498 */
    Object0134f620 refs4a0;                                 /* +0x4a0 */
    u8 unknown4b8[0x80];
    OwnedBlock05943280 block538; /* +0x538 */
    u8 unknown540[0x10];
    OwnedBlock05943280 block550; /* +0x550 */
};

/* derived name: the complete destructor: nothing of its own; the members
 * are released, last first, then the base's destructor runs as a tail call.
 * FUN_002b5480, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
// NONMATCHING: the complete destructor: 1020 bytes in the base, smaller here: the array of references at +0x480 is
// destroyed by a call (an instantiation with more than one caller in the module); the base has it inlined
Object016a7f18::~Object016a7f18() {}
