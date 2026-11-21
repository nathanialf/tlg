/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c8500.h"
#include "tlg_libc.h"

void *FUN_013bd790(void *heap, size_t size, int tag); /* derived name */

/* derived names: a growable byte buffer of the script VM: its state at
 * +0x0, the bytes at +0x8, their capacity at +0x10 and the count at
 * +0x18 */
struct Buffer00d9e3b0 {      /* derived name */
    HksState00dd1740 *state; /* +0x0 */
    char *data;              /* +0x8 */
    size_t capacity;         /* +0x10 */
    size_t size;             /* +0x18 */
};

/* derived names: appends a byte; a full buffer first doubles its capacity
 * (a new block from FUN_013bd790 with the tag 13, the bytes copied, the
 * old block freed through the allocator); 1, or 0 when no block is given
 * (`mov eax, 1`: an int) */
int FUN_00d9e3b0(Buffer00d9e3b0 *buffer, char c) /* derived name */
{
    if (buffer->size >= buffer->capacity) {
        const size_t capacity = buffer->capacity * 2;
        char *data = static_cast<char *>(FUN_013bd790(buffer->state, capacity, 13));
        if (!data)
            return 0;
        memcpy(data, buffer->data, buffer->capacity);
        externalFree(buffer->state, buffer->data, buffer->capacity, 13);
        buffer->data = data;
        buffer->capacity = capacity;
    }
    buffer->data[buffer->size] = c;
    ++buffer->size;
    return 1;
}
