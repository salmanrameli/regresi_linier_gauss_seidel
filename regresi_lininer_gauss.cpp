#include <stdio.h>

int main()
{
	int i, j, k; //variabel looping
	int n; //variabel menyimpan jumlah total data
	float a0 = 0, a1 = 0, a2 = 0;
	char lanjut = 'y';
	
	printf("Masukkan jumlah data: ");
	scanf("%d", &n);
	
	float tabel[n][7];
	
	n = n*1.0;
	
	float xi = 0, xi2 = 0, xi3 = 0, xi4 = 0;
	float yi = 0, xiyi = 0, xi2yi = 0;
	
	for(i=0;i<n;i++)
	{
		printf("Masukkan nilai Xi ke-%d: ", i+1);
		scanf("%f", &tabel[i][0]);
	}
	
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		printf("Masukkan nilai Yi ke-%d: ", i+1);
		scanf("%f", &tabel[i][1]);
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
	
//	printf("\nXi\tYi\tXi2\tXi3\tXi4\tXiYi\tXi2Yi\n");
//	for(i=0;i<n;i++)
//	{
//		for(j=0;j<7;j++)
//		{
//			printf ("%f\t", tabel[i][j]);
//		}
//		printf("\n");
//	}
//	
//	printf("%f\t", xi);
//	printf("%f\t", yi);
//	printf("%f\t", xi2);
//	printf("%f\t", xi3);
//	printf("%f\t", xi4);
//	printf("%f\t", xiyi);
//	printf("%f\t", xi2yi);

	//melakukan perhitungan menggunakan metode gauss - seidel
	while(lanjut != 'n')
	{
		a0 = (yi - (xi * a1) - (xi2 * a2)) / n;
		
		a1 = (xiyi - (xi * a0) - (xi3 * a2)) / xi2;
		
		a2 = (xi2yi - (xi2 * a0) - (xi3 * a1)) / xi4;
		
		printf("\na0 = %.3f\n", a0);
		printf("a1 = %.3f\n", a1);
		printf("a2 = %.3f\n", a2);
		
		getchar();
		printf("lanjutkan perhitungan? (y/n)\n");
		scanf("%c", &lanjut);
		
		if(lanjut == 'n')
		{
			break;
		}
	}
}
