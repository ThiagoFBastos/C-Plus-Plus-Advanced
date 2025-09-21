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

    auto nim = [](auto& x) -> bool {
        std::transform(x.begin(), x.end(), x.begin(), [](int x) { return x & 3;});
        int result = std::reduce(x.begin(), x.end(), 0, [](int a, int b) { return a ^ b; });
        return result;
    };

    for(std::size_t i = 0; i < tests; ++i) {
        std::size_t n;

        std::cin >> n;

        std::vector<int> x(n);

        for(int& value : x)
            std::cin >> value;
    
        if(nim(x)) std::cout << "first\n";
        else std::cout << "second\n";
    }

    return 0;
}