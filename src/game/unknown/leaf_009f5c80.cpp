/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01388080.h"
#include "tlg_game_object016b9108.h"

/* derived name: an object with a pointer at +0x28 (its first member) */
struct Object009f5c80 : Object016b9108 { /* derived name */
    void *unknown28;                     /* +0x28 */
};

/* derived name: when the object has its pointer, queues the command of kind
 * 9 with its name under the queue's lock, if the other object has its
 * pointer too; else marks the object with the flags 0x12. */
// NONMATCHING: instruction order (list-ilp), 76/78 in the module: the name's
// index (`mov esi, r15d`) is taken before the base's vptr store
// (`mov [rdx+rax], rdi`), after it in the base (leaf_007aa0a0.cpp's residual)
// Round 560C, link-stage IR: the vptr store is before the index's zext there; the DAG schedules the
// zext (a register value, no chain) above the store. Not an order of the source.
void FUN_009f5c80(Object009f5c80 *self, Object009f5c80 *other) /* derived name */
{
    if (!self->unknown28)
        return;
    if (!other || !other->unknown28) {
        self->flags |= 0x12;
        return;
    }
    Name name;
    name = self->name;
    CommandQueue05938c40 *queue = D_5938c40->queue;
    queue->lock.lock();
    queue->push<Object016cdfb0>(name);
    queue->lock.unlock();
}
