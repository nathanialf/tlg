/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16bde38
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00e636b0
 * and its destructor 0xe63820), over Object016b9108: two names at +0x28
 * and +0x2c, a pointer at +0x30 and a counted reference another thread may
 * replace at +0x38. Their meaning is not traced. */
class Object016bde38 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016bde38();

  private:
    u8 unknown24[0x4];
    Name name28;                              /* +0x28 */
    Name name2c;                              /* +0x2c */
    void *unknown30;                          /* +0x30 */
    AtomicRef0045c470<Object016b9108> held38; /* +0x38 */
};

/* derived name: the complete destructor: the names emptied, the pointer
 * cleared and the reference emptied, then the members' destructors and the
 * base's, inlined. FUN_00e63ad0, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
Object016bde38::~Object016bde38()
{
    name28 = Name();
    name2c = Name();
    unknown30 = 0;
    held38.clear();
}
