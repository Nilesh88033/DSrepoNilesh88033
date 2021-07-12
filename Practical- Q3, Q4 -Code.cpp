#include<iostream>
using namespace std;
class Relation{
    public:
    int f=0;
    int rel[4][4] ={{1,1,1},
                    {1,1,1},
                    {1,1,1}
                          };
    int checkRef(){
        for(int i=0;i<3;i++){
            if(rel[i][0]!=1){
                cout<<"Not reflexive ";
                return 0;
            }
        }
        cout<<"Reflexive ";
        f++;
        return 0;
    }
    int checkSym(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(rel[i][j]==1 && rel[j][i]!=1){
                   cout<<"Not symmetric ";
                   return 0;
                }
            }
        }
        cout<<"Symmetric ";
        f++;
        return 0;
    }
    int checkAntiSym(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(rel[i][j]==1 && rel[j][i]!=1){
                   cout<<"Antisymmetric ";
                   f++;
                   return 0;
                }
            }
        }
        cout<<"Not Antisymmetric ";
        return 0;
    }
    int checkTrans(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(rel[i][j] && rel[j][k] && !rel[i][k]){
                        cout<<"Not Transitive ";
                        return 0;
                    }
                }
            }
        }
        f++;
        cout<<"Transitive ";
        return 0;


    }
    int checkEqui(){
        checkRef();
        cout<<", ";
        checkSym();
        cout<<"and ";
        checkTrans();
        if(f==3){
            cout<<"so in conclusion the relation is an Equivalence relation";
        }
        else{
            cout<<"so in conclusion the relation is not an Equivalence relation";
        }
    }
    int checkParOrder(){
        checkRef();
        cout<<", ";
        checkAntiSym();
        cout<<"and ";
        checkTrans();
        if(f==3){
            cout<<"so in conclusion the relation is a Partial order relation";
        }
        else{
            cout<<"so in conclusion the relation is not a Partial order relation";
        }

    }
};
int main(){
     Relation r;
     int n;
     while(n!=7){
     cout<<"\nWhat do you want to do with this relation?\n";
     cout<<"1.Check Symmetry\n";
     cout<<"2.Check Reflexivity\n";
     cout<<"3.Check Antisymmetry\n";
     cout<<"4.Check Transitivity\n";
     cout<<"5.Check Equivalence\n";
     cout<<"6.Check Partial Order\n";
     cout<<"7.Exit\n";
     cin>>n;
     switch(n){
     case(1):
        cout<<"The relation is ";
        r.checkSym();
        break;
     case(2):
        cout<<"The relation is ";
        r.checkRef();
        break;
     case(3):
        cout<<"The relation is ";
        r.checkAntiSym();
        break;
     case(4):
        cout<<"The relation is ";
        r.checkTrans();
        break;
     case(5):
        cout<<"The relation is ";
        r.checkEqui();
        break;
     case(6):
        cout<<"The relation is ";
        r.checkParOrder();
        break;
     case(7):
        cout<<"Bye!";
        break;
     default:
        cout<<"Please enter a number between 1-5\n";
     }
     }

}

