/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */


// Binary search: leave two results at the end.
class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        
        while (l+1<r) {
            int mid = l+ (r-l)/2;
            
            int f = guess(mid);
            
            if (f==0) return mid;
            if (f==1) {
                l=mid;
            }
            if (f==-1) {
                r=mid;
            }
        }
        if (guess(l)==0) return l;
        else return r;

    }
};
