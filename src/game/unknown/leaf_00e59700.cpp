/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: what the class below owns at +0x258 (deleted by its
 * destructor's body); not traced */
struct Data00e59700 /* derived name */
{
    u8 unknown0[0x8];
};

/* derived names: the class whose vtable is at 0x16bd9c8
 * (config/vtables.derived.base.txt), derived from Object016b85e0: three
 * counted references at +0x240, +0x248 and +0x250 and an owned object at
 * +0x258. Its destructor deletes the owned object, the references are
 * released last to first, then the base's destructor FUN_00c55550 runs as a
 * tail call. FUN_00e598c0, slot 1, is the deleting destructor. The other
 * fields are not traced. */
class Object016bd9c8 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016bd9c8();

  private:
    u8 unknown8[0x238];
    Ref00503fb0<Object016b9108> held240; /* +0x240 */
    Ref00503fb0<Object016b9108> held248; /* +0x248 */
    Ref00503fb0<Object016b9108> held250; /* +0x250 */
    Data00e59700 *data258;               /* +0x258 */
};

Object016bd9c8::~Object016bd9c8()
{
    delete data258;
}
