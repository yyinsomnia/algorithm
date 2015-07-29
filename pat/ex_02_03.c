       
        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>

        #define Error( Str )        FatalError( Str )
        #define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

        #define EmptyTOS ( -1 )
        #define MinStackSize ( 5 )

        typedef float ElementType;
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
            if( IsFull( S ) )
                Error( "Full stack" );
            else
                S->Array[ ++S->TopOfStack ] = X;
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
            else
                S->TopOfStack--;
        }
/* END */

/* START: fig3_53.txt */
        ElementType
        TopAndPop( Stack S )
        {
            if( !IsEmpty( S ) )
                return S->Array[ S->TopOfStack-- ];
            Error( "Empty stack" );
            return 0;  /* Return value used to avoid warning */
        }
/* END */
        float 
        calc(float a, float b, char operation)
        {
                switch (operation)
                {
                        case '+': return (a + b);
                        case '-': return (a - b);
                        case '*': return (a * b);
                        case '/': return (a / b);
                        default: FatalError("Error");
                }
        }

        int main(void)
        {
            Stack S = CreateStack(30);
            MakeEmpty(S);
            char c, str[10];
            ElementType x, top, op;
            while (scanf("%s", str) == 1)
            {
                printf("%d", strlen(str));
                if (strcmp(str, "+") == 0 || strcmp(str, "-") == 0 || strcmp(str, "*") == 0 || strcmp(str, "/") == 0)
                {
                    x = -str[0]; // to judge the operation...
                    Push((ElementType) x, S);
                } 
                else 
                {
                    if (IsEmpty(S))
                        Error("Error");
                    x = atof(str);
                    top = Top(S);
                    if (top > 0) //also a num
                    {
                        Pop(S);
                        if (IsEmpty(S))
                            Error("Error");
                        op = Top(S);
                        if (op >= 0)
                        {
                            Error("Error");
                        }
                        else 
                        {
                            op = -op; //translate back
                        }
                        Pop(S);
                        top = calc(top, x, op);
                        Push(top, S);

                    }
                    else 
                    {
                        Push(x, S);
                    }
                }
            }
            top = Top(S);
            printf("f%", top);
            return 0;
        }

        




