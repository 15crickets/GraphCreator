#include <iostream>
#include <cstring>

using namespace std;

void print(int adjacency [20][20], int numVertex);

int main(){
  bool stillRunning = true;
  
  while(stillRunning == true){
    cout << "What would you like to do? ADDVERTEX, ADDEDGE, REMOVEVERTEX, or REMOVEEDGE" << endl;
    char choice[50];
    cin.get(choice, 50);
    cin.get();
    int adjacency [20][20] = new int [][];
    for(int i = 0; i < 20; i++){
      for(int j = 0; j < 20; j++){
	adjacency[i][j] = 0;
      }
    }
    int numVertex = 0;
    if(strcmp(choice, "ADDVERTEX") == 0){
      numVertex++;
    }
    else if(strcmp(choice, "ADDEDGE") == 0){

    }
    else if(strcmp(choice, "REMOVEVERTEX") == 0){

    }
    else if(strcmp(choice, "REMOVEEDGE") == 0){

    }
    
  }


}
