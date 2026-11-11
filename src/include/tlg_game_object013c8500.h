/* src/include/tlg_game_object013c8500.h: the class whose vtable is at
 * 0x16bc170 (config/vtables.derived.base.txt), moved from leaf_013c84c0.cpp,
 * which defines its destructor; leaf_00dd2820.cpp derives from it. derived
 * names throughout. */
#ifndef TLG_GAME_OBJECT013C8500_H
#define TLG_GAME_OBJECT013C8500_H

#include "tlg_types.h"

void FUN_013bf660(void *a, void *b); /* derived name */

class Object013c8500 /* derived name */
{
  public:
    virtual void release() /* derived name */
    {
        if (unknown8) {
            FUN_013bf660(unknown8, unknown10);
            unknown8 = 0;
        }
    }

    virtual ~Object013c8500();

  private:
    void *unknown8;  /* +0x8 */
    void *unknown10; /* +0x10 */
};

#endif
