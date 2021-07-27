#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define min(a,b) (a>b ? b : a)
#define N 50000


//Linear Search 
int linearSearch(int arr[] , int size , int x)
{
    int i;
	for(i=0;i<size ; i++)
	{
		if(arr[i] == x)
			return i;
	}
	return -1;
}

//Binary Search
int binaraySearch(int arr[] , int lo , int hi , int x)
{
	if(lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		if(arr[mid] == x)
			return mid;
		if(arr[mid] > x)
			return binaraySearch(arr,lo,mid-1,x);
		if(arr[mid] < x)
			return binaraySearch(arr,mid+1,hi,x);		
	}
	return -1;
}

// Jump Search
int jumpSearch(int arr[] , int size , int x)
{
	int step = (int) sqrt(size);
	int prev = 0;
	while(arr[min(step,size) -1] < x)
	{
		prev = step;
		step += (int) sqrt(size);
		if(prev > size)
			return -1;
	}
	
	while(arr[prev] < x)
	{
		prev++;
		if(prev == min(step , size))
			return -1;
	}
	
	if(arr[prev] == x)
		return prev;
	return -1;
}


//Interpolation Search
int interpolationSearch(int arr[] , int lo , int hi , int x)
{
	int pos;
	if(lo <= hi && x >= arr[lo] && x <= arr[hi])
	{
		pos = lo + (int)( ((hi - lo) * (x - arr[lo])) / (arr[hi] - arr[lo]) );
		if(arr[pos] == x)
			return pos;
		if(arr[pos] > x)
			return interpolationSearch(arr,lo,pos -1 , x);	
		if(arr[pos] < x)
			return interpolationSearch(arr,pos + 1,hi , x);	
	}
	return -1;
}

int main(int argc,char** argv)
{
	int arr[N];
	
	FILE *pf;
	
	pf = fopen("data.txt","r");
	if(pf == NULL)
	{
		fprintf(stderr,"Failed To Open The File .\n");
		return 1;
	}	
	
	int i=0;
	while(!feof(pf))
	{
		fscanf(pf,"%d\n",&arr[i]);
		i++;
	}
	
	
	int x = 9760;
	clock_t start , end ;
	
	start = clock();
	printf("Interpolation Search Index : %d .\n",interpolationSearch(arr,0,N-1,x));
	end = clock();
	printf("Time Spent By InterPolation Search : %.lf ms .\n\n",(double) (end - start) );
	
	start = clock();
	printf("Linear Search Index : %d .\n",linearSearch(arr,N,x));
	end = clock();
	printf("Time Spent By Linear Search : %.lf ms .\n\n",(double) (end - start) );
	
	start = clock();
	printf("Binary Search Index : %d .\n",binaraySearch(arr,0,N-1,x));
	end = clock();
	printf("Time Spent By Binary Search : %.lf ms .\n\n",(double) (end - start) );
	
	start = clock();
	printf("Jump Search Index : %d .\n",jumpSearch(arr,N,x));
	end = clock();
	printf("Time Spent By Jump Search : %.lf ms .\n\n",(double) (end - start) );	
	
		
	fclose(pf);
	return 0;
}