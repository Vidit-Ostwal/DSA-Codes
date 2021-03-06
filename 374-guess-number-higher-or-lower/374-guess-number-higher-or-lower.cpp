/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int st = 1;
      int ed = n;
      
      while (st <= ed)
      {
        int mid = st + (ed - st) /2;
        if (guess(mid) == 0 )
          return mid;
        
        else if (guess(mid) == 1)
          st = mid + 1;
        
        else
          ed = mid - 1;
      }
      return -1;
      
    }
};