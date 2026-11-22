/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* The render library's utilities as this unit includes them (0x15cefab,
 * 0x15ce370). */
#define RENDER_UTIL_DIR /* derived name */ "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4/util/"

#include "tlg_game_render_mutex.h"

/* derived names: the static object at 0x5adac98 (registered with
 * __cxa_atexit at 0x13235fa, made by FUN_01323040): two mutexes and two
 * condition variables, destroyed in reverse order. What lies before
 * them is not traced. */
class Object0149aa20 /* derived name */
{
  public:
    ~Object0149aa20();

  private:
    u8 unknown0[0x10];
    Mutex m_mutex10;                         /* derived name; +0x10 */
    Mutex m_mutex20;                         /* derived name; +0x20 */
    ConditionVariable m_conditionVariable30; /* derived name; +0x30 */
    ConditionVariable m_conditionVariable40; /* derived name; +0x40 */
};

Object0149aa20::~Object0149aa20() {}
