/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16c1088 (stored by FUN_01061610 FUN_010640d0 FUN_01064110): slot 5 the
 * complete destructor, slot 6 the deleting one (operator delete of the
 * object). A callable holder: slots 0 and 1 copy what it holds at +0x8 (into a
 * new block when given none), slot 7 returns its address. */
class Object010641e0 /* derived name */
{
  public:
    virtual Object010641e0 *FUN_010640d0(void *where); /* derived name */
    virtual Object010641e0 *FUN_01064110(void *where); /* derived name */
    virtual void FUN_01064150(void *argument);         /* derived name */
    virtual const void *FUN_010641a0();                /* derived name */
    virtual void FUN_010641b0(bool deallocate);        /* derived name */
    virtual ~Object010641e0();
    virtual void *FUN_01064200(); /* derived name */

  private:
    void *stored; /* +0x8, 8 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object010641e0::FUN_010641b0(bool deallocate)
{
    this->~Object010641e0();
    if (deallocate)
        operator delete(this);
}

Object010641e0::~Object010641e0() {}

void *Object010641e0::FUN_01064200()
{
    return &stored;
}
