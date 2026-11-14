/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aef90.h"
#include "tlg_game_node.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16b6d10
 * (config/vtables.derived.base.txt, stored by FUN_00b78e50 FUN_00b7cab0), derived from
 * Object016aef90 (tlg_game_object016aef90.h): its destructor stores the vtable,
 * releases its own members, last first, then the base's destructor
 * FUN_00847290 runs as a tail call. Its own slots are not traced, nor its fields
 * other than those the destructor tears down. FUN_00b7cbd0, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
class Object016b6d10 : public Object016aef90 /* derived name */
{
  public:
    virtual ~Object016b6d10();

  private:
    u8 unknown120[0xb4];
    Name name1d4; /* +0x1d4: released by the destructor */
    Name name1d8; /* +0x1d8: released by the destructor */
    u8 unknown1dc[0x34];
    Ref00503fb0<Node00503fb0> held210; /* +0x210: a counted reference, released by the destructor */
};

Object016b6d10::~Object016b6d10() {}
