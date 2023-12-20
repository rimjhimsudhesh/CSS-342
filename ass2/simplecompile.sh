echo "**********************"
echo "COMPILING THE PROGRAM"
echo "**********************"
clang++ -std=c++14 -Wall -Wextra *.cpp -o ass2

echo "**********************"
echo "CLANG TIDY CHECKING"
echo "**********************"
clang-tidy *.cpp -- -std=c++14

echo "**********************"
echo "RUNNING THE PROGRAM"
echo "**********************"
./ass2