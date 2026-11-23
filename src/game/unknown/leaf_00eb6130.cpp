/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a request of the four lists FUN_00eb52c0's object keeps,
 * linked through +0x18; nonzero at +0x8 while it is live; +0x24 and +0x84
 * read by the lists' owners */
class Request00eb6130 /* derived name */
{
  public:
    virtual void slot0();  /* derived name; not traced */
    virtual void cancel(); /* derived name: slot 1, called with the state 1 */

    int state; /* +0x8 */
    u8 unknownc[0xc];
    Request00eb6130 *next; /* +0x18 */
    u8 unknown20[0x64];
    int unknown84; /* +0x84: a request with it set is left in the list at +0x2a0 */
};

/* derived name: the object FUN_00eb52c0 and FUN_00ebbba0 run, its lists at
 * +0x298 to +0x2b0 */
struct Requests00eb6130 { /* derived name */
    u8 unknown0[0x298];
    Request00eb6130 *list298; /* +0x298 */
    Request00eb6130 *list2a0; /* +0x2a0 */
    Request00eb6130 *list2a8; /* +0x2a8 */
    Request00eb6130 *list2b0; /* +0x2b0 */
};

/* derived name: each live request of the four lists given the state 1 and
 * cancelled, but those at +0x2a0 with +0x84 set */
void FUN_00eb6130(Requests00eb6130 *requests) /* derived name */
{
    for (Request00eb6130 *request = requests->list2a8, *next; request; request = next) {
        next = request->next;
        if (request->state) {
            request->state = 1;
            request->cancel();
        }
    }
    for (Request00eb6130 *request = requests->list2b0, *next; request; request = next) {
        next = request->next;
        if (request->state) {
            request->state = 1;
            request->cancel();
        }
    }
    for (Request00eb6130 *request = requests->list2a0, *next; request; request = next) {
        next = request->next;
        if (request->state && !request->unknown84) {
            request->state = 1;
            request->cancel();
        }
    }
    for (Request00eb6130 *request = requests->list298, *next; request; request = next) {
        next = request->next;
        if (request->state) {
            request->state = 1;
            request->cancel();
        }
    }
}
