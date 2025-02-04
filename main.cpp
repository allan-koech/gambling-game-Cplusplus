#include <iostream>
#include<string>
#include<typeinfo>
#include <vector>

 using namespace std;

// 1. Accept and update deposit from the customer;
// 2. Get the number of bets and the bet amount from the customer
// 3. Spin the wheel 1. Generate the array with the bettletters;
               //    2. Generate the winning letters
// 4. Check if customer won
// 5. Give the customer winnings
// 6. ask the customer to play again.
int balance;
struct DataPoint{
 string name;
 int value;
};

vector<string> generateLetterArray(const vector<DataPoint>& dataset){
   vector<string> letterArray;
   for(const auto & eachSet : dataset){
      for(int i= 0; i< eachSet.value; i++){
      letterArray.push_back(eachSet.name);
      }
   }
   return letterArray;
}






int collectDeposit(){
   int depositAmount;
   cout << "\n Welcome to Kingdom bets";
   bool checkDeposit = true;
   while(checkDeposit) {
      int proposedDeposit;
      cout << "Enter the amount you would like to deposit  \n ";
      cin >> proposedDeposit;
      if(proposedDeposit > 0){
         depositAmount = proposedDeposit;
         balance += depositAmount;
        cout << " Deposit successful \n";
        checkDeposit = false;
        break;
      } else{
       cout << " invalid amount please try again \n";}
   }
   return 0;
};
int getBetAmount(){
double betPerLine;
int numberOfLines;
double totalBetAmount;
bool checkAmount = true;
do{
cout << "Enter the number of Lines you would like to bet on";
cin >> numberOfLines;
if (numberOfLines < 1 || numberOfLines > 3) {
            cout << "Invalid input! Please enter a number between 1 and 3.";
        }
}while ( numberOfLines < 1 ||numberOfLines > 3 );

do{
   cout << "Enter the amount you would like to bet on per line ";
   cin >> betPerLine;
   totalBetAmount = betPerLine * numberOfLines;
   cout << totalBetAmount;
   if(totalBetAmount > balance || betPerLine < 0 ){
      cout << "Invalid bet Amount! Please try again \n";
   } else {
      cout << "Bet Placed Successfully";
      balance -= totalBetAmount;
      checkAmount = false;
   }
} while(checkAmount);
return 0;
}

void spinWheel(){
vector<DataPoint> letterSet = {
   {"A", 2},
   {"B", 4},
   {"C", 6},
   {"D", 8}
};
vector<string> letterArray = generateLetterArray(letterSet);

}



int main(){
  //collectDeposit();
  // getBetAmount();
  spinWheel();
   return 0;
}