/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: a 48-byte element with a virtual destructor (slot 0, called
 * for each element: `call qword ptr [rax]`); not traced further */
class Element01372c50 /* derived name */
{
  public:
    virtual ~Element01372c50();

  private:
    u8 unknown8[0x28];
};

/* derived names: FUN_01372c50 resets a record that FUN_0087fe50,
 * FUN_00881ef0 and FUN_00882c10 hold: the int at +0x14 cleared, then its
 * first two words, the int at +0x10 made -1 (in that order: the base stores
 * +0x14 first and does not merge it with +0x10), the elements at +0x38 destroyed
 * and their block given back (tlg_game_array.h's clear()), the counted
 * references at +0x50 emptied (clear(0), the out-of-line FUN_0138c8d0),
 * then the 32 bytes from +0x18 cleared. What the fields hold is not
 * traced. */
struct Record01372c50 { /* derived name */
    void reset();       /* derived name */

    void *unknown0;                                        /* +0x0 */
    void *unknown8;                                        /* +0x8 */
    int unknown10;                                         /* +0x10 */
    int unknown14;                                         /* +0x14 */
    void *unknown18[4];                                    /* +0x18 */
    Array05943280<Element01372c50> elements;               /* +0x38 */
    Array05943280<Ref00503fb0<Object016b9108>> references; /* +0x50 */
};

void Record01372c50::reset()
{
    unknown14 = 0;
    unknown0 = 0;
    unknown8 = 0;
    unknown10 = -1;
    elements.clear();
    references.clear(0);
    for (int i = 0; i < 4; ++i)
        unknown18[i] = 0;
}
