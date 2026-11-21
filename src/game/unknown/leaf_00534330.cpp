/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_game_hash00c6a3b0.h"
#include "tlg_game_object016b9108.h"

/* derived names: an object of the root class with a second name at +0x210
 * (FUN_004ab790 compares a name with it, `cmp r13d, [rbx+0x210]`) */
class Named00534330 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x1ec];
    Name unknown210; /* +0x210 */
};

/* derived names: the argument: the object at +0x28 whose name is hashed,
 * the hash kept at +0x15c */
struct Object00534330 { /* derived name */
    u8 unknown0[0x28];
    Named00534330 *unknown28; /* +0x28 */
    u8 unknown30[0x12c];
    u32 unknown15c; /* +0x15c */
};

struct Object016ab4e8; /* tlg_game_object016ab4e8.h */

/* derived names: slot 12 of the vtable at 0x16ab4e8 (its pointer at
 * 0x16ab558): when the argument holds an object at +0x28, the object's
 * second name (its own name where that one is empty) is cut to what follows
 * its last '/' and before "_#", and lookup3's hash of it (FUN_00c6a3b0 from
 * the state 0xdeadbeef three times, then the final mix) is kept at +0x15c.
 * self is not used. Class and method unknown. */
// NONMATCHING: the file-name search: the base tests the first strchr before the loop (`test rax,
// rax; je` to `mov rbx, r15`), then enters the loop at its own test with the name 0 (`xor ebx,
// ebx; jmp` to `mov r15, rax; test r15, r15; jne`), the first test kept; the build threads that
// test away and rotates the loop (rbx and r15 swapped from 0x534372 on). Five forms measured:
// the loop with the name from the path, the last slash then `last ? last + 1 : path`, the name
// from 0 then `if (name == 0)` (the base's loop entry, the final test a select), an inline
// helper with an early return, and this if/else
void FUN_00534330(Object016ab4e8 *, Object00534330 *target) /* derived name */
{
    Named00534330 *object = target->unknown28;
    if (object) {
        const char *string = D_17ac870[object->unknown210.index].string0;
        if (*string == 0)
            string = D_17ac870[object->name.index].string0;
        const char *name = 0;
        const char *slash = strchr(string, '/');
        if (slash == 0) {
            name = string;
        } else {
            while (slash) {
                name = slash + 1;
                slash = strchr(name, '/');
            }
        }
        char buffer[512];
        strcpy(buffer, name);
        char *mark = strstr(buffer, "_#");
        if (mark)
            *mark = 0;
        HashState00c6a3b0 state;
        state.a = state.b = state.c = 0xdeadbeef;
        FUN_00c6a3b0(&state, reinterpret_cast<const u32 *>(buffer), strlen(buffer));
        target->unknown15c = finalHash(state);
    }
}
