/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c8500.h"
#include "tlg_hks.h"

/* derived names: the object's own marks the walks below call with a pointer
 * the record holds (their bodies are not written; the pointers' types are not
 * traced) */
void FUN_013bf510(Object013c8500 *self, void *value); /* derived name */
void FUN_013bf700(Object013c8500 *self, void *value); /* derived name */
void FUN_013bf850(Object013c8500 *self, void *value); /* derived name */
void FUN_013bf9a0(Object013c8500 *self, void *value); /* derived name */
void FUN_013bfaf0(Object013c8500 *self, void *value); /* derived name */
void FUN_013bfc40(Object013c8500 *self, void *value); /* derived name */
void FUN_013bfd90(Object013c8500 *self, void *value); /* derived name */
void FUN_013bfee0(Object013c8500 *self, void *value); /* derived name */

/* derived names: slot 8 of the vtables at 0x16bba90 and 0x16bc170: the
 * pointer at +0x18 to FUN_013bfaf0, then each of the values at +0x30 (the
 * signed 16-bit count at +0x20, read again at each step) through its four
 * slots */
void Object013c8500::visit00dd13d0(const Record00dd13d0 *record)
{
    FUN_013bfaf0(this, record->environment);
    for (int i = 0; i < record->count; ++i)
        visit(&record->values[i]);
}

/* derived names: slot 9: the function at +0x10 to FUN_013bfd90, the pointer
 * at +0x18 to FUN_013bfaf0, the element at +0x21 through its four slots,
 * then each pointer from +0x38 (the function's count at +0x10) to
 * FUN_013bf700 */
void Object013c8500::visit00dd1460(const Record00dd1460 *record)
{
    FUN_013bfd90(this, record->function);
    FUN_013bfaf0(this, record->environment);
    visit(&record->inline21);
    for (int i = 0; i < record->function->count; ++i)
        FUN_013bf700(this, record->pointers[i]);
}

/* derived names: slot 13: each value of the array (its pointer and its
 * unsigned count read again at each step) through its four slots */
void Object013c8500::visit00dd18c0(const ValueArray00dd18c0 *array)
{
    for (u64 i = 0; i < array->count; ++i)
        visit(&array->values[i]);
}

/* derived names: slot 16: the pointer at +0x0 to FUN_013bf510, the value at
 * +0x8 through its four slots, the pointers at +0x18 and +0x20 to
 * FUN_013bfee0 */
void Object013c8500::visit00dd1af0(const Record00dd1af0 *record)
{
    FUN_013bf510(this, record->unknown0);
    visit(&record->value);
    FUN_013bfee0(this, record->unknown18);
    FUN_013bfee0(this, record->unknown20);
}

/* derived names: slot 28: each 32-byte element of the array (its signed
 * count) through slots 68, 107, 29 and 146 */
void Object013c8500::visit00dd1f20(const Array00dd1f20 *array)
{
    for (int i = 0; i < array->count; ++i)
        visit(&array->elements[i]);
}

/* derived names: slot 38: each 16-byte element of the array (its unsigned
 * count at +0x0) through slots 78, 117, 39 and 156 */
void Object013c8500::visit00dd2500(const Array00dd2500 *array)
{
    for (u32 i = 0; i < array->count; ++i)
        visit(&array->elements[i]);
}

/* derived names: slot 35: the block at +0x8, the array of pointers at +0x18,
 * each through its kind's four slots, the pointer at +0x28 to FUN_013bf850,
 * then the array at +0x38 through slots 77, 116, 38 and 155 (the last a
 * tail call) */
void Object013c8500::visit00dd2190(const Record00dd2190 *record)
{
    visit(&record->block8);
    visit(&record->pointers);
    FUN_013bf850(this, record->source);
    visit(&record->array38);
}

/* derived names: slot 18: the pointer at +0x48 to FUN_013bf510, then the
 * arrays at +0x68, +0xa8 and +0x78 and the values at +0xc0 and +0xe8, each
 * through its kind's four slots (the last a tail call) */
void Object013c8500::visit00dd1b80(const Record00dd1b80 *record)
{
    FUN_013bf510(this, record->unknown48);
    visit(&record->array68);
    visit(&record->arrayA8);
    visit(&record->array78);
    visit(&record->valueC0);
    visit(&record->valueE8);
}

/* derived names: slot 15: its first bytes, the record at +0x58, the table at
 * +0x1a8 and the value at +0x1c8, each through its kind's four slots; the
 * pointers at +0x1f8, +0x200 and +0x1e8 to the object's marks; the block at
 * +0x1d8 when its field at +0xa is set; the pointer at +0x588 to FUN_013bfee0 */
void Object013c8500::visit00dd1950(const Record00dd1950 *record)
{
    visit(&record->header);
    visit(&record->record58);
    visit(&record->table1a8);
    visit(&record->value1c8);
    FUN_013bfc40(this, record->unknown1f8);
    FUN_013bf510(this, record->unknown200);
    FUN_013bfaf0(this, record->unknown1e8);
    if (record->block1d8.unknownA)
        visit(&record->block1d8);
    FUN_013bfee0(this, record->unknown588);
}

/* derived names: slot 12: each 16-byte element of the array (its signed
 * count) through slot 51, then, when it was not walked before, slots 90, 11
 * and 129 */
void Object013c8500::visit00dd1740(const Array00dd1740 *array)
{
    for (int i = 0; i < array->count; ++i)
        visit(&array->elements[i]);
}

/* derived names: slot 41: each pointer of the block (its unsigned 16-bit
 * count at +0x8), a copy of it handed to slot 79, then, when it is set and
 * not walked before, to slots 118, 40 and 157 */
void Object013c8500::visit00dd22f0(const Block00dd1950 *block)
{
    for (size_t i = 0; i < block->count; ++i)
        visit(block->items[i]);
}

/* derived names: slot 10: the parts at +0x18 and +0x28 and the array at
 * +0x38, each through its kind's four slots, then the record at +0x48, when
 * set, through slot 74 and, when it was not walked before, slots 113, 35 and
 * 152 */
void Object013c8500::visit00dd1510(const Record00dd1510 *record)
{
    visit23(&record->part18);
    visit24(&record->part28);
    visit(&record->items);
    if (record->debug)
        visit(record->debug);
}

/* derived names: slot 3: the global state at +0x10 through slot 54 and,
 * when it is set and not walked before, slots 93, 15 and 132; the ranges at
 * +0x18 and +0x48 and the value at +0x70 through their kinds' four slots, the
 * pointers at +0x68, +0xa8 and +0xb0 to the object's marks */
void Object013c8500::visit00dd0ce0(const Record00dd0ce0 *record)
{
    visit(record->global);
    visit(&record->entries);
    visit(&record->values);
    FUN_013bf700(this, record->unknown68);
    visit(&record->value70);
    FUN_013bf850(this, record->unknownA8);
    FUN_013bf510(this, record->unknownB0);
}

/* derived names: slot 29: a 32-byte element by its kind, through the four
 * slots of the kind it is walked as (5 as slot 31's, 7 as 34's, 8 as 30's,
 * 9 as 32's, 10 as 33's; any other not walked) */
void Object013c8500::visit00dd1fc0(const Element00dd1f20 *element)
{
    switch (element->kind) {
    case 5:
        beforeKind31(element);
        enterKind31(element);
        markKind31(element);
        afterKind31(element);
        break;
    case 7:
        beforeKind34(element);
        enterKind34(element);
        markKind34(element);
        afterKind34(element);
        break;
    case 8:
        beforeKind30(element);
        enterKind30(element);
        markKind30(element);
        afterKind30(element);
        break;
    case 9:
        beforeKind32(element);
        enterKind32(element);
        markKind32(element);
        afterKind32(element);
        break;
    case 10:
        beforeKind33(element);
        enterKind33(element);
        markKind33(element);
        afterKind33(element);
        break;
    }
}

/* derived names: slot 6: each set value of the table's array with its key
 * (the number of its place from 1), each node with a set key (its value,
 * then its key), each as a copy through its four slots; then the pointer at
 * +0x10, when set, with its low bit cleared to FUN_013bf9a0 if that bit is
 * set, else to FUN_013bfaf0 */
void Object013c8500::visit00dd0f90(const Table00dd0f90 *table)
{
    for (u32 i = 0; i < table->arrayCount; ++i) {
        const HksObject *slot = &table->array[i];
        if (slot->type & 0xf) {
            HksObject key;
            key.value.number = float(i + 1);
            key.type = 3;
            const int type = slot->type;
            void *const pointer = slot->value.pointer;
            HksObject value;
            value.type = type;
            value.value.pointer = pointer;
            visit(&key);
            visit(&value);
        }
    }
    for (u32 i = 0; i < table->mask + 1; ++i) {
        const Node00dd0f90 *node = &table->nodes[i];
        if (node->key.type & 0xf) {
            const int valueType = node->value.type;
            void *const valuePointer = node->value.value.pointer;
            HksObject value;
            value.type = valueType;
            value.value.pointer = valuePointer;
            const int keyType = node->key.type;
            void *const keyPointer = node->key.value.pointer;
            HksObject key;
            key.type = keyType;
            key.value.pointer = keyPointer;
            visit(&value);
            visit(&key);
        }
    }
    if (u64 pointer = table->unknown10) {
        if (pointer & 1)
            FUN_013bf9a0(this, reinterpret_cast<void *>(pointer & ~u64(1)));
        else
            FUN_013bfaf0(this, reinterpret_cast<void *>(pointer));
    }
}
