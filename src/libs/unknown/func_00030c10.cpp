/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpWorldObject380::FUN_00030c10(void *argument0, hknpWorldObject380Pair *pair,
                                      void *argument2, void *argument4, void *argument5,
                                      void *argument6, hknpWorldObject380Writer *writer)
{
    hknpWorldObject380Info info;
    info.flag = false;
    const int end =
        FUN_0002b6c0(argument0, pair, argument2, &info, argument4, argument5, argument6, writer);
    hknpWorldObject380Output *output = pair->output;
    output->range = writer->range;
    output->count = u16(end - output->range.start);
}
