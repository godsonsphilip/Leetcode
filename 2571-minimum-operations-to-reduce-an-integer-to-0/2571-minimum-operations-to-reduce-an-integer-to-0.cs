public class Solution{
    public int MinOperations(int n) 
    {
        int ops = 0;
        while (n > 0) 
        {
            // Case 1: last two bits are "11"
            if ( (n & 3) == 3 )   
            {
                n = n+1;
                ops++;
            }
            // Case 2: last bit is "1" only
            else if ( (n & 1) == 1 )
            {
                n = n-1;
                ops++;
            }
            // Case 3: last bit is "0"
            else
            {
                n = n >> 1;    // equivalent to dividing n by 2
            }
        }
        return ops;
    }
}