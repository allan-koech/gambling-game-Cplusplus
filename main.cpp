#include <iostream>
#include<string>
#include<typeinfo>
#include <vector>
#include <cstdlib>
#include <random>
#include <chrono>
 using namespace std;

// 1. Accept and update deposit from the customer;
// 2. Get the number of bets and the bet amount from the customer
// 3. Spin the wheel 1. Generate the array with the bettletters;
               //    2. Generate the winning letters
// 4. Check if customer won
// 5. Give the customer winnings
// 6. ask the customer to play again.
int balance;
int rows = 3;// number of letters from right to left
int columns = 3;// number of letters from top to bottom
double betPerLine;
int numberOfLines = 3;
double totalBetAmount;
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


vector <vector<string>> getWinningLetters(vector<string> & letterarray, int rowsToGenerate, int columnsToGenerate){
   int realTime;
   int randomNo;
   unsigned seed = chrono::system_clock::now().time_since_epoch().count();
   std::mt19937 gen(seed);
   uniform_int_distribution<> distrib(0, letterarray.size() - 1);

   vector<vector<string>> rows;

   for(int i = 0; i< rowsToGenerate; i++){
      vector<string> column;
      for(int j = 0; j< columnsToGenerate; j++){
      vector<string> letterArray(letterarray);
      unsigned seed = chrono::system_clock::now().time_since_epoch().count();
      mt19937 gen(seed);
      randomNo = distrib(gen);
      cout << randomNo << "\n";
      column.push_back(letterArray[randomNo]);
      if(j== columnsToGenerate - 1 ){
         rows.push_back(column);
         };
      }
}

vector<vector<string>> transposed(rows[0].size(), std::vector<std::string>(rows.size()));
for (int i =0; i< rows.size(); ++i){
   for(int j = 0; j< rows[i].size(); ++j){
      transposed[j][i] = rows[i][j];
      }}
for (int i =0; i< transposed.size(); ++i){
   for(int j = 0; j< transposed[i].size(); ++j){
      cout << transposed[i][j] << "|";
      }}


return transposed;
};

vector<vector<string>> spinWheel(){
vector<DataPoint> letterSet = {
   {"A", 2},
   {"B", 4},
   {"C", 6},
   {"D", 8}
};
vector<string> letterArray = generateLetterArray(letterSet);
vector<vector<string>> selectedLetters = getWinningLetters(letterArray, rows, columns);

return selectedLetters;

}

void checkWin(vector<vector<string>> selectedLetters ){
   vector <DataPoint> letterWin = {
   {"A", 8},
   {"B", 6},
   {"C", 4},
   {"D", 2}
   };
   int winnings;
   for(int i = 0; i < numberOfLines; ++i){ // checks the number of lines the customer bet on;
      cout << "Checking row"<< i+1;
      bool allSame = true;
      for(int j = 0; j < selectedLetters[i].size(); ++j ){// selects the individual letters in the array to check
         if(selectedLetters[i][i] != selectedLetters[i][j]){
            allSame = false;
            break;
         } }
      if(allSame){
         int multiplier;
         cout<< "You won row"<< i+1;
         for(const auto &eachSet : letterWin){// picks the multiplier by comparing it to a value in the array won;
            if(eachSet.name == selectedLetters[i][i]){
               winnings = eachSet.value * betPerLine;
               balance += winnings;
            }
         }}}
         }



int main(){
  //collectDeposit();
  //getBetAmount();
  
  checkWin(spinWheel());

   return 0;
}