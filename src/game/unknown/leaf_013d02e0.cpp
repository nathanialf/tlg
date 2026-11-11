/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 7 of the vtables at 0x16d3798, 0x16d3c08 and 0x16d6960:
 * passes the object at +0x8, the three floats its first argument points to and
 * the pointer and the int its second points to to FUN_007a4fa0, as a tail
 * call. The types are not traced. Class and method unknown. */
struct Record013d02e0 { /* derived name */
    void *unknown0;
    int unknown8;
};

struct Object013d02e0 { /* derived name */
    u8 unknown0[0x8];
    void *unknown8;
};

void FUN_007a4fa0(void *object, float x, float y, float z, void *pointer,
                  int value); /* derived name */

// NONMATCHING: list-ilp order: the base loads the object and the three floats first, then the pointer and the int into rsi and edx; the compile loads the record's two fields first into rax and rcx and moves them after (the same with a 12-byte record passed by value)
void FUN_013d02e0(Object013d02e0 *self, const float *vector,
                  const Record013d02e0 *record) /* derived name */
{
    FUN_007a4fa0(self->unknown8, vector[0], vector[1], vector[2], record->unknown0,
                 record->unknown8);
}
