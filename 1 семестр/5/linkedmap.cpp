#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Node{

string key;
string x;
Node *prew, *next, *last, *sled;

};

Node *cur = NULL;

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

        t->last = cur;
        if (cur)
        t->last->sled = t;
        t->sled = NULL;
        cur = t;

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

    string prev(string k){
        string ans = "none";

        Node *temp = Head;
        while (temp){
            if ((temp->key == k)&&(temp->last)){
                return temp->last->x;
            }
            temp = temp->next;
        }

        return ans;
    }

    string next(string k){
        string ans = "none";

        Node *temp = Head;
        while (temp){
            if ((temp->key == k)&&(temp->sled)){
                return temp->sled->x;
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

                if (temp == cur){
                    cur = cur->last;
                }

                if ((j ==0) && (temp->next)){
                    if (temp->last){
                        if (temp->sled){
                            temp->last->sled = temp->sled;
                        }
                        else{
                            temp->last->sled = NULL;
                        }
                    }
                    if (temp->sled){
                        if (temp->last){
                            temp->sled->last = temp->last;
                        }
                        else{
                            temp->sled->last = NULL;
                        }
                    }
                    Head = Head->next;
                    Head->prew = NULL;
                    delete temp;
                    n--;
                    return;
                }
                else{
                    if ((j == 0) && (Head == Tail)){

                        if (temp->last){
                            if (temp->sled){
                                temp->last->sled = temp->sled;
                            }
                            else{
                                temp->last->sled = NULL;
                            }
                        }
                        if (temp->sled){
                            if (temp->last){
                                temp->sled->last = temp->last;
                            }
                            else{
                                temp->sled->last = NULL;
                            }
                        }

                        Head->next = NULL;
                        Head = NULL;
                        delete Head;
                        n = 0;
                        return;
                    }
                }
                if (j == n-1){

                    if (temp->last){
                        if (temp->sled){
                            temp->last->sled = temp->sled;
                        }
                        else{
                            temp->last->sled = NULL;
                        }
                    }
                    if (temp->sled){
                        if (temp->last){
                            temp->sled->last = temp->last;
                        }
                        else{
                            temp->sled->last = NULL;
                        }
                    }

                    Tail = Tail->prew;
                    Tail->next = NULL;
                    delete temp;
                    n--;
                    return;
                }

                if (temp->last){
                        if (temp->sled){
                            temp->last->sled = temp->sled;
                        }
                        else{
                            temp->last->sled = NULL;
                        }
                    }
                    if (temp->sled){
                        if (temp->last){
                            temp->sled->last = temp->last;
                        }
                        else{
                            temp->sled->last = NULL;
                        }
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
    ifstream fin("linkedmap.in");
    ofstream fout("linkedmap.out");

    while (fin >> s){
        if (s == "put"){
            fin >> s1 >> s2;

            a[hesh(s1)].add(s1,s2);
        }
        else{
            if (s == "get"){

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
                if (s == "delete"){
                    fin >> s1;
                    a[hesh(s1)].removeX(s1);
                }
                else{
                    if (s == "prev"){
                        fin >> s1;
                        fout << a[hesh(s1)].prev(s1) << endl;
                    }
                    else{
                        fin >> s1;
                        fout << a[hesh(s1)].next(s1) << endl;
                    }
                }
            }
        }
    }
    return 0;
}
