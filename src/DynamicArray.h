#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

template <typename T>
class DynamicArray
{
   private:
    T* data_;
    size_t size_;
    size_t capacity_;

    void resize()
    {
        size_t newCapacity = capacity_ == 0 ? 1 : capacity_ * 2;
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size_; i++)
        {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }

   public:
    DynamicArray() : data_(nullptr), size_(0), capacity_(0) {}

    ~DynamicArray() { delete[] data_; }

    DynamicArray(DynamicArray const& other) : size_(other.size_), capacity_(other.capacity_)
    {
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; i++)
        {
            data_[i] = other.data_[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this != &other)
        {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];
            for (size_t i = 0; i < size_; i++)
            {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    void push_back(const T& value)
    {
        if (size_ >= capacity_)
        {
            resize();
        }
        data_[size_++] = value;
    }

    void pop_back()
    {
        size_--;
    }

    T& operator[](size_t index) { return data_[index]; }

    T& back()
    {
        return data_[size_ - 1];
    }

    bool empty() { return size_ == 0; }

    size_t size() { return size_; }

    void clear() { size_ = 0; }
};

#endif
