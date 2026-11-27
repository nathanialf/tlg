/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_matrix01343890.h"
#include "tlg_game_string01331840.h"
#include "tlg_hks_string.h"

/* derived name: pushes a matrix as a string, its sixteen floats row by row
 * with four decimals (FUN_01331840 into a text of 4 KiB, then the string of
 * its length pushed by FUN_013aacc0); FUN_00477e40, FUN_00e72a30 and
 * FUN_013513b0 call it */
// NONMATCHING: the base converts each float from memory after one vxorps of the
// pass-through register (`vcvtss2sd xmm0, xmm8, [rsi]`); the build loads each with
// vmovss and converts the register (NOTES round 260A item 1, region-wide)
// Round 578E: equal under cvtzero-01 (not installed: tools/patches/proposed/
// llvm-3.7.1-cvtzero-01-extload-cvtss2sd-zero-passthrough.patch): the base's pass-through is
// a zero of the block made at selection.
void FUN_00c8ada0(lua_State *state, const Matrix01343890 *matrix) /* derived name */
{
    String01331840 text;
    FUN_01331840(
        &text,
        "%.4f %.4f %.4f %.4f   %.4f %.4f %.4f %.4f   %.4f %.4f %.4f %.4f   %.4f %.4f %.4f %.4f",
        matrix->rows[0].x, matrix->rows[0].y, matrix->rows[0].z, matrix->rows[0].w,
        matrix->rows[1].x, matrix->rows[1].y, matrix->rows[1].z, matrix->rows[1].w,
        matrix->rows[2].x, matrix->rows[2].y, matrix->rows[2].z, matrix->rows[2].w,
        matrix->rows[3].x, matrix->rows[3].y, matrix->rows[3].z, matrix->rows[3].w);
    FUN_013aacc0(state, text.text, strlen(text.text));
}
