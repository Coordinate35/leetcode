#include <stdio.h>
#include <stdlib.h>

int comp(const void* p, const void* q){ 
    return (*(int*) p - *(int*) q); 
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    if(nums ==NULL) return 0;
    if(numsSize <4) return 0;
    int **Ans = (int**)malloc(200*sizeof(int*));
    qsort(nums,numsSize,sizeof(int),comp);
    int a,b,c,d,count=0;;
    for(a=0; a < numsSize-3;a++){
        // check [a,x,x,x] mininum
        if(nums[a]+nums[a+1]+nums[a+2]+nums[a+3]>target)    
            break;
        // check [a,x,x,x] maxinum
        if(nums[a]+nums[numsSize-3]+nums[numsSize-2]+nums[numsSize-1]<target)
            continue;
        for(b=a+1;b<numsSize-2;b++){
            // check [a,b,x,x] mininu
            if(nums[a]+nums[b]+nums[b+1]+nums[b+2]>target)
                break;      
            // check [a,b,x,x] maxinum          
            if(nums[a]+nums[b]+nums[numsSize-2]+nums[numsSize-1]<target)
                continue;
            for(c=b+1,d = (numsSize-1);c<d;){
                if(nums[a]+nums[b]+nums[c]+nums[d]>target){
                    d--;
                }
                else if(nums[a]+nums[b]+nums[c]+nums[d]<target){
                    c++;
                }else{
                    Ans[count] = (int*)malloc(4*sizeof(int));
                    Ans[count][0]=nums[a];
                    Ans[count][1]=nums[b];
                    Ans[count][2]=nums[c];
                    Ans[count][3]=nums[d];
                    while(c<d && Ans[count][2]==nums[c]) c++;   
                    while(c<d && Ans[count][3]==nums[d]) d--;           
                    count++;
                    if(count % 200 == 0)
                        Ans = (int**)realloc(Ans,sizeof(int*)*(count+200));
                }
            }
            while(b<numsSize-1 && nums[b+1] == nums[b]) b++;    
        }
        while(a<numsSize-1 && nums[a+1] == nums[a]) a++;        
    }
    *returnSize = count;
    return (int**)realloc(Ans,sizeof(int*)*count);
}

/*
void quick_sort(int* nums, int start, int end)
{
	int i, reference, buffer, j;
	reference = nums[start];
	j = start;
	if (start == end)
	{
		return;
	}
	for (i = start; i <= end; i++)
	{
		if (nums[i] < reference)
		{
			buffer = nums[i];
			nums[i] = nums[j];
			nums[j] = buffer;
			j += 1;
		}
	}
	if (j > start + 1)
	{
		quick_sort(nums, start, j - 1);
	}
	if (j < end)
	{
		if (j == start)
		{
			j += 1;
		}
		quick_sort(nums, j, end);
	}
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int first, second, third, fourth, sum;
    int first_edge = numsSize - 3;
    int second_edge = numsSize - 2;
    int size = 0;
    int **result;
    int *one_result;
    quick_sort(nums, 0, numsSize - 1);
    result = (int**)malloc(sizeof(int*));
    *returnSize = 0;
    if (numsSize == 0)
    {
        return NULL;
    }
    for (first = 0; first < first_edge; first++)
    {
    	for (second = first + 1; second < second_edge; second++)
    	{
    		third = second + 1;
    		fourth = numsSize - 1;
    		while (fourth > third)
    		{
    			sum = nums[first] + nums[second] + nums[third] + nums[fourth];
    			if (sum > target)
    			{
    				fourth -= 1;
    			}
    			else if (sum < target)
    			{
    				third += 1;
    			}
    			else
    			{
    				size += 1;
    				result = (int**)realloc(result, size * sizeof(int*));
    				one_result = (int*)malloc(4 * sizeof(int));
    				one_result[0] = nums[first];
    				one_result[1] = nums[second];
    				one_result[2] = nums[third];
    				one_result[3] = nums[fourth];
    				result[size - 1] = one_result;    				
    				while (nums[third + 1] == nums[third])
    				{
    					third += 1;
    				}
    				while (nums[fourth + 1] == nums[fourth])
    				{
    					fourth -= 1;
    				}
    				fourth -= 1;
    				third += 1;
    			}
    		}
            while (nums[second + 1] == nums[second])
            {
                second += 1;
            }   
    	}
        while (nums[first + 1] == nums[first])
        {
            first += 1;
        }
    }
    if (size == 0)
    {
    	return NULL;
    }
    else
    {
        *returnSize = size;
    	return result;
    }
}
*/

int main()
{
	int nums[] = {-9,4,0,-3,6,3,-3,-9,-7,1,0,-7,-8,7,1};
	int numsSize = 15;
	int target = -9;
	int returnSize, i, j;
	int **result;
	result = fourSum(nums, numsSize, target, &returnSize);
	for (i = 0; i < returnSize; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	/*
	quick_sort(nums, 0, numsSize - 1);
	for (i = 0; i < numsSize; i++)
	{
		printf("%d ", nums[i]);
	}
	*/
	return 0;
}