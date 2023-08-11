//This coad is made by shrikant as a project 1
#include <iostream>
using namespace std;

    char num[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    string p1, p2;
    int choice,row,column;
    char turn = 'X';
    bool draw = false;
  
class Tic {
public:
    

    void display_board() 
    {

      system("cls");

   cout<<"   \n             |      |     \n";
   cout<<"         "<< num[0][0]    <<"   |   "<< num[0][1]    <<"  |  "<< num[0][2]  <<"\n";
   cout<<"        _____|______|_____\n";
   cout<<"             |      |     \n";
   cout<<"         "<< num[1][0]    <<"   |   "<< num[1][1]   <<"  |  "<< num[1][2]  <<"\n";
   cout<<"        _____|______|_____\n";
   cout<<"             |      |     \n";
   cout<<"         "<< num[2][0]   <<"   |   "<< num[2][1]    <<"  |  "<< num[2][2]  <<"\n";
   cout<<"             |      |     \n\n";
   cout << endl;
    }

    void player_turn() {
        if (turn == 'X') {
            cout << p1 << " your [X] TURN : ";
        } else if (turn == 'O') {
            cout << p2 << " your [O] TURN : ";
        }

        cin >> choice;

        switch (choice) {
        case 1: num[0][0] = turn; break;
        case 2: num[0][1] = turn; break;
        case 3: num[0][2] = turn; break;
        case 4: num[1][0] = turn; break;
        case 5: num[1][1] = turn; break;
        case 6: num[1][2] = turn; break;
        case 7: num[2][0] = turn; break;
        case 8: num[2][1] = turn; break;
        case 9: num[2][2] = turn; break;
        default:
            cout << "Invalid choice..🎃" << endl;
            player_turn();
            return;
        }

         if (turn == 'X' && (num[row][column] != 'X' || num[row][column] != 'O')) {
        num[row][column] = turn;
         turn = 'O';
    }
    else if (turn == 'O' && (num[row][column] != 'X' || num[row][column] != 'O')) {
        num[row][column] = turn;
          turn = 'X';
    }
    else {
        cout << "BOX ALREADYY FILLED...!!\n PLEASE TRYY AGAIN" << endl;
        player_turn();
    }
        
    }

    bool gameover() {
        // check win
        for (int i = 0; i < 3; i++) {
            if ((num[i][0] == num[i][1] && num[i][0] == num[i][2]) || 
                (num[0][i] == num[1][i] && num[0][i] == num[2][i])) {
                return false;
            }
        }
        
        if ((num[0][0] == num[1][1] && num[0][0] == num[2][2]) || 
            (num[0][2] == num[1][1] && num[0][2] == num[2][0])) {
            return false;
        }

        //game playing
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (num[i][j] != 'X' && num[i][j] != 'O') {
                    return true;
                }
            }
        }

        //game draw
        draw = true;
        return false;
    }
};

int main() {
    cout << "    WELCOME TO TIC TAC TOE GAME \n\n";
    cout << "PLAYER A [X]" << "\nPLAYER B [O]\n\n";

    Tic access;

    cout << "Enter player 1 name: ";
    cin >> p1;
    cout << "Enter player 2 name: ";
    cin >> p2;

    while (access.gameover()) {
        access.display_board();
        access.player_turn();
    }

    access.display_board();

    if (turn == 'X' && draw == false) {
        cout << p2 << " YOU WIN \a🎆🎉✨🎊 " << endl;
    } else if (turn == 'O' && draw == false) {
        cout << p1 << " YOU WIN \a🎆🎉✨🎊 " << endl;
    } else {
        cout << "GAME DRAW!!\a 🤩 " << endl;
    }

    return 0 ;
}
