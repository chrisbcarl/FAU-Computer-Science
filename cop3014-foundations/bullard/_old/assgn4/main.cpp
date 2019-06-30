//
//  main.cpp
//  WORD
//
//  Created by sphota on 9/24/15.
//  Copyright © 2015 Lex Levi. All rights reserved.
//

#include <iostream>
#include "word.h"
#include "math.h"

int main(int argc, const char * argv[]) {
	
		WORD you;
		cout<<"Testing the default constructor and printing empty word\n";
		cout<<you<<endl;
	
	
		WORD me("123abc345abc129012");
		cout<<"Testing the explicit-value constructor\n";
		cout<<me<<endl;
	
		WORD them = me;
		cout<<"Testing the copy constructor\n";
		cout<< them <<" = "<< me << endl;
	
	
		cout<<"Testing length\n";
		cout<<"The length of me is "<<me.Length()<<endl;
		cout<<"The length of them is "<<them.Length()<<endl;
		cout<<"The length of you is "<<you.Length()<<endl;
	
		WORD them2("XXXXXXXXX");
		WORD you2("12345");
		cout<<you2<<endl;
		cout<<"Testing Insert by inserting me into you2 at position 0\n";
		cout<<them2<<endl;
		you2.Insert(them2,1);
		cout<<"The word you2 is "<<you2<<endl;
	
		you2.Insert(me,5);
		cout<<you2<<endl;
	
		WORD us;
		us = "abc";
		cout<<"Testing operator= by assignment the value of \"abc\" to use\n";
		cout<<us;
	
		WORD word1, word2, word3;
		word1 = "ABC123XYZ";
		cout<<"Testing overloaded operator= with chaining by assignment the value of \"ABC123XYZ\" to use\n";
		word3=word2=word1;
		cout<<"word3 is "<<word3<<", word2 is "<<word2<<" and word1 is "<<word1<<endl;
		cout<<"Testing overloaded operator= with chaining by assignment the value of word1, \"ABC123XYZ\", into itself \n";
		word1 = word1 = word1;
		cout<<"word1 is "<<word1<<endl;
	
		cout<<"Testing operator+ without chaining"<<endl;
		word3 + word2;
		cout<<word3<<endl;
	
	
		us = "";
		us = "12";
		cout<<us<<endl;
		them.Remove(us);
		you.Remove(us);
		cout<<you<<endl;
	
		cout<<them<<endl;
		cout<<"Testing Remove by removing us from them \n";
		cout<<"The word them is "<<them<<endl;
	
		me.RemoveALL(us);
		cout<<"Testing RemoveAll by removing all occurrences of us in me \n";
		cout<<"The word me is "<<me<<endl;
	
		WORD our, him;
	
		our = "XXXCCCYYY";
		us = "XXXX";
	
		cout<<"Testing IsEqual by testing to see inf us is equal to our \n";
		if (our.IsEqual(us))
			cout<<"The 2 words are equal\n";
		else
			cout<<"The 2 words are not equal\n";
	
    return 0;
}
