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
  if (argc != 2) {
    cout << "Usage: list [input file]" << endl;
  } else {
    cout << "input file: " << argv[1] << endl;
   
    map<string, int> words;
    map<int, string> sortedWords;
    map<string, int>::iterator it;
    map<int, string>::reverse_iterator rit;
    string word;
    int totalWords = 0;
    ifstream ifile(argv[1]);
    ofstream ofile("wordsTweeted");
    ofstream rfile("calculatedData");

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
    if (rfile.is_open()) {
      while(rfile.good()) {
        rfile << "unique words: " << words.size() << endl;
        rfile << "lexical diversity: " << totalWords / words.size() << endl;
        rfile.close();
      }
    }
  }

  return 0;
}
