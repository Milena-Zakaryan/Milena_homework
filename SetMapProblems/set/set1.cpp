#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
int main()
{
// 1set Вам дан список из n целых чисел, ваша задача — посчитать количество различных значений в списке.

	std::set<int> st;
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		std::cin >> x;
		st.insert(x);
	}
	std::cout << st.size();
return 0;
}