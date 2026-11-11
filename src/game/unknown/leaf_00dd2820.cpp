/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"
#include "tlg_game_object013c8500.h"

/* derived names: the script's file handle (as leaf_00de9a00.cpp names it):
 * the stream and the allocation function, with its user data, that made the
 * 0x18-byte handle (called with the handle, its size and 0 to free it). */
struct FileHandle00de9a50 /* derived name */
{
    FILE *file;                                                              /* +0x0 */
    void *(*allocate)(void *user, void *block, size_t size, size_t newSize); /* +0x8 */
    void *user;                                                              /* +0x10 */
};

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16bba90 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00dd2650), a writer of the script heap's dump: it writes the closing
 * tag (the string at 0x15bcdaa, "</havokscriptheap>" and a newline) through
 * its own FUN_00dd2590 (variadic: `xor eax, eax` before the call), closes
 * the file of its handle at +0x18 and frees the handle through its
 * allocation function, then runs its base's destructor (tlg_game_object013c8500.h,
 * inlined in the module). FUN_00dd2890, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
extern const char D_15bcdaa[20];

class Object016bba90 : public Object013c8500 /* derived name */
{
  public:
    virtual ~Object016bba90();
    void FUN_00dd2590(const char *format, ...); /* derived name */

  private:
    FileHandle00de9a50 *handle18; /* +0x18 */
};

Object016bba90::~Object016bba90()
{
    FUN_00dd2590(D_15bcdaa);
    FileHandle00de9a50 *handle = handle18;
    fclose(handle->file);
    handle->allocate(handle->user, handle, sizeof(FileHandle00de9a50), 0);
}
