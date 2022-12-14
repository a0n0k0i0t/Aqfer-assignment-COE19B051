#include<iostream>
#include<queue>
using namespace std;
#define ll long long

#define ll long long
int main(int argc, char*argv[]){
    int r=atoi(argv[1]);
    int s=atoi(argv[2]);

    queue<ll> qu;
    for(int i=3;i<argc;i++){
        ll cur=atoi(argv[i]);
        if(qu.size()<r){  //if currently less than R timestamp allowed in window
            cout<<cur<<" allowed\n";
            qu.push(cur);
        }
        else{
            if(qu.size()>0 && cur > qu.front()+s){ // if cur_timestamp is outside window
                cout<<cur<<" allowed\n";
                qu.pop();
                qu.push(cur);
            }
            else{
                cout<<cur<<" blocked\n";
            }
        }
    }
    return 0;
}