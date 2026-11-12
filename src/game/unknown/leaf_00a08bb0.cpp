/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_sce_kernel.h"
#include "tlg_simd.h"
#include "tlg_types.h"

/* derived names: under the mutex at +0x10 of the list at +0x118 of the
 * global at 0x57c9390 (its int at +0x18 set while held), refreshes every
 * entry (+0x38, the count at +0x40): an entry whose object at +0x28 is set
 * calls the object's slot 7 and copies its vectors at +0x140 and +0x120 to
 * its own +0x60 and +0x70; its int at +0x80 says whether it had one.
 * Returns 0. */
class Source00a08bb0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */

    u8 unknown8[0x118];
    Vec4 unknown120; /* +0x120 */
    u8 unknown130[0x10];
    Vec4 unknown140; /* +0x140 */
};

struct Entry00a08bb0 { /* derived name */
    u8 unknown0[0x28];
    Source00a08bb0 *source; /* +0x28 */
    u8 unknown30[0x30];
    Vec4 unknown60; /* +0x60 */
    Vec4 unknown70; /* +0x70 */
    int valid;      /* +0x80 */
};

struct List00a08bb0 { /* derived name */
    u8 unknown0[0x10];
    pthread_mutex_t mutex; /* +0x10 */
    int busy;              /* +0x18 */
    u8 unknown1c[0x1c];
    Entry00a08bb0 **entries; /* +0x38 */
    u32 count;               /* +0x40 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x118];
    List00a08bb0 *unknown118; /* +0x118 */
};

extern Object057c9390 *D_57c9390;

// NONMATCHING: the base keeps the entry index int, sign-extended at each use (`movsxd rax, ebx`,
// the parked IndVarSimplify class), the build widens it
int FUN_00a08bb0() /* derived name */
{
    if (!D_57c9390)
        return 0;
    List00a08bb0 *list = D_57c9390->unknown118;
    if (!list)
        return 0;
    scePthreadMutexLock(&list->mutex);
    list->busy = 1;
    for (int i = 0; i < list->count; i++) {
        Entry00a08bb0 *entry = list->entries[i];
        int valid = 0;
        if (Source00a08bb0 *source = entry->source) {
            source->slot7();
            entry->unknown60 = source->unknown140;
            entry->unknown70 = source->unknown120;
            valid = 1;
        }
        entry->valid = valid;
    }
    list->busy = 0;
    scePthreadMutexUnlock(&list->mutex);
    return 0;
}
