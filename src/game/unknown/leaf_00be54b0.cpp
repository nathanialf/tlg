/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c7fb0.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b7a40
 * (config/vtables.derived.base.txt, stored by FUN_00be4a80 FUN_00be54b0 FUN_00be5560), derived from
 * Object016c7fb0 (tlg_game_object016c7fb0.h): its destructor stores the vtable,
 * releases its own members, last first, then the base's destructor
 * FUN_00be1980 runs as a tail call. Its own slots are not traced, nor its fields
 * other than those the destructor tears down. FUN_00be5560, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
class Object016b7a40 : public Object016c7fb0 /* derived name */
{
  public:
    virtual ~Object016b7a40();

  private:
    Ref00503fb0<Node00503fb0> heldd8; /* +0xd8: a counted reference, released by the destructor */
};

Object016b7a40::~Object016b7a40() {}
