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

class Object00ca8d20 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0xc];
    int unknown30; /* +0x30 */
    u8 unknown34[0x64];
    Target00ca8d20 *unknown98; /* +0x98 */
};

/* derived names: for each node of the array (its count read once) whose
 * int at +0x30 is not zero, slot 13 of the object at +0x98 of the node is
 * called with a reference to the node, and slot 14 when it returns a value
 * that is not zero. The array's owner is not traced. */
void FUN_00ca8d20(Array05943280<Object00ca8d20 *> *objects) /* derived name */
{
    unsigned count = objects->size();
    for (unsigned i = 0; i < count; ++i) {
        Object00ca8d20 *object = objects->at(i);
        if (object->unknown30 != 0) {
            Target00ca8d20 *target = object->unknown98;
            if (target->slot13(Ref00503fb0<Object00ca8d20>(object)))
                target->slot14();
        }
    }
}
