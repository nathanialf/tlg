/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b4ce0.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00b1acf0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt) and, in this order, two records of four
 * bytes and a float (0xb14040 copies each as one 8-byte word into the object
 * it builds, at +0x2f8 to +0x308), the empty counted reference that other
 * functions replace by compare-and-swap (0x1db8b0, 0xb12e50, 0xb14040,
 * 0xb15230, 0xb1a810), registered with its destructor (0x1346b00), and a
 * third record (0x13904c0 reads it). */
struct Record05832900 /* derived name */
{
    Record05832900(unsigned char b0, unsigned char b1, unsigned char b2, unsigned char b3)
    {
        bytes[0] = b0;
        bytes[1] = b1;
        bytes[2] = b2;
        bytes[3] = b3;
        scale = 1.0f;
    }

    unsigned char bytes[4]; /* +0x0 */
    float scale;            /* +0x4: 1.0 */
};

Record05832900 D_5832900(0, 210, 210, 255);
Record05832900 D_5832908(0, 255, 255, 255);
AtomicRef0045c470<Object016b9108> D_5832910;
Record05832900 D_5832918(255, 255, 255, 0);
