#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::size_t n;

    std::cin >> n;

    std::vector<int> nums(n);

    std::ranges::for_each(nums, [](int& val) { std::cin >> val; });

    std::ranges::sort(nums);

    std::ranges::for_each(nums | std::views::filter([](const int val) {return val % 2 == 0;}), [](const int val) { std::cout << val << '\n';});
    std::ranges::for_each(nums | std::views::filter([](const int val) {return val % 2 == 1;}) | std::views::reverse, [](const int val) { std::cout << val << '\n'; });

    return 0;
}