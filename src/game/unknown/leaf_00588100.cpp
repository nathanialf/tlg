/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: a 16-byte entry of an array: a pointer, then a counted
 * reference to an object (the count raised behind the null test and the
 * released mark, `cmp dword [rcx+8], 0xdeadc0de`). Neither is traced
 * further. */
struct Entry00588100 {                  /* derived name */
    void *key;                          /* +0x0 */
    Ref00503fb0<Object016b9108> object; /* +0x8 */
};

/* FUN_00588100: this unit's copy of the array's append over the entries (the
 * block grown by half the count plus one, at most 0x40000 elements a step) */
template void Array05943280<Entry00588100>::push(const Entry00588100 &value);

/* FUN_0135b4b0: the append of another array of the entries (room made for
 * both counts, then each entry appended through FUN_00588100), out of line
 * until its caller FUN_005897a0 is written */
// NONMATCHING: the callee. append() calling add() is the template's form: the append over counted
// references (0x13a6db0, a row) calls add 0x138e360 and the one over Names (0x134cea0) add 0x1344a20,
// both rows returning the index (`mov eax, r15d`). FUN_00588100 is then add() over the entries, its return
// read by neither caller (0x135b4b0, 0x586470) and dropped at the link, which leaves push()'s
// bytes. Here add() has this append as its only caller in the module: the unit's bitcode keeps the
// call, the link's inliner takes it (a local function's last call). Next: FUN_00586470 (3253 bytes,
// a slot), the second caller, keeps it out of line.
template void Array05943280<Entry00588100>::append(const Array05943280<Entry00588100> &);
