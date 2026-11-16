/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d24f8.h"
#include "tlg_game_object05945a38.h"

/* derived name: the type of the object the constructor makes (`mov rsi,
 * [0x59459e8]` at 0xd63f6e) */
extern Type00503fb0 *D_59459e8;

/* derived name: the made object's class, one over the reference's (`cmp
 * rcx, rbx` at 0xd63f94, the new pointer first); not traced */
struct Value00d63f10 : Object016b9108 {};

/* derived name: the constructor of Object016d24f8: the base built from the
 * name (FUN_00c55320), the members cleared, then an object of the type at
 * 0x59459e8 is made under the empty name (FUN_00cbc5a0, mode 0) and the
 * reference at +0x240 set to it. The empty name is not released: the module
 * knows the callee only reads it. */
Object016d24f8::Object016d24f8(const Name &name) : Object00c55550(name)
{
    Value00d63f10 *made =
        static_cast<Value00d63f10 *>(FUN_00cbc5a0(D_5945a38, D_59459e8, Name(), 0));
    held240.set(made);
}
