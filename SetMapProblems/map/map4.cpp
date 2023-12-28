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

bool wordPattern(const std::string& pattern, const std::string& s) {
	std::unordered_map<char, std::string> charToWord;
	std::unordered_map<std::string, char> wordToChar;

	std::vector<std::string> words;
	size_t start = 0, end = 0;
	while (end < s.size()) {
		while (end < s.size() && s[end] != ' ') {
			++end;
		}
		words.push_back(s.substr(start, end - start));
		start = ++end;
	}

	if (pattern.size() != words.size()) {
		return false;
	}

	for (size_t i = 0; i < pattern.size(); ++i) {
		char c = pattern[i];
		const std::string& word = words[i];

		if (charToWord.find(c) == charToWord.end() && wordToChar.find(word) == wordToChar.end()) {
			charToWord[c] = word;
			wordToChar[word] = c;
		} else {
			if (charToWord[c] != word || wordToChar[word] != c) {
				return false;
			}
		}
	}

	return true;
}

int main()
{
//map4  Задан шаблон и строка s. Найдите, соответствует ли s тому же шаблону. Здесь соответствует означает полное совпадение, такое, что существует биекция между буквой в образце и непустым словом в s. Решить задачу за O(N*log(N)).

		std::string pattern = "abba";
		std::string s = "dog cat cat dog";

		if (wordPattern(pattern, s)) {
			std::cout << "true\n";
		} else {
			std::cout << "false\n";
		}

return 0;
}