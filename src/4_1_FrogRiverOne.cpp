#include <vector>
#include <iostream>

using namespace std;

int solution(int X, vector<int> &A) {
    vector<bool> seen(A.size(),false);
    
    int tot = 0;
    for(int i=0; i<A.size(); i++){
        if( A[i] <= X && (seen[A[i]-1] == false) ){
            seen[A[i]-1] = true;
            tot++;
            if (tot == X){
                return i;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> v{1,2,5,6,3,0};
    cout << solution(6, v);
    return 0;
}