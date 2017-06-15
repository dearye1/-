#include<stdio.h>    
#include<malloc.h> //包含malloc函数
//#include<stdlid.h> //包含exit函数
//定义了一个数据类型，这个数据类型名字加struct Arr，其中包含了三个数据
struct Arr
{
	int *pBase; //存储数组的第一个元素的地址
	int len;   //数组所能容纳的最大元素的个数
	int cut;   //数组有效元素的个数
};

void init_arr(struct Arr *pArr,int length); //初始化
//初始化值函数调用了init—arr这个函数之后，*pBase指向的就不是一个垃圾数字了，而是一个有效的数组
bool append_arr(struct Arr *pArr,int val); //追加
bool insert_arr(struct Arr *pArr,int pos, int val); //插入 val插入的值
bool delete_arr(struct Arr *pArr,int pos, int *pVal /*,int * size*/); //删除 *pval删除的值，利用指针输出
int get();         //获取下标为某一个的值
bool is_empty(struct Arr * pArr); //数组是否空
bool is_full(struct Arr * pArr); //是否满
void sort_arr(struct Arr * pArr); //排序
void show_arr(struct Arr * pArr); //显示
void inversion_arr(struct Arr *pArr); //倒置 


int main(void)
{
	struct Arr arr;//给数组定义了一个变量。名字叫做arr
	int val;
	init_arr(&arr, 10); //传送首地址,定义数组长度6
	//show_arr(&arr); //显示
	append_arr(&arr, 1);
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	append_arr(&arr, 5);
	
	insert_arr(&arr, 5 , 10);//插入
	printf("插入成功");
	show_arr(&arr); //显示

	if (append_arr(&arr, 6))//追加
	{
	printf("追加成功");
	}
	else 
	{
	printf("追加失败\n");
	}
	show_arr(&arr); //显示

	if( delete_arr(&arr, 1, &val) ) //删除
	{
		printf("您删除的元素是  %d\n", val);
	}
	else 
	{
	printf("您删除失败!");
	}	
	show_arr(&arr); //显示
	printf("数组倒置后为：");
    inversion_arr(&arr);//倒置
	show_arr(&arr); //显示
	sort_arr(&arr); //排序
	show_arr(&arr); //显示
/*	printf("%d", cut );*/
/*	printf("%d\n", arr.len );*/
	return 0;
}

void init_arr(struct Arr *pArr, int length) //初始化
{
/*	(*pArr).len  = 99;*/
	pArr->pBase = (int *)malloc(sizeof(int ) * length);//动态数组
	if(NULL == pArr->pBase )
	{
		printf("动态内存分配失败");
	//	exit(-1);//终止程序
	}
	else
	{
	pArr->len = length;
	pArr->cut = 0;
	}
return ;
}

bool is_empty(struct Arr *pArr)//判断数组是否为空
{
	if(0 == pArr->cut )//有效数字是否为0；
		return true;
	else
		return false;
}

bool is_full(struct Arr *pArr) //判断函数是否满
{
	if(pArr->cut ==pArr->len )
		return true;
	else
		return false;
}

void show_arr(struct Arr * pArr)  //显示
{
	if( is_empty(pArr))
	{
	printf("数组为空!\n");
	}
	else
	{
	for(int i=0; i<pArr->cut ; ++i)
		printf("%3d", pArr->pBase[i]);
	printf("\n");
	}
}

bool append_arr(struct Arr *pArr,int val)//追加
{
	//满时
	if( is_full(pArr))
		return false;
	//不满时追加
	else 
		pArr->pBase[pArr->cut ] = val;//val追加的值
		(pArr->cut)++;//
		return true;
}

bool insert_arr(struct Arr *pArr,int pos, int val)//插入
{
	int i;
	if (is_full(pArr))//数组满了
		return false;
	if(pos<1 || pos>pArr->len+1)//插入位置小于一，以及插入的位置大于数组长度
		return false;
	for(i = pArr->cut-1; i>=pos-1; --i)
	{
	pArr->pBase [i+1] = pArr->pBase [i];
	}
	pArr->pBase [pos-1] = val;
	(pArr->cut )++;
	return true;
}

bool delete_arr(struct Arr *pArr, int pos, int *pVal/*, int * size */) //删除 val删除的值
{
	int i;

	if(is_empty(pArr))    //如果数组为空
		return false;
	if(pos<1 || pos>pArr->cut )//如果删除的位置小于一，或者删除的位数大于有效位个数，则输出错误
		return false;
	*pVal = pArr->pBase [pos-1];
	for(i=pos; i <= pArr->cut; ++i)
	{
		pArr->pBase [i-1] = pArr->pBase [i];
	}
	(pArr->cut )--;
/*	* size=pArr->cut ;*/
	printf("有效位数为%d\n",pArr->cut );
		return true;
}

void inversion_arr(struct Arr *pArr)  //倒置
{
	int i=0,j=pArr->cut-1,t;
	/*if(is_empty(pArr))    //如果数组为空
		return false;*/
	while (i < j)
	{
	t=pArr->pBase [i];
	pArr->pBase [i]=pArr->pBase [j];
	pArr->pBase [j]=t;
	++i;
	--j;
	}
		return; 
}

void sort_arr(struct Arr * pArr) //排序
{
	int i,j,t;
	for(i=0; i<=pArr->cut ; ++i)
	{
		for(j=i+1; j<pArr->cut ; ++j)
		{if(pArr->pBase [i]>pArr->pBase [j])
			{
				t=pArr->pBase [i];
				pArr->pBase [i]=pArr->pBase [j];
				pArr->pBase [j]=t;
			}	
			
		}
	}
	return ;
}

/*
定义：
return有终止函数的执行和传递数值,
return true是返回一个真值.
return false是返回一个假值.*/
