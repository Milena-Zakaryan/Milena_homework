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
// 2set Вам даны строка jewels, представляющие типы камней, которые являются драгоценными камнями,
//и stones, представляющие те камни, которые у вас есть. Каждый символ в stones — это камень, который у вас есть.
//Вы хотите знать, сколько камней у вас также являются драгоценностями.
//Буквы чувствительны к регистру, поэтому "а" считается другим типом камня, чем "А".

	std::set<char> stt;
	std::string jewels;
	std::string stones;
	std::cin >> jewels;
	std::cin >> stones;

	for(int i = 0; i < jewels.size(); i++)
	{
			stt.insert(jewels[i]);	
	}
	int count = 0;
	for(int i = 0; i < stones.size(); i++)
	{
		if(stt.find(stones[i]) != stt.end())
		{
			count++;
		}	
	}
	std::cout << count;

return 0;
}