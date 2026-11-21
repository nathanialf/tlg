/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16bd4a0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00dfd980
 * and its destructor FUN_00dfe420), derived from Object016b9108: its slots
 * 2 to 4 are the base's, slot 5 FUN_00c1b340 and slot 6 FUN_00c1b350. Its
 * fields are traced where the destructor tears them down: three references
 * another thread may replace, at +0x28, +0x30 and +0x38. */
class Object016bd4a0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016bd4a0();
    virtual void slot5(); /* derived name; FUN_00c1b340, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    u8 unknown24[0x4];
    AtomicRef0045c470<Object016b9108> shared28; /* +0x28 */
    AtomicRef0045c470<Object016b9108> shared30; /* +0x30 */
    AtomicRef0045c470<Object016b9108> shared38; /* +0x38 */
};

/* derived name: the complete destructor FUN_00dfe420: the three references
 * emptied by compare-and-swap, first to last, then the members and the
 * base torn down. FUN_00dfe7f0, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the
 * vtable. */
Object016bd4a0::~Object016bd4a0()
{
    shared28.clear();
    shared30.clear();
    shared38.clear();
}
