/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c8500.h"
#include "tlg_libc.h"

void *FUN_013bd790(void *heap, size_t size, int tag); /* derived name */

/* derived names: a 24-byte element (`imul` by the inverse of 3 over the
 * difference shifted by 3) of the array below; not traced */
struct Element00dbb560 { /* derived name */
    u8 unknown0[0x18];
};

/* derived names: a growable array of the script VM: its block at +0x0,
 * the end of its capacity at +0x8 and the end of its elements at +0x10 */
struct Array00dbb560 {      /* derived name */
    Element00dbb560 *data;  /* +0x0 */
    Element00dbb560 *limit; /* +0x8 */
    Element00dbb560 *end;   /* +0x10 */
};

/* derived names: grows the array to twice its count plus one: a new block
 * from FUN_013bd790 with the tag 16, the elements and one more copied, the
 * old block freed through the state's allocator (its size the old
 * capacity's bytes, none for a null block; the limit set to the old block
 * first) */
// NONMATCHING: instruction order only: the old size's spill (`mov [rbp-0x30], rcx`) is placed before the doubled
// count (`lea ecx, [r12+r12]`) and the limit's store, where the base forms the count first (scheduling)
void FUN_00dbb560(Array00dbb560 *array, HksState00dd1740 *state) /* derived name */
{
    const int count = array->end - array->data;
    const int size = count + 1;
    const size_t oldBytes =
        array->data ? reinterpret_cast<char *>(array->limit) - reinterpret_cast<char *>(array->data)
                    : 0;
    array->limit = array->data;
    const int capacity = size * 2;
    Element00dbb560 *data =
        static_cast<Element00dbb560 *>(FUN_013bd790(state, capacity * sizeof(Element00dbb560), 16));
    Element00dbb560 *old = array->data;
    memcpy(data, old, size * sizeof(Element00dbb560));
    array->data = data;
    array->limit = data + capacity;
    array->end = data + count;
    externalFree(state, old, oldBytes, 16);
}
