#ifndef TWO_NUM_H // Will only be true the once!
#define TWO_NUM_H
// Class template
namespace two_num
{
  //Class template
  template <class T> class twonum {
  private:
    T x,y;
  public:
    twonum() : x(0),y(0) {};
    twonum(T xx, T yy) : x(xx),y(yy) {};
    T add();
    T sub();
  };
}
using namespace two_num;

//Function definitions inside header files ONLY when using templates and code splitting.
//For friend functions (eg. when using << and >>) more code needed, see week 9 prelec.
//Two member function templates defined here.
template<class T> T twonum<T>::add() {return x+y;};
template<class T> T twonum<T>::sub() {return x-y;};
#endif
 