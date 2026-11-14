/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aa0d0.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16aa140
 * (config/vtables.derived.base.txt, stored by FUN_004b0570 FUN_004b0b10), derived from
 * Object016aa0d0 (tlg_game_object016aa0d0.h): its destructor stores the vtable,
 * releases its own members, last first, then the base's destructor
 * FUN_004af8a0 runs as a tail call. Its own slots are not traced, nor its fields
 * other than those the destructor tears down. FUN_004b0d40, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
class Object016aa140 : public Object016aa0d0 /* derived name */
{
  public:
    virtual ~Object016aa140();

  private:
    u8 unknown38[0x30];
    Ref00503fb0<Node00503fb0> held68; /* +0x68: a counted reference, released by the destructor */
    Ref00503fb0<Node00503fb0> held70; /* +0x70: a counted reference, released by the destructor */
    Ref00503fb0<Node00503fb0> held78; /* +0x78: a counted reference, released by the destructor */
    Ref00503fb0<Node00503fb0> held80; /* +0x80: a counted reference, released by the destructor */
};

Object016aa140::~Object016aa140() {}
