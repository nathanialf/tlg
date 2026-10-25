/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 6 of the file image source's vtable (address point
 * 0x16a3ab0) loads the image its file name gives. */
LoadedImage *FileImageSource::FUN_000ad7b0() /* derived name */
{
    return FUN_00188560(fileName.cString());
}
