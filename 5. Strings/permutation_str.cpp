#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        int s = a.size();
        // string lr = rotate(a.begin(), a,begin());
        string rr = a;
        rotate(rr.begin(), rr.begin()+(s-1), rr.end());
        // cout << rr << endl; 
        string lr = a;
        rotate(lr.begin(), lr.begin()+1, lr.end());
        // cout << lr << endl; 
        if(lr == rr)
            cout << "YES" << endl;
        else    
            cout << "NO" << endl;  
    }
    return 0;
}