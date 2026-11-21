/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_object016d15b0.h"

/* derived names: the class whose vtable is at 0x16bac50
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00d81800
 * and its destructor FUN_00d81bf0), derived from Object016d15b0
 * (tlg_game_object016d15b0.h). Its fields are traced where the destructor
 * tears them down: eleven counted references from +0xb0 to +0x100, three
 * names from +0x108, three counted references from +0x118, a name at
 * +0x454 and four counted references from +0x470. */
class Object016bac50 : public Object016d15b0 /* derived name */
{
  public:
    virtual ~Object016bac50();

  private:
    u8 unknown90[0x20];
    Ref00503fb0<Object016b9108> heldb0;  /* +0xb0 */
    Ref00503fb0<Object016b9108> heldb8;  /* +0xb8 */
    Ref00503fb0<Object016b9108> heldc0;  /* +0xc0 */
    Ref00503fb0<Object016b9108> heldc8;  /* +0xc8 */
    Ref00503fb0<Object016b9108> heldd0;  /* +0xd0 */
    Ref00503fb0<Object016b9108> heldd8;  /* +0xd8 */
    Ref00503fb0<Object016b9108> helde0;  /* +0xe0 */
    Ref00503fb0<Object016b9108> helde8;  /* +0xe8 */
    Ref00503fb0<Object016b9108> heldf0;  /* +0xf0 */
    Ref00503fb0<Object016b9108> heldf8;  /* +0xf8 */
    Ref00503fb0<Object016b9108> held100; /* +0x100 */
    Name name108;                        /* +0x108 */
    Name name10c;                        /* +0x10c */
    Name name110;                        /* +0x110 */
    u8 unknown114[0x4];
    Ref00503fb0<Object016b9108> held118; /* +0x118 */
    Ref00503fb0<Object016b9108> held120; /* +0x120 */
    Ref00503fb0<Object016b9108> held128; /* +0x128 */
    u8 unknown130[0x324];
    Name name454; /* +0x454 */
    u8 unknown458[0x18];
    Ref00503fb0<Object016b9108> held470; /* +0x470 */
    Ref00503fb0<Object016b9108> held478; /* +0x478 */
    Ref00503fb0<Object016b9108> held480; /* +0x480 */
    Ref00503fb0<Object016b9108> held488; /* +0x488 */
};

/* derived name: the complete destructor: the body is empty; the members
 * are torn down, last first, then the base's inline destructor (its blocks
 * at +0x88 and +0x70), and Object00d30550's as a tail
 * call. FUN_00d826a0, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. */
Object016bac50::~Object016bac50() {}
