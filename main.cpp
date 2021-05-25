#include <iostream>
#include <time.h>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
using namespace std;

void NUMBER (int);
void SELECT_NUMBER(int);

int main()
{
    SetConsoleTitle("Roulette");
    string bet;
    int BetNumber;
    int number = rand() % 37;

    cout << "How do you want to bet?" << endl;
    cout << "\nOdds \nEven \nRed \nBlack \nSingle number \nNumber from 1 - 18 \nNumber from 19 - 36\n" << endl;

    bet:
    cin >> bet;
    srand(time(0));

    single:
    if(bet == "single" || bet == "Single"){

    cout << "Enter a number to make a bet" << endl;
    cin >> BetNumber;
    if(BetNumber > 37){
        cout << "That is not a valid number" << endl;
        goto single;
    }

    SELECT_NUMBER(number);

    int number = rand() % 37;
    if(number == BetNumber){

        cout << "\nYou win!" << endl;
        cout << "The number was ";
        NUMBER(number);

  }
    else if(number != BetNumber){

        cout << "\nYou lose!" << endl;
        cout << "The number was ";
        NUMBER(number);
     }
  }

    if(bet == "odds" || bet == "odd" || bet == "Odds" || bet == "Odd"){

        SELECT_NUMBER(number);

        if (number % 2 != 0){

            cout << "\nWinner!" << endl;
            cout << "The number was ";
            NUMBER(number);
        }
        else{

            cout << "\nLoserrr!!" << endl;
            cout << "The number was ";
            NUMBER(number);
        }
  }
     if(bet == "evens" || bet == "even" || bet == "Evens" || bet == "Even"){

       SELECT_NUMBER(number);

        if (number % 2 == 0){

            cout << "\nWinner!" << endl;
            cout << "The number was ";
            NUMBER(number);
        }
        else{

            cout << "\nloserrr!!" << endl;
            cout << "The number was ";
            NUMBER(number);
        }
  }
     if(bet == "red"){

        SELECT_NUMBER(number);

        if (number % 2 == 0  && ((11 < number && number < 19) || (29 < number && number < 37)))
        {
            cout << "\nWinner!!" <<endl;
            cout << "The number was ";
            NUMBER(number);
        }
        else if (number % 2 != 0 && ((0 < number && number < 10) || (18 < number && number < 28))){

            cout << "\nWinner!!" <<endl;
            cout << "The number was ";
            NUMBER(number);
        }
        else{

           cout << "\nYou loseee" << endl;
           cout << "The number was ";
           NUMBER(number);
        }
  }
     if(bet == "black" || bet == "blacks" || bet == "Black" || bet == "Blacks"){

        SELECT_NUMBER(number);

       if (number % 2 == 0 && ((0 < number && number < 11) || (19 < number && number < 29)))
        {
            cout << "\nwinner winner" << endl;
            cout << "the number was ";
            NUMBER(number);
     }
       else if(number % 2 != 0 && ((10 < number && number < 18) || (28 < number && number < 36)))
        {
           cout << "\nwinner winner" << endl;
            cout << "the number was ";
            NUMBER(number);
        }
      else{

        cout << "\nyou loseee" << endl;
           cout << "the number was ";
           NUMBER(number);
        }
  }

    if(bet == "1-18" || bet == "number from 1 - 18" || bet == "1to18" || bet == "number from 1 to 18"){

        SELECT_NUMBER(number);

        if(0 < number && number < 19){

            cout << "\nyou win!" << endl;
            cout << "the number was ";
            NUMBER(number);
        }
      else{

            cout << "\nyou lose!" << endl;
            cout << "the number was ";
            NUMBER(number);
        }
  }
    if(bet == "19-36" || bet == "number from 19 - 36" || bet == "19to36" || bet == "number from 19 to 36"){

        SELECT_NUMBER(number);

        if(18 < number && number < 37){

            cout << "\nyou win!" << endl;
            cout << "the number was ";
            NUMBER(number);
        }
        else{

            cout << "\nyou lose!" << endl;
            cout << "the number was ";
            NUMBER(number);
        }
    }
    else{

        cout << "\ni don't know what you said, try again" << endl;
        goto bet;
    }
}

//choose color according to the number
void NUMBER(int number){

 if(number == 0)
{
    cout << number << " green" << endl; //GREEN
}

        else if (number % 2 == 0 && ((0 < number && number < 11) || (19 < number && number < 29))) //even blacks (1 -> 10 & 20 -> 28)
        {
            cout << number << " black" << endl;

        }

        else if (number % 2 == 0 && ((11 < number && number < 19) || (29 < number && number < 37))) //even reds (12 -> 18 & 30 -> 36)
        {
            cout << number << " red" << endl;
        }

        else if (number % 2 != 0 && ((0 < number && number < 10) || (18 < number && number < 28))) //odd reds (1 -> 9 & 19 -> 27)
        {
            cout << number << " red" << endl;
        }

        else if (number % 2 != 0 && ((10 < number && number < 18) || (28 < number && number < 36))) //odd blacks (11 -> 17 & 29 -> 35)
        {
            cout << number << " black" << endl;
        }

        else
        {
            cout << number << "what the fuck error???" << endl; //error?
        }
}

//select random number
void SELECT_NUMBER(int number){

     number = rand() % 37;
     cout <<"spinning..." << endl;
     this_thread::sleep_for (chrono::seconds(2));
}
