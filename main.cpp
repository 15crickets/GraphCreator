#include <iostream>
#include <cstring>

using namespace std;

void print(int adjacency [20][20], int numVertex, char names [20]);

int main(){
  bool stillRunning = true;
  
  while(stillRunning == true){
    cout << "What would you like to do? ADDVERTEX, ADDEDGE, REMOVEVERTEX, REMOVEEDGE, PRINT, or QUIT" << endl;
    char names [20];
    char choice[50];
    cin.get(choice, 50);
    cin.get();
    int adjacency [20][20];
    for(int i = 0; i < 20; i++){
      for(int j = 0; j < 20; j++){
	adjacency[i][j] = 0;
      }
    }
    int numVertex = 0;
    if(strcmp(choice, "ADDVERTEX") == 0){
      cout << "Enter a letter that will serve as the name for this vertex" << endl;
      char name;
      cin >> name;
      cin.get();
      names[numVertex] = name;
      numVertex++;
    }
    else if(strcmp(choice, "ADDEDGE") == 0){

    }
    else if(strcmp(choice, "REMOVEVERTEX") == 0){

    }
    else if(strcmp(choice, "REMOVEEDGE") == 0){

    }
    else if(strcmp(choice, "PRINT") == 0){
      print(adjacency, numVertex, names);
    }
    else if(strcmp(choice, "QUIT") == 0){
      stillRunning = false;
    }
    
  }


}


void print(int adjacency [20][20], int numVertex, char names[20]){
  for(int i = 0; i < numVertex; i++){
    cout << names[i] << "   ";
  }
  cout << endl;
  for(int i = 0; i < numVertex; i++){
    for(int j = 0; j < numVertex; j++){
      cout << adjacency[i][j] << "   ";
    }
    cout << endl;
    
  }


}
