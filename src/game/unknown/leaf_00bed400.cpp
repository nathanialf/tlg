/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_mutex.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_sce_kernel.h"

/* derived names: a mutex with a depth at +0x8 and its made flag at +0xc,
 * 16 bytes: destroyed as Mutex013847e0 is (tlg_game_mutex.h), the depth
 * cleared after the flag; how it is made and locked is not traced */
class Mutex00bed400 /* derived name */
{
  public:
    ~Mutex00bed400()
    {
        destroy();
    }

    void destroy() /* derived name */
    {
        if (created) {
            scePthreadMutexDestroy(&mutex);
            mutex = 0;
            created = 0;
            depth = 0;
        }
    }

  private:
    pthread_mutex_t mutex; /* +0x0 */
    /* volatile: the lock's depth, shared between threads as
     * Mutex013847e0's is (tlg_game_mutex.h); its clear here is a store of
     * its own, after the flag's (0xbed442) */
    volatile int depth; /* +0x8 */
    int created;        /* +0xc */
};

/* derived names: the class whose vtable is at 0x16b7c28
 * (config/vtables.derived.base.txt, stored by its creator FUN_00c32940 and
 * its destructor FUN_00bed400), with no base whose destructor does
 * anything. Its fields are traced where the destructor tears them down:
 * three mutexes at +0x8, +0x18 and +0x30, heap blocks at +0x60, +0x98 and
 * +0xb8 and a reference another thread may replace at +0xd0. */
class Object016b7c28 /* derived name */
{
  public:
    virtual ~Object016b7c28();

  private:
    Mutex00bed400 mutex8;  /* +0x8 */
    Mutex013847e0 mutex18; /* +0x18 */
    Mutex013847e0 mutex30; /* +0x30 */
    u8 unknown48[0x18];
    OwnedBlock05943280 block60; /* +0x60 */
    u8 unknown68[0x30];
    OwnedBlock05943280 block98; /* +0x98 */
    u8 unknownA0[0x18];
    OwnedBlock05943280 blockB8; /* +0xb8 */
    u8 unknownC0[0x10];
    AtomicRef0045c470<Object016b9108> heldD0; /* +0xd0 */
};

/* derived name: the complete destructor: the three mutexes destroyed and
 * the reference at +0xd0 emptied by compare-and-swap, then the members
 * torn down, last first. FUN_00bed6f0, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
Object016b7c28::~Object016b7c28()
{
    mutex8.destroy();
    mutex18.destroy();
    mutex30.destroy();
    heldD0.clear();
}
