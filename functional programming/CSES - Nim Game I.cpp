#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::size_t tests;

    std::cin >> tests;

    for(std::size_t i = 0; i < tests; ++i) {
        std::size_t n;

        std::cin >> n;

        std::vector<int> x(n);

        for(int& value : x)
            std::cin >> value;

        int result = std::reduce(x.begin(), x.end(), 0, [](int a, int b) { return a ^ b; });

        if(result) std::cout << "first\n";
        else std::cout << "second\n";
    }

    return 0;
}