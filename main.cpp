#include <iostream>
#include <time.h>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

void NUMBER (int);

int main()
{
    string bet;
    int BetNumber;
    cout << "how do you want to bet" << endl;
    cout << " odds \n even \n red \n black \n single number \n number from 1 - 18 \n number from 19 - 36" << endl;
    cin >> bet;

    single:
    if(bet == "single"){

    cout << "enter a nummber to make a bet" << endl;
    cin >> BetNumber;
    if(BetNumber > 37){
        cout << "that is not a valid number" << endl;
        goto single;
    }

    srand(time(0));

    cout <<"spinning..." << endl;
    this_thread::sleep_for (chrono::seconds(2));

        int number = rand() % 37;
        if(number == BetNumber){

            cout << "\nyou win!" << endl;
            cout << "the number was ";
            NUMBER(number);

        }
        else if(number != BetNumber){

            cout << "\nyou lose!" << endl;
            cout << "the number was ";
            NUMBER(number);
        }
    }

     if(bet == "odds" || bet == "odd"){

        srand(time(0));
        cout <<"spinning..." << endl;
    this_thread::sleep_for (chrono::seconds(2));
        int number = rand() % 37;

        if (number % 2 != 0){

            cout << "\nwinner!" << endl;
            cout << "the number was ";
            NUMBER(number);
        }
        else{

            cout << "\nloserrr!!" << endl;
            cout << "the number was ";
            NUMBER(number);
        }
     }
     if(bet == "evens" || bet == "even"){

        srand(time(0));
        cout <<"spinning..." << endl;
    this_thread::sleep_for (chrono::seconds(2));
        int number = rand() % 37;

        if (number % 2 == 0){

            cout << "\nwinner!" << endl;
            cout << "the number was ";
            NUMBER(number);
        }
        else{

            cout << "\nloserrr!!" << endl;
            cout << "the number was ";
            NUMBER(number);
        }
     }
     if(bet == "red"){

        srand(time(0));
        cout <<"spinning..." << endl;
    this_thread::sleep_for (chrono::seconds(2));
        int number = rand() % 37;

        if (number % 2 == 0  && ((11 < number && number < 19) || (29 < number && number < 37)))
        {
            cout << "\nwinner!!" <<endl;
            cout << "the number was ";
            NUMBER(number);
        }
        else if (number % 2 != 0 && ((0 < number && number < 10) || (18 < number && number < 28))){

            cout << "\nwinner!!" <<endl;
            cout << "the number was ";
            NUMBER(number);
        }
        else{

           cout << "\nyou loseee" << endl;
           cout << "the number was ";
           NUMBER(number);
        }
     }
     if(bet == "black"){

        srand(time(0));
        cout <<"spinning..." << endl;
    this_thread::sleep_for (chrono::seconds(2));
        int number = rand() % 37;

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

        srand(time(0));
        cout <<"spinning..." << endl;
    this_thread::sleep_for (chrono::seconds(2));
        int number = rand() % 37;

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

        srand(time(0));
        cout <<"spinning..." << endl;
    this_thread::sleep_for (chrono::seconds(2));
        int number = rand() % 37;

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

}

void NUMBER(int number){
 if(number == 0)
        {
            cout << number << " green" << endl;
        }

        /*even blacks (1 -> 10 & 20 -> 28)*/
        else if (number % 2 == 0 && ((0 < number && number < 11) || (19 < number && number < 29)))
        {
            cout << number << " black" << endl;

        }

        /*even reds (12 -> 18 & 30 -> 36)*/
        else if (number % 2 == 0 && ((11 < number && number < 19) || (29 < number && number < 37)))
        {
            cout << number << " red" << endl;
        }

        /*odd reds (1 -> 9 & 19 -> 27)*/
        else if (number % 2 != 0 && ((0 < number && number < 10) || (18 < number && number < 28)))
        {
            cout << number << " red" << endl;
        }

        /*odd blacks (11 -> 17 & 29 -> 35)*/
        else if (number % 2 != 0 && ((10 < number && number < 18) || (28 < number && number < 36)))
        {
            cout << number << " black" << endl;
        }

        /*error?*/
        else
        {
            cout << number << "what the fuck error???" << endl;
        }
}

