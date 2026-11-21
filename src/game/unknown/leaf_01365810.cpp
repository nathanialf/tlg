/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: a record with no virtual function whose destructor is a
 * function of its own (0x1365810, called by FUN_00712f40 and FUN_01362e30): its
 * members released last first (the name at +0x18, the reference at +0x10, the reference at +0x8). The other fields are not traced. */
struct Record01365810 /* derived name */
{
    ~Record01365810();

    u8 unknown0[0x8];
    Ref00503fb0<Object016b9108> held8;  /* +0x8 */
    Ref00503fb0<Object016b9108> held10; /* +0x10 */
    Name name18;                        /* +0x18 */
};

Record01365810::~Record01365810() {}
