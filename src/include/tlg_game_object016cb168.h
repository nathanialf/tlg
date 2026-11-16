/* src/include/tlg_game_object016cb168.h: the class whose vtable is at
 * 0x16cb168, a base of the classes at 0x16aba48 and 0x16aba80 (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CB168_H
#define TLG_GAME_OBJECT016CB168_H

#include "tlg_types.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16cb168
 * (config/vtables.derived.base.txt, stored by FUN_005aaa70 FUN_005ab240
 * FUN_005ab2e0 and 7 more), derived from Object016b9108: its slots 2 to 4
 * are the base's. Its own fields from +0x24 are traced only where its
 * destructor FUN_013ada50 tears them down (the record at +0x28); the rest are
 * not traced. The destructor is inline (the class has no key function): its
 * out-of-line copy and the deleting one (0x13adaf0) lie among the inline
 * definitions the link laid out together (from 0x1323040); every unit that
 * emits the vtable emits both, and their rows are claimed from
 * leaf_005ab240.cpp. The classes of leaf_005ab240.cpp and leaf_005ab510.cpp
 * derive from it: their destructors hold its destructor's
 * body inlined (they store this class's vptr, 0x16cb178, then the base's). */
class Object016cb168 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creators of the derived classes (FUN_005aaa70): the
     * base built from the name, this class's vptr, the array cleared
     * (`vmovdqu [r15+0x28], xmm0`), its owner index from the thread's heap
     * and its state; the derived class's vptr is stored after them */
    Object016cb168(const Name &name) : Object016b9108(name) {}

    virtual ~Object016cb168() {}

  private:
    u8 unknown24[0x4];
    /* +0x28: an array of counted references, torn down by the destructor
     * (`lea rdi, [rbx+0x28]; call 0x134f620`) */
    Array01343a80<Ref00503fb0<Node00503fb0>> record28;
};

#endif
