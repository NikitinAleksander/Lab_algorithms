#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

long easyNumber = 9883;

struct Node{

string key;
string x;
Node *prew, *next;

};

class List{
    Node *Head, *Tail;
    long n = 0;

    public: List():Head(NULL),Tail(NULL){};

    void add(string k,string x){

        Node *temp = Head;
        while (temp){
            if ( temp->key == k){

                    temp->x = x;

                return;
            }
            temp = temp->next;
        }

        n++;
        Node *t = new Node;
        t->next = NULL;
        t->key = k;
        t->x = x;
        if (Head != NULL){
            t->prew = Tail;
            Tail->next = t;
            Tail = t;
        }
        else{
            t->prew = NULL;
            Head = Tail = t;
        }
    }

    string exist(string k){

        string ans = "!";

        Node *temp = Head;
        while (temp){
            if ( temp->key == k){
                return temp->x;
            }
            temp = temp->next;
        }

        return ans;

    }

    void removeX(string k){

        long j = 0;

        Node *temp = Head;
        while (temp){
            if ( temp->key == k){

                if ((j ==0) && (temp->next)){
                    Head = Head->next;
                    Head->prew = NULL;
                    delete temp;
                    n--;
                    return;
                }
                else{
                    if ((j == 0) && (Head == Tail)){
                        Head->next = NULL;
                        Head = NULL;
                        delete Head;
                        n = 0;
                        return;
                    }
                }
                if (j == n-1){
                    Tail = Tail->prew;
                    Tail->next = NULL;
                    delete temp;
                    n--;
                    return;
                }

                temp->next->prew = temp->prew;
                temp->prew->next = temp->next;
                delete temp;
                n--;

                return;
            }
            j++;
            temp = temp->next;
        }

    }

    void showList(){
        //cout << "showList"<<endl;
        Node *temp = Head;
        bool f = false;
        while (temp){
            cout <<"("<< temp->key <<" - "<<temp->x <<"), ";
            temp = temp->next;
            f = true;
        }
        if (f)
            cout << endl;

    }

    ~List(){
        while (Head){
            Tail = Head->next;
            delete Head;
            Head = Tail;
        }
    }

};

List a[100000];

string s,s1,s2;

int hesh(string s3){
    int ans = 0;
    for (int i = 0; i< s3.length();i++)
        ans += s3[i]*(i+1);
    return ans;
}

long x;

int main(){

    //freopen("set.in", "r", stdin);
    //freopen("set.out", "w", stdout);
    ifstream fin("map.in");
    ofstream fout("map.out");


    //lst.showList();

    while (fin >> s){
        if (s[0] == 'p'){
            fin >> s1 >> s2;
            //cout << hesh(s1) << endl;
            a[hesh(s1)].add(s1,s2);
        }
        else{
            if (s[0] == 'g'){

                fin  >> s1;

                string t = a[hesh(s1)].exist(s1);
                if (t != "!"){
                    fout << t << endl;
                }
                else{
                    fout << "none" << endl;
                }

            }
            else{
                fin >> s1;
                a[hesh(s1)].removeX(s1);
            }
        }
    }


    return 0;
}
