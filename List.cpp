#include <iostream>
#include <fstream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

int main (int argc, char** argv) {
  if (argc != 3) {
    cout << "Usage: list [filename] [threshold]" << endl;
  } else {
    cout << "filename: " << argv[1] << endl;
    cout << "threshold: " << argv[2] << endl;
    cout << atoi(argv[1]) + atoi(argv[2]) << endl;

    string line;

    ifstream file(argv[1]);
    if (file.is_open()) {
      while(file.good()) {
        getline(file, line);
        cout << line << endl;
      }
    }
  }

  return 0;
}
