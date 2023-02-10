string Solution::fractionToDecimal(int A, int B) {
    long long Aa = A, Bb = B;
    bool neg = false;
    if(Aa<0) {
        neg = true;
        Aa *= -1;
    }
    if(Bb<0) {
        neg = (neg? false: true);
        Bb *= -1;
    }
    if(Aa%Bb == 0)
        return to_string(Aa/Bb);
    else {
        string ans = to_string(Aa/Bb);
        ans += '.';
        map<long long, int> m;
        while(Aa%Bb != 0) {
            if(m[Aa%Bb] == 0) {
                m[Aa%Bb] = ans.size();
            } else {
                string finans = "";
                finans += ans.substr(0, m[Aa%Bb]);
                finans += '(';
                finans += ans.substr(m[Aa%Bb]);
                finans += ')';
                // cout<<m[Aa%Bb]<<" "<<ans.substr(m[Aa%Bb].size());
                return (neg? "-"+finans: finans);
            }
            Aa = (Aa%Bb)*10;
            string str = to_string(Aa/Bb);
            // cout<<Aa<<" "<<Bb<<" ";
            // cout<<str<<" "<<ans<<"\n\n";
            ans += str[str.size()-1];
        }
        return (neg? "-"+ans: ans);
    }
}
