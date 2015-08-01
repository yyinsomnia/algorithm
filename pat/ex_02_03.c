#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )

typedef struct ElementRecord *ElementType;
/* START: fig3_45.txt */
#ifndef _Stack_h
#define _Stack_h

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty( Stack S );
int IsFull( Stack S );
Stack CreateStack( int MaxElements );
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( ElementType X, Stack S );
ElementType Top( Stack S );
void Pop( Stack S );
ElementType TopAndPop( Stack S );

#endif  /* _Stack_h */

/* END */

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

struct ElementRecord
{
    float val;
    char  isOperator;
};

/* START: fig3_48.txt */
int
IsEmpty( Stack S )
{
    return S->TopOfStack == EmptyTOS;
}
/* END */

int
IsFull( Stack S )
{
    return S->TopOfStack == S->Capacity - 1;
}

/* START: fig3_46.txt */
Stack
CreateStack( int MaxElements )
{
    Stack S;

/* 1*/      if( MaxElements < MinStackSize )
/* 2*/          Error( "Stack size is too small" );

/* 3*/      S = malloc( sizeof( struct StackRecord ) );
/* 4*/      if( S == NULL )
/* 5*/          FatalError( "Out of space!!!" );

/* 6*/      S->Array = malloc( sizeof( ElementType ) * MaxElements );
/* 7*/      if( S->Array == NULL )
/* 8*/          FatalError( "Out of space!!!" );
/* 9*/      S->Capacity = MaxElements;
/*10*/      MakeEmpty( S );

/*11*/      return S;
}
/* END */

/* START: fig3_49.txt */
void
MakeEmpty( Stack S )
{
    S->TopOfStack = EmptyTOS;
}
/* END */

/* START: fig3_47.txt */
void
DisposeStack( Stack S )
{
    if( S != NULL )
    {
        free( S->Array );
        free( S );
    }
}
/* END */

/* START: fig3_50.txt */
void
Push( ElementType X, Stack S )
{
    char *s;
    if( IsFull( S ) )
        Error( "Full stack" );
    else {
        S->Array[ ++S->TopOfStack ] = X;   
    }
}
/* END */


/* START: fig3_51.txt */
ElementType
Top( Stack S )
{
    if( !IsEmpty( S ) )
        return S->Array[ S->TopOfStack ];
    Error( "Empty stack" );
    return 0;  /* Return value used to avoid warning */
}
/* END */

/* START: fig3_52.txt */
void
Pop( Stack S )
{
    if( IsEmpty( S ) )
        Error( "Empty stack" );
    else {
        S->TopOfStack--;   
    }
}
/* END */

/* START: fig3_53.txt */
ElementType
TopAndPop( Stack S )
{
    if( !IsEmpty( S ) ) {
        free(S->Array[S->TopOfStack]);
        return S->Array[ S->TopOfStack-- ];   
    }
    Error( "Empty stack" );
    return 0;  /* Return value used to avoid warning */
}
/* END */
float 
calc(float a, float b, char operator)
{
    printf("%f %c %f\n", a, operator, b);
    switch (operator)
    {
            case '+': return (a + b);
            case '-': return (a - b);
            case '*': return (a * b);
            case '/': if (b == 0.0) {
                Error("Error");
            } else {
                return (a / b);
            }
            default: FatalError("Error");
    }
}

int isStrOperator(char *s)
{
    return strlen(s) == 1 && (strcmp(s, "+") == 0 || strcmp(s, "-") == 0 || strcmp(s, "*") == 0 || strcmp(s, "/") == 0);
}

int main(void)
{
    Stack S = CreateStack(30);
    MakeEmpty(S);
    char c, tmp, str[10];
    ElementType x, top, op, val1, val2;
    while (scanf("%s", str) == 1)
    {
        ElementType x = malloc(sizeof(struct ElementRecord));
        if (isStrOperator(str))
        {
            x->val = str[0];
            x->isOperator = 1;
            Push(x, S);
        } 
        else 
        {
            x->val = atof(str);
            x->isOperator = 0;
            Push(x, S);
            
            while ((val1 = Top(S)) && !val1->isOperator) //also a num
            {
                val1 = Top(S);
                Pop(S);
                if (IsEmpty(S)) {
                    Push(val1, S); //fill back
                    break; //it is important
                }
                val2 = Top(S);
                if (val2->isOperator) {
                    Push(val1, S); //fill back
                    break;
                }
                Pop(S);
                
                op = Top(S);
                if (!op->isOperator)
                {
                    Error("Error");
                }
                
                Pop(S);
                top = malloc(sizeof(struct ElementRecord));
                
                top->val = calc(val2->val, val1->val, (char) op->val);
                top->isOperator = 0;
                free(val1);free(val2);free(op);
                Push(top, S);
            }
       
        }
        
        tmp = getchar();
        if (tmp == '\n') {
            break;
        } else {
            ungetc(tmp, stdin);
        }
        
    }
    top = Top(S);
    Pop(S);
    if (!IsEmpty(S) || top->isOperator) {
        printf("ERROR");
    } else {
        printf("%.1f", top->val);   
    }
    return 0;
}

        




