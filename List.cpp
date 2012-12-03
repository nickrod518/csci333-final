#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::map;
using std::pair;

int main (int argc, char** argv) {
  if (argc != 3) {
    cout << "Usage: list [filename] [threshold]" << endl;
  } else {
    cout << "filename: " << argv[1] << endl;
    cout << "threshold: " << argv[2] << endl;
   
    map<string, int> list;
    map<string, int>::iterator it;
    string line;

    ifstream file(argv[1]);
    if (file.is_open()) {
      while(file.good()) {
        getline(file, line);
        
        if (list.count(line))
          list[line]++;
        else
          list.insert(pair<string, int>(line, 1));
      }
    }

    cout << "NAME" << "\t: " << "OCCURRENCES" << endl;
    for (it = list.begin(); it != list.end(); ++it) {
      if ((*it).second >= atoi(argv[2]))
        cout << (*it).first << " \t: " << (*it).second << endl;
    }
  }

  return 0;
}
