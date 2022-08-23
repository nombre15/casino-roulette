#include <iostream>
#include <time.h>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
#include <conio.h>
using namespace std;

void CHOOSE_RANDOM_NUMBER(int&);
void CHOOSE_COLOR(int&, string&);
void CONTINUE();

int main(){

    do{
        SetConsoleTitle("Roulette");
        string bet, color, colorNumber;
        int BetNumber;
        srand(time(0));
        int random;

        cout << "How do you want to make a bet?" << endl;
        cout << "\nOdds \nEven \nRed \nBlack \nSingle number \nNumber from 1 - 18 \nNumber from 19 - 36\n" << endl;

        cin >> bet;

        system("CLS");

//single number
        if(bet == "single" || bet == "Single" || bet == "number" || bet == "Number" || bet == "NUMBER" || bet == "SINGLE"){

            single:
            cout << "Type in the number to make a bet" << endl;
            cin >> BetNumber;

            if(BetNumber > 37){
                cout << BetNumber << " is greater than 37, not a valid number\n" << endl;
                goto single;
            }

            system("CLS");

            CHOOSE_RANDOM_NUMBER(random);

            if(random == BetNumber){

                cout << "Winner!" << endl;
                cout << "\nWinner number: "; CHOOSE_COLOR(random, color);
            }

            else {

                cout << "You lost!" << endl;
                cout << "\nWinner number: "; CHOOSE_COLOR(random, color);
            }

            cout << "\n\nYour bet: "; CHOOSE_COLOR(BetNumber, color);
        }
//end single number

//odds
        if(bet == "odds" || bet == "odd" || bet == "Odd" || bet == "Odds" || bet == "ODD" || bet == "ODDS"){

            CHOOSE_RANDOM_NUMBER(random);

            if (random % 2 != 0){

                cout << "Winner!" << endl;
                cout << "\nWinner number: "; CHOOSE_COLOR(random, color);
            }

            else{

                cout << "\nLoserrrrrrrr!!" << endl;
                cout << "\nWinner number: "; CHOOSE_COLOR(random, color);
            }

            cout << "\n\nYour bet: Odds" << endl;
        }
//end odds

//evens
        if(bet == "evens" || bet == "even" || bet == "Evens" || bet == "Even" || bet == "EVEN" || bet == "EVENS"){

            CHOOSE_RANDOM_NUMBER(random);

            if (random % 2 == 0){

                cout << "Winner!" << endl;
                cout << "\nWinner number: "; CHOOSE_COLOR(random, color);
            }

            else{

                cout << "Loserr!!" << endl;
                cout << "\nWinner number: "; CHOOSE_COLOR(random, color);
            }

            cout << "\n\nYour bet: Evens" << endl;
        }
//end evens

//reds
        if(bet == "red" || bet == "reds" || bet == "Red" || bet == "Reds" || bet == "RED" || bet == "REDS"){

            CHOOSE_RANDOM_NUMBER(random);
            CHOOSE_COLOR(random, color);
            system("CLS");

            if (color == "red"){

                cout << "\nWinner!!" <<endl;
                cout << "\nWinner number: "; CHOOSE_COLOR(random, color);
            }

            else{

                cout << "You looost" << endl;
                cout << "\nWinner number: "; CHOOSE_COLOR(random, color);
            }

            cout << "\n\nYour bet: Reds" << endl;
        }
//end reds

//blacks
        if(bet == "black" || bet == "blacks" || bet == "Black" || bet == "Blacks" || bet == "BLACKS" || bet == "BLACK"){

            CHOOSE_RANDOM_NUMBER(random);
            CHOOSE_COLOR(random, color);
            system("CLS");

            if (color == "black"){

                cout << "Winner winner" << endl;
                cout << "\nWinner number: "; CHOOSE_COLOR(random, color);
            }

            else{

                cout << "You looost" << endl;
                cout << "\nWinner number: "; CHOOSE_COLOR(random, color);
            }

            cout << "\n\nYour bet: Blacks" << endl;
        }
//end blacks

//1-18
        if(bet == "1-18" || bet == "number from 1 - 18" || bet == "1to18" || bet == "Number from 1 to 18"){

            CHOOSE_RANDOM_NUMBER(random);

            if(0 < random && random < 19){

                cout << "Winner!" << endl;
                cout << "\nWinner number: "; CHOOSE_COLOR(random, color);
            }

            else{

                cout << "Loser!" << endl;
                cout << "\nWinner number: "; CHOOSE_COLOR(random, color);
            }

            cout << "\n\nYour bet: 1-18" << endl;
        }
//end 1-18

//19-36
        if(bet == "19-36" || bet == "number from 19 - 36" || bet == "19to36" || bet == "number from 19 to 36"){

            CHOOSE_RANDOM_NUMBER(random);

            if(18 < random && random < 37){

                cout << "You win!" << endl;
                cout << "\nWinner number: "; CHOOSE_COLOR(random, color);
            }

            else{

                cout << "You lose!" << endl;
                cout << "\nWinner number: "; CHOOSE_COLOR(random, color);
            }

            cout << "\n\nYour bet: 19-36" << endl;
        }
//end 19-36

//single number
        else if(stoi(bet) >= 0 && stoi(bet) < 38){

            CHOOSE_RANDOM_NUMBER(random);
            BetNumber = stoi(bet);

            if(BetNumber == random){

                cout << "Winner winner!" << endl;
                cout << "\nLucky number: "; CHOOSE_COLOR(random, color);
            }

            else{

                cout << "Loser!" << endl;
                cout << "\nLucky number: "; CHOOSE_COLOR(random, color);
            }

            cout << "\n\nYour bet: "; CHOOSE_COLOR(BetNumber, color);
        }
//end single number

//exception
        else if(stoi(bet) > 37){

            cout << stoi(bet) << " is greater than 37, not a valid number\n" << endl;
            goto single;
        }
//fin exception

        CONTINUE();
        system("CLS");

    }while(1==1);
}

//choose color according to number
void CHOOSE_COLOR(int &number, string &id){

    if(number == 0){

        cout << number << " green" << endl; //GREEN
        id = "green";
    }

    else if (number % 2 == 0 && ((1 <= number && number <= 10) || (20 <= number && number <= 28))){ //even blacks (1 -> 10 & 20 -> 28)

        cout << number << " black" << endl;
        id = "black";
    }

    else if (number % 2 == 0 && ((12 <= number && number <= 18) || (30 <= number && number <= 36))){ //even reds (12 -> 18 & 30 -> 36)

        cout << number << " red" << endl;
        id = "red";
    }

    else if (number % 2 != 0 && ((1 <= number && number <= 9) || (19 <= number && number <= 27))){ //odd reds (1 -> 9 & 19 -> 27)

        cout << number << " red" << endl;
        id = "red";
    }

    else if (number % 2 != 0 && ((11 <= number && number <= 17) || (29 <= number && number <= 35))){ //odd blacks (11 -> 17 & 29 -> 35)

        cout << number << " black" << endl;
        id = "black";
    }

    else{

        cout << number << "ERROR???" << endl; //error?
    }
}
//end choose color according to number

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
//end choose random number

//play again
void CONTINUE(){

    int c;
    printf( "\n\n\n\nPress any key to play again");
    c = getch();
    if (c == 0 || c == 224) getch();
}
//end play again
