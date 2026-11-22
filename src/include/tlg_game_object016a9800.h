/* src/include/tlg_game_object016a9800.h: the class whose vtable is at 0x16a9800
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9800_H
#define TLG_GAME_OBJECT016A9800_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the classes of the objects the two arrays of
 * Object016a9800 hold, each over the root (the elements are released only;
 * not traced). Each array's destructor is its own instantiation, called
 * once in the module, so the link inlines both into the class's
 * destructor. */
class Item016a9800_30 : public Object016b9108 /* derived name */
{
};

class Item016a9800_50 : public Object016b9108 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16a9800
 * (config/vtables.derived.base.txt, stored by FUN_00407ab0 FUN_00407c50), 0x70 bytes
 * (`mov edi, 0x70` before operator new in its creator FUN_00407950),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00407ab0 and its destructor FUN_00407c50, the key function, are in
 * leaf_00407c50.cpp. */
class Object016a9800 : public Object016b9108 /* derived name */
{
  public:
    Object016a9800(const Name &name); /* FUN_00407ab0 */
    virtual ~Object016a9800();

  private:
    u8 unknown24[0x4];
    /* +0x28: set by compare-and-swap to the object the constructor makes */
    AtomicRef0045c470<Object016b9108> held28;
    Array01343a80<Ref00503fb0<Item016a9800_30>> array30; /* +0x30 */
    int unknown48; /* +0x48: 0 from the constructor; not traced */
    Array01343a80<Ref00503fb0<Item016a9800_50>> array50; /* +0x50 */
    float unknown68; /* +0x68: 25 from the constructor; not traced */
    u8 unknown6c[0x4];
};

#endif
