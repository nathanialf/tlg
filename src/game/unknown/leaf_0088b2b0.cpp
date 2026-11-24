/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_dispatcher00c644d0.h"
#include "tlg_game_name.h"
#include "tlg_game_object01388080.h"
#include "tlg_libc.h"

extern const char D_159a2ea[27]; /* "Marker.SysSoundEvent.enter" */
extern const char D_159a2db[5];  /* "Menu" */

/* derived names: posts the message "Marker.SysSoundEvent.enter", "Menu" and
 * the name the string names (interned as a copy: the last argument of
 * FUN_013baad0 0; a null or empty string names nothing) through the links
 * at +0xd0 of the record the pointer at 0x5938c40 holds, which are read
 * before the names are made (`mov rax, [rax+0xd0]` at 0x88b2d5). FUN_00886dc0
 * calls it for each of its menu sounds. */
// NONMATCHING: instruction order and registers (module, 562 bytes against 558): the base makes the
// name table's address (`lea r14, [0x17ac870]`, 0x88b37a) after the three indexes are shifted and
// before the copies' first `lock inc`, the build at the first shift (`lea r15`), so r14 and r15
// are exchanged from there; the message's `mov rsi, rbx` after its vptr store where the base has it
// before the first copy's `lock inc` (0x88b3b0). The source list scheduler keeps the lea at its GEP
// (round 570C's notes, the D6 addendum's trigger)
void FUN_0088b2b0(const char *string) /* derived name */
{
    Dispatcher00c644d0 *links = D_5938c40->links;
    Name event(D_159a2ea);
    Name menu(D_159a2db);
    const unsigned interned = Name::intern(string);
    Name name(interned);
    links->post(event, menu, name);
}
