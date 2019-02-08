#include<iostream>

using namespace std;

int family[200001];

int main(){
  int i;
  for(i=0;i<200001;i++){
    family[i]=0;
  }
  freopen("height.in","r",stdin);
  freopen("height.out","w",stdout);
  int n,x,l,r,h;
  cin>>n;
  h=0;
  if(n>0){
    h++;
  }
  for(i=1;i<=n;i++){
    cin>>x>>l>>r;
    if(l>0){
      family[l]=family[i]+1;
      if(family[l]==h){
        h++;
      }
    }

    if(r>0){
      family[r]=family[i]+1;
      if(family[r]==h){
        h++;
      }
    }

  }
  cout<<h;
}
