/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object00c55550.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16a7ce8 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_002a8650): it stores the vtable, releases its Name at +0x23c, then
 * tail-calls its base's destructor (0xc55550). FUN_002a8810, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. The other members are not traced. */
class Object016a7ce8 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object016a7ce8();

  private:
    u8 unknown8[0x234];
    Name name23c; /* +0x23c */
};

Object016a7ce8::~Object016a7ce8() {}
