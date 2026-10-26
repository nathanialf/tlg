/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: the out-of-line constructor of an interface (vtable
 * 0x16a5600) built at +0x68 of the object the function at 0x49d8b creates
 * (vtables 0x16991e0 at +0 and 0x16a4570 at +0x10; the call at 0x49dd8). Its
 * slot 0 is the empty body 0x16a370, slot 1 the empty deleting body 0xd900,
 * slot 7 the method 0x16d200 beside this constructor; slots 4, 6, 9 and 10
 * hold the shared 0x3b640. */
class InterfaceAt68 /* derived name */
{
  public:
    InterfaceAt68();
    virtual ~InterfaceAt68();
};

// NONMATCHING: the vtable 0x16a5600 is named by neither config/vtables.base.txt nor
// config/vtables.derived.base.txt (a ruling).
InterfaceAt68::InterfaceAt68() {}
