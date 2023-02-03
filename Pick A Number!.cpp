#include <bits/stdc++.h>

using namespace std;

const int sz_ar=4;//you change this to change the size of the arra
const int s[sz_ar]={1,5,8,9};//you can change this to any array u want
int a[sz_ar]; int cpy[sz_ar];

bool binser(int l, int r, int cnt){
    int mid=(l+r)/2;
    if (l<=r) {
        if (cpy[mid]>a[cnt]) return binser(l,mid-1,cnt);
        else if (cpy[mid]<a[cnt]) return binser(mid+1,r,cnt);
        else return true;
    }
    else return false;
}

int main() {
    int t=5;//you can change this depending on how many tries you want to give the user
    cout << "*: a number is on the array but not in the right position\n";
    cout << "@: a number is not on the array\n";
    cout << "#: a number is on the right position\n";
    char ans[sz_ar];
    while (t--) {
        cout << "1-9: ";//you can change this
        for (int i=0;i<sz_ar;i++){
            cin>>a[i];
            cpy[i]=s[i];
        }
        sort(cpy,cpy+sz_ar);
        for (int i=0;i<sz_ar;i++) {
            if (s[i]!=a[i]) {
                bool check=binser(0,sz_ar-1,i);
                if(check==true) ans[i]='*';
                else ans[i]='@';  
            }
            else ans[i]='#';
        }
//        cout << endl;
        int cnt=0;
        for (int i=0;i<sz_ar;i++) {
            if (ans[i]=='#') cnt++;
            else continue;
        }
        sort(ans,ans+sz_ar, greater<int>());
        cout << ans;
        if (cnt==4) {
            cout << "\nYou Won!";
            return 0;
        }
        if (t==0) {
            cout << "\nYou Lost!";
        }
        
        cout << endl;    
    }
    return 0;
    
}
