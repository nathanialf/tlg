/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00774560.h"

/* derived names: the member at +0x100 of the class below, handed to
 * FUN_00216780 while its int at +0x8 is set; the rest is not traced */
struct Member00216780 { /* derived name */
    int FUN_00216780(); /* derived name: not traced */

    u8 unknown0[0x8];
    int unknown8; /* +0x8 */
};

/* derived names: the class whose vtable is at 0x16acb20
 * (config/vtables.derived.base.txt, stored by its constructor FUN_007658a0
 * and its destructor FUN_007659d0, not written), derived from
 * Object00774560; nothing else of it is traced */
class Object016acb20 : public Object00774560 /* derived name */
{
  public:
    virtual ~Object016acb20();
    virtual void slot14(Pose0077bac0 *pose); /* FUN_00766e50 */

  private:
    u8 unknowne8[0x18];
    Member00216780 unknown100; /* +0x100 */
};

/* derived name: slot 14: when slot 22 says so, the member at +0x100 is run
 * while its int is set, the body put back home (Object00774560::goHome) and
 * the body's int at +0x1b0c copied to +0x3c; the pose is not read */
void Object016acb20::slot14(Pose0077bac0 *)
{
    if (slot22()) {
        if (unknown100.unknown8)
            unknown100.FUN_00216780();
        goHome();
        unknown3c = unknown68->unknown1b0c;
    }
}
