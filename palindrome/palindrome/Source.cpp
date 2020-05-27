#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str) {
	for (int i = 0; i < str.size() / 2; i++) {
		if (tolower(str[i]) != tolower(str[str.size() - 1 - i])) return false;
	}
	return true;
}

int main() {
	string str = "Level";
	std::cout << "\"" << str << "\" is " << (isPalindrome(str) ? "palindrome" : "not palindrome.") << std::endl;
}