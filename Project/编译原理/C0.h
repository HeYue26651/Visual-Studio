#pragma once
# define norw 9                   //�ؼ��ָ��� 
# define txmax 100                //���ֱ�����
# define nmax  14                 //number�����λ��
# define al 10                    //���ŵ���󳤶�
# define amax 2047                //��ַ�Ͻ�
# define cxmax 200                //����Ŀ�������
#define symnum 23
#define stacksize 500
#define fctnum 14
struct tablestruct
{
	char name[al];                //���� 
	enum object kind;             //���ͣ�variable,intfun,voidfun
	int val;                      //��ֵ
	int level;                    //������
	int adr;                      //��ַ
	int size;                     //��Ҫ������������ռ�
};
struct tablestruct table[txmax];  // ���ֱ� 
enum symbol {
	nul, ident, number, pluse, minuse,
	times, slash, lbrace, rbrace, lparen,
	rparen, comma, semicolon, becomes, ifsym,
	elsesym, whilesym, printfsym, scanfsym,
	intsym, voidsym, returnsym, mainsym,
};
enum symbol wsym[norw]; //�����ֶ�Ӧ�ķ���ֵ 
enum symbol sym;        //��ǰ����
enum symbol ssym[256];  //���ַ��ķ���ֵ 
enum fct                //fct���ͷֱ��ʶĿ�����ĸ���ָ��
{
	lit, ret, lod, sto, cal, inte, jmp, jpc, add, dive, mul, sub, wrt, red,
};

struct instruction  //ָ�� 
{
	enum fct f;     //������ 
	int l;          //���
	int a;
};
struct instruction code[cxmax];   //���Ŀ���������� 
enum object                //objectΪ��ʶ��������
{
	variable,
	intfun,
	voidfun,
};
enum object k;

char fname[al];
FILE* fin;                //fin�ı��ļ�����ָ�������Դ�����ļ�
FILE* fout;               //fout�ı��ļ�����ָ��������ļ�
FILE* fa;

int cx = 0;               //���������ָ�룬ȡֵ��Χ[0,cxmax-1]
int err;                  //���������
int cc, ll;               //getchʹ�õļ�����,cc��ʾ��ǰ�ַ�(ch)��λ�� 
int pdx;				  //��ǰ���ַ
int ptx;				  //���ֱ����λָ��
int ls;
int  num;                 //��ǰnumber 
char ch;                  //��ȡ�ַ��Ļ�����,getchʹ�� 
char line[81];            //��ȡ�л����� 
char id[al + 1];          //��ǰident,���һ���ֽ����ڴ��0
char word[norw][al];      //������
char mnemonic[fctnum][5]; //���������ָ������ 
char tmp[al + 1];
char a[al + 1];           //��ʱ���ţ������һ���ֽ����ڴ��0 

//��������
void error(int n);
void init();

void getch();
void getsym();

void enter(int lev, int pdx);
int gen(enum fct x, int y, int z);
void glintcl();
void intcl();
void funcl();
int paren();
int block();

void ifcl();
void whilecl();
void term();
void expression();
void factor();
void statement();