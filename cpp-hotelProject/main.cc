#include <iostream>
#include <random>
#include <sstream>
#include "Hotel.h"
#include "Date.h"
#include "Reservation.h"
#include "Room.h"


using namespace std;

#define NUM_ROOMS 4
#define NUM_NAMES 4
#define SCORE 2

//global variables for testing purposes
int roomNumbers[NUM_ROOMS] = {101,202,201,102};
int orderedRoomNumbers[NUM_ROOMS] = {101,102,201,202};
string bedTypes[NUM_ROOMS] = {"double", "single", "queen", "king"};
string names[NUM_NAMES*4] = 
{"Bobby", "Alice", "Julie", "Zelda",
"Cindy", "Shelly", "Ahmed", "Jonny",
"Randy", "Dopey", "Sneezy", "Grumpy",
"Doc", "Happy", "Sleepy", "Bashful"};
string orderedNames[NUM_NAMES] = {"Zelda", "Julie", "Alice", "Bobby"};
int caps[NUM_ROOMS] = {12,10,8,9};

int testResOverlap();
bool resOverlap(Reservation& r1, Reservation& r2, bool);
int testIsMatch();
int testAddRoom();
int testAddRoomOrder();
int testDeleteRoom();
int testAddResRoom();
int testAddResRoomOrder();
int testAddRes();
//int testUpdateReservations();

int main(){
    int choice = -1;
    while(choice != 0 && cin.good()){
        std::cout<<endl;
        std::cout<<" 0. Exit"<<endl;
        std::cout<<" 1. [2 marks] Test Reservation overlaps function"<<endl;
        std::cout<<" 2. [2 marks] Test isMatch function"<<endl;
        std::cout<<" 3. [2 marks] Test add room function"<<endl;
        std::cout<<" 4. [2 marks] Test add room for numeric order"<<endl;
        std::cout<<" 5. [2 marks] Test delete room"<<endl;
        std::cout<<" 6. [4 marks] Test add reservation to room"<<endl;
        std::cout<<" 7. [2 marks] Test add reservation to room for correct order"<<endl;
        std::cout<<" 8. [6 marks] Test add reservation to Hotel"<<endl;
        std::cout<<" 9. [Bonus: 1 mark] Test update reservations"<<endl;
        std::cout<<" 10. [22 marks + 1 Bonus] Test all and get mark"<<endl<<endl;
        cin >> choice;
        std::cout<<endl;
        switch (choice)
        {
        case 1: testResOverlap(); break;  
        case 2: testIsMatch(); break;  
        case 3: testAddRoom(); break;  
        case 4: testAddRoomOrder(); break;  
        case 5: testDeleteRoom(); break;
        case 6: testAddResRoom(); break;  
        case 7: testAddResRoomOrder(); break;
        case 8: testAddRes(); break;   
        //case 9: testUpdateReservations(); break;
        case 10:
            int score = 0;
            score += testResOverlap();
            score += testIsMatch();
            score += testAddRoom();
            score += testAddRoomOrder(); 
            score += testDeleteRoom();    
            score += testAddResRoom(); 
            score += testAddResRoomOrder();
            score += testAddRes();
            //score += testUpdateReservations();
            std::cout << "Your score is "<<score<<" out of 22"<<endl<<endl;   
            break;
        }
    }
    std::cout<<"Bye!"<<endl;
    return 0;
    
}

int testResOverlap(){
    int score = 2;
    std::cout<<endl<<"Testing Reservation overlap function..."<<endl;

    //testing different days. Should not overlap.
    Date date1(2022,9,30);
 	Date date2(2022,9,28);
    Reservation res1("Joe", date1, 3);
 	Reservation res2("Bob", date2, 2);

 	std::cout<<endl;
    if (!resOverlap(res1, res2, false)) score = 0;

    // here are my test cases

    // testing for different months should not overlap
    Date da1(2022,10,30);
 	Date da2(2022,9,28);
    Reservation re1("Joe", da1, 3);
 	Reservation re2("Bob", da2, 2);

 	std::cout<<endl;
    if (!resOverlap(re1, re2, false)) score = 0;

    // testing for different months but this time the month for 2nd date is different should not overlap
    Date da3(2022,9,30);
 	Date da4(2022,10,28);
    Reservation re3("Joe", da3, 3);
 	Reservation re4("Bob", da4, 2);

 	std::cout<<endl;
    if (!resOverlap(re3, re4, false)) score = 0;

    //testing for different years but the first year is a bigger date should not overlap
    Date da5(2023,9,30);
 	Date da6(2022,10,28);
    Reservation re5("Joe", da5, 5);
 	Reservation re6("Bob", da6, 3);

 	std::cout<<endl;
    if (!resOverlap(re5, re6, false)) score = 0;

    //testing for the end of the year. Should overlap
    Date da7(2022,12,30);
 	Date da8(2023,1,1);
    Reservation re7("Joe", da7, 5);
 	Reservation re8("Bob", da8, 3);

 	std::cout<<endl;
    if (!resOverlap(re7, re8, true)) score = 0;

    //testing different days but duration overlaps. Should overlap.
    Reservation res3("Joe", date1, 2);
 	Reservation res4("Bob", date2, 3);

 	std::cout<<endl;
    if (!resOverlap(res3, res4, true)) score = 0;

    
    // testing different months, should not overlap
    Date date3(2021, 9, 30);
    Date date4(2021, 10, 2);
    Reservation r1("Joe", date3, 1);
    Reservation r2("Joe", date4, 3);

    std::cout<<endl;
    if (!resOverlap(r1, r2, false)) score = 0;

    // testing different months, should overlap
    Reservation r3("Joe", date3, 5);
    Reservation r4("Joe", date4, 3);

    std::cout<<endl;
    if (!resOverlap(r3, r4, true)) score = 0;

    // testing different years, should not overlap
    Date date5(2022, 12, 31);
    Date date6(2023, 1, 2);
    Reservation r5("Joe", date5, 1);
    Reservation r6("Joe", date6, 3);

    std::cout<<endl;
    if (!resOverlap(r5, r6, false)) score = 0;

    // testing different years, should overlap
    Reservation r7("Joe", date5, 5);
    Reservation r8("Joe", date6, 3);

    std::cout<<endl;
    if (!resOverlap(r7, r8, true)) score = 0;


    // testing different years, should not overlap
    Date date7(2020, 1, 2);
    Date date8(2023, 1, 2);
    Reservation r9("Joe", date7, 1);
    Reservation r10("Joe", date8, 3);

    std::cout<<endl;
    if (!resOverlap(r9, r10, false)) score = 0;
    
    cout<<"Score: "<<score<<endl;
    
    return score;
}

bool resOverlap(Reservation& r1, Reservation& r2, bool ol){
    if (ol){
        if (r1.overlaps(r2)){
            if (r2.overlaps(r1)){
                r1.print();
                std::cout<<" and ";
                r2.print();
                std::cout<<" overlap each other. Test passed"<<endl;
                return true;
            }else{
                r2.print();
                std::cout<<" does not overlap ";
                r1.print();
                std::cout<<" (but they overlap in the other direction) Test failed"<<endl;
                return false;
            }
        }else{
            r1.print();
            std::cout<<" does not overlap ";
            r2.print();
            std::cout<<"Test failed"<<endl;
            if (r2.overlaps(r1)){
                cout<<"but they overlap in the other direction"<<endl;
            }    
            return false;
        }
    }else{
        //they should not overlap in this branch
        if (r1.overlaps(r2)){
            if (r2.overlaps(r1)){
                r1.print();
                std::cout<<" and ";
                r2.print();
                std::cout<<" overlap each other. Test failed"<<endl;
                return false;
            }else{
                r1.print();
                std::cout<<" overlaps ";
                r2.print();
                std::cout<<"Test failed"<<endl;
                return false;
            }
        }else{
            if (r2.overlaps(r1)){
                r1.print();
                std::cout<<" and ";
                r2.print();
                std::cout<<" overlap each other. Test failed"<<endl;
                return false;
            }else{
                r1.print();
                std::cout<<" does not overlap ";
                r2.print();
                std::cout<<"Test passed"<<endl;
                return true;
            }
        }

    }
}

int testIsMatch(){
    std::cout<<endl<<"Testing room isMatch function..."<<endl<<endl;
    Room t1(101, "King", 4, true);
    
    if (!t1.isMatch("King",2, true)){
        std::cout<<"Required 2 capacity, had 4, isMatch false, test failed"<<endl;
        return 0;
    }


    if (!t1.isMatch("King",4, true)){
        std::cout<<"Required 4 capacity, had 4, isMatch false, test failed"<<endl;
        return 0;
    }

    if (t1.isMatch("King",6, true)){
        std::cout<<"Required 6 capacity, had 4, isMatch true, test failed"<<endl;
        return 0;
    }

    cout<<"Capacity tests passed"<<endl;

    if (!t1.isMatch("King",4, false)){
        std::cout<<"Did not require fridge, had fridge, isMatch false, test failed"<<endl;
        return 0;
    }

    if (t1.isMatch("Queen",6, true)||t1.isMatch("Queen",4, true)||t1.isMatch("Queen",2, true)){
        std::cout<<"Required Queen, had King, isMatch true, test failed"<<endl;
        return 0;
    }

    cout<<"bed type tests passed"<<endl;

    Room t2(202, "King", 4, false);

    if (!t2.isMatch("King",4, false)){
        std::cout<<"Did not require fridge, did not have fridge, isMatch false, test failed"<<endl;
        return 0;
    }

    if (t2.isMatch("King",4, true)){
        std::cout<<"Required fridge, did not have fridge, isMatch true, test failed"<<endl;
        return 0;
    }

    cout<<"has fridge tests passed"<<endl;

    std::cout << "room isMatch all tests passed, 2 marks"<<endl;
    return SCORE;
}

int testAddRoom(){
    std::cout<<endl<<"Testing Hotel addRoom function..."<<endl<<endl;

    Hotel gt;
    for (int i = 0; i < NUM_ROOMS; ++i){
        gt.addRoom(roomNumbers[i], bedTypes[i], caps[i], (i%2==0));
    }
    
    //capture the output and put in a stringstream
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    std::cout.rdbuf( strCout.rdbuf() );

    gt.print();

    //replace std::out and print output to console
    std::cout.rdbuf( oldCoutStreamBuf );
    string output = strCout.str();
    std::cout << output;

    //find all room names
    int found = -1;
    for (int i = 0; i < NUM_ROOMS; ++i){
        found = output.find(to_string(roomNumbers[i]));
        if (found == -1){
            std::cout<<"Room "<<roomNumbers[i]<<" not found"<<endl;
            std::cout<<"addRoom test failed"<<endl;
            return 0;
        }
        
    }
    std::cout<<"All room numbers found, 2 marks"<<endl;
    return SCORE;
}

int testAddRoomOrder(){
    std::cout<<endl<<"Testing Hotel addRoom function for correct order..."<<endl<<endl;

    Hotel gt;
    for (int i = 0; i < NUM_ROOMS; ++i){
        gt.addRoom(roomNumbers[i], bedTypes[i], caps[i], (i%2==0));
    }
    
    //capture the output and put in a stringstream
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    std::cout.rdbuf( strCout.rdbuf() );

    gt.print();

    //replace std::out and print output to console
    std::cout.rdbuf( oldCoutStreamBuf );
    string output = strCout.str();
    std::cout << output;

    //find all room names
    int found = -1;
    for (int i = 0; i < NUM_ROOMS; ++i){
        found = output.find(to_string(orderedRoomNumbers[i]), found+1);
        if (found == -1){
            std::cout<<"Room "<<orderedRoomNumbers[i]<<" not found in correct place"<<endl;
            std::cout<<"add rooms in order test failed"<<endl;
            return 0;
        }
        
    }
    std::cout<<"All room found in order, 2 marks"<<endl;
    return SCORE;
}

int testDeleteRoom(){
     std::cout<<endl<<"Testing Hotel deleteRoom function..."<<endl<<endl;

    Hotel gt;
    for (int i = 0; i < NUM_ROOMS; ++i){
        gt.addRoom(roomNumbers[i], bedTypes[i], caps[i], (i%2==0));
    }

    //remove the rooms in a certain order
    int indices[4] = {2,0,3,1};

    for (int i = 0; i < NUM_ROOMS; ++i){
        gt.print();
        int index = indices[i];
        gt.deleteRoom(roomNumbers[index]);
         //capture the output and put in a stringstream
        streambuf* oldCoutStreamBuf = std::cout.rdbuf();
        ostringstream strCout;
        std::cout.rdbuf( strCout.rdbuf() );

        gt.print();

        //replace std::out and print output to console
        std::cout.rdbuf( oldCoutStreamBuf );
        string output = strCout.str();
        std::cout << output;

        //find deleted room name
        int found = output.find(to_string(roomNumbers[index]));
        if (found == -1){
            std::cout<<"Room "<<roomNumbers[index]<<" deleted, not found - success!"<<endl;
        }else{
            std::cout<<"Room "<<roomNumbers[index]<<" found"<<endl;
            std::cout<<"deleteRoom failed"<<endl;
            return 0;
        }
        
        
    }
    std::cout<<"deleteRoom success, "<<SCORE<<" marks"<<endl;
    return SCORE;
    
   
        
}

int testAddResRoom(){
    std::cout<<endl<<"Testing room add reservation function..."<<endl<<endl;

    int score = 0;
    Room t1(101, "King", 6, true);
    Date date1(2022, 4, 20);
    Date date2(2022, 4, 21);
    Date date3(2022, 8, 20);
    t1.addReservation(names[0], date1, 1);
    t1.addReservation(names[1], date2, 2);
    t1.addReservation(names[2], date3, 2);

    //capture the output and put in a stringstream
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    std::cout.rdbuf( strCout.rdbuf() );

    t1.printReservations();

    //replace std::out and print output to console
    std::cout.rdbuf( oldCoutStreamBuf );
    string output = strCout.str();
    std::cout << output;

    //find room name
    int found = -1;
    for (int i = 0; i < NUM_NAMES - 1; ++i){
        found = output.find(names[i]);
        if (found == -1){
            std::cout<<names[i]<<" not found"<<endl;
            std::cout<<"add reservation to room test failed"<<endl;
            return 0;
        }
        
    }
    std::cout<<"All names found, 2 marks"<<endl<<endl;
    score += SCORE;

    t1.addReservation(names[3], date2, 2);
    //reset stringstream
    strCout.str(std::string());
    std::cout.rdbuf( strCout.rdbuf() );

    t1.printReservations();

    //replace std::out and print output to console
    std::cout.rdbuf( oldCoutStreamBuf );
    output = strCout.str();
    std::cout << output;

    if (output.find(names[NUM_NAMES-1])!=-1){
        std::cout<<names[NUM_NAMES-1]<<" reservation found, Reservations overlap, test failed"<<endl;
        return score;
    }
    std::cout<<names[NUM_NAMES-1]<<" reservation not found, test passed, 2 marks"<<endl;
    std::cout<<"Total score: "<<score + SCORE<<" marks"<<endl;
    return score + SCORE;

}

int testAddResRoomOrder(){
    std::cout<<endl<<"Testing room add reservation function for correct order..."<<endl<<endl;

    Room t1(101, "King", 8, true);
    Date date1(2024, 4, 20);
    Date date2(2022, 4, 21);
    Date date3(2022, 4, 18);
    Date date4(2022, 1, 20);
    t1.addReservation(names[0], date1, 1);
    t1.addReservation(names[1], date2, 1);
    t1.addReservation(names[2], date3, 1);
    t1.addReservation(names[3], date4, 2);
    //capture the output and put in a stringstream
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    std::cout.rdbuf( strCout.rdbuf() );

    t1.printReservations();

    //replace std::out and print output to console
    std::cout.rdbuf( oldCoutStreamBuf );
    string output = strCout.str();
    std::cout << output;

    //find room number
    int found = -1;
    for (int i = 0; i < NUM_NAMES - 1; ++i){
        found = output.find(orderedNames[i], found+1);
        if (found == -1){
            std::cout<<orderedNames[i]<<" not found"<<endl;
            std::cout<<"add reservation to room in Date order test failed"<<endl;
            return 0;
        }
        
    }
    std::cout<<"All names found in order, 2 marks"<<endl<<endl;
    return SCORE;    
}

int testAddRes(){
    std::cout<<endl<<"Testing Hotel add reservation function..."<<endl<<endl;

    //test they are all added to the correct room
    Hotel gt;
    cout<<"Going into the for loop"<<endl;
    //add some rooms
    for (int i = 0; i < NUM_ROOMS; ++i){
        cout<<"Iteration number: "<<i<<endl;
        gt.addRoom(roomNumbers[i], bedTypes[i], caps[i], (i%2==0));
    }
    cout<<"out of the first for loop"<<endl;
    

    // add reservations
    Date date1(2022, 12, 25);
    cout<<"going into the second for loop"<<endl;
    for (int i = 0; i < NUM_ROOMS; ++i){
        cout<<"inside the i for loop. iteration: "<<i<<endl;
        for (int j = 0; j < NUM_NAMES; ++j){
            cout<<"inside the j for loop. iteration: "<<j<<endl;
            Date temp(2022,1, 8+j*2);
            cout<<"going into addReservation() function"<<endl;
            gt.addReservation(names[i*4+j], bedTypes[i], 4, false, temp, j);
            cout<<"outie"<<endl;
        }
    }

    //capture the output and put in a stringstream
    //so we can make sure things print properly
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    std::cout.rdbuf( strCout.rdbuf() );

    gt.printReservations();

    //replace std::out and print output to console
    std::cout.rdbuf( oldCoutStreamBuf );
    string output = strCout.str();
    std::cout << output;
    
    Room* room;

    std::cout.rdbuf( strCout.rdbuf() );

    //match the type to the room, then find the corresponding names
    for (int i = 0; i < NUM_ROOMS; ++i){
        strCout.str(std::string());
        gt.getRoom(roomNumbers[i], &room);
        room->printReservations();
        output = strCout.str();
        for (int k = 0; k < NUM_ROOMS; ++k){
            // does this Room have the proper bedType?
            if (output.find(bedTypes[k])!=-1){
                for (int j = 0; j < NUM_NAMES; ++j){
                    if (output.find(names[k*4+j])==-1){
                        std::cout.rdbuf( oldCoutStreamBuf );
                        std::cout << "output: "<<output<<endl;
                        std::cout<<names[k*4+j]<<" not found in "<<bedTypes[k]<<" room, test failed "<<endl;
                        return 0;
                    }
                }
            }
        } 
    }

    //replace std::out 
    std::cout.rdbuf( oldCoutStreamBuf );
    std::cout<<"All names found 6 marks"<<endl;
    return 6;
}

// int testUpdateReservations(){
//     std::cout<<endl<<"Testing Hotel update reservation function..."<<endl<<endl;

//     Hotel gt;

//     //add some rooms
//     for (int i = 0; i < NUM_ROOMS; ++i){
//         gt.addRoom(roomNumbers[i], bedTypes[i], caps[i], (i%2==0));
//     }

//     // add reservations
//     Date dates[NUM_NAMES];
//     for (int i = 0; i < NUM_NAMES; ++i){
//         dates[i].setDate(2022,1,8+i*2);
//     }
//     for (int i = 0; i < NUM_ROOMS; ++i){
//         for (int j = 0; j < NUM_NAMES; ++j){
//             // /Date temp(2022,1, 8+j*2);
//             if (!gt.addReservation(names[i*4+j], bedTypes[i], 4, false, dates[j], j)){
//                 cout<<"Error, reservation not added, exiting test"<<endl;
//                 return 0;
//             }
//         }
//     }
//     cout<<"Printing reservations:"<<endl;
//     gt.printReservations();
//     cout<<"Updating reservations:"<<endl;
//     gt.updateReservations(dates[NUM_NAMES-2]);
//     //capture the output and put in a stringstream
//     //so we can make sure things print properly
//     streambuf* oldCoutStreamBuf = std::cout.rdbuf();
//     ostringstream strCout;
//     std::cout.rdbuf( strCout.rdbuf() );

//     gt.printReservations();

//     //replace std::out and print output to console
//     std::cout.rdbuf( oldCoutStreamBuf );
//     string output = strCout.str();
//     std::cout << output;
//     std::cout<<"Done output"<<endl;
    
//     //print out and collect the dates
//     string dateStrings[NUM_NAMES];
//     for (int i = 0; i < NUM_NAMES; ++i){
//         strCout.str(std::string());
//         std::cout.rdbuf( strCout.rdbuf() );
//         dates[i].print();
//         std::cout.rdbuf( oldCoutStreamBuf );
//         dateStrings[i] = strCout.str();
//     }

//     //cout<<"out of loop"<<endl;

//     //search the output for the eliminated dates.
//     for (int i = 0; i < NUM_NAMES-2; ++i){    
//         if (output.find(dateStrings[i])!=-1){
//             cout<<"Date "<<dateStrings[i]<<" found, test failed."<<endl;        
//             return 0;       
//         }        
//     }

//     //cout<<"out of loop 2"<<endl;

//     //search the output for dates that should be there
//     for (int i =  NUM_NAMES-2;i< NUM_NAMES; ++i){    
//         if (output.find(dateStrings[i])==-1){
//             cout<<"Date "<<dateStrings[i]<<" not found, test failed."<<endl;        
//             return 0;       
//         }        
//     }

//     std::cout<<"Reservations correctly updated, 1 mark"<<endl;
//     return 1;
// }


