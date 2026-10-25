/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the member function hknpCharacterProxy's constructor
 * (0x176420) subscribes to a signal; it hands the signal's arguments on to
 * the virtual at slot 5. */
void hknpCharacterProxy::FUN_00176b10(hknpCharacterProxySignalSource *source,
                                      hknpCharacterProxySignalData *data)
{
    FUN_00176cc0(source, data);
}
