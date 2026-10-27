/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkClass::hkClass(const char *className, const hkClass *parentClass, int objectSizeInBytes,
                 const hkClass **implementedInterfaces, int numImplementedInterfaces,
                 const hkClassEnum *declaredEnums, int numDeclaredEnums,
                 const hkClassMember *declaredMembers, int numDeclaredMembers, const void *defaults,
                 const hkCustomAttributes *attributes, u32 flags, u32 describedVersion)
    : name(className), parent(parentClass), objectSize(objectSizeInBytes),
      numImplementedInterfaces(numImplementedInterfaces), declaredEnums(declaredEnums),
      numDeclaredEnums(numDeclaredEnums), declaredMembers(declaredMembers),
      numDeclaredMembers(numDeclaredMembers), defaults(defaults), attributes(attributes),
      flags(flags), describedVersion(describedVersion)
{
}
