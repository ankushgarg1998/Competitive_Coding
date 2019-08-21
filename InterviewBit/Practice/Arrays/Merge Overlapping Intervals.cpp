/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool comp(const Interval a, const Interval &b) {
    if(a.start == b.start)
        return a.end < b.end;
    return a.start < b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() == 0)
        return A;
        
    sort(A.begin(), A.end(), comp);
    vector<Interval> ans;
    int start = A[0].start, end = A[0].end;
    for(int i=1; i<A.size(); i++) {
        if(A[i].start > end) {
            ans.push_back(*(new Interval(start, end)));
            start = A[i].start;
            end = A[i].end;
        } else
            end = max(A[i].end, end);
    }
    ans.push_back(*(new Interval(start, end)));
    return ans;
}
