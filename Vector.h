#ifndef vectorClass
#define vectorClass

template <typename T> class vector
{
	T* vect;
	int capacity;
	bool empty;

public:
	vector()
	{
		vect = new T[1];
		capacity = 1;
		empty = true;
	}

    vector(unsigned int count, ...)
    {
        va_list args;
        va_start(args, count);

        for (int i = 0; i < count; i++)
            push(va_arg(args, T));

        va_end(args);
    }

	void push(T item)
	{
		if (empty)
		{
			vect[0] = item;
			empty = false;
		}
		else
		{
			T* temp = new T[capacity + 1];
			for (int i = 0; i < capacity; i++)
				temp[i] = vect[i];
			temp[capacity] = item;

			delete[] vect;
			vect = temp;
			capacity++;
		}
	}
	
	void removeAt(unsigned int index)
	{
		if (index < capacity - 1)
		{
			while (index + 1 < capacity)
			{
				vect[index] = vect[index + 1];
				index++;
			}
			capacity--;
		}
		else if (index == capacity - 1)
		{
			capacity--;
		}
	}

	T get(unsigned int index)
	{
		return vect[index];
	}

	unsigned int count()
	{
		return capacity;
	}

    void erase()
    {
        delete[] vect;
    }
private:

};

#endif