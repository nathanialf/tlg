/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_sce_kernel.h"

/* derived names: the destructor FUN_009f43e0 registers with __cxa_atexit for
 * its static object (lea at 0x9f4665): when the int at +0x14 is set, destroys
 * the mutex at +0x0 and clears both. Class unknown. */
class Mutex013847e0 /* derived name */
{
  public:
    ~Mutex013847e0();

  private:
    pthread_mutex_t mutex;
    u8 unknown8[0xc];
    int created; /* +0x14 */
};

Mutex013847e0::~Mutex013847e0()
{
    if (created) {
        scePthreadMutexDestroy(&mutex);
        mutex = 0;
        created = 0;
    }
}
