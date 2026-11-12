/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the sibling of FUN_00dd1dc0 (it calls FUN_013bf850 the same
 * way): dispatches on the kind in the low four bits of its argument's first
 * word (a nine-case jump table, 0x155a9f0, kinds 4 to 12) and passes the
 * pointer at +0x8 to one handler per kind, a tail call with the object;
 * kinds 6 and 11 and any other kind do nothing. The handlers' pointer types
 * are not traced beyond FUN_013bf850's. Class and method unknown. */
struct Object00dd1dc0; /* derived name */
struct Target00dd1dc0; /* derived name */

struct Value00dd1d60 /* derived name */
{
    u32 flags; /* derived name: the kind in bits 0 to 3 */

    union {
        Target00dd1dc0 *target; /* derived name */
        void *pointer;          /* derived name */
    };
};

void FUN_013bf850(Object00dd1dc0 *self, Target00dd1dc0 *value); /* derived name */
void FUN_013bfaf0(Object00dd1dc0 *self, void *value);           /* derived name */
void FUN_013bfc40(Object00dd1dc0 *self, void *value);           /* derived name */
void FUN_013bf510(Object00dd1dc0 *self, void *value);           /* derived name */
void FUN_013c0030(Object00dd1dc0 *self, void *value);           /* derived name */
void FUN_013c0180(Object00dd1dc0 *self, void *value);           /* derived name */
void FUN_013bf9a0(Object00dd1dc0 *self, void *value);           /* derived name */

void FUN_00dd1d60(Object00dd1dc0 *self, const Value00dd1d60 *value) /* derived name */
{
    switch (value->flags & 0xf) {
    case 4:
        FUN_013bf850(self, value->target);
        break;
    case 5:
        FUN_013bfaf0(self, value->pointer);
        break;
    case 7:
        FUN_013bfc40(self, value->pointer);
        break;
    case 8:
        FUN_013bf510(self, value->pointer);
        break;
    case 9:
        FUN_013c0030(self, value->pointer);
        break;
    case 10:
        FUN_013c0180(self, value->pointer);
        break;
    case 12:
        FUN_013bf9a0(self, value->pointer);
        break;
    }
}
