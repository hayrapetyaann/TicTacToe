#include <iostream>

void drawingToBoard(char* places);
void movePlayer1(char* places, char player1);
void movePlayer2(char* places, char player1);
bool winner(char* places, char player1, char player2);
bool checkTie(char* places);

int main() {
    char places[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player1 = 'X';
    char player2 = 'O';
    bool running = true;

    drawingToBoard(places);

    while (running) {
        movePlayer1(places, player1);
        drawingToBoard(places);

        if(winner(places, player1, player2)) {
            running = false;
            break;
        } else if (checkTie(places)) {
            running = false;
            break;
        }

        movePlayer2(places, player2);
        drawingToBoard(places);

        if (winner(places, player1, player2)) {
            running = false;
            break;
        } else if (checkTie(places)) {
            running = false;
            break;
        }
    }


    std::cout << "Thank you.\n";
    return 0;
}

void drawingToBoard(char* places) {
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << places[0] << "  |  " << places[1] << "  |  " << places[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << places[3] << "  |  " << places[4] << "  |  " << places[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << places[6] << "  |  " << places[7] << "  |  " << places[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

void movePlayer1(char* places, char player1) {
    int num = 0;
    do {
        std::cout << "Player1 (X), enter number one to nine: ";
        std::cin >> num;
        if (num >= 0 && num <= 9) {
            --num;
            if (places[num] == ' ') {
                places[num] = player1;
                break;
            }
        } else {
            std::cout << "Enter valid number for game. " << std::endl;
            return;
        }
    } while(!num > 0  || !num < 8);
}

void movePlayer2(char* places, char player2) {
    int num = 0;
    do {
        std::cout << "Player2 (O), enter number one to nine: ";
        std::cin >> num;
        if (num >= 0 && num <= 9) {
            --num;
            if (places[num] == ' ') {
                places[num] = player2;
                break;
            }
        } else {
            std::cout << "Enter valid number for game. " << std::endl;
            return;
        }
    } while(!num > 0  || !num < 8);
}

bool winner(char* places, char player1, char player2) {
    if((places[0] != ' ') && (places[0] == places[1]) && (places[1] == places[2])){
        places[0] == player1 ? std::cout << "Player1 is winner!\n" : std::cout << "Player2 is winner!\n";
    }
    else if((places[3] != ' ') && (places[3] == places[4]) && (places[4] == places[5])){
        places[3] == player1 ? std::cout << "Player1 is winner!\n" : std::cout << "Player2 is winner!\n";
    }
    else if((places[6] != ' ') && (places[6] == places[7]) && (places[7] == places[8])){
        places[6] == player1 ? std::cout << "Player1 is winner!\n" : std::cout << "Player2 is winner!\n";
    }
    else if((places[0] != ' ') && (places[0] == places[3]) && (places[3] == places[6])){
        places[0] == player1 ? std::cout << "Player1 is winner!\n" : std::cout << "Player2 is winner!\n";
    }
    else if((places[1] != ' ') && (places[1] == places[4]) && (places[4] == places[7])){
        places[1] == player1 ? std::cout << "Player1 is winner!\n" : std::cout << "Player2 is winner!\n";
    }
    else if((places[2] != ' ') && (places[2] == places[5]) && (places[5] == places[8])){
        places[2] == player1 ? std::cout << "Player1 is winner!\n" : std::cout << "Player2 is winner!\n";
    }
    else if((places[0] != ' ') && (places[0] == places[4]) && (places[4] == places[8])){
        places[0] == player1 ? std::cout << "Player1 is winner!\n" : std::cout << "Player2 is winner!\n";
    }
    else if((places[2] != ' ') && (places[2] == places[4]) && (places[4] == places[6])){
        places[2] == player1 ? std::cout << "Player1 is winner!\n" : std::cout << "Player2 is winner!\n";
    } else {
        return false;
    }

    return true;
}

bool checkTie(char* places) {
    for (int i = 0; i < 9; ++i) {
        if(places[i] == ' ') {
            return false;
        }
    }

    std::cout << "It is tie..." << std::endl;
    return true;
}
