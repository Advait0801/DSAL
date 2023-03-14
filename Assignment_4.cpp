/*
Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client’s telephone number.
Make use of two collision handling techniques and compare them using
number of comparisons required to find a set of telephone numbers
(Note: Use linear probing with replacement and without replacement)

Name : Advait Naik
Roll No : 21354
*/

#include <iostream>
#include <string.h>
using namespace std;

class Record{
    char clientname[20];
    int phone;

public:
    Record(){
        strcpy(this -> clientname,"----");
        this -> phone = 0;
    }

    Record(char name[],int n){
        strcpy(this -> clientname,name);
        this -> phone = n;
    }

    void print(){
        cout<<clientname<<" "<<phone<<" "<<endl;
    }  

    bool isEmpty(){
        return this -> phone == 0;
    }  

    friend class HashingTable;
};

class HashingTable{
    int tablesize;
    Record *record;

    int hash(char clientname[]){
        int ascii = 0;
        char c = clientname[0];

        for(int i=0;c!='\0';i++){
            ascii = ascii + int(clientname[i]);
            c = clientname[++i];
        }
        return ascii % tablesize;
    }

public:
    HashingTable(int i){
        this -> tablesize = i;
        this -> record = new Record[tablesize];
    }

    void display(){
        for(int i=0;i<tablesize;i++){
            record[i].print();
        }
    }

    void insert_without_replacement(Record r){
        int index = hash(r.clientname); 

        if(record[index].isEmpty()){
            record[index] = r;
        }
        else{
            int currentIndex = index ;
			while( !record[ currentIndex ].isEmpty() ) {
				currentIndex = ( currentIndex + 1 ) % tablesize ;
			}
			record[ currentIndex ] = r ;
        }
    }

    void search(){

    }

    
};

int main(){
    HashingTable ht(10); 
    int r;
    char arr[20];
    cout<<"Pls insert_without_replacement name and roll.."<<endl;
    cin>>arr>>r;
    ht.insert_without_replacement(Record(arr,r));
    ht.insert_without_replacement(Record("advait" , 123454));
    ht.insert_without_replacement(Record("abdbv" , 4687587));
    ht.insert_without_replacement(Record("Krishna" , 7984));
    ht.display();

    return 0;
    
}