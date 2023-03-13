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
        cout<<this -> clientname<<" "<<phone<<endl;
    }

    friend class HashingTable;
};

class HashingTable{
    int tablesize;
    Record *record;

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

    void insert(Record r){
        int ascii = 0;
        char c = r.clientname[0];
        for(int i=0;c!='\0';i++){
            ascii = ascii + int(r.clientname[i]);
            c = r.clientname[++i];
        }
        int index = ascii % tablesize;
        if(record[index].phone == 0){
            record[index] = r;
        }
        else{
            while(!record[index].phone != 0){
                index = (index + 1) % tablesize;
            }
            record[index] = r;
        }
    }

    
};

int main(){
    HashingTable ht(10); 
    ht.insert(Record("Advait" , 123454));
    ht.insert(Record("abdbv" , 4687587));
    ht.insert(Record("Krishna" , 7984));
    ht.display();

    return 0;
    
}