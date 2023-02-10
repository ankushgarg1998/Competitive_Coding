#include <bits/stdc++.h>
#define test int t; cin>>t; while(t--)
using namespace std;

int main()
{
    test{
        int n, m, topToBottom[30][30][60], bottomToTop[30][30][60], prs[60];
        char arr[300][300];
        cin>>n>>m;

        for(int i=0;i<n;i++){
            string str;
            cin>>str;
            for(int j=0;j<str.length();j++){
                arr[i][j] = str[j];
            }/*for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }*/
        }

        /*for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }*/
       
        //memset(topToBottom,0,sizeof(topToBottom));
        //memset(bottomToTop,0,sizeof(topToBottom));

        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(arr[i][j]=='1'){
                    topToBottom[i][j][0]=1;
                }
                    for(int k=i-1;k>=0;k--){
                        if(arr[k][j]=='1'){
                            topToBottom[i][j][i-k]+=1;
                        }
                    }

                    for(int k=j+1;k<m;k++){
                        if(arr[i][k]=='1'){
                            topToBottom[i][j][k-j]+=1;
                        }
                    }

                    int xp = i-1;
                    int yp = j+1;
                    while((i-1)>=0 && (i-1)<n && (j+1)<m && (j+1)>=0){
                        for(int k=2;k<60;k++){
                            topToBottom[i][j][k] += topToBottom[xp][yp][k-2];
                        }
                    }
            }
        }
      //  cout<<"hello\n";

        //////////////////////////////////////////////////////////////////

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(arr[i][j]=='1'){
                    bottomToTop[i][j][0]=1;
                }
                    for(int k=i+1;k<n;k++){
                        if(arr[k][j]=='1'){
                            bottomToTop[i][j][k-i]+=1;
                        }
                    }

                    for(int k=j+1;k<m;k++){
                        if(arr[i][k]=='1'){
                            bottomToTop[i][j][k-j]+=1;
                        }
                    }

                    int xp = i+1;
                    int yp = j+1;
                    while((i+1)<n && (j+1)<m){
                        for(int k=2;k<60;k++){
                            bottomToTop[i][j][k] += bottomToTop[xp][yp][k-2];
                        }
                    }
            }
        }

        ///////////////////////////////////////////////////////////////

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='1'){
                    for(int k=2;k<=(m+n-2);k++){
                        prs[k] = topToBottom[i][j][k] + bottomToTop[i][j][k];
                    }
                    for(int k=j+1;k<m;k++){
                        if(arr[i][k]=='1'){
                            prs[k-j]-=1;
                        }
                    }
                    for(int k=i-1;k>=0;k--){
                        if(arr[k][j]=='1'){
                            prs[i-k]-=1;
                        }
                    }
                }
            }
        }

        //////////////////////////////////////////////////////////////////////

        for(int i=1;i<=(m+n-2);i++){
            cout<<prs[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}