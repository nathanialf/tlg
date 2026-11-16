/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b3d68.h"
#include "tlg_game_object05945a38.h"

/* derived name: the type of the object the constructor makes (`mov rsi,
 * [0x58b6fc8]`) */
extern Type00503fb0 *D_58b6fc8;

/* derived name: the made object's class, one over the reference's (the new
 * pointer compared first after the exchange); not traced */
struct Value00ae7880 : Node00503fb0 {};

/* derived name: the constructor of Object016b3d68, of Object016cba00's
 * shape: the base built from the name, the members cleared, then an object
 * of the type at 0x58b6fc8 is made under the empty name (FUN_00cbc5a0,
 * mode 0) and the reference at +0x28 set to it. */
Object016b3d68::Object016b3d68(const Name &name) : Object016b9108(name)
{
    Value00ae7880 *made =
        static_cast<Value00ae7880 *>(FUN_00cbc5a0(D_5945a38, D_58b6fc8, Name(), 0));
    held28.set(made);
}
