//
//  main.cpp
//  moreThanHalf
//
//  Created by LiLingyu on 15/10/20.
//  Copyright © 2015年 LiLingyu. All rights reserved.
//

#include <iostream>

/*
 已知有数组里面有个元素出现次数超过一半，问如何找出这个数，时间复杂度O(n)，空间复杂度O(1)
 常见的hashmap时间复杂度为O(n)，空间复杂度为O(n)，不是最优选
 */
bool isMoreThanHalf(int* a, int len, int number)
{
    int counter = 0;
    for (int i=0; i<len; i++) {
        if (a[i]==number) {
            counter++;
            if (counter*2>len) {
                return true;
            }
        }
    }
    
    return false;
}

int moreThanHalf(int* a, int len)
{
    int counter = 1;
    int tmp = a[0];
    for (int i=1; i<len; i++) {
        if(a[i]==tmp)
        {
            counter++;
        }
        else
        {
            counter--;
            if (counter<=0) {
                tmp=a[i];
                counter=1;
            }
        }
    }
    /*
    if (counter>=0) {
        return tmp;
    }
    else{
        return -1;
    }*/
    
    if (isMoreThanHalf(a, len, tmp)) {
        return tmp;
    }
    else
    {
        printf("error: no number appears more than half times!\n");
        return -1;
    }
    
    
    
}

int main(int argc, const char * argv[]) {

    const int len=10;
    int a[len] = {1, 1, 5, 5, 1, 5, 1, 5, 5, 5};
    for (int i=0; i<len; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
    printf("result: \n");
    printf("%d\n", moreThanHalf(a, len));
    return 0;
}
