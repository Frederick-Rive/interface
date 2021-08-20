#include <iostream>
#include <string>

class Media
{
protected:
    std::string title;
    float price;

public:
    Media(std::string t = "", float p = 0.0f)
    {
        this->price = p;
        this->title = t;
    }

    virtual void Display() = 0;
};

class Tape : public Media
{
private:
    float time;

public:
    Tape(std::string s, float p, float t)
    {
        this->title = s;
        this->price = p;
        this->time = t;
    }

    void Display()
    {
        std::cout << "Video Tape '" << this->title << "' : " << this->time << " minutes, $" << this->price << "\n\n";
    }
};

class Book : public Media
{
private:
    int pages;

public:
    Book(std::string s, float p, int i)
    {
        this->title = s;
        this->price = p;
        this->pages = i;
    }

    void Display()
    {
        std::cout << "Book '" << this->title << "' : " << this->pages << " pages, $" << this->price << "\n\n";
    }
};

class person
{
protected:
    char name;

public:
    char GetName()
    {
        return name;
    }

    void SetName(char n)
    {
        name = n;
    }

    virtual void GetData() = 0 { }

    virtual bool isOutstanding () = 0 { }
};

class student : public person
{
private:
    float gpa;

public:
    student(char n, float g)
    {
        name = n;
        gpa = g;
    }

    void GetData()
    {
        std::cout << "Student " << name << " : GPA: " << gpa;
        if (isOutstanding())
        {
            std::cout << " ~ This student is Outstanding!";
        }
        std::cout << "\n\n";
    }

    bool isOutstanding()
    {
        return (gpa >= 4) ? true : false;
    }
};

class professor : public person
{
private:
    int numPub;

public:
    professor(char n, int i)
    {
        name = n;
        numPub = i;
    }

    void GetData()
    {
        std::cout << "Professor " << name << " : Number of publications: " << numPub;
        if (isOutstanding())
        {
            std::cout << " ~ This professor is Outstanding!";
        }
        std::cout << "\n\n";
    }

    bool isOutstanding()
    {
        return (numPub >= 6) ? true : false;
    }
};

int main()
{
    /*
    Book b = Book("lord of rings", 12.20f, 500);
    Tape t = Tape("lawd of rangs", 25.99f, 360);
    b.Display();
    t.Display();

    //person p;
    student s = student('s', 3.0f);
    student ss = student('a', 5.0f);
    professor p = professor('p', 4);
    professor pp = professor('z', 12);

    s.GetData();
    ss.GetData();
    p.GetData();
    pp.GetData();
    */

    Media* media[5];

    for (int i = 0; i < 5; i++)
    {
        char c;
        std::cout << "What form of media are you adding?: ";
        std::cin >> c;

        std::string name;
        int page;
        float price, length;

        switch (c)
        {
        case 'b':
            std::cin.ignore();
            std::cout << "\nWhat is the name of the book?";
            std::getline(std::cin, name);
            std::cout << "\nWhat is the page length of the book?";
            std::cin >> page;
            std::cout << "\nWhat is the price of the book?";
            std::cin >> price;

            media[i] = new Book(name, price, page);
            break;
        case 't':
            std::cin.ignore();
            std::cout << "\nWhat is the name of the tape?";
            std::getline(std::cin, name);
            std::cout << "\nWhat is the length of the tape?";
            std::cin >> length;
            std::cout << "\nWhat is the price of the tape?";
            std::cin >> price;

            media[i] = new Tape(name, price, length);
            break;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        media[i]->Display();
    }
}
