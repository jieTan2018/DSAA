#include <iostream>
#include"generic.h"
#include"insertSort.h"
#include"swapSort.h"
#include"selectSort.h"
#include"mergeSort.h"
#include"distributionSort.h"
#include"GeneralSort.h"
using namespace std;

int main()
{
    ////int init_array[] = { 2,5,1,9,3,8,2 1,4,11,13,7,22,17 };
    //int init_array[] = { 2,5,1,9,3,8 };
    ////int init_array[] = { 2,5,9,3 };
    //int arr_length = sizeof(init_array) / sizeof(int);
   /*int large_array[] = { 2,5,1,9,3,8,21,4,11,13,7,22,12,17,6,56,34,26,43,27,26,31,36,41,89,47,19,67,56,77,51,59,42,60 };
    int large_length = sizeof(large_array) / sizeof(int);*/
    //int* orig_array=dynamicArray<int>(init_array, ++arr_length);

    /*cout << "插入排序：\n";
    printArray(insertSort(init_array, arr_length), arr_length, 1);
    cout << "********************\n";*/
    /*cout << "希尔排序：\n";
    printArray(shellSort(orig_array, arr_length), arr_length, 1);*/

   /* cout << "冒泡排序：\n";*/
    //printArray(bubbleSort(init_array, arr_length), arr_length);
    //printArray(bubbleFlagSort(large_array, arr_length), arr_length);

    //cout << "快速排序：\n";
    ///*int demo[] = { 23,13,49,6,31,19,28 };
    //arr_length = sizeof(demo) / sizeof(int);*/
    //printArray(quickSort(large_array, 0, arr_length - 1), arr_length);

    //cout << "简单选择排序：\n";
    ///*int demo[] = { 23,13,49,6,31,19,28 };
    //arr_length = sizeof(demo) / sizeof(int);*/
    //printArray(simpleSelectSort(large_array, arr_length), arr_length);

    /*cout << "堆排序：\n";
    int demo[] = { 47,35,26,26,18,7,13,19 };
    arr_length = sizeof(demo) / sizeof(int);
    int* orig_array = dynamicArray<int>(demo, ++arr_length);
    printArray(heapSort(orig_array, arr_length - 1), arr_length, 1);*/

    /*cout << "归并排序：\n";
    tmpFunc();*/
    //delete[] orig_array;

    //int init_array[] = { 3,5,3,1,5,6,3,8,12, 3,5,1,7,8 };
    int init_array[] = { 61,98,12,15,20,24,31,23,35,35,123,34,12,55,678,6,33,56,78,29,10,435,654,78 };
    int arr_length = sizeof(init_array) / sizeof(int);

    GeneralSort gs(init_array, arr_length);
    cout << "原始序列：";
    gs.printArray();
    //gs.insertSort();
    //gs.shellSort();
    //gs.bubbleSort();
    //gs.quickSort();
    //gs.simpleSelectSort();
    //gs.heapSort();
    //gs.mergeSort();
    //gs.recursionMergeSort();
    //gs.bucketSort(12+1);
    gs.radixSort(678);
    cout << "排序结果：";
    gs.printArray();

    //myMain();
}
