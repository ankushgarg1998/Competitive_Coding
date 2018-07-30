
import java.util.Scanner;


public class addy {

    static long mod = 1000000007;
    public static int n;
    static long dp[][];

    public static long recur(char arr[][], int i, int state) {

        if (arr[state][i] == '#') {
            return 0;
        }
        //System.out.println(state + " " + i);

        if (i == n - 1) {
            if (state == 2) {
                return 1;
            } else {
                return 0;
            }
        }
         
         if(dp[state][i]!=-1)
         {
             return dp[state][i];
         }

        long ways = 0;
        if (state == 2) {
            if ((i + 1) <= n && arr[state][i + 1] != '#') {
                ways = (ways + recur(arr, i + 1, 1)) % mod;
            }
             
            
            if ((i + 1) <= n && arr[state][i + 1] != '#') {
                ways = (ways + recur(arr, i + 1, 3)) % mod;
            }
        } else {
            if ((i + 1) <= n && arr[state][i + 1] != '#') {
                ways = (ways + recur(arr, i + 1, 2)) % mod;
            }
        }

        return dp[state][i] = ways % mod;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int t;
        t = s.nextInt();
        for (int z = 0; z < t; z++) {
             n = s.nextInt();
            char arr[][] = new char[4][1005];

            for (int i = 1; i <= 3; i++) {
                    String str = s.next();
                    for(int k=0;k<str.length();k++)
                    {
                    	arr[i][k+1]=str.charAt(k);
                    }
                 }

            if (arr[1][1] == '#' || arr[3][n] == '#') {
                System.out.print("Case #" + (z+1) + ": ");
                System.out.println("0");
                continue;
            }
            
            dp= new long[4][1005];
            for(int i=0;i<=3;i++)
            {
                for(int j=0;j<=n;j++)
                {
                    dp[i][j]=-1;
                }
            }
            System.out.print("Case #" + (z+1) + ": ");
            System.out.println(recur(arr, 1, 2));
        }

    }
}