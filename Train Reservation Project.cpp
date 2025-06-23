#include <iostream>
using namespace std;

void printSeats(int coach_no, string seat_status[3][8][4]);
void coachesMenu(string seat_status[3][8][4], int* coach_no, int* seats_c1, int* seats_c2, int* seats_c3);
void seatBook(string seat_status[3][8][4], int* coach_no, int* seats_c1, int* seats_c2, int* seats_c3);

int main() {
    string seat_status[3][8][4];
    int seat_no, coach_no = 0, row, col, seats_c1 = 32, seats_c2 = 32, seats_c3 = 32;
    for(int i=0; i<3; i++){
        for(int j=0; j<8; j++){
            for(int k=0; k<4; k++){
                seat_status[i][j][k] = "V";
            }
        }
    }
    cout << "\nTrain Booking System\nV is for Vacant\nB is for Booked\nNA is for Not Available\n";
    char user_choice = 'y';
    while(user_choice == 'y' || user_choice =='Y'){
        if(seats_c1 == 0 && seats_c2 == 0 && seats_c3 == 0){
            cout << "All Seats are Booked";
            break;
        }
        coachesMenu(seat_status, &coach_no, &seats_c1, &seats_c2, &seats_c3);
        cout << "\nDo you want to Book another seat (y/n): ";
        cin >> user_choice;
        cout << endl;
    }
}

void printSeats(int coach_no, string seat_status[3][8][4]){
    int seat = 1;
    cout << "\n-------------------------------" << endl;
    cout << "\t   Coach No: " << coach_no+1 << "\n-------------------------------" << endl;
    cout << "Seat Status\tSeat Numbering" << endl;
    for(int i=0; i<8; i++){
        for(int j=0; j<4; j++){
            if(j==2)
                cout << " ";
            cout << seat_status[coach_no][i][j] << " ";
        }
        cout << "\t";
        for(int j=0; j<4; j++){
            if (j==2)
                cout << " ";
            cout << seat << " ";
            seat++;
        }
        cout << endl;
    }
}

void coachesMenu(string seat_status[3][8][4], int* coach_no, int* seats_c1, int* seats_c2, int* seats_c3){
    int choice;
    while(true){
        printSeats(*coach_no, seat_status);
        cout << endl;
        if((*coach_no == 0 && *seats_c1 == 0) || (*coach_no == 1 && *seats_c2 == 0) ||(*coach_no == 2 && *seats_c1 == 0))
            cout << "All seats in Coach No. " << *coach_no + 1 << " are Booked." << endl;
        if(*coach_no == 0) {
            cout << "For Next Coach Enter 1.\nTo Book Seat Enter 2.\nYour Choice: ";
            cin >> choice;
        }
        else if(*coach_no == 2) {
            cout << "For Previous Coach Enter -1.\nTo Book Seat Enter 2.\nYour Choice: ";
            cin >> choice;
        }
        else {
            cout << "For Previous Coach Enter -1.\nFor Next Coach Enter 1.\nTo Book Seat Enter 2.\nYour Choice: ";
            cin >> choice;
        }
        if(choice == 2)
            break;
        else if(choice == 1)
            (*coach_no)++;
        else if(choice == -1)
            (*coach_no)--;
        else 
            cout << "Invalid Choice." << endl;
    }
    seatBook(seat_status, coach_no, seats_c1, seats_c2, seats_c3);
}

void seatBook(string seat_status[3][8][4], int* coach_no, int* seats_c1, int* seats_c2, int* seats_c3) {
    int seat_no, row, col;
    while(true){
        cout << "Enter Seat No: ";
        cin >> seat_no;
        if(seat_no % 4 == 0){
            row = seat_no / 4 - 1;
            col = 3;
        }
        else{
            row = seat_no / 4;
            col = (seat_no - (row * 4)) - 1;
        }
        if(seat_status[*coach_no][row][col] == "V"){
            seat_status[*coach_no][row][col] = "B";
            cout << "Coach No. " << *coach_no+1 << " Seat No. " << seat_no << " has been Booked Successfully." << endl;
            if(*coach_no == 0)
                *seats_c1--;
            if(*coach_no == 1)
                *seats_c2--;
            if(*coach_no == 2)
                *seats_c3--;
            break;
        }
        else if(seat_status[*coach_no][row][col] == "B" || seat_status[*coach_no][row][col] == "NA")
            cout << "Seat No " << seat_no << " is currently unavailable." << endl;
    }
    printSeats(*coach_no, seat_status);
}