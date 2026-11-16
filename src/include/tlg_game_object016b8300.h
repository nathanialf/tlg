/* src/include/tlg_game_object016b8300.h: the class whose vtable is at
 * 0x16b8300 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B8300_H
#define TLG_GAME_OBJECT016B8300_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: a part of 0x30 bytes holding an array of counted
 * references at +0x18 (its lock at +0x2c). FUN_013a2620 empties it: the 16
 * bytes and the int at +0x10 cleared, every reference released, the array's
 * count cleared and its block given back. The constructor leaves the first
 * 0x14 bytes alone. */
struct Part013a2620 /* derived name */
{
    void FUN_013a2620(); /* derived name: the emptying, not written */

    u8 unknown0[0x10];
    int unknown10;
    u8 unknown14[0x4];
    /* +0x18: torn down by the holder's destructor (`lea rdi, [rbx+0x40]; call 0x134f620`) */
    Array01343a80<Ref00503fb0<Node00503fb0>> records;
};

/* derived names: the class whose vtable is at 0x16b8300
 * (config/vtables.derived.base.txt, stored by FUN_00c20f80 FUN_00c236c0 FUN_00c23760), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced where its destructor FUN_00c236c0 tears them down
 * (the parts' arrays at +0x70, +0x40) and where the creator FUN_00c20f80
 * inlines its constructor; their meaning is not traced. 0xb0 bytes (the
 * creator's `mov edi, 0xb0`). */
class Object016b8300 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_00c20f80: the parts' arrays empty with
     * their locks made free (the members), then both parts emptied
     * (FUN_013a2620 on +0x28 and +0x58) and the five pointers from +0x88
     * cleared (the body: their stores after the calls) */
    Object016b8300(const Name &name) : Object016b9108(name)
    {
        part28.FUN_013a2620();
        part58.FUN_013a2620();
        unknown88 = 0;
        unknown90 = 0;
        unknown98 = 0;
        unknowna0 = 0;
        unknowna8 = 0;
    }

    virtual ~Object016b8300();

  private:
    u8 unknown24[0x4];
    Part013a2620 part28; /* +0x28 */
    Part013a2620 part58; /* +0x58 */
    void *unknown88;     /* +0x88: null from the constructor; not traced */
    void *unknown90;     /* +0x90: null from the constructor; not traced */
    void *unknown98;     /* +0x98: null from the constructor; not traced */
    void *unknowna0;     /* +0xa0: null from the constructor; not traced */
    void *unknowna8;     /* +0xa8: null from the constructor; not traced */
};

#endif
