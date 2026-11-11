/* src/include/tlg_game_mutex.h: the game's mutex wrapper. derived names. The
 * mutex at +0x0 and, at +0x14, whether it was created; the destructor
 * (leaf_013847e0.cpp) destroys a created mutex and clears both. */
#ifndef TLG_GAME_MUTEX_H
#define TLG_GAME_MUTEX_H

#include "tlg_types.h"

#include "tlg_sce_kernel.h"

class Mutex013847e0 /* derived name */
{
  public:
    ~Mutex013847e0();

  private:
    pthread_mutex_t mutex;
    u8 unknown8[0xc];
    int created; /* +0x14 */
};

#endif
