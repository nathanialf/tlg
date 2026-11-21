/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00be2bd0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_creation.h"

/* derived names: an object with a spin lock at +0x48, a record of its own
 * at +0x50 and a pointer at +0x98 that FUN_00be20b0 works from: given the
 * object, a record (its own spin lock at +0x1c) and an argument whose word
 * at +0x240 it reads, FUN_00be20b0 updates the record from the object.
 * FUN_00be2d30 does it for the caller's record (the caller at 0x5f1e4b
 * passes one on its stack) and returns whether it did; FUN_00be2bd0 does it
 * for the object's own record where slot 7 answers nonzero or the counter at
 * +0x8c was zero (counted up), and keeps the argument's word at +0x88. The
 * classes are not traced. */
struct Record00be20b0 { /* derived name */
    u8 unknown0[0x1c];
    Lock059458a4 lock; /* +0x1c */
};

struct Argument00be20b0 { /* derived name */
    u8 unknown0[0x240];
    int unknown240; /* +0x240 */
};

class Object00be20b0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual int slot7();  /* derived name; not traced */

    u8 unknown8[0x40];
    Lock059458a4 lock; /* +0x48 */
    u8 unknown4c[0x4];
    Record00be20b0 record50; /* +0x50 */
    u8 unknown70[0x18];
    int unknown88; /* +0x88 */
    int unknown8c; /* +0x8c: counted up atomically */
    u8 unknown90[0x8];
    void *unknown98; /* +0x98 */
};

void FUN_00be20b0(Object00be20b0 *self, Record00be20b0 *record,
                  Argument00be20b0 *argument); /* derived name */

// NONMATCHING: greedy's assignment only: the constant 1 in r13 and the lock's address in r15, the base the other way
int FUN_00be2d30(Object00be20b0 *self, Record00be20b0 *record,
                 Argument00be20b0 *argument) /* derived name */
{
    self->lock.lock();
    int done = 0;
    if (self->unknown98) {
        FUN_00be20b0(self, record, argument);
        done = 1;
    }
    self->lock.unlock();
    return done;
}

void FUN_00be2bd0(Object00be20b0 *self, Argument00be20b0 *argument) /* derived name */
{
    self->lock.lock();
    if (self->slot7() || __sync_fetch_and_add(&self->unknown8c, 1) == 0) {
        if (self->unknown98) {
            int value = argument->unknown240;
            FUN_00be20b0(self, &self->record50, argument);
            self->unknown88 = value;
        }
    }
    self->lock.unlock();
}
