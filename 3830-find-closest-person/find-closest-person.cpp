class Solution {
public:
    int findClosest(int x, int y, int z) {
        // Either both are same or equidustant from z
        if(x==y or abs(x-z)==abs(y-z)) return 0;
        int xd = abs(x-z), yd = abs(y-z);
        //X on left side
        return (xd<yd) ? 1 : 2;
    }
};