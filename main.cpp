#include <iostream>
#include<string>
#include<typeinfo>

// 1. Accept and update deposit from the customer;
// 2. Get the number of bets and the bet amount from the customer
// 3. Spin the wheel
// 4. Check if customer won
// 5. Give the customer winnings
// 6. ask the customer to play again.

int collectDeposit(){
   int depositAmount;
   std:: cout << "\n Welcome to Kingdom bets";
   bool checkDeposit = true;
   while(checkDeposit) {
      int proposedDeposit;
      std:: cout << " \n Enter the amount you would like to deposit";
      std:: cin >> proposedDeposit;
      if(proposedDeposit > 0){
         depositAmount = proposedDeposit;
        std:: cout << " Deposit successful";
        checkDeposit = false;
        break;
      } else{
         std:: cout << "\n invalid amount please try again";}
   }
   return 0;
};



int main(){
   collectDeposit();
   return 0;
}