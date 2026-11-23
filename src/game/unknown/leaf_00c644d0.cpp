/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_dispatcher00c644d0.h"

/* derived names: a message handed to the receivers of its first name, of
 * its second (the key's bit 63 set), and of the two together (the second
 * in the high half), each where the names are not empty, the names read
 * again for each */
/* OPEN (FINISHING rule 6), checked in round 513D: its callers in the tree declare it under this
 * signature, and the link keeps every call (cost 440, over the link's threshold of 175) */
void FUN_00c644d0(Dispatcher00c644d0 *dispatcher, Object016a7620 *message) /* derived name */
{
    if (message->first().index)
        dispatcher->deliver(message->first().index, message);
    if (message->second().index)
        dispatcher->deliver(u64(message->second().index) | 0x8000000000000000ull, message);
    if (message->first().index && message->second().index)
        dispatcher->deliver(u64(message->second().index) << 32 | message->first().index, message);
}
