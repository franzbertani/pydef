#ifndef HEADER_H
#define HEADER_H
    #include "header.h"
#endif

void heapify(task_struct_t* a[],int n) {
    task_struct_t *item;
    int k,i,j;
    for (k=1;k<n;k++) {
        item = a[k];
        i = k;
        j = (i-1)/2;
        while((i>0)&&(item->deadline[item->deadlineVersion] > a[j]->deadline[a[j]->deadlineVersion])) {
            a[i] = a[j];
            i = j;
            j = (i-1)/2;
        }
        a[i] = item;
    }
}


void adjust(task_struct_t* a[],int n) {
    int i,j;
    task_struct_t* item;
    j = 0;
    item = a[j];
    i = 2*j+1;
    while(i<=n-1) {
        if(i+1 <= n-1)
           if(a[i]->deadline[a[i]->deadlineVersion] < a[i+1]->deadline[a[i+1]->deadlineVersion])
            i++;
        if(item->deadline[item->deadlineVersion] < a[i]->deadline[a[i]->deadlineVersion]) {
            a[j] = a[i];
            j = i;
            i = 2*j+1;
        } else
           break;
    }
    a[j] = item;
}

void heapsort(task_struct_t* a[],int n) {
    task_struct_t* t;
    int i;
    heapify(a,n);
    for (i=n-1;i>0;i--) {
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        adjust(a,i);
    }
}
