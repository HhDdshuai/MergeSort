#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef int elemType;
//归并排序（二路归并）
/*假定待排序表含有n个记录，则可以看成是n个有序的子表，
每个子表长度为1，然后两两归并，...如此重复，直到合并成
一个长度为n的有序表为止*/
void Merge(elemType a[],elemType b[],int low,int mid,int high){
//表a的两段a[low...mid]和a[mid+1...high]各自有序，将它们合并成一个有序表
    int i,j,k;
    for(k = low;k <= high;k++)
        b[k] = a[k];        //先将a中所有元素复制到b中（a为排好序数组）
    for(i = low,j = mid + 1,k = i;i <= mid && j<= high;k++){  //k为归并之后的下标计数
        if(b[i] <= b[j])    //比较b的左右两段中的元素
            a[k] = b[i++];  //将较小值复制到a中
        else
            a[k] = b[j++];
    }
    while(i <= mid)
        a[k++] = b[i++];    //若第一个表未检测完，复制
    while(j <= high)        //两个while只会执行一个
        a[k++] = b[j++];
}
void MergeSort(elemType a[],elemType b[],int low,int high){
    if(low < high){         //递归边界（每个子序列为1时）
        int mid = (low + high) / 2;     //从中间划分两个子序列
        MergeSort(a,b,low,mid);           //对左侧子序列进行递归排序
        MergeSort(a,b,mid + 1,high);      //对右侧子序列进行递归排序
        Merge(a,b,low,mid,high);          //归并
    }
}
int main()
{
    elemType a[] = {12,89,54,12,33,1,5,64,99,53,8,19,564,324,74,58,987,31,54,
    74,45,4545,67,102,136,751,264,11,13,38};
    int len = sizeof(a)/sizeof(elemType);
    //动态分配辅助数组b的内存
    elemType *b = (elemType *)malloc((len + 1)*sizeof(elemType));
    MergeSort(a,b,0,len - 1);
    for(int i = 0;i < len;i++)
        printf("%d ",a[i]);
    return 0;
}
