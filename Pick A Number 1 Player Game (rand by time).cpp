#include <bits/stdc++.h>

using namespace std;

const int sz_ar=6;//you change this to change the size of the array
const int sz_num=10;
int num[sz_num]={0,1,2,3,4,5,6,7,8,9};
int s[sz_ar];//you can change this to any array u want
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

int answer() {
    char ans[sz_ar];
    for (int i=0;i<sz_ar;i++){
        cin>>a[i];
        cpy[i]=s[i];
    }
    sort(cpy,cpy+sz_ar);
    for (int i=0;i<sz_ar;i++) {
        if (s[i]!=a[i]) {
            bool check=binser(0, sz_ar-1, i);
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
    for (int i=0;i<sz_ar;i++) cout << ans[i];
    return cnt;
}

void shuffle(size_t n) {
    if (n>1) {
	srand(time(NULL));
	size_t i;
	for (i=0; i<n-1; i++) {
		size_t j=i+rand()/(RAND_MAX/(n-i)+1);
		size_t t=num[j];
		num[j]=num[i];
		num[i]=t;
		s[i]=num[i];
	} 
    }
}

int main() {
    cout << "https://github.com/MathiasAdya\n\n";
    cout << "THE SEQUENCE CONTAINS 6 INTEGERS FROM 0-n\n";
    cout << "How many tries you want to guess: ";
    int t;cin>>t;//you can change this depending on how many tries you want to give the user
    cout << "*: a number is on the array but not in the right position\n";
    cout << "@: a number is not on the array\n";
    cout << "#: a number is on the right position\n";
    shuffle(sz_num);
//    for (int i=0;i<sz_ar;i++) cout << s[i] << " ";
    cout << "Numbers starting from 0-9: ";//you can change this
    cout << endl;
    int k=1;
    while (t>0) {
    	cout << k << ": ";
    	int cnt=answer();
        if (cnt==sz_ar) {
            cout << "\nYou Won!";
            break;
        }
        --t; 
        if (t==0) cout << "\nYou Lost!";
        cout << endl; 
        k++; 
    }
    cout << "\nAnswer: ";
    for (int i=0;i<sz_ar;i++) cout << s[i] << " ";
    return 0;
}
