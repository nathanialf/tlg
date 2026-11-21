/* src/include/tlg_game_object016a8228.h: the class whose vtable is at 0x16a8228
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8228_H
#define TLG_GAME_OBJECT016A8228_H

#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived name: a member of 0xb0 bytes, five of them at +0xa0 (`lea rdi,
 * [rbx+0xa0]` to `[rbx+0x360]`, each a call of FUN_013455b0, which puts it
 * in its empty state: the pointer at +0x98 emptied, the float at +0x30 set
 * to -1); its fields are not traced */
struct Member013455b0;                     /* derived name */
void FUN_013455b0(Member013455b0 *member); /* derived name */

struct Member013455b0 { /* derived name */

    Member013455b0()
    {
        FUN_013455b0(this);
    }

    /* +0x98: a counted reference that FUN_013455b0 clears and the owner's
     * destructor releases (FUN_002e2aa0: `mov rbx, [rax-0x18]` in its loop
     * over the five) */
    u8 unknown0[0xb0];
};

/* derived name: an array with an int of its own in the array's tail padding
 * at +0x14 (`mov dword [rbx+0x7c], 0` after the allocator's index at +0x78,
 * the array at +0x68; the same at +0x9c and +0x434) */
template <class T> struct Array002e2940 : public Array05943280<T> { /* derived name */

    Array002e2940() : unknown14(0) {}

    int unknown14; /* +0x14 */
};

/* derived names: the class whose vtable is at 0x16a8228
 * (config/vtables.derived.base.txt, stored by FUN_002e2940 FUN_002e2aa0), 0x440 bytes
 * (`mov edi, 0x440` before operator new in its creator FUN_002e27e0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its fields are
 * those its constructor FUN_002e2940 sets: zero from +0x24 to +0x68, two
 * arrays of counted references each emptied to a capacity of 16 (FUN_002e6bd0,
 * the arrays' clear), the five members of 0xb0 bytes and a third array. */
class Object016a8228 : public Object016b9108 /* derived name */
{
  public:
    Object016a8228(const Name &name); /* FUN_002e2940 */
    virtual ~Object016a8228();

  private:
    int unknown24; /* +0x24 */
    /* +0x28: counted references, released last to first by the destructor
     * FUN_002e2aa0 */
    Ref00503fb0<Object016b9108> unknown28[8];
    /* +0x68: an array of counted references, destroyed by FUN_0134f620 */
    Array002e2940<Ref00503fb0<Object016b9108>> unknown68;
    void *unknown80; /* +0x80 */
    /* +0x88: an array of counted references, destroyed by FUN_0134f620 */
    Array002e2940<Ref00503fb0<Object016b9108>> unknown88;
    Member013455b0 unknowna0[5];            /* +0xa0 */
    Ref00503fb0<Object016b9108> unknown410; /* +0x410 */
    int unknown418;                         /* +0x418 */
    Array002e2940<void *> unknown420; /* +0x420: its block released, its elements not traced */
    int unknown438;                   /* +0x438 */
};

#endif
