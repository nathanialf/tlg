/* src/include/tlg_game_object01343880.h: the class between Object016b9108
 * and the classes whose slots 5 to 8 are 0x58a0, 0x1343880 and 0x1af750
 * twice (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT01343880_H
#define TLG_GAME_OBJECT01343880_H

#include "tlg_game_object016b9108.h"

/* derived names: a class over Object016b9108 with a pointer at +0x28, an
 * int at +0x30 and four slots of its own, named after the slot that stores
 * its pointer (FUN_01343880: `mov [rdi+0x28], rsi; ret`). No vtable of its
 * own is known: its constructor and destructor are inlined wherever a
 * derived class is built or destroyed and its vptr store is dead there. The
 * evidence that it is a class and that its two fields are not the derived
 * classes' own: the constructors of the derived classes clear +0x28 and
 * +0x30 BEFORE they store their vptr and their own members after it
 * (0x2189cb to 0x2189de: `mov qword [r15+0x28], 0; mov dword [r15+0x30], 0;
 * mov [r15], rax; mov qword [r15+0x38], 0`; the same at 0xb0e54e to
 * 0xb0e567), where a class's own members are all cleared after its vptr
 * store (0xceaea1, 0xc91f38). */
class Object01343880 : public Object016b9108 /* derived name */
{
  public:
    Object01343880(const Name &name) : Object016b9108(name), unknown28(0), unknown30(0) {}

    /* Slots 5 to 8, defined here: the vtables of the derived classes hold
     * bodies the linker folded with other classes' (0x58a0 `mov eax, 1;
     * ret`; 0x1343880; 0x1af750 `ret` twice). Each is named as its
     * address's row names it (D15); slot 8 is the same address as slot 7,
     * and a second member cannot carry the name. */
    /* slot 5 */
    virtual int FUN_000058a0()
    {
        return 1;
    }

    /* slot 6 */
    virtual void FUN_01343880(void *p)
    {
        unknown28 = p;
    }

    /* slot 7 */
    virtual void FUN_001af750() {}

    /* slot 8: FUN_001af750 again */
    virtual void slot8() {} /* derived name */

    /* +0x28: null from the constructor, set by slot 6; read by a derived
     * class's slot 7 (0xcabe49): the scene node (Object016b85e0) whose
     * components hold the object, as the node's slot 5 makes it (0xc573b0:
     * the object's slot 6 called with the node) and its slot 6 tests it
     * (0xc575d0) */
    void *unknown28;

  private:
    int unknown30; /* +0x30: zero from the constructor; not traced */
};

/* derived name: the object taken out of the node at its +0x28, when it
 * has one, under the world's write lock (leaf_00c5a160.cpp) */
void FUN_00c5a160(Object01343880 *object);

#endif
