/* src/include/tlg_game_object00bc3b10.h: the class whose vtable is at
 * 0x16b76b0, derived from Object016b7670 (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT00BC3B10_H
#define TLG_GAME_OBJECT00BC3B10_H

#include "tlg_game_counted00bd7e30.h"
#include "tlg_game_object016b7670.h"
#include "tlg_game_shared.h"

/* derived names: the class whose vtable is at 0x16b76b0
 * (config/vtables.derived.base.txt; stored also by FUN_00df9930 and
 * FUN_00dfca70). Its complete destructor FUN_00bc3b10 (leaf_00bc3b10.cpp)
 * and its deleting one FUN_00bc3d70, slot 1, release what it holds
 * (FUN_00bc3b40, leaf_00bc3b40.cpp), as FUN_00bc3da0 does before it makes
 * the objects again: six references to counted objects at +0x20 to +0x48
 * and six to shared objects at +0x50 to +0x78, each pair dropped together,
 * then the pointer at +0x80 and the int at +0x88 cleared; the references are
 * plain pointers, which the destructor does not drop itself. The objects'
 * classes and the other fields are not traced. */
class Object00bc3b10 : public Object016b7670 /* derived name */
{
  public:
    virtual ~Object00bc3b10();

    void releaseResources(); /* derived name */

  private:
    u8 unknown8[0x18];
    Counted00bd7e30 *counted20; /* +0x20 */
    Counted00bd7e30 *counted28; /* +0x28 */
    Counted00bd7e30 *counted30; /* +0x30 */
    Counted00bd7e30 *counted38; /* +0x38 */
    Counted00bd7e30 *counted40; /* +0x40 */
    Counted00bd7e30 *counted48; /* +0x48 */
    Shared00901550 *shared50;   /* +0x50 */
    Shared00901550 *shared58;   /* +0x58 */
    Shared00901550 *shared60;   /* +0x60 */
    Shared00901550 *shared68;   /* +0x68 */
    Shared00901550 *shared70;   /* +0x70 */
    Shared00901550 *shared78;   /* +0x78 */
    void *unknown80;            /* +0x80 */
    int unknown88;              /* +0x88 */
};

#endif
