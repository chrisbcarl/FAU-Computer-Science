#include <iostream>

using namespace std;

//define dot product
int dotproduct(int A[], int array1size,
               int B[], int array2size)
{

    if(array1size != array2size) return -1;
    else
    {
        int sum = 0, total = 0;
        for (int i = 0; i < array1size; i++)
        {
            total = A[i] * B[i];
            sum = sum + total;
        }
    return sum;
    }
}


//define vector product
void vectorproduct(int **A, int n1, int m1, int **B, int n2, int m2, int **C, int *n3, int *m3)
{
    //check if # of columns of A is the same as # of rows of B, if not return nothing
//        else we change C
    
    if (m1 != n2)
    {
        *n3 = n1;               //n3 = 0x0000 A34B F7890 0069   //*n3 = a number, n3's value
        *m3 = m2;               //m3 = 0x0000 A34B F7890 1969   //*m3 = a number, m3's value
        C = new int*[*n3];
        
        for (int i = 0; i < *n3; i++) {
            //create a new array of ints for this row of C, C[i]
            C[i] = new int[*m3];
            for (int j = 0; j < *m3; j++) {
                C[i][j] = 999; // currently a stub, so this will change
            }
        }
        
        
    }
    else
    {
        C = 0;
        *n3 = -1;
        *m3 = -1;
    }
    
    
}


//define print 2D array so I don’t have to repeatedly type
//void print2D(int **Array, int n, int m)
void print2D(int *Array[], int n, int m)
{
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cout << Array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}




//define print 1D array so I don’t have to keep typing
void print1D(int Array[], int m)
{
    for(int j = 0; j < m; j++){
        cout << Array[j] << " ";
    }
    cout << endl;
    
}




int main()

{
    // STEP 1: declare 3 2D Matricies, their sizes, and two test arrays for the dot product
    
    int vector1[4] = {0, 1, 2, 3};
    int vector2[4] = {3, 2, 1, 0};
    
    cout << "Printing vector 1: ";     print1D(vector1, 4);   //shows that A is empty
    cout << "Printing vector 2: ";     print1D(vector2, 4);   //shows that B is empty
    
    int **A; int **B; int **C;          // declaring the names of the 2D arrays, nothing is in them yet. they are uninitalized
    int n1, m1, n2, m2;                 // declaring the dimensions of the 2D arrays. They are not yet initiated.
    int *n3, *m3;                       // declaring pointers to C's dimensions
                                        //     we "don't know" what they're supposed to be. They're unknown so we can
                                        //     calculate them later.
    
    n1 = 4; m1 = 3;                     // A is going to be [4 x 3]
    n2 = 3; m2 = 5;                     // B is going to be [3 x 5]
    
    *n3 = 0; *m3 = 0;                   // C supposed to be a ghost right now [0 x 0]
    
    
    
    
    //STEP 2: fill 2 of the three with data
    A = new int*[n1];                    // initializing A to at least have "n1" rows at all. They're empty right now.
                                        // so far, A just points to the first of a few references to something.
                                        // A has no data in it.
    
    B = new int*[n2];                    // initializing B to at least have "n2" rows at all. They're empty right now.
                                        // so far, B just points to the first of a few references to something.
                                        // B has no data in it.
    
    
    C = 0;                               // C gets no love, cause nobody likes C. We're setting it to point to NOTHING
    
    for (int i; i < n1; i ++) {         //"for every row in A, put a real row in there, even though the row is truly empty"
        A[i] = new int[m1];
    }
    
    for (int i; i < n2; i ++) {         //"for every row in B, put a real row in there, even though the row is truly empty"
        B[i] = new int[m2];
    }
    
    
    cout << "Printing A: ";     print2D(A, n1, m1);   //shows that A is empty
    cout << "Printing B: ";     print2D(B, n2, m2);   //shows that B is empty
    
    
    //print them out to be sure
    
    //test the dot product on one
    // print the two 1D arrays, and the dot product
    
    //test the vector product on one
    //print the two 2D arrays, and the vector product 2D array
    
    //done
    
    
    
    
    
    
    return 0;
}
