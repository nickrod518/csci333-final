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
  if (argc != 4) {
    cout << "Usage: list [in file] [out file] [computed results]" << endl;
  } else {
    cout << "in file: " << argv[1] << endl;
    cout << "out file: " << argv[2] << endl;
   
    map<string, int> words;
    map<int, string> sortedWords;
    map<string, int>::iterator it;
    map<int, string>::reverse_iterator rit;
    string word;
    int totalWords = 0;
    ifstream ifile(argv[1]);
    ofstream ofile(argv[2]);
    ofstream cfile(argv[3]);

    // store words in dictionary
    if (ifile.is_open()) {
      while(ifile.good()) {
        getline(ifile, word, ' ');

        if (word != "") {
          totalWords++;
          if (words.count(word))
            words[word]++;
          else
            words.insert(pair<string, int>(word, 1));
        }
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
        for (rit = sortedWords.rbegin(); rit != sortedWords.rend(); ++rit)
          ofile << (*rit).second << "\t:\t" << (*rit).first << endl;
        ofile.close();
      }
    }

    // calculate unique words and lexical diversity and store in new file
    if (cfile.is_open()) {
      while(cfile.good()) {
        cfile << "unique words: " << words.size() << endl;
        cfile << "lexical diversity: " << totalWords / words.size() << endl;
        cfile.close();
      }
    }
  }

  return 0;
}
