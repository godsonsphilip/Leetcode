class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //Two Pointer Approach:
        int n = numbers.size();
        vector<int> pair;
        int left = 0, right = n-1;
        while(left<right){
            if(numbers[left]+numbers[right] == target){
                pair.push_back(left+1);
                pair.push_back(right+1);
                break;
            }
            else if(numbers[left] + numbers[right] > target) right--;
            else {
                left++;
            }
        }
        return pair;
    }
};