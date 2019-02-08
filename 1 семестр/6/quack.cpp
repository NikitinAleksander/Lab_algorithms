#include<iostream>
#include<fstream>
#include<vector>
#include<map>

using namespace std;

void put(vector <unsigned short> &queue,int &n,unsigned short x){
  queue.insert(queue.begin(),x);
  n++;
}

void get(vector<unsigned short> &queue,int &n,unsigned short &x){
  x=queue[n];
  queue.pop_back();
  n--;
}

void _plus(vector<unsigned short> &queue,int &n){
  unsigned short a,b,result;
  get(queue,n,a);
  get(queue,n,b);
  result=a+b;
  put(queue,n,result);
}

void _minus(vector<unsigned short> &queue,int &n){
  unsigned short a,b,result;
  get(queue,n,a);
  get(queue,n,b);
  result=a-b;
  put(queue,n,result);
}

void _multiplication(vector<unsigned short> &queue,int &n){
  unsigned short a,b,result;
  get(queue,n,a);
  get(queue,n,b);
  result=a*b;
  put(queue,n,result);
}

void _div(vector<unsigned short> &queue,int &n){
  unsigned short a,b,result;
  get(queue,n,a);
  get(queue,n,b);
  result=a/b;
  put(queue,n,result);
}

void _mod(vector<unsigned short> &queue,int &n){
  unsigned short a,b,result;
  get(queue,n,a);
  get(queue,n,b);
  result=a%b;
  put(queue,n,result);
}

void _put_register(vector<unsigned short> &queue,int &n,unsigned short &_register){
  unsigned short x;
  get(queue,n,x);
  _register=x;
}

void _get_register(vector<unsigned short> &queue,int &n,unsigned short &_register){
  put(queue,n,_register);
}

void _P(vector<unsigned short> &queue,int &n){
  unsigned short x;
  get(queue,n,x);
  cout<<x<<endl;
}

void _P_register(vector<unsigned short> &queue,int &n,unsigned short &_register){
    cout<<_register<<endl;
}

void _C(vector<unsigned short> &queue,int &n){
  unsigned short x;
  get(queue,n,x);
  char a;
  a=x;
  cout<<a;
}

void _C_register(vector<unsigned short> &queue,int &n,unsigned short &_register){
  char a;
  a=_register;
  cout<<a;
}

void _put_label(map<string,unsigned short> &label,string s,int k){
  label[s]=k;
}

void _get_label(map<string,unsigned short> &label,string s,int &k){
  k=label[s];
}

int main(){
//1.объявляем все что нам понадобится
  map<string,unsigned short> label;
  vector <unsigned short> queue(100);
  int n=-1;
  unsigned short x,y;
  unsigned short _register[26];
  for(int i=0;i<26;i++){
    _register[i]=0;
  }
  string s;
  ifstream file ("quack.in");
  freopen("quack.out","w",stdout);
  int key=0;
  int temp=0;
//
//2.считываем все метки
  while(file>>s){
    temp++;
    key++;
    if(temp==1){
      key--;
    }
    if(s[0]==':'){
      s.erase(0,1);
      _put_label(label,s,key);
      key++;

    }
    key+=s.length()+1;
  }
  file.close();
  file.open("quack.in");
//
//3.делаем все остальное
  while(file>>s){
    if(s.length()==1){
      if(s[0]=='Q'){                        //"Q"
        return 0;
      }
      if(s[0]>='0'&&s[0]<='9'){             //[number]
        x=stoi(s);
        put(queue,n,x);
      }
      if(s[0]=='+'){                        //"+"
        _plus(queue,n);
      }
      if(s[0]=='-'){                        //"-"
        _minus(queue,n);
      }
      if(s[0]=='/'){                        //"/"
        _div(queue,n);
      }
      if(s[0]=='%'){                        //"%"
        _mod(queue,n);
      }
      if(s[0]=='*'){                        //"*"
        _multiplication(queue,n);
      }
      if(s[0]=='P'){                        //"P"
        _P(queue,n);
      }
      if(s[0]=='C'){                        //"C"
        _C(queue,n);
      }
    }else{
      if(s[0]>='0'&&s[0]<='9'){             //[number]
        x=stoi(s);
        put(queue,n,x);
      }
      if(s[0]=='>'){                        //">[register]"
        _put_register(queue,n,_register[s[1]-'a']);
      }
      if(s[0]=='<'){                        //"<[register]"
        _get_register(queue,n,_register[s[1]-'a']);
      }
      if(s[0]=='P'){                        //"P[register]"
        _P_register(queue,n,_register[s[1]-'a']);
      }
      if(s[0]=='C'){                        //"C[register]"
        _C_register(queue,n,_register[s[1]-'a']);
      }
      if(s[0]=='J'){                        //"J[label]"
        s.erase(0,1);
        _get_label(label,s,key);

        file.seekg(key,ios_base::beg);
      }
      if(s[0]=='Z'){                        //"Z[register][label]"
        if(_register[s[1]-'a']==0){
          s.erase(0,2);
          _get_label(label,s,key);
          file.seekg(key,ios_base::beg);
        }
      }
      if(s[0]=='E'){                        //"E[register1][register2][label]"
        if(_register[s[1]-'a']==_register[s[2]-'a']){
          s.erase(0,3);
          _get_label(label,s,key);
          file.seekg(key,ios_base::beg);
        }
      }
      if(s[0]=='G'){                        //"G[register1][register2][label]"
        if(_register[s[1]-'a']>_register[s[2]-'a']){
          s.erase(0,3);
          _get_label(label,s,key);
          file.seekg(key,ios_base::beg);
        }
      }
    }
  }
  file.close();
}
