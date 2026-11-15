/* src/include/tlg_game_object016b39e8.h: the class whose vtable is at
 * 0x16b39e8, a base of a game class (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_OBJECT016B39E8_H
#define TLG_GAME_OBJECT016B39E8_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b39e8
 * (config/vtables.derived.base.txt), derived from Object016b9108. Its fields
 * are traced where its destructor FUN_00ad5a00 (leaf_00ad5a00.cpp, the class's key
 * function: that unit emits the vtable) tears them down and where the
 * creator of the class derived from it, FUN_00ad5c50, builds them: its
 * constructor, inlined there, clears the reference and the first array's
 * block, count and capacity (`vmovdqu [r15+0x28], xmm0; mov qword [r15+0x38],
 * 0`: a run of zero stores made one memset), each array's owner index from
 * the thread's heap and its lock, the second array at +0x48; its vptr store
 * stays, in a block before the derived class's (the owner index's test
 * divides them). */
class Object016b39e8 : public Object016b9108 /* derived name */
{
  public:
    Object016b39e8(const Name &name) : Object016b9108(name) {}

    virtual ~Object016b39e8();

  private:
    AtomicRef0045c470<Node00503fb0> held28; /* +0x28: a counted reference */
    Array01343a80<Name> names30;            /* +0x30 */
    Array01343a80<Name> names48;            /* +0x48 */
};

#endif
