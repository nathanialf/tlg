/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived name: the function pointer at 0x17ac730 through which this code
 * frees its blocks */
extern void (*D_17ac730)(void *block);

/* derived names: a record of three blocks, freed first, third, second */
struct Blocks009066d0 { /* derived name */
    void *unknown0;     /* +0x0 */
    void *unknown8;     /* +0x8 */
    void *unknown10;    /* +0x10 */
};

struct Block009066d0 { /* derived name */
    void *unknown0;    /* +0x0 */
};

struct Object009066d0 { /* derived name */
    u8 unknown0[0x48];
    Blocks009066d0 *unknown48; /* +0x48 */
    Blocks009066d0 *unknown50; /* +0x50 */
    Block009066d0 *unknown58;  /* +0x58 */
};

/* derived name: frees an object: the blocks of its two records at +0x48 and
 * +0x50 and of the one at +0x58, then the three records and the object
 * itself; a null object or pointer is left alone */
void FUN_009066d0(Object009066d0 *self) /* derived name */
{
    if (self) {
        Blocks009066d0 *blocks = self->unknown48;
        if (blocks) {
            if (blocks->unknown0)
                D_17ac730(blocks->unknown0);
            if (blocks->unknown10)
                D_17ac730(blocks->unknown10);
            if (blocks->unknown8)
                D_17ac730(blocks->unknown8);
        }
        blocks = self->unknown50;
        if (blocks) {
            if (blocks->unknown0)
                D_17ac730(blocks->unknown0);
            if (blocks->unknown10)
                D_17ac730(blocks->unknown10);
            if (blocks->unknown8)
                D_17ac730(blocks->unknown8);
        }
        if (self->unknown58 && self->unknown58->unknown0)
            D_17ac730(self->unknown58->unknown0);
        if (self->unknown48)
            D_17ac730(self->unknown48);
        if (self->unknown50)
            D_17ac730(self->unknown50);
        if (self->unknown58)
            D_17ac730(self->unknown58);
        D_17ac730(self);
    }
}
