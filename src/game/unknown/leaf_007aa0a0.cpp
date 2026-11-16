/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01388080.h"
#include "tlg_game_object016b9108.h"

/* derived names: the classes whose vtables are at 0x16add68, 0x16addb8 and
 * 0x16ade08 (config/vtables.derived.base.txt), as far as their slot 7 reads
 * them: the object at +0xb0. Not traced further. */
struct Object007aa0a0 { /* derived name */
    u8 unknown0[0xb0];
    Object016b9108 *unknownb0; /* +0xb0 */
};

/* derived names: slot 7 of the vtable at 0x16add68: queues the command of kind
 * 6 with the name of the object at +0xb0, under the queue's lock (the queue
 * read first, then the name taken: `mov rax, [0x5938c40]; mov rbx,
 * [rax+0xb0]` before `mov rax, [rdi+0xb0]`) */
// NONMATCHING: instruction order (list-ilp), 71/73 in the module: the name's
// index (`mov esi, r15d`) is taken before the base's vptr store
// (`mov [rdx+rax], rdi`), after it in the base; 0x7abb80 and 0x7ac330 the same
void FUN_007aa0a0(Object007aa0a0 *self) /* derived name */
{
    CommandQueue05938c40 *queue = D_5938c40->queue;
    Name name;
    name = self->unknownb0->name;
    queue->lock.lock();
    queue->push<Object016cb830>(name);
    queue->lock.unlock();
}

/* derived names: slot 7 of the vtable at 0x16addb8: queues the command of kind
 * 6 with the name of the object at +0xb0, under the queue's lock (the queue
 * read first, then the name taken: `mov rax, [0x5938c40]; mov rbx,
 * [rax+0xb0]` before `mov rax, [rdi+0xb0]`), the
 * same body */
void FUN_007abb80(Object007aa0a0 *self) /* derived name */
{
    CommandQueue05938c40 *queue = D_5938c40->queue;
    Name name;
    name = self->unknownb0->name;
    queue->lock.lock();
    queue->push<Object016cb830>(name);
    queue->lock.unlock();
}

/* derived names: slot 7 of the vtable at 0x16ade08: queues the command of kind
 * 6 with the name of the object at +0xb0, under the queue's lock (the queue
 * read first, then the name taken: `mov rax, [0x5938c40]; mov rbx,
 * [rax+0xb0]` before `mov rax, [rdi+0xb0]`), the
 * same body */
void FUN_007ac330(Object007aa0a0 *self) /* derived name */
{
    CommandQueue05938c40 *queue = D_5938c40->queue;
    Name name;
    name = self->unknownb0->name;
    queue->lock.lock();
    queue->push<Object016cb830>(name);
    queue->lock.unlock();
}
