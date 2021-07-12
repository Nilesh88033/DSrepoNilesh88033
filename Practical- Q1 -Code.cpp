#include<iostream>
using namespace std;

//--------------------------------
void    operation(string* ,int* );
void   displaySet(string* ,int* );
void     powerSet(string* ,int* );
void         menu(string* ,int* );
string   isMember(string* ,string*,int*);
void         line();
//----------------------------------
void line(){
    cout<<"------------------------------"<<endl;
}
//---------------------------------
string isMember(string* pointerOfSetArray ,string* element,int* lengthOfArray){
    for (int i = 0; i < *lengthOfArray; i++){
        if(*pointerOfSetArray++ == *element){
            return "Yes,it is present.";
        }
    }
    return "No,it is not present.";
}
//******************bug***********************
void powerSet(string* pointerOfSetArray,int* lengthOfArray){
    cout<<endl;
    cout<<"Power SET of A is :"<<endl;
    cout<<"{ ";
    for (int i = 0; i <= *lengthOfArray; i++){
        for (int j = i+1; j <=*lengthOfArray; j++){   
            string* subSetArray = new string[j];
            string* pointerOfSubSetArray = subSetArray ;
            //----------------------------
            for (int k = i; k < j; k++){    
                *subSetArray++ = pointerOfSetArray[k];
            }
            displaySet(pointerOfSubSetArray,&j);
            //----------------------------
            if(i!=*lengthOfArray-1){
                cout<<" ,";
            }
        }   
    }
    cout<<" }";
    cout<<endl;
}
// ******************warning***************************
void displaySet(string *pointerOfSetArray,int* lengthOfArray){
    string *p = pointerOfSetArray;
    cout<<"[";
    for (int i = 0; i < *lengthOfArray; i++){     
        cout<<*p++;
        if(i!=*lengthOfArray-1){
            cout<<" ";
        }
    }   
    cout<<"]";
    // delete[] p;
    // cout<<endl;
}
void menu(string* pointerOfSetArray,int* lengthOfArray){
    cout<<endl;
    line();
    cout<<"****SELECT YOUR CHOICE****"<<endl;
    cout<<"1.)isMember()"<<endl;
    cout<<"2.)powerSet()"<<endl;
    cout<<"3.)displaySet()"<<endl;
    cout<<"4.)exit()"<<endl;
    line();
    operation(pointerOfSetArray,lengthOfArray);
    line();
}
void operation(string* pointerOfSetArray,int* lengthOfArray){
    cout<<endl;
    int* choice = new int();
    cout<<"Enter your choice[1-4] : ";
    cin>>*choice;
    cout<<endl;
    string* tempElement = new string();
    switch (*choice){
        case 1:
            cout<<"Enter the element to check!! : ";
            cin.get();
            getline(cin,*tempElement);
            cout<<isMember(pointerOfSetArray,tempElement,lengthOfArray)<<endl;
            cout<<endl;
            delete tempElement;
            menu(pointerOfSetArray,lengthOfArray);
            break;
        case 2:
            powerSet(pointerOfSetArray,lengthOfArray);
            menu(pointerOfSetArray,lengthOfArray);
            break;
        case 3:
            cout<<"SET A IS : ";
            displaySet(pointerOfSetArray,lengthOfArray);
            cout<<endl;
            menu(pointerOfSetArray,lengthOfArray);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout<<"Invalid Choice"<<endl;
            // menu(pointerOfSetArray,lengthOfArray);
            break;
    }
    delete choice;
}
//------------------------------
int main(){
    int* lengthOfArray = new int();
    cout<<"How many elements you want to enter ? ";
    cin>>*lengthOfArray;
    string* setArray = new string[*lengthOfArray];
    string* pointerOfSetArray =setArray;
    for (int i = 0; i < *lengthOfArray; i++){        
        string* tempInputElement = new string();
        cout<<"Enter your element "<<i+1<<" : ";
        cin>>*tempInputElement;
        *setArray++ = *tempInputElement;
        delete tempInputElement;
    }
    menu(pointerOfSetArray,lengthOfArray);
    // delete lengthOfArray;
    // delete[] setArray;
    // delete[] pointerOfSetArray;
    return 0;
}

