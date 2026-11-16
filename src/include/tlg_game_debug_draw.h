/* src/include/tlg_game_debug_draw.h: the game's debug draws. derived names
 * throughout. A draw of a debug build takes the value it shows by const
 * reference; in the retail build its body is empty (src/game/debug_draw.cpp),
 * the link inlines it at every call and the executable keeps no copy of it.
 * Its trace is in the callers: a local whose address escaped at the unit's
 * own pipeline, so the calls after it were not marked as tail calls
 * (FUN_003447b0's four sines, each a call with one shared epilogue). */
#ifndef TLG_GAME_DEBUG_DRAW_H
#define TLG_GAME_DEBUG_DRAW_H

void debugDrawValue(const float &value); /* derived name */

#endif
