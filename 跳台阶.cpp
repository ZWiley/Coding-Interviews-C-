class Solution {
public:
    int jumpFloor(int number) {
        if (number <=0)
            return 0;
        if (number == 1)
            return 1;
        if (number == 2)
            return 2;
        int f1 = 1,f2 = 2,f3 = 0;
        for (int i = 3; i <= number; i++){
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;    
        }
};
