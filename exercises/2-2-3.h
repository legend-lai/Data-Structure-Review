//Pseudo Code

#ifndef _2_2_3_H
#define _2_2_3_H
#include "sqlist.h"
#include <cstring>

//1
template<typename T>
bool delMin(SqList<T> &list, T &val){
    if(!list.length)
        return false;
    int MinInd = 0;
    val = list[0];
    for(int i = 1; i < list.length; ++i){
        if(list[i] < val)
            val = list[i], MinInd = i;
    }
    list[MinInd] = list[list.length - 1];
    list.length --;
    return true;
}


//2
template<typename T>
void reverse(SqList<T> &list){
    T tmp;
    for(int i = 0; i < list.length / 2; ++i){
        tmp = list[i];
        list[i] = list[list.length - i - 1];
        list[list.length - i - 1] = tmp;
    }
}



//3
template<typename T>
void delVal(SqList<T> &list, const T& val){
    int num = 0;
    for(int i = 0; i < list.length; i++){
        if(list[i] == val)
            num ++;
        else
            list[i-num] = list[i];
    }
    list.length -= num;
}


//4
template<typename T>
bool delRangeinOrderedSqList(SqList<T> &list, const T& s, const T& t){
    if(s >= t || !list.length) return false;

    int lpos, rpos;
    int low = 0, high = list.length-1, mid;

    while(low < high){
        mid = (low + high) / 2;
        if(list[mid] >= s) high = mid;
        else if(list[mid] < s) low = mid + 1;
    }
    if(list[high] < s || list[high] > t) return true;
    lpos = high;

    low = 0, high = list.length - 1;
    while(low < high){
        mid = (low + high) / 2;
        if(mid == low) mid++;
        if(list[mid] <= t) low = mid;
        else if(list[mid] > t) high = mid - 1;
    }
    rpos = low;

    int i, k;
    for(i = rpos + 1, k = 0; i < list.length; ++i, ++k){
        list[lpos + k] = list[i];
    }
    list.length -= (rpos - lpos + 1);
    return true;
}


//5
template<typename T>
bool delRangeinUnorderedSqList(SqList<T> &list, const T& s, const T& t){
    if(s >= t || !list.length) return false;
    int k = 0;
    for(int i = 0; i < list.length; ++i){
        if(list[i] > t || list[i] < s)
            list[k] = list[i], k++;
    }
    list.length = k;
    return true;
}



//6
template<typename T>
void delRepeatIteminOrderedList(SqList<T> &list){
    if(!list.length) return ;
    T val = list[0];
    int k = 1;
    for(int i = 1; i < list.length; i++){
        if(val != list[i])
            list[k] = list[i], val = list[i], k++;
    }
    list.length = k;
}



//7
template<typename T>
bool merge(SqList<T> &A, SqList<T> &B, SqList<T> &C){
    if(C.MaxLength < A.length + B.length) return false;
    int i = 0, j = 0, k = 0;
    while(i < A.length && j < B.length){
        C[k++] = A[i] < B[j] ? A[i++] : B[j++];
    }
    while(i < A.length)
        C[k++] = A[i++];
    while(j < B.length)
        C[k++] = B[j++];
    C.length = k;
    return true;
}



//8
template<typename T>
bool mnReverse(T ary[], int length, const int& m, const int& n){
    if(m + n != length) return false;
    T tmp;
    for(int i = 0; i < length / 2; i++){
        tmp = ary[i];
        ary[i] = ary[length - i - 1];
        ary[length - i - 1] = tmp;
    }
    for(int i = 0; i < n / 2; i++){
        tmp = ary[i];
        ary[i] = ary[n - i - 1];
        ary[n - i - 1] = tmp;
    }
    for(int i = n; i < n + m / 2; i++){
        ary = ary[i];
        ary[i] = ary[2 * n + m - i - 1];
        ary[2 * n + m - i - 1] = tmp;
    }
    return true;
}



//9
template<typename T>
void nine(SqList<T> &list, const T& x){
    if(!list.length){
        list[list.length++] = x;
        return ;
    }
        
    int low = 0, high = list.length - 1, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(list[mid] == x) break;
        if(list[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if(list[mid] == x && mid != list.length - 1)
        std::swap(list[mid], list[mid+1]);
    
    int i;
    if(low > high){
        for(i = list.length - 1; i > high; i--) list[i+1] = list[i];
        list[i+1] = x;
        list.length++;
    }
}


//10
template<typename T>
void reverse(T ary[], int left, int right){
    T tmp;
    for(int i = left; i < (left + right + 1) / 2; i++)
        std::swap(ary[i], ary[right + left - i]);
}

template<typename T>
void ten(T ary[], const int& n, const int& p){
    reverse(ary, 0, n - 1);
    reverse(ary, 0, n - p - 1);
    reverse(ary, n - p, n - 1);
}


//11
//不等长
template<typename T>
T median(SqList<T> &a, SqList<T> &b){
    int pos = (a.length + b.length + 1) / 2;
    int i = 0, j = 0, ch = ' ';
    while(i < a.length && j < b.length && pos--){
        if(a[i] <= b[j])
            ++i, ch = 'a';
        else
            ++j, ch = 'b';
    }
    if(pos > 0)
        while(i < a.length && pos--)
            ch = 'a', i++;
    if(pos > 0)
        while(j < b.length && pos--)
            ch = 'b', j++;
    if(ch == 'a')
        return a[i-1];
    else
        return b[j-1];
}


//等长(两边靠近的思想)
template <typename T>
T median2(SqList<T> &a, SqList<T> &b){
    int al, bl, ar, br, am, bm;
    al = bl = 0;
    ar = a.length - 1;
    br = b.length - 1;
    while(al != ar || bl != br){
        am = (al + ar) / 2;
        bm = (bl + br) / 2;
        if(a[am] == b[bm]) return a[am];
        else if(a[am] < b[bm])
            if((al + ar) % 2)   //偶数
                al = am + 1, br = bm;
            else
                al = am, br = bm;
        else
            if((bl + br) % 2)   //偶数
                bl = bm + 1, ar = am;
            else
                bl = bm, ar = am; 
    }
    return a[al] < b[bl] ? a[al] : b[bl];
}


//12
int mainItem(int ary[], const int& n){
    int tmp = ary[0], cnt = 1;
    for(int i = 1; i < n; i++){
        if(tmp == ary[i]) cnt++;
        else
            if(cnt == 1) tmp = ary[i];
            else cnt--;
    }
    cnt = 0;
    for(int i = 0; i < n; i++)
        if(ary[i] == tmp) cnt++;
    return cnt > n / 2? tmp : -1;
}


//13
int minpInt(int ary[], const int& n){
    bool* mask = new bool[INT_MAX];
    
    for(int i = 0; i < n; i++)
        if(ary[i] > 0) mask[ary[i]] = 1;
    for(int i = 1; i < n; i++)
        if(!mask[i]) return i;
}


//14
bool xmin(const int &x, const int &y, const int &z){
    return x <= y && x <= z;
}


int minD(int A[], int a, int B[], int b, int C[], int c){
    int i = 0, j = 0, k = 0;
    int dis, minDis = INT_MAX, minVal;
    while(i < a && j < b && j < c && minDis > 0){
        dis = abs(A[i] - B[j]) + abs(A[i] - C[k]) + abs(B[j] - C[k]);
        if(dis < minDis) minDis = dis;
        if(xmin(A[i], B[j], C[k])) ++i;
        else if(xmin(B[i], A[j], C[k])) ++j;
        else ++k;
    }
    return minDis;
}



#endif



