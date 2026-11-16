/* src/include/tlg_game_object013cd320_inline.h: the constructor of
 * Object013cd320 (tlg_game_object00c1b7f0.h), included by the units that
 * construct the classes holding it (game region; docs/TARGETS.md). Every
 * name here is derived. It reads VECTOR_W, so the unit that includes this
 * header holds its own copy of tlg_game_vector.h's constants and each
 * constructor reads that unit's copy (FUN_012a7b10: `vmovaps xmm0,
 * [0x5ad8dc0]`, func_012a9c00.cpp's). */
#ifndef TLG_GAME_OBJECT013CD320_INLINE_H
#define TLG_GAME_OBJECT013CD320_INLINE_H

#include "tlg_game_object00c1b7f0.h"
#include "tlg_game_vector.h"

/* derived name: the Name at +0x30 empty, the vector at +0x40 zero, the one
 * at +0x50 the w axis, the five arrays empty (each with the calling
 * thread's heap and its lock free), the pointers null */
inline Object013cd320::Object013cd320()
    : unknown40(_mm_setzero_ps()), unknown50(VECTOR_W.v), unknown120(0), array130(0), array138(0)
{
}

#endif
