#include <iostream>
#include "heap.h"
#define LIMIT -1000000000
#define SIZE 100

Heap::Heap()
{
	/* ÷�ڴ� 1���� ���� */
	heap = new int[SIZE + 1];
	/* ÷�� 0�� ���� */
	heap[0] = LIMIT;	
	size = 0;
}

Heap::~Heap()
{
	delete[] heap;
}

int Heap::getSize() const
{
	return size;
}

bool Heap::empty() const
{
	return size == 0;
}

void Heap::insert(int data)
{
	/* ������ ��忡 �߰� */
	heap[++size] = data;

	/* �˸��� ��ġ�� ���� ÷�� */
	int idx = size;
	
	/* �θ��� ������ �۰ų� ���� ��� �ݺ� */
	while (heap[idx / 2] >= data) {
		heap[idx] = heap[idx / 2];	
		idx /= 2;
	}
	
	/* �˸��� ��ġ */
	heap[idx] = data;
}

int Heap::min() const
{
	if (empty())
		throw "����ִ� ��";

	return heap[1];
}

void Heap::remove()
{
	if (empty())
		throw "����ִ� ��";
	
	/* ������ ��Ҹ� ó������ �̵� */
	heap[1] = heap[size--];
	
	int data = heap[1];
	int idx = 1;
	/* ��ܸ� ��常 �ڽ� ��� ���� */
	while (idx <= size / 2) {
		int leftChild = idx * 2;
		int rightChild = idx * 2 + 1;
		int child = leftChild;

		/* ������ �ڽ� ����� ��ġ�� ���� ���̰� ���� �ڽ� ���� */
		if (rightChild <= size && heap[leftChild] > heap[rightChild])
			child = rightChild;
	
		/* �θ� ��庸�� �۰ų� ���� ��� ���� */		
		if (data <= heap[child])
			break;
		
		heap[idx] = heap[child];
		idx = child;
	}

	heap[idx] = data;
}

void Heap::sort()
{
	/* ���� ���� �� ������ �ּڰ� ���� */
	while(!empty()) {
		std::cout << min() << std::endl;
		remove();
	}
}
