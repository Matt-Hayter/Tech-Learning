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
//std::lexicographical_compare(beg_a, end_a, beg_b, end_b)
//beg_a, end_a are the inital and final position of the first seqence.
//beg-b, end_b are that of the second.
//True if first range is lexicographically less than the other.

struct substring_compare
{
    std::size_t from;
    std::size_t len;

    substring_compare(std::size_t from, std::size_t len)
    : from(from), len(len) {}

    bool operator()(std::string const& a, std::string const& b)
    {
        // sanity checks
        assert(from + len <= a.size());
        assert(from + len <= b.size());

        auto beg_a = std::begin(a) + from;
        auto end_a = beg_a + len;

        auto beg_b = std::begin(b) + from;
        auto end_b = beg_a + len;

        return std::lexicographical_compare(beg_a, end_a, beg_b, end_b);
    }
};

int main()
{
    std::vector<std::string> v
    {
        "12345 QWERTY",
        "23456 ASDFGH",
        "34567 ZXCVBN",
        "23425 sincoo",
        "24232 ksbfkf",
    };

    // start at position 0, comparing 5 characters
    std::sort(std::begin(v), std::end(v), substring_compare(0, 5)); //Arguements are from, len here.

    std::cout << "By first column" << '\n';
    for(auto const& i: v) // just prints here, ordered by number.
        std::cout << i << '\n';

    // start at position 6, comparing 6 characters
    std::sort(std::begin(v), std::end(v), substring_compare(6, 6));

    std::cout << "By second column" << '\n';
    for(auto const& i: v)
        std::cout << i << '\n';
}