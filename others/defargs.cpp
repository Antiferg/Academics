#include <iostream>
using namespace std;

void printarray(string* A,int size) {
    for (int i=0;i<size;i++ ) {
        cout << A[i] << endl;
    }
}

void solution(string* A, string B)
{
    if (A->length() == 12) {
        *A = B + A->substr(2, 10);
    }
    else if (A->length() == 11) {
        *A = B + A->substr(1, 10);
    }
    else {
        *A = B + *A;
    }
}

int check(string* A)
{
    string B = "+91";
    if (A->length() == 10 || A->length() == 11 || A->length() == 12) {
        solution(A, B);
        return 1;
    }

    return 0;
}

int main()
{
    int N;
    cin >> N;
    string A[50];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for(string& a: A){
            check(&a);
    }
    printarray(A,N);
}
