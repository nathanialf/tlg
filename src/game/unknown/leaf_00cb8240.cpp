/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_registry00cb8240.h"

/* derived names: FUN_00cb8240 lists a table's objects (120 call sites):
 * under the table's lock, room is made in the array for every object of the
 * table, then each object whose name still names a record this thread may
 * use (tlg_game_node.h's isUsable) is appended. Returns the array's count,
 * read before the lock is given back (0xcb8454). */
// NONMATCHING: an unrotated list loop, 585 bytes against 591: the base keeps the walk's test at
// its head (`test r12, r12; je` at 0xcb8327, which both exits of the first bucket scan and every
// path of the body reach), the build rotates it and threads the first scan past it; the array's
// address is kept in rdi and at [rbp-0x30] in the base, on the stack only in the build
int FUN_00cb8240(Registry00cb8240 *self, Array05943280<Object00cb8240 *> *objects)
{
    ScopedLock05945a38 lock(&self->lock);
    objects->reserve(objects->size() + self->count);
    Registry00cb8240::Iterator iterator(self);
    while (!iterator.done()) {
        Object00cb8240 *object = iterator.next();
        const Object00cb8240 *record =
            static_cast<const Object00cb8240 *>(D_17ac870[object->name.index].record18);
        if (record && ((record->flags16 & 4) || D_16dc098))
            objects->push(object);
    }
    return objects->size();
}
