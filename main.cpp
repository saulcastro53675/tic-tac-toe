#include <iostream>
#include "src/tictactoe.hpp"
using namespace std;

char spaces['3']['3'] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'}
};

int main() {
  cout << "Welcome to Tic-Tac-Toe!" << endl;
  for (int i = 0; i < 9; i++) {
    cout << " " << spaces[0][0] << " | " << spaces[0][1] << " | " << spaces[0][2] << endl;
    cout << "___+___+___" << endl;
    cout << " " << spaces[1][0] << " | " << spaces[1][1] << " | " << spaces[1][2] << endl;
    cout << "___+___+___" << endl;
    cout << " " << spaces[2][0] << " | " << spaces[2][1] << " | " << spaces[2][2] << endl;
    cout << "It is " << playing() << " turn" << endl;
    cout << "Enter a row a column, 0-2" << endl;
    cin >> r >> c;
    if (r<0 || r>2 || c<0 || c>2) {
      cout << "Enter a different row column a column" << endl;
    } else if (spaces[r][c] == 'X'||spaces[r][c] == 'O') {
      cout << "There's an X or O already on the spot, try again" << endl;
    }
    spaces[r][c] = playing();
  }

  cout << "Would you like to play again?" << endl;

}
