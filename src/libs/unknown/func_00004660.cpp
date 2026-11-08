/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The class's interfaces' count, its enums and their count, then each
 * member: the classes it holds (a struct's class and its parents) and its
 * enum written first, then its name, its type and subtype as the old
 * format had them (an enum's or flags' storage size in the flags, an
 * ignored member as a zero member over its type), its array size and its
 * flags; then the members' count. */
void hkClass::FUN_00004660(hkStreamWriter *writer) const
{
    hkOArchive archive(writer, false);
    archive.FUN_0000a7a0(numImplementedInterfaces);
    for (int i = 0; i < numDeclaredEnums; i++) {
        declaredEnums[i].FUN_00014e80(writer);
    }
    archive.FUN_0000a7a0(numDeclaredEnums);
    for (int i = 0; i < numDeclaredMembers; i++) {
        const hkClassMember &member = declaredMembers[i];
        const char *memberName = member.name;
        const hkClass *memberClass = member.structClass;
        const hkClassEnum *memberEnum = member.enumClass;
        u8 type = member.type;
        u8 subtype = member.subtype;
        const s16 cArraySize = member.cArraySize;
        u16 flags = member.flags.get();
        if (type == hkClassMember::TYPE_ENUM || type == hkClassMember::TYPE_FLAGS) {
            flags ^= hkClassMember::FUN_00007d40(hkClassMember::Type(subtype)).size << 3;
            subtype = 0;
        }
        u16 zeroSubtype = 0;
        if (flags & hkClassMember::SERIALIZE_IGNORED) {
            flags ^= hkClassMember::SERIALIZE_IGNORED;
            zeroSubtype = subtype;
            subtype = type;
            type = hkClassMember::TYPE_ZERO;
        }
        if (memberClass && member.type != hkClassMember::TYPE_POINTER &&
            member.subtype != hkClassMember::TYPE_POINTER) {
            for (const hkClass *c = FUN_00004250(&member); c; c = c->parent) {
                c->FUN_00004660(writer);
            }
        }
        if (memberEnum) {
            FUN_00007f80(&member)->FUN_00014e80(writer);
        }
        archive.FUN_000089f0(memberName, FUN_00017fe0(memberName));
        archive.FUN_0000a480(u16(type));
        archive.FUN_0000a480(u16(subtype));
        if (zeroSubtype) {
            archive.FUN_0000a480(zeroSubtype);
        }
        archive.FUN_0000a480(cArraySize);
        archive.FUN_0000a480(s16(flags));
    }
    archive.FUN_0000a7a0(numDeclaredMembers);
}
