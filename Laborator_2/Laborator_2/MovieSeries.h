class MovieSeries
{
private:
    static const int max_movies=16;
    Movie * movies[max_movies];
    int _count;
public:
    MovieSeries()
    {
        this->_count=0;
    }

    void init()
    {
        _count=0;
    }

    void add(Movie * m)
    {
        if(_count>=16)
            std::cout<<"Maxim 16 filme";
        else
           {
                movies[_count]=m;
                _count++;
           }
    }

    void sort()
    {
        for(int i = 0; i < _count; i++)
            for(int j = i + 1; j < _count; j++)
                if(movies[i]->get_passed_years() < movies[j]->get_passed_years())
                    std::swap(movies[i], movies[j]);
    }

    void print()
    {
        for(int i = 0; i < _count; i++)
        {
            std::cout<<std::endl;
            std::cout<< "Movie series number"<<_count<<std::endl;
            std::cout<< "Name: " << movies[i]->get_name() << std::endl;
            std::cout<< "Year: " << movies[i]->get_year() << std::endl;
            std::cout<< "Score: " << movies[i]->get_score() << std::endl;
            std::cout<< "Length: " << movies[i]->get_length() << std::endl;
            std::cout<< "Passed Years: " << movies[i]->get_passed_years() << std::endl;
            std::cout<< std::endl << std::endl;
        }
    }

};
