/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> ans;
    vector<pair<int, int> > v;
    if(intervals.size() == 0) {
        ans.push_back(Interval(1, 1));
        return ans;
    }
    for(int i=0; i<intervals.size(); i++) {
        v.push_back(make_pair(intervals[i].start, 1));
        v.push_back(make_pair(intervals[i].end, -1));
    }
    v.push_back(make_pair(newInterval.start, 1));
    v.push_back(make_pair(newInterval.end, -1));
    sort(v.begin(), v.end());
    
    int open = 0;
    int oa = 0;
    for(auto x: v) {
        if(x.second == 1) {
            if(open == 0)
                oa = x.first;
            ++open;
        } else {
            --open;
            if(open == 0)
                ans.push_back(Interval(oa, x.first));
        }
    }
    return ans;
}
