/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: a record with no virtual function whose destructor is a
 * function of its own (0x13663d0, called by FUN_01365f60): its
 * members released last first (the name at +0x68, the name at +0x64, the reference at +0x58, the reference at +0x50). The other fields are not traced. */
struct Record013663d0 /* derived name */
{
    ~Record013663d0();

    u8 unknown0[0x50];
    Ref00503fb0<Object016b9108> held50; /* +0x50 */
    Ref00503fb0<Object016b9108> held58; /* +0x58 */
    u8 unknown60[0x4];
    Name name64; /* +0x64 */
    Name name68; /* +0x68 */
};

Record013663d0::~Record013663d0() {}
