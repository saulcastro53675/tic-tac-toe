#include <iostream>
#include <string>
//#include "src/tictactoe.hpp"
using namespace std;
char spaces['3']['3'] = {
  {' ',' ',' '},
  {' ',' ',' '},
  {' ',' ',' '}
};
char player1 = 'X';
char player2 = 'O';
char playing = player1;
inline int r = -1;
inline int c = -1;
string cont;
char winner = ' ';
int main() {
  cout << "Welcome to Tic-Tac-Toe!" << endl;
  for (int i = 0; i < 9; i++) {
    cout << " " << spaces[0][0] << " | " << spaces[0][1] << " | " << spaces[0][2] << endl;
    cout << "___+___+___" << endl;
    cout << " " << spaces[1][0] << " | " << spaces[1][1] << " | " << spaces[1][2] << endl;
    cout << "___+___+___" << endl;
    cout << " " << spaces[2][0] << " | " << spaces[2][1] << " | " << spaces[2][2] << endl;
    cout << "It is " << playing << " turn" << endl;
    cout << "Enter a row a column, 0-2" << endl;
    while (true) {
      cin >> r >> c;
      if (r<0 || r>2 || c<0 || c>2) {
        cout << "Enter a different row column a column" << endl;
      } else if (spaces[r][c] == player1 or spaces[r][c] == player2) {
        cout << "There's an X or O already on the spot, try again" << endl;
      } else {
        break;
      }
    }
    spaces[r][c] = playing;
    cin.clear();
    r = -1;
    c = -1;
    cin.ignore(10000, '\n');
    playing = (playing == player1) ? player2 : player1;

    for (int r = 0; r < 3; r++) {
      if (spaces[r][0] != ' ' && spaces[r][0] == spaces[r][1] && spaces[r][1] == spaces[r][2]) {
        winner = spaces[r][0];
        break;
      }
    }
    for (int c = 0; c < 3; c++) {
      if (spaces[0][c] != ' ' && spaces[0][c] == spaces[1][c] && spaces[1][c] == spaces[2][c]) {
        winner = spaces[0][c];
        break;
      }
    }
    if (winner != ' ') {
      break;
    }
    if (spaces[0][0] != ' ' && spaces[0][0] == spaces[1][1] && spaces[1][1] == spaces[2][2]) {
      winner = spaces[0][0];
      break;
    }
    if (spaces[0][2] != ' ' && spaces[0][2] == spaces[1][1] && spaces[1][1] == spaces[2][0]) {
      winner = spaces[0][2];
      break;
    }
  }
  cout << "The winner is " << winner << endl;
  cout << "Would you like to play again? (yes/no)" << endl;
  while (true) {
    cin >> cont;
    if (cont == "Yes" || cont == "yes") {
      return 0;
    }
    if (cont == "No" || cont == "no") {
      cout << "Goodbye." << endl;
      break;
    }
    if (cont != "Yes" || cont != "No" || cont != "yes" || cont != "no") {
      cout << "That is not a valid entry" << endl;
    }
  }
}