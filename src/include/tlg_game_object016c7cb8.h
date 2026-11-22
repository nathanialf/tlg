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
 * divides them). The object the reference holds is a queue of items too
 * (FUN_0134d990 gives one up under its lock at +0x24, its read and write
 * indices at +0x1c and +0x20): its class is not traced. */
/* derived name: the next item of the queue an object holds, put in the
 * reference; 0 when the queue is empty (635 bytes, not written) */
int FUN_0134d990(Object016b9108 *queue, Ref00503fb0<Object016b9108> *item);

class Object016c7cb8 : public Object016b9108 /* derived name */
{
  public:
    Object016c7cb8(const Name &name) : Object016b9108(name) {}

    virtual ~Object016c7cb8();
    /* slot 5, FUN_00ab9510: the links of the names at +0x30 made, the ones
     * of the names at +0x48 taken out, and the names at +0x30 copied to
     * +0x48 (543 bytes, not written) */
    virtual void slot5(); /* derived name */
    /* slot 6, FUN_00ab9730: each item the held object gives up handed to
     * slot 7 with the argument */
    virtual void slot6(void *argument); /* derived name */
    /* slots 7 to 9 are pure: the vtable's words are zero in the file (the
     * dynamic relocations fill them) */
    virtual void slot7(void *argument, Object016b9108 *item) = 0; /* derived name */
    virtual void slot8() = 0; /* derived name; parameters not traced */
    virtual void slot9() = 0; /* derived name; parameters not traced */

  protected:
    /* +0x28: a counted reference to an object that holds links
     * (tlg_game_links00c63970.h): the derived classes' destructors take
     * them out */
    AtomicRef0045c470<Object016b9108> held28;

  private:
    Array01343a80<Name> names30; /* +0x30 */
    Array01343a80<Name> names48; /* +0x48 */
};

#endif
