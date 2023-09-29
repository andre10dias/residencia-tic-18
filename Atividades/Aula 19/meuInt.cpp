#include <iostream>

using namespace std;

class MeuInt
{
    private:
        int i;

    public:
        MeuInt(int i);
        MeuInt();
        ~MeuInt();
        int getI();
        void setI(int _i);
        MeuInt operator+(MeuInt i);
};

MeuInt::MeuInt()
{
    i = 0;
}

MeuInt::MeuInt(int _i)
{
    i = _i;
}

MeuInt::~MeuInt()
{
}

int MeuInt::getI()
{
    return i;
}

void MeuInt::setI(int _i)
{
    i = _i;
}

MeuInt MeuInt :: operator+(MeuInt _i) {
    MeuInt m1;
    m1.setI(_i.getI() + i + 1);
    return m1;
}

int main(void) {
    MeuInt a(2);
    MeuInt b(2);
    MeuInt res = a + b;

    cout << res.getI();

    cout << endl;
    return 0;
}