/* src/include/tlg_game_object016b1970.h: the class whose vtable is at
 * 0x16b1970 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B1970_H
#define TLG_GAME_OBJECT016B1970_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b1970
 * (config/vtables.derived.base.txt, stored by FUN_009f4890 FUN_009f52f0
 * FUN_009f5490), derived from Object01343880: slots 5 and 7 override
 * the base's (FUN_009f54b0, FUN_009f5520; declared, their bodies are not
 * members yet). 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009f4890 sets them and its destructor FUN_009f52f0
 * tears them down. The destructor is the class's key function
 * (leaf_009f52f0.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016b1970 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 20 bytes from +0x34 to
     * the object's end cleared (`vmovdqu [r15+0x34], xmm0; mov dword
     * [r15+0x44], 0`, the second the upper half of the last reference): an int
     * and the two references, a run of zero stores the compiler made one
     * 20-byte memset */
    Object016b1970(const Name &name) : Object01343880(name), unknown34(0) {}

    virtual ~Object016b1970();
    /* slot 5, FUN_009f54b0: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual int FUN_000058a0();
    /* slot 7, FUN_009f5520: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void FUN_001af750();

  private:
    int unknown34; /* +0x34: zero from the constructor; not traced */
    /* +0x38: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held38;
    /* +0x40: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held40;
};

#endif
