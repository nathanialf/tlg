/* src/include/tlg_game_object016a92c8.h: the class whose vtable is at
 * 0x16a92c8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A92C8_H
#define TLG_GAME_OBJECT016A92C8_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_task003ec770.h"

/* derived names: the class whose vtable is at 0x16a92c8
 * (config/vtables.derived.base.txt, stored by FUN_003ebdd0 FUN_003ec630
 * FUN_003ec6d0), derived from Task003ec770: slots 5 to 9 are its overrides
 * (FUN_003ec770, FUN_003ec7b0, FUN_003ec800, FUN_003ec850, FUN_003ec8a0), each calling the same slot of every child. 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its own fields are traced
 * where its creator FUN_003ebdd0 sets them and its destructor FUN_003ec630
 * tears them down. The destructor is the class's key function
 * (leaf_003ec630.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016a92c8 : public Task003ec770 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x28], xmm0`), its owner index from the thread's heap and
     * its state */
    Object016a92c8(const Name &name) : Task003ec770(name) {}

    virtual ~Object016a92c8();
    void slot5();               /* FUN_003ec770 */
    int slot6(void *argument);  /* FUN_003ec7b0 */
    int slot7(void *argument);  /* FUN_003ec800 */
    int slot8(void *argument);  /* FUN_003ec850 */
    void slot9(void *argument); /* FUN_003ec8a0 */

  private:
    Array01343a80<Ref00503fb0<Task003ec770>>
        children; /* +0x28: counted references to the children */
};

#endif
