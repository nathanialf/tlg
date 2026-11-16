/* src/include/tlg_game_object016abc00.h: the class whose vtable is at
 * 0x16abc00 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ABC00_H
#define TLG_GAME_OBJECT016ABC00_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"
#include "tlg_game_object05945a38.h"

/* derived name: the type of the object the constructor looks up (`mov rsi,
 * [0x598a628]` at 0x5c1088) */
extern Type00503fb0 *D_598a628;

/* derived names: the class of the object the constructor looks up, with
 * the lookup as its own inline function: the base loads the owner
 * (0x5c1068) BEFORE the name is made and the type (0x5c1088) AFTER it, so
 * the type is read inside a function the name is an argument of. Not traced
 * beyond that. */
struct Value005c0fe0 : Object016b9108 {
    static Value005c0fe0 *find(Object05945a38 *owner, const Name &name)
    {
        return static_cast<Value005c0fe0 *>(FUN_00cbc5a0(owner, D_598a628, name, 0));
    }
};

/* derived names: the class whose vtable is at 0x16abc00
 * (config/vtables.derived.base.txt, stored by FUN_005c0fe0 FUN_005c11b0
 * FUN_005c12d0), derived from Object01343880 (the pointer at +0x28 and the
 * int at +0x30 cleared before the vptr store, 0x5c1013): slots 7 and 8
 * override the base's (FUN_005c13f0, FUN_005c1540; declared, their bodies
 * are not members yet). Its own fields are traced where its constructor
 * FUN_005c0fe0 sets them and its destructor FUN_005c11b0 tears them down.
 * The destructor is the class's key function (leaf_005c11b0.cpp), so that
 * unit emits the vtable. */
class Object016abc00 : public Object01343880 /* derived name */
{
  public:
    Object016abc00(const Name &name); /* FUN_005c0fe0 */

    virtual ~Object016abc00();

    /* slot 7, FUN_005c13f0: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void FUN_001af750();
    /* slot 8, FUN_005c1540: named as the base's slot is; not traced */
    virtual void slot8();

  private:
    Array01343a80<Ref00503fb0<Object016b9108>> record38; /* +0x38: an array of counted references */
    /* +0x50: a counted reference, set by the constructor, released by the
     * destructor */
    AtomicRef0045c470<Object016b9108> held50;
};

#endif
