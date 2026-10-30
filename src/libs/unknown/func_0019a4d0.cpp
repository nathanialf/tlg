/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkResult hkSerializeDeprecated::FUN_0019a4d0(StreamReader *reader, const void *,
                                             SerializeErrorDetails *errorOut)
{
    if (errorOut) {
        hkXmlParser parser;
        hkXmlParser::Node *node = HK_NULL;
        if (parser.FUN_0019da90(&node, reader) == HK_SUCCESS) {
            XmlStartElement *start = node->asStart();
            if (start && start->name.cString() &&
                FUN_00017f40(start->name.cString(), "hkpackfile") == 0 && errorOut->id == 0) {
                errorOut->id = 7;
                errorOut->defaultMessage = D_14cca20;
            }
            node->releaseReference();
        }
    }
    return HK_FAILURE;
}
