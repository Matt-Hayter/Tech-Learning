#include <iostream >
using namespace std;
void double_value (double& reference )
{
    reference *=2;
}
int main ()
{
    double number {4.};
    std ::cout <<number <<std :: endl;
    double_value (number);
    std ::cout <<number <<std :: endl;
    return 0;
}