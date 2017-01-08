#ifndef _SEARCH_H
#define _SEARCH_H
bool binSearch(int *a , int &k , int n){
	for(int mid , start = 0 , end = n-1 ;;){
		if(start > end)break;
		mid = (start&end) + ((start^end)>>1);
		if(a[mid] == k){k = mid;return true;}
		if(a[mid] > k){
			end = mid - 1;
		}else {
			start = mid + 1;
		}
	}
	return false;
}
bool binSearchCycle(int *a , int &k , int start , int end){
	if(start < end){
		end--;
		int mid = (start&end) + ((start^end)>>1);
		if(a[mid] == k){
			k = mid;
			return true;
		}
		if(binSearchCycle(a , k , start , mid))return true;
		if(binSearchCycle(a , k , mid + 1 , end+1))return true;
	}
	return false;
}
#endif