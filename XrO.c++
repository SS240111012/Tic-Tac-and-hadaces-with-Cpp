#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
using vi = vector<int> ;

void func()
{
    int spots_empty = 9 ;
    int row1[3] = {0,0,0} ;
    int row2[3] = {0,0,0} ;
    int row3[3] = {0,0,0} ;
    int user_row = 0 ;

    for (int left = 0 ; left < 3 ; ++left) 
    {
        if (left == 0 ) {
            for (int link = 0 ; link < 3 ; ++link) {
                cout << row1[link] << " " ;
            }
        }
        if (left == 1 ) {
            for (int link = 0 ; link < 3 ; ++link) {
                cout << row2[link] << " " ;
            }
        }
        if (left == 2 ) {
            for (int link = 0 ; link < 3 ; ++link) {
                cout << row3[link] << " " ;
            }
        }
        cout << "\n" ;
    }

    cout << "   " << endl ;

    int turn = 1; // 1 = X, 2 = O

    for (/* spots_empty >= 1 */ ; spots_empty > 0 ; spots_empty--) {
        cout << "Which Row and Position do you want to take {1,2,3}? (format: row col)" << endl ;

        int r, c;
        cin >> r >> c;

        // --- Prevent invalid input ---
        if (r < 1 || r > 3 || c < 1 || c > 3) {
            cout << "cell doesn't exist you idiot ! try again.\n";
            spots_empty++; // don't count this turn
            continue;
        }

        // --- Choose target row array ---
        int* target = nullptr;
        if (r == 1) target = row1;
        if (r == 2) target = row2;
        if (r == 3) target = row3;

        // --- Check if cell empty ---
        if (target[c-1] != 0) {
            cout << "This spot already ! choose another.\n";
            spots_empty++; 
            continue;
        }

        // --- Place X or O ---
        if (turn == 1)
            target[c-1] = 1; // X
        else
            target[c-1] = 2; // O

        // --- Print board again ---
        cout << "\nCurrent Board:\n";
        for (int left = 0 ; left < 3 ; ++left) 
        {
            if (left == 0 ) {
                for (int link = 0 ; link < 3 ; ++link)
                    cout << row1[link] << " ";
            }
            if (left == 1 ) {
                for (int link = 0 ; link < 3 ; ++link)
                    cout << row2[link] << " ";
            }
            if (left == 2 ) {
                for (int link = 0 ; link < 3 ; ++link)
                    cout << row3[link] << " ";
            }
            cout << "\n";
        }

        // --- Win Check ---
        auto win = [&](int a, int b, int c){
            return (a == b && b == c && a != 0);
        };

        // rows
        if (win(row1[0], row1[1], row1[2]) ||
            win(row2[0], row2[1], row2[2]) ||
            win(row3[0], row3[1], row3[2]) ||

            // cols
            win(row1[0], row2[0], row3[0]) ||
            win(row1[1], row2[1], row3[1]) ||
            win(row1[2], row2[2], row3[2]) ||

            // diagonals
            win(row1[0], row2[1], row3[2]) ||
            win(row1[2], row2[1], row3[0]))
        {
            cout << "\nPlayer " << (turn == 1 ? "X" : "O") << " WINS! \n";
            return;
        }

        // switch turns
        turn = (turn == 1 ? 2 : 1);
    }

    cout << "Game Draw.\n";
}
// sorry for whatever "hadaces" is ;
int main() 
{
  
    func() ;
    return 0 ;
}
