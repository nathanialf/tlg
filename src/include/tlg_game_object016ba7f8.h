/* src/include/tlg_game_object016ba7f8.h: the class whose vtable is at
 * 0x16ba7f8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BA7F8_H
#define TLG_GAME_OBJECT016BA7F8_H

#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived name: the objects the array at +0xa0 holds (counted, derived
 * from the root class); not traced. The array's destructor over them is
 * this unit's alone and has one caller, so the link inlines it in the
 * destructor below, as the base shows (no call to 0x134f620) */
class ElementA0016ba7f8 : public Object016b9108
{
};

class Object016ba7f8;

/* derived name: called first by the destructor below and by
 * FUN_00d636f0 (leaf_00d636f0.cpp); not traced */
void FUN_00d5c810(Object016ba7f8 *self);

/* derived names: the class whose vtable is at 0x16ba7f8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00d5bd60
 * and its destructor FUN_00d5c340), derived from Object016b9108. Its fields
 * are traced where the destructor tears them down: counted references at
 * +0x50, +0x70 and +0xb8 to +0xc8, names at +0x60, +0x78 and +0x170 and an
 * array of references at +0xa0. */
class Object016ba7f8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ba7f8();

  private:
    u8 unknown24[0x2c];
    Ref00503fb0<Object016b9108> held50; /* +0x50 */
    u8 unknown58[0x8];
    Name name60; /* +0x60 */
    u8 unknown64[0xc];
    Ref00503fb0<Object016b9108> held70; /* +0x70 */
    Name name78;                        /* +0x78 */
    u8 unknown7c[0x4];

  public:
    /* +0x80: cleared by the derived class's slot 8 once it has handed the
     * object on (FUN_00b4b950) */
    int unknown80;

  private:
    u8 unknown84[0x1c];
    Array05943280<Ref00503fb0<ElementA0016ba7f8>> arrayA0; /* +0xa0 */
    Ref00503fb0<Object016b9108> heldB8;                    /* +0xb8 */
    Ref00503fb0<Object016b9108> heldC0;                    /* +0xc0 */
    Ref00503fb0<Object016b9108> heldC8;                    /* +0xc8 */
    u8 unknownD0[0xa0];
    Name name170; /* +0x170 */
};

#endif
