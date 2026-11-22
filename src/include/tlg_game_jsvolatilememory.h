/* src/include/tlg_game_jsvolatilememory.h: the render's volatile memory
 * (render/ps4/JsVolatileMemory.h, as its report names the header): a ring
 * ("arc") of m_size bytes from m_base, allocated from m_head, which must not
 * pass the bound the ring's indices keep for the frame after m_index. The
 * class is named from the header; AllocateInArc by its report. The device
 * holds one at +0x10238 (FUN_01499360 passes it, declaring the callee as
 * FUN_01305ce0). derived names for the fields. */
#ifndef TLG_GAME_JSVOLATILEMEMORY_H
#define TLG_GAME_JSVOLATILEMEMORY_H

#include "tlg_types.h"

class JsVolatileMemory
{
  public:
    u64 AllocateInArc(u32 size, u32 alignment);

  private:
    u32 m_size;           /* +0x0 */
    u32 m_head;           /* +0x4 */
    u32 m_index;          /* +0x8 */
    u32 m_ringIndices[3]; /* +0xc, as the report prints them */
    u64 m_base;           /* +0x18 */
};

#endif
