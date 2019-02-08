#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

long easyNumber = 9883;

struct Node{

long x;
Node *prew, *next;

};

class List{
    Node *Head, *Tail;
    long n = 0;

    public: List():Head(NULL),Tail(NULL){};

    void add(long x){

        Node *temp = Head;
        while (temp){
            if ( temp->x == x){
                return;
            }
            temp = temp->next;
        }

        n++;
        Node *t = new Node;
        t->next = NULL;
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

    bool exist(long x){

        Node *temp = Head;
        while (temp){
            if ( temp->x == x){
                return true;
            }
            temp = temp->next;
        }

        return false;

    }

    void removeX(long x){

        long j = 0;

        Node *temp = Head;
        while (temp){
            if ( temp->x == x){

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
        Node *temp = Head;
        bool f = false;
        while (temp){
            cout << temp->x << " ";
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

List a[119993];

string s;

int hesh(long key){

    return abs(key % 119993);
}

long x;

int main(){


    ifstream fin("set.in");
    ofstream fout("set.out");

    while (fin >> s){

        if (s[0] == 'i'){
            fin >> x;
            a[hesh(x)].add(x);
        }
        else{
            if (s[0] == 'e' ){
                fin >> x;

                if (a[hesh(x)].exist(x)){
                    fout << "true" << endl;
                }
                else{
                    fout << "false" << endl;
                }

            }
            else{
                fin >> x;
                a[hesh(x)].removeX(x);
            }
        }
    }
 
    return 0;
}
