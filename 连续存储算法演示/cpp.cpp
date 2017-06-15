#include<stdio.h>
#include<malloc.h> //����malloc����
//#include<stdlid.h> //����exit����
//������һ���������ͣ���������������ּ�struct Arr�����а�������������
struct Arr
{
	int *pBase; //�洢����ĵ�һ��Ԫ�صĵ�ַ
	int len;   //�����������ɵ����Ԫ�صĸ���
	int cut;   //������ЧԪ�صĸ���
};

void init_arr(struct Arr *pArr,int length); //��ʼ��
//��ʼ��ֵ����������init��arr�������֮��*pBaseָ��ľͲ���һ�����������ˣ�����һ����Ч������
bool append_arr(struct Arr *pArr,int val); //׷��
bool insert_arr(struct Arr *pArr,int pos, int val); //���� val�����ֵ
bool delete_arr(struct Arr *pArr,int pos, int *pVal /*,int * size*/); //ɾ�� *pvalɾ����ֵ������ָ�����
int get();         //��ȡ�±�Ϊĳһ����ֵ
bool is_empty(struct Arr * pArr); //�����Ƿ��
bool is_full(struct Arr * pArr); //�Ƿ���
void sort_arr(struct Arr * pArr); //����
void show_arr(struct Arr * pArr); //��ʾ
void inversion_arr(struct Arr *pArr); //���� 


int main(void)
{
	struct Arr arr;//�����鶨����һ�����������ֽ���arr
	int val;
	init_arr(&arr, 10); //�����׵�ַ,�������鳤��6
	//show_arr(&arr); //��ʾ
	append_arr(&arr, 1);
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	append_arr(&arr, 5);
	
	insert_arr(&arr, 5 , 10);//����
	printf("����ɹ�");
	show_arr(&arr); //��ʾ

	if (append_arr(&arr, 6))//׷��
	{
	printf("׷�ӳɹ�");
	}
	else 
	{
	printf("׷��ʧ��\n");
	}
	show_arr(&arr); //��ʾ

	if( delete_arr(&arr, 1, &val) ) //ɾ��
	{
		printf("��ɾ����Ԫ����  %d\n", val);
	}
	else 
	{
	printf("��ɾ��ʧ��!");
	}	
	show_arr(&arr); //��ʾ
	printf("���鵹�ú�Ϊ��");
    inversion_arr(&arr);//����
	show_arr(&arr); //��ʾ
	sort_arr(&arr); //����
	show_arr(&arr); //��ʾ
/*	printf("%d", cut );*/
/*	printf("%d\n", arr.len );*/
	return 0;
}

void init_arr(struct Arr *pArr, int length) //��ʼ��
{
/*	(*pArr).len  = 99;*/
	pArr->pBase = (int *)malloc(sizeof(int ) * length);//��̬����
	if(NULL == pArr->pBase )
	{
		printf("��̬�ڴ����ʧ��");
	//	exit(-1);//��ֹ����
	}
	else
	{
	pArr->len = length;
	pArr->cut = 0;
	}
return ;
}

bool is_empty(struct Arr *pArr)//�ж������Ƿ�Ϊ��
{
	if(0 == pArr->cut )//��Ч�����Ƿ�Ϊ0��
		return true;
	else
		return false;
}

bool is_full(struct Arr *pArr) //�жϺ����Ƿ���
{
	if(pArr->cut ==pArr->len )
		return true;
	else
		return false;
}

void show_arr(struct Arr * pArr)  //��ʾ
{
	if( is_empty(pArr))
	{
	printf("����Ϊ��!\n");
	}
	else
	{
	for(int i=0; i<pArr->cut ; ++i)
		printf("%3d", pArr->pBase[i]);
	printf("\n");
	}
}

bool append_arr(struct Arr *pArr,int val)//׷��
{
	//��ʱ
	if( is_full(pArr))
		return false;
	//����ʱ׷��
	else 
		pArr->pBase[pArr->cut ] = val;//val׷�ӵ�ֵ
		(pArr->cut)++;//
		return true;
}

bool insert_arr(struct Arr *pArr,int pos, int val)//����
{
	int i;
	if (is_full(pArr))//��������
		return false;
	if(pos<1 || pos>pArr->len+1)//����λ��С��һ���Լ������λ�ô������鳤��
		return false;
	for(i = pArr->cut-1; i>=pos-1; --i)
	{
	pArr->pBase [i+1] = pArr->pBase [i];
	}
	pArr->pBase [pos-1] = val;
	(pArr->cut )++;
	return true;
}

bool delete_arr(struct Arr *pArr, int pos, int *pVal/*, int * size */) //ɾ�� valɾ����ֵ
{
	int i;

	if(is_empty(pArr))    //�������Ϊ��
		return false;
	if(pos<1 || pos>pArr->cut )//���ɾ����λ��С��һ������ɾ����λ��������Чλ���������������
		return false;
	*pVal = pArr->pBase [pos-1];
	for(i=pos; i <= pArr->cut; ++i)
	{
		pArr->pBase [i-1] = pArr->pBase [i];
	}
	(pArr->cut )--;
/*	* size=pArr->cut ;*/
	printf("��Чλ��Ϊ%d\n",pArr->cut );
		return true;
}

void inversion_arr(struct Arr *pArr)  //����
{
	int i=0,j=pArr->cut-1,t;
	/*if(is_empty(pArr))    //�������Ϊ��
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

void sort_arr(struct Arr * pArr) //����
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
���壺
return����ֹ������ִ�кʹ�����ֵ,
return true�Ƿ���һ����ֵ.
return false�Ƿ���һ����ֵ.*/