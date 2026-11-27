/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00a167f0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
/* NONMATCHING FUN_00a16960: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
/* NONMATCHING FUN_00a16ad0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_array.h"
#include "tlg_game_creation.h"
#include "tlg_game_name.h"
#include "tlg_hks.h"

/* derived names: an object with an array of 16-byte entries at +0x150 and a
 * spin lock at +0x1b8 taken around its use; an entry is found by its word
 * at +0xc from the last one down. FUN_00a16960 (called at 0xa15fd2) gives
 * the entry found a new word; FUN_00a167f0 (0x9f9cdb, 0x9fb14b) removes it,
 * the last entry moved into its place. FUN_00a16ad0 (0xa16d6d, 0xa16ef0)
 * hands its arguments to FUN_00a162b0 under the lock (a key, a Name whose
 * index picks one of 32 lists, a name whose record's count it raises, a
 * float added to the value it finds or makes) and answers its value (a
 * Name at both: FUN_00a16e20 passes two read by FUN_00c91140). The class
 * and the entries' first twelve bytes are not traced. */
struct Entry00a16960 { /* derived name */
    u32 unknown0[3];
    int id; /* +0xc */
};

struct Object00a16960 { /* derived name */
    u8 unknown0[0x150];
    Array05943280<Entry00a16960> entries; /* +0x150 */
    u8 unknown168[0x50];
    Lock059458a4 lock; /* +0x1b8 */
};

/* derived names: the value found or made for the key and the name, after
 * the float is added (0xa1666b: `vxorps xmm0`, then `vaddss xmm1, xmm0,
 * xmm2` stored; the callers push xmm0, 0xa16f05) */
float FUN_00a162b0(Object00a16960 *self, const Name *key, const Name *name,
                   float value); /* derived name */

void FUN_00a16960(Object00a16960 *self, int id, int newId) /* derived name */
{
    self->lock.lock();
    for (int i = self->entries.size() - 1; i >= 0; --i) {
        if (self->entries.at(i).id == id) {
            self->entries.at(i).id = newId;
            break;
        }
    }
    self->lock.unlock();
}

void FUN_00a167f0(Object00a16960 *self, int id) /* derived name */
{
    self->lock.lock();
    for (int i = self->entries.size() - 1; i >= 0; --i) {
        if (self->entries.at(i).id == id) {
            self->entries.removeSwap(i);
            break;
        }
    }
    self->lock.unlock();
}

float FUN_00a16ad0(Object00a16960 *self, const Name *key, const Name *name,
                   float value) /* derived name */
{
    self->lock.lock();
    float result = FUN_00a162b0(self, key, name, value);
    self->lock.unlock();
    return result;
}

/* derived names: a reader of an argument of the frame for FUN_00c91140 (as
 * leaf_003e7260.cpp's), here also of the second argument (the index from
 * the top one less: `mov ecx, 1; sub ecx, eax` at 0xa16ebb) */
struct ArgumentReader00c8c290 { /* derived name */

    ArgumentReader00c8c290(lua_State *state_, int argument)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index =
            argument - 1 -
            (int)((unsigned long)((char *)state_->top - (char *)state_->base) / sizeof(HksObject));
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

void FUN_00c91140(ArgumentReader00c8c290 *reader, Name *name); /* derived name */

/* derived names: the object FUN_00a16e20 adds to: at +0x68 of the record at
 * +0x38 of the one at +0x108 of the global the pointer at 0x57c9390 holds */
struct Record00a16e20 { /* derived name */
    u8 unknown0[0x68];
    Object00a16960 *unknown68; /* +0x68 */
};

struct Member00a16e20 { /* derived name */
    u8 unknown0[0x38];
    Record00a16e20 *unknown38; /* +0x38 */
};

struct Game00a16e20 { /* derived name */
    u8 unknown0[0x108];
    Member00a16e20 *unknown108; /* +0x108 */
};

extern Game00a16e20 *D_57c9390;

/* derived names: a script C function: reads its first two arguments as
 * Names (FUN_00c91140) and, both not empty, pushes the value FUN_00a16ad0
 * gives for them with nothing added; returns 1, else 0 */
// NONMATCHING: 14/93 (round 604D): the base keeps both Names' indexes (r14d, r15d) across
// FUN_00a16ad0, which needs FUN_00a162b0 (unwritten) defined in the module for its parameters to be
// nocapture; the build reloads them
int FUN_00a16e20(lua_State *state) /* derived name */
{
    Name key;
    ArgumentReader00c8c290 reader(state, 1);
    FUN_00c91140(&reader, &key);
    if (!key.index)
        return 0;
    Name name;
    ArgumentReader00c8c290 nameReader(state, 2);
    FUN_00c91140(&nameReader, &name);
    if (!name.index)
        return 0;
    pushNumber(state, FUN_00a16ad0(D_57c9390->unknown108->unknown38->unknown68, &key, &name, 0));
    return 1;
}
