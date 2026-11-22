/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_shared.h"

/* derived names: the object the class below owns at +0x360, deleted by its
 * destructor: a shared object held at +0x30; the other fields are not
 * traced */
struct Owned00c2cef0 {
    u8 unknown0[0x30];
    SharedRef00901550<Shared00901550> shared30; /* +0x30 */
};

/* derived names: the class whose vtable is at 0x16b84f0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00c2a730
 * and its destructor FUN_00c2cef0), derived from Object016b85e0 (its
 * destructor 0xc55550): the base's slots and fields are not traced, so the
 * bytes below the first member here are the base's or this class's. Its
 * own fields are traced where the destructor tears them down: counted
 * references at +0x248 to +0x268 and the owned object at +0x360. */
class Object016b84f0 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016b84f0();

  private:
    u8 unknown238[0x10];
    Ref00503fb0<Object016b9108> held248; /* +0x248 */
    Ref00503fb0<Object016b9108> held250; /* +0x250 */
    Ref00503fb0<Object016b9108> held258; /* +0x258 */
    Ref00503fb0<Object016b9108> held260; /* +0x260 */
    Ref00503fb0<Object016b9108> held268; /* +0x268 */
    u8 unknown270[0xf0];
    Owned00c2cef0 *owned360; /* +0x360 */
};

/* derived name: the complete destructor: the owned object is deleted (its
 * pointer is not cleared), then the members are released, last first, and
 * the base's destructor FUN_00c55550 runs as a tail call. FUN_00c2d1e0,
 * slot 1, is the deleting one. The destructor is the class's key function,
 * so this file emits the vtable. */
Object016b84f0::~Object016b84f0()
{
    delete owned360;
}
