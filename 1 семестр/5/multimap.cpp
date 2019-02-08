#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

struct Node{
    int fromList;
    string key;
    string x;
    Node *prew, *next, *last, *sled;

};

Node *curd[1000];
vector<pair<string,long> > nums[1000];

int hesh(string s3){
    int ans = 0;
    for (int i = 0; i< s3.length();i++)
        ans += s3[i]*(i+1);
    return ans%1000;
}

class List{

public:

    Node *Head, *Tail;
    long n = 0;

    List():Head(NULL),Tail(NULL){};

    void add(string k,string x,int curNum,int numList){

        Node *temp = Head;
        while (temp){
            if ((temp->key == k) && (temp->x == x)){

                temp->x = x;

                return;
            }
            temp = temp->next;
        }

        bool flag = true;
        for (long j = 0; j < nums[curNum].size();j++){
            if (nums[curNum][j].first == k){
                nums[curNum][j].second++;
                flag = false;
                break;
            }
        }
        if (flag){
            pair<string, long> rare;
            rare.first = k;
            rare.second = 1;
            nums[curNum].push_back(rare);
        }

        n++;
        Node *t = new Node;
        t->fromList = numList;
        t->next = NULL;
        t->key = k;
        t->x = x;

        t->last = curd[curNum];
        if (curd[curNum])
            t->last->sled = t;
        t->sled = NULL;
        curd[curNum] = t;

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

    void removeOnce(Node *temp){

        if (temp == curd[temp->fromList]){
            curd[temp->fromList] = curd[temp->fromList]->last;
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


        if (temp == Head){
            if (temp->next){

                Head = Head->next;
                Head->prew = NULL;
                n--;
                delete temp;
                return;
            }
            else{

                Head->next = NULL;
                Head = NULL;
                delete Head;
                n = 0;
                return;
            }
        }
        else{
            if(temp == Tail){

                Tail = Tail->prew;
                Tail->next = NULL;
                delete temp;
                n--;
                return;
            }
            else{

                temp->next->prew = temp->prew;
                temp->prew->next = temp->next;
                delete temp;
                n--;
            }
        }

    }

    void removeX(string key, string x,int curNum){

        long j = 0;

        Node *temp = Head;
        while (temp){
            if ((temp->key == key) && (temp->x == x)){

                for (long j = 0; j < nums[curNum].size();j++){
                    if (nums[curNum][j].first == key){
                        nums[curNum][j].second--;
                        break;
                    }
                }

                if (temp == curd[curNum]){
                    curd[curNum] = curd[curNum]->last;
                }

                if ((j ==0) && (temp->next)){
                    //temp->sled->last = temp->last;
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

class ListOfLists {

public:

    List lilHash[1000];

    void add(string key, string x,int curNum){
        int fun = hesh(x);
        lilHash[fun].add(key, x,curNum,fun);
    }

    void deleteOnce(string key, string x, int curNum){
        lilHash[hesh(x)].removeX(key,x,curNum);
    }

    void getX(string key,int curNum){
        Node *temp = curd[curNum];

        long ans = 0;

        for (int i = 0; i< nums[curNum].size();i++){
            if (nums[curNum][i].first == key){
                ans = nums[curNum][i].second;
                break;
            }
        }

        cout << ans << " ";

        long j = 0;

        while (temp && (j < ans)){
            if (temp->key == key){
                cout << temp->x << " ";
                j++;
            }
            temp = temp->last;
        }
        cout << endl;
    }

    void deleteAll(string key, int curNum){
        long col = 0;
        bool flag = false;
        for (int i = 0;i<nums[curNum].size();i++){
            if (nums[curNum][i].first == key){
                col = i;
                flag = true;
                break;
            }
        }

        Node *temp = curd[curNum];

        long j = 0;

        if (flag)
        while (temp && (j < nums[curNum][col].second)){
            if (temp->key == key){
                Node *udol = temp;
                temp = temp->last;
                lilHash[udol->fromList].removeOnce(udol);
                udol = NULL;
                delete udol;
                j++;
            }
            else
                temp = temp->last;
        }
        if (flag)
            nums[curNum][col].second = 0;
    }
};

ListOfLists bigHash[1000];

string s,s1,s2;

int main() {

    freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);

    while (cin >> s){
        if (s == "put"){
            cin >> s1 >> s2;
            int fun = hesh(s1);
            bigHash[fun].add(s1,s2,fun);
        }
        else{
            if (s == "delete"){
                cin >> s1 >> s2;
                int fun = hesh(s1);
                bigHash[fun].deleteOnce(s1, s2,fun);
            }
            else{
                if (s == "get"){
                    cin >> s1;
                    int fun = hesh(s1);
                    bigHash[fun].getX(s1,fun);
                }
                else{
                    cin >> s1;
                    int fun = hesh(s1);
                    bigHash[fun].deleteAll(s1, fun);
                }
            }
        }

    }
    return 0;
}
