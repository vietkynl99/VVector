#ifndef _V_VECTOR_H_
#define _V_VECTOR_H_

#define V_VECTOR_SIZE_MAX_DEFAULT (64)

template <typename T>
class VVector
{
protected:
    int mSizeMax;
    int mSize;
    T *mDataArr;

public:
    VVector(int sizeMax = V_VECTOR_SIZE_MAX_DEFAULT)
    {
        mDataArr = nullptr;
        mSize = 0;
        mSizeMax = sizeMax;
    }

    ~VVector()
    {
        if (mDataArr != nullptr)
        {
            delete[] mDataArr;
            mDataArr = nullptr;
        }
    }

    bool push_back(T value)
    {
        if (mSize >= mSizeMax)
        {
            return false;
        }

        int newSize = mSize + 1;
        T *newDataArr = new T[newSize];
        if (newDataArr == nullptr)
        {
            return false;
        }

        if (mSize > 0)
        {
            for (int i = 0; i < mSize; i++)
            {
                newDataArr[i] = mDataArr[i];
            }
            // memcpy(newDataArr, mDataArr, mSize * sizeof(T));
            delete[] mDataArr;
        }
        newDataArr[newSize - 1] = value;

        mSize = newSize;
        mDataArr = newDataArr;
        return true;
    }

    T at(int index)
    {
        return mDataArr[index];
    }

    int size()
    {
        return mSize;
    }

    VVector &operator=(const VVector &other)
    {
        if (this != &other)
        {
            if (this->mDataArr)
            {
                delete[] this->mDataArr;
                this->mDataArr = nullptr;
            }

            this->mSize = other.mSize;
            this->mSizeMax = other.mSizeMax;
            if (this->mSize > 0)
            {
                this->mDataArr = new T[this->mSize];
                if (this->mDataArr)
                {
                    memcpy(this->mDataArr, other.mDataArr, other.mSize * sizeof(T));
                }
                else
                {
                    this->mSize = 0;
                }
            }
        }
        return *this;
    }

    T &operator[](int index)
    {
        return at(index);
    }
};
#endif