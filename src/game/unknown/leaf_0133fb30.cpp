/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_creation.h"

/* derived names: the queue at 0x581bdd0: 128 requests of 16 bytes, the
 * read count at 0x581c5d0 and the write count at 0x581c5d4 after them (the
 * queue empty when they are equal, each read on its own), its spin lock at
 * 0x581c5d8. FUN_0133fb30 takes the oldest
 * request under the lock and, outside it, hands its object to FUN_0082b220
 * when its word is set, else to FUN_0082bb10. The requests' objects and
 * what the two callees do are not traced. */
struct Request0581bdd0 { /* derived name */
    void *object;        /* +0x0 */
    int kind;            /* +0x8 */
};

extern Request0581bdd0 D_581bdd0[128]; /* derived name */
extern unsigned D_581c5d0;             /* derived name: the read count */
extern unsigned D_581c5d4;             /* derived name: the write count */
extern Lock059458a4 D_581c5d8;         /* derived name */

void FUN_0082b220(void *object); /* derived name */
void FUN_0082bb10(void *object); /* derived name */

// NONMATCHING: jump threading: the build gives the empty queue's path its own
// copy of the release and returns, the base keeps one release with the flag in
// dl (`mov dl, 1; jmp`, `test dl, dl` after it); 78/95, the rest equal
void FUN_0133fb30() /* derived name */
{
    D_581c5d8.lock();
    bool empty = true;
    Request0581bdd0 request;
    if (D_581c5d0 != D_581c5d4) {
        request = D_581bdd0[D_581c5d0 & 127];
        ++D_581c5d0;
        empty = false;
    }
    D_581c5d8.unlock();
    if (!empty) {
        if (request.kind)
            FUN_0082b220(request.object);
        else
            FUN_0082bb10(request.object);
    }
}
