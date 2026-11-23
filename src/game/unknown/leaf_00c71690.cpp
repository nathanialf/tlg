/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"

/* derived names: a 0x548-byte record built on its callers' stacks
 * (FUN_001db8b0 at 0x1dbcdc and 0x1dbe53, FUN_00a26280, FUN_00a267c0,
 * FUN_00a26970, FUN_00d44e50, FUN_00d45610): eight lists of 0x20 bytes,
 * each a locked array and an int, a 0x430-byte block cleared, two ints (0x80
 * and 0x18 at +0x530 and +0x534), a float and an int. The arrays' elements and the
 * fields' meanings are not traced. */
struct List00c71690 /* derived name */
{
    List00c71690() : unknown18(0) {}

    Array01343a80<u32> array; /* +0x0 */
    int unknown18;            /* +0x18 */
};

/* derived names: the record's last 0x448 bytes, a block cleared, two ints,
 * a float and an int. The two ints' stores stay apart (`mov dword
 * [rbx+0x530], 0x80` and `mov dword [rbx+0x534], 0x18`): the store merge
 * walks up from the last store while the stored type is the same
 * (DAGCombiner.cpp:10801, LLVM 3.7.1), and the float's store at +0x438
 * stops it. Measured: an int there, or these fields as the record's own
 * (the float's store then already an integer store when the walk runs; the
 * combiner's order not traced), gives one quadword store of the two. */
struct Block00c71690 /* derived name */
{
    Block00c71690() : block(), unknown430(0x80), unknown434(0x18), unknown438(0.0f), unknown440(0)
    {
    }

    u8 block[0x430];  /* +0x0 */
    int unknown430;   /* +0x430 */
    int unknown434;   /* +0x434 */
    float unknown438; /* +0x438 */
    u8 unknown43c[0x4];
    int unknown440; /* +0x440 */
};

class Record00c71690 /* derived name */
{
  public:
    Record00c71690();

  private:
    List00c71690 lists[8]; /* +0x0 */
    Block00c71690 block;   /* +0x100 */
};

/* FUN_00c71690: the lists made empty in order, then the block */
Record00c71690::Record00c71690() {}
