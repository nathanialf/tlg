/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The library's keycode check (derived names): a flag of the file's own,
 * set by the check at 0x334f0 when the keycode it parses is valid; the
 * empty body 0x1c1e0 runs first. 0x2d880 checks a flag of its own file
 * the same way (0x57be418). */
void FUN_0001c1e0();
void FUN_000334f0(bool *valid);

static bool D_57c8810;

hknpWorldObject388Node *
hknpWorldObject388::FUN_000fc820(void *argument0, const hknpWorldObject388Context *context,
                                 void *argument2, hknpWorldObject388Node *first, void *argument4,
                                 void *argument5, const int *indexA, const int *indexB)
{
    if (!D_57c8810) {
        FUN_0001c1e0();
        FUN_000334f0(&D_57c8810);
        if (!D_57c8810) {
            return 0;
        }
    }
    u8 key = first->key;
    hknpWorldObject388Node *node = first;
    do {
        FUN_000f6ae0(argument0, context->pointer28, argument2, node, &node->range,
                     &context->entries[*indexA], argument4, &context->entries[*indexB], argument5);
        node = static_cast<hknpWorldObject388Node *>(node->next);
        if (!node) {
            return 0;
        }
    } while (node->key == key);
    return node;
}
