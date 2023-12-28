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
//  map1 Дана строка s, найдите в ней первый неповторяющийся символ и верните его индекс. 
//Если он не существует, верните -1. Решить задачу за O(N*log(N)).

	std::map<char, int> mp;
	std::string s;
	std::cin >> s;
	for(int i = 0; i < s.size(); i++){
		mp[s[i]]++;
	}
	bool f = false;
	for(int i = 0; i <s.size(); i++){
		if(mp[s[i]] == 1){
			std::cout << i;
			f = true;
			break;
		}
	}
	if(f == false){
		std::cout << -1;
	}

return 0;
}