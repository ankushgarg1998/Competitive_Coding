void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    queue<int> q;
    for(int x: A)
        q.push(x);
        
    A.resize(A.size()+B.size());
    int k=0;
    for(int i=0; i<B.size(); i++) {
        if(q.empty() || (q.front() > B[i]))
            A[k++] = B[i];
        else {
            A[k++] = q.front();
            q.pop();
            --i;
        }
    }
    while(!q.empty()) {
        A[k++] = q.front();
        q.pop();
    }
}
