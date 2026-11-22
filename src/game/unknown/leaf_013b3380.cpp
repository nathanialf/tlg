/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013671a0.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16b9a30
 * (config/vtables.derived.base.txt, stored by FUN_00cf2bb0 FUN_013b3380 FUN_013b3430), derived from
 * Object013671a0 (the class whose destructor is 0x13671a0): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_013b3380 tears them
 * down (the counted reference at +0x100); the rest are not traced. */
/* derived names: the component of the type the pointer at 0x5948180 holds,
 * as slot 8 below reads it: the component's flag byte at +0x3a and its int
 * at +0x40 */
struct Component05948180 : Component00503fb0 /* derived name */
{};

extern Type00503fb0 *D_5948180;

class Object016b9a30 : public Object013671a0 /* derived name */
{
  public:
    virtual ~Object016b9a30();
    /* slot 5: 0xcf54b0; not traced */
    virtual int FUN_000058a0();
    /* slot 7: 0xcf5530 (it calls Object00ced570's slot 7 first); not traced */
    virtual void FUN_001af750();
    /* slot 8 */
    virtual void slot8();

  private:
    u8 unknown60[0xa0];
    /* +0x100: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held100;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_013671a0 runs as a tail call. FUN_013b3430, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b9a30::~Object016b9a30() {}

/* derived name: slot 8: the first component of the node at +0x28 (the
 * pointer slot 6 of Object01343880 sets) whose type
 * is the one the pointer at 0x5948180 holds or derives from it (the node's
 * reader count not taken): its flag 2 at +0x3a cleared and its int at +0x40
 * set to 1 where it is 0. */
void Object016b9a30::slot8()
{
    Object016b85e0 *node = static_cast<Object016b85e0 *>(unknown28);
    const Type00503fb0 *type = D_5948180;
    Component00503fb0 *found = 0;
    for (unsigned i = 0; i < node->componentCount; ++i) {
        if (::isKindOf(node->componentAt(i)->type, type)) {
            found = node->componentAt(i);
            break;
        }
    }
    if (found) {
        Component05948180 *component = static_cast<Component05948180 *>(found);
        component->flags3a &= ~2;
        if (component->unknown40 == 0)
            component->unknown40 = 1;
    }
}
