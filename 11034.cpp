#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main()
{
        int laps , l, m, c, car, load;
        string bank;
        bool rightBank;
       
        cin >> c;
       
        for (int i = 0; i < c; i++){
                cin >> l >> m;
               
                queue<int>Left, Right;
                load = 0;
                rightBank = 0;
                for (int j = 0; j < m; j++){
                        cin >> car >> bank;
                        if (bank == "left")
                                Left.push(car);
                        else
                                Right.push(car);
                }
                laps = 0;  l *= 100;  
                while (!Left.empty() || !Right.empty()){
               
                       
                        load = 0;
                        if (rightBank){
                                while (!Right.empty() && load + Right.front() <= l)
                                {
                                        load += Right.front(); Right.pop();
                                }
                        }
                        else{
                                while (!Left.empty() && load + Left.front() <= l)
                                {
                                        load += Left.front(); Left.pop();
                                }
                        }
                        ++laps;
                        rightBank = 1 - rightBank;
                }
               
                cout << laps << endl;          
        }
        return 0;
}
