nclude<iostream>
#include<cstring>

using namespace std;

class Food{
public:
     void SetPrice(int myprice){
     price = myprice;
 }
 void GetPrice(){
     cout << price << endl;
 }
private:
    int price;
};

class Fruit : public Food{
public:
    void SetPrice(int myprice){
        //SetPrice関数をオーバーライド
        Food::SetPrice(myprice - 20);
    }
};

int main(){
    Food *pFood;
    Fruit myFruit;

    pFood = &myFruit;

    pFood->SetPrice(100);
    pFood->GetPrice();

    return 0;
}

//純粋仮想関数
//純粋仮想関数とは基底クラスで内容を定義しないもの
//また純粋仮想関数はオブジェクトとして生成できない
#include<iostream>

using namespace std;

class Food{
public:
    virtual void SetPrice(int myprice) = 0;
    int GetPrice(){
        return price;
    }
protected:
    int price;
};

class Fruit : public Food{
public:
    void SetPrice(int myprice){
        price = myprice - 20;
    }
};

class Fish : public Food{
public:
    void SetPrice(int myprice){
        price = myprice / 2;
    }
};


int main(void){
    Food *pFood;
    Fruit myFruit;
    Fish  myFish;

    pFood = &myFruit;
    pFood->SetPrice(100);
    cout << "myFruitのprice = " << pFood->GetPrice() << endl;

    pFood = &myFish;
    pFood->SetPrice(100);
    cout << "myFishのprice = " << pFood->GetPrice() << endl;
    return 0;
}

//pure virtual function
//sampleprogram(1)
//make a order
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

class DrinkBox{
public:
    //contructor
    DrinkBox(){}
    DrinkBox(char *str, int n1, int n2){
        name = new char[strlen(str) + 1];
        strcpy(name, str);
        price = n1;
        count = n2;
    }
    //destructor
    ~DrinkBox(){
        delete [] name;
    }

    int GetTotalPrice(){
        return count * price;
    }

    void PrintTitle(){
        cout << "商品名\t\t単価\t数量\t金額" << endl;
    }
    void PrintData(){
        cout << name << "\t" << price  << "\t"
             << count << "\t" << GetTotalPrice() << endl;
    }

    char *name;
    int price;
    int count;
};

//派生クラす
class AlcholBox : public DrinkBox{
public:
    AlcholBox(char *str, int n1, int n2, float f){
        name = new char[strlen(str) + 1];
        strcpy(name, str);
        price = n1;
        count = n2;
        alcper = f;
    }
    void PrintTitle(){
        cout << "商品名　（度数[%]） \t単価\t数量\t金額" << endl;
    }
    void PrintData(){
        cout << name << "(" << alcper << ") \t" << price << "\t"
             << count << "\t" << GetTotalPrice() << endl;
    }
private:
    float alcper;
};

int main(){
    DrinkBox cofee("コーヒー", 200, 3);
    DrinkBox oolongtea("ウーロン茶", 150, 2);
    AlcholBox wine("ワイン", 300, 2, 15.0);

    cofee.PrintTitle();
    cofee.PrintData();
    oolongtea.PrintData();
    wine.PrintTitle();
    cofee.PrintData();

    int sum = cofee.GetTotalPrice() + oolongtea.GetTotalPrice()
                + wine.GetTotalPrice();
    cout << "\n***　合計金額" << sum << "円***" << endl;
    return 0;
}

//sample program
#include<iostream>

using namespace std;

//base class Figure
class Figure{
public:
    //pure virtual function
    virtual void area() = 0;
    virtual void around() = 0;

    void GetMeasure(){
        area();
        around();
    }
};

//derive class Square
class Square : public Figure{
public:
    
    //contructor
    Square(double s);
    Square(double s, double h);

    //ReDifine
    void area(){
        cout << "四角形の面積：" << side * height << endl;
    }
    void around(){
        cout << "四角形の外周：" << 2 * (side + height) << endl;
    }
private:
    double side;
    double height;
};

//contructor of Squre class
Square::Square(double s){
    side = height = s;
}
Square::Square(double s, double h){
    side = s;
    height = h;
}

//derive class Circle
class Circle : public Figure{
public:
    //Contructor
    Circle(double r);

    //Redefine 
    void area(){
        cout << "円の面積：" << radius * radius * pi << endl;
    }
    void around(){
        cout << "円の円周：" << 2 * (radius * pi) << endl;
    }
private:
    const double pi;
    double radius;
};

// Contructor of derive class Circle
Circle::Circle(double r):pi(3.14){
    radius = r;
}

int main(){
    Figure *pFig1;
    Figure *pFig2;
    Figure *pFig3;
    Square mySquare1(2.5);
    Square mySquare2(2.3, 3.7);
    Circle myCircle(3.6);
    pFig1 = &mySquare1;
    pFig2 = &mySquare2;
    pFig3 = &myCircle;

    pFig1->GetMeasure();
    pFig2->GetMeasure();
    pFig3->GetMeasure();
    return 0;
}

//static member variable
//static member variable is a common memory area.
//initialize static member variable
class Food{
    static int tax;
};

int main(){
    double Food::tax = 1.05;

}

#include<iostream>
using namespace std;

//access static member variable.
class Food{
public:
    static double tax;
};

double Food::tax = 1.05;

int main(){
    Food::tax = 1.05;
    Food myFood;
    myFood.tax = 1.03;
    cout << myFood.tax << endl;

    return 0;
}

//call a static member function
#include<iostream>
using namespace std;

class Food{
public:
    static void SetTax(double n){
        tax = n;
    }
    static void GetTax(){
        cout << tax << endl;
    }
protected:
    static double tax;
};

int main(){
    Food myFood;
    myFood.SetTax(1.03);
    myFood.GetTax();
    return 0;
}




