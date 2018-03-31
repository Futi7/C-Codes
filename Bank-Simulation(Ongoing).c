#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10

enum islemler
{
	EFT=1,
	PC=2,
	KC=3,
	FO=4
};
int maksMusteri=-1;	//Enqueda çalýþacak olan kuyruktaki maksimum bekleyen müþteri sayýsýný tutacak deðiþken.
int	kuyrukSayac=0;  //Enqueda 1 artacak dequeda 1 azalacak olan sayac.
typedef enum islemler islem;

struct atm
{
	int aSuresi;			//Atm'nin hizmet süresi.
	int mSayisi;			//Toplam müþteri sayýsý.
	int atmKontrol;		//Atm'de önceden müþteri olup olmadýðýný kontrol etmek için.
	int sonMusteri;
};
typedef struct atm atm;

struct musteri
{
	int no;//Müþteri numarasý.
	int iSuresi;//Ýþlem süresi.
	int bSuresi;//Bekleme süresi.
	islem isl;//Ýþlem tipi.	
};
typedef struct musteri musteri;
struct queue
{
	musteri mst;
	struct queue *next;
};
typedef struct queue que;

que *root,*rear;

int size=0;
int isEmpty(que *temp)
{
	if(root!=NULL)
		return 0;
	else
		return 1;
}
musteri dequeue()
{
	int i;
	musteri result;
	if(root==NULL)
		printf("Sira bos\n");
	else
	{
    que *temp;
    result=root->mst;
    temp=root;
    root=root->next;
    free(temp);
    size--;
    return result;
	}
}


void enqueue(musteri mst)
{
	if(size==0)
	{
		root=(que*)malloc(sizeof(que));
		root->mst=mst;
		root->next=NULL;
		root->next=rear;
		
	}
	else
	{
	rear=(que*)malloc(sizeof(que));
	rear->mst=mst;
	rear->next=NULL;
	}
	size++;
	kuyrukSayac++;
	if(maksMusteri<kuyrukSayac)
	maksMusteri=kuyrukSayac;
}
//EFT PC KC FO


int islemSure(musteri tmp)
{
	tmp.isl=rand()%5+1;
	switch (tmp.isl)
	{
		case 1:
			return rand()%8+3;
		case 2:
			return rand()%11+10;
		case 3:
			return rand()%11+2;
		case 4:
			return rand()%7+1;
	}
}

int main()
{
	musteri tmp;
	musteri tempEmployee;
	int yeniMusteri;
	atm atmDizi[3];
	atmDizi[0].aSuresi=0;
	atmDizi[1].aSuresi=0;
	atmDizi[2].aSuresi=0;
	atmDizi[0].atmKontrol=0;
	atmDizi[1].atmKontrol=0;
	atmDizi[2].atmKontrol=0;
	int counter=0,i=0,j=0;
	int current=0;	//Sayaçlarda kod karýþýklýklarý olmamasý için 'current' isimli farklý bir deðiþken tanýmladým
	int dakika;

	int temp;
	printf("Simulasyon dakikasini girin.\n");
	scanf("%d",&dakika);
	srand(time(NULL));
	

	//Artýk simülasyon boyunca gelecek olan müþterilerin geliþ dakikalarý belli ve sýralý.
	current=1;
	i=1;
	musteri	employee;
	int enuzunBSuresi=-1;
	int ortBSuresi=0;
	int ortSayac=0;
	int enuzunBMusteri;
	yeniMusteri=rand()%6+1;
	while(counter<dakika)
	{
		
		printf("---%d. dakika---\n****\n",counter);
		if(yeniMusteri==0)
		{
			yeniMusteri=rand()%6+1;//6
			employee.no=i;
			employee.bSuresi=0;
			enqueue(employee);
			printf("%d.Musteri siraya girdi.\n\n",employee.no);
			i++;
		}
		
		
		if(atmDizi[0].aSuresi==0)
		{
			if(atmDizi[0].atmKontrol==1){
			atmDizi[0].atmKontrol=0;
			printf("%d nolu musteri 1.atmden cikis yapti.\n",atmDizi[0].sonMusteri,counter);
			atmDizi[0].sonMusteri=tempEmployee.no;
			}
			if(!isEmpty(root))
			{
				ortBSuresi+=employee.bSuresi;
				ortSayac++;
			tempEmployee=dequeue();
			printf("%d. musteri 1. atmde islem yapmaya basladi.\n",tempEmployee.no);
			atmDizi[0].aSuresi=islemSure(tempEmployee);
			atmDizi[0].atmKontrol=1;
			}
			
		}
		
		else if(atmDizi[1].aSuresi==0)
		{	
			if(atmDizi[1].atmKontrol==1){
			atmDizi[1].sonMusteri=tempEmployee.no;
			printf("%d nolu musteri 2. atmden cikis yapti.\n",atmDizi[1].sonMusteri,counter);
			atmDizi[1].atmKontrol=0;}
			if(!isEmpty(root))
			{
			tempEmployee=dequeue();
			printf("%d. musteri 2. atmde islem yapmaya basladi.\n",tempEmployee.no);
			atmDizi[1].aSuresi=islemSure(tempEmployee);
			atmDizi[1].atmKontrol=1;
			}
			
		}
		else if(atmDizi[2].aSuresi==0)
		{
			if(atmDizi[2].atmKontrol==1)
			{
			atmDizi[2].sonMusteri=tempEmployee.no;
			printf("%d nolu musteri 3. atmden cikis yapti.\n",atmDizi[2].sonMusteri,counter);
			
			atmDizi[2].atmKontrol=0;}
			if(!isEmpty(root))
			{
			tempEmployee=dequeue();
			printf("%d. musteri 3. atmde islem yapmaya basladi.\n",tempEmployee.no);
			atmDizi[2].aSuresi=islemSure(tempEmployee);
			atmDizi[2].atmKontrol=1;
			}
			
		}
		
		counter++;
		
		yeniMusteri--;
		if(atmDizi[0].aSuresi!=0)
		atmDizi[0].aSuresi--;
		if(atmDizi[1].aSuresi!=0)
		atmDizi[1].aSuresi--;
		if(atmDizi[2].aSuresi!=0)
		atmDizi[2].aSuresi--;
		if(employee.bSuresi>enuzunBSuresi)
		{
			enuzunBSuresi=employee.bSuresi;
			enuzunBMusteri=employee.no;
		}
		employee.bSuresi++;
		
	}			printf("\n\n***En uzun kuyruk %d kisi.\n\n***Sirada en cok bekleyen %d nolu musteri,%d dakika.\n\n***Ortalama sirada bekleme suresi %d",maksMusteri,enuzunBMusteri,enuzunBSuresi,ortBSuresi);
		/*Hocam ödeve geçen hafta baþladým algoritmayý yanlýþ kurdum çok fazla hata aldým düzeltmeye çalýþtým olmadý programý 2. kez yapýyorum o 
		yüzden bu kadar geciktim.
		*/
		return 0;
}









