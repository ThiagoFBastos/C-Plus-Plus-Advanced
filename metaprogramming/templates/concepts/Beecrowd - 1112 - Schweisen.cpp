#include <iostream>
#include <ranges>
#include <vector>
#include <concepts>
#include <utility>

template<typename T>
requires std::integral<T>
class Fenwick2D
{
public:

    Fenwick2D(std::size_t rows, std::size_t columns):
        bit(rows + 1, std::vector(columns + 1, T {})),
        rows(rows),
        columns(columns)
    {

    }

    void update(int x, int y, T value)
    {
        for(++x; x <= rows; x += x & -x)
        {
            for(int k = y + 1; k <= columns; k += k & -k)
            {
                bit[x][k] += value;
            }
        }
    }

    T query(int x0, int y0, int x1, int y1)
    {
        return query(x1, y1) - query(x1, y0 - 1) - query(x0 - 1, y1) + query(x0 - 1, y0 - 1);
    }

private:
    std::vector<std::vector<T>> bit;
    std::size_t rows, columns;

    T query(int x, int y)
    {
        T answer {};

        for(++x; x > 0; x -= x & -x)
        {
            for(int k = y + 1; k > 0; k -= k & -k)
            {
                answer += bit[x][k];
            }
        }

        return answer;
    }
};

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    while(true)
    {
        std::size_t rows, columns, queries;
        int p;

        std::cin >> rows >> columns >> p;

        if(rows + columns + p == 0)
            break;

        std::cin >> queries;

        Fenwick2D<int> ft(rows, columns);

        for(std::size_t i = 0; i < queries; ++i)
        {
            char type;

            std::cin >> type;

            if(type == 'A')
            {
                int n, x, y;

                std::cin >> n >> x >> y;

                ft.update(x, y, n);
            }
            else
            {
                int x0, y0, x1, y1;

				std::cin >> x0 >> y0 >> x1 >> y1;

				if(x0 > x1) std::swap(x0, x1);
				if(y0 > y1) std::swap(y0, y1);

				std::cout << p * ft.query(x0, y0, x1, y1) << '\n';
            }
        }

        std::cout << '\n';
    }

    return 0;
}