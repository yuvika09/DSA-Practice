#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int t, n, sum;
        int i = 0, et = 0;
        int ans = 0;
        cin >> t >> n >> sum;
        int x = sum/n;
        int l = sum%n;
        while(i<t && et<(sum-l)){
            et += n;
            ans += n*n;
            i++;
        }
        if(l!=0 )
            ans += l*l;
        cout << ans << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int T;
//     cin >> T;
//     while(T--){
//         int t, n, sum;
//         int ans = 0;
//         cin >> t >> n >> sum;
//         int x = sum/n;
//         int l = sum%n;
//         if(sum%n==0){
//             if(x<=t)
//                 ans = x*n*n;
//             else if(x>t)
//                 ans = t*n*n;
//         }
//         else{
//             if((x+1)>=t)
//                 ans = t*n*n;
//             else if((x+1)<t)
//                 ans = x*n*n + l*l;
//         }
//         cout << ans << endl;   
//     }
//     return 0;
// }