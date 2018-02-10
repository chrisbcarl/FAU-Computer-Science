
#include<iostream>
#include <time.h>

using namespace std;




//THIS IS A PRINTING FUNCTION FOR 1D ARRAYS
void printArray(int *C, int n)
{
    cout<<"Printing 1D"<<endl;
    for(int i = 0; i < n; i++)
    {
            cout << C[i] << " ";
    }
    cout<<endl;
}


//THIS IS A PRINTING FUNCTION FOR 2D ARRAYS
void test(int **C, int n, int m)
{
    int i,j;
    cout<<"Test is called"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


//THIS FUNCTION MAKES NEW 2D ARRAYS TO TEST WITH
void test2(int **A, int n1, int m1, int **B, int *n2, int *m2)
{
    int i,j;
    *n2= n1;
    *m2 = m1;
    
    
    for (i=0;i<n1;i++)
        for(j=0;j<m1;j++)
            B[i][j] = A[i][j]+1;
    
}







int dotproduct(int *A, int sizeA, int *B, int sizeB)
{
    cout<<"Dot product is called"<<endl;
    cout<<"Vector A: " << endl; printArray(A, sizeA);
    cout<<"Vector B: " << endl; printArray(B, sizeB);
    
    cout << endl << endl;
    if (sizeA == sizeB)
    {
        int sum = 0;
        for (int i = 0; i < sizeA; i++)
        {
            sum += A[i]*B[i];
        }
        
        return sum;
    }
    else
        return -1;
}



void test3(int **A, int n1, int m1, int **B, int n2, int m2, int **C, int &n3, int &m3)
{
    int i,j;
    n3= n1;
    m3 = m2;
    
    //for each row in C
    for (i=0;i<n1;i++)
    {
        //and each column in that row
        for(j=0;j<m1;j++)
        {
            //make a temporary array that represents B's column
            int Bcolumn[n2];
            for (int x = 0; x < n2; x++) {
                Bcolumn[x] = B[x][j];
            }
    
            C[i][j] = dotproduct(A[i], m1, Bcolumn, n2);
        }
    }
}



//THIS FUNCTION MAKES NEW 2D ARRAYS TO TEST WITH
void matrixproduct(int **A, int n1, int m1, int **B, int n2, int m2, int **C, int &n3, int &m3)
{
    //for this to work, m1 == n2, and
    //A, which is a [n1 x m1] size matrix, with
    //B, which is a [n2 x m2] size matrix, COMBINE to make
    //C, which is a [n1 x m2] size matrix, so set n3 = n1, and m3 = m2.
    
    /*
     the idea is:
     
     make C filled with good data
     
     
     */
    
    
    
    int i,j;
    n3 = n1;
    m3 = m2;
    
    
    for (i=0;i<n1;i++)
        for(j=0;j<m1;j++)
            B[i][j] = A[i][j]+1;
    
}


int func_main()
{
    
    int n1= 4, m1 =5;
    int A[4][5]= {{1,2,3},
        {4,5,6},
        {7,8},
        {9,10,11,12,13}};
    int i,j;
    
    //THIS IS A PRINTING FUNCTION
    //for each row
    for(i=0;i<n1;i++)
    {
        //for each column in that row
        for(j=0;j<m1;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    
    //let's make a new empty 2D array
    int **B;
    B = new int *[n1];
    
    for(i =0 ; i< n1 ;i++)
    {
        //let's fill it with empty rows
        B[i] = new int [m1];
    }
    
    
    //fill B with everything in A.
    //B = A will make a shallow copy
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m1;j++)
        {
            B[i][j] = A[i][j];
        }
    }
    
    
    //let's make a new pointer that doesn't point to anything yet.
    int **C;
    int n2,m2;
    
    
    //A PRINTING FUNCTION
    test(B,n1,m1);
    
    //assign that lonely pointer to an empty 2D array
    C = new int *[n1];
    for(i=0;i<n1;i++){
        //fill that 2D array with empty rows
        C[i] = new int [m1];
    }
    
    //LETS PRINT A NON-initialized array
    test(C,n2,m2);
    
    
    
    //makes C have new, valid data
    test2(B,n1,m1, C, &n2,&m2);
    
    
    //print C
    test(C,n2,m2);
    
    
    
    int vector1[5] = {0, 1, 2, 3, 4};
    int vector2[5] = {6, 7, 8, 9, 0};
    
    int dot = dotproduct(vector1, 5, vector2, 5);
    
    cout << "dotproduct of vector1 and vector2 = " << dot << endl;
    
    int n3, m3;
    
    
    
    
    
    
    //assign that lonely pointer to an empty 2D array
    int **F;
    F = new int *[n1];
    for(i=0;i<n1;i++){
        //fill that 2D array with empty rows
        F[i] = new int [m1];
    }
    
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m1;j++)
        {
            F[i][j] = A[i][j];
        }
    }
    
    //won't work with A in front, same concepts as the G thing since A is explicitly sized
    test3(F, n1, m1, B, n2, m2, C, n3, m3);
    
    //print C
    
    test(F,n1,m1);
    test(B,n2,m2);
    test(C,n3,m3);
    
    
    
    n1 = 4;
    m1 = 3;
    n2 = 3;
    m2 = 5;
    
    
    srand (unsigned (time(NULL)));
    
    //assign that lonely pointer to an empty 2D array
    int **X;
    X = new int *[n1];
    for(i=0;i<n1;i++){
        //fill that 2D array with empty rows
        X[i] = new int [m1];
    }
    
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m1;j++)
        {
            X[i][j] = rand() % 10 + 1;
        }
    }
    
    
    //assign that lonely pointer to an empty 2D array
    int **Y;
    Y = new int *[n2];
    for(i=0;i<n1;i++){
        //fill that 2D array with empty rows
        Y[i] = new int [m2];
    }
    
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m1;j++)
        {
            Y[i][j] = rand() % 10 + 1;
        }
    }
    
    //assign that lonely pointer to an empty 2D array
    int **Z;
    Z = new int *[n1];
    for(i=0;i<n1;i++){
        //fill that 2D array with empty rows
        Z[i] = new int [m2];
    }
    
    test(X,n1,m1);
    test(Y,n2,m2);
    test(Z,n3,m3);
    
    //won't work with A in front, same concepts as the G thing since A is explicitly sized
    test3(X, n1, m1, Y, n2, m2, Z, n3, m3);
    
    //print C
    
    test(X,n1,m1);
    test(Y,n2,m2);
    test(Z,n3,m3);
    
    
    return 0;
}
