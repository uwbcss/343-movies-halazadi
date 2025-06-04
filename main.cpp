#include <iostream>
#include <string>
using namespace std;

// Update to match new version
void testAll(const string &moviesFile = "data4movies.txt",
             const string &commandsFile = "data4commands.txt");

int main(int argc, char *argv[]) {
  if (argc == 3) {
    testAll(argv[1], argv[2]); // Use provided files
  } else {
    testAll(); // Use defaults
  }

  cout << "Done!" << endl;
  return 0;
}
