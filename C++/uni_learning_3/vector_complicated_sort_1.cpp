#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include <cstring>
#include <limits>
#include <sstream>
#include <vector>
#include <algorithm>
#include <assert.h>

int main
{
    std::vector<std::string> v
    {
        "12345 QWERTY",
        "23456 ASDFGH",
        "34567 ZXCVBN",
    };

std::sort(std::begin(v), std::end(v), [](std::string const& a, std::string const& b){
    return std::lexicographical_compare(std::begin(a), std::begin(a) + 5, std::begin(b), std::begin(b) + 5);
});

std::cout << "By first column" << '\n';
for(auto const& s: v)
    std::cout << s << '\n';

std::sort(std::begin(v), std::end(v), [](std::string const& a, std::string const& b){
    return std::lexicographical_compare(std::begin(a) + 6, std::end(a), std::begin(b) + 6, std::end(b));
}