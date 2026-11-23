/* src/include/tlg_game_object013c96e0.h: the class whose vtable is at
 * 0x16d2d40, derived from Object016b7670 (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT013C96E0_H
#define TLG_GAME_OBJECT013C96E0_H

#include "tlg_game_counted00bd7e30.h"
#include "tlg_game_object016b7670.h"
#include "tlg_game_shared.h"

/* derived names: the class whose vtable is at 0x16d2d40
 * (config/vtables.derived.base.txt; stored also by FUN_00dfca70). Its
 * complete destructor FUN_013c96e0 (leaf_013c96e0.cpp) and its deleting one
 * FUN_013c9710, slot 1, release what it holds (FUN_00bc4600,
 * leaf_00bc4600.cpp): references to shared objects at +0x20, +0x28, +0x38
 * and +0x40 and to counted objects at +0x50 and +0x58, then the pointers at
 * +0x30, +0x48 and +0x60 cleared; the references are plain pointers, which
 * the destructor does not drop itself. The objects' classes and the other
 * fields are not traced. */
class Object013c96e0 : public Object016b7670 /* derived name */
{
  public:
    virtual ~Object013c96e0();

    void releaseResources(); /* derived name */

  private:
    u8 unknown8[0x18];
    Shared00901550 *shared20;   /* +0x20 */
    Shared00901550 *shared28;   /* +0x28 */
    void *unknown30;            /* +0x30 */
    Shared00901550 *shared38;   /* +0x38 */
    Shared00901550 *shared40;   /* +0x40 */
    void *unknown48;            /* +0x48 */
    Counted00bd7e30 *counted50; /* +0x50 */
    Counted00bd7e30 *counted58; /* +0x58 */
    void *unknown60;            /* +0x60 */
};

#endif
