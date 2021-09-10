#include <iostream>
#include <cstdio>
using namespace std;
struct mhs 
{
    char nim[10];
    int usia, jenkel;
    float ip;
};
typedef struct mhs MHS;
int main() 
{
    MHS dt={"G64189250",19,1,2.75};
    MHS arr[]={{"G64189250",19,1,2.75}, {"G64181234",20,2,3.85}};
    MHS *p=&dt;
    MHS q=arr[1];
    cout << dt.nim << " " << dt.usia << endl;
    cout << p->nim << " " << p->usia << endl;
    cout << q.nim << " " << q.usia << endl;
    return 0;
}