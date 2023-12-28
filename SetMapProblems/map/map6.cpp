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

class Trie {
  class TrieNode {
  public:
	std::map<char, TrieNode *> children;
	bool isEndOfWord;

	TrieNode() {
	  isEndOfWord = false;
	}
  };

  TrieNode *root;

public:
  Trie() {
	root = new TrieNode();
  }

  ~Trie() {}

  void insert(const std::string &word) {
	TrieNode *current = root;
	for (char ch : word) {
	  if (current->children.find(ch) == current->children.end()) {
		current->children[ch] = new TrieNode();
	  }
	  current = current->children[ch];
	}
	current->isEndOfWord = true;
  }

  bool startsWith(const std::string &prefix) {
	TrieNode *current = root;
	for (char ch : prefix) {
	  if (current->children.find(ch) == current->children.end()) 	
		return false;
	
	  current = current->children[ch];
	}
	
	return true;
  }
};

int main()
{
//map6 Вам предоставляется структура данных Trie (реализованая используя std::map), которая поддерживает вставку слов. Ваша задача — написать функцию startWith, которая принимает на вход префикс и проверяет, существует ли в Trie хотя бы одно слово, начинающееся с данного префикса. Функция должна возвращать true, если такое слово существует, в противном случае она должна вернуть false.Например: Предположим, что Trie содержит слова: "Hello", "Hey", "World". Если вы вызываете startWith("He"), функция должна вернуть true, поскольку оба слова "Hello" и "Hey" начинаются с префикса "He".
	 Trie trie;
	   trie.insert("Hello");
	   trie.insert("Hey");
	   trie.insert("World");

	   std::cout << trie.startsWith("Hell") << std::endl;  //  true
	   std::cout << trie.startsWith("abc") << std::endl;   //  false
	   std::cout << trie.startsWith("Wo") << std::endl;    //  true

return 0;
}