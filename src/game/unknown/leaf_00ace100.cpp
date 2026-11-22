/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b85e0.h"

/* derived names: a node of the class the pointer at 0x593a6c0 holds (its
 * type walked from +0x18, each type's parent at +0), with bit 0 of the word
 * at +0x240 cleared when asked to be on and set otherwise, stored only when
 * it changes (FUN_0048fd50 sets and clears the same bit) */
class Object00ace100 : public Object016b85e0 /* derived name */
{
  public:
    void setOn(bool on) /* derived name */
    {
        unsigned flags = on ? flags240 & ~1u : flags240 | 1u;
        if (flags240 != flags)
            flags240 = flags;
    }

  private:
    u8 unknown238[0x8];
    unsigned flags240; /* +0x240 */
};

extern const Type00503fb0 *D_593a6c0; /* derived name: the class of the nodes whose bit is set */

/* derived names: the node, when it is of that class, or else every node
 * under it in turn, switched on or off; the count of children read once */
void FUN_00ace100(Object016b85e0 *node, bool on) /* derived name */
{
    if (!node)
        return;
    if (node->isKindOf(D_593a6c0)) {
        static_cast<Object00ace100 *>(node)->setOn(on);
        return;
    }
    int count = node->childCount;
    for (int i = 0; i < count; ++i)
        FUN_00ace100(node->children[i].get(), on);
}
