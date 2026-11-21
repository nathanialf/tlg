/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_chunkstack.h"
#include "tlg_game_object013c8500.h"
#include "tlg_types.h"

/* derived names: an element of the stack below: a stack of 48-byte
 * elements in chunks of 32 (FUN_00db58ca: `mov dword [rbx+0x644], 0x20`)
 * and two fields cleared when it is pushed */
struct Item00db4280 {
    u8 unknown0[0x30];
};

struct Element00db4280 {
    ChunkStack<Item00db4280, 32> items; /* +0x0 */
    u64 unknown648;                     /* +0x648 */
    int unknown650;                     /* +0x650 */
};

/* derived names: the class whose vtable is at 0x16bb578 (its constructor
 * FUN_00db4100): the state at +0x8, the strings at +0x48 (their count at
 * +0x50, each a pointer, from the state's allocator with the tag 0x23) and
 * a stack of 0x658-byte elements at +0x60; the other fields and slots are
 * not traced */
class Object016bb578 /* derived name */
{
  public:
    virtual ~Object016bb578();

  private:
    HksState00dd1740 *state; /* +0x8 */
    u8 unknown10[0x38];
    void **strings;  /* +0x48 */
    u64 stringCount; /* +0x50 */
    u8 unknown58[0x8];
    ChunkStack<Element00db4280, 4> elements; /* +0x60 */
};

// NONMATCHING: the walk of the elements: the base keeps a second copy of the element for the compare with
// the next free one (`mov rax, r12; cmp rax, [r13+0x19f8]`, and `xor eax, eax` beside the two zeros of the
// last chunk's arm), where the build compares the element itself (`cmp r12, [r13+0x19f8]`, the zeros set
// before the branch); the same residual in FUN_00da4250's three walks; the deleting destructor FUN_00db44f0
// is equal
Object016bb578::~Object016bb578()
{
    if (strings) {
        externalFree(state, strings, stringCount * sizeof(void *), 0x23);
        strings = 0;
    }
}
