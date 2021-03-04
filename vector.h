#ifndef vectorClass
#define vectorClass

template <typename T> class vector
{


    public:
        vector()
        {
            array = new T[1];
            capacity = 1;
            current = 0;
        }
    private:
        T* array;
        int capacity;
        int current;
};

#endif