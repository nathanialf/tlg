/* src/include/tlg_game_object0140ccc0.h: the two members whose destructors
 * are 0x140ccc0 and 0x13e8670: a counted reference at +0x18 and, from
 * +0x30, 0xb0-byte elements that each hold one at +0x98 (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT0140CCC0_H
#define TLG_GAME_OBJECT0140CCC0_H

#include "tlg_types.h"
#include "tlg_game_node.h"

/* derived names: the 0xb0-byte element: the reference at +0x98 is released
 * when the element is destroyed (0x140ccf3: `mov rbx, [rax-0x18]` with rax
 * the element's end, `lea r12, [rax-0xb0]` the step). The rest is not
 * traced. */
struct Element0140ccc0 { /* derived name */
    u8 unknown0[0x98];
    Ref00503fb0<Node00503fb0> ref98; /* +0x98 */
    u8 unknowna0[0x10];
};

/* derived names: the member with 24 of those elements (the destructor
 * FUN_0140ccc0 walks them last first from +0x10b0 down to +0x30, then
 * releases the reference at +0x18). Not polymorphic; the rest is not
 * traced. */
class Object0140ccc0 /* derived name */
{
  public:
    ~Object0140ccc0();

  private:
    u8 unknown0[0x18];
    Ref00503fb0<Node00503fb0> ref18; /* +0x18 */
    u8 unknown20[0x10];
    Element0140ccc0 elements[24]; /* +0x30 */
};

/* derived names: the member with four of them (the destructor FUN_013e8670
 * releases the references at +0x2d8, +0x228, +0x178 and +0xc8, then the one
 * at +0x18). */
class Object013e8670 /* derived name */
{
  public:
    ~Object013e8670();

  private:
    u8 unknown0[0x18];
    Ref00503fb0<Node00503fb0> ref18; /* +0x18 */
    u8 unknown20[0x10];
    Element0140ccc0 elements[4]; /* +0x30 */
};

#endif
