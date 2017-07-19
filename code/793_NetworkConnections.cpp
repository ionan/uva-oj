#include <cstdio>
#include <vector>
using namespace std;

vector<int> parent, ranking;

int findSet(int i){
  return parent[i] == i ? parent[i] : findSet(parent[i]);
}

bool sameSet(int a, int b){
  return findSet(a) == findSet(b);
}

void setUnion(int a, int b){
  if (!sameSet(a, b)){
    int setA = findSet(a),
        setB = findSet(b);
    if (ranking[setA] > ranking[setB]){
      parent[setB] = setA;
    } else {
      parent[setA] = setB;
      if (ranking[setA] == ranking[setB]){
        ranking[setA]++;
      }
    }
  }
}

int main(){
  int testCases, computers, a, b;
  char action;
  int trash = scanf("%d\n", &testCases);
  while (testCases--){
    int trash = scanf("%d",&computers);
    while (getchar() != '\n');
    int success = 0, unsuccess = 0;
    parent.assign(computers, 0);
    ranking.assign(computers, 0);
    for (int i = 0; i < computers; i++){
      parent[i] = i;
    }
    char line[100];
    while(gets(line)  &&  sscanf(line, " %c %d %d", &action, &a, &b) == 3) {
      if (action == 'c'){
        setUnion(a - 1, b - 1);
      } else if (action == 'q'){
        sameSet(a - 1, b - 1) ? success++ : unsuccess++;
      }
    }
    printf("%d,%d\n", success, unsuccess);
    if (testCases >= 1) printf("\n");
  }
  return 0;
}
