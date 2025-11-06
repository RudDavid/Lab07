
#include <iostream>
#include <fstream> 
#include <string> 
#include <cctype>
#include <vector>
#include <map>

using namespace std;


int main() {
  vector<int> counts(26, 0);
  ifstream inputFile("Pupupu.txt");
  if (!inputFile.is_open()) {
    cout << "Error opening file!" << endl;
    return 1;
  }
  string text;
  string line;
  while (getline(inputFile, line)) {
    text += line + " ";
  }
  for (char letter : text){
    letter = tolower(letter);
    if (letter >= 'a' && letter <= 'z') {
      counts[letter - 'a']++;
    }
  }
  map<string, int> pupupu;
  for (size_t indexI = 0; indexI<= text.length() - 2; ++indexI) {
    if (isalpha(text[indexI]) && isalpha(text[indexI + 1])) {
      string pair = text.substr(indexI, 2);
      pupupu[pair]++;
    }
  }
  cout << "Letter combination: \n";
  for (int indexI = 0; indexI< 26; ++indexI) {
    if (counts[indexI] > 0) {
      cout << "'" << static_cast<char>('a' + indexI) << "': " << counts[indexI] << endl;
    }
  }
  cout << "\n"
    << "Two-letter combinations: \n";
  for (const auto& pair : pupupu) {
    cout << "'" << pair.first << "': " << pair.second << endl;
  }
}

