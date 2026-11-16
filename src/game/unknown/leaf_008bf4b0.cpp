/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived name: the counted object the array of references of the class
 * below refers to; nothing of it is traced but its base. */
class Node008bf4b0 : public Node00503fb0 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16b0060
 * (config/vtables.derived.base.txt, stored by FUN_008bf290 FUN_008bf4b0),
 * derived from Object016b9108: its destructor FUN_008bf4b0 ends with that
 * class's (the vtable 0x16b9108 stored, the Names at +0x10 and +0xc
 * released). Its members are traced only where the destructor releases
 * them: a Name at +0x2c, an array of counted references at +0x30, an array of Names at +0x48, three counted references from +0x60, an array of counted references at +0x78 and seven counted references from +0x90. */
class Object016b0060 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b0060();

  private:
    u8 unknown24[0x8];
    Name name2c;           /* +0x2c */
    Object0134f620 refs30; /* +0x30: an array of counted references, destroyed by FUN_0134f620 */
    Array05943280<Name> names48;            /* +0x48: an array of Names */
    AtomicRef0045c470<Node00503fb0> held60; /* +0x60: a counted reference */
    AtomicRef0045c470<Node00503fb0> held68; /* +0x68: a counted reference */
    AtomicRef0045c470<Node00503fb0> held70; /* +0x70: a counted reference */
    Array05943280<AtomicRef0045c470<Node008bf4b0>>
        refs78; /* +0x78: an array of counted references (references to a class of its own: the instantiation has this one caller, and its destructor is inlined, where the one at +0x30 is called) */
    AtomicRef0045c470<Node00503fb0> held90; /* +0x90: a counted reference */
    AtomicRef0045c470<Node00503fb0> held98; /* +0x98: a counted reference */
    AtomicRef0045c470<Node00503fb0> helda0; /* +0xa0: a counted reference */
    AtomicRef0045c470<Node00503fb0> helda8; /* +0xa8: a counted reference */
    AtomicRef0045c470<Node00503fb0> heldb0; /* +0xb0: a counted reference */
    AtomicRef0045c470<Node00503fb0> heldb8; /* +0xb8: a counted reference */
    AtomicRef0045c470<Node00503fb0> heldc0; /* +0xc0: a counted reference */
};

/* derived name: the complete destructor: nothing of its own; the members
 * are released, last first, then the base's. FUN_008bfc10, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b0060::~Object016b0060() {}
