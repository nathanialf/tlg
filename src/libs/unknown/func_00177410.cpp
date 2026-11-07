/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpCharacterProxy::FUN_00177410(hknpWorld *signalWorld)
{
    ContactSink001771e0 *sink = static_cast<ContactSink001771e0 *>(signalWorld->FUN_00051610());
    hkArray<hknpCharacterProxyContact> newContacts;
    if (listener.pntr) {
        listener.pntr->unknownVirtual6(this, sink, newContacts);
    }
    if (world->bodyManager.bodies[bodyId].flags & 8) {
        {
            hknpMaterial material;
            material.staticFriction.setReal(0.0f);
            material.dynamicFriction.setReal(0.0f);
            for (int i = 0; i < contacts.getSize(); i++) {
                if (contacts[i].flag28 == 1) {
                    FUN_001771e0(contacts[i], &material, sink);
                }
            }
        }
        for (int i = 0; i < newContacts.getSize(); i++) {
            const hknpCharacterProxyContact &contact = newContacts[i];
            if (!listener.pntr || listener.pntr->unknownVirtual5(this, &contact)) {
                contacts.pushBack(contact);
                FUN_001771e0(contact, HK_NULL, sink);
            }
        }
    }
}
