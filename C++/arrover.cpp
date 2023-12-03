#include <iostream>
using namespace std;

const int LIMIT = 100;         //array size

class safearay {
private:
    int arr[LIMIT];
public:
    class arrErr {
    public:
        string ErrName;
        int ErrNo;
        arrErr(string s, int i) {
            ErrName = s;
            ErrNo = i;
            
        }
    };
    int& operator [](int n)  //note: return by reference
    {
        if (n < 0 || n >= LIMIT) {
            throw arrErr("\nIndex out of bounds", 0);//�迭 ������ ��� ��� ����ó��
        }
        if (arr[n] <= -858993460)
            throw arrErr("\nTrash value error", 2);  // -858993460 ���� ���� ���� ���� ���� ���� ���ٰ� �Ǵ���
                                                     // -858993460 ���� ������ �����Ⱚ�̶�� ���� �޼��� ���
        return arr[n];
    }
    
    int& operator [](string s)                       //�ε��� �ȿ� string �� ������� ����ó��
    {
        throw arrErr("\nType mismatch", 1);
    }
    int& operator [](float s)  
    {
        throw arrErr("\nType mismatchr", 1);         //�ε��� �ȿ� float �� ������� ����ó��
    }
    int& operator [](double s) 
    {
        throw arrErr("\nType mismatch", 1);          //�ε��� �ȿ� double �� ������� ����ó��
    }
    int& operator [](char s)
    {
        throw arrErr("\nType mismatch", 1);          //�ε��� �ȿ� char �� ������� ����ó��
    }
    
};

int main() {
    safearay sa1;
    try {
        //sa1[1000]; // Index out of bounds error, error number is 0.
        //sa1["a"];  //type mismatch error, error number is 1. 
        //sa1[1.1];  //type mismatch error, error number is 1. 
        //sa1['a'];  //type mismatch error, error number is 1. 
        cout << sa1[1]; //Trash value error , error number is 2.
        
    }
    
    catch(safearay::arrErr err){
        cout << "Err Name is " << err.ErrName << "\nerror number is " << err.ErrNo << endl;
        exit(1);
    }
    
    return 0;
}