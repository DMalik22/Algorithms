/*
My dynammic programming approach to the coin change problem.
int amount is the change to be obtained using as few coins as possible given in the coins vector
if it's not possible to get change for amount with the coins given
(for eg, trying to get change for 30 cents with only quarters available)
then -1 must be returned to indicate that.
*/

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> MinNumCoins (amount + 1, amount + 1); //amount + 1 represents infinity in this solution
    int coin_i, numCoins;
    MinNumCoins[0] = 0;
    
    for(int m = 1; m <= amount; m++){
      for(int i = 0; i < coins.size(); i++){
        coin_i = coins[i];
        if(m >= coin_i){
          numCoins = MinNumCoins[m - coin_i] + 1;
          if(numCoins < MinNumCoins[m])
            MinNumCoins[m] = numCoins;
        }
      }
    }
    
    //if given coins can't be used to make change for given amount
    if(MinNumCoins[amount] == amount + 1)
      return -1;
    
    return MinNumCoins[amount];
  }
};
