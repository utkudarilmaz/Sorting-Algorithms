#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>


//#define SIZE 10000
void quicksort(int *a, int high, int low)
{
    if (low>=high) {
        return;
    }
    int pivot=high;
    int head=low-1;
    int index=low;
    int tmp;
    while(index<=pivot){
        if(a[index]>a[pivot]){
            index++;
            continue;
        }
        else if(a[index]<a[pivot]){
            head++;
            tmp=a[head];
            a[head]=a[index];
            a[index]=tmp;
            index++;
            continue;
        }
        if(index==pivot){
            tmp=a[pivot];
            a[pivot]=a[head+1];
            a[head+1]=tmp;
            break;
        }
    }
    quicksort(a, head, low);
    quicksort(a, index, head+1);
    return;
}

void merge_sort (int *a, int size)
{
    //Fill this function

}

void selection_sort (int *a, int size)
{
    int i,j,temp;
    for(i=0; i<size; i++)
	{
		for(j=i+1; j<size; j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void insertion_sort(int *a, int size)
{
    //Fill this function

}


int main (int argc, char **argv)
{

    int size = atoi(argv[1]);
    int choice = atoi(argv[2]);

    srand(time(NULL));
    int  *a = (int *)malloc(sizeof(int)*size);
    int i;
    for(i=0;i<size;i++){
        a[i] = rand()%1000;
    }

    int n = size;
    struct timeval stop, start;
    gettimeofday(&start, NULL);

    if(choice == 1){
        printf("Selection sort is selected\n");
        selection_sort(a, size);
    }
    if(choice == 2){
        printf("Insertion sort is selected\n");
        insertion_sort(a, size);
    }
    if(choice == 3){
        printf("Merge sort is selected\n");
        merge_sort(a, size);
    }
    if(choice == 4){
        printf("Quick sort is selected\n");
        quicksort(a,n-1,0);
    }

    gettimeofday(&stop, NULL);

    float elapsed = (stop.tv_sec - start.tv_sec) * 1000.0f + (stop.tv_usec - start.tv_usec) / 1000.0f;
    printf("Code executed in %f milliseconds.\n", elapsed);


    return 0;
}
