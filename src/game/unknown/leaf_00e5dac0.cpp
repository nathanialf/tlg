/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_sce_fios.h"
#include "tlg_types.h"

/* derived names: whether a file exists (sceFiosFileExistsSync, its NID
 * verified) at the path made of the object's directory at +0x1d0 (its first
 * 62 characters copied) followed, from the directory's length on, by the
 * name in lower case, in a 1 KiB buffer cleared first. FUN_00e5dac0 and
 * FUN_00e5f270 are the same body; no direct caller (a virtual function:
 * the class is not traced). */
struct Device00e5dac0 { /* derived name */
    u8 unknown0[0x1d0];
    char directory[0x40]; /* +0x1d0; its extent not traced */
};

// NONMATCHING: the loop's guard: the base tests the length as 64 bits under two masks
// (`and eax, 0xfffffc00; cmp rax, 0x3ff`, the start `and rbx, r13` with 0xfffffc00 hoisted and
// rebased to 0xffffffff), here one zero-extension serves both (`mov ebx, r12d; cmp rbx, 0x3ff`;
// an unsigned counter gives `cmp r14d, 0x3ff`); the body otherwise equal
bool FUN_00e5dac0(const Device00e5dac0 *self, const char *name) /* derived name */
{
    char path[0x400];
    memset(path, 0, sizeof(path));
    const unsigned length = strlen(self->directory);
    strncpy(path, self->directory, 0x3e);
    for (size_t i = length; i < sizeof(path); ++i) {
        const int c = tolower(*name++);
        if (!c)
            break;
        path[i] = c;
    }
    return sceFiosFileExistsSync(0, path);
}
