/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_sce_kernel.h"

/* The render's condition variable header, as the report names it (0x15b8188). */
#define RENDER_CONDITION_VARIABLE_HEADER /* derived name */                                        \
    "D:\\trico\\engine\\anzu\\engine_src\\props\\..\\render/ps4/util/condition_variable.h"

/* derived names: the render library's condition variable
 * (render/ps4/util/condition_variable.h): the kernel condition variable at
 * +0x0 and, at +0x8, whether it was made. Its destructor is registered with
 * __cxa_atexit for two static instances (0xb98729: 0x58b6010 and 0x58b6030,
 * whose flags the initializer clears); it runs Destory, which destroys a made
 * condition variable, checks the result and clears the flag. */
class ConditionVariable0139ded0 /* derived name */
{
  public:
    ~ConditionVariable0139ded0();

    void Destory()
    {
        if (m_created) {
            int ret = scePthreadCondDestroy(&m_cond);
            ANZU_ASSERT(RENDER_CONDITION_VARIABLE_HEADER, 119, ret == SCE_OK);
            m_created = false;
        }
    }

  private:
    pthread_cond_t m_cond; /* derived name */
    bool m_created;        /* derived name; +0x8 */
};

ConditionVariable0139ded0::~ConditionVariable0139ded0()
{
    Destory();
}
