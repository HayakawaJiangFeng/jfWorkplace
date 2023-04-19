#include<iostream>
using namespace std;
int n,k,sum;
int ans;
int a[100];
void dfs(int s,int pos ,int cnt){
	if(s>sum||cnt>k){
		return ;
	}
	if(cnt==k&&s==sum){
		ans++;
		return ;
	}
	for(int i=pos;i<n;i++){
		dfs(s+a[i],i+1,cnt+1);
	}
}
int main(){
	cin>>n>>k>>sum;
	for(int i=0;i<n;i++){
		a[i]=i+1;
	}
	dfs(0,0,0);
	cout<<ans<<endl;
	return 0;
} 