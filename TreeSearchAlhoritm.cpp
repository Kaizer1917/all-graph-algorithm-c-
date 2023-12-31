#include <iostream>
#include <fstream>
 
 
using namespace std;
 
void creatFile(int maxCost, int kolVer, int **cost){

    int i,j;
    char name[50];
    cout<<"Введите название файла:";
    cin >> name;
    strcat(name, ".txt");
    ofstream out(name);
    out<<maxCost<<"\n";
    out<<kolVer<<"\n";  


for (i=1; i<=kolVer; i++)
{   
    for (j=1; j<=kolVer; j++)
    {   
        out<<cost[i][j]<<" ";
    }
    out<<"\n";
}
 
    out.close();
    cout<<"Файл создан\n";
};
void poiskMinOstDer(int maxCost, int kolVer, int **cost)
{       
    int min=maxCost;
    int minCost=0;
    int i,i2,i3,j,j2,j3,n,shet=1,iRebra=0;
    bool used[99]={false};
    used[1]=true;
    int rebro[99]={0};
    
    while (shet<kolVer)
    {
        for (i=1; i<=kolVer; i++)
        {
            for (j=1; j<=kolVer; j++)
            {
                if (cost[i][j]<min) 
                {
                    if (used[i]!=false)
                    {
                        min=cost[i][j];
                        i2=i3=i;
                        j2=j3=j;
                    }
                        if (used[j3]==false || used[j3]==false)
                        {
                            rebro[iRebra]=j2;
                            iRebra++;
                            shet++;
                            minCost=minCost+min;
                            used[j2]=true;
                        }
                    cost[i2][j2]=cost[j2][i2]=maxCost;
                }
            }
        }
    }
    cout<<1<<" --> ";
    for (i=0; i<kolVer-1; i++)
    {
        cout<<rebro[iRebra];
        if (i<kolVer-2){cout<<" --> ";}
    }
    cout<<"\n Минимальная стоимость: "<<minCost;
};
int main(){
setlocale (LC_ALL, "RUS");
int i,j;
int maxCost=100; 
int kolVer; 
int **cost;
cost = new int *[40];
for (i=0; i<40; i++){cost[i]=new int[40];}
 
 
cout<<"Введите максимальный вес ребра:\n";
cin>>maxCost;
cout<<"Введите количесто вершин графа:\n";
cin>>kolVer;
 

cout<<"Введите матрицу смежности:\n";
for (i=1; i<=kolVer; i++)
{
    for (j=1; j<=kolVer; j++)
    {
        cin>>cost[i][j];
        if (cost[i][j]==0)
        {cost[i][j]=maxCost;}
    }
}
 
creatFile(maxCost,kolVer,cost);
poiskMinOstDer(maxCost, kolVer, cost);
 
 
system("pause");
return 0;
};
