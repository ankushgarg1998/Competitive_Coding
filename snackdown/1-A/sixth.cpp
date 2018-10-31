#include<bits/stdc++.h>
#define li long long int
#define test int t; cin>>t; while(t--)
#define loop(i,a,b) for(long int i=a;i<b;i++)
using namespace std;

li ans;

li maxPeriod(li x, li xi, li y, li yi) {
    li oi = yi-y+1;
    if(oi <= xi) {
        if(x == (y - (yi-xi)))
            return 10000000000;
        else
            return -1;
    }
    return (x + (oi-xi) - 1);
}

bool validPeriod(li x, li xi, li y, li yi) {
    if(x>ans || y>ans)
        return false;
    li leftlast = xi + (ans - x);
    li rightfirst = yi-y+1;
    
    if(rightfirst > leftlast) {
        li span = rightfirst - leftlast - 1;
        if(span%ans == 0)
            return true;
        else
            return false;
    }

    li py = (x + (yi - xi))%ans;
    if(py == 0)
        py = ans;
    if(py == y)
        return true;
    else
        return false;

}

int main() {
    test {
        li n;
        cin>>n;
        vector<li> a(n);
        bool inf = true, firsttime = true, allomo = true;
        li x = -1, xi = -1;
        li y = -1, yi = -1; 
        loop(i, 0, n) {
            cin>>a[i];
            ++x;
            if(a[i] != -1) {
                if(firsttime) {
                    firsttime = false;
                    x = a[i];
                    xi = i;
                }
                else {
                    if(a[i] != x)
                        inf = false;
                }
                if(a[i] != 1)
                    allomo = false;
            }
        }

        if(inf) {
            cout<<"inf";
        } else {
            ans = 10000000000;
            li xis = xi;
            x = a[xis];
            loop(i, xis+1, n) {
                if(a[i] != -1) {
                    // cout<<x<<" "<<xi<<" ";
                    li period = maxPeriod(x, xi, a[i], i);
                    // cout<<period<<"\n";
                    if(period == -1) {
                        ans = -1;
                        break;
                    }
                    ans = min(ans, period);
                    x = a[i];
                    xi = i;
                }
            }
            if(ans == -1)
                cout<<"impossible";
            else {
                // cout<<ans<<"\n";
                calc:
                xi = xis;
                x = a[xis];
                loop(i, xis+1, n) {
                    if(a[i] != -1) {
                        // cout<<x<<" "<<xi<<" ";
                        if(validPeriod(x, xi, a[i], i)) {
                            // cout<<"v\n";
                            x = a[i];
                            xi = i;
                        } else {
                            if(ans == 1)
                                ans = -1;
                            else {
                                ans -= 1;
                                goto calc;
                            }
                            break;
                        }
                    }
                }
                if(ans == -1)
                    cout<<"impossible";
                else
                    cout<<ans;
            }
        }
        cout<<"\n";
    }
    return 0;
}