class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size = rotateArray.size();
        if(size == 0) return 0;
        
        int index1 = 0;
        int index2 = size -1;
        int indexMid = index1;
        while(rotateArray[index1] >= rotateArray[index2])
            {
            if(index2 - index1 == 1)
                {
                indexMid = index2;
                break;
            }
            
            indexMid = (index1+index2) / 2;
            if(rotateArray[indexMid] >= rotateArray[index1])
                index1 = indexMid;
            else if(rotateArray[indexMid] <= rotateArray[index2])
                index2 = indexMid;
           
        }
         return rotateArray[indexMid];
    }
};