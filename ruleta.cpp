#include "ruleta.h"
#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include <windows.h>
#include <algorithm>
#include <conio.h>

ruleta::ruleta(){

    SetConsoleTitle("Ruleta");
}

int ruleta::play(){

    char key;

    //Inicio del juego
    do{

        string bet, colorNumber;
        int betNumber, number, sumBet;
        srand(time(0));

        cout << "Enter the amount of money to bet: $";
        cin >> money;

        validateMoney(money);

        system("cls");

        do{
            cout << "Choose the kind of bet" << endl;
            cout << "   / --|-------------------------------------------------------------------| \n"
                    "  /    | 3 | 6 | 9 | 12 | 15 | 18 | 21 | 24 | 27 | 30 | 33 | 36 | Column 3 | \n"
                    " /     |----------------|-------------------|-------------------|----------| \n"
                    "|   0  | 2 | 5 | 8 | 11 | 14 | 17 | 20 | 23 | 26 | 29 | 32 | 35 | Column 2 | \n"
                    " \\     |----------------|-------------------|-------------------|----------| \n"
                    "  \\    | 1 | 4 | 7 | 10 | 13 | 16 | 19 | 22 | 25 | 28 | 31 | 34 | Column 1 | \n"
                    "   \\___|----------------|-------------------|-------------------|----------| \n"
                    "       |     1st 12     |       2nd 12      |      3rd 12       | \n"
                    "       |--------------------------------------------------------| \n"
                    "       |  1-18  |  Even |   Red   |  Black  |  Odd  |   19-36   | \n"
                    "       |________|_______|_________|_________|_______|___________|" << endl;
            cout << "\n1.One number \n2.Column 3 \n3.Column 2 \n4.Column 1 \n5.1st 12 \n6.2nd 12 \n7.3rd 12 \n8.Number from 1 to 18 \n9.Even \n10.Red \n11.Black \n12.Odd \n13.Number from 19 to 36" << endl << endl;

            cin >> bet;

            transform(bet.begin(), bet.end(), bet.begin(),[](unsigned char c) { return tolower(c); }); // Convierte el string a minusculas

            system("CLS");

            //one single number
            if(bet == "number" || bet == "1"){

                const int MAX_NUM_BET = 36;
                const int MIN_NUM_BET = 0;

                do{

                    cout << "Enter your bet number" << endl;
                    cin >> betNumber;

                    if(betNumber > MAX_NUM_BET){

                        cout << betNumber << " is bigger than 36, not a valid number\n" << endl;
                    }

                    else if(betNumber < MIN_NUM_BET){

                        cout << betNumber << " is less than 0, not a valid number\n" << endl;
                    }

                    while(cin.fail() || cin.peek() != '\n') {

                        system("cls");
                        cout << "Enter a valid number: ";
                        cin.clear();
                        cin.ignore(256,'\n');
                        cin >> betNumber;
                    }
                }while(betNumber > MAX_NUM_BET || betNumber < MIN_NUM_BET);

                system("CLS");
                chooseRandomNumber(number);

                if(number == betNumber){

                    sumBet = 36;
                    playerWins(number, sumBet, red, black, money, colorNumber);
                }

                else {

                    playerLoses(number, red, black, money, colorNumber);
                }

                chooseColor(betNumber, red, black, colorNumber);
                cout << "\n\nYour bet: " << betNumber << " " << colorNumber << endl;
                break;
            }

            //3rd column
            else if(bet == "3rd column" || bet == "third column" || bet == "column 3" || bet == "2"){

                chooseRandomNumber(number);

                if(number % 3 == 0 && number != 0){

                    sumBet = 3;
                    playerWins(number, sumBet, red, black, money, colorNumber);
                }
                else{

                    playerLoses(number, red, black, money, colorNumber);
                }

                cout << "\n\nYour bet was for the third column" << endl;
                break;
            }

            //2nd column
            else if(bet == "2nd column" || bet == "second column" || bet == "column 2" || bet == "3"){

                chooseRandomNumber(number);

                if((number-1) % 3 == 0 && number != 0){

                    sumBet = 3;
                    playerWins(number, sumBet, red, black, money, colorNumber);
                }
                else{

                    playerLoses(number, red, black, money, colorNumber);
                }

                cout << "\n\nYour bet was for the second column" << endl;
                break;
            }

            //1st
            else if(bet == "1st column" || bet == "first column" || bet == "column 1" || bet == "4"){

                chooseRandomNumber(number);

                if((number-2) % 3 == 0 && number != 0){

                    sumBet = 3;
                    playerWins(number, sumBet, red, black, money, colorNumber);
                }
                else{

                    playerLoses(number, red, black, money, colorNumber);
                }

                cout << "\n\nYour bet was for the first column" << endl;
                break;
            }

            //1st 12
            else if(bet == "1st 12" || bet == "first 12" || bet == "5"){

                chooseRandomNumber(number);

                if(number >= 1 && number <= 12){

                    sumBet = 3;
                    playerWins(number, sumBet, red, black, money, colorNumber);
                }
                else{

                    playerLoses(number, red, black, money, colorNumber);
                }

                cout << "\n\nYour bet was for the firt 12" << endl;
                break;
            }

            //2nd 12
            else if(bet == "2nd 12" || bet == "second 12" || bet == "6"){

                chooseRandomNumber(number);

                if(number >= 13 && number <= 24){

                    sumBet = 3;
                    playerWins(number, sumBet, red, black, money, colorNumber);
                }
                else{

                    playerLoses(number, red, black, money, colorNumber);
                }

                cout << "\n\nYour bet was for the second 12" << endl;
                break;
            }

            //3rd 12
            else if(bet == "3rd 12" || bet == "third 12" || bet == "7"){

                chooseRandomNumber(number);

                if(number >= 25 && number <= 36){

                    sumBet = 3;
                    playerWins(number, sumBet, red, black, money, colorNumber);
                }
                else{

                    playerLoses(number, red, black, money, colorNumber);
                }

                cout << "\n\nYour bet was for the third 12" << endl;
                break;
            }

            //1 to 18
            else if(bet == "1 to 18" || bet == "8"){

                chooseRandomNumber(number);

                if(1 <= number && number <= 18){

                    sumBet = 2;
                    playerWins(number, sumBet, red, black, money, colorNumber);
                }

                else{

                    playerLoses(number, red, black, money, colorNumber);
                }

                cout << "\n\nYour bet was for 1 to 18" << endl;
                break;
            }

            //even
            else if(bet == "even" || bet == "9"){

                chooseRandomNumber(number);

                if (number % 2 == 0){

                    sumBet = 2;
                    playerWins(number, sumBet, red, black, money, colorNumber);
                }
                else{

                    playerLoses(number, red, black, money, colorNumber);
                }

                cout << "\n\nYour bet was for the even numbers" << endl;
                break;
            }

            //red
            else if(bet == "reds" || bet == "red" || bet == "10"){

                chooseRandomNumber(number);
                chooseColor(number, red, black, colorNumber);

                if (colorNumber == "red"){

                    sumBet = 2;
                    playerWins(number, sumBet, red, black, money, colorNumber);
                }
                else{

                    playerLoses(number, red, black, money, colorNumber);
                }

                cout << "\n\nYour bet was for red ones" << endl;
                break;
            }

            //black
            else if(bet == "blacks" || bet == "black" || bet == "11"){

                chooseRandomNumber(number);
                chooseColor(number, red, black, colorNumber);

                if (colorNumber == "black"){

                    sumBet = 2;
                    playerWins(number, sumBet, red, black, money, colorNumber);
                }

                else{

                    playerLoses(number, red, black, money, colorNumber);
                }

                cout << "\n\nYour bet was for the black ones" << endl;
                break;
            }

            //odd
            else if(bet == "odd" || bet == "12"){

                chooseRandomNumber(number);

                if (number % 2 != 0){

                    sumBet = 2;
                    playerWins(number, sumBet, red, black, money, colorNumber);
                }
                else{

                    playerLoses(number, red, black, money, colorNumber);
                }

                cout << "\n\nYour bet was for the odd numbers" << endl;
                break;
            }

            //19 to 36
            else if(bet == "19 to 36" || bet == "13"){

                chooseRandomNumber(number);

                if(19 <= number && number <= 36){

                    sumBet = 2;
                    playerWins(number, sumBet, red, black, money, colorNumber);
                }

                else{

                    playerLoses(number, red, black, money, colorNumber);
                }

                cout << "\n\nYour bet was from 19 to 36" << endl;
                break;
            }

            //invalid option
            else{

                cout << bet << " is not a valid option." << endl;
            }
        }
        while(true);

        cout << "\n\nPress E to play again or X to leave" << endl;
        key = getch();

        while(key != 'e' && key != 'x'){

            system("CLS");
            cout << "The entered key is not valid." << endl;
            cout << "Press E to play again or X to leave" << endl;
            key = getch();
        }
        system("CLS");

    }while(key == 'e');

    system("CLS");
    cout << "You leave with $" << money << endl;
    cout << "Thanks for playing!" << endl;
    return 0;
}

void ruleta::chooseRandomNumber(int &number){

     cout <<"Spinning..." << "\n" << endl;

     int max = 50;
     int min = 15;
     int azar = rand()%(max-min + 1) + min;
     int tiempo;
     int temp1 = rand() % 50;
     int temp2 = rand() % 20;

     for(int x = 0; x < azar; x++){

        number = rand() % 37;
        tiempo = temp1 + temp2 * x;
        this_thread::sleep_for (chrono::milliseconds(tiempo));
        cout << number << "\r";
     }

    system("CLS");
}
//Choose color according to the number
void ruleta::chooseColor(int number, int red[], int black[], string &color){

    if(number == 0){

        color = "green";
    }

    for(int i = 0; i < 19; i++){

        if(number == red[i]){

            color = "red";
        }

        else if(number == black[i]){

            color = "black";
        }
    }
}

void ruleta::playerWins(int number,  int sumBet, int red[], int black[], int& money, string& colorNumber){

    cout << "Winner!" << endl;
    chooseColor(number, red, black, colorNumber);
    cout << "\nlucky number: " << number << " " << colorNumber << endl;

    money = money * sumBet;

    cout << "\nNow you have $" << money;
}

void ruleta::playerLoses(int number, int red[], int black[], int& money, string& colorNumber){

    cout << "Loserrr!!" << endl;
    chooseColor(number, red, black, colorNumber);
    cout << "\nlucky number: " << number << " " << colorNumber << endl;

    money = 0;

    cout << "\nNow you have $" << money;
}

void ruleta::validateMoney(int& money){

    system("cls");
    cout << "Enter a valid amount of money\n" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cout << "$";
    cin >> money;
}
