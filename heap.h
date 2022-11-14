#ifndef __HEAP_H__
#define __HEAP_H__

/* ÃÖ¼ÒÈü */
class Heap {
	int *heap;
	int size;

	public:
		Heap();
		~Heap();
		int getSize() const;
		bool empty() const;
		void insert(int);
		int min() const;
		void remove();
		void sort();
};

#endif
