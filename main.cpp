#include <iostream>
#include <time.h>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
#include <conio.h>
using namespace std;

void CHOOSE_RANDOM_NUMBER(int&);
void RANDOM_NUMBER(int&, int&);
void CONTINUE();

int main()
{
    do{
        SetConsoleTitle("Roulette");
        string bet;
        int color = 0;
        string colorNumber;
        int BetNumber;
        srand(time(0));
        int random;

        cout << "How do you want to make a bet?" << endl;
        cout << "\nOdds \nEven \nRed \nBlack \nSingle number \nNumber from 1 - 18 \nNumber from 19 - 36\n" << endl;

        cin >> bet;
        system("CLS");

        single:
        if(bet == "single" || bet == "Single" || bet == "number" || bet == "Number"){

            cout << "Type in the number to make a bet" << endl;
            cin >> BetNumber;

            if(BetNumber > 37){
                cout << "\nNot a valid number\n" << endl;
                goto solo;
            }

            CHOOSE_RANDOM_NUMBER(random);

            if(random == BetNumber){

                cout << "Winner!" << endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }

            else {

                cout << "You lost!" << endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }

            if(color == 0) {

                colorNumber = "black";
            }

            else{

                colorNumber = "red";
            }

            cout << "\n\nYour bet: " << BetNumber << " " << colorNumber;
        }

        if(bet == "odds" || bet == "odd" || bet == "Odd" || bet == "Odds"){

            CHOOSE_RANDOM_NUMBER(random);

            if (random % 2 != 0){

                cout << "Winner!" << endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }

            else{

                cout << "\nLoserrrrrrrr!!" << endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }
        }

        if(bet == "evens" || bet == "even" || bet == "Evens" || bet == "Even"){

        CHOOSE_RANDOM_NUMBER(random);

            if (random % 2 == 0){

                cout << "Winner!" << endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }

            else{

                cout << "Loserr!!" << endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }
        }

        if(bet == "red" || bet == "reds" || bet == "Red" || bet == "Reds"){

            CHOOSE_RANDOM_NUMBER(random);

            if (random % 2 == 0  && ((11 < random && random < 19) || (29 < random && random < 37))){

                cout << "\nWinner!!" <<endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }

            else if (random % 2 != 0 && ((0 < random && random < 10) || (18 < random && random < 28))){

                cout << "Winner!!" <<endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }

            else{

                cout << "You looost" << endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }
        }

        if(bet == "black" || bet == "blacks" || bet == "Black" || bet == "Blacks"){

            CHOOSE_RANDOM_NUMBER(random);

            if (random % 2 == 0 && ((0 < random && random < 11) || (19 < random && random < 29))){

                cout << "Winner winner" << endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }

            else if(random % 2 != 0 && ((10 < random && random < 18) || (28 < random && random < 36))){

                cout << "And we have a winner!" << endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }

            else{

                cout << "You looost" << endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }
        }

        if(bet == "1-18" || bet == "number from 1 - 18" || bet == "1to18" || bet == "Number from 1 to 18"){

            CHOOSE_RANDOM_NUMBER(random);

            if(0 < random && random < 19){

                cout << "Winner!" << endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }

            else{

                cout << "Loser!" << endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }
        }

        if(bet == "19-36" || bet == "number from 19 - 36" || bet == "19to36" || bet == "number from 19 to 36"){

            CHOOSE_RANDOM_NUMBER(random);

            if(18 < random && random < 37){

                cout << "You win!" << endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }

            else{

                cout << "You lose!" << endl;
                cout << "\nWinner number: "; RANDOM_NUMBER(random, color);
            }
        }

        if(bet != "number" || bet != "Number" || bet != "single" || bet != "Single"){
 
            cout << "\n\nYour bet: " << bet << endl;
        }

        CONTINUE();
        system("CLS");

    }while(1==1);
}

//choose color according to number
void RANDOM_NUMBER(int &number, int &id){

    if(number == 0){

        cout << number << " green" << endl; //GREEN
    }

    else if (number % 2 == 0 && ((0 < number && number < 11) || (19 < number && number < 29))){ //even blacks (1 -> 10 & 20 -> 28)

        cout << number << " black" << endl;
        id = 0;
    }

    else if (number % 2 == 0 && ((11 < number && number < 19) || (29 < number && number < 37))){ //even reds (12 -> 18 & 30 -> 36)

        cout << number << " red" << endl;
        id = 1;
    }

    else if (number % 2 != 0 && ((0 < number && number < 10) || (18 < number && number < 28))){ //odd reds (1 -> 9 & 19 -> 27)

        cout << number << " red" << endl;
        id = 1;
    }

    else if (number % 2 != 0 && ((10 < number && number < 18) || (28 < number && number < 36))){ //odd blacks (11 -> 17 & 29 -> 35)

        cout << number << " black" << endl;
        id = 0;
    }

    else{

        cout << number << "ERROR???" << endl; //error?
    }
}

//choose random number
void CHOOSE_RANDOM_NUMBER(int &number){

     cout <<"Spinning..." << "\n" << endl;

     for(int x = 0; x < 8; x++){

        number = rand() % 37;
        this_thread::sleep_for (chrono::milliseconds(500));
        cout << number << "\r";
     }

    system("CLS");
}

void CONTINUE(){

    int c;
    printf( "\n\n\n\nPress any key to play again");
    c = getch();
    if (c == 0 || c == 224) getch();
}
