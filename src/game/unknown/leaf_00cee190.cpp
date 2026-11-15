/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9720.h"

/* derived names: the object the holder's pointer at +0x38 names; its
 * pointer at +0x18 names the holder back. Only that field is traced
 * (the holder's destructor clears both ends). */
struct Peer016b9720 /* derived name */
{
    inline void detach(); /* derived name */

    u8 unknown0[0x18];
    Object016b9720 *holder18; /* +0x18 */
};

/* derived name: cuts the link from both ends where a holder is attached
 * (`mov rcx, [rax+0x18]; test rcx, rcx; je; mov qword [rcx+0x38], 0;
 * mov qword [rax+0x18], 0`). */
inline void Peer016b9720::detach()
{
    if (holder18 != 0) {
        holder18->peer38 = 0;
        holder18 = 0;
    }
}

/* derived name: the complete destructor: the body detaches the linked
 * object where there is one; no member has a destructor; then the base's
 * destructor is inlined (its vptr store, then the two names).
 * FUN_00cee240, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
Object016b9720::~Object016b9720()
{
    if (peer38 != 0)
        peer38->detach();
}
