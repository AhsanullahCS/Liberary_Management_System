#include <iostream>
#include <vector>
using namespace std;

vector<string>Allbooks = {"physics" , "maths" , "algebra" , "accounting" , "computer"};
vector<string>Issuebook;

void SeeBook()
{
    int count = 1;
    cout<<"THE AVAILABLE BOOKS IN THE LIBERARY ARE"<<endl;
    for(string i : Allbooks)
    {
        cout<<"BOOK NO  "<<count<<"  BOOK NAME"<<" --<::>-- "<<i<<endl;
        count++;
    }
}
void IssueBook()
{
    string bname;
    cin.ignore();
    cout<<"ENTER THE NAME OF THE BOOK TO TO ISSUE "<<endl;
    getline(cin, bname);
    bool found = false;
    for(int i=0; i<Allbooks.size(); i++)
    {
        if(Allbooks[i] == bname)
        {
            found = true;
            Issuebook.push_back(Allbooks[i]);
            Allbooks.erase(Allbooks.begin() + i);
            cout<<"YOU SUCCESSFULLY ISSUED THE BOOK -<::>- "<<bname<<endl;
            break;
        }
    }
    if(!found)
    {
    cout<<"YOU ENTER THE WRONG BOOK SEE SPELLINGS"<<endl;
    }
}
void ReturnBook()
{
    string name;
    bool found = false;
    cin.ignore();
    cout<<"ENTER THE NAME OF THE BOOK TO RETURN "<<endl;
    getline(cin, name);
    for(int i=0; i<Issuebook.size();i++)
    {
        if(Issuebook[i] == name)
        {
            found = true;
            Allbooks.push_back(name);
            Issuebook.erase(Issuebook.begin() + i);
            break;
        }
    }
    if(found == true)
    {
        cout<<"THANK YOU FOR SUCCESSFULLY RETURNING THE BOOK--<::>--"<<name<<endl;
    }
    else
    {
        cout<<"PLEASE ENTER THE CORRECT NAME OF THE BOOK "<<endl;
    }
}
void SeeIssueBook()
{
    if(!Issuebook.empty())
    {
        for(int i=0; i<Issuebook.size(); i++)
        {
            cout<<"BOOK NO "<<i+1<<" IS "<<Issuebook[i]<<endl;
        }
    }
    else
    {
        cout<<"--<::>--NO BOOK IS ISSUE FROM THE LIBERARY--<::>--"<<endl;
    }
}

int main()
{
    int n;
    char choice;
    do{
    cout<<"PRESS 1 TO SEE BOOKS OF THE LIBERARY "<<endl;
    cout<<"PRESS 2 TO ISSUE BOOK "<<endl;
    cout<<"PRESS 3 TO SEE THE BOOKS THAT ARE ISSUED "<<endl;
    cout<<"PRESS 4 TO RETURN BOOK "<<endl;
    cout<<"WHAT IS YOUR CHOICE "<<endl;
    cin>>n;
    switch(n)
    {
        case 1:
        
        SeeBook();
        break;
        case 2:

        IssueBook();
        break;
        case 3:

        SeeIssueBook();
        break;
        case 4:

        ReturnBook();
        break;

        default:
        cout<<"::>------------::>INVALID CHOICE::<------------<::"<<endl;
        break;
    }
    
    cout<<"DO YOU WANT TO CONTINUE PRESS Y FOR YES AND N FOR NO "<<endl;
    cin>>choice;
}while(choice == 'y' || choice != 'n');

return 0;
}