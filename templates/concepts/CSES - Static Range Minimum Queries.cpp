#include <iostream>
#include <vector>
#include <concepts>
#include <algorithm>

template<typename T>
requires std::integral<T>
class SparseTable 
{
public:
	SparseTable(const std::vector<T>& data)
	{
		std::size_t n = data.size();
		std::size_t k = 32 - __builtin_clz(n);

		st = std::vector(k, std::vector<T>(n));

		for(std::size_t i = 0; i < n; ++i)
			st[0][i] = data[i];

		for(std::size_t i = 1; i < k; ++i)
			for(std::size_t j = 0; j + (1 << i) <= n; ++j)
				st[i][j] = std::min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	}

	T query(int l, int r)
	{
		int k = 31 - __builtin_clz(r - l + 1);
		return std::min(st[k][l], st[k][r - (1 << k) + 1]);
	}

private:
	std::vector<std::vector<T>> st;
};

int main() 
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::size_t n, q;

	std::cin >> n >> q;

	std::vector<int> data(n);

	for(int& value : data)
		std::cin >> value;

	SparseTable<int> st(data);

	for(std::size_t i = 0; i < q; ++i)
	{
		int l, r;

		std::cin >> l >> r;

		std::cout << st.query(l - 1, r - 1) << '\n';
	}

	return 0;
}
