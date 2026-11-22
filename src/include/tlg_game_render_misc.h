/* src/include/tlg_game_render_misc.h: the render library's utilities
 * (render/ps4/util/misc.h, as its reports name the file): a pointer kept as
 * a 32-bit offset from its own address, SetPointer named by its reports and
 * m_offset by their condition (FUN_01306250, FUN_00b8a480). The class name is
 * derived. */
#ifndef TLG_GAME_RENDER_MISC_H
#define TLG_GAME_RENDER_MISC_H

#include "tlg_types.h"

#include "tlg_game_assert.h"

/* The header's path as JsDevice.cpp includes it (0x15cc614). */
#define RENDER_MISC_H /* derived name */                                                           \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4/util/misc.h"

template <typename T> class OffsetPointer /* derived name */
{
  public:
    /* a null pointer is offset 0; any other must lie at a nonzero offset
     * that fits the 32 bits */
    void SetPointer(T *ptr)
    {
        if (ptr == nullptr) {
            m_offset = 0;
        } else {
            long p = reinterpret_cast<char *>(ptr) - reinterpret_cast<char *>(this);
            ANZU_ASSERT(RENDER_MISC_H, 50, p != 0);
            m_offset = static_cast<s32>(p);
            ANZU_ASSERT(RENDER_MISC_H, 52, p == m_offset);
        }
    }

  private:
    s32 m_offset;
};

#endif
