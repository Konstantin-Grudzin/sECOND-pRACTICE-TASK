// «адача Dictionary

// –еализовать операции объединени€, пересечени€ и вычитани€ словарей. ѕри реализации должен создаватьс€ новый словарь,
// а исходные словари не должны измен€тьс€.  ѕри пересечении новый словарь должен состо€ть только из тех слов, которые имеютс€ в обоих словар€х-операндах.
// ѕри вычитании новый словарь должен содержать слова первого словар€-операнда, отсутствующие во втором.
#pragma once


#include<iostream>
#define end cout<<"\n";

//  арточка иностранного слова представл€ет собой структуру WordCard, содержащую иностранное слово и его перевод.
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


// ƒл€ моделировани€ электронного словар€ иностранных слов реализовать класс Dictionary.
class Dicitionary
{
private:
	// ƒанный класс имеет поле-название словар€ и содержит массив структур WordCard, представл€ющих собой карточки иностранного слова.
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

	// Ќазвание словар€ задаетс€ при создании нового словар€, но должна быть предоставлена возможность его изменени€ во врем€ работы.
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

	// Ќазвание словар€ задаетс€ при создании нового словар€, но должна быть предоставлена возможность его изменени€ во врем€ работы.
	void change_name()
	{
		std::cout << "Enter the new name:";
		std::cin>>this->name;
		std::end;
	}

	// –еализовать поиск определенного слова как отдельный метод.
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

	//  арточки добавл€ютс€ в словарь 
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
		//¬ словаре не должно быть карточек - дублей.
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
		//¬ словаре не должно быть карточек - дублей.
		for (int i = 0; i < this->cur_pos; ++i)
		{
			if (!(strcmp(this->mas[i].get_word(), this->mas[this->cur_pos].get_word())))
			{
				std::cout << "This card is exist!";
				cur_pos--;
			}
		}
	}

	//и удал€ютс€ из него.
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

	// јргументом операции индексировани€ должно быть иностранное слово. 
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

	//ѕри объединении новый словарь должен содержать без повторений все слова,содержащиес€ в обоих словар€х-операндах.
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