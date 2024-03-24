#ifndef MY_CLASS_H // Will only be true the once!
#define MY_CLASS_H
 
//.h file used for class definition

namespace my_ns1
{
  class myclass
  {
  private:
    int x;
  public:
    myclass() : x(0) {} 
    myclass(int xx) : x(xx) {}
    ~myclass(){}
    // Prototypes
    void show();
  };
}
#endif
 