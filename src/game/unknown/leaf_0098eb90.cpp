/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback whose address FUN_0098bd10 takes (lea at
 * 0x98c807), which FUN_0098bd10 also calls directly at 0x98c6e0 and 0x98c90c:
 * it unpacks the arguments a job record holds and passes them, with the
 * record, to FUN_0098ebf0. The record's fields are typed from the registers
 * they are passed in; their meaning is not traced. */
struct Target0098eb90; /* derived name */

struct Job0098eb90 { /* derived name */
    u8 unknown0[0x20];
    void *unknown20;
    void *unknown28;
    void *unknown30;
    void *unknown38;
    int unknown40;
    float unknown44;
    int unknown48;
    int unknown4c;
    float unknown50;
    float unknown54;
    Target0098eb90 *unknown58;
};

void FUN_0098ebf0(Target0098eb90 *target, Job0098eb90 *job, void *a, void *b, void *c, void *d,
                  int e, float f, int g, int h, float i, float j); /* derived name */

void FUN_0098eb90(Job0098eb90 *job) /* derived name */
{
    FUN_0098ebf0(job->unknown58, job, job->unknown20, job->unknown28, job->unknown30,
                 job->unknown38, job->unknown40, job->unknown44, job->unknown48, job->unknown4c,
                 job->unknown50, job->unknown54);
}
