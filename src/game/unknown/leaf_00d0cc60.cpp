/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_recordlayout.h"

/* derived names: the text emptied, then each field of the layout printed
 * from the record: every value of it by its type, "%d" for the integers to
 * 32 bits, "%lld" for the 64-bit, "%.8g" for each float, the four bytes of
 * type 13 third, second, first and fourth before their float, a comma after
 * each value and a semicolon after the field's last */
// NONMATCHING: 786 bytes as the base under cvtzero-01 (round 578E), 770 under the installed
// compiler. The loop's setup is not the base's: the base keeps the fields' pointer in rax from the
// virtual call and the field index in rsi, adds the record to the offset in place (`add rdi,
// [rbp-0x50]`) and has a frame of 0x58 bytes (0x48 here); in each case it reloads the values'
// pointer after the format's cmov and indexes [offset + pointer]. Round 581E
void FUN_00d0cc60(RecordLayout *layout, const void *record, String01331840 *text) /* derived name */
{
    text->text[0] = 0;
    text->length = 0;
    const RecordField *fields = layout->fields();
    for (u32 i = 0; i < layout->fieldCount; ++i) {
        const RecordField &field = fields[i];
        const u32 count = field.count;
        const u32 stride = field.stride;
        const u8 *values = static_cast<const u8 *>(record) + field.offset;
        for (u32 j = 0; j < count; ++j) {
            const u8 *value = values + j * stride;
            const bool more = j < count - 1;
            switch (field.type) {
            case 0:
                FUN_01346a00(text, more ? "%d," : "%d;", *value);
                break;
            case 1:
                FUN_01346a00(text, more ? "%d," : "%d;", *reinterpret_cast<const s8 *>(value));
                break;
            case 2:
                FUN_01346a00(text, more ? "%d," : "%d;", *reinterpret_cast<const u16 *>(value));
                break;
            case 3:
                FUN_01346a00(text, more ? "%d," : "%d;", *reinterpret_cast<const s16 *>(value));
                break;
            case 4:
            case 5:
                FUN_01346a00(text, more ? "%d," : "%d;", *reinterpret_cast<const int *>(value));
                break;
            case 6:
            case 7:
                FUN_01346a00(text, more ? "%lld," : "%lld;",
                             *reinterpret_cast<const long long *>(value));
                break;
            case 8: {
                const float *f = reinterpret_cast<const float *>(value);
                FUN_01346a00(text, more ? "%.8g," : "%.8g;", f[0]);
                break;
            }
            case 9: {
                const float *f = reinterpret_cast<const float *>(value);
                FUN_01346a00(text, more ? "%.8g %.8g," : "%.8g %.8g;", f[0], f[1]);
                break;
            }
            case 10: {
                const float *f = reinterpret_cast<const float *>(value);
                FUN_01346a00(text, more ? "%.8g %.8g %.8g," : "%.8g %.8g %.8g;", f[0], f[1], f[2]);
                break;
            }
            case 11:
            case 12: {
                const float *f = reinterpret_cast<const float *>(value);
                FUN_01346a00(text, more ? "%.8g %.8g %.8g %.8g," : "%.8g %.8g %.8g %.8g;", f[0],
                             f[1], f[2], f[3]);
                break;
            }
            case 13: {
                const float *f = reinterpret_cast<const float *>(value + 4);
                FUN_01346a00(text, more ? "%d %d %d %d %.8g," : "%d %d %d %d %.8g;", value[2],
                             value[1], value[0], value[3], f[0]);
                break;
            }
            }
        }
    }
}
