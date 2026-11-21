/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_chunkstack.h"
#include "tlg_game_compiler00da5b20.h"
#include "tlg_types.h"

/* derived names: what the compiler's state reaches at +0x10, whose
 * pointer at +0x150 the compiler sets back when it is destroyed */
struct Global00da4250 {
    u8 unknown0[0x150];
    void *unknown150; /* +0x150 */
};

struct State00da4250 {
    u8 unknown0[0x10];
    Global00da4250 *global; /* +0x10 */
};

/* derived names: the class whose vtable is at 0x16bb0c0 (the compiler of
 * tlg_game_compiler00da5b20.h, as its slots read it): the state at +0x8,
 * the pointer it gives back to the state's global at +0x10, the stacks of
 * records (0x110 bytes, the one on top at +0x4b8), of entries (at +0x4d0)
 * and of function states (at +0x558, the one on top at +0x7dc8), given
 * back in that order; the other
 * fields and slots are not traced */
/* derived names: the function states of the stack at +0x558
 * (FuncState00da5b20 of tlg_game_compiler00da5b20.h, 0x1e10 bytes), their
 * destructor FUN_00da3790 called for each (not written), and the records
 * of the stack at +0x48 (Record00daa830 there, 0x110 bytes), whose walk
 * the base keeps with nothing in it: their destructor does nothing */
struct Function00da4250 {
    ~Function00da4250();
    u8 unknown0[0x1e10];
};

struct Record00da4250 {
    ~Record00da4250() {}

    u8 unknown0[0x110];
};

class Object016bb0c0 /* derived name */
{
  public:
    virtual ~Object016bb0c0();

  private:
    State00da4250 *state; /* +0x8 */
    void *saved;          /* +0x10 */
    u8 unknown18[0x30];
    ChunkStack<Record00da4250, 4> records;     /* +0x48 */
    ChunkStack<Entry00dadfd0, 4> entries;      /* +0x4d0 */
    ChunkStack<Function00da4250, 4> functions; /* +0x558 */
};

// NONMATCHING: the walks of the records and the function states: the base keeps a second copy of the element
// for the compare with the next free one (`mov rax, rbx; cmp rax, [r14+0x7dd0]`), as FUN_00db4280; the
// function states' destructor is FUN_00da3790 (its row to be named for the class once the walk matches); the
// deleting destructor FUN_00da4530 is equal
Object016bb0c0::~Object016bb0c0()
{
    state->global->unknown150 = saved;
}
