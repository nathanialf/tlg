/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b8b70.h"

/* derived names: the class whose vtable is at 0x16b91f0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00cc9fa0
 * and its complete destructor FUN_00cca6c0), derived from Object016b8b70:
 * five arrays of counted references from +0x1e8 and a polymorphic object
 * it owns at +0x5b0. The destructor empties the arrays to no capacity
 * (FUN_0138c8d0, first to last) and deletes the object (slot 1 behind a
 * null test); then the arrays are torn down, last first, and the base's
 * destructor 0xc9b6e0 runs as a tail call. FUN_00cca790, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. The other members are not traced. */
class Object016b91f0 : public Object016b8b70 /* derived name */
{
  public:
    virtual ~Object016b91f0();

  private:
    u8 unknown8[0x1e0];
    Object0134f620 array1e8; /* +0x1e8 */
    Object0134f620 array200; /* +0x200 */
    Object0134f620 array218; /* +0x218 */
    Object0134f620 array230; /* +0x230 */
    Object0134f620 array248; /* +0x248 */
    u8 unknown260[0x350];
    Object016b9108 *owned5b0; /* +0x5b0: deleted by the destructor */
};

Object016b91f0::~Object016b91f0()
{
    array1e8.clear(0);
    array200.clear(0);
    array218.clear(0);
    array230.clear(0);
    array248.clear(0);
    delete owned5b0;
}
