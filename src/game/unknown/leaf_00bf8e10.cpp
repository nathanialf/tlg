/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b7d50.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b7dd0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00bf7d70
 * and its destructor FUN_00bf8e10), derived from Object016b9108. Its
 * fields are traced where the destructor tears them down: an array of
 * counted references to Object016b7d50s at +0x30 and an array of other
 * references at +0x50. */
class Object016b7dd0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b7dd0();

  private:
    u8 unknown24[0xc];
    Array05943280<Ref00503fb0<Object016b9108>> objects30; /* +0x30: Object016b7d50s */
    u8 unknown48[0x8];
    Array05943280<Ref00503fb0<Object016b9108>> array50; /* +0x50 */
};

/* derived name: the complete destructor: the references at +0x50 are
 * released with the block kept, each object of the array at +0x30 is reset
 * (an unsigned counter given to at(int): `movsxd rax, edx`, the count read
 * again at each one)
 * and the array's references released, then the members are torn down,
 * last first, then the base. FUN_00bf9740, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
// NONMATCHING: register assignment: after the two arrays' destructors the base keeps the object
// in rbx for the root's names, the build copies it back to rcx (508 of 546 instructions equal)
Object016b7dd0::~Object016b7dd0()
{
    array50.removeAll();
    for (unsigned i = 0; i < objects30.size(); ++i)
        static_cast<Object016b7d50 *>(objects30.at(i).get())->reset();
    objects30.removeAll();
}
