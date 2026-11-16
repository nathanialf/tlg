/* src/include/tlg_game_object016c7cb8.h: the class whose vtable is at
 * 0x16c7cb8, a base of a game class (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_OBJECT016C7CB8_H
#define TLG_GAME_OBJECT016C7CB8_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16c7cb8
 * (config/vtables.derived.base.txt), derived from Object016b9108. Its fields
 * are traced where its destructor FUN_00ab92c0 (leaf_00ab92c0.cpp, the class's key
 * function: that unit emits the vtable) tears them down and where the
 * creator of the class derived from it, FUN_00296100, builds them: its
 * constructor, inlined there, clears the reference and the first array's
 * block, count and capacity (`vmovdqu [r15+0x28], xmm0; mov qword [r15+0x38],
 * 0`: a run of zero stores made one memset), each array's owner index from
 * the thread's heap and its lock, the second array at +0x48; its vptr store
 * stays, in a block before the derived class's (the owner index's test
 * divides them). */
class Object016c7cb8 : public Object016b9108 /* derived name */
{
  public:
    Object016c7cb8(const Name &name) : Object016b9108(name) {}

    virtual ~Object016c7cb8();

  private:
    AtomicRef0045c470<Object016b9108> held28; /* +0x28: a counted reference */
    Array01343a80<Name> names30;              /* +0x30 */
    Array01343a80<Name> names48;              /* +0x48 */
};

#endif
