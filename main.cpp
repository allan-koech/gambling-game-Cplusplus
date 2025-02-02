#include <iostream>
#include<string>
#include<typeinfo>

 using namespace std;

// 1. Accept and update deposit from the customer;
// 2. Get the number of bets and the bet amount from the customer
// 3. Spin the wheel
// 4. Check if customer won
// 5. Give the customer winnings
// 6. ask the customer to play again.
int balance;
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



int main(){
  collectDeposit();
   getBetAmount();
   return 0;
}