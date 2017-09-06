class Solution {
public:
    int jumpFloorII(int number) {
		if (number <= 0){
            return -1;
        }else if (number == 1){
            return 1;
        }else{
            return 2 * jumpFloorII(number - 1); 
        }
    }
};
