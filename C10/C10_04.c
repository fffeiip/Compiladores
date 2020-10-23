#include <stdio.h>
#include <time.h>

#define N 100000000


#define fim_string -1
#define AP -2 //Abre Parenteses
#define FP -3 //Fecha Parenteses
#define K -4
#define S -5
#define I -6
#define B -7
#define C -8
#define D -9
#define E -10
#define F -11
#define Y -12

#define add -13
#define sub -14
#define mul -15
#define div -16
#define lt -17
#define gt -18
#define eq -19
#define True -20
#define False -21

// FIB
static int entrada[N] = {S, AP, K, AP, S, I, I, FP, FP, AP, S, AP, S, AP, K, S, FP, K, FP, AP, K, AP, S, I, I, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 2, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, lt, FP, FP, FP, FP, AP, K, I, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, K, K, FP, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 1, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, sub, FP, FP, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, K, K, FP, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 2, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, sub, FP, FP, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, add, FP, FP, FP, FP, 20, fim_string};
// FAT
//static int entrada[N] = {S, AP, K, AP, S, I, I, FP, FP, AP, S, AP, S, AP, K, S, FP, K, FP, AP, K, AP, S, I, I, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 2, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, lt, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, 1, FP, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, K, K, FP, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 1, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, sub, FP, FP, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, mul, FP, FP, FP, FP, 20, fim_string};

static int saida[N];

void printar_array(unsigned int *array1) {
   int i;
   unsigned int fimString = -1;
   for(i = 0;array1[i] != fimString;i++){
       switch (array1[i]){
           case S:
               printf("S");
               break;
           case K:
               printf("K");
               break;
           case B:
               printf("B");
               break;
           case C:
               printf("C");
               break;
           case I:
               printf("I");
               break;
           case FP:
               printf(")");
               break;
           case AP:
               printf("(");
               break;
           case D:
               printf("D");
               break;
           case E:
               printf("E");
               break;
           case F:
               printf("F");
               break;
           case Y:
               printf("Y");
               break;
            case add:
                printf("+");
                break;
            case sub:
                printf("-");
                break;
            case mul:
                printf("*");
                break;
            case div:
                printf("/");
                break;
            case lt:
                printf("<");
                break;
            case gt:
                printf(">");
                break;
            case eq:
                printf("=");
                break;
            case True:
                printf("True");
                break;
            case False:
                printf("False");
                break;
           case fim_string:
                break;
           default:
               printf("%u ", array1[i]);
       }
   }
   printf("\n");
}

/*
 * Remove o parenteses da posição 0 e seu oposto
 */

void remove_parenteses(int *array1){
    int p = 0;
    int paren = 1;
    while (paren) {
        array1[p] = array1[p+1];
        p++;
        if(array1[p] == AP){
            paren++;
        }else if(array1[p] == FP){
            paren--;
        }
    }
    p--;
    while(array1[p+1] != fim_string && array1[p+2] != fim_string){
        array1[p] = array1[p+2];
        p++;
    }
    array1[p] = fim_string;
}

/*
 * Procura o fim do conjunto de inteiros
 */
void casa_parenteses(int* array1, int* p) {
    int paren = 1;
    int a = *p;
    while (paren) {
        unsigned int c  = array1[a];
        if(c == AP){
            paren++;
        }else if(c == FP){
            paren--;
        }
        a++;
    }
    *p = a;
}

/*
 * Verifica se a posicao do array é um inteiro ou um conjunto de inteiros
 */
void acha_argumento(int *array1, int *p){
    int c = (*p)++;
    if (array1[c] == AP) {
        casa_parenteses(array1,p);
    }
}

/*
 * Kab = a
 */

 void reduz_K(int* array1, int* array2) {
     int a, nA;
     int n = 1;

     a = n;
     acha_argumento(array1,&n);

     nA = n-1;
     acha_argumento(array1,&n);

     int k = 0;
     int i;

     for (i = a; i <= nA; i++) {
         array2[k] = array1[i];
         k++;
     }

     for (; array1[n] != fim_string; n++) {
         array2[k] = array1[n];
         k++;
     }

     array2[k] = fim_string;
 }

 /*
  * Sabc = ac(bc)
  */
 void reduz_S(int *array1, int *array2) {
     int a, nA;
     int b, nB;
     int c, nC;
     int n = 1;
     a = n;
     acha_argumento(array1,&n);
     nA = n-1;
     b = n;
     acha_argumento(array1,&n);
     nB = n-1;
     c = n;
     acha_argumento(array1,&n);
     nC = n-1;

     int k = 0;
     int i;

     for (i = a; i <= nA; i++) {
         array2[k] = array1[i];
         k++;
     }
     for (i = c; i <= nC; i++) {
         array2[k] = array1[i];
         k++;
     }

     array2[k] = AP;
     k++;

     for (i = b; i <= nB; i++) {
         array2[k] = array1[i];
         k++;
     }

     for (i = c; i <= nC; i++) {
         array2[k] = array1[i];
         k++;
     }

     array2[k] = FP;
     k++;

     for (; array1[n] != fim_string; n++) {
         array2[k] = array1[n];
         k++;
     }

     array2[k] = fim_string;
 }
 
 //I a => a,

 void reduz_I(int* array1, int* array2) {
    int k = 0;
    int i = 1;
    for ( ; array1[i] != fim_string; i++) {
        array2[k] = array1[i];
        k++;
    }
    array2[k] = fim_string;
}

 //B a b c => a ( b c )
void reduz_B(int *array1, int *array2) {
	int A, nA;
    int b, nB;
    int c, nC;
    int n = 1;
    
    A = n;
	acha_argumento(array1,&n);
	nA = n-1;
	b = n;
	acha_argumento(array1,&n);
	nB = n-1;
	c = n;
	acha_argumento(array1,&n);
	nC = n-1;

	int k = 0;
    int i;
    
	for (i = A; i <= nA; i++) {
		array2[k] = array1[i];
        k++;
    }
	array2[k] = AP;
	k++;

	for (i = b; i <= nB; i++) {
		array2[k] = array1[i];
        k++;
    }

	for (i = c; i <= nC; i++) {
		array2[k] = array1[i];
        k++;
    }

	array2[k] = FP;
	k++;

	for (n = n; array1[n] != fim_string; n++){
		array2[k] = array1[n];
        k++;
    }

	array2[k] = fim_string;
}

// C a b c => a c b
void reduz_C (int *array1, int *array2) {
	int A, nA;
    int b, nB;
    int c, nC;
    int n = 1;

    A = n;
    acha_argumento(array1, &n);
    nA = n - 1;
    b = n;
    acha_argumento(array1,&n);
    nB = n - 1;
    c = n;
    acha_argumento(array1, &n);
    nC = n - 1;

    int k = 0;
    int i; 

    for (i = A; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (i = c; i <= nC; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (i = b; i <= nB; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (i = n; array1[i] != fim_string; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = fim_string;
}

//D a b c d => a ( b d ) ( c d )
void reduz_D(int *array1, int *array2) {
    int A, nA;
    int b, nB;
    int c, nC;
    int d, nD;
    int n = 1;

    A = n;        
	acha_argumento(array1, &n);
	nA = n - 1;
	b = n;
	acha_argumento(array1,&n);
	nB = n - 1;
	c = n;
	acha_argumento(array1,&n);
	nC = n - 1;
	d = n;
	acha_argumento(array1,&n);
	nD = n - 1;

    int k = 0;
	int i; 

	for (i = A; i <= nA; i++){
		array2[k] = array1[i];
        k++;
    }
    
	array2[k] = AP;
	k++;
    
	for (i = b; i <= nB; i++){
		array2[k] = array1[i];
        k++;
    }

	for (i = d; i <= nD; i++){
		array2[k] = array1[i];
        k++;
    }

	array2[k] = FP;
	k++;

	array2[k] = AP;
	k++;

	for (i = c; i <= nC; i++){
		array2[k] = array1[i];
        k++;
    }

	for (i = d; i <= nD; i++){
		array2[k] = array1[i];
        k++;
    }

	array2[k] = FP;
	k++;

	for (i = n; array1[i] != fim_string; i++) {
		array2[k] = array1[i];
        k++;
    }

	array2[k] = fim_string;
}

//E a b c d => a b ( c d ),
void reduz_E(int *array1, int *array2) {
    int A, nA;
    int b, nB;
    int c, nC;
    int	d, nD;
    int n = 1;

    A = n;
	acha_argumento(array1, &n);
	b = n;
	nA = n - 1;
	acha_argumento(array1,&n);
	nB = n - 1;
	c = n;
	acha_argumento(array1,&n);
	nC = n - 1;
	d = n;
	acha_argumento(array1,&n);
	nD = n - 1;

    int k = 0;
	int i;

	for (i = A; i <= nA; i++){
		array2[k] = array1[i];
        k++;
    }

	for (i = b; i <= nB; i++){
		array2[k] = array1[i];
        k++;
    }

	array2[k] = AP;
	k++;

	for (i = c; i <= nC; i++){
		array2[k] = array1[i];
        k++;
    }

	for (i = d; i <= nD; i++){
		array2[k] = array1[i];
        k++;
    }

	array2[k] = FP;
	k++;

	for (i = n; array1[i] != fim_string; i++){
		array2[k] = array1[i];
        k++;
    }

	array2[k] = fim_string;
}

//F a b c d => a ( b d ) c,
void reduz_F(int *array1, int *array2) {
	
    int A, nA;
    int b, nB;
    int c, nC;
	int d, nD;
    int n = 1;

    A = n;
	acha_argumento(array1, &n);
	nA = n - 1;
	b = n;
	acha_argumento(array1,&n);
	nB = n - 1;
	c = n;
	acha_argumento(array1,&n);
	nC = n - 1;
	d = n;
	acha_argumento(array1,&n);
	nD = n - 1;

	int i, k = 0;
	for (i = A; i <= nA; i++) {
		array2[k] = array1[i];
        k++;
    }
        
	array2[k] = AP;
	k++;

	for (i = b; i <= nB; i++, k++){
		array2[k] = array1[i];
        k++;
    }

	for (i = d; i <= nD; i++){
		array2[k] = array1[i];
        k++;
    }

	array2[k] = FP;
	k++;

	for (i = c; i <= nC; i++){
		array2[k] = array1[i];
        k++;
    }

	for (i = n; array1[i] != fim_string; i++){
		array2[k] = array1[i];
        k++;
    }

	array2[k] = fim_string;
}

//Y a => a ( Y a )
void reduz_Y(int *array1, int *array2) {
    int a = 1, nA;
    int n = 1;

    acha_argumento(array1, &n);
    nA = n - 1;
    acha_argumento(array1, &n);

    int k = 0, i = a;
    for ( ; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;
    array2[k] = array1[0];
    k++;

    for (i = a; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }
    
    array2[k] = FP;
    k++;

    for ( ; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }
    array2[k] = fim_string;
}

//+ a b => a + b
void reduz_add(int *array1, int *array2) {
    array2[0] = array1[1] + array1[2];
    int i = 3, k = 1;
    for (; array1[i] != fim_string; i++) {
        array2[k] = array1[i];
        k++;
    }
    array2[k] = fim_string;
}

//- a b => a - b
void reduz_sub(int *array1, int *array2) {
    array2[0] = array1[1] - array1[2];
    int i = 3, k = 1;
    for (; array1[i] != fim_string; i++){
        array2[k] = array1[i];
        k++;
    }
    array2[k] = fim_string;
}

//* a b => a * b
void reduz_mul(int *array1, int *array2) {
    array2[0] = array1[1] * array1[2];
    int i = 3, k = 1;
    for (; array1[i] != fim_string; i++){
        array2[k] = array1[i];
        k++;
    }
    array2[k] = fim_string;
}

// /a b => a / b
void reduz_div(int *array1, int *array2) {
    array2[0] = array1[1] / array1[2];
    int i = 3, k = 1;
    for (; array1[i] != fim_string; i++){
        array2[k] = array1[i];
        k++;
    }
    array2[k] = fim_string;
}

//< a b => True if a < b else False
void reduz_lt(int *array1, int *array2) {
    array2[0] = array1[1] < array1[2] ? True : False;
    int i = 3, k = 1;
    for (; array1[i] != fim_string; i++){
        array2[k] = array1[i];
        k++;
    }
    array2[k] = fim_string;
}


//> a b => True if a > b else False
void reduz_gt(int *array1, int *array2) {
    array2[0] = array1[1] > array1[2] ? True : False;
    int i = 3, k = 1;
    for (; array1[i] != fim_string; i++){
        array2[k] = array1[i];
        k++;
    }
    array2[k] = fim_string;
}

//= a b => True if a = b else False
void reduz_eq(int *array1, int *array2) {
    array2[0] = array1[1] == array1[2] ? True : False;
    int i = 3, k = 1;
    for (; array1[i] != fim_string; i++){
        array2[k] = array1[i];
        k++;
    }
    array2[k] = fim_string;
}

//True a b => a
void reduz_True(int *array1, int *array2) {
    int a = 1, n = 1;
    acha_argumento(array1, &n);
    int nA = n - 1;
    int b = n;
    acha_argumento(array1, &n);
    int nB = n - 1;

    int i = a, k = 0;

    for (; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }
    
    for (i = n; array1[i] != fim_string; i++){
        array2[k] = array1[i];
        k++;
    }

    array2[k] = fim_string;
}


//False a b => b
void reduz_False(int *array1, int *array2) {
    int n = 1;
    acha_argumento(array1, &n);
    int b = n;
    acha_argumento(array1, &n);
    int nB = n - 1;
    int i = b, k = 0;
    for (; i <= nB; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (i = n; array1[i] != fim_string; i++){
        array2[k] = array1[i];
        k++;
    }
    array2[k] = fim_string;
}

void reduz_moveInteiro(int *array1, int *array2) {
    int a = 1, n = 1;
    acha_argumento(array1,&n);
    int nA = n-1, b = n;
    acha_argumento(array1,&n);
    int nB = n-1, c = n;

    int i = a, k = 0;
    for (; i <= nB; i++){
        array2[k] = array1[i];
        k++;
    }

    array2[k] = array1[0];
    k++;

    for (i = c; array1[i] != fim_string; i++){
        array2[k] = array1[i];
        k++;
    }

    array2[k] = fim_string;
 }

int main(){
    int *array1, *array2, *array3;
    array1 = entrada;
    array2 = saida;
    while(array1[1] != fim_string){
        switch (array1[0]){
            case AP:
                remove_parenteses(array1);
                array2[0] = fim_string;
                break;
            case B:
                reduz_B(array1, array2);
                break;
            case C:
                reduz_C(array1, array2);
                break;
            case S:
                reduz_S(array1, array2);
                break;
            case I:
                reduz_I(array1, array2);
                break;
            case K:
                reduz_K(array1, array2);
                break;
            case D:
                reduz_D(array1, array2);
                break;
            case E:
                reduz_E(array1, array2);
                break;
            case F:
                reduz_F(array1, array2);
                break;
            case Y:
                reduz_Y(array1, array2);
                break;
            case add:
                reduz_add(array1, array2);
                break;
            case sub:
                reduz_sub(array1, array2);
                break;
            case mul:
                reduz_mul(array1, array2);
                break;
            case div:
                reduz_div(array1, array2);
                break;
            case lt:
                reduz_lt(array1, array2);
                break;
            case gt:
                reduz_gt(array1, array2);
                break;
            case eq:
                reduz_eq(array1, array2);
                break;
            case True:
                reduz_True(array1, array2);
                break;
            case False:
                reduz_False(array1, array2);
                break;
            default:
                if (array1[0] >= 0)
                    reduz_moveInteiro(array1, array2);
                break;
        }
        array3 = array1;
        array1 = array2;
        array2 = array3;
    }
    printar_array(array1);
    float clks = CLOCKS_PER_SEC;
    printf("\nTempo = %f", (clock()/clks));
    return 0;
}
