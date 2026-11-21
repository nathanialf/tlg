/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_buffer00d650e0.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d23a8
 * (config/vtables.derived.base.txt), derived from Object016b9108. Its own
 * fields from +0x24 are traced only where its destructor tears them down
 * (the buffer at +0x28, tlg_game_buffer00d650e0.h); the rest are not
 * traced. */
class Object016d23a8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d23a8();

  private:
    u8 unknown24[0x4];
    Buffer00d650e0 buffer28; /* +0x28 */
};

/* derived names: the complete destructor: the buffer reset, then destroyed (its
 * second reset), then the
 * base's destructor inlined (its vptr store, then the two names).
 * FUN_013b9a60, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
// NONMATCHING: the buffer's flags tested in memory (`test byte [rbx+0x34], 1`) where the base loads them
// once (`mov eax, [rbx+0x34]; test al, 1`) and reloads after the release: leaf_00d650e0.cpp's buffer class
Object016d23a8::~Object016d23a8()
{
    buffer28.reset();
}
