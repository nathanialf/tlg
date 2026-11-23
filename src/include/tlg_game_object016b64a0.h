/* src/include/tlg_game_object016b64a0.h: the class whose vtable is at
 * 0x16b64a0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B64A0_H
#define TLG_GAME_OBJECT016B64A0_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"
#include "tlg_game_array01343a80.h"

/* derived name: the class between Object01343880 and Object016b64a0: two
 * pointers at +0x38, cleared by its constructor (one 16-byte store BEFORE
 * the derived class's vptr store at 0xb4ac1e, where that class's own members
 * are cleared after it). No vtable of its own is known. */
class Base016b64a0 : public Object01343880 /* derived name */
{
  public:
    Base016b64a0(const Name &name) : Object01343880(name), unknown38(0), unknown40(0) {}

  protected:
    void *unknown38; /* +0x38: null from the constructor; not traced */
    void *unknown40; /* +0x40: null from the constructor; not traced */
};

/* derived names: the class whose vtable is at 0x16b64a0
 * (config/vtables.derived.base.txt, stored by FUN_00b4aaf0 FUN_0b4aca0
 * FUN_0b4adc0), derived from Base016b64a0. 0x68 bytes (`mov edi,
 * 0x68` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00b4aaf0 sets them and its destructor FUN_0b4aca0
 * tears them down. The destructor is the class's key function
 * (leaf_00b4aca0.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016b64a0 : public Base016b64a0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name (its two pointers at +0x38
     * cleared in one 16-byte store before the vptr store, 0xb4ac18), the
     * vptr, the reference and the array cleared, the array's owner index
     * from the thread's heap and its state */
    Object016b64a0(const Name &name) : Base016b64a0(name) {}

    virtual ~Object016b64a0();

  private:
    /* +0x48: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held48;
    Array01343a80<Ref00503fb0<Object016b9108>> record50; /* +0x50: an array of counted references */
};

#endif
