/* src/include/tlg_game_cell.h: four pairs of floats its header gives the
 * files that include it, after the vector constants (game region;
 * docs/TARGETS.md). Every name here is derived. The static initializers
 * 0x2030d0, 0xa63b80 and 0xb654e0 build them into their own units' .bss
 * (config/header_statics.base.txt). */
#ifndef TLG_GAME_CELL_H
#define TLG_GAME_CELL_H

#include "tlg_game_float2.h"
#include "tlg_game_vector.h"

/* derived names: a 128 by 128 cell, its half and its extent in a 2048-wide
 * sheet, each built from the cell (the base reads the cell's x back and
 * multiplies; the y products are stored as 64 and 1/16); the sheet's texel,
 * 1/2048 */
static const float SHEET_TEXEL_VALUE = 1.0f / 2048.0f; /* derived name */

static const Float2 CELL_EXTENT(128.0f, 128.0f);                           /* derived name */
static const Float2 CELL_HALF(CELL_EXTENT.x * 0.5f, CELL_EXTENT.y * 0.5f); /* derived name */
static const Float2 CELL_IN_SHEET(CELL_EXTENT.x *SHEET_TEXEL_VALUE,        /* derived name */
                                  CELL_EXTENT.y *SHEET_TEXEL_VALUE);
static const Float2 SHEET_TEXEL(SHEET_TEXEL_VALUE, SHEET_TEXEL_VALUE); /* derived name */

#endif
