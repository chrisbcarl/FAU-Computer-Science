#include <iostream>

using namespace std;

class Character
{
public:
	Character(char data)
	{
		this->data = data;
		next = 0;
	}
	char data;
	Character* next;
};


class Word
{

private:
	Character* first;
	Character* last;

public:
	Word();												//default constructor
	Word(char);										//explicit value constructor
	Word(const Word&);									//deep copy constructor

	void add(char);

	Word & operator=(const Word& rhs);
	friend Word operator + (Word, const Word&);
	friend ostream & operator << (ostream&, const Word&);
	friend bool operator == (const Word&, const Word&);

	/*
	Word& operator += (const Word&);
	Word& operator += (T);
	Word& operator -= (const Word&);
	Word& operator -= (T c);
	Word& operator *= (const Word&);
	Word& operator *= (T);
	Word& operator ++ ();
	Word& operator ++ (int);
	Word& operator -- ();
	Word& operator -- (int);

	friend Word operator + (Word, const Word&);
	friend Word operator - (Word, const Word&);
	friend Word operator * (Word, const Word&);
	friend Word operator / (Word, const Word&);

	
	friend bool operator >  (const Word&, const Word&);
	friend bool operator >= (const Word&, const Word&);
	friend bool operator <  (const Word&, const Word&);
	friend bool operator <= (const Word&, const Word&);
	*/
};


Word::Word()
{
	first = 0;
	last = 0;
}


Word::Word(char data)
{
	first = new Character(data);
	last = first;
}


Word::Word(const Word& original)
{
	first = 0;

	Character* p = original.first;
	while (p != 0)
	{
		add(p->data);
		p = p->next;
	}
	last = p;
}

void Word::add(char data)
{
	if (first == 0)
	{
		first = new Character(data);
		last = first;
	}
	else
	{
		last->next = new Character(data);
		last = last->next;
	}
}

Word & Word::operator=(const Word & rhs)
{
	first = 0;

	Character* p = rhs.first;
	while (p != 0)
	{
		add(p->data);
		p = p->next;
	}
	last = p;

	return *this;
}


Word operator+(Word lhs, const Word& rhs)
{
	Character* p = rhs.first;
	while (p->next != 0)
	{
		lhs.add(p->data);
		p = p->next;
	}
	lhs.last = p;

	return lhs;
}

ostream & operator<<(ostream & out, const Word & rhs)
{
	Character* p = rhs.first;
	while (p->next != 0)
	{
		out << p->data;
		p = p->next;
	}
	out << p->data;

	return out;
}

bool operator==(const Word& lhs, const Word& rhs)
{
	Character* l = lhs.first;
	Character* r = rhs.first;
	while (l->next != 0 && l->next != 0)
	{
		if (l->data != r->data) return false;
	}

	return true;
}

int main()
{
	Word w1 = Word(); w1.add('h'); w1.add('e'); w1.add('l'); w1.add('l'); w1.add('o');
	Word w2 = Word(); w2.add(' '); w2.add('w'); w2.add('o'); w2.add('r'); w2.add('l'); w2.add('d');
	Word w3 = Word(); w3.add(' '); w3.add('c'); w3.add('h'); w3.add('r'); w3.add('i'); w3.add('s');
	cout << w1 << w2 << w3 << endl;
	Word w4 = w1 + w2;
	cout << w4 << endl;

	return 0;
}