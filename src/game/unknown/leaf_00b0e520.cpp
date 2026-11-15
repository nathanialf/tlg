/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b4c08.h"
#include "tlg_game_object05945a38.h"

/* derived name: the type of the object the constructor makes (`mov rsi,
 * [0x5831930]` at 0xb0e57f) */
extern Type00503fb0 *D_5831930;

/* derived name: the made object's class, one over the reference's (`cmp
 * rcx, rbx` at 0xb0e5a4, the new pointer first); not traced */
struct Value00b0e520 : Node00503fb0 {};

/* derived name: the constructor of Object016b4c08: the base built from the
 * name, the members cleared, then an object of the type at 0x5831930 is made
 * under the empty name (FUN_00cbc5a0, mode 0) and the reference at +0x38
 * set to it. The empty name is not released: the module knows the callee
 * only reads it, and the name's scope ends before the exchange (an atomic
 * operation between the two would keep the release). */
// NONMATCHING: 338 bytes for 302: the build ends in two tail calls (`jmp [rax+0x10]`, `jmp
// FUN_00c14bc0`) where the base calls and returns. The base's calls are not tail calls, as when
// the empty name's address had escaped into FUN_00cbc5a0 (the callee's body unknown where tail
// calls were marked), yet the name's release is gone (the body known where loads were forwarded)
Object016b4c08::Object016b4c08(const Name &name) : Object01343880(name), unknown40(0)
{
    Value00b0e520 *made =
        static_cast<Value00b0e520 *>(FUN_00cbc5a0(D_5945a38, D_5831930, Name(), 0));
    held38.set(made);
}
