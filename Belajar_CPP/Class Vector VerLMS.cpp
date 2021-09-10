#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
class myData
{
    private:
        vector<int> list;
    public:
        myData() { list.clear(); }   // default constructor
        void setAllData();
        int getSize() { return list.size(); }
        double getAvg();
        void del();
};

int main()
{
    myData obj;
    cout.precision(2);
    obj.setAllData();
    int nAwal=obj.getSize();
    double rAwal=obj.getAvg();
    obj.del();
    cout << nAwal << " " << obj.getSize() << endl;
    cout << fixed << rAwal << " " << obj.getAvg() << endl; 
    return 0;
}
void myData::setAllData() 
{
    int nilai;
    cin >> nilai;
    while (nilai!=-9)
    {
        list.push_back(nilai);
        cin >> nilai;
    }
}
double myData::getAvg()
{
    int sum=0;
    double rataan;
    if (list.size()!=0)
    {
        for(int i=0; i<list.size();i++) sum+=list[i];
        rataan=(double)sum/list.size();
    } else rataan=-9.99;
    return rataan;
}
void myData::del() {
    int pos, now=0;
    cin >> pos;
    while (pos!=-9)
    {
        pos-=(now++);
        if (pos<=list.size()) {
            --pos;
            list.erase (list.begin()+pos);
        }
        cin >> pos;
    }            
}