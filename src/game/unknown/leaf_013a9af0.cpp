/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: a record with no virtual function whose destructor is a
 * function of its own (0x13a9af0, called by FUN_00c67250, FUN_00c68570 and FUN_00d392f0): its
 * members released last first (the name at +0x30, the reference at +0x8, the reference at +0x0). The other fields are not traced. */
struct Record013a9af0 /* derived name */
{
    ~Record013a9af0();

    Ref00503fb0<Object016b9108> held0; /* +0x0 */
    Ref00503fb0<Object016b9108> held8; /* +0x8 */
    u8 unknown10[0x20];
    Name name30; /* +0x30 */
};

Record013a9af0::~Record013a9af0() {}
