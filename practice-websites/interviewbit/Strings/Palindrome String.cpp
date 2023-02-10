int Solution::isPalindrome(string A) {
    int i=0, j=A.size();
    while(i<j) {
        if((A[i]>='a' && A[i]<='z') || (A[i]>='A' && A[i]<='Z') || (A[i]>='0' && A[i]<='9')) {
            if((A[j]>='a' && A[j]<='z') || (A[j]>='A' && A[j]<='Z') || (A[j]>='0' && A[j]<='9')) {
                if(toupper(A[i]) != toupper(A[j]))
                    return 0;
                else {
                    ++i; --j;
                }
            } else
                --j;
        } else
            ++i;
    }
    return 1;
}
