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

bool containsNearbyDuplicate(std::vector<int>& nums, int k)
{
	std::set<int> numSet;

	for (int i = 0; i < nums.size(); ++i) 
	{

		if (numSet.find(nums[i]) != numSet.end()) 
			return true;


		numSet.insert(nums[i]);

		if (numSet.size() > k) 
			numSet.erase(nums[i - k]);

	}

	return false;
}

int main()
{
//map3 Задан целочисленный массив nums и целое число k, напечатать "true", если в массиве есть два различных индекса i и j, такие что nums[i] == nums[j] и abs(i - j) <= k. Напечатать "false" в противном случае. Решить задачу за O(N*log(N)).

	std::vector<int> nums = {1, 2, 3, 1};
	int k = 3;

	if (containsNearbyDuplicate(nums, k)) 
		std::cout << "true\n";
	 else {
		std::cout << "false\n";
	}
return 0;
}