/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16afaf0 (stored by FUN_008b0e10 FUN_008b0e60): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object008b0fc0 /* derived name */
{
  public:
    virtual Object008b0fc0 *FUN_008b0e10(void *where); /* derived name */
    virtual Object008b0fc0 *FUN_008b0e60(void *where); /* derived name */
    virtual void FUN_008b0eb0(void *argument);         /* derived name */
    virtual const void *FUN_008b0f80();                /* derived name */
    virtual void FUN_008b0f90(bool deallocate);        /* derived name */
    virtual ~Object008b0fc0();
    virtual void *FUN_008b0fe0(); /* derived name */

  private:
    unsigned char stored[32]; /* +0x8, 32 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object008b0fc0::FUN_008b0f90(bool deallocate)
{
    this->~Object008b0fc0();
    if (deallocate)
        operator delete(this);
}

Object008b0fc0::~Object008b0fc0() {}

void *Object008b0fc0::FUN_008b0fe0()
{
    return &stored;
}
