#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

bool cmp1(pii x, pii y) {
   return (x.first < y.first);
}

bool cmp2(pii x, pii y) {
   return (x.second > y.second);
}
void cetak(vector<pii> data) {
   for(int i=0; i<data.size(); i++)
      cout<<data[i].first<<","<<data[i].second<<endl;
}

int main() {
    vector<pii> data;
   
    data.push_back(pii(3,10));
    data.push_back(pii(5,30));
    data.push_back(pii(8,20));
    data.push_back(pii(4,40));
    cout<<"Urutan awal:"<<endl;
    cetak(data);
    sort(data.begin(), data.end(), cmp1);
    cout<<"Urutan sort by pertama (asc):"<<endl;
    cetak(data);
    sort(data.begin(), data.end(), cmp2);
    cout<<"Urutan sort by kedua (desc):"<<endl;
    cetak(data);

    return 0;
} 