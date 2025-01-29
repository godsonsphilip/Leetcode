function pivotIndex(nums: number[]): number {
    let result = -1;
    let sumLeft = 0;
    let sumRight = nums.reduce((accum, current) => accum + current, 0);;
    for(let i = 0; i < nums.length; i++){
        sumLeft = i === 0 ? 0 : (sumLeft + nums[i - 1]);
        sumRight = sumRight - nums[i];
        if(sumLeft === sumRight) {
            return i;
        }
    }
    return result;
};