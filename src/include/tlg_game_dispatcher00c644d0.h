/* src/include/tlg_game_dispatcher00c644d0.h: the dispatcher of three-name
 * messages at +0xd0 of the record the pointer at 0x5938c40 holds (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_DISPATCHER00C644D0_H
#define TLG_GAME_DISPATCHER00C644D0_H

#include "tlg_game_mutex.h"
#include "tlg_game_object016a7620.h"

class Dispatcher00c644d0;                                                   /* derived name */
void FUN_00c644d0(Dispatcher00c644d0 *dispatcher, Object016a7620 *message); /* derived name */

/* derived names: the receivers of one key (+0x10 of its route, 24 bytes;
 * not traced), handed a message by FUN_00c63f30 */
struct Receivers00c63f30 { /* derived name */
    u8 unknown0[0x18];
};

void FUN_00c63f30(Receivers00c63f30 *receivers, Object016a7620 *message); /* derived name */

/* derived names: one key's entry in the dispatcher's table: the key (a
 * name's index, a name's index with bit 63 set, or two names' indexes),
 * its receivers and the next entry of the bucket */
struct Route00c644d0 { /* derived name */
    u64 key;           /* +0x0 */
    u8 unknown8[0x8];
    Receivers00c63f30 receivers; /* +0x10 */
    Route00c644d0 *next;         /* +0x28 */
};

/* derived names: FUN_00c644d0 hands a message to the receivers its first
 * two names select. post() makes a message of three names, hands it on,
 * then destroys it when no receiver kept a reference to it (its count still
 * zero, or the released mark); the names are its arguments, copied by the
 * caller (the three `lock inc` before the message's operator new at
 * 0x9480a4) and released after the message is handed on. */
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

    /* under the lock, the message handed to the receivers of the key's
     * route, the bucket the key's low byte */
    void deliver(u64 key, Object016a7620 *message) /* derived name */
    {
        mutex.lock();
        for (Route00c644d0 *route = routes[key & 0xff]; route; route = route->next) {
            if (route->key == key) {
                FUN_00c63f30(&route->receivers, message);
                break;
            }
        }
        mutex.unlock();
    }

    Mutex013847e0 mutex; /* +0x0 */
    u8 unknown18[0x38];
    Route00c644d0 *routes[256]; /* +0x50 */
};

#endif
