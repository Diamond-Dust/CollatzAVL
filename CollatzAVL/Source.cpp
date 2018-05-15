#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include"AVL.h"
#include<stdlib.h>
#include<stdio.h>

#define MAXNUM 1431655764

int main() {
	AVL AVLTree;
	unsigned int currentQNode;
	Node* currentNode;
	char charter;
	unsigned int n, queries, times, currentInt;
	scanf("%u", &n);
	unsigned int *nums;
	nums = (unsigned int*)malloc(sizeof(unsigned int) * n);
	for (unsigned int i = 0; i < n; i++)
	{
		scanf("%u", &nums[i]);
		if (nums[i] != 1)
			AVLTree.Add(nums[i], i);
	}

	scanf("%u", &queries);

	for (unsigned int i = 0; i < queries; i++)
	{
		scanf("%u %c", &times, &charter);
		if (charter == 'l')
		{
			for (unsigned int j = 0; j < times; j++)
			{
				currentQNode = AVLTree.PopMax();
				if (nums[currentQNode] % 2 == 0)
				{
					nums[currentQNode] /= 2;
					if (nums[currentQNode] > 1)
						AVLTree.Add(nums[currentQNode], currentQNode);
				}
				else
				{
					nums[currentQNode] *= 3;
					nums[currentQNode]++;
					if (nums[currentQNode] < MAXNUM)
						AVLTree.Add(nums[currentQNode], currentQNode);
					else
						nums[currentQNode] = 0;
				}
			}
		}
		else
		{
			for (unsigned int j = 0; j < times; j++)
			{
				currentQNode = AVLTree.PopMin();
				if (nums[currentQNode] % 2 == 0)
				{
					nums[currentQNode] /= 2;
					if (nums[currentQNode] > 1)
						AVLTree.Add(nums[currentQNode], currentQNode);
				}
				else
				{
					if (nums[currentQNode] <= MAXNUM)
					{
						nums[currentQNode] *= 3;
						nums[currentQNode]++;
						AVLTree.Add(nums[currentQNode], currentQNode);
					}
					else
						nums[currentQNode] = 0;
				}
			}
		}
	}

	for (unsigned int i = 0; i < n; i++)
		if (nums[i] == 0)
			printf("%c ", 'm');
		else
			printf("%u ", nums[i]);

}