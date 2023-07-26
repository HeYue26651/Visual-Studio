#pragma once
# define norw 9                   //关键字个数 
# define txmax 100                //名字表容量
# define nmax  14                 //number的最大位数
# define al 10                    //符号的最大长度
# define amax 2047                //地址上界
# define cxmax 200                //最多的目标代码数
#define symnum 23
#define stacksize 500
#define fctnum 14
struct tablestruct
{
	char name[al];                //名字 
	enum object kind;             //类型：variable,intfun,voidfun
	int val;                      //数值
	int level;                    //所处层
	int adr;                      //地址
	int size;                     //需要分配的数据区空间
};
struct tablestruct table[txmax];  // 名字表 
enum symbol {
	nul, ident, number, pluse, minuse,
	times, slash, lbrace, rbrace, lparen,
	rparen, comma, semicolon, becomes, ifsym,
	elsesym, whilesym, printfsym, scanfsym,
	intsym, voidsym, returnsym, mainsym,
};
enum symbol wsym[norw]; //保留字对应的符号值 
enum symbol sym;        //当前符号
enum symbol ssym[256];  //单字符的符号值 
enum fct                //fct类型分别标识目标代码的各条指令
{
	lit, ret, lod, sto, cal, inte, jmp, jpc, add, dive, mul, sub, wrt, red,
};

struct instruction  //指令 
{
	enum fct f;     //功能码 
	int l;          //层次
	int a;
};
struct instruction code[cxmax];   //存放目标代码的数组 
enum object                //object为标识符的类型
{
	variable,
	intfun,
	voidfun,
};
enum object k;

char fname[al];
FILE* fin;                //fin文本文件用于指向输入的源程序文件
FILE* fout;               //fout文本文件用于指向输出的文件
FILE* fa;

int cx = 0;               //虚拟机代码指针，取值范围[0,cxmax-1]
int err;                  //错误计数器
int cc, ll;               //getch使用的计数器,cc表示当前字符(ch)的位置 
int pdx;				  //当前层地址
int ptx;				  //名字表最后位指针
int ls;
int  num;                 //当前number 
char ch;                  //获取字符的缓冲区,getch使用 
char line[81];            //读取行缓冲区 
char id[al + 1];          //当前ident,多出一个字节用于存放0
char word[norw][al];      //保留字
char mnemonic[fctnum][5]; //虚拟机代码指令名称 
char tmp[al + 1];
char a[al + 1];           //临时符号，多出的一个字节用于存放0 

//函数声明
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