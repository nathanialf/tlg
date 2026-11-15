/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ae258
 * (config/vtables.derived.base.txt, stored by FUN_00805d90 FUN_00805f80),
 * derived from Object016b9108: its destructor FUN_00805f80 ends with that
 * class's (the vtable 0x16b9108 stored, the Names at +0x10 and +0xc
 * released). Its members are traced only where the destructor releases
 * them: Names at +0x24 (in the base's tail), +0x2c, +0x30, +0x60 and +0xa0, three counted references from +0x48 and an array of Names at +0x68. */
class Object016ae258 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ae258();

  private:
    Name name24; /* +0x24 */
    u8 unknown28[0x4];
    Name name2c; /* +0x2c */
    Name name30; /* +0x30 */
    u8 unknown34[0x14];
    AtomicRef0045c470<Node00503fb0> held48; /* +0x48: a counted reference */
    AtomicRef0045c470<Node00503fb0> held50; /* +0x50: a counted reference */
    AtomicRef0045c470<Node00503fb0> held58; /* +0x58: a counted reference */
    Name name60;                            /* +0x60 */
    Array05943280<Name> names68;            /* +0x68: an array of Names */
    u8 unknown80[0x20];
    Name namea0; /* +0xa0 */
};

/* derived name: the complete destructor: nothing of its own; the members
 * are released, last first, then the base's. FUN_00806340, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ae258::~Object016ae258() {}
