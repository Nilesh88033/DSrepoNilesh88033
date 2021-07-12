#include <bits/stdc++.h>
using namespace std;

class SET
{
        int size;
        char set[100];

public:
        SET(int s)
        {
                size = s;
                set[size];
        }

        void input()
        {
                cout << "Enter the elements of set:-   " << endl;

                for (int i = 0; i < size; i++)
                {
                        cin >> set[i];
                }
        }

        bool isSubSet(SET set1)
        {
                bool table[set1.size] = {false};
                for (int i = 0; i < set1.size; i++)
                {
                        for (int j = 0; j < size; j++)
                        {
                                if (set1.set[i] == set[j])
                                {
                                        table[i] = true;
                                        break;
                                }
                        }
                }

                for (int i = 0; i < set1.size; i++)
                {
                        if (table[i] == false)
                        {
                                return false;
                        }
                }

                return true;
        }

        void Union(SET set1)
        {
                vector<char> setunion;

                for (int i = 0; i < size; i++)
                {
                        setunion.push_back(set[i]);
                }

                bool table[set1.size] = {false};
                for (int i = 0; i < set1.size; i++)
                {
                        for (int j = 0; j < size; j++)
                        {
                                if (set1.set[i] == set[j])
                                {
                                        table[i] = true;
                                        break;
                                }
                        }
                }

                for (int i = 0; i < set1.size; i++)
                {
                        if (table[i] == false)
                        {
                                setunion.push_back(set1.set[i]);
                        }
                }

                cout << "Union of both sets is:- " << endl
                     << "{";
                for (int i = 0; i < setunion.size(); i++)
                {
                        cout << setunion[i] << ",";
                }
                cout << "}" << endl;
        }

        void Intersection(SET set1)
        {
                vector<char> setintersection;

                bool table[set1.size] = {false};
                for (int i = 0; i < set1.size; i++)
                {
                        for (int j = 0; j < size; j++)
                        {
                                if (set1.set[i] == set[j])
                                {
                                        table[i] = true;
                                        break;
                                }
                        }
                }

                for (int i = 0; i < set1.size; i++)
                {
                        if (table[i] == true)
                        {
                                setintersection.push_back(set1.set[i]);
                        }
                }

                cout << "Intersection of both sets is:- " << endl
                     << "{";
                for (int i = 0; i < setintersection.size(); i++)
                {
                        cout << setintersection[i] << ",";
                }
                cout << "}" << endl;
        }

        void Complement()
        {
                vector<bool> checkvalue(3);
                checkvalue.push_back(false);
                checkvalue.push_back(false);
                checkvalue.push_back(false);
                vector<char> universalset;

                for (int i = 0; i < size; i++)
                {
                        if (set[i] >= 'A' && set[i] <= 'Z')
                        {
                                checkvalue[0] = true;
                        }
                        else if (set[i] >= 'a' && set[i] <= 'z')
                        {
                                checkvalue[1] = true;
                        }
                        else if (set[i] >= '0' && set[i] <= '9')
                        {
                                checkvalue[2] = true;
                        }
                }

                if (checkvalue[0] == true)
                {
                        for (int i = 0; i < 26; i++)
                        {
                                universalset.push_back(char(i + 65));
                        }
                }
                if (checkvalue[1] == true)
                {
                        for (int i = 0; i < 26; i++)
                        {
                                universalset.push_back(char(i + 97));
                        }
                }
                if (checkvalue[2] == true)
                {
                        for (int i = 0; i < 10; i++)
                        {
                                universalset.push_back(char(i + 48));
                        }
                }

                for (int i = 0; i < size; i++)
                {
                        for (int j = 0; j < universalset.size(); j++)
                        {
                                if (set[i] == universalset[j])
                                {
                                        universalset.erase(universalset.begin() + j);
                                        break;
                                }
                        }
                }

                cout << "{";
                for (int i = 0; i < universalset.size(); i++)
                {
                        cout << universalset[i] << ",";
                }
                cout << "}" << endl
                     << endl;
        }

        void SetDifference(SET set1)
        {
                vector<char> setdifference;

                vector<char> setintersection;

                bool table[set1.size] = {false};
                for (int i = 0; i < set1.size; i++)
                {
                        for (int j = 0; j < size; j++)
                        {
                                if (set1.set[i] == set[j])
                                {
                                        table[i] = true;
                                        break;
                                }
                        }
                }

                for (int i = 0; i < set1.size; i++)
                {
                        if (table[i] == true)
                        {
                                setintersection.push_back(set1.set[i]);
                        }
                }

                for (int i = 0; i < size; i++)
                {
                        bool flag = false;
                        for (int j = 0; j < setintersection.size(); j++)
                        {
                                if (set[i] == setintersection[j])
                                {
                                        flag = false;
                                        break;
                                }
                                else
                                {
                                        flag = true;
                                }
                        }
                        if (flag == true)
                        {
                                setdifference.push_back(set[i]);
                        }
                }

                cout << "{";
                for (int i = 0; i < setdifference.size(); i++)
                {
                        cout << setdifference[i] << ",";
                }
                cout << "}" << endl
                     << endl;
        }

        void SymmetricDifference(SET set1)
        {
                vector<char> symdifference;

                vector<char> setunion;

                for (int i = 0; i < size; i++)
                {
                        setunion.push_back(set[i]);
                }

                bool table[set1.size] = {false};
                for (int i = 0; i < set1.size; i++)
                {
                        for (int j = 0; j < size; j++)
                        {
                                if (set1.set[i] == set[j])
                                {
                                        table[i] = true;
                                        break;
                                }
                        }
                }

                for (int i = 0; i < set1.size; i++)
                {
                        if (table[i] == false)
                        {
                                setunion.push_back(set1.set[i]);
                        }
                }

                for(int i=0;i<setunion.size();i++)
                {
                        symdifference.push_back(setunion[i]);
                }

                vector<char> setintersection;

                bool table1[set1.size] = {false};
                for (int i = 0; i < set1.size; i++)
                {
                        for (int j = 0; j < size; j++)
                        {
                                if (set1.set[i] == set[j])
                                {
                                        table1[i] = true;
                                        break;
                                }
                        }
                }

                for (int i = 0; i < set1.size; i++)
                {
                        if (table1[i] == true)
                        {
                                setintersection.push_back(set1.set[i]);
                        }
                }

                for (int i = 0; i < symdifference.size(); i++)
                {
                        bool flag = false;
                        for (int j = 0; j < setintersection.size(); j++)
                        {
                                if (symdifference[i] == setintersection[j])
                                {
                                        symdifference.erase(symdifference.begin() + i);
                                }
                        }
                }

                cout << "{";
                for (int i = 0; i < symdifference.size(); i++)
                {
                        cout << symdifference[i] << ",";
                }
                cout << "}" << endl
                     << endl;
        }

        void CartesianProd(SET set1)
        {
                string cartprod[set1.size][size];

                for(int i=0;i<size;i++)
                {
                        for(int j=0;j<set1.size;j++)
                        {
                                string temp = "(";
                                temp = temp + set[i];
                                temp = temp + ",";
                                temp = temp + set1.set[j];
                                temp = temp + ")";

                                cartprod[j][i] = temp;
                        }
                }

                cout<<"{";
                for(int i=0;i<size;i++)
                {
                        for(int j=0;j<set1.size;j++)
                        {
                                cout<<cartprod[j][i]<<",";
                        }
                }
                cout<<"}";
        }
};

int main()
{
        int size;

        cout << "Enter size of first set:-   ";
        cin >> size;

        SET set1(size);
        set1.input();

        cout << "Enter size of second set:-   ";
        cin >> size;

        SET set2(size);
        set2.input();

        bool issubset = set1.isSubSet(set2);

        if (issubset)
        {
                cout << "Set 2 is subset of Set 1" << endl;
        }
        else
        {
                cout << "Set 2 is not a subset of Set 1" << endl;
        }

        set1.Union(set2);

        set1.Intersection(set2);

        cout << "Complement of first set:-   " << endl;
        set1.Complement();

        cout << "Complement of second set:-   " << endl;
        set2.Complement();

        cout << "Set1 - Set2" << endl;
        set1.SetDifference(set2);

        cout << "Set2 - Set1" << endl;
        set2.SetDifference(set1);

        cout << "Symmetric difference" << endl;
        set1.SymmetricDifference(set2);

        cout<<"Cartesian product of both the sets:-  "<<endl;
        set1.CartesianProd(set2);

        return 0;
}

