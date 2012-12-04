#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::map;
using std::pair;

int main (int argc, char** argv) {
  if (argc != 3) {
    cout << "Usage: list [in file] [out file]" << endl;
  } else {
    cout << "in file: " << argv[1] << endl;
    cout << "out file: " << argv[2] << endl;
   
    map<string, int> words;
    map<int, string> sortedWords;
    map<string, int>::iterator it;
    map<int, string>::iterator it2;
    string word;
    ifstream ifile(argv[1]);
    ofstream ofile(argv[2]);

    // store words in dictionary
    if (ifile.is_open()) {
      while(ifile.good()) {
        getline(ifile, word, ' ');
        
        if (words.count(word))
          words[word]++;
        else
          words.insert(pair<string, int>(word, 1));
      }
    }

    // move words to another dictionary sorted by occurrences
    for (it = words.begin(); it != words.end(); ++it) {
      cout << (*it).first << endl;
      sortedWords.insert(pair<int, string>((*it).second, (*it).first));
    }

    // move words to file in order of occurrences
    if (ofile.is_open()) {
      while(ofile.good()) {
        for (it2 = sortedWords.begin(); it2 != sortedWords.end(); ++it2)
          ofile << (*it2).second << " : " << (*it2).first << endl;
        ofile.close();
      }
    }
  }

  return 0;
}
