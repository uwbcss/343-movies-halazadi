# Self-Evaluation

## Name(s): Hassanain Al-Azadi & Hasn Al-Shamkhawi

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes/No

- Yes -0

Q: All public functions have been implemented: ENTER_NUMBER

- All public functions for Store, Movie types, Inventory, Customer, Factory, and Command classes are fully implemented. -0

Inventory: Full – Correctly lists inventory, sorted by genre rules

History: Full – Shows customer history including multiple transactions

Borrow: Full – Borrow logic works including invalid cases

Return: Full – Return logic handles stock update and invalid cases


Q: -1 for each compilation warning, min -3: ENTER_NUMBER

- No warnings -0

Q: -1 for each clang-tidy warning, min -3: ENTER_NUMBER

- No warnings -0

Q: -1 for each clang-format warning, min -3: ENTER_NUMBER

- No warnings -0


Q: -2 for any detected memory leak: ENTER_NUMBER

- No leaks -0

Q: Do the tests sufficiently test the code: ENTER_NUMBER

- All major functions are exercised by sample data and command files -0

Q: Are all functions in .h and .cpp file documents (min -3): ENTER_NUMBER

- Yes all functions documented -0

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: Store::processCommandLine (Store.cpp)

invalid movie type: MovieFactory::createMovie (MovieFactory.cpp)

invalid customer ID: Command::execute (inside Borrow.cpp / Return.cpp)

invalid movie: Inventory::getMovie and Borrow::execute

factory classes: CommandFactory, MovieFactory

hashtable: std::unordered_map<int, Customer*> customers in Store,
std::unordered_map<char, std::unordered_map<std::string, Movie*>> in Inventory

container used for comedy movies: std::unordered_map<std::string, Movie*>

function for sorting comedy movies: Lambda inside Inventory::printInventory()

function where comedy movies are sorted: Inventory::printInventory()

functions called when retrieving a comedy movie based on title and year:
Movie::getKey, Inventory::getMovie

functions called for retrieving and printing customer history:
Customer::getHistory, Customer::printHistory, History::execute

container used for customer history: std::vector<Transaction*> history

functions called when borrowing a movie:
Borrow::execute, Inventory::getMovie, Customer::addTransaction

explain borrowing a movie that does not exist:
Inventory::getMovie returns nullptr → Borrow displays invalid movie key

explain borrowing a movie that has 0 stock:
Borrow::execute checks Movie::borrowMovie() which returns false → error shown

explain returning a movie that customer has not checked out:
Customer::hasBorrowed(movie) check fails → Return::execute displays error

any static_cast or dynamic_cast used:
dynamic_cast is used in sorting classics in Inventory.cpp

## Bonus +5

Are there multiple files, of the form runit-without-XXX, where the same set of files will compile and run excluding some of the commands or genres? TODO(student)

Yes +5
runit-without-classic.txt → no Classic commands
runit-without-return.txt → no Return commands 
data4movies-without-classic.txt → a version of the movie list with all C, lines removed!

(Run it using data4movies-without-classic.txt and runit-without-classic.txt to verify 'no-Classic' compatibility.)


Q: Total points: ADD_ALL_POINTS (max 25 (+ 5 Bonus))

TOTAL: (30/25)