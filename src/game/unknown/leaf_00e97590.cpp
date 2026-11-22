/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_buffer00d650e0.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16be338
 * (config/vtables.derived.base.txt, stored by FUN_00e96f30 FUN_00e97590),
 * derived from Object016b9108: its destructor FUN_00e97590 ends with that
 * class's (the vtable 0x16b9108 stored, the Names at +0x10 and +0xc
 * released). Its members are traced only where the destructor releases
 * them: an array of Names at +0x28, a block at +0x40, a buffer at +0x58 and a counted reference at +0x90. */
class Object016be338 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016be338();

  private:
    Array05943280<Name> names28; /* +0x28: an array of Names */
    OwnedBlock05943280 block40;  /* +0x40: a block released by the destructor */
    u8 unknown48[0x10];
    Buffer00d650e0 buffer58; /* +0x58: a buffer (tlg_game_buffer00d650e0.h) */
    u8 unknown70[0x20];
    AtomicRef0045c470<Object016b9108> held90; /* +0x90: a counted reference */
};

/* derived name: the complete destructor: nothing of its own; the members
 * are released, last first, then the base's. FUN_00e977e0, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016be338::~Object016be338() {}
