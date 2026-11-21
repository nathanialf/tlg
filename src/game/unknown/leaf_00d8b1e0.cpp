/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object01367090.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_game_object016b9108.h"

/* derived names: the objects the arrays at +0x250 and +0x298 hold
 * (counted, derived from the root class, two kinds); not traced. Each
 * array's destructor over its kind is this unit's alone and has one caller,
 * so the link inlines both in the destructor below, as the base shows (no
 * call to 0x134f620 for them) */
class Element250016bae90 : public Object016b9108
{
};

class Element298016bae90 : public Object016b9108
{
};

/* derived name: an element of the array at +0x8338, 24 bytes (`lea rax,
 * [rax+rax*2]; lea rdi, [rcx+rax*8]`): a pair of references first, whose
 * destructor FUN_01367090 is called on each; the rest is not traced */
struct Element8338016bae90 {
    Object01367090 pair; /* +0x0 */
    u8 unknown10[0x8];
};

/* derived name: a table of 4096 counted references, each released first
 * to last by its destructor before the references themselves are torn
 * down, last first */
struct RefTable016bae90 {
    ~RefTable016bae90()
    {
        for (unsigned long i = 0; i < 0x1000; ++i)
            references[i].release();
    }

    Ref00503fb0<Object016b9108> references[0x1000];
};

/* derived names: the class whose vtable is at 0x16bae90
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00d8af80
 * and its destructor FUN_00d8b1e0), derived from Object016b85e0 (its
 * destructor 0xc55550): the base's slots and fields are not traced, so the
 * bytes below the first member here are the base's or this class's. Its
 * own fields are traced where the destructor tears them down: arrays of
 * counted references at +0x250 to +0x2b0 and +0x308, references at +0x2c8
 * to +0x300, a table of references at +0x328 and an array of pairs at
 * +0x8338. */
class Object016bae90 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016bae90();

  private:
    u8 unknown8[0x248];
    Array05943280<Ref00503fb0<Element250016bae90>> array250; /* +0x250 */
    Array05943280<Ref00503fb0<Object016b9108>> array268;     /* +0x268 */
    Array05943280<Ref00503fb0<Object016b9108>> array280;     /* +0x280 */
    Array05943280<Ref00503fb0<Element298016bae90>> array298; /* +0x298 */
    Array05943280<Ref00503fb0<Object016b9108>> array2b0;     /* +0x2b0 */
    Ref00503fb0<Object016b9108> held2c8;                     /* +0x2c8 */
    Ref00503fb0<Object016b9108> held2d0;                     /* +0x2d0 */
    Ref00503fb0<Object016b9108> held2d8;                     /* +0x2d8 */
    Ref00503fb0<Object016b9108> held2e0;                     /* +0x2e0 */
    Ref00503fb0<Object016b9108> held2e8;                     /* +0x2e8 */
    Ref00503fb0<Object016b9108> held2f0;                     /* +0x2f0 */
    Ref00503fb0<Object016b9108> held2f8;                     /* +0x2f8 */
    Ref00503fb0<Object016b9108> held300;                     /* +0x300 */
    Array05943280<Ref00503fb0<Object016b9108>> array308;     /* +0x308 */
    u8 unknown320[0x8];
    RefTable016bae90 table328; /* +0x328 */
    u8 unknown8328[0x10];
    Array05943280<Element8338016bae90> array8338; /* +0x8338 */
};

/* derived name: the complete destructor: the body is empty; the members
 * are torn down, last first, then the base's destructor FUN_00c55550 runs
 * as a tail call. FUN_00d8ba10, slot 1, is the deleting one. The destructor
 * is the class's key function, so this file emits the vtable. */
Object016bae90::~Object016bae90() {}
