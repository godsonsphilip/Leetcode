class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> result = new ArrayList<>();
        result.add(0);
        if(n==0) return result;

        int i = 1;
        while(i<Math.pow(2,n)){  // This signifies the number of numbers possible from n bits
            for(int j = result.size()-1; j>=0; j--){
                int p = result.get(j) + i;  //Here each number in the sequence is found by adding the number of elementts possibke from the end to start of this resulr list.
                result.add(p);
            }
            i*=2;
        }
        return result;
    }
}