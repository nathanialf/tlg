/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: two callbacks FUN_00481170 registers (their addresses
 * taken at 0x48143d and 0x48148d): each looks the int at +0xc of its second
 * argument up in one of two tables of 16 lists, keyed by its low four bits
 * (the first at +0x0, the second at +0xa0 of the record at +0x58 of the
 * record at +0x900 of the record at +0x38 of the object at 0x57c9390), and
 * calls the handler of the first entry with that key with the argument;
 * both return 0. The first argument is unused; the types beyond their
 * widths are not traced. */
struct Message004a2c80 { /* derived name */
    u8 unknown0[0xc];
    unsigned unknownC; /* +0xc: the key */
};

struct Handler004a2c80 {                       /* derived name */
    unsigned key;                              /* +0x0 */
    void (*handler)(Message004a2c80 *message); /* +0x8 */
    Handler004a2c80 *next;                     /* +0x10 */
};

struct Tables004a2c80 {            /* derived name */
    Handler004a2c80 *unknown0[16]; /* +0x0 */
    u8 unknown80[0x20];
    Handler004a2c80 *unknownA0[16]; /* +0xa0 */
};

struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x58];
    Tables004a2c80 *unknown58; /* +0x58 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Member057c9390_38_900 *unknown900; /* +0x900 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38; /* +0x38 */
};

extern Object057c9390 *D_57c9390;

int FUN_004a2c80(void *, Message004a2c80 *message) /* derived name */
{
    Tables004a2c80 *tables = D_57c9390->unknown38->unknown900->unknown58;
    unsigned key = message->unknownC;
    for (Handler004a2c80 *entry = tables->unknown0[key & 15]; entry; entry = entry->next) {
        if (entry->key == key) {
            entry->handler(message);
            break;
        }
    }
    return 0;
}

int FUN_004a2cd0(void *, Message004a2c80 *message) /* derived name */
{
    Tables004a2c80 *tables = D_57c9390->unknown38->unknown900->unknown58;
    unsigned key = message->unknownC;
    for (Handler004a2c80 *entry = tables->unknownA0[key & 15]; entry; entry = entry->next) {
        if (entry->key == key) {
            entry->handler(message);
            break;
        }
    }
    return 0;
}
