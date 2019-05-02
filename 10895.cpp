#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;

vector<vector <ii> > vec;
vector<vector <ii> > adj;

void setRow(vi vIndex, vi vValue, int rowIndex){

    
    pair<int,int> tmp;

    for(int x=0; x<vIndex.size(); x++){
        tmp.first  = vIndex[x];
        tmp.second = vValue[x];
        vec[rowIndex].push_back(tmp);
    }
}

void printAnswer(int rows, int cols){

    vector<ii> answerRow;
    printf("%d %d\n", cols, rows);

    for(int a=0; a<adj.size(); a++){
        answerRow = adj[a];

        if(!answerRow.size()){
            printf("0\n\n");
        }
        else{
            printf("%d", answerRow.size());
            
            for(int c=0; c<answerRow.size(); c++){
                printf(" %d", answerRow[c].first + 1);
            }
            printf("\n");
            
            for(int d=0; d<answerRow.size(); d++){
                if(d < answerRow.size()-1)
                    printf("%d ", answerRow[d].second);
                else
                    printf("%d\n", answerRow[d].second);
            }
        }
    }
}

int main(){
    int rows, cols, noEmpty, val;
    vi vIndex, vValue;
    ii tmp, tmpA;
    string trash;

    while(scanf("%d %d", &rows, &cols) != EOF){
        vec.assign(rows, vector<ii>());
        adj.assign(cols, vector<ii>());

        for(int a=0; a<rows; a++){
            scanf("%d", &noEmpty);
            if(!noEmpty){
                getline(cin, trash);
                continue;
            }
            
            for(int b=0; b<noEmpty; b++){
                cin>>val;
                vIndex.push_back(val-1);
            }
            
            for(int b=0; b<noEmpty; b++){
                cin>>val;
                vValue.push_back(val);
            }
          
            setRow(vIndex, vValue, a);
            vIndex.clear();
            vValue.clear();
        }

        for(int x=0; x<vec.size(); x++){
            for(int y=0; y<vec[x].size(); y++){
                tmp = vec[x][y];
                tmpA.first = x;
                tmpA.second = tmp.second;
                adj[tmp.first].push_back(tmpA);
            }
        }
        printAnswer(rows,cols);
    }
return 0;
}
