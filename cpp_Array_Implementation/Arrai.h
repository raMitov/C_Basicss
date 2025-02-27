//
// Created by garjo on 2/27/25.
//

#ifndef ARRAI_H
#define ARRAI_H
template <typename T, size_t N>
class Arrai {
    public:
        constexpr size_t size() const { return N; }
        T& operator[](size_t index) {return data[index];}
        const T& operator[](size_t index) const { return data[index]; }
        T* Data() { return data; }
        const T* Data() const { return data; }
     private:
       T data[N];
};

#endif //ARRAI_H
