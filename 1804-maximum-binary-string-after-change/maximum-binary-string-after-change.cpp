class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        string temp = binary;
        int index = -1;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(temp[i]=='0'){
                if(index==-1) index = i;
                else count++;
            }
            
        }

        for(int i = 0; i<n; i++){
            if(i==index+count) temp[i] = '0';
            else temp[i] = '1';
        }
        return temp;
    }
};