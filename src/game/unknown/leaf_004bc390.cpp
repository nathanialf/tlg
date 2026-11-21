/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: an 8-byte entry of an array: a Name, then an int (the
 * block's alignment 4). Neither is traced further. */
struct Entry004bc390 { /* derived name */
    Name name;         /* +0x0 */
    u32 value4;        /* +0x4 */
};

/* derived names: what holds the array at +0x0, emptied by FUN_0047e690
 * and FUN_0048bcd0 (0x47f06b, 0x48c343) */
class Table004bc390 /* derived name */
{
  public:
    void FUN_004bc390();

  private:
    Array05943280<Entry004bc390> entries; /* +0x0 */
};

/* the entries emptied (each name released) and the capacity made 16 */
void Table004bc390::FUN_004bc390()
{
    entries.clear(16);
}
