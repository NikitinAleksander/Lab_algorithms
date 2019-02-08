#include <iostream>
#include <fstream>

using namespace std;

struct node
{
    int k;
    int l;
    int r;
};

void _check(struct node *a, int i, bool &check, int min, int max)
{
    if((a[i].k < max)&&(a[i].k > min))
    {
        if(a[i].l!=0){
            _check(a,a[i].l-1,check,min,a[i].k);
          }
        if(a[i].r!=0){
            _check(a,a[i].r-1,check,a[i].k,max);
          }
    }
    else check = false;
}

int main()
{
    ifstream in("check.in");
    ofstream out("check.out");
    bool check = true;
    struct node *a;
    int n;
    in >> n;
    a = new struct node[n];
    for(int i = 0; i < n; i++){
        in >> a[i].k >> a[i].l >> a[i].r;
      }
    if(n!=0) {
      _check(a,0,check,-1000000001,1000000001);
    }
    if(check){
        out << "YES";
      }else{
        out << "NO";
      }
    out.close();
    in.close();
}
