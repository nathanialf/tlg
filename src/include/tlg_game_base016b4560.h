/* src/include/tlg_game_base016b4560.h: a class between Object016b9108 and
 * the game classes over it (game region; docs/TARGETS.md). Every name here
 * is derived. */
#ifndef TLG_GAME_BASE016B4560_H
#define TLG_GAME_BASE016B4560_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

class Object016b85e0;
struct Component00503fb0;

/* derived names: the context slot 5 of the classes over Base016b4560 is
 * given, its fields as the bodies read and write them: FUN_00f1ae60 and its
 * six twins (0x1068bc0, 0x11ee4d0, 0x129a9e0, 0x12aa6c0, 0x12b4950,
 * 0x12f61e0) read the mode at +0x4 and the node at +0x28, set the group at
 * +0x668, the node's component at +0x670 and the pass at +0x678, and hand
 * the context on to the objects of their arrays (`mov rsi, r13; call [rax +
 * 0x28]`); the bodies of slot 5 read the pair at +0x668 (0xf8b450, 0x11eaf90,
 * 0x12b3210, 0xfdf160: `test rsi, rsi; je; mov r15, [rsi + 0x670]; mov r14,
 * [rsi + 0x668]`). The rest is not traced. */
struct Context016b4560 { /* derived name */
    u8 unknown0[0x4];
    int mode4; /* +0x4: 2 runs the arrays at +0x48 and +0x60 of a group, else the one at +0x78 */
    u8 unknown8[0x20];
    Object016b85e0 *node28; /* +0x28 */
    u8 unknown30[0x638];
    void *group668; /* +0x668: the group's pointer at +0x28 while its objects run */
    Component00503fb0 *component670; /* +0x670 */
    int pass678;                     /* +0x678: the array that runs (0, 1, 2), -1 after */
};

/* derived name: the type of the component the groups give the context
 * (Object016cb108's: its creator FUN_005ab9e0 leaves it for the
 * constructor) */
extern Type00503fb0 *D_57fd340;

/* derived name: the class between Object016b9108 and the classes whose
 * vtables are 0x16b4488, 0x16b4560, 0x16b45a8, 0x16b45f0, 0x16b4638 and
 * 0x16b4680 (creators 0xaf8b40, 0xaf9310, 0xaf95f0, 0xaf98d0, 0xaf9bb0,
 * 0xaf9e90) and the others that derive from it: its constructor, inlined,
 * clears the int at +0x24 BEFORE the derived class's vptr store (`mov dword
 * [r15+0x24], 0` at 0xaf9428); its own vptr store is dead. The derived
 * constructors set the int again in their bodies (0x5d, 0x59, 0x5b: a
 * kind). Slot 5, the first of its own, is given the context (above); the
 * derived classes override it. Not traced further. */
class Base016b4560 : public Object016b9108 /* derived name */
{
  public:
    Base016b4560(const Name &name) : Object016b9108(name), kind(0) {}

    /* slot 5: every derived class declares its own (0x1af750, the empty
     * body, in the classes that do nothing with it) */
    virtual void slot5(Context016b4560 *context); /* derived name */

  protected:
    /* the objects of an array run with the context (slot 5 of each), the
     * pass set first when the array holds any: the count and the block read
     * once (0xf1aef0: `mov r12d, [r14+0x50]; test r12d, r12d; je`, the pass
     * stored, then `mov rbx, [r14+0x48]` and the loop's `add rbx, 8; dec
     * r12d; jne`) */
    static void runAll(Array05943280<Ref00503fb0<Object016b9108>> &objects,
                       Context016b4560 *context, int pass) /* derived name */
    {
        const unsigned count = objects.size();
        if (count == 0)
            return;
        context->pass678 = pass;
        Ref00503fb0<Object016b9108> *at = objects.begin();
        for (unsigned i = 0; i < count; ++i)
            static_cast<Base016b4560 *>(at[i].get())->slot5(context);
    }

    int kind; /* +0x24 */ /* derived name */
};

#endif
