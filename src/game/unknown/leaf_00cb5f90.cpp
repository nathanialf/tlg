/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_dispatcher00c644d0.h"
#include "tlg_game_name.h"
#include "tlg_game_object01388080.h"
#include "tlg_libc.h"
#include "tlg_sce_kernel.h"

extern const char D_15b42f6[14]; /* "Trophy.Unlock" */
extern const char D_15b4304[13]; /* "TrophySystem" */

/* derived names: the lock of the trophies' list of ids waiting to be
 * unlocked: its mutex and a word set while it is held (as
 * leaf_00cf2ab0.cpp's snoopers) */
struct Lock00cb5f90 { /* derived name */

    void lock() /* derived name */
    {
        scePthreadMutexLock(&mutex);
        busy = 1;
    }

    void unlock() /* derived name */
    {
        busy = 0;
        scePthreadMutexUnlock(&mutex);
    }

    pthread_mutex_t mutex; /* +0x0 */
    int busy;              /* +0x8 */
};

/* derived names: a trophy of the table by name, 16 bytes (FUN_00cb5f80
 * compares the names): its name and its id */
struct Trophy00cb5f90 { /* derived name */
    const char *name;   /* +0x0 */
    int id;             /* +0x8 */
};

/* derived names: the trophies sorted by name, their count at +0x8 */
struct TrophyTable00cb5f90 { /* derived name */
    u8 unknown0[0x8];
    int count;                  /* +0x8 */
    Trophy00cb5f90 trophies[1]; /* +0x10 */
};

/* derived names: the trophies' state: whether ids are queued (+0x0), the
 * queue of 80 ids (-1 for a free slot), a bit for each id already unlocked
 * (+0x14c), the queue's lock (+0x170), the table by name (+0x180) and the
 * count of ids (+0x188) */
struct Trophies00cb5f90 { /* derived name */
    bool queueing0;
    u8 unknown1[0x3];
    int queue4[80]; /* +0x4 */
    u8 unknown144[0x8];
    u32 unlocked14c[9];    /* +0x14c */
    Lock00cb5f90 *lock170; /* +0x170 */
    u8 unknown178[0x8];
    const TrophyTable00cb5f90 *table180; /* +0x180 */
    int count188;                        /* +0x188 */
};

int FUN_00cb5f80(const void *a, const void *b); /* derived name */

/* derived names: the three names of a message, each a copy of its own: made
 * from the names first, then handed to the links (the base copies the event,
 * the sender and the name, `lock inc` at 0xcb6190, 0xcb61a6 and 0xcb61bc,
 * before it reads the links at 0xcb61e1); released in reverse after the
 * message is handed on */
struct Message00cb5f90 { /* derived name */

    Message00cb5f90(const Name &event, const Name &sender, const Name &argument)
        : event(event), sender(sender), argument(argument)
    {
    }

    Name event;
    Name sender;
    Name argument;
};

/* derived names: the trophy the name names unlocked: looked up by name
 * (bsearch over the table), and unless its id is out of range or already
 * unlocked, queued when the trophies are queueing (the first free slot of
 * 80 unless it is there) and "Trophy.Unlock" posted from "TrophySystem"
 * with the trophy's name (interned as a copy) through the links at +0xd0 of
 * the record the pointer at 0x5938c40 holds */
// NONMATCHING: 208/217 at the base's 882 bytes. The three names are copied into a value of their own
// before the links are read (the base's order: intern, three copies, the made name released, then
// the links). Two scheduling classes left: after the message's operator new the build forms the
// event's entry offset (`mov r15, r13; shl r15, 5`) before the message's count and vptr stores
// where the base copies rdx and rbx first and shifts after the stores (0xcb61fd to 0xcb6222); and
// the argument's release loads its slot (`mov rcx, [rbp-0x60]`) before `mov eax, -1` (0xcb6277)
void FUN_00cb5f90(Trophies00cb5f90 *self, const char *name) /* derived name */
{
    const TrophyTable00cb5f90 *table = self->table180;
    if (!table)
        return;
    Trophy00cb5f90 key;
    key.name = name;
    const Trophy00cb5f90 *trophy = static_cast<const Trophy00cb5f90 *>(
        bsearch(&key, table->trophies, table->count, sizeof(Trophy00cb5f90), FUN_00cb5f80));
    if (!trophy)
        return;
    const int id = trophy->id;
    if (id < 0 || self->count188 <= id)
        return;
    if (self->unlocked14c[id >> 5] & (1u << (id & 31)))
        return;
    if (self->queueing0) {
        self->lock170->lock();
        for (int i = 0; i < 80; ++i) {
            if (self->queue4[i] == id)
                break;
            if (self->queue4[i] == -1) {
                self->queue4[i] = id;
                break;
            }
        }
        self->lock170->unlock();
    }
    static Name D_5945890(D_15b42f6, false);
    static Name D_59458a0(D_15b4304, false);
    const Message00cb5f90 message(D_5945890, D_59458a0, Name(Name::intern(name)));
    D_5938c40->links->send(message.event, message.sender, message.argument);
}
