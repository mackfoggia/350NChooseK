#include <iostream>
using namespace std;



int choose(int n, int k);
int chooseM(int n, int k, int **);
int chooseT(int n, int k, int **);


int main(int argc, char * argv[]){
  int n = atoi(argv[1]);
  int k = atoi(argv[2]);
  
  int ** T = new int *[n+1];
  int ** T2 = new int *[n+1];
  for(int i = 0; i < n+1; ++i){
    T[i] = new int[k+1];
    T2[i] = new int[k+1];
    for(int j = 0; j < k+1; ++j){
      T[i][j] = -1;
      T2[i][j] = 0;
    }
  }

  cout << n << " choose " << k << ": " << choose(n, k) << endl;
  cout << n << " chooseM " << k << ": " << chooseM(n, k, T) << endl;
  cout << n << " chooseT " << k << ": " << chooseT(n, k, T2) << endl;
  
  return 0;
}




int choose(int n, int k){
  if(k == 1) return n;
  if(n == k) return 1;

  return choose(n-1, k-1) + choose(n-1, k);
}


int chooseM(int n, int k, int ** T){
  if(k == 1) return n;
  if(n == k) return 1;
  
  if(T[n][k] == -1) 
    T[n][k] = choose(n-1, k-1) + choose(n-1, k);
  
  return T[n][k];
}



int chooseT(int n, int k, int ** T2){
  for(int a = 0; a <= n; ++a){
    for(int count = 0; count < a + 1; ++count){
      if(count == 0) T2[a][count] = 1;
      else if(count > a) T2[a][count] = 1;
      else T2[a][count] = T2[a-1][count] + T2[a-1][count-1];
      //cout << T2[a][count] << ' ';
    }
    //cout << endl;
  }
  return T2[n][k];
}
