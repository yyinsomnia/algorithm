#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;


int main(void)
{
    ElementType *A;
    ElementType *PSA;
    ElementType *TmpA;
    int is_insert(ElementType *, ElementType *, int);
    int get_merge_length(ElementType *, int N);
    void merge_pass(ElementType *, ElementType *, int, int);

    int n, i, insert_index, tmp, length;
    if (scanf("%d", &n) == 1 && n > 0) {
        A = malloc(n * sizeof(ElementType));
        PSA = malloc(n * sizeof(ElementType));
        for (i = 0; i < n; i++) {
            scanf("%d", A + i);
        }
        for (i = 0; i < n; i++) {
            scanf("%d", PSA + i);
        }
        insert_index = is_insert(A, PSA, n);
        if (insert_index) {
            tmp = PSA[insert_index];
            for (i = insert_index; PSA[i - 1] > tmp && i > 0; i--) {
                PSA[i] = PSA[i - 1];
            }
            PSA[i] = tmp;

            printf("Insertion Sort\n");
            printf("%d", PSA[0]);
            for (i = 1; i < n; i++) {
                printf(" %d", PSA[i]);
            }
        } else {
            TmpA = malloc(n * sizeof(ElementType));
            length = get_merge_length(PSA, n);
            if (length < n) {
                merge_pass(PSA, TmpA, n, length);
                printf("Merge Sort\n");
                printf("%d", TmpA[0]);
                for (i = 1; i < n; i++) {
                    printf(" %d", TmpA[i]);
                }
            }
            free(TmpA);
        }
        free(A);
        free(PSA);
    }
}

int get_merge_length(ElementType PSA[], int N)
{
    int is_sorted(ElementType *, int, int);
    int length, i;
    for (length = 1; length < N; length *= 2) {
        for (i = 0; i <= N - 2 * length; i += 2 * length) {
            if (!is_sorted(PSA, i, i + 2 * length - 1)) {
                return length;
            }
        }
    }
    return N;
}


void merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{
    void Merge1( ElementType *, ElementType *,
                int, int, int);
    int i, j;
    for (i = 0; i <= N - 2 * length; i += 2 * length) {
        Merge1(A, TmpA, i, i + length, i + 2 * length - 1);
    }
    if (i + length < N)
        Merge1(A, TmpA, i, i + length, N - 1);
    else 
        for (j = i; j < N; j++) {TmpA[j] = A[j];}
}


void Merge1( ElementType A[ ], ElementType TmpArray[ ],
                int Lpos, int Rpos, int RightEnd )
{
    int i, LeftEnd, NumElements, TmpPos;

    LeftEnd = Rpos - 1;
    TmpPos = Lpos;
    NumElements = RightEnd - Lpos + 1;

    /* main loop */
    while( Lpos <= LeftEnd && Rpos <= RightEnd )
        if( A[ Lpos ] <= A[ Rpos ] )
            TmpArray[ TmpPos++ ] = A[ Lpos++ ];
        else
            TmpArray[ TmpPos++ ] = A[ Rpos++ ];

    while( Lpos <= LeftEnd )  /* Copy rest of first half */
        TmpArray[ TmpPos++ ] = A[ Lpos++ ];
    while( Rpos <= RightEnd ) /* Copy rest of second half */
        TmpArray[ TmpPos++ ] = A[ Rpos++ ];

}
//2 1 4 3 6 5 8 7 10 9
//1 2 3 4 6 5 8 7 10 9
int is_insert(ElementType A[], ElementType PSA[], int N)
{
    int i, j;
    for (i = 0; i < N - 1; i++) {
        if (PSA[i] > PSA[i + 1]) {
            for (j = i + 1; j < N; j++) {
                if (A[j] != PSA[j]) {
                    return 0;
                }
            }
            return i + 1;
        } 
    } return -1; //already sorted
}

int is_sorted(ElementType A[], int left, int right)
{
    int i;
    for (i = left; i < right; i++) {
        if (A[i] > A[i + 1]) {
            return 0;
        }
    }
    return 1;
}


