#include <iostream>
#include <string>
using namespace std;

class clsCalculator {
private:
    float _Result = 0;
    float _LastNumber;
    string _LastOperation="Clear";
    float _PreviuosResult;
    /*Methods*/

public:
    void Clear() {
        _Result = 0;
        _PreviuosResult = 0;
        _LastNumber = 0;
        _LastOperation = "Clear";
    }
    void Add(int Num) {
        _PreviuosResult = _Result;
        _Result += Num;
        _LastNumber = Num;
        _LastOperation = "Adding ";
    }
    void Subtract(int Num) {
        _PreviuosResult = _Result;
        _Result -= Num;
        _LastNumber = Num;
        _LastOperation = "Subtracting ";
    }
    void Multiply(int Num) {
        _PreviuosResult = _Result;
        _Result *= Num;
        _LastNumber = Num;
        _LastOperation = "Multiblicating ";
    }
    void Divide(int Num) {
        _LastNumber = Num;
        if (Num == 0)
            Num++;

        _PreviuosResult = _Result;
        _Result /= Num;
        _LastOperation = "Dividing ";
    }
    void CanceledLastCalc() {
        _Result = _PreviuosResult;
        _LastOperation = "Cancelling Last Operation ";
    }
    void PrintResult() {
        cout << "Result ";
        if (_LastOperation == "Cancelling Last Operation ") {
            cout << "After " << _LastOperation << "is: " << _Result << endl;
        }
        else
        cout << "After "<<_LastOperation<<_LastNumber << " is: " << _Result << endl;
    }
};
int main()
{
    clsCalculator Calculator1;
    Calculator1.Add(10);
    Calculator1.PrintResult();
    Calculator1.Multiply(10);
    Calculator1.PrintResult();
    Calculator1.CanceledLastCalc();
    Calculator1.PrintResult();
    Calculator1.Divide(0);
    Calculator1.PrintResult();
}

