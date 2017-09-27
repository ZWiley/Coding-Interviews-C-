//统计一个数字在排序数组中出现的次数。
/***************************************************
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return count(data.begin(), data.end(), k);
    }
};
****************************************************/

/***************************************************
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
       int count = 0;
       for(int i = 0; i < data.size(); i++){
           if(data[i] == k){
               count++;
           }
       }
       return count;
    }
};
**************************************************/

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
       if(data.empty()) return 0;

       int number = 0;
       int first = GetFirstIndex(data, k, 0, data.size()-1);
       int last  = GetLastIndex(data, k ,0, data.size()-1);
       if(first > -1 && last > -1)
            number = last - first - 1;
       return number;
    }

    int GetFirstIndex(vector<int> &data, int k, int start, int end){
        if(start > end) return -1;
        int mid = start + (end - start)/2;

        if(data[mid] == k){
            if((mid == start) || (data[mid - 1] !=k))
                return mid;
            else 
                end = mid -1;
        }else{
            if(data[mid] > k) end = mid - 1;
            else start = mid+1;
        }
        return GetFirstIndex(data, k, start, end);
    }

    int GetLastIndex(vector<int> &data, int k, int start, int end){
        if(start > end) return -1;
        
        int mid = start +(end-start)/2;
        if(data[mid] == k){
            if((mid == end) || (data[mid+1] != k)) return mid;
            else start = mid + 1；
        }else{
            if(data[mid] > k) end = mid - 1;
            else start = mid+1;
        }
        return GetLastIndex(data, k ,start, end);
    }
};