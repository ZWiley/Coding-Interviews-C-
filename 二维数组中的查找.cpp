class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        if(array.empty()) return false;
        int row=array.size();
        int col=array[0].size();
        int r=0;
        int c=col-1;
        while(r<row&&c>=0){
            if(target==array[r][c])
                return true;
            if(target<array[r][c]){
                c--;
                continue;
            }
            if(target>array[r][c]){
                r++;
                continue;
            }
        }
        return false;
    }
};