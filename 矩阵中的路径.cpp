/**
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
 * 如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
 * 例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
 * 因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/
class Solution {
    bool hasPathRecu(char* matrix, int rows, int cols, int row, int col, char *str, int length, vector<bool> used)
    {
        if(length==strlen(str))
            return true;
        if(row<0||row>=rows||col<0||col>=cols)
            return false;
        int index = col + row*cols;
        bool result = false;
        if( !used[index] && matrix[index]==str[length]){
            used[index] = true;
            result = hasPathRecu(matrix, rows, cols, row-1, col, str, length+1, used)|| hasPathRecu(matrix, rows, cols, row+1, col, str, length+1, used)
                ||hasPathRecu(matrix, rows, cols, row, col+1, str, length+1, used)||hasPathRecu(matrix, rows, cols, row, col-1, str, length+1, used);
            used[index] = false;
        }
        if(result)
            return true;
        return false;
    }
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        vector<bool> used(strlen(matrix),false);
        if(str==NULL) return true;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(hasPathRecu(matrix, rows, cols, i, j, str, 0, used))
                    return true;
            }
        }
        return false;
     
    }
};