#include <iostream>
#include <string>
using namespace std;

class ruleta{

    public:
        ruleta();
        int play();
        void chooseRandomNumber(int &number);
        void chooseColor(int number, int red[], int black[], string &color);
        void playerWins(int number,  int sumBet, int red[], int black[], int& money, string& colorNumber);
        void playerLoses(int number, int red[], int black[], int& money, string& colorNumber);
        void validateMoney(int& money);

    private:
        int money;
        int red[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
        int black[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
};
