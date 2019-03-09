#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef int elemType;
//�鲢���򣨶�·�鲢��
/*�ٶ����������n����¼������Կ�����n��������ӱ�
ÿ���ӱ���Ϊ1��Ȼ�������鲢��...����ظ���ֱ���ϲ���
һ������Ϊn�������Ϊֹ*/
void Merge(elemType a[],elemType b[],int low,int mid,int high){
//��a������a[low...mid]��a[mid+1...high]�������򣬽����Ǻϲ���һ�������
    int i,j,k;
    for(k = low;k <= high;k++)
        b[k] = a[k];        //�Ƚ�a������Ԫ�ظ��Ƶ�b�У�aΪ�ź������飩
    for(i = low,j = mid + 1,k = i;i <= mid && j<= high;k++){  //kΪ�鲢֮����±����
        if(b[i] <= b[j])    //�Ƚ�b�����������е�Ԫ��
            a[k] = b[i++];  //����Сֵ���Ƶ�a��
        else
            a[k] = b[j++];
    }
    while(i <= mid)
        a[k++] = b[i++];    //����һ����δ����꣬����
    while(j <= high)        //����whileֻ��ִ��һ��
        a[k++] = b[j++];
}
void MergeSort(elemType a[],elemType b[],int low,int high){
    if(low < high){         //�ݹ�߽磨ÿ��������Ϊ1ʱ��
        int mid = (low + high) / 2;     //���м仮������������
        MergeSort(a,b,low,mid);           //����������н��еݹ�����
        MergeSort(a,b,mid + 1,high);      //���Ҳ������н��еݹ�����
        Merge(a,b,low,mid,high);          //�鲢
    }
}
int main()
{
    elemType a[] = {12,89,54,12,33,1,5,64,99,53,8,19,564,324,74,58,987,31,54,
    74,45,4545,67,102,136,751,264,11,13,38};
    int len = sizeof(a)/sizeof(elemType);
    //��̬���丨������b���ڴ�
    elemType *b = (elemType *)malloc((len + 1)*sizeof(elemType));
    MergeSort(a,b,0,len - 1);
    for(int i = 0;i < len;i++)
        printf("%d ",a[i]);
    return 0;
}
