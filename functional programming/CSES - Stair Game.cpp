#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::size_t tests;

    std::cin >> tests;

    auto nim = [](int n) -> bool {
        std::vector<int> x(n);
        std::iota(x.begin(), x.end(), 0);
        std::for_each(x.begin(), x.end(), [](int& elem) { 
            int input;
            std::cin >> input;
            elem = -(elem & 1) & input;
        });
        int result = std::reduce(x.begin(), x.end(), 0, [](int a, int b) { return a ^ b; });
        return result;
    };

    for(std::size_t i = 0; i < tests; ++i) {
        std::size_t n;

        std::cin >> n;
    
        if(nim(n)) std::cout << "first\n";
        else std::cout << "second\n";
    }

    return 0;
}