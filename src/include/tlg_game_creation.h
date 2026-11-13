/* src/include/tlg_game_creation.h: the lock the creators of the registry's
 * classes take before they construct an object (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_CREATION_H
#define TLG_GAME_CREATION_H

#include "tlg_game_node.h"
#include "tlg_sce_kernel.h"

/* derived name: the calling thread's event queue (tp -40, the thread-local the GOT
 * slot at 0x16d80f8 names): a creator that finds the lock taken arms a
 * 100000 ns timer on it and waits for the event (0x218929 to 0x21898a). */
extern __thread SceKernelEqueue D_16dc0a8;

/* derived names: the spin lock at 0x59458a4 (2,118 sites name it). A
 * creator takes it after allocating the object (`xor eax, eax; lock
 * cmpxchg [0x59458a4], r13d` with r13d 1, at 0x2188e9) and
 * Object016b9108's constructor releases it. */
class Lock059458a4 /* derived name */
{
  public:
    /* takes the lock: while another thread holds it, a 100000 ns timer on
     * the thread's queue and a wait for one event with a timeout of 1, or,
     * where the timer cannot be armed, a sleep of one microsecond */
    void lock()
    {
        while (compareAndSwap(&locked, 0, 1) != 0) {
            SceKernelTimespec time;
            time.tv_sec = 0;
            time.tv_nsec = 100000;
            SceKernelUseconds timeout = 1;
            SceKernelEqueue queue = D_16dc0a8;
            if (sceKernelAddHRTimerEvent(queue, 0, &time, 0) == 0) {
                SceKernelEvent event;
                int count = 0;
                sceKernelWaitEqueue(queue, &event, 1, &count, &timeout);
            } else {
                sceKernelUsleep(1);
            }
        }
    }

  private:
    int locked; /* +0x0: 1 while a creator holds it */
};

extern Lock059458a4 D_59458a4;

/* derived name: the type's record a creator leaves for Object016b9108's
 * constructor, which takes it and clears it and the lock (`mov rax,
 * [0x57ca3d0]; mov [0x59458a8], rax` at 0x2189a0) */
struct Type059458a8; /* derived name; not traced */
extern Type059458a8 *D_59458a8;

#endif
