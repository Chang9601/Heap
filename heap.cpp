#include <iostream>
#include "heap.h"
#define LIMIT -1000000000
#define SIZE 100

Heap::Heap()
{
	/* 첨자는 1부터 시작 */
	heap = new int[SIZE + 1];
	/* 첨자 0은 더미 */
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
	/* 마지막 노드에 추가 */
	heap[++size] = data;

	/* 알맞은 위치를 위한 첨자 */
	int idx = size;
	
	/* 부모의 값보다 작거나 같을 경우 반복 */
	while (heap[idx / 2] >= data) {
		heap[idx] = heap[idx / 2];	
		idx /= 2;
	}
	
	/* 알맞은 위치 */
	heap[idx] = data;
}

int Heap::min() const
{
	if (empty())
		throw "비어있는 힙";

	return heap[1];
}

void Heap::remove()
{
	if (empty())
		throw "비어있는 힙";
	
	/* 마지막 요소를 처음으로 이동 */
	heap[1] = heap[size--];
	
	int data = heap[1];
	int idx = 1;
	/* 비단말 노드만 자식 노드 소유 */
	while (idx <= size / 2) {
		int leftChild = idx * 2;
		int rightChild = idx * 2 + 1;
		int child = leftChild;

		/* 오른쪽 자식 노드의 위치가 범위 안이고 작은 자식 선택 */
		if (rightChild <= size && heap[leftChild] > heap[rightChild])
			child = rightChild;
	
		/* 부모 노드보다 작거나 같을 경우 종료 */		
		if (data <= heap[child])
			break;
		
		heap[idx] = heap[child];
		idx = child;
	}

	heap[idx] = data;
}

void Heap::sort()
{
	/* 이진 힙이 빌 때까지 최솟값 추출 */
	while(!empty()) {
		std::cout << min() << std::endl;
		remove();
	}
}
