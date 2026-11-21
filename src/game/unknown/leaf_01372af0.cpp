/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: the 48-byte elements of the array at +0x18 below, each
 * destroyed through its vtable's slot 0 (`call [rax]`); nothing else of
 * them is traced */
class Element01372af0 /* derived name */
{
  public:
    virtual ~Element01372af0();

  private:
    u8 unknown8[0x28];
};

/* derived names: a record that FUN_00881ef0, FUN_00882c10 and the
 * constructor of Object016af2d8 empty through FUN_01372af0: a pointer and
 * two ints, a counted reference another thread may replace at +0x10 and an
 * array of polymorphic elements at +0x18. Their meaning is not traced. */
struct Record01372af0 /* derived name */
{
    /* 0x1372af0: the pointer and the int at +0x8 cleared, the array
     * emptied and its block given back, the reference emptied, then the int
     * at +0xc cleared */
    void reset(); /* derived name */

    void *unknown0;                           /* +0x0 */
    int unknown8;                             /* +0x8 */
    int unknownC;                             /* +0xc */
    AtomicRef0045c470<Object016b9108> held10; /* +0x10 */
    Array05943280<Element01372af0> elements;  /* +0x18 */
};

void Record01372af0::reset()
{
    unknown0 = 0;
    unknown8 = 0;
    elements.clear();
    held10.clear();
    unknownC = 0;
}
