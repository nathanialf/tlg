/* src/libs/havok/Common/Base/System/Io/Platform/Ps4/hkPs4StreamWriter.cpp: the
 * file its assert names (config/homes.base.txt, FUN_00091ef0). */
#include "tlg_sce_fios.h"
#include "tlg_types.h"

/* derived names: the stream writer over a Fios file handle at +0xc (vtable
 * address point 0x16a3500: slot 5, 0x91ff0, tells whether the handle is
 * valid; slot 6, FUN_00091ef0, writes; slot 7, 0x91fe0, syncs; slot 9,
 * 0x92010, seeks; slot 10 tells the position). The class takes its name
 * from the file. Slot 11 of the vtable 0x16a3560 (another class reading
 * through a Fios handle at +0xc, its slots 7 and 9 seeking) holds the same
 * body. */
class hkPs4StreamWriter /* derived name */
{
  public:
    virtual ~hkPs4StreamWriter();

    int FUN_00092030() const; /* vtable slot 10; derived name */

    u8 unknown8[4];
    SceFiosFH handle; /* derived name */
};

int hkPs4StreamWriter::FUN_00092030() const /* derived name */
{
    return sceFiosFHTell(handle);
}
