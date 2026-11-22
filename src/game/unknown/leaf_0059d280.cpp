/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_block.h"

/* derived names: an object of FUN_0059d280's node's list, its sixth virtual
 * method (slot 5, +0x28) given the VM. */
struct Entry59d280Vtable { /* derived name */
    void *unknown0[5];
    void (*method5)(void *self, void *vm); /* +0x28 */
};

struct Entry59d280 { /* derived name */
    Entry59d280Vtable *vtable;
};

/* derived names: the node FUN_0059c610 queues FUN_0059d280 with: a list of
 * objects, the array at +0x48 and its count at +0x50. */
struct Node59d280 { /* derived name */
    u8 unknown0[0x48];
    Entry59d280 **entries; /* +0x48 */
    int count;             /* +0x50 */
};

/* derived names: a 0xa8-byte record of the object below, a block at +0x0 */
struct Record59d280 { /* derived name */

    /* the block released and its pointer cleared (derived name) */
    void clear()
    {
        if (block) {
            FUN_00ebf3f0(block);
            block = 0;
        }
    }

    void *block;
    u8 unknown8[0xa0];
};

/* derived names: the object the node's value holds at +0x8: a block at
 * +0xf0 and an array of records at +0xf8, its count at +0x100. */
struct Object59d280 { /* derived name */

    /* the block at +0xf0 released and its pointer cleared (derived name) */
    void clearBlock()
    {
        if (block) {
            FUN_00ebf3f0(block);
            block = 0;
        }
    }

    /* each record's block released, the count read once (derived name) */
    void clearRecords()
    {
        const int count = recordCount;
        for (int i = 0; i < count; ++i)
            records[i].clear();
    }

    u8 unknown0[0xf0];
    void *block;           /* +0xf0 */
    Record59d280 *records; /* +0xf8 */
    int recordCount;       /* +0x100 */
};

struct Value59d280 { /* derived name */
    u8 unknown0[8];
    Object59d280 *object; /* +0x8 */
};

/* derived names: a call FUN_0059c610 appends to the owner's call frame,
 * given the VM and the node and value it was queued with: hands the VM to
 * each object of the node's list (method 5), then releases the block at
 * +0xf0 of the value's object and the block of each of its records,
 * clearing each pointer; returns 0. */
int FUN_0059d280(void *vm, const CallArguments583950 *arguments) /* derived name */
{
    Node59d280 *node = static_cast<Node59d280 *>(arguments->node);
    Value59d280 *value = static_cast<Value59d280 *>(arguments->value);
    const int count = node->count;
    for (int i = 0; i < count; ++i) {
        Entry59d280 *entry = node->entries[i];
        entry->vtable->method5(entry, vm);
    }
    value->object->clearBlock();
    value->object->clearRecords();
    return 0;
}
