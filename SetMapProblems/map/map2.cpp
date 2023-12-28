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
// map2 Имея строку s, состоящая из строчных или прописных букв, верните длину самого длинного палиндрома, который можно построить из этих букв. Буквы чувствительны к регистру, например, "Аа" здесь не считается палиндромом. Решить задачу за O(N*log(N)).

	std::map<char, int> mp;
	std::string s;
	std::cin >> s;
	for (char x : s) {
		++mp[x];
	}
    int count = 0;
	bool odd = false;
	for(auto it : mp){
	 count += (it.second / 2) * 2;
	 if (it.second % 2 == 1) 
		 odd = true;	 		
	}
	if(odd)
	 count++;
	std::cout << count;

return 0;
}