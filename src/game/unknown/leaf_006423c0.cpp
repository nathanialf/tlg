/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: whether the object the name at 0x15aba40 names (of the
 * type the pointer at 0x5814678 holds, usable by this thread) is there and
 * has its float at +0x1b4 below 0.9. It reads no argument. The
 * object's class is not traced. */
struct Named006423c0 : Object016b9108 /* derived name */
{
    u8 unknown24[0x190];
    float unknown1b4; /* +0x1b4 */
};

extern const char D_15aba40[18];
extern const Type00503fb0 *D_5814678;

// The floats are converted from memory over a zero of the block (`vxorps`, then `vcvtss2sd x, z, [mem]`)
// by the selection rule (tools/patches/llvm-3.7.1-cvtzero-01-extload-cvtss2sd-zero-passthrough.patch, D95).
bool FUN_006423c0() /* derived name */
{
    Named006423c0 *object = findNamed<Named006423c0>(Name(D_15aba40), D_5814678);
    return object && object->unknown1b4 < 0.9;
}
