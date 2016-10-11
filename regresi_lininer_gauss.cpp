#include <stdio.h>

int main()
{
	int i, j, k; //variabel looping
	int n; //variabel menyimpan jumlah total data
	int a0 = 0, a1 = 0, a2 = 0;
	
	printf("Masukkan jumlah data: ");
	scanf("%d", &n);
	
	int tabel[n][7];
	
	int xi = 0, xi2 = 0, xi3 = 0, xi4 = 0;
	int yi = 0, xiyi = 0, xi2yi = 0;
	
	for(i=0;i<n;i++)
	{
		printf("Masukkan nilai Xi ke-%d: ", i+1);
		scanf("%d", &tabel[i][0]);
	}
	
	for(i=0;i<n;i++)
	{
		printf("Masukkan nilai Yi ke-%d: ", i+1);
		scanf("%d", &tabel[i][1]);
	}
	
	for(i=0;i<n;i++)
	{
		tabel[i][2] = tabel[i][0] * tabel[i][0]; //menghitung nilai perkalian Xi^2
		tabel[i][3] = tabel[i][2] * tabel[i][0]; //menghitung nilai perkalian Xi^3
		tabel[i][4] = tabel[i][3] * tabel[i][0]; //menghitung nilai perkalian Xi^4
		tabel[i][5] = tabel[i][0] * tabel[i][1]; //menghitung nilai perkalian Xi * Yi
		tabel[i][6] = tabel[i][2] * tabel[i][1]; //menghitung nilai perkalian Xi^2 * Yi
	}
	
	//menghitung total dari setiap kolom pada tabel
	for(i=0;i<5;i++)
	{
		xi += tabel[i][0];
		yi += tabel[i][1];
		xi2 += tabel[i][2];
		xi3 += tabel[i][3];
		xi4 += tabel[i][4];
		xiyi += tabel[i][5];
		xi2yi += tabel[i][6];
	}
	
	printf("\nXi\tYi\tXi2\tXi3\tXi4\tXiYi\tXi2Yi\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<7;j++)
		{
			printf ("%d\t", tabel[i][j]);
		}
		printf("\n");
	}
	
	printf("%d\t", xi);
	printf("%d\t", yi);
	printf("%d\t", xi2);
	printf("%d\t", xi3);
	printf("%d\t", xi4);
	printf("%d\t", xiyi);
	printf("%d\t", xi2yi);
}
