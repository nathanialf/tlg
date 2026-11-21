/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016a7620.h"

class Dispatcher00c644d0;                                                   /* derived name */
void FUN_00c644d0(Dispatcher00c644d0 *dispatcher, Object016a7620 *message); /* derived name */

/* derived names: the dispatcher at +0xd0 of the record the pointer at
 * 0x5938c40 holds: FUN_00c644d0 (not written) hands a message to the
 * receivers its first two names select. post() makes a message of three
 * names, hands it on, then destroys it when no receiver kept a reference to
 * it (its count still zero, or the released mark); the names are its
 * arguments, copied by the caller (the three `lock inc` before the message's
 * operator new at 0x9480a4) and released after the message is handed on. */
class Dispatcher00c644d0 /* derived name */
{
  public:
    void post(Name a, Name b, Name c) /* derived name */
    {
        Object016a7620 *message = new Object016a7620(a, b, c);
        FUN_00c644d0(this, message);
        if (message->references == 0 || message->references == RELEASED)
            delete message;
    }
};

/* derived names: the record the pointer at 0x5938c40 holds. */
struct Object05938c40 {
    u8 unknown0[0xd0];
    Dispatcher00c644d0 *unknownd0; /* +0xd0 */
};

extern Object05938c40 *D_5938c40;

/* derived names: three names posted to the dispatcher, which is read
 * before the names are copied (`mov rax, [rax+0xd0]` first) */
void FUN_00948040(const Name &a, const Name &b, const Name &c) /* derived name */
{
    D_5938c40->unknownd0->post(a, b, c);
}
