/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"
#include "tlg_game_referenced.h"

/* derived names: the function at 0x16be4d0 (+0x40 from the vtable stored at
 * 0x16be490): a resource's loaded contents let go. The list at +0x58 of the
 * resource (its count at +0, its objects at +8) counts the packfiles; loaded
 * in place, each packfile of the buffer's table (from +8: its offset in the
 * buffer and its size) is unloaded there; otherwise each object loses its
 * reference. The list is freed and the pointer cleared. The object itself
 * is not read; the classes are not traced. */
struct Object00e9a860; /* derived name */

struct List00e9a860 { /* derived name */
    u32 count;
    Referenced00eaaec0 **objects; /* +0x8 */
};

struct Resource00e9a860 { /* derived name */
    u8 unknown0[0x58];
    List00e9a860 *unknown58;
};

struct Packfile00e9a860 { /* derived name */
    u32 offset;
    int size;
};

struct Buffer00e9a860 { /* derived name */
    u8 unknown0[0x8];
    Packfile00e9a860 packfiles[1];
};

void FUN_00e9a860(Object00e9a860 *, Resource00e9a860 *resource, Buffer00e9a860 *buffer,
                  int loadedInPlace) /* derived name */
{
    List00e9a860 *list = resource->unknown58;
    if (list == 0) {
        return;
    }
    if (loadedInPlace) {
        for (u32 i = 0; i < list->count; i++) {
            FUN_0017e860(hkAddByteOffset(static_cast<void *>(buffer), buffer->packfiles[i].offset),
                         buffer->packfiles[i].size);
        }
    } else {
        for (u32 i = 0; i < list->count; i++) {
            list->objects[i]->removeReference();
        }
    }
    delete list;
    resource->unknown58 = 0;
}
