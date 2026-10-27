/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the complete destructor (slot 0) of six allocators with
 * nothing of their own to destroy (vtables 0x168ca00, 0x168d440, 0x168d4c0,
 * 0x168d540, 0x168da10, 0x168e220; also slot 1 of the first, fifth and
 * sixth; each has the thirteen-slot allocator interface, 0x168ca00 and
 * 0x168da10 with AllocatorBase's defaults 0x8d70 and 0x8d80 in slots 4 and
 * 5). It runs AllocatorBase's out-of-line destructor. */
class Allocator00004ac0 : public AllocatorBase /* derived name */
{
  public:
    virtual ~Allocator00004ac0();
};

Allocator00004ac0::~Allocator00004ac0() {}
