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


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	std::vector<int> findFrequentTreeSum(TreeNode* root) {
		std::unordered_map<int, int> sumFrequency;
		int maxFrequency = 0;

		calculateSubtreeSum(root, sumFrequency, maxFrequency);

		std::vector<int> result;
		for (const auto& entry : sumFrequency) {
			if (entry.second == maxFrequency) {
				result.push_back(entry.first);
			}
		}

		return result;
	}

private:
	int calculateSubtreeSum(TreeNode* root, std::unordered_map<int, int>& sumFrequency, int& maxFrequency) {
		if (!root) {
			return 0;
		}

		int leftSum = calculateSubtreeSum(root->left, sumFrequency, maxFrequency);
		int rightSum = calculateSubtreeSum(root->right, sumFrequency, maxFrequency);

		int subtreeSum = root->val + leftSum + rightSum;
		sumFrequency[subtreeSum]++;
		maxFrequency = std::max(maxFrequency, sumFrequency[subtreeSum]);

		return subtreeSum;
	}
};

int main()
{
//map7 Дан корень двоичного дерева, верните наиболее часто встречающуюся сумму поддерева. Если таких сумм несколько, верните все значения с наибольшей частотой в любом порядке.Сумма поддерева узла определяется как сумма всех значений узлов, образованных поддеревом, корнем которого является этот узел (включая сам узел). Алгоритм должен работать как можно оптимально.
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(2);
	root->right = new TreeNode(-3);

	Solution solution;
	std::vector<int> result = solution.findFrequentTreeSum(root);

	std::cout << "Most frequent subtree sums: ";
	for (int value : result) {
		std::cout << value << " ";
	}
	std::cout << std::endl;

return 0;
}