template<typename T>
class Vector {
private:
    T *data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void realloc(size_t newCapacity) {
        T * newBlock = new T[newCapacity];
        // if we're shrinking the array, don't copy anything after.
        if (newCapacity > size) {
            size = newCapacity;
        }

        for (size_t i = 0; i < size; i++) {
            newBlock[i] = data[i];
        }

        delete [] data;
        data = newBlock;
        capacity = newCapacity;
    }

public:
    Vector() { realloc(2); } //alocate new memory!
    ~Vector() { delete[] data; } //free wgar we've allocated.

    void pushBack() (const T & value) {
        if (size == capacity) {
            realloc(capacity + capacity / 2); //grow by 1.5 
        }
        data[size++] = value;
    }

    size_t size() const { return size};

    const T & operator[](size_t index) const { //const version
        return data[index];
    }

    T & operator[](size_t index) { //non-const version
        return data[index];
    }

    void popBack() {
        if (size > 0) {
            data[--size].~T();
        }
    }

    class iterator {
    private:
        T* currentElement;

    public:
        T & operator++() {
            ++currentElement;
            return *this;
        }

        T & operator++(int) {
            T temp = *currentElement;
            ++currentElement;
            return temp;

        }

        T & operator*() {
            return *currentElement;
        }

        bool operator==(const iterator & other) const {
            return currentElement == other.currentElement;
        }

        bool operator!=(const iterator & other) const {
            return currentElement != other.currentElement;
        }
    };

    iterator begin() { return iterator(data); }
    iterator end() { return iterator(data + capacity); }

};