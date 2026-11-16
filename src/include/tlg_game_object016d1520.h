/* src/include/tlg_game_object016d1520.h: the class whose vtable is at
 * 0x16d1520 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D1520_H
#define TLG_GAME_OBJECT016D1520_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"
#include "tlg_game_array01343a80.h"

class Object016d1520;

/* derived names: the link of an object in the list at 0x59396d0
 * (FUN_00c63060 puts the object first: the next object, and the address of
 * the pointer that points to this one); a base class of the objects, built
 * before their vptr is stored (0xc5fbbd: its 16 bytes cleared before
 * `mov [rbx], rax`, the members after it) */
struct Link00c63060 { /* derived name */

    Link00c63060() : next(0), from(0) {}

    Object016d1520 *next;  /* +0x0 */
    Object016d1520 **from; /* +0x8 */
};

/* derived names: the class whose vtable is at 0x16d1520
 * (config/vtables.derived.base.txt, stored by FUN_00c5fb80 FUN_013a9670 FUN_013a9790), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's)
 * and from Link00c63060 at +0x38 (the list at 0x59396d0 links the object
 * through it: FUN_00c63060 writes +0x38 and +0x40).
 * Its fields are traced where its constructor FUN_00c5fb80 sets them and its
 * destructor FUN_013a9670 tears them down (the counted reference at +0x48,
 * the array at +0x50). */
class Object016d1520 : public Object01343880, public Link00c63060 /* derived name */
{
  public:
    Object016d1520(const Name &name); /* FUN_00c5fb80 */
    virtual ~Object016d1520();

  private:
    /* +0x48: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held48;
    /* +0x50: an array of counted references with its lock at +0x64, torn
     * down by the destructor (`lea rdi, [rbx+0x50]; call 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> record50;
    int unknown68; /* +0x68: zero from the constructor */
    int unknown6c; /* +0x6c: 8 from the constructor */
    int unknown70; /* +0x70: 1 from the constructor */
};

#endif
