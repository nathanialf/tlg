/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_007a4c40 with the pointer at +0x8, its own first
 * argument, the pointer and the int of the pair its second argument points to,
 * and its third and fourth arguments, as a tail call; slot 6 of the vtable at
 * 0x16d3798 (its pointer at 0x16d37d8); slot 6 of the vtable at 0x16d3c08 (its
 * pointer at 0x16d3c48); and 1 more pointers. The types are not traced. Class
 * and method unknown. */
struct Target013d02c0; /* derived name */

struct Pair013d02c0 { /* derived name */
    void *unknown0;
    int unknown8;
};

struct Object013d02c0 { /* derived name */
    u8 unknown0[8];
    Target013d02c0 *unknown8;
};

void FUN_007a4c40(Target013d02c0 *target, void *a, void *pointer, int value, void *b,
                  void *c); /* derived name */

void FUN_013d02c0(Object013d02c0 *self, void *a, const Pair013d02c0 *pair, void *b,
                  void *c) /* derived name */
{
    FUN_007a4c40(self->unknown8, a, pair->unknown0, pair->unknown8, b, c);
}
