#include <iostream>
#include <map>
#include <cstring>
#include <vector>
using namespace std;

void print(int adjacency [20][20],vector<int> deletedIndices, int numVertex, char names [20]);
void setEdge(int (& adjacency)[20][20], char names[20], vector<int> deletedIndices, int target);
int findShortest(int adjacency[20][20], char names[20], int firstIndex, int secondIndex, int distances[20], int indexesUsed[20], int shortestDistance, int count);
int main(){
  bool stillRunning = true;
  int numVertex = 0; 
      
  int adjacency [20][20];
  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 20; j++){
      adjacency[i][j] = 0;
    }
  }
  vector<int> deletedIndices;


  while(stillRunning == true){
    cout << "What would you like to do? ADDVERTEX, ADDEDGE, REMOVEVERTEX, REMOVEEDGE, PRINT, FINDSHORTEST, or QUIT" << endl;
    char names [20];
    char choice[50];
    cin.get(choice, 50);
    cin.get();

    if(strcmp(choice, "ADDVERTEX") == 0){
      cout << "Enter a letter that will serve as the name for this vertex" << endl;
      char name;
      cin >> name;
      cin.get();
      if(deletedIndices.empty() == false){
        int tempIndex = deletedIndices.back();
        deletedIndices.pop_back();
        names[tempIndex] = name;
      }
      else{
        names[numVertex] = name;
        cout << names[0] << endl;
        numVertex++;
      }
    }
    else if(strcmp(choice, "ADDEDGE") == 0){
      cout << "What value would you like the edge to have? " << endl;
      int target;
      cin >> target;
      cin.get();
      setEdge(adjacency, names, deletedIndices, target);
    }
    else if(strcmp(choice, "REMOVEVERTEX") == 0){
      cout << "Which vertex would you like to remove? " << endl;
      char deletedVertex;
      cin >> deletedVertex;
      cin.get();
      int charExists = -1;
      for(int i = 0; i < 20; i++){
        if(names[i] == deletedVertex){
          charExists = i;
        }
      }
      if(charExists != -1){
        deletedIndices.push_back(charExists);
        for(int i = 0; i < 20; i++){
          for(int j = 0; j < 20; j++){
            if(i == charExists || j == charExists){
              adjacency[i][j] = 0;
            }
          }
        }
      }
      else{
        cout << "That vertex name does not exist" << endl;
      }
    }
    else if(strcmp(choice, "REMOVEEDGE") == 0){
      setEdge(adjacency, names, deletedIndices, 0);
    }
    else if(strcmp(choice, "FINDSHORTEST") == 0){
      cout << "What is the starting node: " << endl;
      char first;
      cin >> first;
      cin.get();
      cout << "What is the ending node: " << endl;
      char second;
      cin >> second;
      cin.get();
      bool firstMatch = false;
      bool secondMatch = false;
      int firstIndex;
      int secondIndex;
      for(int i = 0; i < 20; i++){
        if(names[i] == first && count(deletedIndices.begin(), deletedIndices.end(), i) == 0){
          cout << "FIRST: " << i << endl;
          firstMatch = true;
          firstIndex = i;
        }
        if(names[i] == second && count(deletedIndices.begin(), deletedIndices.end(), i) == 0){
          cout << "SECOND: " << i << endl;
          secondMatch = true;
          secondIndex = i;
        }
      }
      if(firstMatch == true && secondMatch == true){
        int indexesUsed[20];
        for(int i = 0; i < 20; i++){
          indexesUsed[i] = 0;
        }
        int distances[20];
        for(int i = 0; i < 20; i++){
          distances[i] = 0;
        }
        int shortestDistance = 0;
        int count = 0;
        shortestDistance = findShortest(adjacency, names, firstIndex, secondIndex, distances, indexesUsed, shortestDistance, count);
        if(shortestDistance == 0){
          cout << "No such path exists" << endl;
        }
        else{
          cout << "The shortest distance between those two nodes is " << shortestDistance << endl;
        }
      }
      else{
        cout << "One or both of those edges was invalid" << endl;
      }
    }
    else if(strcmp(choice, "PRINT") == 0){
      print(adjacency, deletedIndices, numVertex, names);
    }
    else if(strcmp(choice, "QUIT") == 0){
      stillRunning = false;
    }
    
  }


}

int findShortest(int adjacency[20][20], char names[20], int firstIndex, int secondIndex, int distances [20], int indexesUsed[20], int shortestDistance, int count){
  cout << "Entering" << endl;
  cout << firstIndex << endl;
  cout << secondIndex << endl;
  if(count == 0){
    cout << "First go round" << endl;
    for(int j = 0; j < 20; j++){
      if(adjacency[j][firstIndex] != 0){
        distances[j] = adjacency[j][firstIndex];
        cout << "J: " << j << endl;
      }
    }
    cout << "OUT" << endl;
    indexesUsed[firstIndex] = 1;
    count++;
    shortestDistance = findShortest(adjacency, names, firstIndex, secondIndex, distances, indexesUsed, shortestDistance, count);
    return shortestDistance;
  }
  else{
    int temp = 0;
    int iter = 0;
    while((iter < 20 && (distances[iter] == 0 || indexesUsed[iter] != 0))){
      iter++;
      cout << "ITERATOR: " << iter << endl;
      cout << "DIST: " << distances[iter] << endl;
      cout << "INDEXUSED: " << indexesUsed[iter] << endl;
    }
    temp = distances[iter];
    cout << "ITER: " << iter << endl;
    if(iter == 20){
      shortestDistance = distances[secondIndex];
      return shortestDistance;
    }
    for(int i = 0; i < 20; i++){
      if(distances[i] < temp && distances[i] != 0 && indexesUsed[i] == 0){
        temp = distances[i];
        iter = i;
      }
    }
    for(int j = 0; j < 20; j++){
      if(adjacency[j][iter] != 0){
        if(distances[j] == 0 || distances[j] > (distances[iter] + adjacency[j][iter])){
          cout << "JHERE: " << j << endl;
          cout << distances[iter] << "DIST" << endl;
          cout << adjacency[j][iter] << "HEREWEGO" << endl;
          distances[j] = adjacency[j][iter] + distances[iter];
        }
      }
    }
    cout << "ITERHERE: " << iter << endl;
    indexesUsed[iter] = 1;
    count++;
    shortestDistance = findShortest(adjacency, names, firstIndex, secondIndex, distances, indexesUsed, shortestDistance, count);
    return shortestDistance;
  }
  
  
}

void setEdge(int (& adjacency)[20][20], char names[20], vector<int> deletedIndices, int target){
      cout << "Enter the first letter of the edge: " << endl;
      char first;
      cin >> first;
      cin.get();
      cout << "Enter the second letter of the edge: " << endl;
      char second;
      cin >> second;
      cin.get();
      bool firstMatch = false;
      bool secondMatch = false;
      int firstIndex;
      int secondIndex;
      for(int i = 0; i < 20; i++){
        if(names[i] == first && count(deletedIndices.begin(), deletedIndices.end(), i) == 0){
          cout << "FIRST: " << i << endl;
          firstMatch = true;
          firstIndex = i;
        }
        if(names[i] == second && count(deletedIndices.begin(), deletedIndices.end(), i) == 0){
          cout << "SECOND: " << i << endl;
          secondMatch = true;
          secondIndex = i;
        }
      }
      if(firstMatch == true && secondMatch == true){
 
        adjacency[secondIndex][firstIndex] = target;

        cout << adjacency[0][1] << endl;
      }
      else{
        cout << "One or both of those edges was invalid" << endl;
      }
      cout << adjacency[0][1] << endl;

}

void print(int adjacency [20][20], vector<int> deletedIndices, int numVertex, char names[20]){
  cout << "HI" << endl;
  for(int i = 0; i < numVertex; i++){
    if(count(deletedIndices.begin(), deletedIndices.end(), i) == 0){
      cout << names[i] << "   ";
    }
  }
  cout << endl;
  for(int i = 0; i < numVertex; i++){
    if(count(deletedIndices.begin(), deletedIndices.end(), i) == 0){
      for(int j = 0; j < numVertex; j++){
        if(count(deletedIndices.begin(), deletedIndices.end(), j) == 0){
          cout << adjacency[i][j] << "   ";
        }
      }
    
      cout << endl;
    }
  }


}
