/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_mutex.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b93f8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00cd7ee0
 * and its destructor FUN_00cd8720), with no base whose destructor does
 * anything. Its fields are traced where the destructor tears them down:
 * ten heap blocks 0x38 bytes apart from +0x48, a counted reference at
 * +0x260, eight arrays from +0x270 (their elements not traced), two
 * mutexes at +0x330 and +0x348, references at +0x368 and +0x378 and a heap
 * block at +0x3c8. */
class Object016b93f8 /* derived name */
{
  public:
    virtual ~Object016b93f8();

  private:
    u8 unknown8[0x40];
    OwnedBlock05943280 block48; /* +0x48 */
    u8 unknown50[0x30];
    OwnedBlock05943280 block80; /* +0x80 */
    u8 unknown88[0x30];
    OwnedBlock05943280 blockb8; /* +0xb8 */
    u8 unknownc0[0x30];
    OwnedBlock05943280 blockf0; /* +0xf0 */
    u8 unknownf8[0x30];
    OwnedBlock05943280 block128; /* +0x128 */
    u8 unknown130[0x30];
    OwnedBlock05943280 block160; /* +0x160 */
    u8 unknown168[0x30];
    OwnedBlock05943280 block198; /* +0x198 */
    u8 unknown1a0[0x30];
    OwnedBlock05943280 block1d0; /* +0x1d0 */
    u8 unknown1d8[0x30];
    OwnedBlock05943280 block208; /* +0x208 */
    u8 unknown210[0x30];
    OwnedBlock05943280 block240; /* +0x240 */
    u8 unknown248[0x18];
    Ref00503fb0<Object016b9108> held260; /* +0x260 */
    u8 unknown268[0x8];
    Array05943280<u32> array270; /* +0x270 */
    Array05943280<u32> array288; /* +0x288 */
    Array05943280<u32> array2a0; /* +0x2a0 */
    Array05943280<u32> array2b8; /* +0x2b8 */
    Array05943280<u32> array2d0; /* +0x2d0 */
    Array05943280<u32> array2e8; /* +0x2e8 */
    Array05943280<u32> array300; /* +0x300 */
    Array05943280<u32> array318; /* +0x318 */
    Mutex013847e0 mutex330;      /* +0x330 */
    Mutex013847e0 mutex348;      /* +0x348 */
    u8 unknown360[0x8];
    Ref00503fb0<Object016b9108> held368; /* +0x368 */
    u8 unknown370[0x8];
    Ref00503fb0<Object016b9108> held378; /* +0x378 */
    u8 unknown380[0x48];
    OwnedBlock05943280 block3c8; /* +0x3c8 */
};

/* derived name: the complete destructor: the body is empty; the members
 * are torn down, last first. FUN_00cd8e00, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
Object016b93f8::~Object016b93f8() {}
