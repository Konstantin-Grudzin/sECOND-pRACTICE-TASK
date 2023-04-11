// Çàäà÷à Dictionary

// Ðåàëèçîâàòü îïåðàöèè îáúåäèíåíèÿ, ïåðåñå÷åíèÿ è âû÷èòàíèÿ ñëîâàðåé. Ïðè ðåàëèçàöèè äîëæåí ñîçäàâàòüñÿ íîâûé ñëîâàðü,
// à èñõîäíûå ñëîâàðè íå äîëæíû èçìåíÿòüñÿ.  Ïðè ïåðåñå÷åíèè íîâûé ñëîâàðü äîëæåí ñîñòîÿòü òîëüêî èç òåõ ñëîâ, êîòîðûå èìåþòñÿ â îáîèõ ñëîâàðÿõ-îïåðàíäàõ.
// Ïðè âû÷èòàíèè íîâûé ñëîâàðü äîëæåí ñîäåðæàòü ñëîâà ïåðâîãî ñëîâàðÿ-îïåðàíäà, îòñóòñòâóþùèå âî âòîðîì.
#pragma once


#include<iostream>
#define end cout<<"\n";

// Êàðòî÷êà èíîñòðàííîãî ñëîâà ïðåäñòàâëÿåò ñîáîé ñòðóêòóðó WordCard, ñîäåðæàùóþ èíîñòðàííîå ñëîâî è åãî ïåðåâîä.
class WordCard
{
	private:
		char* word;
		char* translate;
public:
	char* get_word()
	{
		return this->word;
	}
	char* get_translate()
	{
		return this->translate;
	}
	void change_card()
	{
		std::cout << "Please, enter the word:";
		std::cin >> word;
		std::end;

		std::cout << "Please, enter the translate:";
		std::cin >> translate;
		std::end;
	}

	WordCard* operator=(WordCard temp)
	{
		this->translate = temp.get_translate();
		this->word = temp.get_word();
		return this;
	}

	~WordCard()
	{
		delete[] word;
		delete[] translate;
	}
};


// Äëÿ ìîäåëèðîâàíèÿ ýëåêòðîííîãî ñëîâàðÿ èíîñòðàííûõ ñëîâ ðåàëèçîâàòü êëàññ Dictionary.
class Dicitionary
{
private:
	// Äàííûé êëàññ èìååò ïîëå-íàçâàíèå ñëîâàðÿ è ñîäåðæèò ìàññèâ ñòðóêòóð WordCard, ïðåäñòàâëÿþùèõ ñîáîé êàðòî÷êè èíîñòðàííîãî ñëîâà.
	int size;
	int cur_pos;
	WordCard* mas;
	char* name;
public:

	int get_size()
	{
		return this->size;
	}

	WordCard get_mas_elem(int i)
	{
		return this->mas[i];
	}

	// Íàçâàíèå ñëîâàðÿ çàäàåòñÿ ïðè ñîçäàíèè íîâîãî ñëîâàðÿ, íî äîëæíà áûòü ïðåäîñòàâëåíà âîçìîæíîñòü åãî èçìåíåíèÿ âî âðåìÿ ðàáîòû.
	Dicitionary()
	{
		size = 1024;
		mas = new WordCard [size];

		std::cout << "Please, enter the name of the dictionary:";
		std::cin >> name;
		std::end;
	}

	~Dicitionary()
	{
		delete[] mas;
	}

	// Íàçâàíèå ñëîâàðÿ çàäàåòñÿ ïðè ñîçäàíèè íîâîãî ñëîâàðÿ, íî äîëæíà áûòü ïðåäîñòàâëåíà âîçìîæíîñòü åãî èçìåíåíèÿ âî âðåìÿ ðàáîòû.
	void change_name()
	{
		std::cout << "Enter the new name:";
		std::cin>>this->name;
		std::end;
	}

	// Ðåàëèçîâàòü ïîèñê îïðåäåëåííîãî ñëîâà êàê îòäåëüíûé ìåòîä.
	int get_index_by_word(bool output=false)
	{
		char* search_word;
		std::cout << "Input the word you need:";
		std::cin >> search_word;
		std::end;

		for (int i = 0; i <= this->cur_pos; ++i)
		{
			if (!(strcmp(search_word, this->mas[i].get_word())))
			{
				if (output)
				{
					std::cout << "Here is your translate:" << this->mas[i].get_translate();
					std::end;
					return i;
				}
			}
		}

		std::cout << "This word doesnt exist!";
		std::end;
		
		return -1; 
	}

	// Êàðòî÷êè äîáàâëÿþòñÿ â ñëîâàðü 
	void add_card()
	{
		if (this->cur_pos >= size)
		{
			this->size *= 2;
			WordCard* temp = new WordCard [size];
			for (int i = 0; i < this->size / 2; ++i)
			{
				temp[i] = this->mas[i];
			}
			delete[] mas;
			this->mas = temp;
		}
		(this->mas[this->cur_pos++]).change_card();
		//Â ñëîâàðå íå äîëæíî áûòü êàðòî÷åê - äóáëåé.
		for (int i = 0; i < this->cur_pos; ++i)
		{
			if (!(strcmp(this->mas[i].get_word(), this->mas[this->cur_pos].get_word())))
			{
				std::cout << "This card is exist!";
				cur_pos--;
			}
		}
	}

	void add_card(WordCard B)
	{
		if (this->cur_pos >= size)
		{
			this->size *= 2;
			WordCard* temp = new WordCard[size];
			for (int i = 0; i < this->size / 2; ++i)
			{
				temp[i] = this->mas[i];
			}
			delete[] mas;
			this->mas = temp;
		}
		(this->mas[this->cur_pos++])=B;
		//Â ñëîâàðå íå äîëæíî áûòü êàðòî÷åê - äóáëåé.
		for (int i = 0; i < this->cur_pos; ++i)
		{
			if (!(strcmp(this->mas[i].get_word(), this->mas[this->cur_pos].get_word())))
			{
				std::cout << "This card is exist!";
				cur_pos--;
			}
		}
	}

	//è óäàëÿþòñÿ èç íåãî.
	void del_card()
	{
		int pos = get_index_by_word();
		if (pos != -1)
		{
			WordCard temp;
			this->mas[pos] = this->mas[cur_pos--];
			std::cout << "Deleted!";
			std::end;
		}
	}

	// Àðãóìåíòîì îïåðàöèè èíäåêñèðîâàíèÿ äîëæíî áûòü èíîñòðàííîå ñëîâî. 
	WordCard& operator[] (char* search_word)
	{
		for (int i = 0; i <= this->cur_pos; ++i)
		{
			if (!(strcmp(search_word, this->mas[i].get_word())))
			{
				return (this->mas[i]);
			}
		}
	}

	//Ïðè îáúåäèíåíèè íîâûé ñëîâàðü äîëæåí ñîäåðæàòü áåç ïîâòîðåíèé âñå ñëîâà,ñîäåðæàùèåñÿ â îáîèõ ñëîâàðÿõ-îïåðàíäàõ.
	Dicitionary operator+(Dicitionary B)
	{
		Dicitionary C;
		for (int i = 0; i < this->get_size(); ++i)
		{
			C.add_card(this->get_mas_elem(i));
		}
		for (int i = 0; i < B.get_size(); ++i)
		{
			C.add_card(B.get_mas_elem(i));
		}
	}
};
