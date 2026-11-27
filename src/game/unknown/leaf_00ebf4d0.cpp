/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_game_object00f0e560.h"

/* derived names: the sound runtime's calls on a handle (the first argument
 * an int, `mov edi, [rbx+0xc]`); what they do is not traced. */
void FUN_00ed7e60(int handle, int other);
void FUN_00ed7180(int handle);
void FUN_00ed5e10(int handle);

/* derived names: the owner of the entries below, which counts them at +0x84 */
struct Owner016beae0 { /* derived name */
    u8 unknown0[0x84];
    int count84; /* +0x84 */
};

/* derived names: the class whose vtable is at 0x16beae0
 * (config/vtables.derived.base.txt; built by FUN_00eb6be0), an entry of an
 * intrusive list over Object00f0e560 holding a handle of the sound runtime
 * (+0xc, negative for none) and another at +0x28. Its destructor
 * (0xebf4d0; the deleting one 0xebf580) releases the handle when it holds
 * one (the second handed back first when it holds that too: each then
 * marked -1, the four bytes at +0x34 reset), tells its owner (+0x20) there
 * is one fewer, then the base takes it out of its list. */
class Object016beae0 : public Object00f0e560 /* derived name */
{
  public:
    virtual ~Object016beae0();

  private:
    Owner016beae0 *owner; /* +0x20 */
    int other28;          /* +0x28 */
    u8 unknown2c[0x8];
    s8 unknown34;    /* +0x34 */
    s8 unknown35[3]; /* +0x35 */
};

// NONMATCHING: the four bytes at +0x34: the base stores them as a byte, a 16-bit word and a byte in
// that order (also 0xeb6e4d, 0xeb7095, 0xebd6a7), but as four bytes in the constructor (0xeb6d81);
// four byte stores here become one 32-bit store, and this memset puts the byte at +0x37 before the
// word. The deleting destructor FUN_00ebf580 differs at the same place only.
// Round 599C, link-stage IR compiled alone: the memset and a single i24 store give the same
// (byte first, also with -pre-RA-sched=source): the two stores of one TokenFactor; 0xebd6a7 has
// an unrelated store between the base's word and byte, so the base is that form too. Chained
// i16 then i8 stores give the base's order. Decided in SelectionDAG, after the IR.
Object016beae0::~Object016beae0()
{
    if (unknownc >= 0) {
        if (other28 >= 0) {
            FUN_00ed7e60(unknownc, other28);
            other28 = -1;
        }
        FUN_00ed7180(unknownc);
        FUN_00ed5e10(unknownc);
        unknownc = -1;
        unknown34 = -2;
        memset(unknown35, -1, sizeof(unknown35));
    }
    owner->count84--;
}
