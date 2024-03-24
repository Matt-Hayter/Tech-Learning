// PL9/smart1.cpp
// Example of use of smart pointers (RAII)
// Niels Walet, last updated 04/12/2019
#include <iostream>
#include <memory>
class my_class 
{ 
public:
  my_class() { std::cout << "my_class c'tor\n"; }
  my_class(const my_class&) { std::cout << "my_class copy c'tor\n"; }
  my_class(my_class&&) { std::cout << "my_class move c'tor\n"; }
  ~my_class() { std::cout << "~my_class d'tor\n"; }
};
class deleter 
{
public:
  deleter() {};
  deleter(const deleter&) { std::cout << "deleter copy ctor\n"; }
  deleter(deleter&) { std::cout << "deleter non-const copy ctor\n";}
  deleter(deleter&&) { std::cout << "deleter move ctor \n"; }
  void operator()(my_class* p) const {
    std::cout << "deleter is deleting a my_class\n";
    delete p;
  };
};
  
int main()
{
  std::cout << "Example constructor(1)...\n";
  std::unique_ptr<my_class> up1;  // up1 is empty
  std::unique_ptr<my_class> up1b(nullptr);  // up1b is empty
  std::cout << "Example constructor(2)...\n";
  {
    std::unique_ptr<my_class> up2(new my_class); //up2 now owns a my_class
  } // my_class deleted as it goes out of scope 
  std::cout << "Example constructor(3)...\n";
  deleter d;
  {  // deleter type is not a reference
    std::unique_ptr<my_class, deleter> up3(new my_class, d); // deleter copied
  }
  {  // deleter type is a reference 
    std::unique_ptr<my_class, deleter&> up3b(new my_class, d); // up3b holds a reference to d
  }
  // Move semantics using 
  std::cout << "Example constructor(4)...\n";
  {  // deleter is not a reference 
    std::unique_ptr<my_class, deleter> up4(new my_class, deleter()); // deleter moved
  }
  // Have to both move object and move ownership of unique_ptr
  std::cout << "Example constructor(5)...\n";
  {
    std::unique_ptr<my_class> up5a(new my_class);
    std::unique_ptr<my_class> up5b(std::move(up5a)); // ownership transfer
  }
  std::cout << "Example constructor(6)...\n";
  {
    std::unique_ptr<my_class, deleter> up6a(new my_class, d); // deleter is copied
    std::unique_ptr<my_class, deleter> up6b(std::move(up6a)); // deleter is moved
  
    std::unique_ptr<my_class, deleter&> up6c(new my_class, d); // deleter is a reference
    std::unique_ptr<my_class, deleter> up6d(std::move(up6c)); // deleter is copied
  }
  std::cout << "Example constructor(7)...\n";
  {
    std::unique_ptr<my_class> up7a(new my_class);
    std::unique_ptr<my_class> up7b(std::move(up7a)); // ownership transfer
  }
}

//Note: variables are deleted when they go out of scope whereas pointers are not (unless told to).
//      Therefore, it's best to use unique pointers if using pointers.
 