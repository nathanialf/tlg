/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_sce_kernel.h"

/* The render's mutex header, as the report names it (0x15b8147). */
#define RENDER_MUTEX_HEADER /* derived name */                                                     \
    "D:\\trico\\engine\\anzu\\engine_src\\props\\..\\render/ps4/util/mutex.h"

/* derived names: the render library's mutex (render/ps4/util/mutex.h): the
 * kernel mutex at +0x0 and, at +0x8, whether it was made. Its destructor is
 * registered with __cxa_atexit for two static instances (0xb98702: 0x58b6000
 * and 0x58b6020); it runs Destory ("Destory", the report's name for the
 * function), which destroys a made mutex, checks the result and clears the
 * flag. */
class Mutex0139ddf0 /* derived name */
{
  public:
    ~Mutex0139ddf0();

    void Destory()
    {
        if (m_created) {
            int rc = scePthreadMutexDestroy(&m_mutex);
            ANZU_ASSERT(RENDER_MUTEX_HEADER, 126, rc == SCE_OK);
            m_created = false;
        }
    }

  private:
    pthread_mutex_t m_mutex; /* derived name */
    bool m_created;          /* derived name; +0x8 */
};

Mutex0139ddf0::~Mutex0139ddf0()
{
    Destory();
}
