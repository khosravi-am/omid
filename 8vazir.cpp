#include "iostream"
#include "vector"

using namespace std;


int is_safe(vector<int> Yvozara,int x,int y){
    for(int i=0;i<Yvozara.size();i++)
        if(Yvozara[i]!=-1 && (i==x || Yvozara[i]==y || abs(i-x)==abs(Yvozara[i]-y)))
            return 0;
    return 1;
}

void print(vector<vector <int>> map){
    for(auto& row :map){
        for(auto& col:row)
            cout << col << " ";
        cout << endl;
    }
}

void backTrack(vector<vector <int>>& map,vector <int>& stack_vozaraY,int& i,int &j,int& x){
        if (x==i-1)
            i-=1;
        map[i-1][stack_vozaraY[i-1]]=0;
        j=stack_vozaraY[i-1];
        stack_vozaraY[i-1]=-1;
        i-=1;
}


int main(){
    int n;
    cout << "enter map size : n>0"<<endl;
    cin >> n;
    vector<vector <int>> map(n,vector<int>(n));
    
    vector <int> stack_vozaraY(n,-1);

    int x,y;
    cout << "enter cordinate of first vazir: (0<x,y<8)" << endl;
    cin >> x >> y ;
 
    stack_vozaraY[x]=y;
    map[x][y]=1;
    for (int i = 0; i < map.size(); i++)
    {
        if(i!=x)
        for (int j = 0; j < map.size(); j++)
        {
            if (is_safe(stack_vozaraY,i,j))
            {
                stack_vozaraY[i]=j;
                map[i][j]=1;
                break;
            }
            if(j==map.size()-1)
            {
                backTrack(map,stack_vozaraY,i,j,x);
                
                if(j== map.size()-1 )
                    backTrack(map,stack_vozaraY,i,j,x);
            }
   
        }
        
    }
    print(map);
    

    return 0;
}