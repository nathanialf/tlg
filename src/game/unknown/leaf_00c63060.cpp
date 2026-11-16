/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d1520.h"
#include "tlg_game_object05945a38.h"

/* derived names: the objects linked through their member at +0x38, the
 * first one at +0x0 and the spin lock at +0x34 taken around the links'
 * writes (the list's address formed before the lock is taken: `lea rax,
 * [r14+0x18]` at 0xc630b9); the rest is not traced */
struct Links00c63060 { /* derived name */

    /* the object is linked by its link, and made first from it again
     * (`lea rax, [rdi+0x38]` before the test, `add rax, -0x38` for the
     * store at 0xc631a6) */
    void pushFront(Link00c63060 &link) /* derived name */
    {
        lock.lock();
        if (first)
            first->from = &link.next;
        link.next = first;
        link.from = &first;
        first = &static_cast<Object016d1520 &>(link);
        lock.unlock();
    }

    Object016d1520 *first; /* +0x0 */
    u8 unknown8[0x2c];
    Lock059458a4 lock; /* +0x34 */
};

/* derived names: the list at 0x59396d0: a recursive lock (the mutex, the
 * owner thread at +0x8, the depth at +0x10) and the linked objects at
 * +0x18 */
struct List059396d0 {           /* derived name */
    RecursiveLock05945a38 lock; /* +0x0 */
    Links00c63060 objects;      /* +0x18 */
};

/* derived name: puts the object first in the list under its lock; the
 * list keeps a reference of its own (the count raised without a null test,
 * `mov rcx, [r15]; cmp dword [rcx+8], 0xdeadc0de` at 0xc630a6) */
// NONMATCHING: greedy's assignment: the spin lock's 1 in r13d and its address in r12 (0xc630c4,
// 0xc630db), the build the other way round; 116 of 123 instructions equal, the rest the same
// two registers
void FUN_00c63060(List059396d0 *list, Ref00503fb0<Object016d1520> object)
{
    list->lock.lock();
    Object016d1520 *added = object.get();
    addReference(added);
    list->objects.pushFront(*added);
    list->lock.unlock();
}
