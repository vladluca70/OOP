class Movie
{
private:
    std::string name;
    int year;
    double score;
    int length;

public:
    Movie()
    {
        this->name="";
        this->year=0;
        this->score=0;
        this->length=0;
    }
    void set_name(const std::string name)
    {
        this->name=name;
    }

    std::string get_name()
    {
        return name;
    }

    void set_year(int year)
    {
        this->year=year;
    }

    int get_year()
    {
        return year;
    }

    void set_score(double score)
    {
        if(score>10 or score<1)
            std::cout<<"Scorul trebuie sa fie in intervalul [1, 10]";
        else
            this->score=score;
    }

    double get_score()
    {
        return score;
    }

    void set_length(int length)
    {
        this->length=length;
    }

    int get_length()
    {
        return length;
    }

    int get_passed_years()
    {
        return (2024-year);
    }
};


int movie_compare_name( Movie& m1,  Movie& m2)
{
    int L1, L2;
    L1=m1.get_name().length();
    L2=m2.get_name().length();
    if(L1<L2)
        return -1;
    if(L1==L2)
        return 0;
    return 1;
}

int movie_compare_year( Movie& m1,  Movie& m2)
{
    if(m1.get_year()<m2.get_year())
        return -1;
    if(m1.get_year()==m1.get_year())
        return 0;
    return 1;
}

int movie_compare_score( Movie& m1,  Movie& m2)
{
    if(m1.get_score()<m2.get_score())
        return -1;
    if(m1.get_score()==m1.get_score())
        return 0;
    return 1;
}

int movie_compare_length( Movie& m1,  Movie& m2)
{
    if(m1.get_length()<m2.get_length())
        return -1;
    if(m1.get_length()==m1.get_length())
        return 0;
    return 1;
}

int movie_compare_passed_years( Movie& m1,  Movie& m2)
{
    if(m1.get_passed_years()<m2.get_passed_years())
        return -1;
    if(m1.get_passed_years()==m1.get_passed_years())
        return 0;
    return 1;
}
