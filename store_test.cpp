/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include "Store.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  cout << "End testStore1" << endl;
}

void testStore2() {
  cout << "Start testStore2" << endl;
  cout << "End testStore2" << endl;
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

// Modified testAll to accept optional filenames
void testAll(const string &moviesFile = "data4movies.txt",
             const string &commandsFile = "data4commands.txt") {
  Store store;
  store.loadCustomers("data4customers.txt");
  store.loadInventory(moviesFile);
  store.processCommands(commandsFile);
}
