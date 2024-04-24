#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>

std::vector < std::string > splitPhrase (const std::string & phrase)
{

    std::vector < std::string > words;

    std::string word;

    for (char c:phrase)
    {
        if (c == ' ' || c == ',' || c == '.' || c == '?' || c == '!')
        {
            if (!word.empty ())
            {
                words.push_back (word);
                word.clear ();
            }

        }
        else

            word += std::tolower (c);
    }

    if (!word.empty ())
        words.push_back (word);

    return words;
}



int main ()
{

    std::ifstream inputFile ("text.txt");
    if (!inputFile.is_open ())
    {

        std::cout << "Fiisierul nu poate fi deschis" << std::endl;
        return 1;
    }


    std::string phrase;
    std::getline (inputFile, phrase);
    inputFile.close ();

    std::vector < std::string > words = splitPhrase (phrase);

    std::map < std::string, int >wordCount;
    for (const auto & word:words)
        wordCount[word]++;

    auto cmp =
        [](const std::pair < std::string, int >&a,
           const std::pair < std::string, int >&b)
    {
        return a.second < b.second || (a.second == b.second
                                       && a.first > b.first);
    };


    std::priority_queue < std::pair < std::string, int >, std::vector < std::pair < std::string, int >>, decltype (cmp) > sortedWords (cmp);

    for (const auto & pair:wordCount)
        sortedWords.push (pair);

    while (!sortedWords.empty ())
    {

        std::cout << sortedWords.top ().first << " => " << sortedWords.
                  top ().second << std::endl;
        sortedWords.pop ();
    }


    return 0;
}


