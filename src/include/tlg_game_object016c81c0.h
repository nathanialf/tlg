/* src/include/tlg_game_object016c81c0.h: the class whose vtable is at 0x16c81c0
 * (game region; docs/TARGETS.md) and the classes its creators build on it.
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C81C0_H
#define TLG_GAME_OBJECT016C81C0_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16c81c0
 * (config/vtables.derived.base.txt, stored by its constructor 0xd68470 and
 * its destructor 0xd687e0), derived from Object016b9108 (0xd68470 first
 * calls that class's constructor 0xcb6310). 0x98 bytes: each creator below
 * allocates 0x98 (`mov edi, 0x98` before operator new) and its derived
 * class stores only its vptr. The constructor takes, after the name, a
 * colour (ARGB: 0xff87ceeb, 0xff1e90ff), a group (0 to 0x13) and an id
 * (290 up, one per class); it passes the name on to 0xcb6310 and its body
 * does not read the other three. Neither function is written; the fields
 * from +0x24 are not traced. */
class Object016c81c0 : public Object016b9108 /* derived name */
{
  public:
    /* 0xd68470, its row named after it (D15) */
    Object016c81c0(const Name &name, u32 colour, int group, int id);
    virtual ~Object016c81c0(); /* 0xd687e0 */

  private:
    u8 unknown24[0x74];
};

/* derived names: the classes on Object016c81c0 that its creators build, each
 * named by its vtable (config/vtables.base.txt). None has members of its own: the
 * creator stores only the class's vptr after the base's constructor. The
 * three constants each passes are the creator's (`mov edx`, `mov ecx`,
 * `mov r8d` before the call to 0xd68470). */

class Object016c5de8 : public Object016c81c0 /* derived name */
{
  public:
    Object016c5de8(const Name &name) : Object016c81c0(name, 0xffff0000, 8, 290) {}

    virtual ~Object016c5de8();
};

class Object016c5e30 : public Object016c81c0 /* derived name */
{
  public:
    Object016c5e30(const Name &name) : Object016c81c0(name, 0xffffb010, 8, 291) {}

    virtual ~Object016c5e30();
};

class Object016c5e78 : public Object016c81c0 /* derived name */
{
  public:
    Object016c5e78(const Name &name) : Object016c81c0(name, 0xffffb010, 8, 292) {}

    virtual ~Object016c5e78();
};

class Object016c5ec0 : public Object016c81c0 /* derived name */
{
  public:
    Object016c5ec0(const Name &name) : Object016c81c0(name, 0xffffb010, 8, 293) {}

    virtual ~Object016c5ec0();
};

class Object016c5f08 : public Object016c81c0 /* derived name */
{
  public:
    Object016c5f08(const Name &name) : Object016c81c0(name, 0xffffb010, 8, 294) {}

    virtual ~Object016c5f08();
};

class Object016c5f50 : public Object016c81c0 /* derived name */
{
  public:
    Object016c5f50(const Name &name) : Object016c81c0(name, 0xffffb010, 8, 295) {}

    virtual ~Object016c5f50();
};

class Object016c5f98 : public Object016c81c0 /* derived name */
{
  public:
    Object016c5f98(const Name &name) : Object016c81c0(name, 0xff808000, 13, 296) {}

    virtual ~Object016c5f98();
};

class Object016c5fe0 : public Object016c81c0 /* derived name */
{
  public:
    Object016c5fe0(const Name &name) : Object016c81c0(name, 0xff808000, 13, 297) {}

    virtual ~Object016c5fe0();
};

class Object016c6028 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6028(const Name &name) : Object016c81c0(name, 0xff808000, 13, 298) {}

    virtual ~Object016c6028();
};

class Object016c6070 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6070(const Name &name) : Object016c81c0(name, 0xff808000, 13, 299) {}

    virtual ~Object016c6070();
};

class Object016c60b8 : public Object016c81c0 /* derived name */
{
  public:
    Object016c60b8(const Name &name) : Object016c81c0(name, 0xff808000, 13, 300) {}

    virtual ~Object016c60b8();
};

class Object016c6100 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6100(const Name &name) : Object016c81c0(name, 0xff808000, 13, 301) {}

    virtual ~Object016c6100();
};

class Object016c6148 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6148(const Name &name) : Object016c81c0(name, 0xffd2691e, 13, 302) {}

    virtual ~Object016c6148();
};

class Object016c6190 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6190(const Name &name) : Object016c81c0(name, 0xffd2691e, 13, 303) {}

    virtual ~Object016c6190();
};

class Object016c61d8 : public Object016c81c0 /* derived name */
{
  public:
    Object016c61d8(const Name &name) : Object016c81c0(name, 0xffc0c0c0, 0, 304) {}

    virtual ~Object016c61d8();
};

class Object016c6220 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6220(const Name &name) : Object016c81c0(name, 0xff87cefa, 0, 305) {}

    virtual ~Object016c6220();
};

class Object016c6268 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6268(const Name &name) : Object016c81c0(name, 0xff00ff00, 16, 306) {}

    virtual ~Object016c6268();
};

class Object016c62b0 : public Object016c81c0 /* derived name */
{
  public:
    Object016c62b0(const Name &name) : Object016c81c0(name, 0xff00ff00, 16, 307) {}

    virtual ~Object016c62b0();
};

class Object016c62f8 : public Object016c81c0 /* derived name */
{
  public:
    Object016c62f8(const Name &name) : Object016c81c0(name, 0xff00ff00, 16, 308) {}

    virtual ~Object016c62f8();
};

class Object016c6340 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6340(const Name &name) : Object016c81c0(name, 0xff00ff00, 16, 309) {}

    virtual ~Object016c6340();
};

class Object016c6388 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6388(const Name &name) : Object016c81c0(name, 0xff00ff00, 16, 310) {}

    virtual ~Object016c6388();
};

class Object016c63d0 : public Object016c81c0 /* derived name */
{
  public:
    Object016c63d0(const Name &name) : Object016c81c0(name, 0xff00ff00, 16, 311) {}

    virtual ~Object016c63d0();
};

class Object016c6418 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6418(const Name &name) : Object016c81c0(name, 0xff774444, 0, 312) {}

    virtual ~Object016c6418();
};

class Object016c6460 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6460(const Name &name) : Object016c81c0(name, 0xff774477, 0, 313) {}

    virtual ~Object016c6460();
};

class Object016c64a8 : public Object016c81c0 /* derived name */
{
  public:
    Object016c64a8(const Name &name) : Object016c81c0(name, 0xff774477, 0, 314) {}

    virtual ~Object016c64a8();
};

class Object016c64f0 : public Object016c81c0 /* derived name */
{
  public:
    Object016c64f0(const Name &name) : Object016c81c0(name, 0xff774477, 0, 315) {}

    virtual ~Object016c64f0();
};

class Object016c6538 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6538(const Name &name) : Object016c81c0(name, 0xff774477, 0, 316) {}

    virtual ~Object016c6538();
};

class Object016c6580 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6580(const Name &name) : Object016c81c0(name, 0xff774477, 17, 317) {}

    virtual ~Object016c6580();
};

class Object016c65c8 : public Object016c81c0 /* derived name */
{
  public:
    Object016c65c8(const Name &name) : Object016c81c0(name, 0xff77aa77, 17, 318) {}

    virtual ~Object016c65c8();
};

class Object016c6610 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6610(const Name &name) : Object016c81c0(name, 0xff774477, 17, 319) {}

    virtual ~Object016c6610();
};

class Object016c6658 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6658(const Name &name) : Object016c81c0(name, 0xff774477, 17, 320) {}

    virtual ~Object016c6658();
};

class Object016c66a0 : public Object016c81c0 /* derived name */
{
  public:
    Object016c66a0(const Name &name) : Object016c81c0(name, 0xff774477, 17, 321) {}

    virtual ~Object016c66a0();
};

class Object016c66e8 : public Object016c81c0 /* derived name */
{
  public:
    Object016c66e8(const Name &name) : Object016c81c0(name, 0xff774422, 0, 326) {}

    virtual ~Object016c66e8();
};

class Object016c6730 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6730(const Name &name) : Object016c81c0(name, 0xff774422, 0, 327) {}

    virtual ~Object016c6730();
};

class Object016c6778 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6778(const Name &name) : Object016c81c0(name, 0xff774422, 0, 328) {}

    virtual ~Object016c6778();
};

class Object016c67c0 : public Object016c81c0 /* derived name */
{
  public:
    Object016c67c0(const Name &name) : Object016c81c0(name, 0xfff433ff, 12, 329) {}

    virtual ~Object016c67c0();
};

class Object016c6808 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6808(const Name &name) : Object016c81c0(name, 0xfff433ff, 12, 330) {}

    virtual ~Object016c6808();
};

class Object016c6850 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6850(const Name &name) : Object016c81c0(name, 0xffffff00, 0, 331) {}

    virtual ~Object016c6850();
};

class Object016c6898 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6898(const Name &name) : Object016c81c0(name, 0xffff4500, 0, 332) {}

    virtual ~Object016c6898();
};

class Object016c68e0 : public Object016c81c0 /* derived name */
{
  public:
    Object016c68e0(const Name &name) : Object016c81c0(name, 0xffadd8e6, 0, 333) {}

    virtual ~Object016c68e0();
};

class Object016c6928 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6928(const Name &name) : Object016c81c0(name, 0xff87ceeb, 0, 334) {}

    virtual ~Object016c6928();
};

class Object016c6970 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6970(const Name &name) : Object016c81c0(name, 0xff1e90ff, 0, 335) {}

    virtual ~Object016c6970();
};

class Object016c69b8 : public Object016c81c0 /* derived name */
{
  public:
    Object016c69b8(const Name &name) : Object016c81c0(name, 0xffffff00, 0, 336) {}

    virtual ~Object016c69b8();
};

class Object016c6a00 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6a00(const Name &name) : Object016c81c0(name, 0xff902020, 0, 340) {}

    virtual ~Object016c6a00();
};

class Object016c6a48 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6a48(const Name &name) : Object016c81c0(name, 0xff902020, 0, 342) {}

    virtual ~Object016c6a48();
};

class Object016c6a90 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6a90(const Name &name) : Object016c81c0(name, 0xff902020, 0, 343) {}

    virtual ~Object016c6a90();
};

class Object016c6ad8 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6ad8(const Name &name) : Object016c81c0(name, 0xff404040, 0, 345) {}

    virtual ~Object016c6ad8();
};

class Object016c6b20 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6b20(const Name &name) : Object016c81c0(name, 0xff404040, 0, 346) {}

    virtual ~Object016c6b20();
};

class Object016c6b68 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6b68(const Name &name) : Object016c81c0(name, 0xff774444, 0, 349) {}

    virtual ~Object016c6b68();
};

class Object016c6bb0 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6bb0(const Name &name) : Object016c81c0(name, 0xff774444, 0, 350) {}

    virtual ~Object016c6bb0();
};

class Object016c6bf8 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6bf8(const Name &name) : Object016c81c0(name, 0xff0000ff, 10, 352) {}

    virtual ~Object016c6bf8();
};

class Object016c6c40 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6c40(const Name &name) : Object016c81c0(name, 0xff0000ff, 10, 353) {}

    virtual ~Object016c6c40();
};

class Object016c6c88 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6c88(const Name &name) : Object016c81c0(name, 0xff00ffff, 0, 355) {}

    virtual ~Object016c6c88();
};

class Object016c6cd0 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6cd0(const Name &name) : Object016c81c0(name, 0xffffb010, 1, 357) {}

    virtual ~Object016c6cd0();
};

class Object016c6d18 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6d18(const Name &name) : Object016c81c0(name, 0xffffb010, 1, 359) {}

    virtual ~Object016c6d18();
};

class Object016c6d60 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6d60(const Name &name) : Object016c81c0(name, 0xffffb010, 1, 361) {}

    virtual ~Object016c6d60();
};

class Object016c6da8 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6da8(const Name &name) : Object016c81c0(name, 0xfff0e68c, 1, 362) {}

    virtual ~Object016c6da8();
};

class Object016c6df0 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6df0(const Name &name) : Object016c81c0(name, 0xfff0e68c, 1, 363) {}

    virtual ~Object016c6df0();
};

class Object016c6e38 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6e38(const Name &name) : Object016c81c0(name, 0xff00ff00, 0, 364) {}

    virtual ~Object016c6e38();
};

class Object016c6e80 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6e80(const Name &name) : Object016c81c0(name, 0xffffffff, 12, 366) {}

    virtual ~Object016c6e80();
};

class Object016c6ec8 : public Object016c81c0 /* derived name */
{
  public:
    Object016c6ec8(const Name &name) : Object016c81c0(name, 0xff808000, 13, 368) {}

    virtual ~Object016c6ec8();
};

#endif
