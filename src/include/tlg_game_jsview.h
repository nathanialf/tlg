/* src/include/tlg_game_jsview.h: the render's view of a resource
 * (render/ps4/JsView.cpp, as its destructor's report names the file). The
 * class name is that report's ("~JsView", 0x15cf11d), the field's name its
 * condition; its vtable is the row _ZTV6JsView (0x16cab98,
 * config/vtables.derived.base.txt). */
#ifndef TLG_GAME_JSVIEW_H
#define TLG_GAME_JSVIEW_H

#include "tlg_types.h"

#include "tlg_game_object0130acb0.h"

/* The view's source file, as the reports name it (0x15cf0e7). */
#define JS_VIEW_CPP /* derived name */                                                             \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4\\JsView.cpp"

class JsView : public Object0130acb0
{
  public:
    /* slots 0 and 1 (0x1326b10, 0x1326c10) */
    virtual ~JsView();

  private:
    u8 unknown10[0x20];
    JsUnknown *m_pResource; /* +0x30: the viewed resource, a reference held */
};

#endif
