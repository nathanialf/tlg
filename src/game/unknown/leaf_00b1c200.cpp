/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b4e70
 * (config/vtables.derived.base.txt, stored by FUN_00b1bff0 FUN_00b1c200),
 * derived from Object016b9108: its destructor FUN_00b1c200 ends with that
 * class's (the vtable 0x16b9108 stored, the Names at +0x10 and +0xc
 * released). Its members are traced only where the destructor releases
 * them: Names at +0x4c and +0x50, an array of Names at +0x58, a block at +0x70 and counted references at +0x88, +0x90, +0x98 and +0xa8. */
class Object016b4e70 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b4e70();

  private:
    u8 unknown24[0x28];
    Name name4c;                 /* +0x4c */
    Name name50;                 /* +0x50 */
    Array05943280<Name> names58; /* +0x58: an array of Names */
    OwnedBlock05943280 block70;  /* +0x70: a block released by the destructor */
    u8 unknown78[0x10];
    AtomicRef0045c470<Node00503fb0> held88; /* +0x88: a counted reference */
    AtomicRef0045c470<Node00503fb0> held90; /* +0x90: a counted reference */
    AtomicRef0045c470<Node00503fb0> held98; /* +0x98: a counted reference */
    u8 unknowna0[0x8];
    AtomicRef0045c470<Node00503fb0> helda8; /* +0xa8: a counted reference */
};

/* derived name: the complete destructor: nothing of its own; the members
 * are released, last first, then the base's. FUN_00b1c5e0, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b4e70::~Object016b4e70() {}
