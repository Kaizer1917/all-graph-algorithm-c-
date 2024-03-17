
#include <iostream>
#include <queue>


int main(int argc, const char * argv[])
{
    int dl[] = {-1, 0, 1, 0}; 
    int dc[] = {0, 1, 0, -1};

    queue<int> X, Y; 

    X.push(start_x); 
    Y.push(start_y);

    void lee()
    {
      int x, y, xx, yy;
      while(!X.empty()) 
      {
        x = X.front(); 
        y = Y.front();
        for(int i = 0; i < 4; i++)
        {
          xx = x + dl[i]; 
          yy = y + dc[i];
          if('position is valid') 
          {
              X.push(xx); 
              Y.push(yy);
              mat[xx][yy] = -1; 
          }
          
        }
        
        X.pop(); 
        Y.pop();
        
      }


    }
}

