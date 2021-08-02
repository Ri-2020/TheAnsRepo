#include <bits/stdc++.h>
using namespace std;

class Keyset{
    public:
    string date;
    long num;
};

class ansSet{
    public:
    string theDay;
    long sum;
};

string weekday[] = {"Sat", "Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" };

int getDay(string date){

    int dd = stoi(date.substr(8,2));
    int mm = stoi(date.substr(5,2));
    int century = stoi(date.substr(0,2));
    int year = stoi(date.substr(2,2));
    if(mm<=2){ 
        mm+=12;
        year--;
    }

    int ans = (dd + floor((13*(mm+1))/5) + year + floor(year/4) + floor(century/4) + (5*century));
    ans = ans%7;
    return ans;
}

void printAns(vector<Keyset> keys){

    vector<ansSet> ans(7);

    for(int i=1 ; i<=7 ; i++){

        if(i==7){
            ans[i-1].theDay = weekday[0];
            ans[i-1].sum = 0;
            continue;
        }
        ans[i-1].theDay = weekday[i];
        ans[i-1].sum = 0;
    }

    for(int i=0 ; i<8 ; i++){
        int wd = getDay(keys[i].date);
        if(wd == 0){
            ans[6].sum+=keys[i].num;
        }
        else{
            ans[wd-1].sum+=keys[i].num;
        }
    }

    for(int i=0 ; i<7 ; i++){
        cout<<ans[i].theDay<<": "<<ans[i].sum<<endl;
    }
}

int main()
{
    vector<Keyset> keys(8);
    // create given test set 
    keys[0].date = "2020-01-01"; keys[0].num = 4;
    keys[1].date = "2020-01-02"; keys[1].num = 4;
    keys[2].date = "2020-01-03"; keys[2].num = 6;
    keys[3].date = "2020-01-04"; keys[3].num = 8;
    keys[4].date = "2020-01-05"; keys[4].num = 2;
    keys[5].date = "2020-01-06"; keys[5].num = -6;
    keys[6].date = "2020-01-07"; keys[6].num = 2;
    keys[7].date = "2020-01-08"; keys[7].num = -2;
    printAns(keys);
    return 0;
}