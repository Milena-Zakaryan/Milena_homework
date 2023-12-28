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
// 3set Дана строка s, найдите длину самой длинной подстроки без повторяющихся символов. Решить задачу за O(N*log(N)).

	 std::string s;
	 std::cin >> s;

	 int right = 0;
	 int left = 0;
	 int max = 0;
	 int dlina = 0;
	 std::set<char> st;
	  while(right<s.size())
	  {
		if(dlina>max)
		 max = dlina;
		if(st.find(s[right])!=st.end())
		{
		  st.erase(s[left]);
		  ++left;
		  dlina = 0;
		}
		else{
		  st.insert(s[right]);
		  ++right;
		  ++dlina;
		}
	  }
		if(dlina>max)
		 max = dlina;

	  std::cout << max << std::endl;

return 0;
}