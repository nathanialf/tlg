/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b1bf0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_001bd010
 * and its destructor FUN_00a08d00), with no base whose destructor does
 * anything. Its fields are traced where the destructor tears them down:
 * eleven counted references from +0x10 to +0x60. */
class Object016b1bf0 /* derived name */
{
  public:
    virtual ~Object016b1bf0();

  private:
    u8 unknown8[0x8];
    Ref00503fb0<Object016b9108> held10; /* +0x10 */
    Ref00503fb0<Object016b9108> held18; /* +0x18 */
    Ref00503fb0<Object016b9108> held20; /* +0x20 */
    Ref00503fb0<Object016b9108> held28; /* +0x28 */
    Ref00503fb0<Object016b9108> held30; /* +0x30 */
    Ref00503fb0<Object016b9108> held38; /* +0x38 */
    Ref00503fb0<Object016b9108> held40; /* +0x40 */
    Ref00503fb0<Object016b9108> held48; /* +0x48 */
    Ref00503fb0<Object016b9108> held50; /* +0x50 */
    Ref00503fb0<Object016b9108> held58; /* +0x58 */
    Ref00503fb0<Object016b9108> held60; /* +0x60 */
};

/* derived name: the complete destructor: the body is empty; the
 * references are released, last first. FUN_00a092b0, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b1bf0::~Object016b1bf0() {}
