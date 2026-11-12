/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3d88.h"
#include "tlg_game_object016d3dd0.h"

/* derived names: the class whose vtable is at 0x16bfc70
 * (config/vtables.derived.base.txt, stored by FUN_00f71bc0 and its two
 * destructors), derived from Object016d3d88: slot 2 is its own
 * (FUN_013d90d0), slot 3 the base's, slots 4 to 6 its own (declared; their
 * bodies are not written here). Its own fields from +0x34 are traced only
 * where its destructor tears them down: an array of two Object016d3dd0 at
 * +0x80 (each: its vptr stored, `call 0x13d8be0`, its block at +0x8
 * released; the second first, the first one's address held: `mov r14, rbx;
 * sub r14, -0x80` before the first call). */
class Object016bfc70 : public Object016d3d88 /* derived name */
{
  public:
    virtual ~Object016bfc70();
    virtual void slot2(); /* derived name; FUN_013d90d0, not traced */
    virtual void slot4(); /* derived name; FUN_00f7d610, not traced */
    virtual void slot5(); /* derived name; FUN_013d8910, not traced */
    virtual void slot6(); /* derived name; FUN_013d89f0, not traced */

  private:
    u8 unknown34[0x4c];
    Object016d3dd0 members80[2]; /* +0x80, +0xa0 */
};

/* derived name: the complete destructor: the body is empty; the pair at
 * +0x80 is destroyed, last first (their destructor 0x13d8b70 inlined), then
 * the base's destructor is inlined (its vptr store, the Name at +0x30, the
 * block at +0x18). FUN_013d9ec0, slot 1, is the deleting one. The destructor
 * is the class's key function, so this file emits the vtable. */
// NONMATCHING: the array's first entry's address held across the calls (`mov r14, rbx; sub r14, -0x80`
// before the first call) where the build folds it into each use (331 bytes against 355): the class
// of 0xa920f0's ten entries, an array destroy loop that reaches code generation as more than one block
Object016bfc70::~Object016bfc70() {}
