/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_game_jsvolatilememory.h"
#include "tlg_libc.h"

/* The header's path as the device's units include it (0x15cc83a). */
#define JS_VOLATILE_MEMORY_H /* derived name */                                                    \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4/JsVolatileMemory.h"

// NONMATCHING: 108 of 110: after the check's trap the base reloads m_head before the stack guard's address (`mov eax, [r14+4]; mov rdi, [guard]`); here the guard's reload comes first (the block after the trap, the post-RA order; not traced)
/* AllocateInArc (the report's name for the function): the request grown by
 * 0x400 and rounded to 64 bytes; the ring wrapped when it does not fit; the
 * block aligned; reaching the next frame's bound prints the ring and fails
 * the check. */
u64 JsVolatileMemory::AllocateInArc(u32 size, u32 alignment)
{
    u32 need = (size + 0x400 + 0x3f) & ~0x3fu;
    u32 mask = alignment - 1;
    if (static_cast<u64>(m_head + need) + mask > m_size)
        m_head = 0;
    u64 address = m_base + m_head;
    u64 p = (address + mask - 1) & -static_cast<u64>(mask);
    u32 padding = static_cast<u32>(p - address);
    u32 bound = m_ringIndices[(m_index + 1) % 3];
    if (m_head <= bound && m_head + need > bound) {
        printf("Out of memory(VolatileGarlic), need=%u, boundIndex=%u, arcTail=%u\n", need, bound,
               m_index);
        for (u32 i = 0; i < 3; ++i)
            printf("ringIndices[%u]=%u\n", i, m_ringIndices[i]);
        ANZU_ASSERT(JS_VOLATILE_MEMORY_H, 55, false);
    }
    m_head += padding + need;
    return p;
}
