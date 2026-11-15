/* src/include/tlg_game_object016a9290.h: the class whose vtable is at
 * 0x16a9290 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9290_H
#define TLG_GAME_OBJECT016A9290_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9290
 * (config/vtables.derived.base.txt, stored by FUN_003ea9b0 FUN_003eac20 FUN_003eacf0), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_003eac20 tears them down
 * (the block at +0x28, the record at +0x40); the others where its
 * constructor FUN_003ea9b0 sets them. 0x6070 bytes (`mov edi, 0x6070`
 * before operator new in its creator FUN_003e84f0). */
/* derived names: one of the 384 cells of Object016a9290 (0x40 bytes, the
 * array at +0x60 built by a loop that stores the first 32 bytes of each:
 * `vmovups [rbx+rax], ymm0` from the constant at 0x14e3860, rax from 0x60 to
 * 0x6060 by 0x40): an empty box, its minimum (1e9, 1e9, 1e9, 1) and its
 * maximum (-1e9, -1e9, -1e9, 1); the rest is not traced. */
struct Cell003ea9b0 { /* derived name */

    Cell003ea9b0()
        : minimum(1000000000.0f, 1000000000.0f, 1000000000.0f, 1.0f),
          maximum(-1000000000.0f, -1000000000.0f, -1000000000.0f, 1.0f)
    {
    }

    Float4A minimum;
    Float4A maximum;
    u8 unknown20[0x20];
};

class Object016a9290 : public Object016b9108 /* derived name */
{
  public:
    Object016a9290(const Name &name); /* FUN_003ea9b0 */
    virtual ~Object016a9290();

  private:
    u8 unknown24[0x4];
    /* +0x28: an array of pointers with its lock (+0x3c): three null
     * pointers appended by the constructor (8-byte elements: `shl eax, 3`;
     * the alignment 8 passed), its block released by the destructor (`mov
     * rax, [rbx+0x28]; ... cmp ecx, 0xa`) */
    Array01343a80<void *> array28;
    /* +0x40: an array of references with its lock (+0x54), torn down by the
     * destructor (`lea rdi, [rbx+0x40]; call 0x134f620`) */
    Array01343a80<Ref00503fb0<Node00503fb0>> array40;
    u8 unknown58[0x8];
    Cell003ea9b0 cells[0x180]; /* +0x60 */
    u8 unknown6060[0x10];
};

#endif
