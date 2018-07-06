//
//  main.cpp
//  StaticPolymorphism
//
//  Created by Subrat on 06/07/18.
//  Copyright © 2018 Subrat. All rights reserved.
//

#include <iostream>
using namespace std;

/**** Example1- Using virtual
class SoftwareEngineer {
private:
    string name;
public:
    void GenerateWorkReport() {
        WorkReport();
    }
     virtual void WorkReport() {
        cout << " This is Generic work report. Derived class should implement\n";
    }; // = 0
};

class Developer : public SoftwareEngineer {
public:
    void WorkReport() {
        cout << " Doing developement work!!!\n";
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Developer dev;
    dev.GenerateWorkReport();
    return 0;
}
******/
/*** Example 2 - Simulating polymorphim.
                 Template meta programming**/

template<typename T>
class SoftwareEngineer {
private:
    //string name;
public:
    void GenerateWorkReport() {
        static_cast<T*>(this)->WorkReport();
    }
    void WorkReport() {
        cout << " This is Generic work report. Derived class should implement\n";
    }; // = 0
};

class Developer : public SoftwareEngineer<Developer> {
public:
    void WorkReport() {
        cout << " Doing developement work!!!\n";
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Developer dev;
    dev.GenerateWorkReport();
    return 0;
}
