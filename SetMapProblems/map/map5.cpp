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
//map5 Дана строка s, отсортируйте ее в порядке убывания частоты встречаемости символов. Частота символа — это количество раз, которое он появляется в строке. Вернуть отсортированную строку. Если ответов несколько, верните любой из них.
	std::string s;
	std::cin >> s;
	std::map<char,int> mp;

	for(char x:s)
	{
		++mp[x];
	}
	std::vector<std::pair<char,int>> vec;
	
	for(auto it:mp)
	{
		vec.push_back(std::make_pair(it.first, it.second));
	}

	std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) 
	{
			return a.second > b.second;
	});

	for(auto it:vec)
	{
		std::cout << std::string(it.second,it.first);
	}


return 0;
}