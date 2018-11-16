#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
#include "BST.h"
using namespace std;
struct upcCode{
	string upc,desc;
};
bool operator>(const upcCode &first, const upcCode &second){
	return first.upc>second.upc;
}
bool operator<(const upcCode &first, const upcCode &second){
	return first.upc<second.upc;
}
ostream& operator<<(ostream& os, const upcCode u){
	os<<"UPC Code: "<<u.upc<<endl<<u.desc<<endl;
}
int main(){
	ifstream upcFile;
	clock_t timeStamp;
	double duration;
	BST<upcCode> tree;
	string userInput;
	cout<<"Enter file name: ";
	cin>>userInput;
	upcFile.open(userInput);
	if(!upcFile){
		cout<<"Unable to find "<<userInput<<endl;
		exit(0); }
		
	//BST initialize
	string x,y;
	getline(upcFile,x); //get rid of the first description line
	timeStamp=clock();
	while(getline(upcFile,x)){
		istringstream ss(x);
		getline(ss,x,',');
		getline(ss,y);
		upcCode temp;
		temp.upc=x;
		temp.desc=y;
		tree.insert(temp);
	}
	upcFile.close();
	duration=(clock()-timeStamp)/(double) CLOCKS_PER_SEC;
	cout<<"BST initialize time: "<<fixed<<duration<<"s"<<endl;
	
	//Array initialize
	upcFile.open("upc_corpus.txt");
	int numLines=-1;//accounting for first description line
	timeStamp=clock();
	while(getline(upcFile,x))
		numLines++;
	upcFile.close();
	upcFile.open("upc_corpus.txt");
	upcCode *fullList = new upcCode[numLines];
	getline(upcFile,x); //description line
	for(int i =0;i<numLines;i++){
		getline(upcFile,x);
		istringstream ss(x);
		getline(ss,x,',');
		getline(ss,y);
		upcCode temp;
		temp.upc=x;
		temp.desc=y;
		fullList[i]=temp;
	}
	upcFile.close();
	duration=(clock()-timeStamp)/(double) CLOCKS_PER_SEC;
	cout<<"Array initialize time: "<<fixed<<duration<<"s"<<endl;
		
	while(1){
		cout<<"Enter a UPC code(q to exit): ";
		cin>>userInput;
		if(userInput=="q"){
			exit(0);
		}
		//BST search
		upcCode forSearch,foundUPC;
		forSearch.upc = userInput;
		forSearch.desc="No item found.";
		timeStamp=clock();
		foundUPC = tree.search(forSearch);
		duration=(clock()-timeStamp)/(double) CLOCKS_PER_SEC;
		cout<<foundUPC;
		cout<<"BST time: "<<fixed<<duration<<"s"<<endl;
		//array search
		timeStamp=clock();
		for(int i =0;i<numLines;i++){
			if(fullList[i].upc==userInput){
				duration=(clock()-timeStamp)/(double) CLOCKS_PER_SEC;
				cout<<"Array time: "<<fixed<<duration<<"s"<<endl;
				break;
			}
		}
		
	}	
	
	
	
	
	
}