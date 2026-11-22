/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_buffer00d650e0.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d1e58
 * (config/vtables.derived.base.txt), derived from Object016b9108. Its own
 * fields from +0x24 are traced only where its destructor tears them down
 * (the buffer at +0x28, tlg_game_buffer00d650e0.h); the rest are not
 * traced. */
class Object016d1e58 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d1e58();

  private:
    u8 unknown24[0x4];
    Buffer00d650e0 buffer28; /* +0x28 */
};

/* derived names: the complete destructor: the buffer destroyed, then the
 * base's destructor inlined (its vptr store, then the two names).
 * FUN_013b2d70, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016d1e58::~Object016d1e58() {}
