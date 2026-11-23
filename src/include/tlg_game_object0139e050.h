/* src/include/tlg_game_object0139e050.h: a blob of a file's bytes (derived
 * name, from its creator's message "CreateBlob: Error. Cannot open file
 * %s.", 0xb9886a), the class over Object0130acb0 whose vtable is at 0x16d0180
 * (config/vtables.derived.base.txt). Its destructor (leaf_0139e050.cpp) is
 * the key function. */
#ifndef TLG_GAME_OBJECT0139E050_H
#define TLG_GAME_OBJECT0139E050_H

#include "tlg_types.h"

#include "tlg_game_object0130acb0.h"

class Object0139e050 : public Object0130acb0 /* derived name */
{
  public:
    /* kind 6 (CreateBlob, 0xb98790) */
    Object0139e050() : Object0130acb0(6) {}

    virtual ~Object0139e050();

    void *data; /* +0x30 (derived name): malloc'd, freed with free */
    u64 size;   /* +0x38 (derived name): cleared with it */
};

#endif
