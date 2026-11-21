/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object00f0e560.h"
#include "tlg_sce_kernel.h"

/* FUN_00f0e560 */
// NONMATCHING: the base's vtable stored last (`lea rcx, [0x16d3680]; mov [rdi], rcx` at 0xf0e591):
// Object013cd310's destructor has an empty body, which clang skips the store for
// (CanSkipVTablePointerInitialization), and its own out-of-line copy 0x13cd310 stores it too: what
// its body or fields hold is not known. FUN_00f0e5a0, the deleting destructor, drops the store and
// is equal.
Object00f0e560::~Object00f0e560()
{
    if (next18)
        next18->link10 = link10;
    if (link10)
        *link10 = next18;
    link10 = 0;
    next18 = 0;
}

/* derived names: the classes whose vtables are at 0x16beca8 and 0x16bed98
 * (config/vtables.derived.base.txt), entries of an intrusive list over
 * Object00f0e560: each destructor runs the class's own function first
 * (0xf0e0d0, 0xf0e430, below), then the base's, inlined (the entry
 * taken out of its list). */
class Object016beca8 : public Object00f0e560 /* derived name */
{
  public:
    virtual ~Object016beca8();

    void FUN_00f0e0d0();
};

/* the calling thread's event queue (tlg_game_creation.h) */
extern __thread SceKernelEqueue D_16dc0a8;

class Object016bed98 : public Object00f0e560 /* derived name */
{
  public:
    virtual ~Object016bed98();

    void FUN_00f0e430();

  private:
    int unknown20; /* +0x20: not zero while the sound below is held */
    int unknown24; /* +0x24: not zero while FUN_00ebff80 has been called for it */
};

/* FUN_00f0e070; its deleting destructor FUN_00f0e1c0 */
// NONMATCHING: the base's vtable stored last, as FUN_00f0e560 (0xf0e0b9)
Object016beca8::~Object016beca8()
{
    FUN_00f0e0d0();
}

/* FUN_00f0e3d0; its deleting destructor FUN_00f0e500 */
// NONMATCHING: the base's vtable stored last, as FUN_00f0e560 (0xf0e419)
Object016bed98::~Object016bed98()
{
    FUN_00f0e430();
}

/* derived names: the sound runtime's calls the teardowns make, not traced */
int FUN_00ebff80(int);          /* derived name */
int FUN_00ebf860(void **block); /* derived name */
int FUN_00efc330(int handle);   /* derived name */

/* derived names: the class's own teardown, called by its destructors and by
 * FUN_00f0e220: with a handle of the sound runtime at +0xc (not negative),
 * the handle goes to FUN_00efc330 until it takes it (a result that is not
 * negative), the thread waiting 100 microseconds after each try (a 100000 ns
 * timer on its queue and one event waited for with a timeout of 100, or
 * where the timer cannot be armed a sleep of 100), then it is set to -1 */
void Object016beca8::FUN_00f0e0d0()
{
    if (unknownc < 0)
        return;
    int result;
    do {
        result = FUN_00efc330(unknownc);
        SceKernelTimespec time;
        time.tv_sec = 0;
        time.tv_nsec = 100000;
        SceKernelUseconds timeout = 100;
        SceKernelEqueue queue = D_16dc0a8;
        if (sceKernelAddHRTimerEvent(queue, 0, &time, 0) == 0) {
            SceKernelEvent event;
            int count = 0;
            sceKernelWaitEqueue(queue, &event, 1, &count, &timeout);
        } else {
            sceKernelUsleep(100);
        }
    } while (result < 0);
    unknownc = -1;
}

/* derived names: the class's own teardown, called by its destructors and at
 * 0xebbcad: with a handle of the sound runtime at +0xc (not negative), what
 * it holds is given back (FUN_00ebff80 with 0 and 1 when +0x24 is set; the
 * block FUN_00ebf860 hands back released to its owner), then the handle
 * goes to FUN_00efc330 and is set to -1 */
void Object016bed98::FUN_00f0e430()
{
    if (unknownc < 0)
        return;
    if (unknown20) {
        if (unknown24) {
            FUN_00ebff80(0);
            FUN_00ebff80(1);
            unknown24 = 0;
        }
        void *block = 0;
        if (FUN_00ebf860(&block) >= 0)
            releaseBlock(block);
        unknown20 = 0;
    }
    FUN_00efc330(unknownc);
    unknownc = -1;
}
