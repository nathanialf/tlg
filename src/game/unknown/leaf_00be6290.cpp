/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_buffer00d650e0.h"
#include "tlg_game_name.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b7ad8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00be56b0
 * and its complete destructor FUN_00be6290), derived from Object016b9108: a
 * buffer at +0x28, an array of counted references at +0x58 and an array of
 * Names at +0x70. The destructor's body is empty; the members are torn
 * down, last first, then the base's destructor is inlined (its vptr store,
 * then the two names). FUN_00be6430, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable.
 * The other fields are not traced. */
class Object016b7ad8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b7ad8();

  private:
    u8 unknown24[0x4];
    Buffer00d650e0 buffer28; /* +0x28 */
    u8 unknown40[0x18];
    Object0134f620 array58;      /* +0x58 */
    Array05943280<Name> names70; /* +0x70 */
};

// NONMATCHING: the buffer's flags tested in memory (`test byte [r14+0x34], 1`) where the base loads them
// once (`mov eax, [r14+0x34]; test al, 1`) and reloads after the release: leaf_00d650e0.cpp's buffer class;
// the deleting destructor FUN_00be6430 is equal
Object016b7ad8::~Object016b7ad8() {}
