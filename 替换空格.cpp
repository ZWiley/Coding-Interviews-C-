class Solution {
public:
	void replaceSpace(char string[] ,int length) {
		if(string == NULL || length <= 0)
            return ;
        
        int originalLength = 0;
        int numberBlank = 0;
        int i =0;
        while(string[i] != '\0')
            {
            ++originalLength;
            if(string[i] == ' ')
                ++numberBlank;
            	++i;
        }
        int newLength = originalLength + numberBlank * 2;
        if(newLength > length)
            return ;
        int indexOriginal = originalLength;
        int indexNew = newLength;
        while(indexOriginal >= 0 && indexNew > indexOriginal)
            {
            if(string[indexOriginal] == ' ')
                {
                string[indexNew --] = '0';
                string[indexNew --] = '2';
                string[indexNew --] = '%';
             }
            else{
                string[indexNew --] = string[indexOriginal];
            }
            --indexOriginal;
        }
	}
};