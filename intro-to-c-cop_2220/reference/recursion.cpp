//#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h> 
//#include <ctype.h>
//#include<string>
//
////0110
////010
////01
//
//bool palindrome(int arr[], int n, int i)
//{
//	int begin = i;
//	int end = n - i - 1;
//	int equivalent;
//	int next_equivalent;
//	
//
//	if (i == n / 2)				//STOP at this equivalent
//	{
//		equivalent = arr[begin] == arr[end];
//		
//		return equivalent;
//	}
//	else  
//	{
//		equivalent = arr[begin] == arr[end];
//		
//		next_equivalent = palindrome(arr, n, i + 1);
//		return equivalent && next_equivalent;		//current equivalent, and the NEXT equivalent
//	}
//	
//	
//	
//}
//
//
//int main()
//{
//	int arr[] = { 0, 1, 1, 0 };
//	int brr[] = { 0, 1, 0 };
//	int crr[] = { 0, 1 };
//	int drr[] = { 0, 1, 1, 0, 0, 1, 1, 0 };
//	int equivalent=0;
//	equivalent= palindrome(arr, 4, 0);
//	if (equivalent == 0)
//	{
//		printf("This not a palendrome ");
//	}
//	equivalent = palindrome(brr, 3, 0);
//	if (equivalent == 0)
//	{
//		printf("This not a palendrome ");
//	}
//	equivalent = palindrome(crr, 2, 0); if (equivalent == 0)
//	{
//		printf("This not a palendrome ");
//	}
//	equivalent = palindrome(drr, 8, 0);
//	if (equivalent == 0)
//	{
//		printf("This not a palendrome ");
//	}
//
//
//	return 0;
//}