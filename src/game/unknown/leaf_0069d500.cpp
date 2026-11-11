/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16ac620 (stored by FUN_0069cb70 FUN_0069d390 FUN_0069d3d0): slot 5 the
 * complete destructor, slot 6 the deleting one (operator delete of the
 * object). A callable holder: slots 0 and 1 copy what it holds at +0x8 (into a
 * new block when given none), slot 7 returns its address. */
class Object0069d500 /* derived name */
{
  public:
    virtual Object0069d500 *FUN_0069d390(void *where); /* derived name */
    virtual Object0069d500 *FUN_0069d3d0(void *where); /* derived name */
    virtual void FUN_0069d410(void *argument);         /* derived name */
    virtual const void *FUN_0069d4c0();                /* derived name */
    virtual void FUN_0069d4d0(bool deallocate);        /* derived name */
    virtual ~Object0069d500();
    virtual void *FUN_0069d520(); /* derived name */

  private:
    char stored; /* +0x8, 1 byte copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object0069d500::FUN_0069d4d0(bool deallocate)
{
    this->~Object0069d500();
    if (deallocate)
        operator delete(this);
}

Object0069d500::~Object0069d500() {}

void *Object0069d500::FUN_0069d520()
{
    return &stored;
}
