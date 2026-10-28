/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: one product to the result, the schema's type and five
 * values written, the stream moved past the schema. */
void FUN_0017d430(const SetupParams0017d430 *params, const SetupScales0017d430 *scales,
                  SetupOut0017d430 *out, Schema0017d430 **schemaInOut)
{
    out->unknownc = params->unknown0 * scales->unknown8;
    Schema0017d430 *schema = *schemaInOut;
    schema->type = 10;
    schema->unknown30 = params->unknown8 * scales->unknown4;
    schema->unknown34 = params->unknownc * scales->unknown4;
    schema->unknown38 = params->unknown4;
    schema->unknown3c = params->unknown10;
    schema->unknown40 = params->unknown14;
    *schemaInOut = schema + 1;
}
