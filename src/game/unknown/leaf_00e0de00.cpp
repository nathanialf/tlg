/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16bd6a0, over the one whose
 * destructor is 0xc1b7f0, with four Names of its own at +0x38 to +0x44.
 * Its complete destructor (FUN_00e0de00, slot 0) stores 0x16bd6b0, releases
 * the Names last to first (`mov eax, [rbx+0x44]; ... shl rax, 5; lock
 * xadd`), then tail-calls the base's destructor; slot 1 (FUN_00e0def0)
 * calls it before operator delete. The Names' use is not traced. */
class Object016bd6a0 : public Object00c1b7f0 /* derived name */
{
  public:
    virtual ~Object016bd6a0();

  private:
    Name name38; /* +0x38 */
    Name name3c; /* +0x3c */
    Name name40; /* +0x40 */
    Name name44; /* +0x44 */
};

Object016bd6a0::~Object016bd6a0() {}
