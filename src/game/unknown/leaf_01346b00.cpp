/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* The destructor of a counted reference another thread may replace
 * (tlg_game_node.h) has a copy of its own in the executable, 0x1346b00. No
 * call reaches it: the static initializers of 14 units hand its address to
 * atexit (15 `lea` sites, 0x205d80 to 0xd7ef30), each for a static reference
 * that other functions replace by compare-and-swap (`lock cmpxchg qword` on
 * the static's address in 0x1bd010, 0x1fb830, 0x1db8b0 and the rest). The
 * member instantiated here. */
template AtomicRef0045c470<Object016b9108>::~AtomicRef0045c470();
