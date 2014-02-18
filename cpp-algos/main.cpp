//
//  main.cpp
//  cpp-algos
//
//  Created by Ash Booth on 14/02/2014.
//  Copyright (c) 2014 Ash Booth. All rights reserved.
//

#include <iostream>
#include <limits>

void print_array(int data[], int length)
{
    for (int i = 0; i < length; i++) {
        std::cout << data[i] << ", ";
    }
    std::cout << std::endl;
}

void insertion_sort(int data[], int p, int r)
{
    int length = r-p;
    for(int i = 1; i < length; ++i)
    {
        int key = data[i];
        int j = i-1;
        while (j>=0 && data[j]>key) {
            data[j+1] = data[j];
            j-=1;
        }
        data[j+1] = key;
    }
}

void merge(int data[], int p, int q, int r)
{
    int length1 = q-p+1;
    int length2 = r-q;
    int left_array[length1+1];
    int right_array[length2+1];
    for (int i = 0; i<length1; i++) {
        left_array[i] = data[p+i];
    }
    for (int j=0; j<length2; j++) {
        right_array[j] = data[q+j+1];
    }
    left_array[length1] = std::numeric_limits<int>::max();
    right_array[length2] = std::numeric_limits<int>::max();
    int i = 0;
    int j = 0;
    for (int k = p; k<=r; k++) {
        if (left_array[i] <=right_array[j]) {
            data[k] = left_array[i];
            i+=1;
        }
        else {
            data[k] = right_array[j];
            j+=1;
        }
    }
}

void merge_sort(int data[],int p, int r)
{
    if(p<r) {
        int q = (p+r)/2;
        merge_sort(data, p, q);
        merge_sort(data, q+1, r);
        merge(data, p, q, r);
    }
}

void run_exp(int data[], int n, int m, void (*f)(int[],int,int))
{
    for (int i=0; i<n; i++) {
        int arr[m];
        for(int j=0; j<m;j++) {
            arr[j] = rand() % 101;
        }
        std::cout << "before sorting:" << std::endl;
        print_array(arr, m);
        (*f)(data,0,m);
        std::cout << "After sorting:" << std::endl;
        print_array(arr, m);
        std::cout << std::endl;
    }

}


int main(int argc, const char * argv[])
{
    int n = 5;
    int m = 10;

    int a [] = {1,11,5,7,9,2,4,0,8};
    
    std::cout << "before:" << std::endl;
    print_array(a, m);
    merge_sort(a, 0, m);
    std::cout << "after:" << std::endl;
    print_array(a, m);
    
    return 0;
}

