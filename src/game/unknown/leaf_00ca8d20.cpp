/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

class Object00ca8d20; /* derived name */

/* derived names: the object at +0x98 of each node of the list. Slot 13
 * takes a counted reference to the node by value (the temporary's address
 * in rsi, released after the call) and returns an int; slot 14 is called
 * when that is not zero. The class and the other slots are not traced. */
class Target00ca8d20 /* derived name */
{
  public:
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    virtual void unknown3();
    virtual void unknown4();
    virtual void unknown5();
    virtual void unknown6();
    virtual void unknown7();
    virtual void unknown8();
    virtual void unknown9();
    virtual void unknown10();
    virtual void unknown11();
    virtual void unknown12();
    virtual int slot13(Ref00503fb0<Object00ca8d20> object); /* derived name */
    virtual void slot14();                                  /* derived name */
};

class Object00ca8d20 : public Node00503fb0 /* derived name */
{
  public:
    u8 unknown68[0x30];
    Target00ca8d20 *unknown98; /* +0x98 */
};

/* derived names: for each node of the array (its count read once) whose
 * int at +0x30 is not zero, slot 13 of the object at +0x98 of the node is
 * called with a reference to the node, and slot 14 when it returns a value
 * that is not zero. The array's owner is not traced. */
// NONMATCHING: 86/92, 337 bytes against 337: the two spill slots exchanged (the base keeps the array at
// [rbp-0x40] and the count at [rbp-0x44], the build at [rbp-0x48] and [rbp-0x3c]) and the array's spill
// stored before the canary's load in the base: the frame objects' order (r260917, round 260A's candidate 3)
void FUN_00ca8d20(Array05943280<Object00ca8d20 *> *objects) /* derived name */
{
    unsigned count = objects->size();
    for (unsigned i = 0; i < count; ++i) {
        Object00ca8d20 *object = objects->at(i);
        if (object->readers != 0) {
            Target00ca8d20 *target = object->unknown98;
            if (target->slot13(Ref00503fb0<Object00ca8d20>(object)))
                target->slot14();
        }
    }
}
