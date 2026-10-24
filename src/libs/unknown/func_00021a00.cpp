/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the deleting destructor of a class whose destructor does
 * nothing and whose storage comes from the global operator new; the linker
 * kept one copy for every class of that shape. */
PlainPolymorphic::~PlainPolymorphic() /* derived name */ {}
