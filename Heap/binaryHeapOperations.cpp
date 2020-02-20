struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap=100) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
};
int MinHeap ::  extractMin()
{
    if(heap_size == 0) return -1;
    int val = harr[0];
    deleteKey(0);
    return val;
}

/* Removes element from position x in the min heap  */
void MinHeap :: deleteKey(int i)
{
    if(i >= heap_size) return;
    swap(harr[i],harr[heap_size-1]);
    heap_size--;
    if(i < heap_size) MinHeapify(i);
}

/* Inserts an element at position x into the min heap*/
void MinHeap ::insertKey(int k)
{
   decreaseKey(heap_size,k);
   heap_size++;
}


// Decrease Key operation, helps in deleting key from heap
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(harr[i], harr[parent(i)]);
       i = parent(i);
    }
}


/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}
